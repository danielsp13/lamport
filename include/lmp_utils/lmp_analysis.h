/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_analysis.h
 * @author Daniel Perez Ruiz
 * @brief 
 */

#ifndef _LMP_COMPILER_ANALYSIS_DPR_
#define _LMP_COMPILER_ANALYSIS_DPR_

// ===============================================================

// ----- DEFINICION DE MACROS PARA GESTION DE ANALISIS -----

#define LMP_PARSING_SUCCESS 0       ///< Indica el exito en el parsing de un fichero de lamport
#define LMP_PARSING_FAILURE -1      ///< Indica el fallo en el parsing de un fichero de lamport

#define LMP_PARSING_ERROR_MSG_HEADER "--- [LMP: PARSING - ERROR]"
#define LMP_PARSING_ERROR_MSG "Fallo al procesar el fichero"

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE C -----

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===============================================================

// ----- INCLUSION DE MODULOS -----

#include "AST/AST.h"            ///< Abstract Syntax Tree (AST)

// ===============================================================

// ----- VARIABLES GLOBALES DE GESTION (AST) -----

/**
 * @brief AST del programa lamport reconocido por el analizador sintactico
 */
extern struct program * program;

// ===============================================================

// ----- IMPORTACION DE FUNCIONES Y VARIABLES EXTERNAS (FLEX/BISON) -----

/**
 * @brief Funcion generada por Flex. Se encarga de realizar el analisis
 * lexico, reconociendo tokens a partir del texto fuente y retornando el
 * tipo de token reconocido.
 * 
 * Utilizada por yyparse()
 */
extern int yylex(void);

/**
 * @brief Funcion generada por Bison. Realiza el analisis sintactico del texto
 * fuente, estructurando los tokens reconocidos en la fase anterior por yylex().
 * @param program : Puntero a AST del programa
 */
extern int yyparse(void);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION (PARSING) -----

/**
 * @brief Realiza el analisis lexico y sintactico del fichero de lamport
 * abierto por el compilador
 * @return LMP_PARSING_SUCCESS si exito, LMP_PARSING_FAILURE en otro caso
 */
int lmp_parsing_file();

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION (AST) -----

/**
 * @brief Imprime el AST generado por el analizador sintactico
 */
void lmp_print_AST();

/**
 * @brief Libera la memoria del AST generado por el analizador sintactico
 */
void lmp_free_AST();

#endif //_LMP_COMPILER_ANALYSIS_DPR_