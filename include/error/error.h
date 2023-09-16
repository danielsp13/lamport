/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file error_manager.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para gestion de errores
 * producidos en la compilacion.
 */

#ifndef _LAMPORT_ERROR_DPR_
#define _LAMPORT_ERROR_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "error_type.h"     ///< Tipos de errores

// ===============================================================

// ----- DEFINICION DE TIPOS DE ERRORES -----

/**
 * @brief Estructura que define los tipos de errores que se pueden producir
 * en la compilacion del lenguaje
 */
typedef enum{
    ERROR_SYNTAX,           ///< Error sintactico
    ERROR_SEMANTIC          ///< Error semantico
} error_t;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURA DE ERROR -----

/**
 * @brief Estructura que representa un error de compilacion del lenguaje
 */
struct error{
    error_t kind;                       ///< Tipo de error
    char * kind_str;                    ///< Tipo de error (str)
    unsigned long err_line;             ///< Linea donde se produjo el error
    char * msg;                         ///< Mensaje de error

    union{
        // Datos adicionales para error sintactico
        struct{
            error_syntax_t kind;        ///< Tipo de error sintactico
        } error_syntax;
        
        // Datos adicionales para error semantico
        struct{
            error_semantic_t kind;          ///< Tipo de error semantico
            unsigned long def_line;         ///< Especifica la linea donde se definio el simbolo encontrado (para errores relacionados con duplicacion)
            int which;                      ///< Posicion en la que se declaro el parametro con anterioridad (para errores relacionados con duplicacion de parametros)
            char *id;                       ///< Identificador del simbolo que produjo el error (para errores relacionados con simbolos)
        } error_semantic;
    } err_data;                         ///< Informacion adicional del error

    struct error * next;                ///< Puntero a siguiente error
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE ERRORES ----

/**
 * @brief Crea y reserva memoria para un error
 * @param kind : tipo de error
 * @param err_line : linea donde se produjo el error
 * @param msg : mensaje de error
 * @return puntero a error creado e inicializado
 */
struct error * create_error(error_t kind, unsigned long err_line, char *msg);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE LIBERACION DE ERRORES ----

/**
 * @brief Libera la memoria reserada para una lista de errores
 * @param list_errors : lista de errores
 */
void free_list_errors(struct error *list_errors);

/**
 * @brief Libera la memoria reservada para un error
 * @param error : error a liberar
 */
void free_error(struct error *error);

#endif //_LAMPORT_ERROR_DPR_