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

struct expression * create_expression_non_literal(expression_t kind){
    struct expression *ex = malloc(sizeof(*ex));

    // -- Comprobar reserva de memoria exitosa
    if(!ex)
        return NULL;

    // -- Asignar tipo de expresion (expression_t y str)
    ex->kind = kind;
    switch (ex->kind)
    {
    case EXPR_BINARY:
        ex->kind_str = strdup("binary operation");
        break;
    
    case EXPR_UNARY:
        ex->kind_str = strdup("unary operation");
        break;

    case EXPR_IDENTIFIER:
        ex->kind_str = strdup("identifier");
        break;

    case EXPR_FUNCTION_INV:
        ex->kind_str = strdup("function invocation");
        break;

    case EXPR_GROUPED:
        ex->kind_str = strdup("grouped expression");
        break;
    
    default:
        ex->kind_str = NULL;
        break;
    }

    // -- Comprobar asignacion de tipo de expresion (str) exitosa
    if(!ex->kind_str){
        // -- Liberar memoria reservada para la expresion
        free(ex);
        return NULL;
    }

    // -- Asignar puntero a siguiente expresion (NULL)
    ex->next = NULL;

    // -- Retornar expresion creada
    return ex;
}

struct expression * create_expression_literal(expression_literal_t kind){
    struct expression *ex = malloc(sizeof(*ex));

    // -- Comprobar reserva de memoria exitosa
    if(!ex)
        return NULL;

    // -- Asignar tipo de expresion (expression_t, expression_literal_t y str)
    ex->kind = EXPR_LITERAL;
    ex->expr.expression_literal.kind = kind;
    switch (ex->expr.expression_literal.kind)
    {
    case EXPR_LITERAL_INTEGER:
        ex->kind_str = strdup("literal integer");
        break;
    
    case EXPR_LITERAL_REAL:
        ex->kind_str = strdup("literal real");
        break;

    case EXPR_LITERAL_STRING:
        ex->kind_str = strdup("literal string");
        break;

    case EXPR_LITERAL_CHARACTER:
        ex->kind_str = strdup("literal char");
        break;

    case EXPR_LITERAL_BOOLEAN:
        ex->kind_str = strdup("literal boolean");
        break;

    default:
        ex->kind_str = NULL;
        break;
    }

    // -- Comprobar asignacion de tipo de expresion (str) exitosa
    if(!ex->kind_str){
        // -- Liberar memoria reservada para la expresion
        free(ex);
        return NULL;
    }

    // -- Asignar puntero a siguiente expresion (NULL)
    ex->next = NULL;

    // -- Retornar expresion creada
    return ex;
}

struct expression * create_expression_binary_operation(expression_binary_t kind, char *operator, struct expression *left, struct expression *right, unsigned long line){
    struct expression *ex = create_expression_non_literal(EXPR_BINARY);

    // -- Comprobar reserva de memoria exitosa
    if(!ex)
        return NULL;

    // -- Asignar tipo de operacion binaria
    ex->expr.expression_binary_operation.kind = kind;
    // -- Asignar accion de operacion
    switch (ex->expr.expression_binary_operation.kind)
    {
    case EXPR_ADD:
        ex->expr.expression_binary_operation.action = strdup("sumar");
        break;
    case EXPR_SUB:
        ex->expr.expression_binary_operation.action = strdup("restar");
        break;
    case EXPR_MULT:
        ex->expr.expression_binary_operation.action = strdup("multiplicar");
        break;
    case EXPR_DIV:
        ex->expr.expression_binary_operation.action = strdup("dividir");
        break;
    case EXPR_MOD:
        ex->expr.expression_binary_operation.action = strdup("obtener el modulo de");
        break;
    default:
        ex->expr.expression_binary_operation.action = strdup("comparar");
        break;
    }
    // -- Comprobar asignacion de accion exitoso
    if(!ex->expr.expression_binary_operation.action){
        // -- Liberar memoria reservada para la expresion
        free(ex);
        return NULL;
    }

    // -- Asignar simbolo de operacion binaria
    ex->expr.expression_binary_operation.operator = strdup(operator);
    // -- Comprobar asignacion de simbolo (exitosa)
    if(!ex->expr.expression_binary_operation.operator){
        // -- Liberar memoria reservada para la expresion
        free(ex);
        return NULL;
    }

    // -- Asignar operando izquierdo de la operacion
    ex->expr.expression_binary_operation.left = left;
    // -- Asignar operando derecho de la operacion
    ex->expr.expression_binary_operation.right = right;
    // -- Asignar linea donde se definio la expresion
    ex->expr.expression_binary_operation.line = line;
    
