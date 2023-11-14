/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_printer.hpp
 * @author Daniel Perez Ruiz
 * @brief Implementacion del impresor de codigo intermedio Lineal (IR)
 */

#include "IR/builder/ir_printer.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_PRINTER] -----

std::string IR_Printer::ir_code_instruction_to_string(IR_instruction_type_t instr_code){
    // -- Definir codigo de instruccion str
    std::string instr_code_str = "<unknown code_instruction>";

    auto it = instructions_str.find(instr_code);
    if(it != instructions_str.end())
        instr_code_str = it->second;

    // -- Retornar codigo de instruccion
    return instr_code_str;
}

std::string IR_Printer::ir_operand_instruction_to_string(IR_operand op){
    // -- Definir operando de instruccion str
    std::string instr_op_str = "";

    // -- Obtener tipo de operando y direccion
    IR_operand_t kind = op.get_kind();
    int address = op.get_address();

    // -- Comprobar que tipo de operando es
    switch (kind)
    {
    case IR_OPERAND_REGISTER:
    {
        instr_op_str = "%r" + std::to_string(address);
        break;
    }
    case IR_OPERAND_LITERAL:
    {
        instr_op_str = "$" + tables.get_entry_literal(address)->to_string();
        break;
    }
    case IR_OPERAND_VARIABLE:
    {
        instr_op_str = tables.get_entry_variable(address)->get_name();
        break;
    }
    case IR_OPERAND_VARIABLE_ARRAY:
    {
        instr_op_str = tables.get_entry_variable(address)->get_name() + "+(%r" + std::to_string(op.get_offset()) + ")";
        break;
    }
    case IR_OPERAND_LABEL:
    {
        instr_op_str = tables.get_entry_label(address)->get_label();
        break;
    }
    case IR_OPERAND_THREAD_ID:
    {
        instr_op_str = "[" + std::to_string(address) + "]";
        break;
    }
    case IR_OPERAND_DIRECT_JMP:
    {
        instr_op_str = "(" + std::to_string(address) + ")";
        break;
    }
    
    default:
        break;
    }

    // -- Retornar operando str
    return instr_op_str;
}

std::string IR_Printer::ir_instruction_to_string(IR_instruction instr){
    // -- Definir instruccion
    std::string instr_str = "";

    // -- Obtener codigo de instruccion y su conversion a string
    std::string instr_code_str = instr.get_code_instr_str() + " ";

    // -- Obtener operando de instruccion (destino)
    std::optional<IR_operand> instr_op_destiny = instr.get_operand_destiny();
    std::string instr_op_destiny_str = "";
    if(instr_op_destiny.has_value()){
        instr_op_destiny_str = this->ir_operand_instruction_to_string(instr_op_destiny.value());

        if(instr.get_code_instr() != IR_START_DYNAMIC_PROCESS){
            instr_op_destiny_str += " <--- ";
        }
        else{
            instr_op_destiny_str += " , ";
        }
    }

    // -- Obtener primer operando
    std::optional<IR_operand> instr_op_1 = instr.get_operand_1();
    std::string instr_op_1_str = "";
    if(instr_op_1.has_value()){
        instr_op_1_str = this->ir_operand_instruction_to_string(instr_op_1.value());

        // -- Incluir ":" en caso de etiqueta
        if(instr.get_code_instr() == IR_LABEL)
            instr_op_1_str += ":";
    }

    // -- Obtener segundo operando
    std::optional<IR_operand> instr_op_2 = instr.get_operand_2();
    std::string instr_op_2_str = "";
    if(instr_op_2.has_value()){
        if(instr.get_code_instr() == IR_OP_JMP_TRUE || instr.get_code_instr() == IR_OP_JMP_FALSE){
            instr_op_2_str = " >>> ";   
        }
        else{
            instr_op_2_str = " , ";
        }
        instr_op_2_str += this->ir_operand_instruction_to_string(instr_op_2.value());
    }

    // -- Obtener instruccion str final
    instr_str = instr_code_str + instr_op_destiny_str + instr_op_1_str + instr_op_2_str;

    // -- Retornar string de instruccion
    return instr_str;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_PRINTER] -----

IR_Printer& IR_Printer::get_instance(){
    static IR_Printer instance;
    return instance;
}

void IR_Printer::print_ir_instructions(std::ostream& os){
    std::string instr_str;

    os << "INSTRUCCIONES IR" << std::endl;
    os << "================================================" << std::endl;
    for(unsigned int i=0; i<this->ir_instructions_str.size(); i++){
        instr_str = ir_instructions_str[i];

        // Usar un ostringstream para formatear el número
        std::ostringstream instr_int;
        instr_int << std::setfill('0') << std::setw(4) << i;

        os << "0i" << instr_int.str() << ": " << instr_str << "\n";
    }

    os.flush();
}

void IR_Printer::print_tables(std::ostream& os){
    tables.print_literals_table(os);
    tables.print_variables_table(os);
    tables.print_labels_table(os);
    os << std::endl;
}

void IR_Printer::add_ir_instruction_to_printer(IR_instruction instr){
    this->ir_instructions_str.push_back(this->ir_instruction_to_string(instr));
}

void IR_Printer::add_ir_instruction_to_printer(IR_instruction instr, int position){
    this->ir_instructions_str.insert(ir_instructions_str.begin()+position,this->ir_instruction_to_string(instr));
}

void IR_Printer::operator()(int i, const IR_instruction & instr){
    ir_instructions_str[i] = this->ir_instruction_to_string(instr);
}