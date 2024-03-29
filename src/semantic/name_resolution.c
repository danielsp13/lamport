/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file name_resolution.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para implementar resolucion de nombres
 * sobre el AST
 */

#include "semantic/name_resolution.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE RESOLUCION DE NOMBRES (LISTAS) -----

void resolve_list_declarations(struct declaration *list_declarations, char * precedence){
    // -- Obtener declaracion actual de la lista
    struct declaration *current_declaration = list_declarations;

    // -- Realizar procedimiento mientras haya un nodo en la lista
    while(current_declaration){
        // -- Aplicar resolucion de nombres a nodo
        resolve_declaration(current_declaration,precedence);

        // -- Ir a siguiente declaracion
        current_declaration = current_declaration->next;
    }
}

void resolve_list_expressions(struct expression *list_expressions){
    // -- Obtener expresion actual de la lista
    struct expression *current_expression = list_expressions;

    // -- Realizar procedimiento mientras haya un nodo en la lista
    while(current_expression){
        // -- Aplicar resolucion de nombres a nodo
        resolve_expression(current_expression);

        // -- Ir a siguiente expresion
        current_expression = current_expression->next;
    }
}

void resolve_list_statements(struct statement *list_statements){
    // -- Obtener sentencia actual de la lista
    struct statement *current_statement = list_statements;

    // -- Realizar procedimiento mientras haya un nodo en la lista
    while(current_statement){
        // -- Aplicar resolucion de nombres a nodo
        resolve_statement(current_statement);

        // -- Ir a siguiente sentencia
        current_statement = current_statement->next;
    }
}

void resolve_list_process(struct process *list_process){
    // -- Obtener proceso actual de la lista
    struct process *current_process = list_process;

    // -- Realizar procedimiento mientras haya un nodo en la lista
    while(current_process){
        // -- Aplicar resolucion de nombres a nodo
        resolve_process(current_process);

        // -- Ir a siguiente proceso
        current_process = current_process->next;
    }
}

void resolve_list_parameters(struct parameter *list_parameter){
    // -- Obtener parametro actual de la lista
    struct parameter *current_parameter = list_parameter;
    // -- Definir contador de parametros
    unsigned int position = 0;

    // -- Realizar procedimiento mientras haya un nodo en la lista
    while(current_parameter){
        // -- Aplicar resolucion de nombres a nodo
        resolve_parameter(current_parameter, position);

        // -- Ir a siguiente parametro
        current_parameter = current_parameter->next;
        // -- Actualizar posicion de parametro
        position++;
    }
}

