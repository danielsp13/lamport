/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file error_syntax.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para gestion de errores
 * producidos en el analizador sintactico
 */

#ifndef _LAMPORT_ERROR_PARSER_DPR_
#define _LAMPORT_ERROR_PARSER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "error.h"              ///< Estructura de error

// ===============================================================

// ----- DEFINICION DE MENSAJES DE ERROR ----

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE ERRORES (SINTACTICOS) ----

/**
 * @brief Crea y reserva memoria para un error sintactico
 * @param kind : tipo de error sintactico
 * @param err_line : linea donde se produjo el error sintactico
 * @param msg : mensaje de error
 * @return puntero a error sintactico inicializado
 */
struct error * create_error_syntax(error_syntax_t kind, unsigned long line, char *msg);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE IMPRESION DE ERRORES (SINTACTICOS) ----

/**
 * @brief Imprime la lista de errores sintacticos
 * @param list_errors : lista de errores
 */
void print_list_error_syntax(struct error *list_errors);

#endif //_LAMPORT_ERROR_PARSER_DPR_