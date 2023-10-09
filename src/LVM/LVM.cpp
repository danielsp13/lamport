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

inline bool LVM::instruction_is_load_or_store(const IR_instruction & instr){
    bool result = false;
    const IR_instruction_type_t kind = instr.get_code_instr();

    result = kind == IR_OP_LOAD;
    result = result == true ? true : kind == IR_OP_STORE;

    return result;
}

inline bool LVM::instruction_is_label_pointer(const IR_instruction & instr){
    bool result = false;
    const IR_instruction_type_t kind = instr.get_code_instr();

    result = kind == IR_LABEL;

    return result;
}

inline bool LVM::instruction_is_binary_operation(const IR_instruction & instr){
    bool result = false;
    const IR_instruction_type_t kind = instr.get_code_instr();

    result = kind == IR_OP_ADD;
    result = result == true ? true : kind == IR_OP_SUB;
    result = result == true ? true : kind == IR_OP_MULT;
    result = result == true ? true : kind == IR_OP_DIV;
    result = result == true ? true : kind == IR_OP_MOD;
    
    result = result == true ? true : kind == IR_OP_CMP_LTE;
    result = result == true ? true : kind == IR_OP_CMP_LT;
    result = result == true ? true : kind == IR_OP_CMP_GTE;
    result = result == true ? true : kind == IR_OP_CMP_GT;
    result = result == true ? true : kind == IR_OP_CMP_EQ;
    result = result == true ? true : kind == IR_OP_CMP_NEQ;

    result = result == true ? true : kind == IR_OP_AND;
    result = result == true ? true : kind == IR_OP_OR;

    return result;
}

inline bool LVM::instruction_is_unary_operation(const IR_instruction & instr){
    bool result = false; 
    const IR_instruction_type_t kind = instr.get_code_instr();
    
    result = kind == IR_OP_NEG;
    result = result == true ? true : kind == IR_OP_NOT;

    return result;
}

inline bool LVM::instruction_is_jump(const IR_instruction & instr){
    bool result = false; 
    const IR_instruction_type_t kind = instr.get_code_instr();
    
    result = kind == IR_OP_JMP;
    result = result == true ? true : kind == IR_OP_JMP_FALSE;
    result = result == true ? true : kind == IR_OP_JMP_TRUE;

    return result;
}

inline bool LVM::instruction_is_print(const IR_instruction & instr){
    bool result = false; 
    const IR_instruction_type_t kind = instr.get_code_instr();
    
    result = kind == IR_OP_PRINT;

    return result; 
}


std::vector<LVM_Register> LVM::get_registers_from_operands(const IR_instruction & instr){
    std::vector<LVM_Register> registers;

    // 1.B Elementos para ejecucion
    // ----- Operandos de instruccion
    IR_operand op_dest, op_1, op_2;
    // ----- Direcciones a registro
    int reg_addr_dest, reg_addr_op1, reg_addr_op2;
    // ----- Registro
    LVM_Register reg_dest, reg_op1, reg_op2;

    // -- Obtener operando destino
    op_dest = *instr.get_operand_destiny();
    // -- Obtener operando 1
    op_1 = *instr.get_operand_1();

    // -- Obtener direcciones de registros
    reg_addr_dest = op_dest.get_address();
    reg_addr_op1 = op_1.get_address();

    // -- Obtener registros
    reg_dest = this->register_table[reg_addr_dest];
    reg_op1 = this->register_table[reg_addr_op1];

    // -- Insertar en vector
    registers.push_back(reg_dest);
    registers.push_back(reg_op1);

    // -- Comprobar si la operacion no es unaria
    if(!instruction_is_unary_operation(instr)){
        // -- Obtener operando 2
        op_2 = *instr.get_operand_2();

        // -- Obtener direcciones de registros
        reg_addr_op2 = op_2.get_address();

        // -- Obtener registros
        reg_op2 = this->register_table[reg_addr_op2];

        // -- Insertar en vector
        registers.push_back(reg_op2);
    }

    return registers;
}

