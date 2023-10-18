/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file ir_translator_stmt.cpp
 * @author Daniel Perez Ruiz
 * @brief Definicion del constructor de codigo intermedio Lineal para SENTENCIAS (IR)
 */

#include "IR/ir_translator_stmt.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [IR_Translator_Statement] -----

void IR_Translator_Statement::translate_statement_to_ir_instructions(struct statement * stmt, bool from_subprogram){
   // -- Comprobar tipo de sentencias
    switch (stmt->kind)
    {
    // ---- SENTENCIA BLOQUE DE SENTENCIAS
    case STMT_BLOCK_BEGIN:
    {
        this->translate_list_statements_to_ir_instructions(stmt->stmt.statement_block.body,from_subprogram);
        break;
    }
    // ---- SENTENCIA BLOQUE DE SENTENCIAS PARALELO
    case STMT_BLOCK_COBEGIN:
    {
        // TODO (ESPECIFICAR COBEGIN)
        this->translate_list_statements_to_ir_instructions(stmt->stmt.statement_block.body,from_subprogram);
        break;
    }
    // ---- SENTENCIA DE BLOQUE DE SENTENCIAS ATOMICAS
    case STMT_ATOMIC:
    {
        instructions.emit_instruction(IR_OP_ATOMIC_BEGIN);
        this->translate_list_statements_to_ir_instructions(stmt->stmt.statement_block.body,from_subprogram);
        instructions.emit_instruction(IR_OP_ATOMIC_END);
        break;
    }
    // ---- SENTENCIA ASIGNACION
    case STMT_ASSIGNMENT:
    {
        this->translate_statement_assignment_to_ir_instructions(stmt,from_subprogram);
        // -- Resetear registros
        reg_manager.reset_general_purpose_register_counter();
        break;
    }
    // ---- SENTENCIA IF/ELSE
    case STMT_IF_ELSE:
    {
        this->translate_statement_ifelse_to_ir_instructions(stmt,from_subprogram);
        // -- Resetear registros
        reg_manager.reset_general_purpose_register_counter();
        break;
    }
    // ---- SENTENCIA WHILE
    case STMT_WHILE:
    {
        this->translate_statement_while_to_ir_instructions(stmt,from_subprogram);
        // -- Resetear registros
        reg_manager.reset_general_purpose_register_counter();
        break;
    }
    // ---- SENTENCIA FOR
    case STMT_FOR:
    {
        this->translate_statement_for_to_ir_instructions(stmt,from_subprogram);
        // -- Resetear registros
        reg_manager.reset_general_purpose_register_counter();
        break;
    }
    // ---- SENTENCIA PRINT
    case STMT_PRINT:
    {
        this->translate_statement_print_to_ir_instructions(stmt,from_subprogram);
        // -- Resetear registros
        reg_manager.reset_general_purpose_register_counter();
        break;
    }
    // ---- SENTENCIA INVOCACION DE PROCEDIMIENTO
    case STMT_PROCEDURE_INV:
    {
        this->translate_statement_procedure_inv_to_ir_instructions(stmt,from_subprogram);
        // -- Resetear registros
        reg_manager.reset_general_purpose_register_counter();
        break;
    }
    // ---- SENTENCIA DE RETORNO DE FUNCION
    case STMT_RETURN:
    {
        this->translate_statement_return_to_ir_instructions(stmt,from_subprogram);
        break;
    }
    // ---- SENTENCIAS DE CREACION Y SINCRONIZACION DE HEBRAS
    case STMT_FORK:
    {
        this->translate_statement_fork_to_ir_instructions(stmt,from_subprogram);
        break;
    }
    case STMT_JOIN:
    {
        this->translate_statement_join_to_ir_instructions(stmt,from_subprogram);
        break;
    }
    
    default:
        break;
    }
}
        
