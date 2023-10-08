/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file LVM.cpp
 * @author Daniel Perez Ruiz
 * @brief Maquina Virtual de Lamport
 */

#include "LVM/LVM.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [LVM] -----

int LVM::get_phisical_address_from_operand(const IR_operand & op){
    // -- Variable para direccion fisica
    int phisical_address;
    // -- Variable para segmento de memoria
    int virtual_segment;
    // -- Variable para direccion virtual
    int virtual_address = op.get_address();
    // -- Variable para offset (solo para variables de tipo array)
    int offset = op.get_offset();
    
    switch (op.get_kind())
    {
    case IR_OPERAND_LITERAL:
    {
        virtual_segment = 0;
        break;
    }
    case IR_OPERAND_VARIABLE:
    {
        virtual_segment = 1;
        break;
    }
    case IR_OPERAND_VARIABLE_ARRAY:
    {
        virtual_segment = 1;
        break;
    }
    case IR_OPERAND_LABEL:
    {
        virtual_segment = 2;
        break;
    }
    default:
        std::cout << "EXCEPCION: " << op.get_kind_str() << std::endl;
        throw std::invalid_argument("SEGMENTO VIRTUAL DE OPERANDO INVALIDO.");
        break;
    }

    // -- Obtener direccion fisica mirando en la tabla de paginas
    phisical_address = this->pages_table(virtual_segment,virtual_address);

    // -- Retornar direccion fisica
    return phisical_address;
}

void LVM::execute_instruction(int index){
    // 0.A Comprobar que la instruccion es correcta
    if(index >= this->instructions.size())
        throw std::out_of_range("INDICE DE INSTRUCCION NO VALIDO.");

    // 0.B Obtener instruccion a la que apunta el indice
    IR_instruction instr_to_exec = this->instructions[index];

    // 1. Obtener codigo de instruccion
    IR_instruction_type_t instr_code = instr_to_exec.get_code_instr();

    // 1.B Decidir accion
    switch (instr_code)
    {
    // ---- INSTRUCCIONES DE ALMACENAMIENTO ENTRE MEMORIA/REGISTROS
    case IR_OP_LOAD:
    {
        this->execute_instruction_load(instr_to_exec);
        // -- Incrementar contador de programa
        this->program_counter++;
        break;
    }
    case IR_OP_STORE:
    {
        this->execute_instruction_store(instr_to_exec);
        // -- Incrementar contador de programa
        this->program_counter++;
        break;
    }
    // ---- INSTRUCCION DE IMPRESION POR SALIDA ESTANDAR
    case IR_OP_PRINT:
    {
        this->execute_instruction_print(instr_to_exec);
        // -- Incrementar contador de programa
        this->program_counter++;
        break;
    }
    // ---- INSTRUCCION DE ETIQUETA
    case IR_LABEL:
    {
        // -- Incrementar contador de programa
        this->program_counter++;
        break;
    }

    
    default:
        break;
    }

}

void LVM::execute_instruction_load(const IR_instruction & instr){
    // 1.B Elementos para ejecucion
    // ----- Operandos de instruccion
    IR_operand op_dest, op_1;
    // ----- Direccion fisica a memoria
    int phisical_address;
    // ----- Direccion a registro
    int register_address;
    // ----- Bloque de memoria
    LVM_Memory_Block mem_block;

    // -- Obtener operando de destino
    op_dest = *instr.get_operand_destiny();
    // -- Obtener operando de precedencia
    op_1 = *instr.get_operand_1();

    // -- Determinar registro donde se almacenara
    register_address = op_dest.get_address();
    // -- Determinar direccion fisica donde se encuentra el valor
    phisical_address = this->get_phisical_address_from_operand(op_1);
    // -- Traer el bloque de memoria de esa direccion fisica
    mem_block = this->memory[phisical_address];

    // -- Enviar a registro
    this->register_table(register_address,mem_block);
}


