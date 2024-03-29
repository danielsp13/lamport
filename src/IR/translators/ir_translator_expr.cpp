/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_expr.cpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del constructor de codigo intermedio Lineal para EXPRESIONES (IR)
 */

#include "IR/translators/ir_translator_expr.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_Translator_Declaration] -----

int IR_Translator_Expression::translate_expression_to_ir_instructions(struct expression * expr, bool from_subprogram){
    // -- Comprobar tipo de expresion
    switch (expr->kind)
    {
    case EXPR_BINARY:
    {   
        return this->translate_expression_binary_operation_to_ir_instructions(expr,from_subprogram);
        break;
    }
    case EXPR_UNARY:
    {
        return this->translate_expression_unary_operation_to_ir_instructions(expr,from_subprogram);
        break;
    }
    case EXPR_IDENTIFIER:
    {
        return this->translate_expression_identifier_to_ir_instructions(expr,from_subprogram);
        break;
    }
    case EXPR_LITERAL:
    {
        return this->translate_expression_literal_to_ir_instructions(expr,from_subprogram);
        break;
    }
    case EXPR_FUNCTION_INV:
    {
        return this->translate_expression_function_inv_to_ir_instructions(expr,from_subprogram);
        break;
    }
    case EXPR_GROUPED:
    {
        // -- Simplemente devolver el registro de la expresion entre parentesis
        return this->translate_expression_to_ir_instructions(expr->expr.grouped_expression,from_subprogram);
        break;
    }
    
    default:
        // ---- Excepcion
        std::string MSG = "[IR_Translation] Tipo de expresion no soportada para traduccion a IR.";
        throw std::runtime_error(MSG);

        break;
    }
}

int IR_Translator_Expression::translate_expression_binary_operation_to_ir_instructions(struct expression * expr, bool from_subprogram){
    // -- Traducir las expresiones mas interiores, si procede
    const int reg_left = this->translate_expression_to_ir_instructions(expr->expr.expression_binary_operation.left,from_subprogram);
    const int reg_right = this->translate_expression_to_ir_instructions(expr->expr.expression_binary_operation.right,from_subprogram);

    // -- Obtener identificador de siguiente registro
    const int reg_assigned = reg_manager.get_next_general_purpose_register();

    // -- Deliberar instruccion a emitir
    // ---- Operando de destino (registro)
    IR_operand op_dest = instructions.emit_operand_register(reg_assigned);
    // ---- Operando izquierdo (op1)
    IR_operand op_1 = instructions.emit_operand_register(reg_left);
    // ---- Operando izquierdo (op2)
    IR_operand op_2 = instructions.emit_operand_register(reg_right);

    // -- Emitir instruccion
    IR_instruction_type_t instr_code;
    switch (expr->expr.expression_binary_operation.kind)
    {
    // ------ OPERACIONES ARITMETICAS
    case EXPR_ADD:
    {
        instr_code = IR_OP_ADD_I;
        if(expr->expr.expression_binary_operation.type->kind == TYPE_REAL)
            instr_code = IR_OP_ADD_F;

        instructions.emit_instruction(instr_code,op_dest,op_1,op_2);
        break;
    }
    case EXPR_SUB:
    {

        instr_code = IR_OP_SUB_I;
        if(expr->expr.expression_binary_operation.type->kind == TYPE_REAL)
            instr_code = IR_OP_SUB_F;

        instructions.emit_instruction(instr_code,op_dest,op_1,op_2);
        break;
    }
    case EXPR_MULT:
    {

        instr_code = IR_OP_MULT_I;
        if(expr->expr.expression_binary_operation.type->kind == TYPE_REAL)
            instr_code = IR_OP_MULT_F;

        instructions.emit_instruction(instr_code,op_dest,op_1,op_2);
        break;
    }
    case EXPR_DIV:
    {
        instr_code = IR_OP_DIV_I;
        if(expr->expr.expression_binary_operation.type->kind == TYPE_REAL)
            instr_code = IR_OP_DIV_F;

        instructions.emit_instruction(instr_code,op_dest,op_1,op_2);
        break;
    }
    case EXPR_MOD:
    {
        instructions.emit_instruction(IR_OP_MOD_I,op_dest,op_1,op_2);
        break;
    }
    // ------ OPERACIONES DE COMPARACION
    case EXPR_LT:
    {
        instructions.emit_instruction(IR_OP_CMP_LT,op_dest,op_1,op_2);
        break;
    }
    case EXPR_LTE:
    {
        instructions.emit_instruction(IR_OP_CMP_LTE,op_dest,op_1,op_2);
        break;
    }
    case EXPR_GT:
    {
        instructions.emit_instruction(IR_OP_CMP_GT,op_dest,op_1,op_2);
        break;
    }
    case EXPR_GTE:
    {
        instructions.emit_instruction(IR_OP_CMP_GTE,op_dest,op_1,op_2);
        break;
    }
    case EXPR_EQ:
    {
        instructions.emit_instruction(IR_OP_CMP_EQ,op_dest,op_1,op_2);
        break;
    }
    case EXPR_NEQ:
    {
        instructions.emit_instruction(IR_OP_CMP_NEQ,op_dest,op_1,op_2);
        break;
    }
    // ------ OPERACIONES LOGICAS
    case EXPR_AND:
    {
        instructions.emit_instruction(IR_OP_AND,op_dest,op_1,op_2);
        break;
    }
    case EXPR_OR:
    {
        instructions.emit_instruction(IR_OP_OR,op_dest,op_1,op_2);
        break;
    }

    default:
        // ---- Excepcion
        std::string MSG = "[IR_Translation] Tipo de expresion (operacion binaria) no soportada para traduccion a IR.";
        throw std::runtime_error(MSG);
        break;
    }

    // -- Retornar registro
    return reg_assigned;
}