void IR_Translator_Statement::translate_statement_assignment_to_ir_instructions(struct statement * stmt, bool from_subprogram){
    // ---- 0. Obtener nombre de variable
    std::string var_name = std::string(stmt->stmt.statement_assignment.symb->name);
    // ---- 0.A Comprobar si la variable es una variable local de un subprograma (independientemente)
    bool var_is_local_subprog = assistant_translator.is_var_local_subprog(var_name);

    // ---- 1. Obtener registro donde se encontrara la expresion a asignar
    const int reg_expr_to_assign = expr_translator.translate(stmt->stmt.statement_assignment.expr,from_subprogram);
    
    // ---- 1.1 Definir operando registro con el resultado de la expresion a asignar
    IR_operand op_1 = instructions.emit_operand_register(reg_expr_to_assign);

    // ---- 2. Comprobar si la sentencia se esta realizando sobre un subprograma
    int reg_local_variable; int id_variable_in_table;
    if(from_subprogram){
        // ---- 2.1 Buscar si la variable es una variable local de subprograma
        if(var_is_local_subprog){
            // ---- 2.1.A.1 Obtener registro 
            reg_local_variable = assistant_translator.get_reg_from_var_local_subprog(var_name);
        }
        // ---- 2.2 En caso contrario, obtener id de variable (global)
        else{
            // --- Scope global
            id_variable_in_table = tables.get_index_from_global_variable(var_name);
        }
    }
    // ---- 2.B En otro caso, buscar en la tabla
    else{
        id_variable_in_table = tables.get_index_from_local_variable(var_name);
        if(id_variable_in_table == -1){
            // ---- Buscar en otro scope
            id_variable_in_table = tables.get_index_from_global_variable(var_name);
        }
    }
    
    // ---- 3. Definir operando de destino
    IR_operand op_dest;

    // ---- 3.1 Comprobar si se esta realizando sobre un subprograma
    if(from_subprogram && var_is_local_subprog){
        // ---- 3.1.A.1 Emitir operando de tipo registro
        op_dest = instructions.emit_operand_register(reg_local_variable);
    }
    // ---- 3.1.B Comprobar en la tabla de variables
    else{
        if(tables.check_if_variable_is_array_using_index(id_variable_in_table)){
            // -- Obtener el offset
            int reg_offset = expr_translator.translate(stmt->stmt.statement_assignment.index_expr,from_subprogram);

            // -- Obtener operando
            op_dest = instructions.emit_operand_variable_array(id_variable_in_table,reg_offset);
        }
        else{
            // -- Obtener operando normal
            op_dest = instructions.emit_operand_variable(id_variable_in_table);
        }
    }
    
    // ---- 4. Emitir instruccion
    instructions.emit_instruction(IR_OP_STORE,op_dest,op_1);
}

void IR_Translator_Statement::translate_statement_ifelse_to_ir_instructions(struct statement * stmt, bool from_subprogram){
    // ---- 0. Emitir instrucciones para condicion de if/else
    int reg_if_else_condition = expr_translator.translate(stmt->stmt.statement_if_else.condition,from_subprogram);

    // ---- 1. Obtener total de instrucciones en este momento
    const int total_instr_before_if = instructions.size();

    // ---- 2. Generar instrucciones para bloque if
    this->translate_list_statements_to_ir_instructions(stmt->stmt.statement_if_else.if_body,from_subprogram);

    // ---- 3. Obtener posicion actual de instruccion
    int total_instr_after_if = instructions.size()+1;

    // ---- 4. Generar mas instrucciones si hay bloque else
    int id_label_in_table = 0; const std::string id_label_block = instructions.get_next_label_id();
    if(stmt->stmt.statement_if_else.else_body){
        // -- Obtener total de instrucciones tras generacion de bloque if
        const int total_instr_now = instructions.size()+2;

        // -- Generar instruccion de salto condicional
        id_label_in_table = tables.add_entry_label(std::string("else_block(") + id_label_block + ")",total_instr_now+1);
        IR_operand op_expr_cmp = instructions.emit_operand_register(reg_if_else_condition);
        IR_operand op_jmp = instructions.emit_operand_label(id_label_in_table);
        IR_instruction instr_jmp_false(IR_OP_JMP_FALSE,false,op_expr_cmp,op_jmp);

        instructions.add_instruction_to_list_in_position(instr_jmp_false,total_instr_before_if);

        // -- Generar instruccion de etiqueta de bloque else
        instructions.emit_instruction(IR_LABEL,op_jmp);

        // -- Generar instrucciones para bloque else
        this->translate_list_statements_to_ir_instructions(stmt->stmt.statement_if_else.else_body,from_subprogram);
    }

    // ---- 5. Generar instruccion de etiqueta de fin de bloque else
    id_label_in_table = tables.add_entry_label(std::string("end_if(") + id_label_block + ")",instructions.size()+1);
    IR_operand op_end_if = instructions.emit_operand_label(id_label_in_table);
    instructions.emit_instruction(IR_LABEL,op_end_if);

    // ---- 6. Emitir instruccion de salto incondicional a fin de etiqueta en la posicion after if
    IR_instruction instr_jmp_end_if(IR_OP_JMP,op_end_if);
    instructions.add_instruction_to_list_in_position(instr_jmp_end_if,total_instr_after_if);
}

