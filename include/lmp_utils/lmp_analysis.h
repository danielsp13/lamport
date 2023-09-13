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

#define LMP_SEMANTIC_SUCCESS 0   ///< Indica el exito en el procedimiento de analisis semantico
#define LMP_SEMANTIC_FAILURE -1  ///< Indica el fallo en el procedimiento de analisis semantico

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE C -----

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===============================================================

// ----- INCLUSION DE MODULOS -----

#include "parser/parser_register.h"     ///< Registro de cadenas de caracteres
#include "error/error_manager.h"        ///< Manejador de errores
#include "AST/AST.h"                    ///< Abstract Syntax Tree (AST)
#include "semantic/name_resolution.h"   ///< Semantic : Resolucion de nombres

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

// ----- PROTOTIPO DE FUNCIONES DE GESTION (SEMANTIC) -----

/**
 * @brief Realiza el analisis semantico del fichero de lamport abierto
 * por el compilador
 * @return LMP_PARSING_SUCCESS si exito, LMP_PARSING_FAILURE en otro caso
 */
int lmp_semantic_analysis();

/**
 * @brief Aplica el metodo de resolucion de nombres sobre el AST generado
 * en la fase de parsing
 * @return LMP_PARSING_SUCCESS si exito, LMP_PARSING_FAILURE en otro caso
 */
int lmp_semantic_name_resolution();

/**
 * @brief Libera la memoria de la tabla de simbolos utilizada en el analisis
 * semantico
 */
void lmp_free_symbol_table();

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

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION (PARSER REGISTER) -----

/**
 * @brief Libera la memoria utilizada por el registro de cadenas
 */
void lmp_free_string_register();

/**
 * @brief Libera la memoria utilizada por el registro de nodos AST
 */
void lmp_free_AST_node_register();

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION (ERRORES) -----

/**
 * @brief Imprime la informacion de todos los errores sintacticos producidos
 */
void lmp_print_error_syntax();

/**
 * @brief Imprime la informacion de todos los errores semanticos producidos en el analisis
 */
void lmp_print_error_semantic();

/**
 * @brief Libera la memoria utilizada por el modulo de gestion de errores
 */
void lmp_free_error_module();

#endif //_LMP_COMPILER_ANALYSIS_DPR_