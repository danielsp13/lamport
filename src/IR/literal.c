/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file literal.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para generacion
 * de codigo intermedio (Literales de IR Lineal)
 */

#include "IR/literal.h"

// ===============================================================

// ----- IMPLEMENIRION DE FUNCIONES DE GESTION DE LITERALES DE IR -----

struct IR_literal * create_IR_literal(IR_literal_t kind){
    // -- Reservar memoria
    struct IR_literal * lit = malloc(sizeof(*lit));

    // -- Comprobar reserva de memoria exitosa
    if(!lit)
        return NULL;

    // -- Asignar tipo de literal
    lit->kind = kind;
    switch (lit->kind)
    {
    case IR_LITERAL_INTEGER:
    {
        lit->kind_str = strdup("integer");
        break;
    }
    case IR_LITERAL_REAL:
    {
        lit->kind_str = strdup("real");
        break;
    }
    case IR_LITERAL_CHAR:
    {
        lit->kind_str = strdup("char");
        break;
    }
    case IR_LITERAL_STRING:
    {
        lit->kind_str = strdup("string");
        break;
    }
    case IR_LITERAL_BOOLEAN:
    {
        lit->kind_str = strdup("boolean");
        break;
    }
    default:
    {
        lit->kind_str = NULL;
        break;
    }
    }
    
    if(!lit->kind_str){
        free(lit);
        return NULL;
    }

    // -- Retornar literal
    return lit;
}

struct IR_literal * create_IR_literal_integer(int value){
    // -- Generar literal
    struct IR_literal * lit = create_IR_literal(IR_LITERAL_INTEGER);

    // -- Comprobar creacion exitosa
    if(!lit)
        return NULL;

    // -- Asignar valor
    lit->value.literal_integer = value;

    // -- Retornar literal
    return lit;
}

struct IR_literal * create_IR_literal_real(float value){
    // -- Generar literal
    struct IR_literal * lit = create_IR_literal(IR_LITERAL_REAL);

    // -- Comprobar creacion exitosa
    if(!lit)
        return NULL;

    // -- Asignar valor
    lit->value.literal_real = value;

    // -- Retornar literal
    return lit;
}

struct IR_literal * create_IR_literal_char(char value){
    // -- Generar literal
    struct IR_literal * lit = create_IR_literal(IR_LITERAL_CHAR);

    // -- Comprobar creacion exitosa
    if(!lit)
        return NULL;

    // -- Asignar valor
    lit->value.literal_char = value;

    // -- Retornar literal
    return lit;
}

struct IR_literal * create_IR_literal_string(char *value){
    // -- Generar literal
    struct IR_literal * lit = create_IR_literal(IR_LITERAL_STRING);

    // -- Comprobar creacion exitosa
    if(!lit)
        return NULL;

    // -- Asignar valor
    lit->value.literal_string = strdup(value);

    // -- Comprobar asignacion exitosa
    if(!lit->value.literal_string){
        free(lit);
        return NULL;
    }

    // -- Retornar literal
    return lit;
}

struct IR_literal * create_IR_literal_boolean(int value){
    // -- Generar literal
    struct IR_literal * lit = create_IR_literal(IR_LITERAL_BOOLEAN);

    // -- Comprobar creacion exitosa
    if(!lit)
        return NULL;

    // -- Asignar valor
    lit->value.literal_boolean = value;

    // -- Retornar literal
    return lit;
}

// ===============================================================

// ----- IMPLEMENIRION DE FUNCIONES DE LIBERACION DE LITERALES DE IR -----

void free_IR_literal(struct IR_literal * lit){
    if(!lit)
        return;
    
    // -- Liberar tipo de literal
    free(lit->kind_str);
    lit->kind_str = NULL;

    // -- Liberar valor, si se requiere
    switch (lit->kind)
    {
    case IR_LITERAL_STRING:
    {
        free(lit->value.literal_string);
        lit->value.literal_string = NULL;
        break;
    }
    
    default:
        break;
    }

    free(lit);
}

// ===============================================================

// ----- IMPLEMENIRION DE FUNCIONES DE IMPRESION DE LITERALES DE IR -----

void print_IR_literal(struct IR_literal * lit){
    if(!lit)
        return;

    // -- Imprimir en diferentes casos
    printf("$");
    switch (lit->kind)
    {
    case IR_LITERAL_INTEGER:
    {
        printf("%d",lit->value.literal_integer);
        break;
    }
    case IR_LITERAL_REAL:
    {
        printf("%f",lit->value.literal_real);
        break;
    }
    case IR_LITERAL_CHAR:
    {
        printf("%c",lit->value.literal_char);
        break;
    }
    case IR_LITERAL_STRING:
    {
        printf("%s",lit->value.literal_string);
        break;
    }
    case IR_LITERAL_BOOLEAN:
    {
        printf("%d",lit->value.literal_boolean);
        break;
    }
    
    default:
        break;
    }
}