void IR_Translator_Statement::translate_statement_for_to_ir_instructions(struct statement * stmt, bool from_subprogram){
    // ---- 0. Obtener identificador de contador de bucle
    std::string index_name = std::string(stmt->stmt.statement_for.counter_name);
    // ---- 1. Registrar en tabla de variables
    int id_variable_in_table = tables.add_entry_variable(IR_VAR_LOCAL,index_name,IR_VAR_TYPE_INT);

    // ---- 2. Inicializar el contador
    const int reg_index_init = expr_translator.translate(stmt->stmt.statement_for.intialization,from_subprogram);

    // ---- Emitir instruccion de carga de valor en variable
    IR_operand op_index_dest = instructions.emit_operand_variable(id_variable_in_table);
    IR_operand op_index = instructions.emit_operand_register(reg_index_init);
    instructions.emit_instruction(IR_OP_STORE,op_index_dest,op_index);

    // -- Generar etiqueta de entrada de bucle for
    const std::string id_label_block = instructions.get_next_label_id();
    const int instr_for_start = instructions.size()+1;
    int id_label_in_table = tables.add_entry_label(std::string("for_start(") + id_label_block + ")",instr_for_start);
    IR_operand op_for_start = instructions.emit_operand_label(id_label_in_table);
    instructions.emit_instruction(IR_LABEL,op_for_start);

    // ---- Emitir instruccion de comparacion con condicion de fin de bucle
    const int reg_index_end = expr_translator.translate(stmt->stmt.statement_for.finish,from_subprogram);
    const int reg_index_cmp = reg_manager.get_next_general_purpose_register();
    IR_operand op_index_cmp = instructions.emit_operand_register(reg_index_cmp);
    IR_operand op_index_end = instructions.emit_operand_register(reg_index_end);
    instructions.emit_instruction(IR_OP_CMP_LTE,op_index_cmp,op_index,op_index_end);
    const int instr_for_condition = instructions.size();

    // ---- Generar instrucciones de cuerpo de bucle for
    this->translate_list_statements_to_ir_instructions(stmt->stmt.statement_for.body,from_subprogram);

    // ---- Generar instrucciones de actualizacion de contador
    // ------- Generar operacion de carga de incremento
    int id_literal_in_table = tables.add_entry_literal(static_cast<int>(1));
    IR_operand op_index_inc = instructions.emit_operand_literal(id_literal_in_table);
    const int reg_assigned = this->reg_manager.get_next_general_purpose_register();
    IR_operand op_reg_index_inc = instructions.emit_operand_register(reg_assigned);
    instructions.emit_instruction(IR_OP_LOAD,op_reg_index_inc,op_index_inc);

    instructions.emit_instruction(IR_OP_ADD,op_index,op_index,op_reg_index_inc);
    instructions.emit_instruction(IR_OP_STORE,op_index_dest,op_index);

    // ---- Generar instruccion de salto incondicional al inicio del bucle
    instructions.emit_instruction(IR_OP_JMP,op_for_start);

    // ---- Generar instruccion de ruptura de bucle for
    id_label_in_table = tables.add_entry_label(std::string("for_end(") + id_label_block + ")",instructions.size()+2);
    IR_operand op_for_end = instructions.emit_operand_label(id_label_in_table);
    IR_instruction instr_jmp_false(IR_OP_JMP_FALSE,false,op_index_cmp,op_for_end);

    instructions.add_instruction_to_list_in_position(instr_jmp_false,instr_for_condition);

    // ---- Generar instruccion de etiqueta de fin de bucle for
    instructions.emit_instruction(IR_LABEL,op_for_end);
}

