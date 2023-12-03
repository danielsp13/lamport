/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ALU.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion de ALU de CPU para la maquina virtual de lamport
 */

#include "LVM/CPU/ALU.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [ALU] -----



// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [ALU] -----


LVM_CPU_ALU& LVM_CPU_ALU::get_instance(){
    static LVM_CPU_ALU instance;
    return instance;
}

void LVM_CPU_ALU::execute_binary_operation(IR_instruction_type_t instr_code, int reg_dest, int reg_op_1, int reg_op_2){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Ejecutando operacion: ";

    int binary_op = -1;
    if(instr_code == IR_OP_ADD_I || instr_code == IR_OP_ADD_F){
        binary_op = 0;
    }
    if(instr_code == IR_OP_SUB_I || instr_code == IR_OP_SUB_F){
        binary_op = 1;
    }
    if(instr_code == IR_OP_MULT_I || instr_code == IR_OP_MULT_F){
        binary_op = 2;
    }
    if(instr_code == IR_OP_DIV_I || instr_code == IR_OP_DIV_F){
        binary_op = 3;
    }
    if(instr_code == IR_OP_MOD_I){
        binary_op = 4;
    }
    if(instr_code == IR_OP_CMP_LT){
        binary_op = 5;
    }
    if(instr_code == IR_OP_CMP_LTE){
        binary_op = 6;
    }
    if(instr_code == IR_OP_CMP_GT){
        binary_op = 7;
    }
    if(instr_code == IR_OP_CMP_GTE){
        binary_op = 8;
    }
    if(instr_code == IR_OP_CMP_EQ){
        binary_op = 9;
    }
    if(instr_code == IR_OP_CMP_NEQ){
        binary_op = 10;
    }
    if(instr_code == IR_OP_AND){
        binary_op = 11;
    }
    if(instr_code == IR_OP_OR){
        binary_op = 12;
    }

    // -- Determinar tipo de operacion a ejecutar
    switch (binary_op)
    {
    // ---- OPERACIONES ARITMETICAS
    case 0:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " + " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";

        registers[reg_dest] = registers[reg_op_1] + registers[reg_op_2];
        break;
    }
    case 1:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " - " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";

        registers[reg_dest] = registers[reg_op_1] - registers[reg_op_2];
        break;
    }
    case 2:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " * " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";

        registers[reg_dest] = registers[reg_op_1] * registers[reg_op_2];
        break;
    }
    case 3:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " / " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";

        registers[reg_dest] = registers[reg_op_1] / registers[reg_op_2];
        break;
    }
    case 4:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " % " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";

        registers[reg_dest] = registers[reg_op_1] % registers[reg_op_2];
        break;
    }

    // ---- OPERACIONES DE COMPARACION
    case 5:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " < " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";

        registers[reg_dest] = registers[reg_op_1] < registers[reg_op_2];
        break;
    }
    case 6:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " <= " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";

        registers[reg_dest] = registers[reg_op_1] <= registers[reg_op_2];
        break;
    }
    case 7:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " > " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";

        registers[reg_dest] = registers[reg_op_1] > registers[reg_op_2];
        break;
    }
    case 8:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " >= " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";

        registers[reg_dest] = registers[reg_op_1] >= registers[reg_op_2];
        break;
    }
    case 9:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " == " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";
        
        registers[reg_dest] = registers[reg_op_1] == registers[reg_op_2];
        break;
    }
    case 10:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " != " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";

        registers[reg_dest] = registers[reg_op_1] != registers[reg_op_2];
        break;
    }
    
    // ---- OPERACIONES LOGICAS
    case 11:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " and " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";

        registers[reg_dest] = registers[reg_op_1] && registers[reg_op_2];
        break;
    }
    case 12:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")" + " or " + "%r" + std::to_string(reg_op_2) + "(" + registers[reg_op_2].get_value_str() + ")";

        registers[reg_dest] = registers[reg_op_1] || registers[reg_op_2];
        break;
    }

    default:
        throw std::invalid_argument("OPERACIÓN BINARIA NO SOPORTADA.");
        break;
    }

    tracker.track(tracker_msg,true);
}


void LVM_CPU_ALU::execute_unary_operation(IR_instruction_type_t instr_code, int reg_dest, int reg_op_1){
    // -- Registrar en traza de ejecucion
    std::string tracker_msg = TRACKER_HEADER + "Ejecutando operacion: ";

    int unary_op = -1;
    if(instr_code == IR_OP_NEG_I || instr_code == IR_OP_NEG_F){
        unary_op = 0;
    }
    if(instr_code == IR_OP_NOT){
        unary_op = 1;
    }
    
    // -- Determinar tipo de operacion a ejecutar
    switch (unary_op)
    {
    case 0:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "-" + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")";

        registers[reg_dest] = -registers[reg_op_1];
        break;
    }
    case 1:
    {
        tracker_msg += "%r" + std::to_string(reg_dest) + " = " + "not " + "%r" + std::to_string(reg_op_1) + "(" + registers[reg_op_1].get_value_str() + ")";

        registers[reg_dest] = !registers[reg_op_1];
        break;
    }
    
    default:
        throw std::invalid_argument("OPERACIÓN UNARIA NO SOPORTADA.");
        break;
    }

    tracker.track(tracker_msg,true);
}