/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file operand.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para generacion
 * de codigo intermedio (Operando de IR Lineal)
 */

#include "IR/operand.h"

// ===============================================================

// ----- DEFINICION DE VARIABLES GLOBALES -----

// Variable para definir ID de operandos temporales (contador)
unsigned long CURRENT_REG_ID = 0;

// ===============================================================

// ----- IMPLEMENIRION DE FUNCIONES DE ASISTENCIA A GESTION DE OPERANDOS IR -----

unsigned long generate_IR_operand_virtual_reg_ID(){
    return ++CURRENT_REG_ID;
}

// ===============================================================

// ----- IMPLEMENIRION DE FUNCIONES DE GESTION DE OPERANDOS IR -----

struct IR_operand * create_IR_operand(IR_operand_t kind){
    struct IR_operand * operand = malloc(sizeof(*operand));

    // -- Comprobar creacion exitosa de operando
    if(!operand)
        return NULL;

    // -- Asignar tipo de operando
    operand->kind = kind;
    switch (operand->kind)
    {
    case IR_OP_VIRTUAL_REG:
    {
        operand->kind_str = strdup("operando registro virtual");
        break;
    }
    case IR_OP_VAR:
    {
        operand->kind_str = strdup("operando variable");
        break;
    }
    case IR_OP_LITERAL:
    {
        operand->kind_str = strdup("operando literal");
        break;
    }
    default:
    {
        operand->kind_str = NULL;
        break;
    }
    }

    if(!operand->kind_str){
        free(operand);
        return NULL;
    }

    // -- Retornar operando
    return operand;
}

struct IR_operand * create_IR_operand_var(char * var_name){
    // -- Crear operando
    struct IR_operand * operand = create_IR_operand(IR_OP_VAR);

    // -- Comprobar creacion de operando
    if(!operand)
        return NULL;

    // -- Asignar nombre de variable
    operand->data.var_name = strdup(var_name);

    if(!operand->data.var_name){
        free(operand);
        return NULL;
    }

    // -- Retornar operando
    return operand;
}

struct IR_operand * create_IR_operand_virtual_reg(){
    struct IR_operand * operand = create_IR_operand(IR_OP_VIRTUAL_REG);

    // -- Comprobar creacion de operando
    if(!operand)
        return NULL;

    // -- Asignar ID de variable temporal
    operand->data.id_reg = generate_IR_operand_virtual_reg_ID();

    // -- Retornar operando
    return operand;
}

struct IR_operand * create_IR_operand_literal(struct IR_literal * literal){
    struct IR_operand * operand = create_IR_operand(IR_OP_LITERAL);

    // -- Comprobar creacion de operando
    if(!operand)
        return NULL;

    // -- Asignar literal
    operand->data.literal = literal;

    // -- Retornar operando
    return operand;
}

struct IR_operand * create_IR_operand_literal_integer(int value){
    // -- Crear literal y comprobar
    struct IR_literal * literal = create_IR_literal_integer(value);

    if(!literal)
        return NULL;

    // -- Crear operando
    return create_IR_operand_literal(literal);
}

struct IR_operand * create_IR_operand_literal_real(float value){
    // -- Crear literal y comprobar
    struct IR_literal * literal = create_IR_literal_real(value);

    if(!literal)
        return NULL;

    // -- Crear operando
    return create_IR_operand_literal(literal);
}

struct IR_operand * create_IR_operand_literal_char(char value){
    // -- Crear literal y comprobar
    struct IR_literal * literal = create_IR_literal_char(value);

    if(!literal)
        return NULL;

    // -- Crear operando
    return create_IR_operand_literal(literal);
}

struct IR_operand * create_IR_operand_literal_string(char *value){
    // -- Crear literal y comprobar
    struct IR_literal * literal = create_IR_literal_string(value);

    if(!literal)
        return NULL;

    // -- Crear operando
    return create_IR_operand_literal(literal);
}

struct IR_operand * create_IR_operand_literal_boolean(int value){
    // -- Crear literal y comprobar
    struct IR_literal * literal = create_IR_literal_boolean(value);

    if(!literal)
        return NULL;

    // -- Crear operando
    return create_IR_operand_literal(literal);
}

// ===============================================================

// ----- IMPLEMENIRION DE FUNCIONES DE LIBERACION DE OPERANDOS IR -----

void free_IR_operand(struct IR_operand * operand){
    if(!operand)
        return;

    // -- Liberar tipo de operando
    free(operand->kind_str);
    operand->kind_str = NULL;

    // -- Liberar contenido de operando en funcion de su tipo
    switch (operand->kind)
    {
    case IR_OP_VAR:
    {
        free(operand->data.var_name);
        operand->data.var_name = NULL;
        break;
    }

    case IR_OP_VIRTUAL_REG:
    {
        // -- No hacer nada
        break;
    }
    
    case IR_OP_LITERAL:
    {
        free_IR_literal(operand->data.literal);
        operand->data.literal = NULL;
        break;
    }

    default:
        break;
    }

    // -- Liberar operando
    free(operand);
}

// ===============================================================

// ----- IMPLEMENIRION DE FUNCIONES DE IMPRESION DE OPERANDOS IR -----

void print_IR_operand(struct IR_operand * operand){
    if(!operand)
        return;

    // -- Imprimir en funcion del tipo
    switch (operand->kind)
    {
    case IR_OP_VIRTUAL_REG:
    {
        printf("%%r%ld",operand->data.id_reg);
        break;
    }
    case IR_OP_VAR:
    {
        printf("%s",operand->data.var_name);
        break;
    }
    case IR_OP_LITERAL:
    {
        print_IR_literal(operand->data.literal);
        break;
    }
    
    default:
        break;
    }
}