    // -- Retornar expresion creada e inicializada
    return ex;
}

struct expression * create_expression_unary_operation(expression_unary_t kind, char *operator, struct expression *left, unsigned long line){
    struct expression *ex = create_expression_non_literal(EXPR_UNARY);

    // -- Comprobar reserva de memoria exitosa
    if(!ex)
        return NULL;

    // -- Asignar tipo de operacion unaria
    ex->expr.expression_unary_operation.kind = kind;
    // -- Asignar accion de operacion
    switch (ex->expr.expression_unary_operation.kind)
    {
    case EXPR_NEGATIVE:
        ex->expr.expression_unary_operation.action = strdup("cambiar de signo");
        break;
    case EXPR_NOT:
        ex->expr.expression_unary_operation.action = strdup("restar");
        break;
    case EXPR_MULT:
        ex->expr.expression_unary_operation.action = strdup("multiplicar");
        break;
    case EXPR_DIV:
        ex->expr.expression_unary_operation.action = strdup("dividir");
        break;
    case EXPR_MOD:
        ex->expr.expression_unary_operation.action = strdup("obtener el modulo de");
        break;
    default:
        ex->expr.expression_unary_operation.action = strdup("comparar");
        break;
    }
    // -- Comprobar asignacion de accion exitoso
    if(!ex->expr.expression_unary_operation.action){
        // -- Liberar memoria reservada para la expresion
        free(ex);
        return NULL;
    }

    // -- Asignar simbolo de operacion unaria
    ex->expr.expression_unary_operation.operator = strdup(operator);
    if(!ex->expr.expression_unary_operation.operator){
        // -- Liberar memoria reservada para la expresion
        free(ex);
        return NULL;
    }

    // -- Asignar operando izquierdo de la operacion
    ex->expr.expression_unary_operation.left = left;
    // -- Asignar linea donde se definio la expresion
    ex->expr.expression_unary_operation.line = line;

    // -- Retornar expresion creada e inicializada
    return ex;
}

struct expression * create_expression_identifier(char *id, struct expression *index_expr, unsigned long line){
    struct expression *ex = create_expression_non_literal(EXPR_IDENTIFIER);

    // -- Comprobar reserva de memoria exitosa
    if(!ex)
        return NULL;

    // -- Asignar identificador de variable
    ex->expr.expression_identifier.id = strdup(id);
    // -- Comprobar asignacion de identificador exitosa
    if(!ex->expr.expression_identifier.id){
        // -- Liberar memoria reservada para la expresion
        free(ex);
        return NULL;
    }

    // -- Asignar expresion de indice (acceso a array)
    ex->expr.expression_identifier.index_expr = index_expr;

    // -- Asignar linea en la que se produjo el uso del identificador
    ex->expr.expression_identifier.line = line;

    // -- Asignar referencia a simbolo de la tabla de simbolos (NULL)
    ex->expr.expression_identifier.symb = NULL;

    // -- Retornar expresion creada e inicializada
    return ex;
}

struct expression * create_expression_literal_integer(int value){
    struct expression *ex = create_expression_literal(EXPR_LITERAL_INTEGER);

    // -- Comprobar reserva de memoria exitosa
    if(!ex)
        return NULL;

    // -- Asignar valor de literal
    ex->expr.expression_literal.value.integer_literal = value;
    
    // -- Retornar expresion creada e inicializada
    return ex;
}

struct expression * create_expression_literal_real(float value){
    struct expression *ex = create_expression_literal(EXPR_LITERAL_REAL);

    // -- Comprobar reserva de memoria exitosa
    if(!ex)
        return NULL;

    // -- Asignar valor de literal
    ex->expr.expression_literal.value.real_literal = value;
    
    // -- Retornar expresion creada e inicializada
    return ex;
}

struct expression * create_expression_literal_string(char *value){
    struct expression *ex = create_expression_literal(EXPR_LITERAL_STRING);

    // -- Comprobar reserva de memoria exitosa
    if(!ex)
        return NULL;

    // -- Asignar valor de literal
    ex->expr.expression_literal.value.string_literal = strdup(value);
    // -- Comprobar asginacion de literal exitosa
    if(!ex->expr.expression_literal.value.string_literal){
        // -- Liberar memoria reservada para la declaracion
        free(ex);
        return NULL;
    }
    
    // -- Retornar expresion creada e inicializada
    return ex;
}

struct expression * create_expression_literal_char(char value){
    struct expression *ex = create_expression_literal(EXPR_LITERAL_CHARACTER);

