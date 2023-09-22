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
    {
        ex->kind_str = strdup("binary operation");
        break;
    }
    case EXPR_UNARY:
    {
        ex->kind_str = strdup("unary operation");
        break;
    }
    case EXPR_IDENTIFIER:
    {
        ex->kind_str = strdup("identifier");
        break;
    }
    case EXPR_FUNCTION_INV:
    {
        ex->kind_str = strdup("function invocation");
        break;
    }
    case EXPR_GROUPED:
    {
        ex->kind_str = strdup("grouped expression");
        break;
    }
    default:
    {
        ex->kind_str = NULL;
        break;
    }
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
    {
        ex->kind_str = strdup("literal integer");
        break;
    }
    
    case EXPR_LITERAL_REAL:
    {
        ex->kind_str = strdup("literal real");
        break;
    }

    case EXPR_LITERAL_STRING:
    {
        ex->kind_str = strdup("literal string");
        break;
    }

    case EXPR_LITERAL_CHARACTER:
    {
        ex->kind_str = strdup("literal char");
        break;
    }

    case EXPR_LITERAL_BOOLEAN:
    {
        ex->kind_str = strdup("literal boolean");
        break;
    }

    default:
    {
        ex->kind_str = NULL;
        break;
    }
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
    {
        ex->expr.expression_binary_operation.action = strdup("sumar");
        break;
    }
    case EXPR_SUB:
    {
        ex->expr.expression_binary_operation.action = strdup("restar");
        break;
    }
    case EXPR_MULT:
    {
        ex->expr.expression_binary_operation.action = strdup("multiplicar");
        break;
    }
    case EXPR_DIV:
    {
        ex->expr.expression_binary_operation.action = strdup("dividir");
        break;
    }
    case EXPR_MOD:
    {
        ex->expr.expression_binary_operation.action = strdup("obtener el modulo de");
        break;
    }
    default:
    {
        ex->expr.expression_binary_operation.action = strdup("comparar");
        break;
    }
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
    {
        ex->expr.expression_unary_operation.action = strdup("cambiar de signo");
        break;
    }
    case EXPR_NOT:
    {
        ex->expr.expression_unary_operation.action = strdup("negacion logica");
        break;
    }
    default:
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
        free_expression(current_expression);
        // -- Nodo actual -> siguiente
        current_expression = next;
    }
}


void free_expression(struct expression *expr){
    // -- Si NULL, simplemente devolver
    if(!expr)
        return;

    // -- Liberar tipo de expresion (str)
    if(expr->kind_str){
        free(expr->kind_str);
        expr->kind_str = NULL;
    }

    switch (expr->kind)
    {
    case EXPR_BINARY:
    {
        free(expr->expr.expression_binary_operation.operator);
        expr->expr.expression_binary_operation.operator = NULL;

        free(expr->expr.expression_binary_operation.action);
        expr->expr.expression_binary_operation.action = NULL;

        free_expression(expr->expr.expression_binary_operation.left);
        expr->expr.expression_binary_operation.left = NULL;
        free_expression(expr->expr.expression_binary_operation.right);
        expr->expr.expression_binary_operation.right = NULL;
        break;
    }

    case EXPR_UNARY:
    {
        free(expr->expr.expression_unary_operation.operator);
        expr->expr.expression_unary_operation.operator = NULL;

        free(expr->expr.expression_unary_operation.action);
        expr->expr.expression_unary_operation.action = NULL;

        free_expression(expr->expr.expression_unary_operation.left);
        expr->expr.expression_unary_operation.left = NULL;
        break;
    }

    case EXPR_IDENTIFIER:
    {
        free(expr->expr.expression_identifier.id);
        expr->expr.expression_identifier.id = NULL;

        free_list_expressions(expr->expr.expression_identifier.index_expr);
        expr->expr.expression_identifier.index_expr = NULL;

        expr->expr.expression_identifier.symb = NULL;
        break;
    }

    case EXPR_LITERAL:
    {
        switch (expr->expr.expression_literal.kind)
        {
        case EXPR_LITERAL_STRING:
        {
            free(expr->expr.expression_literal.value.string_literal);
            expr->expr.expression_literal.value.string_literal = NULL;
            break;
        }
        
        default:
            break;
        }
        
        break;
    }

    case EXPR_FUNCTION_INV:
    {
        free(expr->expr.expression_function_inv.function_name);
        expr->expr.expression_function_inv.function_name = NULL;

        free_list_expressions(expr->expr.expression_function_inv.arguments_list);
        expr->expr.expression_function_inv.arguments_list = NULL;

        free_symbol(expr->expr.expression_function_inv.symb );
        expr->expr.expression_function_inv.symb = NULL;

        break;
    }

    case EXPR_GROUPED:
    {
        free_expression(expr->expr.grouped_expression);
        expr->expr.grouped_expression = NULL;

        break;
    }
    }

    // -- Liberar nodo
    free(expr);
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO EXPRESIONES) -----