void LVM::execute_instruction_store(const IR_instruction & instr){
    // 1.B Elementos para ejecucion
    // ----- Operandos de instruccion
    IR_operand op_dest, op_1;
    // ----- Direccion fisica a memoria
    int phisical_address;
    // ----- Direccion a registro
    int register_address;
    // ----- Bloque de memoria
    LVM_Memory_Block mem_block;
    // ----- Registro
    LVM_Register reg;

    // -- Obtener operando de destino
    op_dest = *instr.get_operand_destiny();
    // -- Obtener operando de precedencia
    op_1 = *instr.get_operand_1();

    // -- Determinar registro donde se encuentra almacenado el valor
    register_address = op_1.get_address();
    // -- Determinar direccion fisica donde se almacenara el valor de registro
    phisical_address = this->get_phisical_address_from_operand(op_dest);

    // -- Obtener registro
    reg = this->register_table(register_address);

    // -- Decidir contenido de registro y almacenar en bloque
    switch (reg.get_type_of_alloc())
    {
    case REG_CONTAINS_INTEGER:
    {
        mem_block.allocate_value<int>(reg.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        mem_block.allocate_value<float>(reg.get_value<float>());
        break;
    }
    case REG_CONTAINS_CHAR:
    {
        mem_block.allocate_value<char>(reg.get_value<char>());
        break;
    }
    case REG_CONTAINS_STRING:
    {
        mem_block.allocate_value<std::string>(reg.get_value<std::string>());
        break;
    }
    case REG_CONTAINS_BOOL:
    {
        mem_block.allocate_value<bool>(reg.get_value<bool>());
        break;
    }
    default:
        throw std::invalid_argument("CONTENIDO DE REGISTRO PARA OP_STORE INVÁLIDO.");
        break;
    }

    // -- Almacenar el bloque de memoria en la direccion fisica especificada
    this->memory[phisical_address] = mem_block;
}

void LVM::execute_instruction_print(const IR_instruction & instr){
    // 1.B Elementos para ejecucion
    // ----- Operandos de instruccion
    IR_operand op_1;
    // ----- Direccion a registro
    int register_address;
    // ----- Registro
    LVM_Register reg;

    // -- Obtener operando
    op_1 = *instr.get_operand_1();

    // -- Obtener direccion de registro
    register_address = op_1.get_address();

    // -- Obtener registro
    reg = this->register_table(register_address);

    // -- Imprimir contenido de registro
    switch (reg.get_type_of_alloc())
    {
    case REG_CONTAINS_INTEGER:
    {
        std::cout << reg.get_value<int>();
        break;
    }
    case REG_CONTAINS_REAL:
    {
        std::cout << reg.get_value<float>();
        break;
    }
    case REG_CONTAINS_CHAR:
    {
        std::cout << reg.get_value<char>();
        break;
    }
    case REG_CONTAINS_STRING:
    {
        std::string reg_value = reg.get_value<std::string>();
        if(reg_value != "\n")
            reg_value.erase(std::remove(reg_value.begin(), reg_value.end(), '\"'), reg_value.end());

        std::cout << reg_value;
        break;
    }
    case REG_CONTAINS_BOOL:
    {
        std::cout << reg.get_value<bool>();
        break;
    }

    default:
        break;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [LVM] -----

LVM& LVM::get_instance(){
    static LVM instance;
    return instance;
}

void LVM::print_pages_table(std::ostream& os){
    if(this->state == LVM_STATE_BORN)
        return;

    this->pages_table.print_page_table(os);
}

void LVM::print_memory(std::ostream& os){
    if(this->state == LVM_STATE_BORN)
        return;

    this->memory.print_memory(os);
}

bool LVM::preload_lvm(bool verbose_avaiable){
    if(this->state == LVM_STATE_BORN){
        // -- Cambiar estado a prepared
        this->state = LVM_STATE_PREPARED;

        // -- Volcar contenido a memoria
        this->initializer.dump_to_memory();

        // -- Imprimir contenido (si esta habilitado)
        if(verbose_avaiable){
            // -- Imprimir tabla de paginas
            this->print_pages_table();

            // -- Imprimir memoria
            this->print_memory();
        }

        return true;
    }
    
    return false;
}

bool LVM::start(){
    if(this->state == LVM_STATE_PREPARED){
        // -- Cambiar estado a ejecutandose
        this->state == LVM_STATE_RUNNING;
        
        // -- Ejecucion de listado de instrucciones
        while(this->program_counter < this->instructions.size()){
            this->execute_instruction(program_counter);
        }

        return true;
    }
    
    return false;
}