void LVM::execute_instruction(int index){
    // 0.A Comprobar que la instruccion es correcta
    if(index >= this->instructions.size())
        throw std::out_of_range("INDICE DE INSTRUCCION NO VALIDO.");

    // 0.B Obtener instruccion a la que apunta el indice
    IR_instruction instr_to_exec = this->instructions[index];

    // -- Decidir accion
    // ---- INSTRUCCION DE ALMACENAMIENTO
    if(instruction_is_load_or_store(instr_to_exec)){
        this->execute_instruction_load_or_store(instr_to_exec);
        // --- Incrementar contador de programa
        this->program_counter++;
    }
    // ---- INSTRUCCION DE OPERACION BINARIA
    else if(instruction_is_binary_operation(instr_to_exec)){
        this->execute_instruction_binary_operation(instr_to_exec);
        // --- Incrementar contador de programa
        this->program_counter++;
    }
    // ---- INSTRUCCION DE OPERACION UNARIA
    else if(instruction_is_unary_operation(instr_to_exec)){
        this->execute_instruction_unary_operation(instr_to_exec);
        // --- Incrementar contador de programa
        this->program_counter++;
    }
    // ---- INSTRUCCION DE IMPRESION
    else if(instruction_is_print(instr_to_exec)){
        this->execute_instruction_print(instr_to_exec);
        // --- Incrementar contador de programa
        this->program_counter++;
    }
    // ---- INSTRUCCION DE ETIQUETA
    else if(instruction_is_label_pointer(instr_to_exec)){
        // --- Incrementar contador de programa
        this->program_counter++;
    }
    // ---- INSTRUCCION DE SALTO
    else if(this->instruction_is_jump(instr_to_exec)){
        this->execute_instruction_jump(instr_to_exec);
    }
    // ---- OPERACION NO SOPORTADA
    else{
        throw std::invalid_argument("INSTRUCCIÓN NO SOPORTADA.");
    }

}

