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

IR_operand IR_Builder::emit_operand_register(int id_reg){
    IR_operand op(IR_OPERAND_REGISTER,id_reg);
    return op;
}

IR_operand IR_Builder::emit_operand_literal(int id_lit){
    IR_operand op(IR_OPERAND_LITERAL,id_lit);
    return op;
}

IR_operand IR_Builder::emit_operand_variable(int id_var){
    IR_operand op(IR_OPERAND_VARIABLE,id_var);
    return op;
}

IR_operand IR_Builder::emit_operand_variable_array(int id_var, int offset){
    IR_operand op(IR_OPERAND_VARIABLE_ARRAY,id_var,offset);
    return op;
}

IR_operand IR_Builder::emit_operand_label(int id_label){
    IR_operand op(IR_OPERAND_LABEL,id_label);
    return op;
}

std::string IR_Builder::get_next_label_id(){
    return std::to_string(id_label_annonymous++);
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS (TRADUCCIONES) [IR_MANAGER] -----

bool IR_Builder::translate_declaration_to_ir_instruction(struct declaration * decl){
    // -- Variable de resultado
    bool translate_result = true;

    // -- 1. Obtener nombre de variable
    std::string var_name = std::string(decl->name);

    // -- 2. Obtener scope de variable
    auto var_scope = AST_symbol_IR_var_t.find(decl->symb->kind);
    // ------ Comprobar que se encontro scope
    if(var_scope == AST_symbol_IR_var_t.end())
        return false;

    // -- 3. Obtener tipo de dato de variable
    auto var_type = AST_type_IR_type.find(decl->type->kind);
    // ------ Comprobar que se encontro tipo de dato
    if(var_type == AST_type_IR_type.end())
        return false;

    // -- 4. Comprobar si la variable es de tipo array
    // ---- Identificador de registro de variable
    int id_variable_in_table = 0;
    if(var_type->second == IR_VAR_TYPE_ARRAY){
        var_type = AST_type_IR_type.find(decl->type->subtype->kind);
        if(var_type == AST_type_IR_type.end())
            return false;

        // -- 4.1 Obtener longitud de array
        // ---- FUTURE (por ahora se sabe que si paso el typechecking es porque es un literal puro integer)
        size_t var_size = decl->type->size->expr.expression_literal.value.integer_literal; 

        // -- 4.2 Registrar variable
        id_variable_in_table = tables.add_entry_variable(var_scope->second,var_name,var_type->second,var_size);
    }
    else{
        // -- 5. Registrar variable
        id_variable_in_table = tables.add_entry_variable(var_scope->second,var_name,var_type->second);
    }

    // -- 6. Evaluar valor de variable
    if(decl->value){
        // -- 6.1 Aplicar constant folding en expresion
        decl->value = optimizer.constant_folding(decl->value);

        // -- 6.2 Traducir expresion de asignacion a instruccion IR
        const int id_reg_value = this->translate_expression_to_ir_instructions(decl->value);
        if(id_reg_value == -1){
            // -- Manejar error en traduccion //TODO
            return false;
        }

        // -- 6.3 Emitir instruccion de almacenamiento de valor en variable
        // ---- Operando de destino
        IR_operand op_dest = this->emit_operand_variable(id_variable_in_table);
        // ---- Operando de carga
        IR_operand op_1 = this->emit_operand_register(id_reg_value);

        instruction_table.emit_instruction(IR_OP_STORE,op_dest,op_1);
    }

    // -- Retornar resultado de traduccion
    return translate_result;
}

bool IR_Builder::translate_list_declarations_to_ir_instructions(struct declaration * list_decl){
    // -- Variable de resultado
    bool translate_result = true;

    struct declaration *current_decl = list_decl;
    while(current_decl != NULL){
        // -- Traducir declaracion
        translate_result = translate_result == false ? false : this->translate_declaration_to_ir_instruction(current_decl);
        // -- Ir a siguiente declaracion
        current_decl = current_decl->next;
    }

    // -- Retornar resultado de traduccion
    return translate_result;
}

bool IR_Builder::translate_subprogram_to_ir_instructions(struct subprogram * subprog){
    return true;
}

bool IR_Builder::translate_list_subprograms_to_ir_instructions(struct subprogram * list_subprog){
    // -- Variable de resultado
    bool translate_result = true;

    struct subprogram *current_subprog = list_subprog;
    while(current_subprog != NULL){
        // -- Traducir declaracion
        translate_result = translate_result == false ? false : this->translate_subprogram_to_ir_instructions(current_subprog);
        // -- Ir a siguiente declaracion
        current_subprog = current_subprog->next;
    }

    // -- Retornar resultado de traduccion
    return translate_result;
}

bool IR_Builder::translate_process_to_ir_instructions(struct process * proc){
    // -- Variable de resultado
    bool translate_result = true;

    // 1. Obtener nombre de proceso
    std::string id_label_block = this->get_next_label_id();
    std::string proc_name = std::string(proc->name_process);

    // 2. Registrar proceso como una variable (de scope global)
    int id_process_in_table = tables.add_entry_variable(IR_VAR_GLOBAL,proc_name,IR_VAR_TYPE_PROCESS);

    // 3. Generar etiqueta de entrada de proceso
    int id_label_in_table = tables.add_entry_label(std::string("start_proc_") + proc_name + "(" + id_label_block + ")",instruction_table.size()+1);

    // 4. Emitir instruccion de punto de entrada de proceso
    IR_operand op_label = this->emit_operand_label(id_label_in_table);

    instruction_table.emit_instruction(IR_LABEL,op_label);

    // 5. Traducir declaraciones de proceso
    if(proc->declarations)
        translate_result = this->translate_list_declarations_to_ir_instructions(proc->declarations);

    // 6. Traducir sentencias de proceso
    // TODO .. COMPROBAR SI EL BLOQUE DE SENTENCIAS ES COBEGIN
    if(proc->statements)
        translate_result = this->translate_list_statements_to_ir_instructions(proc->statements);

    // 7. Generar etiqueta de fin de proceso
    id_label_in_table = tables.add_entry_label(std::string("end_proc_") + proc_name + "(" + id_label_block + ")",instruction_table.size()+1);

    // 4. Emitir instruccion de punto de entrada de proceso
    op_label = this->emit_operand_label(id_label_in_table);

    instruction_table.emit_instruction(IR_LABEL,op_label);

    // -- Retornar resultado de traduccion
    return translate_result;
}

bool IR_Builder::translate_list_process_to_ir_instructions(struct process * list_proc){
    // -- Variable de resultado
    bool translate_result = true;

    struct process *curret_proc = list_proc;
    while(curret_proc != NULL){
        // -- Traducir declaracion
        translate_result = translate_result == false ? false : this->translate_process_to_ir_instructions(curret_proc);
        // -- Ir a siguiente declaracion
        curret_proc = curret_proc->next;
    }

    // -- Retornar resultado de traduccion
    return translate_result;
}

bool IR_Builder::translate_statement_to_ir_instructions(struct statement * stmt){
    // -- Comprobar tipo de sentencias
    switch (stmt->kind)
    {
    // ---- SENTENCIA BLOQUE DE SENTENCIAS
    case STMT_BLOCK_BEGIN:
    {
        return this->translate_list_statements_to_ir_instructions(stmt->stmt.statement_block.body);
        break;
    }
    // ---- SENTENCIA BLOQUE DE SENTENCIAS PARALELO
    case STMT_BLOCK_COBEGIN:
    {
        break;
    }
    // ---- SENTENCIA DE BLOQUE DE SENTENCIAS ATOMICAS
    case STMT_ATOMIC:
    {
        break;
    }
    // ---- SENTENCIA ASIGNACION
    case STMT_ASSIGNMENT:
    {
        return this->translate_statement_assignment_to_ir_instructions(stmt);
        break;
    }
    // ---- SENTENCIA IF/ELSE
    case STMT_IF_ELSE:
    {
        return this->translate_statement_ifelse_to_ir_instructions(stmt);
        break;
    }
    // ---- SENTENCIA WHILE
    case STMT_WHILE:
    {
        return this->translate_statement_while_to_ir_instructions(stmt);
        break;
    }
    // ---- SENTENCIA FOR
    case STMT_FOR:
    {
        return this->translate_statement_for_to_ir_instructions(stmt);
        break;
    }
    // ---- SENTENCIA PRINT
    case STMT_PRINT:
    {
        return this->translate_statement_print_to_ir_instructions(stmt);
        break;
    }
    // ---- SENTENCIA INVOCACION DE PROCEDIMIENTO
    case STMT_PROCEDURE_INV:
    {
        //TODO
        break;
    }
    // ---- SENTENCIA DE RETORNO DE FUNCION
    case STMT_RETURN:
    {
        //TODO
        break;
    }
    // ---- SENTENCIAS DE CREACION Y SINCRONIZACION DE HEBRAS
    case STMT_FORK:
    {
        //TODO
        break;
    }
    case STMT_JOIN:
    {
        //TODO
        break;
    }
    
    default:
        break;
    }

    // -- Retornar fracaso
    return false;
}

bool IR_Builder::translate_statement_assignment_to_ir_instructions(struct statement * stmt){
    // -- 0. Obtener nombre de variable
    std::string var_name = std::string(stmt->stmt.statement_assignment.symb->name);

    // -- 1. Obtener id de variable a asignar
    int id_variable_in_table = tables.get_index_from_local_variable(var_name);
    if(id_variable_in_table == -1){
        // ---- Buscar en otro scope
        id_variable_in_table = tables.get_index_from_global_variable(var_name);
    }

    // -- 2. Obtener registro donde se encontrara la expresion a asignar
    const int reg_assigned = this->translate_expression_to_ir_instructions(stmt->stmt.statement_assignment.expr);

    // -- 3. Emitir instruccion de STORE
    IR_operand op_1 = this->emit_operand_register(reg_assigned);

    // -- 3.B : Comprobar si el acceso se esta haciendo sobre un array
    IR_operand op_dest;
    if(tables.check_if_variable_is_array_using_index(id_variable_in_table)){
        // -- Obtener el offset
        int reg_offset = this->translate_expression_to_ir_instructions(stmt->stmt.statement_assignment.index_expr);

        // -- Obtener operando
        op_dest = this->emit_operand_variable_array(id_variable_in_table,reg_offset);
    }
    else{
        // -- Obtener operando normal
        op_dest = this->emit_operand_variable(id_variable_in_table);
    }

    instruction_table.emit_instruction(IR_OP_STORE,op_dest,op_1);

    // -- Retornar exito
    return true;
}

bool IR_Builder::translate_statement_ifelse_to_ir_instructions(struct statement * stmt){
    // -- Emitir instrucciones para condicion de if/else
    int reg_addr = this->translate_expression_to_ir_instructions(stmt->stmt.statement_if_else.condition);

    // -- Obtener total de instrucciones en este momento
    const int total_instr_before = instruction_table.size();

    // -- Generar instrucciones para bloque if
    this->translate_list_statements_to_ir_instructions(stmt->stmt.statement_if_else.if_body);

    // -- Obtener posicion actual de instruccion
    int total_instr_after_if = instruction_table.size()+1;

    // -- Generar mas instrucciones si hay bloque else
    int id_label_in_table = 0; const std::string id_label_block = this->get_next_label_id();
    if(stmt->stmt.statement_if_else.else_body){
        // -- Obtener total de instrucciones tras generacion de bloque if
        const int total_instr_now = instruction_table.size()+2;

        // -- Generar instruccion de salto condicional
        id_label_in_table = tables.add_entry_label(std::string("else_block(") + id_label_block + ")",total_instr_now+1);
        IR_operand op_expr_cmp = this->emit_operand_register(reg_addr);
        IR_operand op_jmp = this->emit_operand_label(id_label_in_table);
        IR_instruction instr_jmp_false(IR_OP_JMP_FALSE,false,op_expr_cmp,op_jmp);

        instruction_table.add_instruction_to_list_in_position(instr_jmp_false,total_instr_before);

        // -- Generar instruccion de etiqueta de bloque else
        instruction_table.emit_instruction(IR_LABEL,op_jmp);

        // -- Generar instrucciones para bloque else
        this->translate_list_statements_to_ir_instructions(stmt->stmt.statement_if_else.else_body);
    }

    // -- Generar instruccion de etiqueta de fin de bloque else
    id_label_in_table = tables.add_entry_label(std::string("end_if(") + id_label_block + ")",instruction_table.size()+1);
    IR_operand op_end_if = this->emit_operand_label(id_label_in_table);
    instruction_table.emit_instruction(IR_LABEL,op_end_if);

    // -- Emitir instruccion de salto incondicional a fin de etiqueta en la posicion after if
    IR_instruction instr_jmp_end_if(IR_OP_JMP,op_end_if);
    instruction_table.add_instruction_to_list_in_position(instr_jmp_end_if,total_instr_after_if);

    return true;
}

bool IR_Builder::translate_statement_while_to_ir_instructions(struct statement * stmt){
    // -- Generar etiqueta de entrada de bucle while
    const std::string id_label_block = this->get_next_label_id();
    const int instr_while_start = instruction_table.size()+1;
    int id_label_in_table = tables.add_entry_label(std::string("while_start(") + id_label_block + ")",instr_while_start);

    // -- Generar instruccion de etiqueta de inicio de while
    IR_operand op_while_start = this->emit_operand_label(id_label_in_table);
    instruction_table.emit_instruction(IR_LABEL,op_while_start);

    // -- Generar instrucciones ir para condicion del bucle
    const int reg_while_condition = this->translate_expression_to_ir_instructions(stmt->stmt.statement_while.condition);
    IR_operand op_while_condition = this->emit_operand_register(reg_while_condition);

    // -- Obtener total de instrucciones en vector hasta el momento de generar para la condicion
    const int instr_while_condition = instruction_table.size();

    // -- Generar instrucciones ir para cuerpo del bucle
    this->translate_list_statements_to_ir_instructions(stmt->stmt.statement_while.body);

    // -- Generar instruccion ir de salto incondicional al inicio del bucle
    instruction_table.emit_instruction(IR_OP_JMP,op_while_start);

    // -- Generar instruccion de ruptura de bucle while
    id_label_in_table = tables.add_entry_label(std::string("while_end(") + id_label_block + ")",instruction_table.size()+2);
    IR_operand op_while_end = this->emit_operand_label(id_label_in_table);
    IR_instruction instr_jmp_false(IR_OP_JMP_FALSE,false,op_while_condition,op_while_end);

    instruction_table.add_instruction_to_list_in_position(instr_jmp_false,instr_while_condition);

    // -- Generar instruccion de etiqueta de fin de bucle while
    instruction_table.emit_instruction(IR_LABEL,op_while_end);

    return true;
}

bool IR_Builder::translate_statement_for_to_ir_instructions(struct statement * stmt){
    // -- Generar instrucciones para inicializacion de contador de bucle for
    // ---- Obtener identificador de contador de bucle
    std::string index_name = std::string(stmt->stmt.statement_for.counter_name);
    // ---- Registrar en tabla de variables
    int id_variable_in_table = tables.add_entry_variable(IR_VAR_LOCAL,index_name,IR_VAR_TYPE_INT);

    // ---- Inicializar el contador
    const int reg_index_init = this->translate_expression_to_ir_instructions(stmt->stmt.statement_for.intialization);

    // ---- Emitir instruccion de carga de valor en variable
    IR_operand op_index_dest = this->emit_operand_variable(id_variable_in_table);
    IR_operand op_index = this->emit_operand_register(reg_index_init);
    instruction_table.emit_instruction(IR_OP_STORE,op_index_dest,op_index);

    // -- Generar etiqueta de entrada de bucle for
    const std::string id_label_block = this->get_next_label_id();
    const int instr_for_start = instruction_table.size()+1;
    int id_label_in_table = tables.add_entry_label(std::string("for_start(") + id_label_block + ")",instr_for_start);
    IR_operand op_for_start = this->emit_operand_label(id_label_in_table);
    instruction_table.emit_instruction(IR_LABEL,op_for_start);

    // ---- Emitir instruccion de comparacion con condicion de fin de bucle
    const int reg_index_end = this->translate_expression_to_ir_instructions(stmt->stmt.statement_for.finish);
    const int reg_index_cmp = reg_manager.get_next_register();
    IR_operand op_index_cmp = this->emit_operand_register(reg_index_cmp);
    IR_operand op_index_end = this->emit_operand_register(reg_index_end);
    instruction_table.emit_instruction(IR_OP_CMP_LTE,op_index_cmp,op_index,op_index_end);
    const int instr_for_condition = instruction_table.size();

    // ---- Generar instrucciones de cuerpo de bucle for
    this->translate_list_statements_to_ir_instructions(stmt->stmt.statement_for.body);

    // ---- Generar instrucciones de actualizacion de contador
    // ------- Generar operacion de carga de incremento
    int id_literal_in_table = tables.add_entry_literal(static_cast<int>(1));
    IR_operand op_index_inc = this->emit_operand_literal(id_literal_in_table);
    const int reg_assigned = this->reg_manager.get_next_register();
    IR_operand op_reg_index_inc = this->emit_operand_register(reg_assigned);
    instruction_table.emit_instruction(IR_OP_LOAD,op_reg_index_inc,op_index_inc);

    instruction_table.emit_instruction(IR_OP_ADD,op_index,op_index,op_reg_index_inc);
    instruction_table.emit_instruction(IR_OP_STORE,op_index_dest,op_index);

    // ---- Generar instruccion de salto incondicional al inicio del bucle
    instruction_table.emit_instruction(IR_OP_JMP,op_for_start);

    // ---- Generar instruccion de ruptura de bucle for
    id_label_in_table = tables.add_entry_label(std::string("for_end(") + id_label_block + ")",instruction_table.size()+2);
    IR_operand op_for_end = this->emit_operand_label(id_label_in_table);
    IR_instruction instr_jmp_false(IR_OP_JMP_FALSE,false,op_index_cmp,op_for_end);

    instruction_table.add_instruction_to_list_in_position(instr_jmp_false,instr_for_condition);

    // ---- Generar instruccion de etiqueta de fin de bucle for
    instruction_table.emit_instruction(IR_LABEL,op_for_end);

    return true;
}

bool IR_Builder::translate_statement_print_to_ir_instructions(struct statement * stmt){
    // -- Emitir tantas instrucciones de impresion como expresiones haya
    struct expression * current_expr_to_print = stmt->stmt.statement_print.expressions_list;
    // -- Analizar una a una
    int reg_expression = 0;
    IR_operand op_print;

    while(current_expr_to_print){
        // -- Obtener registro de carga de expresion
        reg_expression = this->translate_expression_to_ir_instructions(current_expr_to_print);

        // -- Generar operando de registro
        op_print = this->emit_operand_register(reg_expression);

        // -- Emitir instruccion de impresion
        instruction_table.emit_instruction(IR_OP_PRINT,op_print);

        // -- Ir a siguiente expresion a imprimir
        current_expr_to_print = current_expr_to_print->next;
    }

    // -- Cargar literal de salto de linea e imprimir al final de la sentencia
    struct expression * expr_endl = create_expression_literal_string(std::string("\n").c_str());

    // -- Obtener registro de carga de expresion
    reg_expression = this->translate_expression_to_ir_instructions(expr_endl);

    // -- Generar operando de registro
    op_print = this->emit_operand_register(reg_expression);

    // -- Emitir instruccion de impresion
    instruction_table.emit_instruction(IR_OP_PRINT,op_print);

    // -- Liberar expresion utilizada
    free_expression(expr_endl);

    return true;
}

bool IR_Builder::translate_list_statements_to_ir_instructions(struct statement * list_stmt){
    // -- Variable de resultado
    bool translate_result = true;

    struct statement *current_stmt = list_stmt;
    while(current_stmt != NULL){
        // -- Traducir declaracion
        translate_result = translate_result == false ? false : this->translate_statement_to_ir_instructions(current_stmt);
        // -- Ir a siguiente declaracion
        current_stmt = current_stmt->next;
    }

    // -- Retornar resultado de traduccion
    return translate_result;
}

int IR_Builder::translate_expression_to_ir_instructions(struct expression * expr){
    // -- Comprobar tipo de expresion
    switch (expr->kind)
    {
    case EXPR_BINARY:
    {   
        return this->translate_expression_binary_operation_to_ir_instructions(expr);
        break;
    }
    case EXPR_UNARY:
    {
        return this->translate_expression_unary_operation_to_ir_instructions(expr);
        break;
    }
    case EXPR_IDENTIFIER:
    {
        return this->translate_expression_identifier_to_ir_instructions(expr);
        break;
    }
    case EXPR_LITERAL:
    {
        return this->translate_expression_literal_to_ir_instructions(expr);
        break;
    }
    case EXPR_FUNCTION_INV:
    {
        return this->translate_expression_function_inv_to_ir_instructions(expr);
        break;
    }
    case EXPR_GROUPED:
    {
        // -- Simplemente devolver el registro de la expresion entre parentesis
        return this->translate_expression_to_ir_instructions(expr->expr.grouped_expression);
        break;
    }
    
    default:
        break;
    }

    // -- Devolver error si algo no es manejado correctamente
    return -1;
}

int IR_Builder::translate_expression_binary_operation_to_ir_instructions(struct expression * expr){
    // -- Traducir las expresiones mas interiores, si procede
    const int reg_left = this->translate_expression_to_ir_instructions(expr->expr.expression_binary_operation.left);
    const int reg_right = this->translate_expression_to_ir_instructions(expr->expr.expression_binary_operation.right);

    // -- Obtener identificador de siguiente registro
    const int reg_assigned = this->reg_manager.get_next_register();

    // -- Deliberar instruccion a emitir
    // ---- Operando de destino (registro)
    IR_operand op_dest = this->emit_operand_register(reg_assigned);
    // ---- Operando izquierdo (op1)
    IR_operand op_1 = this->emit_operand_register(reg_left);
    // ---- Operando izquierdo (op2)
    IR_operand op_2 = this->emit_operand_register(reg_right);

    // -- Emitir instruccion
    switch (expr->expr.expression_binary_operation.kind)
    {
    // ------ OPERACIONES ARITMETICAS
    case EXPR_ADD:
    {
        instruction_table.emit_instruction(IR_OP_ADD,op_dest,op_1,op_2);
        break;
    }
    case EXPR_SUB:
    {
        instruction_table.emit_instruction(IR_OP_SUB,op_dest,op_1,op_2);
        break;
    }
    case EXPR_MULT:
    {
        instruction_table.emit_instruction(IR_OP_MULT,op_dest,op_1,op_2);
        break;
    }
    case EXPR_DIV:
    {
        instruction_table.emit_instruction(IR_OP_DIV,op_dest,op_1,op_2);
        break;
    }
    case EXPR_MOD:
    {
        instruction_table.emit_instruction(IR_OP_MOD,op_dest,op_1,op_2);
        break;
    }
    // ------ OPERACIONES DE COMPARACION
    case EXPR_LT:
    {
        instruction_table.emit_instruction(IR_OP_CMP_LT,op_dest,op_1,op_2);
        break;
    }
    case EXPR_LTE:
    {
        instruction_table.emit_instruction(IR_OP_CMP_LTE,op_dest,op_1,op_2);
        break;
    }
    case EXPR_GT:
    {
        instruction_table.emit_instruction(IR_OP_CMP_GT,op_dest,op_1,op_2);
        break;
    }
    case EXPR_GTE:
    {
        instruction_table.emit_instruction(IR_OP_CMP_GTE,op_dest,op_1,op_2);
        break;
    }
    case EXPR_EQ:
    {
        instruction_table.emit_instruction(IR_OP_CMP_EQ,op_dest,op_1,op_2);
        break;
    }
    case EXPR_NEQ:
    {
        instruction_table.emit_instruction(IR_OP_CMP_NEQ,op_dest,op_1,op_2);
        break;
    }
    // ------ OPERACIONES LOGICAS
    case EXPR_AND:
    {
        instruction_table.emit_instruction(IR_OP_AND,op_dest,op_1,op_2);
        break;
    }
    case EXPR_OR:
    {
        instruction_table.emit_instruction(IR_OP_OR,op_dest,op_1,op_2);
        break;
    }

    default:
        break;
    }

    // -- Retornar registro
    return reg_assigned;
}

int IR_Builder::translate_expression_unary_operation_to_ir_instructions(struct expression * expr){
    // -- Traducir las expresiones mas interiores
    const int reg_left = this->translate_expression_to_ir_instructions(expr->expr.expression_unary_operation.left);

    // -- Obtener identificador de siguiente registro
    const int reg_assigned = this->reg_manager.get_next_register();

    // -- Deliberar instruccion a emitir
    // ---- Operando de destino (registro)
    IR_operand op_dest = this->emit_operand_register(reg_assigned);
    // ---- Operando izquierdo (op1)
    IR_operand op_1 = this->emit_operand_register(reg_left);

    switch (expr->expr.expression_unary_operation.kind)
    {
    // ------ OPERACIONES ARITMETICAS
    case EXPR_NEGATIVE:
    {
        instruction_table.emit_instruction(IR_OP_NEG,op_dest,op_1);
        break;
    }
    // ------ OPERACIONES LOGICAS
    case EXPR_NOT:
    {
        instruction_table.emit_instruction(IR_OP_NOT,op_dest,op_1);
        break;
    }
    
    default:
        break;
    }

    // -- Retornar registro
    return reg_assigned;
}

int IR_Builder::translate_expression_identifier_to_ir_instructions(struct expression * expr){
    // -- Obtener nombre de variable
    std::string var_name = std::string(expr->expr.expression_identifier.id);

    // TODO : Comprobar si es un acceso a array

    // -- Obtener indice de identificador de variable
    int id_variable_in_table = tables.get_index_from_local_variable(var_name);

    // -- Comprobar si el indice es distinto de -1, en otro caso, buscar en otro scope
    if(id_variable_in_table == -1)
        id_variable_in_table = tables.get_index_from_global_variable(var_name);

    // -- Realizar carga del valor de variable en un registro
    const int reg_assigned = this->reg_manager.get_next_register();

    // -- 3.B : Comprobar si el acceso se esta haciendo sobre un array
    IR_operand op_dest = this->emit_operand_register(reg_assigned);

    // -- Definir operando de registro 1
    IR_operand op_1;
    if(tables.check_if_variable_is_array_using_index(id_variable_in_table)){
        // -- Obtener el offset
        int reg_offset = this->translate_expression_to_ir_instructions(expr->expr.expression_identifier.index_expr);

        // -- Obtener operando
        op_1 = this->emit_operand_variable_array(id_variable_in_table,reg_offset);
    }
    else{
        // -- Obtener operando normal
        op_1 = this->emit_operand_variable(id_variable_in_table);
    }

    // -- Emitir instruccion
    instruction_table.emit_instruction(IR_OP_LOAD,op_dest,op_1);

    // -- Retornar registro asignado
    return reg_assigned;
}

int IR_Builder::translate_expression_literal_to_ir_instructions(struct expression * expr){
    // -- Obtener identificador de siguiente registro
    const int reg_assigned = this->reg_manager.get_next_register();

    // -- Deliberar instruccion a emitir
    // ---- Operando de destino (registro)
    IR_operand op_dest = this->emit_operand_register(reg_assigned);
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
    IR_operand op_1 = this->emit_operand_literal(id_literal_in_table);

    // -- Incluir instruccion de carga
    instruction_table.emit_instruction(IR_OP_LOAD,op_dest,op_1);

    // -- Retornar registro
    return reg_assigned;
}

int IR_Builder::translate_expression_function_inv_to_ir_instructions(struct expression * expr){
    return -1;
}

bool IR_Builder::translate_program_to_ir_instructions(struct program * prog){
    // 1. Obtener nombre de programa
    std::string prog_name = std::string(prog->name_program);

    // 3. Generar etiqueta de entrada de programa
    int id_label_in_table = tables.add_entry_label(std::string("prog_") + prog_name,instruction_table.size()+1);

    // 4. Emitir instruccion de punto de entrada de proceso
    IR_operand op_label = this->emit_operand_label(id_label_in_table);

    instruction_table.emit_instruction(IR_LABEL,op_label);

    // -- Comprobar las declaraciones globales del programa
    if(prog->declarations){
        // -- Traducir lista de declaraciones
        this->translate_list_declarations_to_ir_instructions(prog->declarations);
    }

    // -- Comprobar los subprogramas del programa
    if(prog->subprograms){
        // -- Traducir lista de subprogramas
        // TODO
    }

    // -- Comprobar los procesos del programa
    if(prog->process){
        // -- Traducir lista de procesos
        this->translate_list_process_to_ir_instructions(prog->process);
    }

    // -- Retornar exito
    return true;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_MANAGER] -----

int IR_Builder::build(bool verbose_avaiable){
    // -- Generar traduccion a IR de programa
    this->translate_program_to_ir_instructions(AST_program);

    if(verbose_avaiable){
        // -- Imprimir tablas
        tables.print_literals_table(); std::cout << std::endl;
        tables.print_variables_table(); std::cout << std::endl;
        tables.print_labels_table(); std::cout << std::endl;

        // -- Imprimir instrucciones IR
        IR_Printer::get_instance().print_ir_instructions();
    }
    return 0;
}