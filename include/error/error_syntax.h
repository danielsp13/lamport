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

// -- Definicion de errores de reconocimiento de programa (program)
#define ERR_SYNTAX_PROGRAM_EXPECTED_PROGRAM_TOKEN_MSG "se esperaba 'program' al inicio de definicion del programa"
#define ERR_SYNTAX_PROGRAM_EXPECTED_IDENTIFIER_AFTER_PROGRAM_MSG "se esperaba un identificador despues de: 'program'"

// -- Definicion de errores de reconocimiento de declaraciones (declaration)
#define ERR_SYNTAX_DECLARATION_EXPECTED_VAR_TOKEN_MSG "se esperaba 'var' al inicio de la declaracion"
#define ERR_SYNTAX_DECLARATION_EXPECTED_IDENTIFIER_AFTER_VAR_MSG "se esperaba un identificador despues de: 'var'"
#define ERR_SYNTAX_DECLARATION_EXPECTED_DELIM2P_TOKEN_MSG "fata ':' en la declaracion"
#define ERR_SYNTAX_DECLARATION_EXPECTED_OPASSIGN_TOKEN_MSG "falta ':=' en la declaracion"
#define ERR_SYNTAX_DECLARATION_EXPECTED_DELIMPC_DECL_MSG "falta ';' al final de la declaracion"

// -- Definicion de errores de reconocimiento de expresiones (expression)
#define ERR_SYNTAX_EXPRESSION_EXPECTED_EXPRESSION_MSG "se esperaba una expresion valida"

// -- Definicion de errores de reconocimiento de tipos (type)
#define ERR_SYNTAX_TYPE_EXPECTED_TYPE_TOKEN_MSG "se esperaba tipo de dato valido despues de: ':'"

// -- Definicion de errores de reconocimiento de subprogramas (subprogram)
#define ERR_SYNTAX_PROCEDURE_EXPECTED_PROCEDURE_TOKEN_MSG "se esperaba 'procedure' al inicio de la definicion"
#define ERR_SYNTAX_PROCEDURE_EXPECTED_IDENTIFIER_AFTER_PROCEDURE_MSG "se esperaba un identificador despues de: 'procedure'"

#define ERR_SYNTAX_FUNCTION_EXPECTED_FUNCTION_TOKEN_MSG "se esperaba 'function' al inicio de la definicion"
#define ERR_SYNTAX_FUNCTION_EXPECTED_IDENTIFIER_AFTER_FUNCTION_MSG "se esperaba un identificador despues de: 'function'"
#define ERR_SYNTAX_FUNCTION_EXPECTED_DELIM2P_TOKEN_MSG "fata ':' en la definicion de funcion"

#define ERR_SYNTAX_SUBPROGRAM_EXPECTED_PARIZDO_TOKEN_MSG "falta '(' en la definicion de subprograma"
#define ERR_SYNTAX_SUBPROGRAM_EXPECTED_PARDCHO_TOKEN_MSG "falta ')' en la definicion de subprograma"
#define ERR_SYNTAX_SUBPROGRAM_EXPECTED_DELIMPC_TOKEN_MSG "falta ';' en la definicion de subprograma"

// -- Definicion de errores de reconocimiento de parametros (parameter)
#define ERR_SYNTAX_PARAMETER_EXPECTED_IDENTIFIER_MSG "se esperaba un identificador valido de parametro"
#define ERR_SYNTAX_PARAMETER_EXPECTED_DELIM2P_MSG "falta ':' en la definicion de parametro"
#define ERR_SYNTAX_PARAMETER_EXPECTED_DELIMC_MSG "falta ',' en la definicion de parametros"
#define ERR_SYNTAX_PARAMETER_EXPECTED_PARAMETER_MSG "se esperaba un parametro en la lista"