void IR_Translator_Statement::translate_statement_while_to_ir_instructions(struct statement * stmt, bool from_subprogram){
    // -- Generar etiqueta de entrada de bucle while
    const std::string id_label_block = instructions.get_next_label_id();
    const int instr_while_start = instructions.size()+1;
    int id_label_in_table = tables.add_entry_label(std::string("while_start(") + id_label_block + ")",instr_while_start);

    // -- Generar instruccion de etiqueta de inicio de while
    IR_operand op_while_start = instructions.emit_operand_label(id_label_in_table);
    instructions.emit_instruction(IR_LABEL,op_while_start);

    // -- Generar instrucciones ir para condicion del bucle
    const int reg_while_condition = expr_translator.translate(stmt->stmt.statement_while.condition,from_subprogram);
    IR_operand op_while_condition = instructions.emit_operand_register(reg_while_condition);

    // -- Obtener total de instrucciones en vector hasta el momento de generar para la condicion
    const int instr_while_condition = instructions.size();

    // -- Generar instrucciones ir para cuerpo del bucle
    this->translate_list_statements_to_ir_instructions(stmt->stmt.statement_while.body,from_subprogram);

    // -- Generar instruccion ir de salto incondicional al inicio del bucle
    instructions.emit_instruction(IR_OP_JMP,op_while_start);

    // -- Generar instruccion de ruptura de bucle while
    id_label_in_table = tables.add_entry_label(std::string("while_end(") + id_label_block + ")",instructions.size()+2);
    IR_operand op_while_end = instructions.emit_operand_label(id_label_in_table);
    IR_instruction instr_jmp_false(IR_OP_JMP_FALSE,false,op_while_condition,op_while_end);

    instructions.add_instruction_to_list_in_position(instr_jmp_false,instr_while_condition);

    // -- Generar instruccion de etiqueta de fin de bucle while
    instructions.emit_instruction(IR_LABEL,op_while_end);
}

void IR_Translator_Statement::translate_statement_print_to_ir_instructions(struct statement * stmt, bool from_subprogram){
    // -- Emitir tantas instrucciones de impresion como expresiones haya
    struct expression * current_expr_to_print = stmt->stmt.statement_print.expressions_list;
    // -- Analizar una a una
    int reg_expression = 0;
    IR_operand op_print;

    while(current_expr_to_print){
        // -- Obtener registro de carga de expresion
        reg_expression = expr_translator.translate(current_expr_to_print,from_subprogram);

        // -- Generar operando de registro
        op_print = instructions.emit_operand_register(reg_expression);

        // -- Emitir instruccion de impresion
        instructions.emit_instruction(IR_OP_PRINT,op_print);

        // -- Ir a siguiente expresion a imprimir
        current_expr_to_print = current_expr_to_print->next;
    }

    // -- Emitir instruccion de fin de impresion
    instructions.emit_instruction(IR_END_PRINT);
}

void IR_Translator_Statement::translate_statement_procedure_inv_to_ir_instructions(struct statement * stmt, bool from_subprogram){
    // ---- 0. Obtener nombre de procedimiento
    std::string procedure_name = std::string(stmt->stmt.statement_procedure_inv.procedure_name);
    // ---- 1. Generar instrucciones IR para cada argumento de procedimiento
    int addr_reg_argument;
    IR_operand op_reg_argument, op_reg_parameter;

    // ---- 1.1 Recorrer la lista de argumentos de invocacion
    struct expression * current_argument = stmt->stmt.statement_procedure_inv.arguments_list;
    while(current_argument){
        // ---- Obtener registro donde se encontrara la expresion
        addr_reg_argument = expr_translator.translate(current_argument,from_subprogram);

        // ---- Definir operando
        op_reg_argument = instructions.emit_operand_register(addr_reg_argument);
        
        // ---- Emitir instruccion de push en pila
        instructions.emit_instruction(IR_OP_PUSH,op_reg_argument);

        // ---- Ir a siguiente argumento
        current_argument = current_argument->next;
    }

    // ---- 2. Generar instruccion de llamada a procedimiento
    // ----- Obtener indice en tabla donde se encuentra la etiqueta de inicio de procedimiento
    std::string call_procedure_label = std::string("start_subprog_") + std::string(stmt->stmt.statement_procedure_inv.procedure_name);
    int index_label_in_table = tables.get_index_from_label_id(call_procedure_label);
    if(index_label_in_table == -1){
        // -- Crear placeholder para etiqueta
        index_label_in_table = tables.add_entry_label(call_procedure_label,-2);
    }

    // ----- Operando etiqueta para realizar el salto
    IR_operand op_label_procedure = instructions.emit_operand_label(index_label_in_table);

    // ----- Emitir instruccion de llamada a procedimiento
    instructions.emit_instruction(IR_OP_CALL,op_label_procedure);
}

