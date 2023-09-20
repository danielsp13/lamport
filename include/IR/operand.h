/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file operand.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para generacion
 * de codigo intermedio (Operando de IR Lineal)
 */

#ifndef _LAMPORT_IR_OPERAND_DPR_
#define _LAMPORT_IR_OPERAND_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "literal.h"                    ///< Literales del lenguaje

// ===============================================================

// ----- DEFINICION DE VARIABLES GLOBALES -----   

// Variable para definir ID de operandos de registros virtuales (contador)
extern unsigned long CURRENT_REG_ID;

// ===============================================================

// ----- DEFINICION DE TIPOS DE OPERANDOS DE IR -----

/**
 * @brief Enumerado que representa los diferentes tipos de operandos
 * que permite el codigo IR Lineal
 */
typedef enum{
    IR_OP_VIRTUAL_REG,                  ///< Variable registro virtual
    IR_OP_VAR,                          ///< Variable definida por el programador
    IR_OP_LITERAL                       ///< Valor literal
} IR_operand_t;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURA OPERANDO IR -----

/**
 * 
 */
struct IR_operand{
    IR_operand_t kind;                  ///< Tipo de operando
    char *kind_str;                     ///< Tipo de operando (str)

    union{
        char *var_name;                ///< Si es una variable
        unsigned long id_reg;          ///< Si es una variable registro
        struct IR_literal * literal;   ///< Si es una constante
    } data;
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE ASISTENCIA A GESTION DE OPERANDOS IR -----

/**
 * @brief Genera un nuevo identificador para un operando de tipo registro del lenguaje IR
 * @return identificador entero de operando IR registro
 */
unsigned long generate_IR_operand_virtual_reg_ID();

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE OPERANDOS IR -----

/**
 * @brief Crea y reserva memoria para la definicion de un operando del lenguaje IR
 * @param kind : tipo de operando
 * @return puntero a operando creado (sin asignar valor)
 */
struct IR_operand * create_IR_operand(IR_operand_t kind);

/**
 * @brief Crea y reserva memoria para la definicion de un operando de variable del lenguaje IR
 * @param var_name : identificador de la variable
 * @return puntero a operando creado  e inicializado
 */
struct IR_operand * create_IR_operand_var(char * var_name);

/**
 * @brief Crea y reserva memoria para la definicion de un operando de registro del lenguaje IR
 * @return puntero a operando creado e inicializado
 */
struct IR_operand * create_IR_operand_virtual_reg();

/**
 * @brief Crea y reserva memoria para la definicion de un operando literal del lenguaje IR
 * @param literal : valor de literal
 * @return puntero a operando creado e inicializado
 */
struct IR_operand * create_IR_operand_literal(struct IR_literal * literal);

/**
 * @brief Crea y reserva memoria para la definicion de un operando literal de tipo integer
 * @param value : valor de integer
 * @return puntero a operando creado e inicializado
 */
struct IR_operand * create_IR_operand_literal_integer(int value);

/**
 * @brief Crea y reserva memoria para la definicion de un operando literal de tipo real
 * @param value : valor de real
 * @return puntero a operando creado e inicializado
 */
struct IR_operand * create_IR_operand_literal_real(float value);

/**
 * @brief Crea y reserva memoria para la definicion de un operando literal de tipo char
 * @param value : valor de char
 * @return puntero a operando creado e inicializado
 */
struct IR_operand * create_IR_operand_literal_char(char value);

/**
 * @brief Crea y reserva memoria para la definicion de un operando literal de tipo string
 * @param value : valor de string
 * @return puntero a operando creado e inicializado
 */
struct IR_operand * create_IR_operand_literal_string(char *value);

/**
 * @brief Crea y reserva memoria para la definicion de un operando literal de tipo boolean
 * @param value : valor de booleano
 * @return puntero a operando creado e inicializado
 */
struct IR_operand * create_IR_operand_literal_boolean(int value);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE LIBERACION DE OPERANDOS IR -----

/**
 * @brief Libera la memoria reservada para un operando del lenguaje IR
 * @param operand : operando
 */
void free_IR_operand(struct IR_operand * operand);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE IMPRESION DE OPERANDOS IR -----

/**
 * @brief Imprime un operando del lenguaje IR
 * @param operand : operando
 */
void print_IR_operand(struct IR_operand * operand);

#endif //_LAMPORT_IR_OPERAND_DPR_