    // -- Comprobar reserva de memoria exitosa
    if(!ex)
        return NULL;

    // -- Asignar valor de literal
    ex->expr.expression_literal.value.character_literal = value;
    
    // -- Retornar expresion creada e inicializada
    return ex;
}

struct expression * create_expression_literal_boolean(int value){
    struct expression *ex = create_expression_literal(EXPR_LITERAL_BOOLEAN);

    // -- Comprobar reserva de memoria exitosa
    if(!ex)
        return NULL;

    // -- Asignar valor de literal
    ex->expr.expression_literal.value.boolean_literal = value;
    
    // -- Retornar expresion creada e inicializada
    return ex;
}


struct expression * create_expression_function_invocation(char *function_name, struct expression *arguments_list, unsigned long line){
    struct expression *ex = create_expression_non_literal(EXPR_FUNCTION_INV);

    // -- Comprobar reserva de memoria exitosa
    if(!ex)
        return NULL;

    // -- Asginar nombre de funcion
    ex->expr.expression_function_inv.function_name = strdup(function_name);
    // -- Comprobar asignacion de nombre de funcion exitosa
    if(!ex->expr.expression_function_inv.function_name){
        // -- Liberar memoria reservada para la expresion
        free(ex);
        return NULL;
    }
    // -- Asignar lista de argumentos de la invocacion de funcion
    ex->expr.expression_function_inv.arguments_list = arguments_list;

    // -- Asignar linea en la que se produjo el uso del identificador
    ex->expr.expression_function_inv.line = line;

    // -- Asignar referencia a simbolo de la tabla de simbolos (NULL)
    ex->expr.expression_function_inv.symb = NULL;
    
    // -- Retornar expresion creada e inicializada
    return ex;
}

struct expression * create_expression_grouped(struct expression *grouped_expression){
    struct expression *ex = create_expression_non_literal(EXPR_GROUPED);

    // -- Comprobar reserva de memoria exitosa
    if(!ex)
        return NULL;

    // -- Asignar expresion entre parentesis
    ex->expr.grouped_expression = grouped_expression;
    
    // -- Retornar expresion creada e inicializada
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
        free_expression(&current_expression);
        // -- Nodo actual -> siguiente
        current_expression = next;
    }
}


void free_expression(struct expression **expr){
    // -- Obtener expresion
    struct expression *e = *expr;

    // -- Si NULL, simplemente devolver
    if(!e)
        return;

    // -- Liberar tipo de expresion (str)
    if(e->kind_str){
        free(e->kind_str);
        e->kind_str = NULL;
    }

    switch (e->kind)
    {
    case EXPR_BINARY:
        free(e->expr.expression_binary_operation.operator);
        e->expr.expression_binary_operation.operator = NULL;

        free(e->expr.expression_binary_operation.action);
        e->expr.expression_binary_operation.action = NULL;

        free_expression(&e->expr.expression_binary_operation.left);
        free_expression(&e->expr.expression_binary_operation.right);
        break;

    case EXPR_UNARY:
        free(e->expr.expression_unary_operation.operator);
        e->expr.expression_unary_operation.operator = NULL;

        free(e->expr.expression_unary_operation.action);
        e->expr.expression_unary_operation.action = NULL;

        free_expression(&e->expr.expression_unary_operation.left);
        break;

    case EXPR_IDENTIFIER:
        free(e->expr.expression_identifier.id);
        e->expr.expression_identifier.id = NULL;

        free_list_expressions(e->expr.expression_identifier.index_expr);
        e->expr.expression_identifier.index_expr = NULL;

        e->expr.expression_identifier.symb = NULL;
        break;

    case EXPR_LITERAL:
        switch (e->expr.expression_literal.kind)
        {
        case EXPR_LITERAL_STRING:
            free(e->expr.expression_literal.value.string_literal);
            e->expr.expression_literal.value.string_literal = NULL;
            break;
        
        default:
            break;
        }
        
        break;

    case EXPR_FUNCTION_INV:
        free(e->expr.expression_function_inv.function_name);
        e->expr.expression_function_inv.function_name = NULL;

        free_list_expressions(e->expr.expression_function_inv.arguments_list);
        e->expr.expression_function_inv.arguments_list = NULL;

        e->expr.expression_identifier.symb = NULL;

        break;

    case EXPR_GROUPED:
        free_expression(&e->expr.grouped_expression);
        e->expr.grouped_expression = NULL;

        break;
    }

    // -- Liberar nodo
    free(e);
    // -- Poner puntero a NULL
    *expr = NULL;
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO EXPRESIONES) -----