void print_AST_expressions(struct expression *expressions_list, unsigned int depth, FILE * output){
    // -- Determinar identacion de nodo
    char * IDENT_NODE = build_identation_spaces(depth); 
    // -- Determinar profundidad del siguiente nodo
    const unsigned int NEXT_NODE_DEPTH = depth+2;

    // -- Si NULL, simplemente devolver
    if(!expressions_list){
        fprintf(output,"%s%s %s\n",IDENT_NODE, IDENT_BLANK_ARROW, NULL_NODE_MSG);

        // -- Liberar memoria utilizada para la identacion
        free(IDENT_NODE); IDENT_NODE = NULL; 

        return;
    }

    struct expression *current_expression = expressions_list;
    while(current_expression){
        // -- Imprimir tipo de expresion
        fprintf(output,"%s%s> EXPRESION DE TIPO: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, current_expression->kind_str);

        // -- Imprimir expresion
        switch (current_expression->kind)
        {
        case EXPR_BINARY:
        {
            fprintf(output,"%s%s  SIMBOLO DE OPERACION: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, current_expression->expr.expression_binary_operation.operator);
            fprintf(output,"%s%s  OPERANDO IZQUIERDO:\n",IDENT_NODE, IDENT_BLANK_ARROW);
            print_AST_expressions(current_expression->expr.expression_binary_operation.left,NEXT_NODE_DEPTH,output);
            fprintf(output,"%s%s  OPERANDO DERECHO:\n",IDENT_NODE, IDENT_BLANK_ARROW);
            print_AST_expressions(current_expression->expr.expression_binary_operation.right,NEXT_NODE_DEPTH,output);
            break;
        }
        
        case EXPR_UNARY:
        {
            fprintf(output,"%s%s  SIMBOLO DE OPERACION: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, current_expression->expr.expression_unary_operation.operator);
            fprintf(output,"%s%s  OPERANDO IZQUIERDO:\n",IDENT_NODE, IDENT_BLANK_ARROW);
            print_AST_expressions(current_expression->expr.expression_unary_operation.left,NEXT_NODE_DEPTH,output);
            break;
        }

        case EXPR_IDENTIFIER:
        {
            fprintf(output,"%s%s  NOMBRE DE IDENTIFICADOR: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, current_expression->expr.expression_identifier.id);
            if(current_expression->expr.expression_identifier.index_expr){
                fprintf(output,"%s%s  EXPRESION DE ACCESO A POSICION DE IDENTIFICADOR:\n",IDENT_NODE, IDENT_BLANK_ARROW);
                print_AST_expressions(current_expression->expr.expression_identifier.index_expr,NEXT_NODE_DEPTH,output);
            }
            break;
        }

        case EXPR_LITERAL:
        {
            fprintf(output,"%s%s  VALOR DE LITERAL: ",IDENT_NODE, IDENT_BLANK_ARROW);
            switch (current_expression->expr.expression_literal.kind)
            {
            case EXPR_LITERAL_INTEGER:
            {
                fprintf(output,"[%d]\n",current_expression->expr.expression_literal.value.integer_literal);
                break;
            }
            
            case EXPR_LITERAL_REAL:
            {
                fprintf(output,"[%f]\n",current_expression->expr.expression_literal.value.real_literal);
                break;
            }
            
            case EXPR_LITERAL_BOOLEAN:
            {
                fprintf(output,"[%d]\n",current_expression->expr.expression_literal.value.boolean_literal);
                break;
            }

            case EXPR_LITERAL_CHARACTER:
            {
                fprintf(output,"[%c]\n",current_expression->expr.expression_literal.value.character_literal);
                break;
            }

            case EXPR_LITERAL_STRING:
            {
                fprintf(output,"[%s]\n",current_expression->expr.expression_literal.value.string_literal);
                break;
            }
            default:
            {
                fprintf(output,"[%s]\n",UNDEFINED_VALUE_MSG);
            }
            }
            break;
        }

        case EXPR_FUNCTION_INV:
        {
            fprintf(output,"%s%s  INVOCACION DE FUNCION DE NOMBRE: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, current_expression->expr.expression_function_inv.function_name);
            fprintf(output,"%s%s  LISTADO DE ARGUMENTOS DE INVOCACION DE FUNCION:\n",IDENT_NODE, IDENT_BLANK_ARROW);
            print_AST_expressions(current_expression->expr.expression_function_inv.arguments_list,NEXT_NODE_DEPTH,output);
            break;
        }

        case EXPR_GROUPED:
        {
            fprintf(output,"%s%s  EXPRESION ENTRE ( )\n",IDENT_NODE, IDENT_BLANK_ARROW);
            print_AST_expressions(current_expression->expr.grouped_expression,NEXT_NODE_DEPTH,output);
            break;
        }
        }

        // Ir a la siguiente expresion
        current_expression = current_expression->next;
    }

    // -- Liberar memoria utilizada para la identacion
    free(IDENT_NODE); IDENT_NODE = NULL;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE NODO (EXPRESIONES) -----

struct expression * copy_list_expressions(struct expression *list_expressions){
    struct expression *copy_list_expr = NULL;
    struct expression *copy_last_expr = NULL;

    struct expression *current_expr = list_expressions;
    while(current_expr){
        if(!copy_list_expr){
            copy_list_expr = copy_expression(current_expr);
            copy_last_expr = copy_list_expr;
        }
        else{
            copy_last_expr->next = copy_expression(current_expr);
            copy_last_expr = copy_last_expr->next;
        }

        current_expr = current_expr->next;
    }

    return copy_list_expr;
}

struct expression * copy_expression(struct expression *expr){
    // -- Comprobar que hay expresion
    if(!expr)
        return NULL;

    // -- Definir expresion de copia
    struct expression *expr_copy = NULL;

    // -- Comprobar diferentes casos de expresiones validos
    switch (expr->kind)
    {
    case EXPR_BINARY:
    {
        // -- Realizar copia de expresion
        expr_copy = copy_expression_binary(expr);
        break;
    }

    case EXPR_UNARY:
    {
        // -- Realizar copia de expresion
        expr_copy = copy_expression_unary(expr);
        break;
    }

    case EXPR_IDENTIFIER:
    {
        // -- Realizar copia de expresion
        expr_copy = copy_expression_identifier(expr);
        break;
    }

    case EXPR_LITERAL:
    {
        // -- Realizar copia de expresion
        expr_copy = copy_expression_literal(expr);
        break;
    }
    
    case EXPR_FUNCTION_INV:
    {
        // -- Realizar copia de expresion
        expr_copy = copy_expression_function_inv(expr);
        break;
    }

    case EXPR_GROUPED:
    {
        // -- Realizar copia de expresion
        expr_copy = copy_expression_grouped(expr);
        break;
    }
    
    default:
        break;
    }

    // -- Retornar copia de expresion
    return expr_copy;
}

struct expression * copy_expression_binary(struct expression *expr){
    if(!expr)
        return NULL;

    // -- Obtener atributos de la expresion original
    expression_binary_t copy_binary_kind = expr->expr.expression_binary_operation.kind;
    char *copy_operator = expr->expr.expression_binary_operation.operator;
    struct expression * copy_left = copy_expression(expr->expr.expression_binary_operation.left);
    struct expression * copy_right = copy_expression(expr->expr.expression_binary_operation.right);
    unsigned long copy_line = expr->expr.expression_binary_operation.line;

    // -- Retornar copia
    return create_expression_binary_operation(copy_binary_kind,copy_operator,copy_left,copy_right,copy_line);
}

struct expression * copy_expression_unary(struct expression *expr){
    if(!expr)
        return NULL;

    // -- Obtener atributos de la expresion original
    expression_unary_t copy_unary_kind = expr->expr.expression_unary_operation.kind;
    char * copy_operator = expr->expr.expression_unary_operation.operator;
    struct expression *copy_left = copy_expression(expr->expr.expression_unary_operation.left);
    unsigned long copy_line = expr->expr.expression_unary_operation.line;

    // -- Retornar copia
    return create_expression_unary_operation(copy_unary_kind,copy_operator,copy_left,copy_line);
}

struct expression * copy_expression_identifier(struct expression *expr){
    if(!expr)
        return NULL;

    // -- Obtener atributos de la expresion original
    char *copy_id = expr->expr.expression_identifier.id;
    struct expression *copy_index_expr = copy_expression(expr->expr.expression_identifier.index_expr);
    unsigned long copy_line = expr->expr.expression_identifier.line;

    // -- Retornar copia
    return create_expression_identifier(copy_id,copy_index_expr,copy_line);
}

struct expression * copy_expression_literal(struct expression *expr){
    if(!expr)
        return NULL;

    // -- Obtener atributos de la expresion original
    expression_literal_t copy_literal_kind = expr->expr.expression_literal.kind;
    switch (copy_literal_kind)
    {
    case EXPR_LITERAL_INTEGER:
    {
        int copy_integer_value = expr->expr.expression_literal.value.integer_literal;
        return create_expression_literal_integer(copy_integer_value);
        break;
    }
    case EXPR_LITERAL_REAL:
    {
        float copy_float_value = expr->expr.expression_literal.value.real_literal;
        return create_expression_literal_real(copy_float_value);
        break;
    }
    case EXPR_LITERAL_CHARACTER:
    {
        char copy_character_value = expr->expr.expression_literal.value.character_literal;
        return create_expression_literal_char(copy_character_value);
        break;
    }
    case EXPR_LITERAL_STRING:
    {
        char *copy_string_value = expr->expr.expression_literal.value.string_literal;
        return create_expression_literal_string(copy_string_value);
        break;
    }
    case EXPR_LITERAL_BOOLEAN:
    {
        int copy_boolean_value = expr->expr.expression_literal.value.boolean_literal;
        return create_expression_literal_boolean(copy_boolean_value);
        break;
    }
    default:
    {
        return NULL;
        break;
    }
    }
}

struct expression * copy_expression_function_inv(struct expression *expr){
    if(!expr)
        return NULL;

    // -- Obtener atributos de expresion original
    char *copy_function_name = expr->expr.expression_function_inv.function_name;
    struct expression *copy_list_arguments = copy_list_expressions(expr->expr.expression_function_inv.arguments_list);
    unsigned long copy_line = expr->expr.expression_function_inv.line;

    return create_expression_function_invocation(copy_function_name,copy_list_arguments,copy_line);
}

struct expression * copy_expression_grouped(struct expression *expr){
    if(!expr)
        return NULL;

    // -- Obtener atributos de expresion original
    struct expression *copy_grouped_expr = copy_expression(expr->expr.grouped_expression);

    // -- Retornar copia
    return create_expression_grouped(copy_grouped_expr);
}