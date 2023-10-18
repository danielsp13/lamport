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
    // -- Recuperar el tam de la tabla de literales
    const int size_table = tables.get_size_table_literals();

    // -- Direccion de memoria inicial
    const int start_addr = LVM_Segment_Table::START_ADDR_FOR_LITERALS;
    // -- Direccion de memoria final
    const int end_addr = LVM_Segment_Table::END_ADDR_FOR_LITERALS;
    // -- Direccion de segmento de tabla de literales
    const int segment_address = LVM_Segment_Table::SEGMENT_FOR_LITERALS;

    // -- Definicion de literal IR
    mem_block_content lit;
    // -- Definicion de bloque de memoria
    LVM_Memory_Block mem_block;

    // -- Recorrer la tabla de literales
    for(int i = 0; i < size_table; i++){
        // -- Comprobar que no hay desbordamiento de memoria
        if(start_addr+i >= end_addr){
            throw std::out_of_range("DESBORDAMIENTO DE LA MEMORIA EN ASIGNACION DE BLOQUES A LITERALES");
        }

        // -- 1. Obtener literal
        lit = *tables.get_entry_literal(i);
        // -- 2. Obtener el bloque de memoria inicializado
        mem_block = this->initialize_mem_block(0,lit);

        // -- 3. Asignar bloque a memoria
        this->memory[start_addr+i] = mem_block;

        // -- 4. Completar paginacion de memoria virtual+fisica
        this->segment_table(segment_address,i) = start_addr+i;
    }

}

void LVM_Initializer::dump_variables(){
    // -- Recuperar el tam de la tabla de variables
    const int size_table = tables.get_size_table_variables();

    // -- Direccion de memoria inicial
    const int start_addr = LVM_Segment_Table::START_ADDR_FOR_VARIABLES;
    // -- Direccion de memoria
    int address = 0;
    // -- Direccion base de array
    int base_address = 0;
    // -- Segmento a alojar
    int segment_address;

    // -- Definicion de variable IR
    mem_block_content var;
    // -- Definicion de ambito de variable
    bool var_global = false;
    // -- Definicion de tipo de variable IR
    IR_variable_type_t var_type;
    // -- Definicion de bloque de memoria
    LVM_Memory_Block mem_block;
    // -- Nombre de variable proceso
    std::string process_name = std::string("");

    // -- Recorrer la tabla de variables
    for(int i = 0; i < size_table; i++){
        // -- 1. Obtener variable
        var = *tables.get_entry_variable(i);

        // -- 1.B obtener scope de variable
        var_global = std::get<IR_variable>(var).is_global();

        // -- 1.B obtener tipo de variable
        var_type = std::get<IR_variable>(var).get_type();

        // -- 1.C Comprobar si la variable refiere a un subprograma
        if(var_type == IR_VAR_TYPE_SUBPROGRAM)
            continue;

        // -- 1.D Comprobar si la variable es global
        if(var_global){
            // -- Dedicar segmento para variables globales
            segment_address = LVM_Segment_Table::SEGMENT_FOR_GLOBAL_VARIABLES;

            // -- 1.D.1 Comprobar si la variable global es un proceso
            if(var_type == IR_VAR_TYPE_PROCESS){
                // --- Obtener nuevo segmento
                segment_address = segment_table.get_new_segment_for_thread();
                // --- Indicar nuevo nombre de proceso
                process_name = std::get<IR_variable>(var).get_name();
                // --- Incluir nuevo segmento
                segment_table.new_segment(segment_address,process_name);

                // --- Continuar
                continue;
            }
            
        }
        else if(var_type == IR_VAR_TYPE_DPROCESS){
            continue;
        }

        // -- 2 comprobar si la variable refiere a un array
        if(var_type == IR_VAR_TYPE_ARRAY){
            // -- 2.A Obtener el size de array
            const size_t size_arr = std::get<IR_variable>(var).get_size_array();

            // -- Inicializar para cada posicion de array
            for(int j=0; j<size_arr; j++){
                // -- 2. Obtener el bloque de memoria inicializado
                mem_block = this->initialize_mem_block(1,var);

                // -- 3. Asignar bloque a memoria
                this->memory[start_addr+address] = mem_block;

                // -- 4. Registrar en tabla de segmentos
                this->segment_table(segment_address,i,j) = start_addr+address;

                // -- Incrementar direccion
                address++;
            }

            // -- Registrar limite de array
            bounds_arrays.insert_upper_bounds(i,start_addr+address-1);
        }
        else{
            // -- 2. Obtener el bloque de memoria inicializado
            mem_block = this->initialize_mem_block(1,var);

            // -- 3. Asignar bloque a memoria
            this->memory[start_addr+address] = mem_block;

            // -- 4. Completar paginacion de memoria virtual+fisica
            this->segment_table(segment_address,i) = start_addr+address;

            // -- Incrementar direccion
            address++;
        }
    }
}

void LVM_Initializer::dump_labels(){
    // -- Recuperar el tam de la tabla de etiquetas
    const int size_table = tables.get_size_table_labels();

    // -- Direccion de memoria inicial
    const int start_addr = LVM_Segment_Table::START_ADDR_FOR_LABELS;
    // -- Direccion de memoria final
    const int end_addr = LVM_Segment_Table::END_ADDR_FOR_LABELS;
    // -- Direccion de segmento de tabla de etiquetas
    const int segment_address = LVM_Segment_Table::SEGMENT_FOR_LABELS;

    // -- Definicion de etiqueta IR
    mem_block_content label;
    // -- Definicion de bloque de memoria
    LVM_Memory_Block mem_block;

    // -- Recorrer la tabla de etiquetas
    for(int i = 0; i < size_table; i++){
        // -- Comprobar que no hay desbordamiento de memoria
        if(start_addr+i >= end_addr)
            throw std::out_of_range("DESBORDAMIENTO DE LA MEMORIA EN ASIGNACION DE BLOQUES A ETIQUETAS");

        // -- 1. Obtener etiqueta
        label = *tables.get_entry_label(i);
        // -- 2. Obtener el bloque de memoria inicializado
        mem_block = this->initialize_mem_block(2,label);

        // -- 3. Asignar bloque a memoria
        this->memory[start_addr+i] = mem_block;

        // -- 4. Completar paginacion de memoria virtual+fisica
        this->segment_table(segment_address,i) = start_addr+i;
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

void LVM_Initializer::create_threads(){
    // -- Hebra a crear
    LVM_Thread * thread = nullptr;
    // -- Contador de segmentos virtuales
    int segment_addr = LVM_Segment_Table::SEGMENT_FOR_THREADS;
    // -- Identificador de hebra
    int id_thread = 0;

    for(int i=0; i<instructions.size(); i++){
        // -- Inicializar 
        if(instructions[i].get_code_instr() != IR_START_PROCESS)
            continue;

        // -- Crear nueva hebra
        thread = new LVM_Thread(id_thread++,i+1,segment_addr++);

        // -- Incluir en la cola
        scheduler.new_thread_raw(thread);
    }
}