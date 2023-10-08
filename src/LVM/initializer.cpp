/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file initializer.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de cargador de arranque de la maquina virtual de lamport
 */

#include "LVM/initializer.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [INITIALIZER] -----

LVM_Memory_Block LVM_Initializer::initialize_mem_block(int content_type, const mem_block_content& content){
    // -- Definir bloque de memoria
    LVM_Memory_Block mem_block;

    // -- Definir enteros discriminantes
    const int CONTENT_IS_LITERAL = 0;
    const int CONTENT_IS_VARIABLE = 1;
    const int CONTENT_IS_LABEL = 2;

    // -- Inicializar bloque dependiendo del contenido
    switch (content_type)
    {
    case CONTENT_IS_LITERAL:
    {
        IR_literal lit = std::get<IR_literal>(content);
        switch (lit.get_kind())
        {
        case IR_LIT_INTEGER:
        {   
            mem_block.allocate_value<int>(lit.get_literal<int>());
            break;
        }
        case IR_LIT_REAL:
        {   
            mem_block.allocate_value<float>(lit.get_literal<float>());
            break;
        }
        case IR_LIT_CHAR:
        {   
            mem_block.allocate_value<char>(lit.get_literal<char>());
            break;
        }
        case IR_LIT_STRING:
        {   
            mem_block.allocate_value<std::string>(lit.get_literal<std::string>());
            break;
        }
        case IR_LIT_BOOLEAN:
        {   
            mem_block.allocate_value<bool>(lit.get_literal<bool>());
            break;
        }
        default:
            break;
        }

        break;
    }
    case CONTENT_IS_VARIABLE:
    {
        IR_variable var = std::get<IR_variable>(content);
        // -- Comprobar si la variable es un array
        IR_variable_type_t kind = var.is_array() ? var.get_array_type() : var.get_type();
        
        switch (kind)
        {
        case IR_VAR_TYPE_INT:
        {   
            mem_block.allocate_value<int>(var.get_initial_value<int>());
            break;
        }
        case IR_VAR_TYPE_REAL:
        {
            mem_block.allocate_value<float>(var.get_initial_value<float>());
            break;
        }
        case IR_VAR_TYPE_CHAR:
        {
            mem_block.allocate_value<char>(var.get_initial_value<char>());
            break;
        }
        case IR_VAR_TYPE_STR:
        {
            mem_block.allocate_value<std::string>(var.get_initial_value<std::string>());
            break;
        }
        case IR_VAR_TYPE_BOOL:
        {
            mem_block.allocate_value<bool>(var.get_initial_value<bool>());
            break;
        }
        case IR_VAR_TYPE_SEMAPHORE:
        {
            mem_block.allocate_value<int>(var.get_initial_value<int>());
            break;
        }

        
        default:
            break;
        }
        break;
    }
    case CONTENT_IS_LABEL:
    {
        IR_label label = std::get<IR_label>(content);
        mem_block.allocate_value<long>(static_cast<long>(label.get_addr()));
        break;
    }
    
    default:
        break;
    }

    // -- Retornar bloque de memoria
    return mem_block;
}

void LVM_Initializer::dump_literals(){
    /**
     * El objetivo es volcar la tabla de literales en la memoria en las siguientes direcciones
     * Inicio de memoria: 0m00000000  (posicion 0)
     * Fin de memoria: 0m00000999 (posicion 999)
     */

    // -- Recuperar el tam de la tabla de literales
    const int size_table = tables.get_size_table_literals();

    // -- Direccion de memoria inicial
    const int start_addr = 0;
    // -- Direccion de segmento de tabla de literales
    const int segment_address = 0;

    // -- Definicion de literal IR
    mem_block_content lit;
    // -- Definicion de bloque de memoria
    LVM_Memory_Block mem_block;

    // -- Recorrer la tabla de literales
    for(int i = 0; i < size_table; i++){
        // -- 1. Obtener literal
        lit = *tables.get_entry_literal(i);
        // -- 2. Obtener el bloque de memoria inicializado
        mem_block = this->initialize_mem_block(segment_address,lit);

        // -- 3. Asignar bloque a memoria
        this->memory[start_addr+i] = mem_block;

        // -- 4. Completar paginacion de memoria virtual+fisica
        this->page_table(segment_address,i) = start_addr+i;
    }

}

void LVM_Initializer::dump_variables(){
    /**
     * El objetivo es volcar la tabla de variables en la memoria en las siguientes direcciones
     * Inicio de memoria: 0m00001000  (posicion 1000)
     * Fin de memoria: 0m0003999 (posicion 3999)
     */

    // -- Recuperar el tam de la tabla de variables
    const int size_table = tables.get_size_table_variables();

    // -- Direccion de memoria inicial
    const int start_addr = 1000;
    // -- Direccion de segmento de tabla de variables
    const int segment_address = 1;

    // -- Definicion de variable IR
    mem_block_content var;
    // -- Definicion de bloque de memoria
    LVM_Memory_Block mem_block;

    // -- Recorrer la tabla de variables
    for(int i = 0; i < size_table; i++){
        // -- 1. Obtener variable
        var = *tables.get_entry_variable(i);

        // -- 1.B comprobar si la variable refiere a un proceso
        if(std::get<IR_variable>(var).get_type() == IR_VAR_TYPE_DPROCESS || std::get<IR_variable>(var).get_type() == IR_VAR_TYPE_PROCESS)
            continue;

        // -- 2. Obtener el bloque de memoria inicializado
        mem_block = this->initialize_mem_block(segment_address,var);

        // -- 3. Asignar bloque a memoria
        this->memory[start_addr+i] = mem_block;

        // -- 4. Completar paginacion de memoria virtual+fisica
        this->page_table(segment_address,i) = start_addr+i;
    }
}

void LVM_Initializer::dump_labels(){
    /**
     * El objetivo es volcar la tabla de etiquetas en la memoria en las siguientes direcciones
     * Inicio de memoria: 0m00004000  (posicion 4000)
     * Fin de memoria: 0m0004999 (posicion 4999)
     */

    // -- Recuperar el tam de la tabla de etiquetas
    const int size_table = tables.get_size_table_labels();

    // -- Direccion de memoria inicial
    const int start_addr = 4000;
    // -- Direccion de segmento de tabla de etiquetas
    const int segment_address = 2;

    // -- Definicion de etiqueta IR
    mem_block_content label;
    // -- Definicion de bloque de memoria
    LVM_Memory_Block mem_block;

    // -- Recorrer la tabla de etiquetas
    for(int i = 0; i < size_table; i++){
        // -- 1. Obtener etiqueta
        label = *tables.get_entry_label(i);
        // -- 2. Obtener el bloque de memoria inicializado
        mem_block = this->initialize_mem_block(segment_address,label);

        // -- 3. Asignar bloque a memoria
        this->memory[start_addr+i] = mem_block;

        // -- 4. Completar paginacion de memoria virtual+fisica
        this->page_table(segment_address,i) = start_addr+i;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [INITIALIZER] -----

LVM_Initializer& LVM_Initializer::get_instance(){
    static LVM_Initializer instance;
    return instance;
}

void LVM_Initializer::dump_to_memory(){
    // -- Realizar volcado de memoria de literales
    this->dump_literals();
    // -- Realizar volcado de memoria de variables
    this->dump_variables();
    // -- Realizar volcado de memoria de etiquetas
    this->dump_labels();
}