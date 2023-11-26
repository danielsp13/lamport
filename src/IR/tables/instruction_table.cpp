/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file instruction_table.cpp
 * @author Daniel Perez Ruiz
 * @brief Contenedor de instrucciones de codigo intermedio Lineal (IR)
 */

#include "IR/tables/instruction_table.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [INSTRUCTION TABLE] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [INSTRUCTION TABLE] -----

IR_Instruction_Table& IR_Instruction_Table::get_instance(){
    static IR_Instruction_Table instance;
    return instance;
}

IR_operand IR_Instruction_Table::emit_operand_register(int id_reg){
    IR_operand op(IR_OPERAND_REGISTER,id_reg);
    return op;
}

IR_operand IR_Instruction_Table::emit_operand_literal(int id_lit){
    IR_operand op(IR_OPERAND_LITERAL,id_lit);
    return op;
}

IR_operand IR_Instruction_Table::emit_operand_variable(int id_var){
    IR_operand op(IR_OPERAND_VARIABLE,id_var);
    return op;
}

IR_operand IR_Instruction_Table::emit_operand_variable_array(int id_var, int offset){
    IR_operand op(IR_OPERAND_VARIABLE_ARRAY,id_var,offset);
    return op;
}

IR_operand IR_Instruction_Table::emit_operand_variable_index(int id_var){
    IR_operand op(IR_OPERAND_VARIABLE_INDEX,id_var);
    return op;
}

IR_operand IR_Instruction_Table::emit_operand_label(int id_label){
    IR_operand op(IR_OPERAND_LABEL,id_label);
    return op;
}

IR_operand IR_Instruction_Table::emit_operand_id_thread(int id_thread){
    IR_operand op(IR_OPERAND_THREAD_ID,id_thread);
    return op;
}

IR_operand IR_Instruction_Table::emit_operand_direct_jmp(int jmp_addr){
    IR_operand op(IR_OPERAND_DIRECT_JMP,jmp_addr);
    return op;
}

std::string IR_Instruction_Table::get_next_label_id(){
    return std::to_string(id_label_annonymous++);
}

void IR_Instruction_Table::add_instruction_to_list(IR_instruction instr){
    // -- Insertar en lista de instrucciones
    this->instruction_table.push_back(instr);
}

void IR_Instruction_Table::add_instruction_to_list_in_position(IR_instruction instr, int position){
    // -- Insertar en la lista de instrucciones
    this->instruction_table.insert(instruction_table.begin() + position, instr);
}

void IR_Instruction_Table::replace_instruction_in_position(IR_instruction instr, int position){
    instruction_table[position] = instr;
}

void IR_Instruction_Table::emit_instruction(IR_instruction_type_t code_instr){
    // -- Crear instruccion
    IR_instruction instr(code_instr);

    // -- Incluir
    this->add_instruction_to_list(instr);
}

void IR_Instruction_Table::emit_instruction(IR_instruction_type_t code_instr, IR_operand op_1){
    // -- Crear instruccion
    IR_instruction instr(code_instr,op_1);

    // -- Incluir
    this->add_instruction_to_list(instr);
}

void IR_Instruction_Table::emit_instruction(IR_instruction_type_t code_instr, IR_operand op_dest, IR_operand op_1){
    // -- Crear instruccion
    IR_instruction instr(code_instr,op_dest,op_1);

    // -- Incluir
    this->add_instruction_to_list(instr);
}

void IR_Instruction_Table::emit_instruction(IR_instruction_type_t code_instr, IR_operand op_dest, IR_operand op_1, IR_operand op_2){
    // -- Crear instruccion
    IR_instruction instr(code_instr,op_dest,op_1,op_2);

    // -- Incluir
    this->add_instruction_to_list(instr);
}

void IR_Instruction_Table::emit_instruction(IR_instruction_type_t code_instr, bool dest, IR_operand op_1, IR_operand op_2){
    // -- Crear instruccion
    IR_instruction instr(code_instr,false,op_1,op_2);

    // -- Incluir
    this->add_instruction_to_list(instr);
}

IR_instruction& IR_Instruction_Table::operator[](int i){
    return this->instruction_table[i];
}

const IR_instruction& IR_Instruction_Table::operator[](int i) const{
    return this->instruction_table[i];
}