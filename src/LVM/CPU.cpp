/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file CPU.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de CPU para la maquina virtual de lamport
 */

#include "LVM/CPU.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [CPU] -----

int LVM_CPU::get_phisical_address_from_operand(const IR_operand & op){
    // -- Variable para direccion fisica
    int phisical_address;
    // -- Variable para segmento de memoria
    int virtual_segment;
    // -- Variable para direccion virtual
    int virtual_address = op.get_address();
    // -- Variable para offset (solo para variables de tipo array)
    int reg_index_offset = op.get_offset();
    
    switch (op.get_kind())
    {
    case IR_OPERAND_LITERAL:
    {
        virtual_segment = segments_table.SEGMENT_FOR_LITERALS;
        break;
    }
    case IR_OPERAND_VARIABLE:
    {
        virtual_segment = 0;//segments_table.SEGMENT_FOR_VARIABLES;
        break;
    }
    case IR_OPERAND_VARIABLE_ARRAY:
    {
        virtual_segment = 0;//segments_table.SEGMENT_FOR_VARIABLES_ARRAY;

        // -- Obtener el registro que contiene el offset, y a continuacion el offset
        LVM_Register reg_offset = register_table[reg_index_offset];
        int offset = reg_offset.get_value<int>();

        // -- Comprobar limites de offset (negativo)
        bounds_arrays.check_if_is_negative_offset(offset);

        // -- Preobtener direccion fisica
        phisical_address = this->segments_table(virtual_segment,virtual_address,offset);

        // -- Comprobar limites de array
        bounds_arrays.check_if_exceds_bound(virtual_address,phisical_address,offset);

        // -- Retornar direccion fisica
        return phisical_address;

        break;
    }
    case IR_OPERAND_LABEL:
    {
        virtual_segment = segments_table.SEGMENT_FOR_LABELS;
        break;
    }
    default:
        throw std::invalid_argument("SEGMENTO VIRTUAL DE OPERANDO INVALIDO.");
        break;
    }

    // -- Obtener direccion fisica mirando en la tabla de paginas
    phisical_address = this->segments_table(virtual_segment,virtual_address);

    // -- Retornar direccion fisica
    return phisical_address;
}

inline bool LVM_CPU::instruction_is_start_or_end_process(const IR_instruction & instr){
    bool result = false;
    const IR_instruction_type_t kind = instr.get_code_instr();

    result = kind == IR_START_PROCESS;
    result = result == true ? true : kind == IR_END_PROCESS;

    return result;
}
        
inline bool LVM_CPU::instruction_is_start_or_end_program(const IR_instruction & instr){
    bool result = false;
    const IR_instruction_type_t kind = instr.get_code_instr();

    result = kind == IR_END_PROGRAM;
    result = result == true ? true : kind == IR_START_PROGRAM;

    return result;
}

inline bool LVM_CPU::instruction_is_load_or_store(const IR_instruction & instr){
    bool result = false;
    const IR_instruction_type_t kind = instr.get_code_instr();

    result = kind == IR_OP_LOAD;
    result = result == true ? true : kind == IR_OP_STORE;

    return result;
}

inline bool LVM_CPU::instruction_is_label_pointer(const IR_instruction & instr){
    bool result = false;
    const IR_instruction_type_t kind = instr.get_code_instr();

    result = kind == IR_LABEL;

    return result;
}