void LVM::execute_instruction_load_or_store(IR_instruction & instr){
    const IR_instruction_type_t instr_code = instr.get_code_instr();

    switch (instr_code)
    {
    case IR_OP_LOAD:
    {
        this->execute_instruction_load(instr);
        break;
    }
    case IR_OP_STORE:
    {
        this->execute_instruction_store(instr);
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

void LVM::execute_instruction_binary_operation(const IR_instruction & instr){
    // -- 1. Elementos para ejecucion
    // ---- Direccion a registro destino
    int reg_addr_dest;
    // ---- Operando destino
    IR_operand op_dest;
    // ---- Registros
    LVM_Register reg_dest, reg_op_1, reg_op_2;
    std::vector<LVM_Register> registers;

    // -- Obtener operando destino
    op_dest = *instr.get_operand_destiny();
    // -- Obtener direcciones de registros
    reg_addr_dest = op_dest.get_address();

    // -- Obtener registros
    registers = this->get_registers_from_operands(instr);
    reg_dest = registers[0];
    reg_op_1 = registers[1];
    reg_op_2 = registers[2];

    // -- Obtener codigo de instruccion
    IR_instruction_type_t instr_code = instr.get_code_instr();

    // -- Realizar operacion en funcion de codigo
    switch (instr_code)
    {
    // ---- OPERACIONES ARITMETICAS
    case IR_OP_ADD:
    {
        reg_dest = reg_op_1 + reg_op_2;
        break;
    }
    case IR_OP_SUB:
    {
        reg_dest = reg_op_1 - reg_op_2;
        break;
    }
    case IR_OP_MULT:
    {
        reg_dest = reg_op_1 * reg_op_2;
        break;
    }
    case IR_OP_DIV:
    {
        reg_dest = reg_op_1 / reg_op_2;
        break;
    }
    case IR_OP_MOD:
    {
        reg_dest = reg_op_1 % reg_op_2;
        break;
    }
    // ---- OPERACIONES DE COMPARACION
    case IR_OP_CMP_LT:
    {
        reg_dest = reg_op_1 < reg_op_2;
        break;
    }
    case IR_OP_CMP_LTE:
    {
        reg_dest = reg_op_1 <= reg_op_2;
        break;
    }
    case IR_OP_CMP_GT:
    {
        reg_dest = reg_op_1 > reg_op_2;
        break;
    }
    case IR_OP_CMP_GTE:
    {
        reg_dest = reg_op_1 >= reg_op_2;
        break;
    }
    case IR_OP_CMP_EQ:
    {
        reg_dest = reg_op_1 == reg_op_2;
        break;
    }
    case IR_OP_CMP_NEQ:
    {
        reg_dest = reg_op_1 != reg_op_2;
        break;
    }
    // ---- OPERACIONES LOGICAS
    case IR_OP_AND:
    {
        reg_dest = reg_op_1 && reg_op_2;
        break;
    }
    case IR_OP_OR:
    {
        reg_dest = reg_op_1 || reg_op_2;
        break;
    }

    default:
        throw std::invalid_argument("OPERACIÓN BINARIA NO SOPORTADA.");
        break;
    }

    // -- Incluir el registro de destino en la tabla de registros
    this->register_table[reg_addr_dest] = reg_dest;
}

void LVM::execute_instruction_unary_operation(const IR_instruction & instr){
        // -- 1. Elementos para ejecucion
    // ---- Direccion a registro destino
    int reg_addr_dest;
    // ---- Operando destino
    IR_operand op_dest;
    // ---- Registros
    LVM_Register reg_dest, reg_op_1;
    std::vector<LVM_Register> registers;

    // -- Obtener operando destino
    op_dest = *instr.get_operand_destiny();
    // -- Obtener direcciones de registros
    reg_addr_dest = op_dest.get_address();

    // -- Obtener registros
    registers = this->get_registers_from_operands(instr);
    reg_dest = registers[0];
    reg_op_1 = registers[1];

    // -- Obtener codigo de instruccion
    IR_instruction_type_t instr_code = instr.get_code_instr();

    // -- Realizar operacion en funcion de codigo
    switch (instr_code)
    {
    case IR_OP_NEG:
    {
        reg_dest = -reg_op_1;
        break;
    }
    case IR_OP_NOT:
    {
        reg_dest = !reg_op_1;
        break;
    }
    
    default:
        throw std::invalid_argument("OPERACIÓN UNARIA NO SOPORTADA.");
        break;
    }

    // -- Incluir el registro de destino en la tabla de registros
    this->register_table[reg_addr_dest] = reg_dest;
}

void LVM::execute_instruction_jump(const IR_instruction & instr){
    // 1.B Elementos para ejecucion
    // ---- Operandos de instruccion
    IR_operand op_1, op_2;
    // ---- Direccion a registro
    int register_address;
    // ---- Direccion a memoria fisica
    int phisical_address;
    // ---- Registro
    LVM_Register reg;
    // ---- Bloque de memoria
    LVM_Memory_Block mem_block;

    // -- Comprobar en funcion del tipo de salto
    switch (instr.get_code_instr())
    {
    case IR_OP_JMP:
    {   
        // -- Obtener operando 1 (bloque de memoria)
        op_1 = *instr.get_operand_1();
        
        // -- Obtener direccion fisica
        phisical_address = this->get_phisical_address_from_operand(op_1);

        // -- Obtener bloque
        mem_block = this->memory[phisical_address];

        // -- Obtener direccion de salto
        this->program_counter = mem_block.get_value<long>();

        break;
    }
    case IR_OP_JMP_FALSE:
    {
        // -- Obtener operando 1 (registro)
        op_1 = *instr.get_operand_1();
        // -- Obtener operando 2 (bloque de memoria)
        op_2 = *instr.get_operand_2();

        // -- Obtener direccion de registro
        register_address = op_1.get_address();
        // -- Obtener direccion fisica
        phisical_address = this->get_phisical_address_from_operand(op_2);

        // -- Obtener registro
        reg = this->register_table[register_address];
        // -- Obtener bloque de memoria
        mem_block = this->memory[phisical_address];

        // -- Comprobar si el valor de reg es falso, y en ese caso, saltar
        if(reg.get_value<bool>() == false){
            // -- Saltar
            this->program_counter = mem_block.get_value<long>();
        }
        else{
            // -- Continuar flujo normal de instrucciones
            this->program_counter++;
        }


        break;
    }
    case IR_OP_JMP_TRUE:
    {
        // -- Obtener operando 1 (registro)
        op_1 = *instr.get_operand_1();
        // -- Obtener operando 2 (bloque de memoria)
        op_2 = *instr.get_operand_2();

        // -- Obtener direccion de registro
        register_address = op_1.get_address();
        // -- Obtener direccion fisica
        phisical_address = this->get_phisical_address_from_operand(op_2);

        // -- Obtener registro
        reg = this->register_table[register_address];
        // -- Obtener bloque de memoria
        mem_block = this->memory[phisical_address];

        // -- Comprobar si el valor de reg es falso, y en ese caso, saltar
        if(reg.get_value<bool>() == true){
            // -- Saltar
            this->program_counter = mem_block.get_value<long>();
        }
        else{
            // -- Continuar flujo normal de instrucciones
            this->program_counter++;
        }

        break;
    }
    
    default:
        break;
    }

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
        std::cout << reg.get_value_str();
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

LVM::~LVM(){
    if(this->state != LVM_STATE_DEAD)
        this->state = LVM_STATE_SHUTDOWN;
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