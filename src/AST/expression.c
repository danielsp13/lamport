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
    ex->kind_str = strdup("binary operation");
    if(!ex->kind_str){
        free(ex->kind_str);
        return NULL;
    }
    ex->expr.expression_binary_operation.kind = kind;
    ex->expr.expression_binary_operation.operator = strdup(operator);
    if(!ex->expr.expression_binary_operation.operator){
        free(ex->expr.expression_binary_operation.operator);
        return NULL;
    }

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
    ex->kind_str = strdup("unary operation");
    if(!ex->kind_str){
        free(ex->kind_str);
        return NULL;
    }
    ex->expr.expression_unary_operation.kind = kind;
    ex->expr.expression_unary_operation.operator = strdup(operator);
    if(!ex->expr.expression_unary_operation.operator){
        free(ex->expr.expression_unary_operation.operator);
        return NULL;
    }
    ex->expr.expression_unary_operation.left = left;
    ex->next = NULL;

    return ex;
}

struct expression * create_expression_identifier(char *id){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_IDENTIFIER;
    ex->kind_str = strdup("identifier");
    if(!ex->kind_str){
        free(ex->kind_str);
        return NULL;
    }
    ex->expr.expression_identifier.id = strdup(id);
    if(!ex->expr.expression_identifier.id){
        free(ex->expr.expression_identifier.id);
        return NULL;
    }
    ex->next = NULL;

    return ex;
}

struct expression * create_expression_literal_integer(int value){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_LITERAL;
    ex->expr.expression_literal.kind = EXPR_LITERAL_INTEGER;
    ex->kind_str = strdup("literal integer");
    if(!ex->kind_str){
        free(ex->kind_str);
        return NULL;
    }
    ex->expr.expression_literal.value.integer_literal = value;
    ex->next = NULL;
    
    return ex;
}

struct expression * create_expression_literal_real(float value){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_LITERAL;
    ex->expr.expression_literal.kind = EXPR_LITERAL_REAL;
    ex->kind_str = strdup("literal real");
    if(!ex->kind_str){
        free(ex->kind_str);
        return NULL;
    }
    ex->expr.expression_literal.value.real_literal = value;
    ex->next = NULL;
    
    return ex;
}

struct expression * create_expression_literal_string(char *value){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_LITERAL;
    ex->expr.expression_literal.kind = EXPR_LITERAL_STRING;
    ex->kind_str = strdup("literal string");
    if(!ex->kind_str){
        free(ex->kind_str);
        return NULL;
    }
    ex->expr.expression_literal.value.string_literal = strdup(value);
    if(!ex->expr.expression_literal.value.string_literal){
        return NULL;
    }

    ex->next = NULL;
    
    return ex;
}

struct expression * create_expression_literal_char(char value){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_LITERAL;
    ex->expr.expression_literal.kind = EXPR_LITERAL_CHARACTER;
    ex->kind_str = strdup("literal char");
    if(!ex->kind_str){
        free(ex->kind_str);
        return NULL;
    }
    ex->expr.expression_literal.value.character_literal = value;
    ex->next = NULL;
    
    return ex;
}

struct expression * create_expression_literal_boolean(int value){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_LITERAL;
    ex->expr.expression_literal.kind = EXPR_LITERAL_BOOLEAN;
    ex->kind_str = strdup("literal boolean");
    if(!ex->kind_str){
        free(ex->kind_str);
        return NULL;
    }
    ex->expr.expression_literal.value.boolean_literal = value;
    ex->next = NULL;
    
    return ex;
}


struct expression * create_expression_function_invocation(char *function_name, struct parameter_list *parameters){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_FUNCTION_INV;
    ex->kind_str = strdup("function invocation");
    if(!ex->kind_str){
        free(ex->kind_str);
        return NULL;
    }
    ex->expr.expression_function_inv.function_name = strdup(function_name);
    if(!ex->expr.expression_function_inv.function_name){
        free(ex->expr.expression_function_inv.function_name);
        return NULL;
    }
    ex->expr.expression_function_inv.parameters = parameters;
    ex->next = NULL;

    return ex;
}

struct expression * create_expression_grouped(struct expression *grouped_expression){
    struct expression *ex = malloc(sizeof(*ex));

