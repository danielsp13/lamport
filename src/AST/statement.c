/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file statement.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO sentencias
 */

#include "AST/statement.h"

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

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO SENTENCIAS) -----

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