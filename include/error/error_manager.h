/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file error_manager.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para gestion de errores
 * producidos en la compilacion. Gestor de errores general.
 */

#ifndef _LAMPORT_ERROR_MANAGER_DPR_
#define _LAMPORT_ERROR_MANAGER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include "error_semantic.h"         ///< Errores semanticos
#include "error_syntax.h"           ///< Errores sintacticos

// ===============================================================

// ----- DEFINICION DE VARIABLES DE CONTROL -----

// Cuenta el total de errores sintacticos producidos
extern unsigned int TOTAL_SYNTAX_ERRORS;

// Cuenta el total de errores semanticos producidos
extern unsigned int TOTAL_SEMANTIC_ERRORS;

// ===============================================================

// ----- DEFINICION DE LISTAS ENLAZADAS DE CONTROL -----

// Lista enlazada de errores sintacticos
extern struct error *list_error_syntax;

// Lista enlazada de errores semanticos
extern struct error *list_error_semantic;

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE ERRORES -----

/**
 * @brief Incluye un nuevo error a la lista correspondiente
 * @param err : error a incluir
 */
void add_error_to_list(struct error * err);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE ERRORES (SINTACTICOS) -----

/**
 * @brief Incluye un nuevo error sintactico en la lista de errores sintacticos
 * @param err : error sintactico
 */
void add_error_syntax_to_list(struct error * err);

/**
 * @brief Crea e inlcuye un nuevo error sintactico en la lista de errores sintacticos
 * @param kind : tipo de error sintactico
 * @param identifier : identificador de declaracion/subprograma/proceso donde se produjo el error sintactico
 * @param line : linea donde se produjo el error sintactico
 * @param msg : mensaje de error
 */
void create_and_add_error_syntax_to_list(error_syntax_t kind, char *identifier, unsigned long line, char *msg);

/**
 * @brief Devuelve el total de errores sintacticos producidos
 * @return total de errores sintacticos
 */
unsigned int get_total_error_syntax();

/**
 * @brief Libera la memoria utilizada para la lista de errores sintacticos
 */
void free_list_error_syntax();

/**
 * @brief Imprime los errores sintacticos
 */
void report_list_error_syntax();

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE ERRORES (SEMANTICOS) -----

/**
 * @brief Incluye un nuevo error semantico en la lista de errores semanticos
 * @param err : error semantico
 */
void add_error_semantic_to_list(struct error * err);

/**
 * @brief Devuelve el total de errores semanticos producidos
 * @return total de errores semanticos
 */
unsigned int get_total_error_semantic();

/**
 * @brief Libera la memoria utilizada para la lista de errores semanticos
 */
void free_list_error_semantic();

/**
 * @brief Imprime los errores semanticos
 */
void report_list_error_semantic();

#endif //_LAMPORT_ERROR_MANAGER_DPR_