inline bool LVM_CPU::instruction_is_binary_operation(const IR_instruction & instr){
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

inline bool LVM_CPU::instruction_is_unary_operation(const IR_instruction & instr){
    bool result = false; 
    const IR_instruction_type_t kind = instr.get_code_instr();
    
    result = kind == IR_OP_NEG;
    result = result == true ? true : kind == IR_OP_NOT;

    return result;
}

inline bool LVM_CPU::instruction_is_jump(const IR_instruction & instr){
    bool result = false; 
    const IR_instruction_type_t kind = instr.get_code_instr();
    
    result = kind == IR_OP_JMP;
    result = result == true ? true : kind == IR_OP_JMP_FALSE;
    result = result == true ? true : kind == IR_OP_JMP_TRUE;

    return result;
}

inline bool LVM_CPU::instruction_is_print(const IR_instruction & instr){
    bool result = false; 
    const IR_instruction_type_t kind = instr.get_code_instr();
    
    result = kind == IR_OP_PRINT;

    return result; 
}

inline bool LVM_CPU::instruction_is_push_or_pop(const IR_instruction & instr){
    bool result = false; 
    const IR_instruction_type_t kind = instr.get_code_instr();
    
    result = kind == IR_OP_PUSH;
    result = result == true ? true : kind == IR_OP_PUSH_LOCAL;
    result = result == true ? true : kind == IR_OP_POP;
    result = result == true ? true : kind == IR_OP_POP_LOCAL;

    return result; 
}

inline bool LVM_CPU::instruction_is_call_or_ret_subprogram(const IR_instruction & instr){
    bool result = false; 
    const IR_instruction_type_t kind = instr.get_code_instr();
    
    result = kind == IR_OP_CALL;
    result = result == true ? true : kind == IR_OP_RET;

    return result; 
}

inline bool LVM_CPU::instruction_is_not_instruction(const IR_instruction & instr){
    bool result = false; 
    const IR_instruction_type_t kind = instr.get_code_instr();
    
    result = kind == NOT_IR_END_SUBPROGRAM_INSTR;
    result = result == true ? true : kind == NOT_IR_START_SUBPROGRAM_INSTR;

    return result;  
}

std::vector<LVM_Register> LVM_CPU::get_registers_from_operands(const IR_instruction & instr){
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

void LVM_CPU::execute_instruction(const IR_instruction & instr_to_exec){
    // -- Decidir accion
    // ---- INSTRUCCION DE COMIENZO/FIN DE PROCESO
    if(instruction_is_start_or_end_process(instr_to_exec)){
        this->execute_instruction_start_or_end_process(instr_to_exec);
    }
    // ---- INSTRUCCION DE ALMACENAMIENTO
    else if(instruction_is_load_or_store(instr_to_exec)){
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
    // ---- INSTRUCCION DE PUSH/POP EN PILA
    else if(this->instruction_is_push_or_pop(instr_to_exec)){
        this->execute_instruction_push_or_pop(instr_to_exec);
        this->program_counter++;
    }
    // ---- INSTRUCCION DE CALL/RET DE SUBPROGRAMA
    else if(this->instruction_is_call_or_ret_subprogram(instr_to_exec)){
        this->execute_instruction_call_or_ret(instr_to_exec);
    }
    // ---- INSTRUCCION DE INICIO/FIN DE PROGRAMA
    else if(this->instruction_is_start_or_end_program(instr_to_exec)){
        this->execute_instruction_start_or_end_program(instr_to_exec);
    }
    // ---- INSTRUCCION NOT INSTRUCTION
    else if(this->instruction_is_not_instruction(instr_to_exec)){
        this->program_counter++;
    }
    // ---- OPERACION NO SOPORTADA
    else{
        throw std::invalid_argument("INSTRUCCIÓN NO SOPORTADA. ("  + instr_to_exec.get_code_instr_str() + ")");
    }

}

void LVM_CPU::execute_instruction_start_or_end_process(const IR_instruction & instr){
    switch (instr.get_code_instr())
    {
    case IR_START_PROCESS:
    {
        this->execute_instruction_start_process(instr);
        break;
    }
    case IR_END_PROCESS:
    {
        this->execute_instruction_end_process(instr);
        break;
    }
    
    default:
        break;
    }
}

void LVM_CPU::execute_instruction_start_process(const IR_instruction & instr){
    // -- Incrementar el contador de programa a siguiente instruccion
    this->program_counter++;
}

void LVM_CPU::execute_instruction_end_process(const IR_instruction & instr){
    IR_Instruction_Table& instructions = IR_Instruction_Table::get_instance();
    
    // -- 1. Buscar otro proceso
    for(int i=this->program_counter; i<total_instructions; i++){
        // -- 2. Buscar un start process
        if(instructions[i].get_code_instr() == IR_START_PROCESS){
            this->program_counter = i;
            return;
        }

        // -- 2. Buscar un end program
        if(instructions[i].get_code_instr() == IR_END_PROGRAM){
            this->program_counter = i;
            return;
        }
    }

}

void LVM_CPU::execute_instruction_start_or_end_program(const IR_instruction & instr){
    switch (instr.get_code_instr())
    {
    case IR_START_PROGRAM:
    {
        this->execute_instruction_start_program(instr);
        break;
    }
    case IR_END_PROGRAM:
    {
        this->execute_instruction_end_program(instr);
        break;
    }
    
    default:
        break;
    }
}

void LVM_CPU::execute_instruction_start_program(const IR_instruction & instr){
    // ---- Incrementar contador de programa
    this->program_counter++;
    // ---- Recorrer instrucciones
    bool start_subprog_reached = false, end_subprog_reached = false;
    for(int i=this->program_counter; i<total_instructions; i++){
        // ---- Recuperar instruccion
        IR_instruction instr = instructions[i];
        // ---- Comprobar si se ha alcanzado el inicio de seccion de subprogramas
        if(instr.get_code_instr() == NOT_IR_START_SUBPROGRAM_INSTR && !start_subprog_reached)
            start_subprog_reached = true;
        // ---- Comprobar si se ha alcanzado el fin de seccion de subprogramas
        else if(instr.get_code_instr() == NOT_IR_END_SUBPROGRAM_INSTR && !end_subprog_reached)
            end_subprog_reached = true;
        // ---- Comprobar si se ha alcanzado el inicio de un proceso
        else if(instr.get_code_instr() == IR_START_PROCESS)
            return;

        // ---- Comprobar casos
        if(!start_subprog_reached)
            this->execute_instruction(instr);
        else if(!end_subprog_reached)
            this->program_counter++;
    }
}

void LVM_CPU::execute_instruction_end_program(const IR_instruction & instr){
    this->program_counter = total_instructions+1;
}

void LVM_CPU::execute_instruction_load_or_store(const IR_instruction & instr){
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


void LVM_CPU::execute_instruction_load(const IR_instruction & instr){
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


void LVM_CPU::execute_instruction_store(const IR_instruction & instr){
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

    // -- Comprobar si operando de destino es un registro o acceso a memoria
    if(op_dest.get_kind() == IR_OPERAND_REGISTER){
        // -- Obtener direccion de registro
        int addr_reg_destiny = op_dest.get_address();

        this->register_table[addr_reg_destiny] = this->register_table[register_address];
    }
    // -- En caso contrario, se trata de una variable en memoria
    else{
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
            throw std::invalid_argument("CONTENIDO DE REGISTRO PARA OP_STORE INVÁLIDO, INSTRUCCION [" + std::to_string(this->program_counter) + "].");
            break;
        }

        // -- Almacenar el bloque de memoria en la direccion fisica especificada
        this->memory[phisical_address] = mem_block;
    }
}

void LVM_CPU::execute_instruction_binary_operation(const IR_instruction & instr){
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

    IR_operand op_1 = *instr.get_operand_1();
    IR_operand op_2 = *instr.get_operand_2();

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

void LVM_CPU::execute_instruction_unary_operation(const IR_instruction & instr){
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

void LVM_CPU::execute_instruction_jump(const IR_instruction & instr){
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

void LVM_CPU::execute_instruction_print(const IR_instruction & instr){
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

void LVM_CPU::execute_instruction_call_or_ret(const IR_instruction & instr){
    // Decidir
    switch (instr.get_code_instr())
    {
    case IR_OP_CALL:
    {
        this->execute_instruction_call(instr);
        break;
    }
    case IR_OP_RET:
    {
        this->execute_instruction_ret(instr);
        break;
    }
    
    default:
        break;
    }
}

void LVM_CPU::execute_instruction_call(const IR_instruction & instr){
    // Crear un contexto nuevo y almacenar el estado actual de la maquina virtual
    LVM_Context new_context;
    // --- Guardar contador de programa actual
    new_context.program_counter = this->program_counter;
    // --- Guardar tabla de registros
    new_context.register_table = this->register_table.get_registers();
    // --- Realizar push de contexto en pila
    stack_contexts.push(new_context);

    // -- Obtener operando de instruccion
    IR_operand op_call = *instr.get_operand_1();
    // -- Obtener direccion fisica
    int phisical_address = this->get_phisical_address_from_operand(op_call);

    // -- Obtener bloque de memoria
    LVM_Memory_Block mem_block = this->memory[phisical_address];

    // -- Obtener direccion de etiqueta
    int call_addr = static_cast<int>(mem_block.get_value<long>());

    // -- Contador de programa apunta a principio de subprograma
    this->program_counter = call_addr;
}

void LVM_CPU::execute_instruction_ret(const IR_instruction & instr){
    // --- Obtener el contexto guardado
    LVM_Context old_context = stack_contexts.top();
    // --- Devolver contador de programa a estado original
    this->program_counter = old_context.program_counter;
    this->program_counter++;
    // --- Devolver tabla de registros
    for(int i=reg_manager.get_return_subprog_register()+1; i<old_context.register_table.size();i++){
        this->register_table[i] = old_context.register_table[i];
    }

    // FUTURE
}

void LVM_CPU::execute_instruction_push_or_pop(const IR_instruction & instr){
    // Decidir
    switch (instr.get_code_instr())
    {
    case IR_OP_PUSH:
    {
        this->execute_instruction_push(instr);
        break;
    }
    case IR_OP_POP:
    {
        this->execute_instruction_pop(instr);
        break;
    }
    
    default:
        break;
    }
}

void LVM_CPU::execute_instruction_push(const IR_instruction & instr, bool from_local){
    // -- Obtener operando de direccion de registro
    IR_operand op_reg = *instr.get_operand_1();
    // -- Obtener direccion de registro
    int reg_addr = op_reg.get_address();
    // -- Obtener registro
    LVM_Register reg = register_table[reg_addr];
    // -- Generar bloque de pila e insertar
    LVM_Stack_Block stack_block;

    switch (reg.get_type_of_alloc())
    {
    case REG_CONTAINS_INTEGER:
    {
        stack_block.allocate_value<int>(reg.get_value<int>());
        break;
    }
    case REG_CONTAINS_REAL:
    {
        stack_block.allocate_value<float>(reg.get_value<float>());
        break;
    }
    case REG_CONTAINS_CHAR:
    {
        stack_block.allocate_value<char>(reg.get_value<char>());
        break;
    }
    case REG_CONTAINS_STRING:
    {
        stack_block.allocate_value<std::string>(reg.get_value<std::string>());
        break;
    }
    case REG_CONTAINS_BOOL:
    {
        stack_block.allocate_value<bool>(reg.get_value<bool>());
        break;
    }
    default:
        throw std::invalid_argument("NO SE PUDO ALOJAR UN BLOQUE DE PILA CORRECTAMENTE.");
        break;
    }

    // -- Realizar push del bloque en la pila
    stack.push(stack_block);
}

void LVM_CPU::execute_instruction_push_local(const IR_instruction & instr){
    this->execute_instruction_push(instr,true);
}

void LVM_CPU::execute_instruction_pop(const IR_instruction & instr, bool from_local){
    // -- Obtener operando de direccion de registro
    IR_operand op_reg = *instr.get_operand_1();
    // -- Obtener direccion de registro
    int reg_addr = op_reg.get_address();
    // -- Obtener bloque de pila (tope)
    LVM_Stack_Block stack_block = stack.top(); stack.pop();
    // -- Generar registro
    LVM_Register reg;

    switch (stack_block.get_type_of_alloc())
    {
    case STACK_BLOCK_INTEGER:
    {
        reg.allocate_value<int>(stack_block.get_value<int>());
        break;
    }
    case STACK_BLOCK_REAL:
    {
        reg.allocate_value<float>(stack_block.get_value<float>());
        break;
    }
    case STACK_BLOCK_CHAR:
    {
        reg.allocate_value<char>(stack_block.get_value<char>());
        break;
    }
    case STACK_BLOCK_STRING:
    {
        reg.allocate_value<std::string>(stack_block.get_value<std::string>());
        break;
    }
    case STACK_BLOCK_BOOL:
    {
        reg.allocate_value<bool>(stack_block.get_value<bool>());
        break;
    }
    default:
        throw std::invalid_argument("NO SE PUDO ALOJAR UN BLOQUE DE PILA CORRECTAMENTE.");
        break;
    }

    // -- Volver a asignar registro a tabla
    this->register_table[reg_addr] = reg;

}

void LVM_CPU::execute_instruction_pop_local(const IR_instruction & instr){
    this->execute_instruction_pop(instr,true);
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [CPU] -----

LVM_CPU& LVM_CPU::get_instance(){
    static LVM_CPU instance;
    return instance;
}

void LVM_CPU::execute_instructions(){
    while(get_program_counter() < total_instructions){
        //std::cout << "PC: " << program_counter << std::endl;
        execute_instruction(instructions[this->program_counter]);
    }
}