int IR_Translator_Expression::translate_expression_unary_operation_to_ir_instructions(struct expression * expr, bool from_subprogram){
    // -- Traducir las expresiones mas interiores
    const int reg_left = this->translate_expression_to_ir_instructions(expr->expr.expression_unary_operation.left,from_subprogram);

    // -- Obtener identificador de siguiente registro
    const int reg_assigned = reg_manager.get_next_general_purpose_register();

    // -- Deliberar instruccion a emitir
    // ---- Operando de destino (registro)
    IR_operand op_dest = instructions.emit_operand_register(reg_assigned);
    // ---- Operando izquierdo (op1)
    IR_operand op_1 = instructions.emit_operand_register(reg_left);

    IR_instruction_type_t instr_code;
    switch (expr->expr.expression_unary_operation.kind)
    {
    // ------ OPERACIONES ARITMETICAS
    case EXPR_NEGATIVE:
    {
        instr_code = IR_OP_NEG_I;
        if(expr->expr.expression_unary_operation.type->kind == TYPE_REAL)
            instr_code = IR_OP_NEG_F;

        instructions.emit_instruction(instr_code,op_dest,op_1);
        break;
    }
    // ------ OPERACIONES LOGICAS
    case EXPR_NOT:
    {
        instructions.emit_instruction(IR_OP_NOT,op_dest,op_1);
        break;
    }
    
    default:
        // ---- Excepcion
        std::string MSG = "[IR_Translation] Tipo de expresion (operacion unaria) no soportada para traduccion a IR.";
        throw std::runtime_error(MSG);
        break;
    }

    // -- Retornar registro
    return reg_assigned;
}

