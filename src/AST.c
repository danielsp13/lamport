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

struct declaration * create_declaration(char *name, struct type *type, struct statement *code){
    struct declaration *d = malloc(sizeof(*d));

    if(!d)
        return NULL;

    d->name = name;
    d->type = type;
    d->code = code; 
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

struct expression * create_expression_unary_operator(expression_unary_t kind, char *operator, struct expression *left){
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
    ex->expr.id = id;
    ex->next = NULL;

    return ex;
}

struct expression * create_expression_literal(expression_literal_t kind, void *value){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_LITERAL;
    ex->next = NULL;
    switch (kind)
    {
    case EXPR_LITERAL_INTEGER:
        ex->expr.expression_literal.kind = EXPR_LITERAL_INTEGER;
        ex->expr.expression_literal.value.integer_literal = (intptr_t) value;
        break;

    case EXPR_LITERAL_REAL:
        ex->expr.expression_literal.kind = EXPR_LITERAL_REAL;
        ex->expr.expression_literal.value.real_literal = *((float *) value);
        break;

    case EXPR_LITERAL_BOOLEAN:
        ex->expr.expression_literal.kind = EXPR_LITERAL_BOOLEAN;
        ex->expr.expression_literal.value.boolean_literal = *((bool *) value);
        break;

    case EXPR_LITERAL_CHARACTER:
        ex->expr.expression_literal.kind = EXPR_LITERAL_CHARACTER;
        ex->expr.expression_literal.value.character_literal = *((char *) value);
        break;

    case EXPR_LITERAL:
        ex->expr.expression_literal.kind = EXPR_LITERAL;
        ex->expr.expression_literal.value.string_literal = (char *) value;
        break;
    
    default:
        ex->expr.expression_literal.kind = EXPR_LITERAL;
        ex->expr.expression_literal.value.string_literal = (char *) value;
        break;
    }

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