void IR_Translator_Statement::translate_statement_return_to_ir_instructions(struct statement * stmt, bool from_subprogram){
    // --- 0. Obtener nombre de funcion de retorno
    //std::string function_name = std::string(stmt->stmt.statement_return.function_name);

    // --- 1. Obtener registro de expresion
    int reg_expr_to_return = expr_translator.translate(stmt->stmt.statement_return.returned_expr,from_subprogram);

    // --- 2. Emitir operando de retorno
    IR_operand op_expr_return = instructions.emit_operand_register(reg_expr_to_return);

    // --- 3. Obtener registro de retorno de funcion
    int reg_return = reg_manager.get_return_subprog_register();

    // --- 3.1 Emitir operando de registro de retorno
    IR_operand op_reg_return = instructions.emit_operand_register(reg_return);

    // --- 4.1 Emitir operando de almacenamiento de resultado en registro de retorno
    instructions.emit_instruction(IR_OP_STORE,op_reg_return,op_expr_return);

    // --- 4.2 Emitir instruccion de retorno
    instructions.emit_instruction(IR_OP_RET);
}

void IR_Translator_Statement::translate_statement_fork_to_ir_instructions(struct statement * stmt, bool from_subprogram){
    // -- 0. Obtener nombre de procedimiento
    std::string procedure_name = std::string(stmt->stmt.statement_fork.forked_procedure);

    // -- 1. Generar nombre para proceso dinamico
    std::string dprocess_name = std::string("dp_") + procedure_name;
    // -- 2. Registrar como variable local
    int id_variable_in_table = tables.add_entry_variable(IR_VAR_LOCAL,dprocess_name,IR_VAR_TYPE_DPROCESS);
    // -- 3. Generar operando de variable dinamic
    IR_operand op_1 = instructions.emit_operand_variable(id_variable_in_table);
    // -- 4. Obtener etiqueta de salto a procedimiento
    std::string call_procedure_label = std::string("start_subprog_") + procedure_name;
    int index_label_in_table = tables.get_index_from_label_id(call_procedure_label);
    // -- 5. Obtener operando de etiqueta de salto
    IR_operand op_2 = instructions.emit_operand_label(index_label_in_table);

    // -- 4. Emitir instruccion
    instructions.emit_instruction(IR_OP_FORK,false,op_1,op_2);
}
        
void IR_Translator_Statement::translate_statement_join_to_ir_instructions(struct statement * stmt, bool from_subprogram){
    // -- 0. Obtener nombre de procedimiento
    std::string forked_procedure = std::string("dp_") + std::string(stmt->stmt.statement_join.joined_procedure);

    // -- 1. Buscar referencia en la tabla de variables
    int id_variable_in_table = tables.get_index_from_local_variable(forked_procedure);
    if(id_variable_in_table == -1)
        id_variable_in_table = tables.get_index_from_global_variable(forked_procedure);

    // -- 2. Emitir operando
    IR_operand op_1 = instructions.emit_operand_variable(id_variable_in_table);
    // -- 3. Emitir instruccion
    instructions.emit_instruction(IR_OP_JOIN,op_1);
}

void IR_Translator_Statement::translate_list_statements_to_ir_instructions(struct statement * list_stmt, bool from_subprogram){
    struct statement *current_stmt = list_stmt;
    while(current_stmt != NULL){
        // -- Traducir sentencia
        this->translate_statement_to_ir_instructions(current_stmt,from_subprogram);
        // -- Ir a siguiente sentencia
        current_stmt = current_stmt->next;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICOS [IR_Translator_Statement] -----

IR_Translator_Statement& IR_Translator_Statement::get_instance(){
    static IR_Translator_Statement instance;
    return instance;
}

void IR_Translator_Statement::translate(struct statement * list_stmt, bool from_subprogam){
    this->translate_list_statements_to_ir_instructions(list_stmt,from_subprogam);
}