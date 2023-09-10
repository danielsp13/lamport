/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file name_resolution.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para implementar resolucion de nombres
 * sobre el AST
 */

#include "semantic/name_resolution.h"

// ===============================================================

// ----- DEFINICION DE CONSTANTES DE CONTROL -----

// Cuenta el total de errores semanticos producidos en la resolucion de nombres
unsigned long TOTAL_ERROR_NAME_RESOLUTION = 0;

// Lista enlazada de errores semanticos producidos en la resolucion de nombres
struct error_semantic *list_error_name_resolution = NULL;

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE RESOLUCION DE NOMBRES (LISTAS) -----

void resolve_list_declarations(struct declaration *list_declarations){
    // -- Obtener declaracion actual de la lista
    struct declaration *current_declaration = list_declarations;

    // -- Realizar procedimiento mientras haya un nodo en la lista
    while(current_declaration){
        // -- Aplicar resolucion de nombres a nodo
        resolve_declaration(current_declaration);

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

void resolve_list_parameters(struct parameter_list *list_parameter){
    // -- Obtener parametro actual de la lista
    struct parameter_list *current_parameter = list_parameter;
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

void resolve_declaration(struct declaration *decl){
    // -- Comprobar que la declaracion existe
    if(!decl)
        return;

    // -- Determinar si la declaracion es local o global
    // ---> Si scope_level() == 1 --> Estamos en el ambito global
    // ---> Si scope_level() > 1 --> Estamos en ambito local
    symbol_t kind = scope_level() > 1 ? SYMBOL_LOCAL : SYMBOL_GLOBAL;

    // -- Crear y asociar simbolo a esta declaracion
    switch (kind)
    {
    case SYMBOL_LOCAL:
        decl->symb = create_symbol_local(decl->type, decl->name);
        break;

    case SYMBOL_GLOBAL:
        decl->symb = create_symbol_global(decl->type, decl->name);
        break;
    
    default:
        break;
    }

    // -- Vincular simbolo al scope actual
    bind_symbol_to_scope(decl->symb);

    // -- Resolver expresion de valor (si existe)
    if(decl->value){
        // -- Resolucion de nombres en: expresion
        resolve_expression(decl->value);
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
        // -- Aplicar resolucion de nombres a expresiones de tipo operacion binaria
        resolve_expression_binary_operation(expr);
        break;

    case EXPR_UNARY:
        // -- Aplicar resolucion de nombres a expresiones de tipo operacion unaria
        resolve_expression_unary_operation(expr);
        break;

    case EXPR_IDENTIFIER:
        // -- Aplicar resolucion de nombres a expresiones de tipo identificador
        resolve_expression_identifier(expr);
        break;
    
    case EXPR_FUNCTION_INV:
        // -- Aplicar resolucion de nombres a expresiones de tipo invocacion de funciones
        resolve_expression_function_inv(expr);
        break;

    case EXPR_LITERAL:
        // -- No se necesita resolucion de nombres en este tipo de expresion
        break;

    case EXPR_GROUPED:
        // -- Aplicar resolucion de nombres a expresiones entre parentesis
        resolve_expression_grouped(expr);
        break;
    
    default:
        // -- No se deberia caer en este caso
        break;
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
    expr->expr.expression_identifier.symb = lookup_symbol_from_all_scopes(expr->expr.expression_identifier.id);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!expr->expr.expression_identifier.symb){
        // -- Realizar handling de este error: USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error_semantic * error = create_error_semantic_undefined_symbol(expr->expr.expression_identifier.id, expr->expr.expression_identifier.line);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_name_resolution_to_list(error);
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
    expr->expr.expression_function_inv.symb = lookup_symbol_from_all_scopes(expr->expr.expression_function_inv.function_name);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!expr->expr.expression_function_inv.symb){
        // -- Realizar handling de este error: USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error_semantic * error = create_error_semantic_undefined_symbol(expr->expr.expression_function_inv.function_name, expr->expr.expression_function_inv.line);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_name_resolution_to_list(error);
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
        // -- Aplicar resolucion de nombres a sentencias de tipo asignacion
        resolve_statement_assignment(stmt);
        break;

    case STMT_WHILE:
        // -- Aplicar resolucion de nombres a sentencias de tipo while
        resolve_statement_while(stmt);
        break;

    case STMT_FOR:
        // -- Aplicar resolucion de nombres a sentencias de tipo for
        resolve_statement_for(stmt);
        break;

    case STMT_IF_ELSE:
        // -- Aplicar resolucion de nombres a sentencias de tipo if-else
        resolve_statement_if_else(stmt);
        break;

    case STMT_PROCEDURE_INV:
        // -- Aplicar resolucion de nombres a sentencias de tipo invocacion de procedimiento
        resolve_statement_procedure_inv(stmt);
        break;

    case STMT_BLOCK_BEGIN:
        // -- Aplicar resolucion de nombres a sentencias de tipo bloque
        resolve_statement_block(stmt);
        break;

    case STMT_BLOCK_COBEGIN:
        // -- Aplicar resolucion de nombres a sentencias de tipo bloque
        resolve_statement_block(stmt);
        break;

    case STMT_FORK:
        // -- Aplicar resolucion de nombres a sentencias de tipo fork
        resolve_statement_fork(stmt);
        break;

    case STMT_ATOMIC:
        // -- Aplicar resolucion de nombres a sentencias de tipo bloque
        resolve_statement_block(stmt);
        break;

    case STMT_RETURN:
        // -- Aplicar resolucion de nombres a sentencias de tipo retorno
        resolve_statement_return(stmt);
        break;

    case STMT_PRINT:
        // -- Aplicar resolucion de nombres a sentencias de tipo print
        resolve_statement_print(stmt);
        break;
    
    default:
        // -- No se deberia caer en este caso
        break;
    }
}

void resolve_statement_assignment(struct statement *stmt){
    // -- Comprobar que la sentencia existe
    if(!stmt)
        return;

    // -- Aplicar resolucion de nombres a identificador de variable
    // -- Asignar referencia de simbolo a esta sentencia
    stmt->stmt.statement_assignment.symb = lookup_symbol_from_all_scopes(stmt->stmt.statement_assignment.variable_name);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula) 
    if(!stmt->stmt.statement_assignment.symb){
        // -- Realizar handling de este error: USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error_semantic * error = create_error_semantic_undefined_symbol(stmt->stmt.statement_assignment.variable_name,stmt->stmt.statement_assignment.line);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_name_resolution_to_list(error);
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

    // -- Aplicar resolucion de nombres al identificador de contador de bucle
    // -- Asignar referencia de simbolo a esta sentencia
    stmt->stmt.statement_for.symb = lookup_symbol_from_all_scopes(stmt->stmt.statement_for.counter_name);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!stmt->stmt.statement_for.symb){
        // -- Realizar handling de este error: USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error_semantic * error = create_error_semantic_undefined_symbol(stmt->stmt.statement_for.counter_name,stmt->stmt.statement_for.line);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_name_resolution_to_list(error);
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
    stmt->stmt.statement_procedure_inv.symb = lookup_symbol_from_all_scopes(stmt->stmt.statement_procedure_inv.procedure_name);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!stmt->stmt.statement_procedure_inv.symb){
        // -- Realizar handling de este error: USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error_semantic * error = create_error_semantic_undefined_symbol(stmt->stmt.statement_procedure_inv.procedure_name,stmt->stmt.statement_procedure_inv.line);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_name_resolution_to_list(error);
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
    stmt->stmt.statement_fork.symb = lookup_symbol_from_all_scopes(stmt->stmt.statement_fork.forked_process);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!stmt->stmt.statement_fork.symb){
        // -- Realizar handling de este error : USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error_semantic * error = create_error_semantic_undefined_symbol(stmt->stmt.statement_fork.forked_process,stmt->stmt.statement_fork.line);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_name_resolution_to_list(error);
    }
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

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO PROCESOS) -----

void resolve_process(struct process *proc){
    // -- Comprobar que el proceso existe
    if(!proc)
        return;

    // -- Aplicar resolucion de nombres al identificador de proceso
    proc->symb_process = lookup_symbol_from_all_scopes(proc->name_process);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(proc->symb_process){
        // -- Realizar handling de este error : PROCESO REDEFINIDO
        // -- Crear error
        struct error_semantic * error = create_error_semantic_duplicated_symbol(proc->name_process,proc->line);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_name_resolution_to_list(error);
    }
    // -- En caso de que no se encuentre, realizamos la insercion en la tabla de simbolos
    else{
        // -- Creamos un simbolo de tipo parametro
        proc->symb_process = create_symbol_global(NULL,proc->name_process);

        // -- Vincular simbolo al scope actual
        bind_symbol_to_scope(proc->symb_process);
    }

    // -- ENTRAR EN UN NUEVO SCOPE
    push_scope_to_symbol_table();

    // -- Aplicar resolucion de nombres a declaraciones de proceso
    resolve_list_declarations(proc->declarations);


    switch (proc->kind)
    {
    case PROCESS_SINGLE:
        // -- Aqui no se hace nada, pues ya se hizo toda la resolucion que se debia
        break;

    case PROCESS_VECTOR:
        // -- Aplicar resolucion de nombres a proceso de tipo vector
        resolve_process_vector(proc);
        break;
    
    default:
        // -- No deberia caer en este caso
        break;
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

    // -- Aplicar resolucion de nombres al identificador de indexador de procesos
    proc->symb_index = lookup_symbol_from_all_scopes(proc->index_identifier);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(!proc->symb_index){
        // -- Realizar handling de este error : USO DE SIMBOLO SIN DECLARAR
        // -- Crear error
        struct error_semantic * error = create_error_semantic_undefined_symbol(proc->index_identifier, proc->line);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_name_resolution_to_list(error);
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
        // -- Aplicar resolucion de nombres al tipo de dato array
        resolve_type_array(type);
        break;
    
    default:
        // -- En el resto de casos, no es necesario aplicar resolucion de nombres
        break;
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

void resolve_parameter(struct parameter_list *parameter, unsigned int position){
    // -- Comprobar que el parametro existe
    if(!parameter)
        return;

    // -- Asignar referencia de simbolo a este parametro, buscandolo de la tabla
    // -- Se busca el simbolo solo en el scope actual
    parameter->symb = lookup_symbol_from_current_scope(parameter->name_parameter);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    // -- OJO! Aqui queremos que NO se encuentre, si se encuentra tenemos un error de redefinicion
    if(parameter->symb){
        // -- Realizar handling de este error : PARAMETRO REDEFINIDO
        // -- Crear error
        struct error_semantic * error = create_error_semantic_duplicated_symbol(parameter->name_parameter,parameter->line);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_name_resolution_to_list(error);
    }
    // -- En caso de que no se encuentre, realizamos la insercion en la tabla de simbolos
    else{
        // -- Creamos un simbolo de tipo parametro
        parameter->symb = create_symbol_param(parameter->type,parameter->name_parameter,position);

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
    subprog->symb = lookup_symbol_from_all_scopes(subprog->name_subprogram);

    // -- Comprobar existencia de simbolo en la tabla (se manifiesta viendo que la asociacion no es nula)
    if(subprog->symb){
        // -- Realizar handling de este error : SUBPROGRAMA REDEFINIDO
        // -- Crear error
        struct error_semantic * error = create_error_semantic_duplicated_symbol(subprog->name_subprogram,subprog->line);

        // -- Insertar error en la lista de errores semanticos
        add_error_semantic_name_resolution_to_list(error);
    }
    // -- En caso de que no se encuentre, realizamos la insercion en la tabla de simbolos
    else{
        // -- Creamos un simbolo de tipo global
        subprog->symb = create_symbol_global(NULL, subprog->name_subprogram);

        // -- Vincular simbolo al scope actual
        bind_symbol_to_scope(subprog->symb);
    }

    // -- ENTRAR EN UN NUEVO SCOPE
    push_scope_to_symbol_table();

    // -- Aplicar resolucion de nombres de parametros
    resolve_list_parameters(subprog->parameters);

    // -- Aplicar resolucion de nombres a declaraciones
    resolve_list_declarations(subprog->declarations);

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
    resolve_list_declarations(prog->declarations);

    // -- Aplicar resolucion de nombres a lista de subprogramas
    resolve_list_subprograms(prog->subprograms);

    // -- Aplicar resolucion de nombres a lista de procesos
    resolve_list_process(prog->process);

    // -- SALIR DEL SCOPE CREADO
    remove_current_scope_from_symbol_table();
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE ERRORES -----

void add_error_semantic_name_resolution_to_list(struct error_semantic * err){
    // -- Comprobar si hay error
    if(!err)
        return;

    // -- Comprobar si hay algun elemento en la lista
    if(!list_error_name_resolution){
        // -- Si no hay, se asigna como primero
        list_error_name_resolution = err;
    }
    else{
        // -- En caso contrario, busca la cola y se anida
        struct error_semantic *current_error = list_error_name_resolution;
        while(current_error->next){
            current_error = current_error->next;
        }

        // -- Asignar error al final del error actual
        current_error->next = err;
    }

    // -- Incrementar la lista de errores semanticos
    TOTAL_ERROR_NAME_RESOLUTION++;
}

void free_list_error_semantic_name_resolution(){
    // -- Comprobar que la lista de errores es nula
    if(!list_error_name_resolution)
        return;

    // -- Liberar lista de errores
    free_list_error_semantic(list_error_name_resolution);
    list_error_name_resolution = NULL;

    // -- Colocar a 0 el contador de errores
    TOTAL_ERROR_NAME_RESOLUTION = 0;
}

void report_list_error_semantic_name_resolution(){
    print_list_error_semantic(list_error_name_resolution);
}