int IR_Translator_Expression::translate_expression_identifier_to_ir_instructions(struct expression * expr, bool from_subprogram){
    // -- 0. Obtener nombre de variable
    std::string var_name = std::string(expr->expr.expression_identifier.id);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // -- 1. Comprobar si el identificador corresponde a una variable de subprograma
    if(from_subprogram){
        int reg_var_local = assistant_translator.get_reg_from_var_local_subprog(var_name);

        // -- Si se ha encontrado, entonces emitir instrucciones adecuadas
        if(reg_var_local != -1){
            return reg_var_local;
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // -- Obtener indice de identificador de variable
    int id_variable_in_table = tables.get_index_from_local_variable(var_name,precedence);

    // -- Comprobar si el indice es distinto de -1, en otro caso, buscar en otro scope
    if(id_variable_in_table == -1)
        id_variable_in_table = tables.get_index_from_global_variable(var_name);

    //std::cout << "precedence: " << precedence << "; var_name: " << var_name << "; id_variable_in_table: " << id_variable_in_table << std::endl; std::cout.flush();

    // -- Realizar carga del valor de variable en un registro
    const int reg_assigned = this->reg_manager.get_next_general_purpose_register();

    // -- 3.B : Comprobar si el acceso se esta haciendo sobre un array
    IR_operand op_dest = instructions.emit_operand_register(reg_assigned);

    // -- Definir operando de registro 1
    IR_operand op_1;
    if(tables.check_if_variable_is_array_using_index(id_variable_in_table)){
        // -- Obtener el offset
        int reg_offset = this->translate_expression_to_ir_instructions(expr->expr.expression_identifier.index_expr,from_subprogram);

        // -- Obtener operando
        op_1 = instructions.emit_operand_variable_array(id_variable_in_table,reg_offset);
    }
    else{
        // -- Obtener operando normal
        op_1 = instructions.emit_operand_variable(id_variable_in_table);
    }

    // -- Emitir instruccion
    instructions.emit_instruction(IR_OP_LOAD,op_dest,op_1);

    // -- Retornar registro asignado
    return reg_assigned;
}

int IR_Translator_Expression::translate_expression_literal_to_ir_instructions(struct expression * expr, bool from_subprogram){
    // -- Obtener identificador de siguiente registro
    const int reg_assigned = this->reg_manager.get_next_general_purpose_register();

    // -- Deliberar instruccion a emitir
    // ---- Operando de destino (registro)
    IR_operand op_dest = instructions.emit_operand_register(reg_assigned);
    // ---- Indice de registro de literal
    int id_literal_in_table = 0;
    
    switch (expr->expr.expression_literal.kind)
    {
    case EXPR_LITERAL_INTEGER:
    {   
        int lit_value = expr->expr.expression_literal.value.integer_literal;
        // -- Asignar en la tabla el valor de literal
        id_literal_in_table = tables.add_entry_literal(static_cast<int>(lit_value));
        break;    
    }
    case EXPR_LITERAL_REAL:
    {   
        float lit_value = expr->expr.expression_literal.value.real_literal;
        // -- Asignar en la tabla el valor de literal
        id_literal_in_table = tables.add_entry_literal(lit_value);

        break;    
    }
    case EXPR_LITERAL_CHARACTER:
    {   
        char lit_value = expr->expr.expression_literal.value.character_literal;
        // -- Asignar en la tabla el valor de literal
        id_literal_in_table = tables.add_entry_literal(lit_value);

        break;    
    }
    case EXPR_LITERAL_STRING:
    {   
        std::string lit_value = std::string(expr->expr.expression_literal.value.string_literal);
        // -- Asignar en la tabla el valor de literal
        id_literal_in_table = tables.add_entry_literal(lit_value);

        break;    
    }
    case EXPR_LITERAL_BOOLEAN:
    {   
        bool lit_value = expr->expr.expression_literal.value.boolean_literal;
        // -- Asignar en la tabla el valor de literal
        id_literal_in_table = tables.add_entry_literal(static_cast<bool>(lit_value));

        break;    
    }        
    
    default:
        break;
    }

    // -- Operando de carga
    IR_operand op_1 = instructions.emit_operand_literal(id_literal_in_table);

    // -- Incluir instruccion de carga
    instructions.emit_instruction(IR_OP_LOAD,op_dest,op_1);

    // -- Retornar registro
    return reg_assigned;
}

int IR_Translator_Expression::translate_expression_function_inv_to_ir_instructions(struct expression * expr, bool from_subprogram){
    // ----- 0. Obtener nombre de subprograma funcion
    std::string function_name = std::string(expr->expr.expression_function_inv.function_name);

    // ---- 1. Generar instrucciones IR para cada argumento de funcion
    int addr_reg_argument;
    IR_operand op_reg_argument, op_reg_parameter;

    // ---- 1.1 Recorrer la lista de argumentos de invocacion
    struct expression * current_argument = expr->expr.expression_function_inv.arguments_list;
    while(current_argument){
        // ---- Obtener registro donde se encontrara la expresion
        addr_reg_argument = translate(current_argument,from_subprogram);

        // ---- Definir operando
        op_reg_argument = instructions.emit_operand_register(addr_reg_argument);
        
        // ---- Emitir instruccion de push en pila
        instructions.emit_instruction(IR_OP_PUSH,op_reg_argument);

        // ---- Ir a siguiente argumento
        current_argument = current_argument->next;
    }

    // ---- 2. Generar instruccion de llamada a funcion
    // ----- Obtener indice en tabla donde se encuentra la etiqueta de inicio de funcion
    std::string call_function_label = std::string("start_subprog_") + std::string(expr->expr.expression_function_inv.function_name);
    int index_label_in_table = tables.get_index_from_label_id(call_function_label);
    if(index_label_in_table == -1){
        // -- Crear placeholder para etiqueta
        index_label_in_table = tables.add_entry_label(call_function_label,-2);
    }

    // ----- Operando etiqueta para realizar el salto
    IR_operand op_label_function = instructions.emit_operand_label(index_label_in_table);

    // ----- Emitir instruccion de llamada a funcion
    instructions.emit_instruction(IR_OP_CALL,op_label_function);
    
    // ----- Retornar registro donde se encuentra el resultado de la llamada
    return reg_manager.get_return_subprog_register();
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_Translator_Expression] -----

IR_Translator_Expression& IR_Translator_Expression::get_instance(){
    static IR_Translator_Expression instance;
    return instance;
}

struct expression * IR_Translator_Expression::optimize(struct expression * expr){
    return optimizer.constant_folding(expr);
}

int IR_Translator_Expression::translate(struct expression * expr, bool from_subprogam){
    // -- Traducir
    int reg = this->translate_expression_to_ir_instructions(expr,from_subprogam);
    return reg;
}