    if(!ex)
        return NULL;

    ex->kind = EXPR_GROUPED;
    ex->kind_str = strdup("grouped expression");
    if(!ex->kind_str){
        free(ex->kind_str);
        return NULL;
    }
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

    if(expr->kind_str)
        free(expr->kind_str);

    // -- Liberar nodo
    free(expr);
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO EXPRESIONES) -----

void print_AST_expressions(struct expression *expressions_list){
    const char *IDENT_ARROW = "------->";
    // -- Si NULL, simplemente devolver
    if(!expressions_list){
        printf(" %s <NONE>\n", IDENT_ARROW);
        return;
    }

    struct expression *current_expression = expressions_list;
    while(current_expression){
        // -- Imprimir tipo de expresion
        printf(" %s EXPRESION DE TIPO [%s]\n", IDENT_ARROW, current_expression->kind_str);

        printf(" %s CONTENIDO DE LA EXPRESION DE TIPO: [%s]\n", IDENT_ARROW, current_expression->kind_str);
        // -- Imprimir expresion
        switch (current_expression->kind)
        {
        case EXPR_BINARY:
            printf(" %s SIMBOLO DE OPERACION: [%s]\n", IDENT_ARROW, current_expression->expr.expression_binary_operation.operator);
            printf(" %s OPERANDO IZQUIERDO: \n", IDENT_ARROW);
            print_AST_expressions(current_expression->expr.expression_binary_operation.left);
            printf(" %s OPERANDO DERECHO: \n", IDENT_ARROW);
            print_AST_expressions(current_expression->expr.expression_binary_operation.right);
            break;
        
        case EXPR_UNARY:
            printf(" %s SIMBOLO DE OPERACION: [%s]\n", IDENT_ARROW, current_expression->expr.expression_unary_operation.operator);
            printf(" %s OPERANDO IZQUIERDO: \n", IDENT_ARROW);
            print_AST_expressions(current_expression->expr.expression_unary_operation.left);
            break;

        case EXPR_IDENTIFIER:
            printf(" %s NOMBRE DE IDENTIFICADOR: [%s]\n", IDENT_ARROW, current_expression->expr.expression_identifier.id);
            break;

        case EXPR_LITERAL:
            switch (current_expression->expr.expression_literal.kind)
            {
            case EXPR_LITERAL_INTEGER:
                printf(" %s VALOR DE LITERAL: [%d] \n", IDENT_ARROW, current_expression->expr.expression_literal.value.integer_literal);
                break;
            
            case EXPR_LITERAL_REAL:
                printf(" %s VALOR DE LITERAL: [%f] \n", IDENT_ARROW, current_expression->expr.expression_literal.value.real_literal);
                break;
            
            case EXPR_LITERAL_BOOLEAN:
                printf(" %s VALOR DE LITERAL: [%d] \n", IDENT_ARROW, current_expression->expr.expression_literal.value.boolean_literal);
                break;

            case EXPR_LITERAL_CHARACTER:
                printf(" %s VALOR DE LITERAL: [%c] \n", IDENT_ARROW, current_expression->expr.expression_literal.value.character_literal);
                break;

            case EXPR_LITERAL_STRING:
                printf(" %s VALOR DE LITERAL: [%s] \n", IDENT_ARROW, current_expression->expr.expression_literal.value.string_literal);
                break;
            }
            break;

        case EXPR_FUNCTION_INV:
            printf(" %s INVOCACION DE FUNCION DE NOMBRE: [%s]\n", IDENT_ARROW, current_expression->expr.expression_function_inv.function_name);
            printf(" %s PARAMETROS DE FUNCION: [%s]\n", IDENT_ARROW, current_expression->expr.expression_function_inv.function_name);
            print_AST_parameters(current_expression->expr.expression_function_inv.parameters);
            break;

        case EXPR_GROUPED:
            printf(" %s EXPRESION ENTRE ( )\n", IDENT_ARROW);
            print_AST_expressions(current_expression->expr.grouped_expression);
            break;
        }

        printf("\n");

        // Ir a la siguiente expresion
        current_expression = current_expression->next;
    }
}