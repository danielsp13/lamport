/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file error_semantic.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para gestion de errores
 * producidos en el analizador semantico
 */

#ifndef _LAMPORT_ERROR_SEMANTIC_DPR_
#define _LAMPORT_ERROR_SEMANTIC_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ===============================================================

// ----- DEFINICION DE TIPOS DE ERRORES ----

#define ERR_UNDEFINED_SYMBOL_MSG "uso de simbolo no definido"
#define ERR_DUPLICATED_SYMBOL_MSG "definicion de simbolo multiple"

// ===============================================================

// ----- DEFINICION DE TIPOS DE ERRORES ----

/**
 * @brief Estructura que representa los diferentes tipos de errores semanticos
 * del lenguaje lamport
 */
typedef enum{
    UNDEFINED_SYMBOL,               ///< Se ha detectado el uso de un simbolo no definido
    DUPLICATED_SYMBOL               ///< Se ha detectado la declaracion de un mismo simbolo mas de una vez
} error_semantic_t;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DE ERRORES (SEMANTICOS) ----

/**
 * @brief Estructura que representa un error semantico en el lenguaje lamport
 */
struct error_semantic{
    error_semantic_t kind;          ///< Tipo de error semantico
    unsigned long line;             ///< Especifica la linea donde se produjo el error semantico
    char *id;                       ///< Identificador del simbolo que produjo el error (para errores relacionados con simbolos)
    char *msg;                      ///< Mensaje de error semantico

    struct error_semantic *next;    ///< Puntero a siguiente error semantico utilizado
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE ERRORES (SEMANTICOS) ----

/**
 * @brief Crea y reserva memoria para un error semantico
 * @param kind : tipo de error semantico
 * @param id : identificador de simbolo
 * @param line : linea donde se produjo el error semantico
 * @param msg : mensaje de error
 * @return puntero a error semantico inicializado
 */
struct error_semantic * create_error_semantic(error_semantic_t kind, char *id, unsigned long line, char *msg);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo: USO DE SIMBOLO NO DEFINIDO
 * @param id : identificador de simbolo
 * @param line : linea donde se produjo el error semantico
 * @return puntero a error semantico inicializado
 */
struct error_semantic * create_error_semantic_undefined_symbol(char *id, unsigned long line);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo: DEFINCION DE SIMBOLO DUPLICADO
 * @param id : identificador de simbolo
 * @param line : linea donde se produjo el error semantico
 * @return puntero a error semantico inicializado
 */
struct error_semantic * create_error_semantic_duplicated_symbol(char *id, unsigned long line);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE LIBERACION DE ERRORES (SEMANTICOS) ----

/**
 * @brief Libera la memoria reservada para la lista de errores semanticos
 * @param list_errors : lista de errores
 */
void free_list_error_semantic(struct error_semantic *list_errors);

/**
 * @brief Libera la memoria reservada para un error semantico
 * @param error : error semantico
 */
void free_error_semantic(struct error_semantic *error);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE IMPRESION DE ERRORES (SEMANTICOS) ----

/**
 * @brief Imprime la lista de errores semanticos
 * @param list_errors : lista de errores
 */
void print_list_error_semantic(struct error_semantic *list_errors);

#endif //_LAMPORT_ERROR_SEMANTIC_DPR_