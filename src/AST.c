/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file AST.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles)
 */

#include "AST.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (DECLARACIONES) -----

struct declaration * create_declaration_variable(char *name, struct type *type, struct expression *value){
    struct declaration *d = malloc(sizeof(*d));

    if(!d)
        return NULL;

    d->name = name;
    d->type = type;
    d->value = value; 
    d->next = NULL;

    return d;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (SENTENCIAS) -----

struct statement * create_statement_assignment(char *variable_name, struct expression *expr){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_ASSIGNMENT;
    st->stmt.statement_assignment.variable_name = variable_name;
    st->stmt.statement_assignment.expr = expr;
    st->next = NULL;

    return st;
}

struct statement * create_statement_while(struct expression *condition, struct statement *body){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_WHILE;
    st->stmt.statement_while.condition = condition;
    st->stmt.statement_while.body = body;
    st->next = NULL;

    return st;
}

struct statement * create_statement_for(struct expression *initialization, struct expression *condition, struct expression *increment, struct statement *body){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_FOR;
    st->stmt.statement_for.intialization = initialization;
    st->stmt.statement_for.condition = condition;
    st->stmt.statement_for.increment = increment;
    st->stmt.statement_for.body = body;
    st->next = NULL;

    return st;
}

struct statement * create_statement_if_else(struct expression *condition, struct statement *if_body, struct statement *else_body){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_IF_ELSE;
    st->stmt.statement_if_else.condition = condition;
    st->stmt.statement_if_else.if_body = if_body;
    st->stmt.statement_if_else.else_body = else_body;
    st->next = NULL;

    return st; 
}

struct statement * create_statement_procedure_inv(char *procedure_name, struct parameter_list *parameters){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_PROCEDURE_INV;
    st->stmt.statement_procedure_inv.procedure_name = procedure_name;
    st->stmt.statement_procedure_inv.parameters = parameters;
    st->next = NULL;

    return st; 
}

struct statement * create_block_of_statements(statement_t block_type, struct statement *body){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = block_type;
    st->stmt.statement_block.body = body;
    st->next = NULL;

    return st; 
}

struct statement * create_statement_block_begin(struct statement *body){
    return create_block_of_statements(STMT_BLOCK_BEGIN, body);
}

struct statement * create_statement_block_cobegin(struct statement *body){
    return create_block_of_statements(STMT_BLOCK_COBEGIN, body);
}

struct statement * create_statement_atomic(struct statement *body){
    return create_block_of_statements(STMT_ATOMIC, body);
}

struct statement * create_statement_fork(char *process_name, struct statement *stmt){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_FORK;
    st->stmt.statement_fork.forked_process = process_name;
    st->stmt.statement_fork.stmt = stmt;
    st->next = NULL;

    return st; 
}

struct statement * create_statement_return(struct expression *returned_expr){
    struct statement *st = malloc(sizeof(*st));

    if(!st)
        return NULL;

    st->kind = STMT_RETURN;
    st->stmt.statement_return.returned_expr = returned_expr;
    st->next = NULL;

    return st; 
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (EXPRESIONES) -----

struct expression * create_expression_binary_operation(expression_binary_t kind, char *operator, struct expression *left, struct expression *right){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_BINARY;
    ex->expr.expression_binary_operation.kind = kind;
    ex->expr.expression_binary_operation.operator = operator;
    ex->expr.expression_binary_operation.left = left;
    ex->expr.expression_binary_operation.right = right;
    ex->next = NULL;
    
    return ex;
}

struct expression * create_expression_unary_operation(expression_unary_t kind, char *operator, struct expression *left){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_UNARY;
    ex->expr.expression_unary_operation.kind = kind;
    ex->expr.expression_unary_operation.operator = operator;
    ex->expr.expression_unary_operation.left = left;
    ex->next = NULL;

    return ex;
}

struct expression * create_expression_identifier(char *id){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_IDENTIFIER;
    ex->expr.expression_identifier.id = id;
    ex->next = NULL;

    return ex;
}

struct expression * create_expression_literal_integer(int value){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->expr.expression_literal.kind = EXPR_LITERAL_INTEGER;
    ex->expr.expression_literal.value.integer_literal = value;
    
    return ex;
}

struct expression * create_expression_literal_real(float value){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->expr.expression_literal.kind = EXPR_LITERAL_REAL;
    ex->expr.expression_literal.value.real_literal = value;
    
