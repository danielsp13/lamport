/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file literal.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para generacion
 * de codigo intermedio  (Literales de IR Lineal)
 */

#ifndef _LAMPORT_IR_LITERAL_DPR_
#define _LAMPORT_IR_LITERAL_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ===============================================================

// ----- DEFINICION DE VARIABLES GLOBALES -----    

// ===============================================================

// ----- DEFINICION DE TIPOS DE LITERALES DE IR -----

/**
 * @brief Enumerado que representa los diferentes tipos de literales
 * posibles en el codigo IR
 */
typedef enum{
    IR_LITERAL_INTEGER,                ///< Literal entero
    IR_LITERAL_REAL,                   ///< Literal flotante
    IR_LITERAL_STRING,                 ///< Literal de cadena de caracteres
    IR_LITERAL_CHAR,                   ///< Literal de caracter
    IR_LITERAL_BOOLEAN                 ///< Literal booleano
} IR_literal_t;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURA LITERAL -----

struct IR_literal{
    IR_literal_t kind;                 ///< Tipo de literal
    char *kind_str;                     ///< Tipo de literal (str)

    union{
        int literal_integer;            ///< Literal entero
        float literal_real;             ///< Literal flotante
        char literal_char;              ///< Literal caracter
        char *literal_string;           ///< Literal de cadena de caracteres
        int literal_boolean;            ///< Literal de booleano
    } value;
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE LITERALES DE IR -----

/**
 * @brief Crea y reserva memoria para la definicion de un literal del lenguaje IR
 * @param kind : tipo de literal
 * @return puntero a literal creado (sin asignar valor)
 */
struct IR_literal * create_IR_literal(IR_literal_t kind);

/**
 * @brief Crea y reserva memoria para la definicion de un literal entero del lenguaje IR
 * @param value : valor de literal
 * @return puntero a literal creado e inicializado
 */
struct IR_literal * create_IR_literal_integer(int value);

/**
 * @brief Crea y reserva memoria para la definicion de un literal real del lenguaje IR
 * @param value : valor de literal
 * @return puntero a literal creado e inicializado
 */
struct IR_literal * create_IR_literal_real(float value);

/**
 * @brief Crea y reserva memoria para la definicion de un literal caracter del lenguaje IR
 * @param value : valor de literal
 * @return puntero a literal creado e inicializado
 */
struct IR_literal * create_IR_literal_char(char value);

/**
 * @brief Crea y reserva memoria para la definicion de un literal cadena de caracteres del lenguaje IR
 * @param value : valor de literal
 * @return puntero a literal creado e inicializado
 */
struct IR_literal * create_IR_literal_string(char *value);

/**
 * @brief Crea y reserva memoria para la definicion de un literal booleano del lenguaje IR
 * @param value : valor de literal
 * @return puntero a literal creado e inicializado
 */
struct IR_literal * create_IR_literal_boolean(int value);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE LIBERACION DE LITERALES DE IR -----

/**
 * @brief Libera la memoria reservada para un literal del lenguaje IR
 * @param lit : literal
 */
void free_IR_literal(struct IR_literal * lit);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE IMPRESION DE LITERALES DE IR -----

/**
 * @brief Imprime un literal del lenguaje IR
 * @param lit : literal
 */
void print_IR_literal(struct IR_literal * lit);

#endif //_LAMPORT_IR_LITERAL_DPR_