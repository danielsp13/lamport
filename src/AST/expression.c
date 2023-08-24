/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file expression.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO expresiones
 */

#include "AST/expression.h"

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

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO EXPRESIONES) -----

void free_list_expressions(struct expression *expressions_list){
    struct expression *current_expression = expressions_list;
    while(current_expression){
        // -- Seleccionar siguiente en la lista
        struct expression *next = current_expression->next;
        // -- Liberar nodo
        free_expression(current_expression);
        // -- Nodo actual -> siguiente
        current_expression = next;
    }
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