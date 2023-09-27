/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_builder.cpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del constructor de codigo intermedio Lineal (IR)
 */

#include "IR/ir_builder.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS DE CLASE IR MANAGER (GESTION DE INSTANCIA) -----

IR_Builder& IR_Builder::get_instance(){
    static IR_Builder instance;
    return instance;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_MANAGER] -----

std::string IR_Builder::ir_code_instruction_to_string(IR_instruction_type_t instr_code){
    // -- Definir codigo de instruccion str
    std::string instr_code_str = "<unknown code_instruction>";

    auto it = instructions_str.find(instr_code);
    if(it != instructions_str.end())
        instr_code_str = it->second;

    // -- Retornar codigo de instruccion
    return instr_code_str;
}

std::string IR_Builder::ir_operand_instruction_to_string(IR_operand op){
    // -- Definir operando de instruccion str
    std::string instr_op_str = "";

    // -- Obtener tipo de operando y direccion
    IR_operand_t kind = op.get_kind();
    int address = op.get_address();

    // -- Comprobar que tipo de operando es
    switch (kind)
    {
    case IR_operand_t::IR_OPERAND_REGISTER:
    {
        instr_op_str = "%r" + std::to_string(address);
        break;
    }
    case IR_operand_t::IR_OPERAND_LITERAL:
    {
        instr_op_str = "$" + tables.get_entry_literal(address)->to_string();
        break;
    }
    case IR_operand_t::IR_OPERAND_VARIABLE:
    {
        instr_op_str = tables.get_entry_variable(address)->to_string();
        break;
    }
    case IR_operand_t::IR_OPERAND_LABEL:
    {
        instr_op_str = tables.get_entry_label(address)->get_label();
        break;
    }
    
    default:
        break;
    }

    // -- Retornar operando str
    return instr_op_str;
}

std::string IR_Builder::ir_instruction_to_string(unsigned int index){
    // -- Definir instruccion
    std::string instr_str = "";

    // -- Comprobar indices de acceso
    if(0 > index || index >= ir_instructions.size())
        return std::string("<unknown instruction>");

    // -- Obtener instruccion
    IR_instruction instr = ir_instructions[index];

    // -- Obtener codigo de instruccion y su conversion a string
    std::string instr_code_str = this->ir_code_instruction_to_string(instr.get_code_instr()) + " ";

    // -- Obtener operando de instruccion (destino)
    std::optional<IR_operand> instr_op_destiny = instr.get_operand_destiny();
    std::string instr_op_destiny_str = "";
    if(instr_op_destiny.has_value()){
        instr_op_destiny_str = this->ir_operand_instruction_to_string(instr_op_destiny.value()) + " <--- ";
    }

    // -- Obtener primer operando
    std::optional<IR_operand> instr_op_1 = instr.get_operand_1();
    std::string instr_op_1_str = "";
    if(instr_op_1.has_value()){
        instr_op_1_str = this->ir_operand_instruction_to_string(instr_op_1.value());
    }

    // -- Obtener segundo operando
    std::optional<IR_operand> instr_op_2 = instr.get_operand_2();
    std::string instr_op_2_str = "";
    if(instr_op_2.has_value()){
        instr_op_2_str = " , " + this->ir_operand_instruction_to_string(instr_op_2.value());
    }

    // -- Obtener instruccion str final
    instr_str = instr_code_str + instr_op_destiny_str + instr_op_1_str + instr_op_2_str;

    // -- Retornar string de instruccion
    return instr_str;
}

void IR_Builder::print_ir_instructions(FILE * output){
    std::string instr_str;

    for(unsigned int i=0; i<this->ir_instructions.size(); i++){
        instr_str = this->ir_instruction_to_string(i);
        fprintf(output, "%s\n",instr_str.c_str());
    }
}

void IR_Builder::add_instruction(IR_instruction_type_t code_instr){
    // -- Crear instruccion
    IR_instruction instr(code_instr);

    // -- Insertar en lista de instrucciones
    this->ir_instructions.push_back(instr);
}

void IR_Builder::add_instruction(IR_instruction_type_t code_instr, IR_operand op_1){
    // -- Crear instruccion
    IR_instruction instr(code_instr,op_1);

    // -- Insertar en lista de instrucciones
    this->ir_instructions.push_back(instr);
}

void IR_Builder::add_instruction(IR_instruction_type_t code_instr, IR_operand op_dest, IR_operand op_1){
    // -- Crear instruccion
    IR_instruction instr(code_instr,op_dest,op_1);

    // -- Insertar en lista de instrucciones
    this->ir_instructions.push_back(instr);
}

void IR_Builder::add_instruction(IR_instruction_type_t code_instr, IR_operand op_dest, IR_operand op_1, IR_operand op_2){
    // -- Crear instruccion
    IR_instruction instr(code_instr,op_dest,op_1,op_2);

    // -- Insertar en lista de instrucciones
    this->ir_instructions.push_back(instr);
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_MANAGER] -----

int IR_Builder::start(){

    return 0;
}