void print_AST_expressions(struct expression *expressions_list, unsigned int depth){
    // -- Determinar identacion de nodo
    char * IDENT_NODE = build_identation_spaces(depth); 
    // -- Determinar profundidad del siguiente nodo
    const unsigned int NEXT_NODE_DEPTH = depth+2;

    // -- Si NULL, simplemente devolver
    if(!expressions_list){
        printf("%s%s %s\n",IDENT_NODE, IDENT_BLANK_ARROW, NULL_NODE_MSG);

        // -- Liberar memoria utilizada para la identacion
        free(IDENT_NODE); IDENT_NODE = NULL; 

        return;
    }

    struct expression *current_expression = expressions_list;
    while(current_expression){
        // -- Imprimir tipo de expresion
        printf("%s%s> EXPRESION DE TIPO: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, current_expression->kind_str);

        // -- Imprimir expresion
        switch (current_expression->kind)
        {
        case EXPR_BINARY:
            printf("%s%s  SIMBOLO DE OPERACION: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, current_expression->expr.expression_binary_operation.operator);
            printf("%s%s  OPERANDO IZQUIERDO:\n",IDENT_NODE, IDENT_BLANK_ARROW);
            print_AST_expressions(current_expression->expr.expression_binary_operation.left,NEXT_NODE_DEPTH);
            printf("%s%s  OPERANDO DERECHO:\n",IDENT_NODE, IDENT_BLANK_ARROW);
            print_AST_expressions(current_expression->expr.expression_binary_operation.right,NEXT_NODE_DEPTH);
            break;
        
        case EXPR_UNARY:
            printf("%s%s  SIMBOLO DE OPERACION: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, current_expression->expr.expression_unary_operation.operator);
            printf("%s%s  OPERANDO IZQUIERDO:\n",IDENT_NODE, IDENT_BLANK_ARROW);
            print_AST_expressions(current_expression->expr.expression_unary_operation.left,NEXT_NODE_DEPTH);
            break;

        case EXPR_IDENTIFIER:
            printf("%s%s  NOMBRE DE IDENTIFICADOR: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, current_expression->expr.expression_identifier.id);
            if(current_expression->expr.expression_identifier.index_expr){
                printf("%s%s  EXPRESION DE ACCESO A POSICION DE IDENTIFICADOR:\n",IDENT_NODE, IDENT_BLANK_ARROW);
                print_AST_expressions(current_expression->expr.expression_identifier.index_expr,NEXT_NODE_DEPTH);
            }
            break;

        case EXPR_LITERAL:
            printf("%s%s  VALOR DE LITERAL: ",IDENT_NODE, IDENT_BLANK_ARROW);
            switch (current_expression->expr.expression_literal.kind)
            {
            case EXPR_LITERAL_INTEGER:
                printf("[%d]\n",current_expression->expr.expression_literal.value.integer_literal);
                break;
            
            case EXPR_LITERAL_REAL:
                printf("[%f]\n",current_expression->expr.expression_literal.value.real_literal);
                break;
            
            case EXPR_LITERAL_BOOLEAN:
                printf("[%d]\n",current_expression->expr.expression_literal.value.boolean_literal);
                break;

            case EXPR_LITERAL_CHARACTER:
                printf("[%c]\n",current_expression->expr.expression_literal.value.character_literal);
                break;

            case EXPR_LITERAL_STRING:
                printf("[%s]\n",current_expression->expr.expression_literal.value.string_literal);
                break;
            default:
                printf("[%s]\n",UNDEFINED_VALUE_MSG);
            }
            break;

        case EXPR_FUNCTION_INV:
            printf("%s%s  INVOCACION DE FUNCION DE NOMBRE: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, current_expression->expr.expression_function_inv.function_name);
            printf("%s%s  LISTADO DE ARGUMENTOS DE INVOCACION DE FUNCION:\n",IDENT_NODE, IDENT_BLANK_ARROW);
            print_AST_expressions(current_expression->expr.expression_function_inv.arguments_list,NEXT_NODE_DEPTH);
            break;

        case EXPR_GROUPED:
            printf("%s%s  EXPRESION ENTRE ( )\n",IDENT_NODE, IDENT_BLANK_ARROW);
            print_AST_expressions(current_expression->expr.grouped_expression,NEXT_NODE_DEPTH);
            break;
        }

        // Ir a la siguiente expresion
        current_expression = current_expression->next;
    }

    // -- Liberar memoria utilizada para la identacion
    free(IDENT_NODE); IDENT_NODE = NULL;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE NODO (EXPRESIONES) -----

struct expression * copy_expression(struct expression *expr){
    // -- Comprobar que hay expresion
    if(!expr)
        return NULL;

    // -- Definir expresion de copia
    struct expression *expr_copy = malloc(sizeof(*expr_copy));

    // -- Comprobar creacion de expresion exitoso
    if(!expr_copy)
        return NULL;

    // -- Realizar copia en funcion del tipo de expresion
    char *original_operator;
    struct expression *original_left, *original_right;
    char *original_id;
    struct expression *original_index_expr;
    unsigned long original_line;

    // -- Comprobar diferentes casos de expresiones validos
    switch (expr->kind)
    {
    case EXPR_BINARY:
        // -- Obtener atributos de la expresion original
        expression_binary_t original_binary_kind = expr->expr.expression_binary_operation.kind;
        original_operator = expr->expr.expression_binary_operation.operator;
        original_left = expr->expr.expression_binary_operation.left;
        original_right = expr->expr.expression_binary_operation.right;
        original_line = expr->expr.expression_binary_operation.line;

        // -- Realizar copia de expresion
        expr_copy = create_expression_binary_operation(original_binary_kind, original_operator, original_left, original_right,original_line);
        break;

    case EXPR_UNARY:
        // -- Obtener atributos de la expresion original
        expression_unary_t original_unary_kind = expr->expr.expression_unary_operation.kind;
        original_operator = expr->expr.expression_unary_operation.operator;
        original_left = expr->expr.expression_unary_operation.left;
        original_line = expr->expr.expression_unary_operation.line;

        // -- Realizar copia de expresion
        expr_copy = create_expression_unary_operation(original_unary_kind, original_operator, original_left,original_line);
        break;

    case EXPR_IDENTIFIER:
        // -- Obtener atributos de la expresion original
        original_id = expr->expr.expression_identifier.id;
        original_index_expr = expr->expr.expression_identifier.index_expr;
        original_line = expr->expr.expression_identifier.line;

        // -- Realizar copia de expresion
        expr_copy = create_expression_identifier(original_id,original_index_expr,original_line);
        break;

    case EXPR_LITERAL:
        // -- Obtener atributos de la expresion original
        expression_literal_t original_literal_kind = expr->expr.expression_literal.kind;
        switch (original_literal_kind)
        {
        case EXPR_LITERAL_INTEGER:
            int original_integer_value = expr->expr.expression_literal.value.integer_literal;
            expr_copy = create_expression_literal_integer(original_integer_value);
            break;
        case EXPR_LITERAL_REAL:
            float original_float_value = expr->expr.expression_literal.value.real_literal;
            expr_copy = create_expression_literal_real(original_float_value);
            break;
        case EXPR_LITERAL_CHARACTER:
            char original_character_value = expr->expr.expression_literal.value.character_literal;
            expr_copy = create_expression_literal_char(original_character_value);
            break;
        case EXPR_LITERAL_STRING:
            char *original_string_value = expr->expr.expression_literal.value.string_literal;
            expr_copy = create_expression_literal_string(original_string_value);
            break;
        case EXPR_LITERAL_BOOLEAN:
            int original_boolean_value = expr->expr.expression_literal.value.boolean_literal;
            expr_copy = create_expression_literal_boolean(original_boolean_value);
            break;
        default:
            // -- Realizar copia de expresion
            expr_copy = NULL;
            break;
        }
        break;
    
    case EXPR_FUNCTION_INV:
        // -- Obtener atributos de expresion original
        char *original_function_name = expr->expr.expression_function_inv.function_name;
        struct expression *original_list_arguments = expr->expr.expression_function_inv.arguments_list; 
        original_line = expr->expr.expression_function_inv.line;

        struct expression *copy_list_arguments = NULL;
        struct expression *current_original_argument = original_list_arguments;
        while(current_original_argument){
            if(!copy_list_arguments)
                copy_list_arguments = copy_expression(current_original_argument);
            else
                copy_list_arguments->next = copy_expression(current_original_argument);
            
            // -- Ir a siguiente argumento
            current_original_argument = current_original_argument->next;
        }

        // -- Realizar copia de expresion
        expr_copy = create_expression_function_invocation(original_function_name, original_list_arguments, original_line);
        break;

    case EXPR_GROUPED:
        // -- Obtener atributos de expresion original
        struct expression *original_grouped_expr = expr->expr.grouped_expression;

        // -- Realizar copia de expresion
        expr_copy = create_expression_grouped(original_grouped_expr);
        break;
    
    default:
        break;
    }

    // -- Retornar copia de expresion
    return expr_copy;
}