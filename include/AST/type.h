/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file type.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO tipos
 */

#ifndef _LAMPORT_AST_TYPE_DPR_
#define _LAMPORT_AST_TYPE_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE NODO -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "expression.h"          ///< Expresiones
#include "print_assistant.h"     ///< Asistencia de impresion de AST

// ===============================================================

// ----- DEFINICION DE TIPOS DE DATO -----

/**
 * @brief Estructura que representa los tipos de datos del lenguaje de lamport.
 */
typedef enum{
    TYPE_INTEGER,           ///< Tipo de dato entero
    TYPE_BOOLEAN,           ///< Tipo de dato booleano
    TYPE_CHAR,              ///< Tipo de dato caracter
    TYPE_STRING,            ///< Tipo de dato cadena de caracteres
    TYPE_REAL,              ///< Tipo de dato flotante
    TYPE_ARRAY,             ///< Tipo de dato array
    TYPE_SEMAPHORE,         ///< Tipo de dato semaforo
    TYPE_DPROCESS,          ///< Tipo de dato proceso dinamico
} type_t;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DEL AST (NODO DE TIPOS) -----

/**
 * @brief Estructura que representa a un tipo de dato en lamport.
 * 
 * Esta estructura almacena informacion sobre un tipo de dato de una variable
 * o de una funcion mencionada en una declaracion, en el lenguaje lamport.
 * 
 * Dependiendo del tipo de dato, se requerira mas informacion adicional
 * para describir adecuadamente el valor de la variable o el retorno de la funcion.
 * 
 * TIPOS DE DATO BASICOS
 *   -> Son tipos de datos simples, conocidos:
 *   -> Lista:
 *      ///> INTEGER
 *      ///> REAL
 *      ///> BOOLEAN
 *      ///> CHAR
 *      ///> STRING
 * 
 * TIPOS DE DATO COMPUESTOS
 *   -> Son tipos de datos especiales que requieren mas informacion
 *   -> Lista:
 *      ///> ARRAY
 *      ///> SEMAPHORE
 *      ///> DPROCESS
 */
struct type{
    type_t kind;                            ///< Tipo de dato
    char *kind_str;                         ///< Tipo de dato (en formato string)
    struct type *subtype;                   ///< Subtipo de dato (arrays)
    struct expression *size;                ///< Size de dato (arrays)
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (TIPOS) -----

/**
 * @brief Crea y reserva memoria para un tipo de dato de tipo basico
 * @param kind : tipo de dato
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_basic_type(type_t kind);

/**
 * @brief Crea y reserva memoria para el tipo de dato de array
 * @param subtype : tipo de dato almacenado en el array
 * @param size : dimension del array
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_array_type(struct type *subtype, struct expression *size);

/**
 * @brief Crea y reserva memoria para el tipo de dato semaphore
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_semaphore_type();

/**
 * @brief Crea y reserva memoria para el tipo de dato proceso dinamico
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_dprocess_type();

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO TIPOS) ------

/**
 * @brief Libera la memoria asignada para un nodo de tipo type
 * @param type : Puntero a nodo tipo
 */
void free_type(struct type **type);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO TIPOS) -----

/**
 * @brief Imprime un nodo de tipo de dato
 * @param type : Puntero a nodo tipo
 * @param depth : Profundidad en la impresion del nodo
 */
void print_AST_type(struct type *type, unsigned int depth);

#endif //_LAMPORT_AST_TYPE_DPR_