    return ex;
}

struct expression * create_expression_literal_string(char *value){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->expr.expression_literal.kind = EXPR_LITERAL_STRING;
    ex->expr.expression_literal.value.string_literal = value;
    
    return ex;
}

struct expression * create_expression_literal_char(char value){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->expr.expression_literal.kind = EXPR_LITERAL_CHARACTER;
    ex->expr.expression_literal.value.character_literal = value;
    
    return ex;
}

struct expression * create_expression_literal_boolean(int value){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->expr.expression_literal.kind = EXPR_LITERAL_BOOLEAN;
    ex->expr.expression_literal.value.boolean_literal = value;
    
    return ex;
}


struct expression * create_expression_function_invocation(char *function_name, struct parameter_list *parameters){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_FUNCTION_INV;
    ex->expr.expression_function_inv.function_name = function_name;
    ex->expr.expression_function_inv.parameters = parameters;
    ex->next = NULL;

    return ex;
}

struct expression * create_expression_grouped(struct expression *grouped_expression){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_GROUPED;
    ex->expr.grouped_expression = grouped_expression;
    ex->next = NULL;

    return ex;  
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (TIPOS) -----

struct type * create_basic_type(type_t kind){
    struct type *t = malloc(sizeof(*t));

    if(!t)
        return NULL;

    t->kind = kind;
    t->subtype = NULL;
    t->parameters = NULL;

    return t;
}

struct type * create_function_type(struct type *subtype, struct parameter_list *parameters){
    struct type *t = malloc(sizeof(*t));

    if(!t)
        return NULL;

    t->kind = TYPE_FUNCTION;
    t->subtype = subtype;
    t->parameters = parameters;

    return t;
}

struct type * create_array_type(struct type *subtype){
    struct type *t = malloc(sizeof(*t));

    if(!t)
        return NULL;

    t->kind = TYPE_ARRAY;
    t->subtype = subtype;
    t->parameters = NULL;

    return t;
}

struct type * create_semaphore_type(){
    struct type *t = malloc(sizeof(*t));

    if(!t)
        return NULL;

    t->kind = TYPE_SEMAPHORE;
    t->subtype = NULL;
    t->parameters = NULL;

    return t;
}

struct type * create_dprocess_type(){
    struct type *t = malloc(sizeof(*t));

    if(!t)
        return NULL;

    t->kind = TYPE_DPROCESS;
    t->subtype = NULL;
    t->parameters = NULL;

    return t;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (PARAMETROS) -----

struct parameter_list * create_parameter_list(char * name_parameter, struct type * type){
    struct parameter_list *pl = malloc(sizeof(*pl));

    if(!pl)
        return NULL;

    pl->name_parameter = name_parameter;
    pl->type = type;
    pl->next = NULL;

    return pl;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (SUBPROGRAMAS Y PROCESOS) -----

struct subprogram * create_subprogram(subprogram_t kind, char *name_subprogram, struct parameter_list *parameters, struct declaration *declarations, struct statement *statements, struct type *type){
    struct subprogram *subprog = malloc(sizeof(*subprog));

    if(!subprog)
        return NULL;

    subprog->kind = kind;
    subprog->name_subprogram = name_subprogram;
    subprog->parameters = parameters;
    subprog->declarations = declarations;
    subprog->statements = statements;
    subprog->type = type;
    subprog->next = NULL;

    return subprog;
}

struct subprogram * create_subprogram_procedure(char *name_procedure, struct parameter_list *parameters, struct declaration *declarations, struct statement *statements){
    return create_subprogram(SUBPROGRAM_PROCEDURE, name_procedure, parameters, declarations, statements, NULL);
}

struct subprogram * create_subprogram_function(char *name_function, struct parameter_list *parameters, struct declaration *declarations, struct statement *statements, struct type *type){
    return create_subprogram(SUBPROGRAM_FUNCTION, name_function, parameters, declarations, statements, type);   
}

struct process * create_process(char *name_process, struct declaration *declarations, struct statement *statements){
    struct process *proc = malloc(sizeof(*proc));

    if(!proc)
        return NULL;

    proc->name_process = name_process;
    proc->declarations = declarations;
    proc->statements = statements;
    proc->next = NULL;