void resolve_list_subprograms(struct subprogram *list_subprograms){
    // -- Obtener subprograma actual de la lista
    struct subprogram *current_subprogram = list_subprograms;

    // -- Realizar procedimiento mientras haya un nodo en la lista
    while(current_subprogram){
        // -- Aplicar resolucion de nombres a nodo
        resolve_subprogram(current_subprogram);

        // -- Ir a siguiente subprograma
        current_subprogram = current_subprogram->next;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO DECLARACIONES) -----

void resolve_declaration(struct declaration *decl, char * precedence){
    // -- Comprobar que la declaracion existe
    if(!decl)
        return;

    // -- Comprobar existencia de simbolo en la tabla
    struct symbol * target_symb = lookup_symbol_from_current_scope(decl->name);

    if(target_symb){
        // -- Realizar handling de este error : VARIABLE REDEFINIDA
        // -- Crear error
        struct error * error = create_error_semantic_duplicated_symbol(decl->name,decl->line, target_symb->line, ERR_DUPLICATED_VARIABLE_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    else{
        // -- Determinar si la declaracion es local o global
        // ---> Si scope_level() == 1 --> Estamos en el ambito global
        // ---> Si scope_level() > 1 --> Estamos en ambito local
        symbol_t kind = scope_level() > 1 ? SYMBOL_LOCAL : SYMBOL_GLOBAL;

        // -- Crear y asociar simbolo a esta declaracion
        switch (kind)
        {
        case SYMBOL_LOCAL:
        {
            decl->symb = create_symbol_local(decl->type, decl->name, precedence, decl->line);
            break;
        }

        case SYMBOL_GLOBAL:
        {
            decl->symb = create_symbol_global(decl->type, decl->name, decl->line);
            break;
        }
        
        default:
            break;
        }

        // -- Vincular simbolo al scope actual
        bind_symbol_to_scope(decl->symb);

        // -- Resolver expresion de inicializacion de array (si es array)
        if(decl->type->kind == TYPE_ARRAY){
            // -- Resolucion de nombres en: expresion
            resolve_expression(decl->type->size);
        }

        // -- Resolver expresion de valor (si existe)
        if(decl->value){
            // -- Resolucion de nombres en: expresion
            resolve_expression(decl->value);
        }
    }
    
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO EXPRESIONES) -----

void resolve_expression(struct expression *expr){
    // -- Comprobar que la expresion existe
    if(!expr)
        return;

    // -- Aplicar resolucion de nombres dependiendo del tipo de expresion
    switch (expr->kind)
    {
    case EXPR_BINARY:
    {
        // -- Aplicar resolucion de nombres a expresiones de tipo operacion binaria
        resolve_expression_binary_operation(expr);
        break;
    }

    case EXPR_UNARY:
    {
        // -- Aplicar resolucion de nombres a expresiones de tipo operacion unaria
        resolve_expression_unary_operation(expr);
        break;
    }

    case EXPR_IDENTIFIER:
    {
        // -- Aplicar resolucion de nombres a expresiones de tipo identificador
        resolve_expression_identifier(expr);
        break;
    }
    
    case EXPR_FUNCTION_INV:
    {
        // -- Aplicar resolucion de nombres a expresiones de tipo invocacion de funciones
        resolve_expression_function_inv(expr);
        break;
    }

    case EXPR_LITERAL:
    {
        // -- No se necesita resolucion de nombres en este tipo de expresion
        break;
    }

    case EXPR_GROUPED:
    {
        // -- Aplicar resolucion de nombres a expresiones entre parentesis
        resolve_expression_grouped(expr);
        break;
    }
    
    default:
    {
        // -- No se deberia caer en este caso
        break;
    }
    }
}

void resolve_expression_binary_operation(struct expression *expr){
    // -- Comprobar que la expresion existe
    if(!expr)
        return;

    // -- Aplicar resolucion de nombres a los operandos de la operacion
    // -- Resolucion de nombres a operando izquierdo
    resolve_expression(expr->expr.expression_binary_operation.left);
    // -- Resolucion de nombres a operando derecho
    resolve_expression(expr->expr.expression_binary_operation.right);
}

void resolve_expression_unary_operation(struct expression *expr){
    // -- Comprobar que la expresion existe
    if(!expr)
        return;

    // -- Aplicar resolucion de nombres a operando de la operacion
    resolve_expression(expr->expr.expression_unary_operation.left);
}

void resolve_expression_identifier(struct expression *expr){
    // -- Comprobar que la expresion existe
    if(!expr)
        return;

    // -- Asignar referencia de simbolo a esta expresion, buscandolo de la tabla
    // -- Se busca el simbolo en todos los scopes existentes en la tabla
    struct symbol * target_symb = lookup_symbol_from_all_scopes(expr->expr.expression_identifier.id); 

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!target_symb){
        // -- Realizar handling de este error: USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error * error = create_error_semantic_undefined_symbol(expr->expr.expression_identifier.id, expr->expr.expression_identifier.line, ERR_UNDEFINED_VARIABLE_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    else{
        // -- Asignar simbolo
        expr->expr.expression_identifier.symb = target_symb;
    }

    // -- Si el identificador tiene asociado una expresion de indice, resolverla
    if(expr->expr.expression_identifier.index_expr){
        // -- Aplicar resolucion de nombres a expresion de indice
        resolve_expression(expr->expr.expression_identifier.index_expr);
    }
}

void resolve_expression_function_inv(struct expression *expr){
    // -- Comprobar que la expresion existe
    if(!expr)
        return;

    // -- Asignar referencia de simbolo a esta expresion, buscandolo de la tabla
    struct symbol * target_symb = lookup_symbol_from_all_scopes(expr->expr.expression_function_inv.function_name);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!target_symb){
        // -- Realizar handling de este error: USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error * error = create_error_semantic_undefined_symbol(expr->expr.expression_function_inv.function_name, expr->expr.expression_function_inv.line, ERR_UNDEFINED_FUNCTION_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    else{
        // -- Asignar simbolo
        expr->expr.expression_function_inv.symb = copy_symbol(target_symb);
    }

    // -- Comprobar si para la funcion dispone de parametros
    int total_parameters = 0;
    struct type * current_type = expr->expr.expression_function_inv.symb->list_type_parameters;
    while(current_type){
        total_parameters++;
        current_type = current_type->next;
    }

    int total_arguments = 0;
    struct expression * current_argument = expr->expr.expression_function_inv.arguments_list;
    while(current_argument){
        total_arguments++;
        current_argument = current_argument->next;
    }

    if(total_parameters != total_arguments){
        // -- Realizar handling de este error: USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error * error = create_error_semantic_invalid_parameters(expr->expr.expression_function_inv.function_name,expr->expr.expression_function_inv.line, ERR_UNDEFINED_PARAMETERS_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }

    // -- Aplicar resolucion de nombres a la lista de expresiones que hacen de argumentos de la funcion
    if(expr->expr.expression_function_inv.arguments_list){
        // -- Aplicar resolucion de nombres a argumentos (lista)
        resolve_list_expressions(expr->expr.expression_function_inv.arguments_list);
    }
}

void resolve_expression_grouped(struct expression *expr){
    // -- Comprobar que la expresion existe
    if(!expr)
        return;

    // -- Aplicar resolucion de nombres a la expresion que engloban los parentesis
    resolve_expression(expr->expr.grouped_expression);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO SENTENCIAS) -----

void resolve_statement(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;

    // -- Aplicar resolucion de nombres dependiendo del tipo de sentencia
    switch (stmt->kind)
    {
    case STMT_ASSIGNMENT:
    {
        // -- Aplicar resolucion de nombres a sentencias de tipo asignacion
        resolve_statement_assignment(stmt);
        break;
    }

    case STMT_WHILE:
    {
        // -- Aplicar resolucion de nombres a sentencias de tipo while
        resolve_statement_while(stmt);
        break;
    }

    case STMT_FOR:
    {
        // -- Aplicar resolucion de nombres a sentencias de tipo for
        resolve_statement_for(stmt);
        break;
    }

    case STMT_IF_ELSE:
    {
        // -- Aplicar resolucion de nombres a sentencias de tipo if-else
        resolve_statement_if_else(stmt);
        break;
    }

    case STMT_PROCEDURE_INV:
    {
        // -- Aplicar resolucion de nombres a sentencias de tipo invocacion de procedimiento
        resolve_statement_procedure_inv(stmt);
        break;
    }

    case STMT_BLOCK_BEGIN:
    {
        // -- Aplicar resolucion de nombres a sentencias de tipo bloque
        resolve_statement_block(stmt);
        break;
    }

    case STMT_BLOCK_COBEGIN:
    {
        // -- Aplicar resolucion de nombres a sentencias de tipo bloque
        resolve_statement_block(stmt);
        break;
    }

    case STMT_FORK:
    {
        // -- Aplicar resolucion de nombres a sentencias de tipo fork
        resolve_statement_fork(stmt);
        break;
    }

    case STMT_JOIN:
    {
        // -- Aplicar resolucion de nombres a sentencias de tipo join
        resolve_statement_join(stmt);
        break;
    }

    case STMT_SLEEP:
    {
        resolve_statement_sleep(stmt);
        break;
    }

    case STMT_ATOMIC:
    {
        // -- Aplicar resolucion de nombres a sentencias de tipo bloque
        resolve_statement_block(stmt);
        break;
    }

    case STMT_RETURN:
    {
        // -- Aplicar resolucion de nombres a sentencias de tipo retorno
        resolve_statement_return(stmt);
        break;
    }

    case STMT_PRINT:
    {
        // -- Aplicar resolucion de nombres a sentencias de tipo print
        resolve_statement_print(stmt);
        break;
    }

    case STMT_SEM_WAIT:
    {
        resolve_statement_sem_wait(stmt);
        break;
    }

    case STMT_SEM_SIGNAL:
    {
        resolve_statement_sem_signal(stmt);
        break;
    }
    
    default:
    {
        // -- No se deberia caer en este caso
        break;
    }
    }
}

void resolve_statement_assignment(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;

    // -- Aplicar resolucion de nombres a identificador de variable
    // -- Asignar referencia de simbolo a esta sentencia
    struct symbol * target_symb = lookup_symbol_from_all_scopes(stmt->stmt.statement_assignment.variable_name);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula) 
    if(!target_symb){
        // -- Realizar handling de este error: USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error * error = create_error_semantic_undefined_symbol(stmt->stmt.statement_assignment.variable_name,stmt->stmt.statement_assignment.line, ERR_UNDEFINED_VARIABLE_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    else{
        // -- Asignar simbolo
        stmt->stmt.statement_assignment.symb = copy_symbol(target_symb);
    }

    // -- Si el identificador de variable tiene asociado una expresion de indice, resolverla
    if(stmt->stmt.statement_assignment.index_expr){
        // -- Aplicar resolucion de nombres a expresion de indice
        resolve_expression(stmt->stmt.statement_assignment.index_expr);
    }

    // -- Aplicar resolucion de nombres a la expresion de asignacion
    resolve_expression(stmt->stmt.statement_assignment.expr);
}

void resolve_statement_while(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;

    // -- Aplicar resolucion de nombres a la condicion del bucle
    resolve_expression(stmt->stmt.statement_while.condition);

    // -- Aplicar resolucion de nombres al cuerpo del bucle
    resolve_list_statements(stmt->stmt.statement_while.body);
}

void resolve_statement_for(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;
    
    // -- Asignar referencia de simbolo a este parametro, buscandolo de la tabla
    // -- Se busca el simbolo solo en el scope actual
    struct symbol * target_symb = lookup_symbol_from_all_scopes(stmt->stmt.statement_for.counter_name);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    // -- OJO! Aqui queremos que NO se encuentre, si se encuentra tenemos un error de redefinicion
    if(target_symb){
        // -- Realizar handling de este error : INDICE REDEFINIDO
        // -- Crear error
        struct error * error = create_error_semantic_duplicated_symbol(stmt->stmt.statement_for.counter_name, stmt->stmt.statement_for.line, target_symb->line ,ERR_DUPLICATED_INDEX_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    else{
        // -- Creamos un simbolo de tipo local
        struct type * type_symb = create_basic_type(TYPE_INTEGER);
        struct symbol * new_symb = create_symbol_local(type_symb, stmt->stmt.statement_for.counter_name,NULL, stmt->stmt.statement_for.line);
        free_type(type_symb);

        if(new_symb){
            // -- Asignar simbolo a for
            stmt->stmt.statement_for.symb = new_symb;

            // -- Vincular simbolo al scope actual
            bind_symbol_to_scope(stmt->stmt.statement_for.symb);
        }
    }

    // -- Aplicar resolucion de nombres a la expresion de inicio del bucle for
    resolve_expression(stmt->stmt.statement_for.intialization);

    // -- Aplicar resolucion de nombres a la expresion de finalizacion de bucle for
    resolve_expression(stmt->stmt.statement_for.finish);

    // -- Aplicar resolucion de nombres a la lista de sentencias del cuerpo de bucle
    resolve_list_statements(stmt->stmt.statement_for.body);
}

void resolve_statement_if_else(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;

    // -- Aplicar resolucion de nombres a la condicion del if
    resolve_expression(stmt->stmt.statement_if_else.condition);

    // -- Aplicar resolucion de nombres a la lista de sentencias del cuerpo del if
    resolve_list_statements(stmt->stmt.statement_if_else.if_body);

    // -- Aplicar resolucion de nombres a la lista de sentencias del cuerpo del else (si tiene)
    if(stmt->stmt.statement_if_else.else_body){
        resolve_list_statements(stmt->stmt.statement_if_else.else_body);
    }
}

void resolve_statement_procedure_inv(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;

    // -- Aplicar resolucion de nombres al identificador de procedimiento
    // -- Asignar referencia de simbolo a esta sentencia
    struct symbol * target_symb = lookup_symbol_from_all_scopes(stmt->stmt.statement_procedure_inv.procedure_name);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!target_symb){
        // -- Realizar handling de este error: USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error * error = create_error_semantic_undefined_symbol(stmt->stmt.statement_procedure_inv.procedure_name,stmt->stmt.statement_procedure_inv.line, ERR_UNDEFINED_PROCEDURE_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    else{
        stmt->stmt.statement_procedure_inv.symb = copy_symbol(target_symb);
    }

    // -- Comprobar si para la funcion dispone de parametros
    int total_parameters = 0;
    struct type * current_type = stmt->stmt.statement_procedure_inv.symb->list_type_parameters;
    while(current_type){
        total_parameters++;
        current_type = current_type->next;
    }

    int total_arguments = 0;
    struct expression * current_argument = stmt->stmt.statement_procedure_inv.arguments_list;
    while(current_argument){
        total_arguments++;
        current_argument = current_argument->next;
    }

    if(total_parameters != total_arguments){
        // -- Realizar handling de este error: USO INVALIDO DE SUBPROGRAMA
        // -- Crear error
        struct error * error = create_error_semantic_invalid_parameters(stmt->stmt.statement_procedure_inv.procedure_name,stmt->stmt.statement_procedure_inv.line, ERR_UNDEFINED_PARAMETERS_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }


    // -- Si dispone de argumentos de invocacion, aplicar resolucion de nombres a la lista
    resolve_list_expressions(stmt->stmt.statement_procedure_inv.arguments_list);
}

void resolve_statement_block(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;

    // -- Aplicar resolucion de nombres a la lista de sentencias del bloque
    resolve_list_statements(stmt->stmt.statement_block.body);
}

void resolve_statement_fork(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;


    // -- Aplicar resolucion de nombres al identificador de proceso
    // -- Asignar referencia de simbolo a este proceso
    struct symbol * target_symb = lookup_symbol_from_all_scopes(stmt->stmt.statement_fork.forked_procedure);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!target_symb){
        // -- Realizar handling de este error : USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error * error = create_error_semantic_undefined_symbol(stmt->stmt.statement_fork.forked_procedure,stmt->stmt.statement_fork.line, ERR_UNDEFINED_PROCESS_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    // -- Asignar simbolo
    else{
        stmt->stmt.statement_fork.symb = copy_symbol(target_symb);
        stmt->stmt.statement_fork.symb->type = create_dprocess_type();
    }
}

void resolve_statement_join(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    /*if(!stmt)
        return;


    // -- Aplicar resolucion de nombres al identificador de proceso
    // -- Asignar referencia de simbolo a este proceso
    struct symbol * target_symb = lookup_symbol_from_all_scopes(stmt->stmt.statement_join.joined_procedure);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!target_symb){
        // -- Realizar handling de este error : USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error * error = create_error_semantic_undefined_symbol(stmt->stmt.statement_join.joined_procedure,stmt->stmt.statement_join.line, ERR_UNDEFINED_PROCESS_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    // -- Asignar simbolo
    else{
        stmt->stmt.statement_join.symb = copy_symbol(target_symb);
        stmt->stmt.statement_join.symb->type = create_dprocess_type();
    }*/
}

void resolve_statement_sleep(struct statement *stmt){
    if(!stmt)
        return;

    resolve_expression(stmt->stmt.statement_sleep.sleep_expr);
}

void resolve_statement_return(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;

    // -- Aplicar resolucion de nombres a la expresion de retorno
    resolve_expression(stmt->stmt.statement_return.returned_expr);
}

void resolve_statement_print(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;

    // -- Aplicar resolucion de nombres a las expresiones de impresion
    resolve_list_expressions(stmt->stmt.statement_print.expressions_list);
}

void resolve_statement_sem_wait(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;


    // -- Aplicar resolucion de nombres al identificador de proceso
    // -- Asignar referencia de simbolo a este proceso
    struct symbol * target_symb = lookup_symbol_from_all_scopes(stmt->stmt.statement_semaphore.semaphore_name);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!target_symb){
        // -- Realizar handling de este error : USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error * error = create_error_semantic_undefined_symbol(stmt->stmt.statement_semaphore.semaphore_name,stmt->stmt.statement_semaphore.line, ERR_UNDEFINED_PROCESS_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    // -- Asignar simbolo
    else{
        stmt->stmt.statement_semaphore.symb = copy_symbol(target_symb);
    }
}

void resolve_statement_sem_signal(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;


    // -- Aplicar resolucion de nombres al identificador de proceso
    // -- Asignar referencia de simbolo a este proceso
    struct symbol * target_symb = lookup_symbol_from_all_scopes(stmt->stmt.statement_semaphore.semaphore_name);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!target_symb){
        // -- Realizar handling de este error : USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error * error = create_error_semantic_undefined_symbol(stmt->stmt.statement_semaphore.semaphore_name,stmt->stmt.statement_semaphore.line, ERR_UNDEFINED_PROCESS_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    // -- Asignar simbolo
    else{
        stmt->stmt.statement_semaphore.symb = copy_symbol(target_symb);
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO PROCESOS) -----

void resolve_process(struct process *proc){
    // -- Comprobar que el proceso existe
    if(!proc)
        return;

    // -- Aplicar resolucion de nombres al identificador de proceso
    struct symbol * target_symb = lookup_symbol_from_all_scopes(proc->name_process);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(target_symb){
        // -- Realizar handling de este error : PROCESO REDEFINIDO
        // -- Crear error
        struct error * error = create_error_semantic_duplicated_symbol(proc->name_process,proc->line, target_symb->line, ERR_DUPLICATED_PROCESS_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    // -- En caso de que no se encuentre, realizamos la insercion en la tabla de simbolos
    else{
        struct type * dproc_type = create_dprocess_type();
        // -- Creamos un simbolo de tipo parametro
        proc->symb_process = create_symbol_global(dproc_type,proc->name_process, proc->line);
        
        // -- Liberar tipo
        free_type(dproc_type);

        // -- Vincular simbolo al scope actual
        bind_symbol_to_scope(proc->symb_process);
    }

    // -- Liberar simbolo
    //free_symbol(target_symb);

    // -- ENTRAR EN UN NUEVO SCOPE
    push_scope_to_symbol_table();

    // -- Aplicar resolucion de nombres a declaraciones de proceso
    resolve_list_declarations(proc->declarations,proc->name_process);

    switch (proc->kind)
    {
    case PROCESS_SINGLE:
    {
        // -- Aqui no se hace nada, pues ya se hizo toda la resolucion que se debia
        break;
    }

    case PROCESS_VECTOR:
    {
        // -- Aplicar resolucion de nombres a proceso de tipo vector
        resolve_process_vector(proc);
        break;
    }
    
    default:
    {
        // -- No deberia caer en este caso
        break;
    }
    }

    // -- Aplicar resolucion de nombres a las sentencias del proceso
    resolve_list_statements(proc->statements);

    // -- SALIR DEL SCOPE CREADO
    remove_current_scope_from_symbol_table();
}

void resolve_process_vector(struct process *proc){
    // -- Comprobar que el proceso existe
    if(!proc)
        return;

    struct symbol * target_symb = lookup_symbol_from_all_scopes(proc->index_identifier);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    // -- OJO! Aqui queremos que NO se encuentre, si se encuentra tenemos un error de redefinicion
    if(target_symb){
        // -- Realizar handling de este error : INDICE REDEFINIDO
        // -- Crear error
        struct error * error = create_error_semantic_duplicated_symbol(proc->index_identifier, proc->line, target_symb->line ,ERR_DUPLICATED_INDEX_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    else{
        // -- Creamos un simbolo de tipo local
        struct type * type_symb = create_basic_type(TYPE_INTEGER);
        struct symbol * new_symb = create_symbol_local(type_symb, proc->index_identifier, proc->name_process, proc->line);
        free_type(type_symb);

        if(new_symb){
            // -- Asignar simbolo a indice de proceso
            proc->symb_index = new_symb;

            // -- Vincular simbolo al scope actual
            bind_symbol_to_scope(proc->symb_index);
        }
    }

    // -- Aplicar resolucion de nombres a la expresion de inicio de indexacion
    resolve_expression(proc->index_start);
    // -- Aplicar resolucion de nombres a la expresion de fin de indexacion
    resolve_expression(proc->index_end);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO TIPO DE DATO) -----

void resolve_type(struct type *type){
    // -- Comprobar que el tipo de dato existe
    if(!type)
        return;

    // -- Aplicar resolucion de nombres en los casos que sean requeridos
    switch (type->kind)
    {
    case TYPE_ARRAY:
    {
        // -- Aplicar resolucion de nombres al tipo de dato array
        resolve_type_array(type);
        break;
    }
    
    default:
    {
        // -- En el resto de casos, no es necesario aplicar resolucion de nombres
        break;
    }
    }
}

void resolve_type_array(struct type *type){
    // -- Comprobar que el tipo de dato existe
    if(!type)
        return;

    // -- Aplicar resolucion de nombres a size de array
    resolve_expression(type->size);

    // -- Aplicar resolucion de nombres a subtipo de dato
    resolve_type(type->subtype);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO LISTA DE PARAMETROS) -----

void resolve_parameter(struct parameter *parameter, unsigned int position){
    // -- Comprobar que el parametro existe
    if(!parameter)
        return;

    // -- Asignar referencia de simbolo a este parametro, buscandolo de la tabla
    // -- Se busca el simbolo solo en el scope actual
    struct symbol * target_symb = lookup_symbol_from_current_scope(parameter->name_parameter);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    // -- OJO! Aqui queremos que NO se encuentre, si se encuentra tenemos un error de redefinicion
    if(target_symb){
        // -- Realizar handling de este error : PARAMETRO REDEFINIDO
        // -- Crear error
        struct error * error = create_error_semantic_duplicated_symbol_parameter(parameter->name_parameter,parameter->line,target_symb->which, ERR_DUPLICATED_PARAMETER_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);
    }
    // -- En caso de que no se encuentre, realizamos la insercion en la tabla de simbolos
    else{
        // -- Creamos un simbolo de tipo parametro
        parameter->symb = create_symbol_param(parameter->type,parameter->name_parameter,position,parameter->line);

        // -- Vincular simbolo al scope actual
        bind_symbol_to_scope(parameter->symb);
    }

    // -- Aplicar resolucion de nombres a tipo de parametro
    resolve_type(parameter->type);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO SUBPROGRAMA) -----

void resolve_subprogram(struct subprogram *subprog){
    // -- Comprobar que el subprograma existe
    if(!subprog)
        return;

    // -- Asignar referencia de simbolo a este subprograma, buscandolo en la tabla
    // -- Se busca el simbolo en todos los scopes existentes
    struct symbol * target_symb = lookup_symbol_from_all_scopes(subprog->name_subprogram);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(target_symb){
        // -- Realizar handling de este error : SUBPROGRAMA REDEFINIDO
        // -- Crear error
        struct error * error = create_error_semantic_duplicated_symbol(subprog->name_subprogram,subprog->line, target_symb->line, ERR_DUPLICATED_SUBPROGRAM_MSG);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_to_list(error);

        // -- Liberar simbolo
        //free_symbol(target_symb);
    }
    // -- En caso de que no se encuentre, realizamos la insercion en la tabla de simbolos
    else{
        // -- Creamos un simbolo de tipo global
        struct symbol * new_symb = create_symbol_global(subprog->type, subprog->name_subprogram, subprog->line);
        if(new_symb){
            // -- incluir el tipo de dato de los parametros en el simbolo del subprograma
            new_symb->list_type_parameters = copy_list_types(subprog->type_parameters);

            // -- Asignar simbolo a subprograma
            subprog->symb = new_symb;

            // -- Vincular simbolo al scope actual
            bind_symbol_to_scope(subprog->symb);
        }
    }

    // -- ENTRAR EN UN NUEVO SCOPE
    push_scope_to_symbol_table();

    // -- Aplicar resolucion de nombres de parametros
    resolve_list_parameters(subprog->parameters);

    // -- Aplicar resolucion de nombres a declaraciones
    resolve_list_declarations(subprog->declarations,subprog->name_subprogram);

    // -- Aplicar resolucion de nombres a sentencias
    resolve_list_statements(subprog->statements);

    // -- Resolucion de nombres en subprograma de tipo funcion
    if(subprog->kind == SUBPROGRAM_FUNCTION){
        // -- Aplicar resolucion de nombres a tipo de dato de retorno de funcion
        resolve_type(subprog->type);
    }

    // -- SALIR DEL SCOPE CREADO
    remove_current_scope_from_symbol_table();
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO PROGRAMA) -----

void resolve_program(struct program *prog){
    // -- Comprobar que el programa existe
    if(!prog)
        return;

    // -- ENTRAR EN UN NUEVO SCOPE
    push_scope_to_symbol_table();

    // -- Aplicar resolucion de nombres a lista de declaraciones
    resolve_list_declarations(prog->declarations,NULL);

    // -- Aplicar resolucion de nombres a lista de subprogramas
    resolve_list_subprograms(prog->subprograms);

    // -- Aplicar resolucion de nombres a lista de procesos
    resolve_list_process(prog->process);

    // -- SALIR DEL SCOPE CREADO
    remove_current_scope_from_symbol_table();
}