// -- Definicion de errrores de reconocimiento de procesos (process)
#define ERR_SYNTAX_PROCESS_EXPECTED_IDENTIFIER_AFTER_PROCESS_MSG "se esperaba un identificador despues de: 'process'"
#define ERR_SYNTAX_PROCESS_EXPECTED_DELIMPC_MSG "falta ';' en la definicion de proceso"
#define ERR_SYNTAX_PROCESS_EXPECTED_CORCHIZDO_MSG "falta '[' en la definicion de vector de procesos"
#define ERR_SYNTAX_PROCESS_EXPECTED_CORCHDCHO_MSG "falta ']' en la definicion de vector de procesos"
#define ERR_SYNTAX_PROCESS_EXPECTED_DELIM2P_MSG "falta ':' en la definicion de vector de procesos"
#define ERR_SYNTAX_PROCESS_EXPECTED_IDENTIFIER_INDEXER_MSG "se esperaba un identificador valido de indexacion de vector de procesos"
#define ERR_SYNTAX_PROCESS_EXPECTED_DELIMARR_MSG "se esperaba delimitador de rango de vector de procesos: '..'"

// -- Definicion de errores de reconocimiento de sentencias (statements)
#define ERR_SYNTAX_STATEMENT_EXPECTED_DELIMPC_MSG "falta ';' al final de la sentencia"
#define ERR_SYNTAX_STATEMENT_EXPECTED_STATEMENT_MSG "se esperaba una sentencia valida"
#define ERR_SYNTAX_STATEMENT_EXPECTED_NON_EMPTY_BLOCK_MSG "bloque de sentencias vacio"

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

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE MARCADO DE ERRORES SINTACTICOS -----

// ----/////----------------------------------------------------------
// FUNCIONES DE MANEJO DE ERRORES (DECLARACIONES)

extern void mark_error_syntax_declaration_expected_var();

extern void mark_error_syntax_declaration_expected_identifier();

extern void mark_error_syntax_declaration_expected_delim2p();

extern void mark_error_syntax_declaration_expected_type();

extern void mark_error_syntax_declaration_expected_opassign();

extern void mark_error_syntax_declaration_expected_delimpc();

// ----/////----------------------------------------------------------
// FUNCIONES DE MANEJO DE ERRORES (SUBPROGRAMAS)

extern void mark_error_syntax_subprogram_expected_procedure();

extern void mark_error_syntax_subprogram_procedure_expected_identifier();

extern void mark_error_syntax_subprogram_function_expected_function();

extern void mark_error_syntax_subprogram_function_expected_identifier();

extern void mark_error_syntax_subprogram_function_expected_delim2p();

extern void mark_error_syntax_subprogram_expected_parizdo();

extern void mark_error_syntax_subprogram_expected_pardcho();

extern void mark_error_syntax_subprogram_expected_delimpc();

// ----/////----------------------------------------------------------
// FUNCIONES DE MANEJO DE ERRORES (TIPOS)

extern void mark_error_syntax_type_expected_type();

// ----/////----------------------------------------------------------
// FUNCIONES DE MANEJO DE ERRORES (PARAMETROS)

extern void mark_error_syntax_parameter_expected_parameter();

extern void mark_error_syntax_parameter_expected_identifier();

extern void mark_error_syntax_parameter_expected_delim2p();

extern void mark_error_syntax_parameter_expected_delimc();

// ----/////----------------------------------------------------------
// FUNCIONES DE MANEJO DE ERRORES (SENTENCIAS)

extern void mark_error_syntax_statement_expected_statement();

extern void mark_error_syntax_statement_empty_block();

extern void mark_error_syntax_statement_expected_delimpc();

// ----/////----------------------------------------------------------
// FUNCIONES DE MANEJO DE ERRORES (EXPRESIONES)

extern void mark_error_syntax_expression_expected_expr();

// ----/////----------------------------------------------------------
// FUNCIONES DE MANEJO DE ERRORES (PROCESOS)

extern void mark_error_syntax_process_expected_identifier();

extern void mark_error_syntax_process_expected_delimpc();

extern void mark_error_syntax_process_expected_corchizdo();

extern void mark_error_syntax_process_expected_corchdcho();

extern void mark_error_syntax_process_expected_index_identifier();

extern void mark_error_syntax_process_expected_delim2p();

extern void mark_error_syntax_process_expected_delimarr();

// ----/////----------------------------------------------------------
// FUNCIONES DE MANEJO DE ERRORES (PROGRAMAS)

extern void mark_error_syntax_program_expected_program();

extern void mark_error_syntax_program_expected_identifier();

#endif //_LAMPORT_ERROR_PARSER_DPR_