    return proc;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (PROGRAMAS) -----

struct program * create_program(char *name_program, struct declaration *declarations, struct subprogram *subprograms, struct process *process){
    struct program *prog = malloc(sizeof(*prog));

    if(!prog)
        return NULL;

    prog->name_program = name_program;
    prog->declarations = declarations;
    prog->subprograms = subprograms;
    prog->process = process;

    return prog;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST -----

void free_program(struct program *prog){
    // -- Si NULL, simplemente devolver
    if(!prog)
        return;

    // -- Liberacion del nombre del programa
    if(prog->name_program)
        free(prog->name_program);

    // -- Liberacion de declaraciones
    if(prog->declarations)
        free_list_declarations(prog->declarations);

    // -- Liberacion de subprogramas
    if(prog->subprograms)
        free_list_subprograms(prog->subprograms);

    // -- Liberacion de procesos
    if(prog->process)
        free_list_process(prog->process);

    // -- Liberar nodo raiz programa
    free(prog);
}

void free_list_declarations(struct declaration *declarations_list){
    struct declaration *current_declaration = declarations_list;
    while(current_declaration){
        // -- Seleccionar siguiente en la lista
        struct declaration *next = current_declaration->next;
        // -- Liberar nodo
        free_declaration(current_declaration);
        // -- Nodo actual -> siguiente
        current_declaration = next;
    }
}

void free_list_subprograms(struct subprogram *subprograms_list){
    struct subprogram *current_subprogram = subprograms_list;
    while(current_subprogram){
        // -- Seleccionar siguiente en la lista
        struct subprogram *next = current_subprogram->next;
        // -- Liberar nodo
        free_subprogram(current_subprogram);
        // -- Nodo actual -> siguiente
        current_subprogram = next;
    }
}

void free_list_process(struct process *process_list){
    struct process *current_process = process_list;
    while(current_process){
        // -- Seleccionar siguiente en la lista
        struct process *next = current_process->next;
        // -- Liberar nodo
        free_process(current_process);
        // -- Nodo actual -> siguiente
        current_process = next;
    }
}

void free_list_statements(struct statement *statements_list){
    struct statement *current_statement = statements_list;
    while(current_statement){
        // -- Seleccionar siguiente en la lista
        struct statement *next = current_statement->next;
        // -- Liberar nodo
        free_statement(current_statement);
        // -- Nodo actual -> siguiente
        current_statement = next;
    }
}

void free_list_parameters(struct parameter_list *parameter_list){
    struct parameter_list *current_parameter_list = parameter_list;
    while(current_parameter_list){
        // -- Seleccionar siguiente en la lista
        struct parameter_list *next = current_parameter_list->next;
        // -- Liberar nodo
        free_parameter(current_parameter_list);
        // -- Nodo actual -> siguiente
        current_parameter_list = next;
    }
}

void free_subprogram(struct subprogram *subprog){
    // -- Si NULL, simplemente devolver
    if(!subprog)
        return;

    // -- Liberar nombre de subprograma
    if(subprog->name_subprogram)
        free(subprog->name_subprogram);

    // -- Liberar tipo de subprograma (solo para funciones)
    if(subprog->type)
        free_type(subprog->type);

    // -- Liberar declaraciones del subprograma
    if(subprog->declarations)
        free_list_declarations(subprog->declarations);

    // -- Liberar
    if(subprog->parameters)
        free_list_parameters(subprog->parameters);

    // -- Liberar
    if(subprog->statements)
        free_list_statements(subprog->statements);

    
    // -- Liberar nodo
    free(subprog);
}

void free_process(struct process *proc){
    // -- Si NULL, simplemente devolver
    if(!proc)
        return;

    // -- Liberar nombre de proceso
    if(proc->name_process)
        free(proc->name_process);

    // -- Liberar declaraciones de proceso
    if(proc->declarations)
        free_list_declarations(proc->declarations);

    // -- Liberar sentencias de proceso
    if(proc->statements){
        free_list_statements(proc->statements);
    }

    // -- Liberar nodo
    free(proc);
}

void free_declaration(struct declaration *decl){
    // -- Si NULL, simplemente devolver
    if(!decl)
        return;

    // -- Liberar nombre de variable
    if(decl->name)
        free(decl->name);

    // -- Liberar tipo de declaracion
    if(decl->type)
        free_type(decl->type);

    // -- Liberar expresion de valor
    if(decl->value)
        free_expression(decl->value);

    // -- Liberar nodo
    free(decl);
}

void free_statement(struct statement *stmt){
    // -- Si NULL, simplemente devolver
    if(!stmt)
        return;

    // -- Liberar en funcion del tipo de sentencia
    switch (stmt->kind)
    {
    case STMT_ASSIGNMENT:
        free(stmt->stmt.statement_assignment.variable_name);
        free_expression(stmt->stmt.statement_assignment.expr);
        break;

    case STMT_WHILE:
        free_expression(stmt->stmt.statement_while.condition);
        free_list_statements(stmt->stmt.statement_while.body);
        break;

    case STMT_FOR:
        free_expression(stmt->stmt.statement_for.intialization);
        free_expression(stmt->stmt.statement_for.condition);
        free_expression(stmt->stmt.statement_for.increment);
        free_list_statements(stmt->stmt.statement_for.body);
        break;

    case STMT_IF_ELSE:
        free_expression(stmt->stmt.statement_if_else.condition);
        free_list_statements(stmt->stmt.statement_if_else.if_body);
        if(stmt->stmt.statement_if_else.else_body)
            free_list_statements(stmt->stmt.statement_if_else.else_body);
        break;

    case STMT_PROCEDURE_INV:
        free(stmt->stmt.statement_procedure_inv.procedure_name);
        if(stmt->stmt.statement_procedure_inv.parameters)
            free_list_parameters(stmt->stmt.statement_procedure_inv.parameters);
        break;

    case STMT_BLOCK_BEGIN:
        free_list_statements(stmt->stmt.statement_block.body);
        break;

    case STMT_BLOCK_COBEGIN:
        free_list_statements(stmt->stmt.statement_block.body);
        break;

    case STMT_FORK:
        free(stmt->stmt.statement_fork.forked_process);
        free_list_statements(stmt->stmt.statement_fork.stmt);
        break;

    case STMT_ATOMIC:
        free_list_statements(stmt->stmt.statement_block.body);
        break;

    case STMT_RETURN:
        free_expression(stmt->stmt.statement_return.returned_expr);
        break;
    }
    
    // -- Liberar nodo
    free(stmt);
}

void free_expression(struct expression *expr){
    // -- Si NULL, simplemente devolver
    if(!expr)
        return;

    switch (expr->kind)
    {
    case EXPR_BINARY:
        free(expr->expr.expression_binary_operation.operator);
        free_expression(expr->expr.expression_binary_operation.left);
        free_expression(expr->expr.expression_binary_operation.right);
        break;

    case EXPR_UNARY:
        free(expr->expr.expression_unary_operation.operator);
        free_expression(expr->expr.expression_unary_operation.left);
        break;

    case EXPR_IDENTIFIER:
        free(expr->expr.expression_identifier.id);
        break;

    case EXPR_LITERAL:
        switch (expr->expr.expression_literal.kind)
        {
        case EXPR_LITERAL_STRING:
            free(expr->expr.expression_literal.value.string_literal);
            break;
        
        default:
            break;
        }
        break;

    case EXPR_FUNCTION_INV:
        free(expr->expr.expression_function_inv.function_name);
        free_list_parameters(expr->expr.expression_function_inv.parameters);
        break;

    case EXPR_GROUPED:
        free_expression(expr->expr.grouped_expression);
        break;
    }

    // -- Liberar nodo
    free(expr);
}

void free_type(struct type *type){
    // -- Si NULL, simplemente devolver
    if(!type)
        return;

    // -- Liberar en funcion del tipo
    switch (type->kind)
    {
    case TYPE_ARRAY:
        free_type(type->subtype);
        break;

    case TYPE_FUNCTION:
        free_type(type->subtype);
        free_list_parameters(type->parameters);
        break;

    default:
        break;
    }

    // -- Liberar nodo
    free(type);
}

void free_parameter(struct parameter_list *parameter){
    // -- Si NULL, simplemente devolver
    if(!parameter)
        return;

    // -- Liberar nombre de parametro
    if(parameter->name_parameter)
        free(parameter->name_parameter);

    // -- Liberar tipo de parametro
    if(parameter->type)
        free_type(parameter->type);


    // -- Liberar nodo
    free(parameter);
}