/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file instruction_table.cpp
 * @author Daniel Perez Ruiz
 * @brief Contenedor de instrucciones de codigo intermedio Lineal (IR)
 */

#include "IR/instruction_table.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [INSTRUCTION TABLE] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [INSTRUCTION TABLE] -----

IR_Instruction_Table& IR_Instruction_Table::get_instance(){
    static IR_Instruction_Table instance;
    return instance;
}

void IR_Instruction_Table::add_instruction_to_list(IR_instruction instr){
    // -- Insertar en lista de instrucciones
    this->instruction_table.push_back(instr);

    // -- Insertar en la lista de instrucciones en string
    printer.add_ir_instruction_to_printer(instr);
}

void IR_Instruction_Table::add_instruction_to_list_in_position(IR_instruction instr, int position){
    // -- Insertar en la lista de instrucciones
    this->instruction_table.insert(instruction_table.begin() + position, instr);

    // -- Insertar en la lista de instrucciones en string
    printer.add_ir_instruction_to_printer(instr,position);
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

IR_instruction& IR_Instruction_Table::operator[](int i){
    return this->instruction_table[i];
}

const IR_instruction& IR_Instruction_Table::operator[](int i) const{
    return this->instruction_table[i];
}