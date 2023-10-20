/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file name_resolution.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de funciones para implementar resolucion de nombres
 * sobre el AST
 */

#ifndef _LAMPORT_SEMANTIC_NAME_RESOLUTION_DPR_
#define _LAMPORT_SEMANTIC_NAME_RESOLUTION_DPR_

#ifdef __cplusplus
extern "C" {
#endif

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "symbol.h"                 ///< Simbolo
#include "symbol_table.h"           ///< Tabla de simbolos
#include "AST/AST.h"                ///< AST
#include "error/error_manager.h"    ///< Gestor de errores

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE RESOLUCION DE NOMBRES (LISTAS) -----

/**
 * @brief Realiza la resolucion de nombres a una lista de declaraciones
 * @param list_declarations : puntero a lista de declaraciones
 * @param precedence : nombre de precedencia de la lista de declaraciones
 */
void resolve_list_declarations(struct declaration *list_declarations, char * precedence);

/**
 * @brief Realiza la resolucion de nombres a una lista de expresiones
 * @param list_expressions : puntero a lista de expresiones
 */
void resolve_list_expressions(struct expression *list_expressions);

/**
 * @brief Realiza la resolucion de nombres a una lista de sentencias
 * @param list_statements : puntero a lista de sentencias
 */
void resolve_list_statements(struct statement *list_statements);

/**
 * @brief Realiza la resolucion de nombres a una lista de procesos
 * @param list_process : puntero a lista de procesos
 */
void resolve_list_process(struct process *list_process);

/**
 * @brief Realiza la resolucion de nombres a una lista de parametros de subprograma
 * @param list_parameter : puntero a lista de parametros
 */
void resolve_list_parameters(struct parameter *list_parameter);

/**
 * @brief Realiza la resolucion de nombres a una lista de subprogramas
 * @param list_subprograms : puntero a lista de subprogramas
 */
void resolve_list_subprograms(struct subprogram *list_subprograms);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO DECLARACIONES) -----

/**
 * @brief Realiza la resolución de nombres dentro de una declaración de variable.
 * @param decl : puntero a declaracion de una variable
 * @param precedence : precedencia de la declaracion
 */
void resolve_declaration(struct declaration *decl, char * precedence);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO EXPRESIONES) -----

/**
 * @brief Realiza la resolucion de nombres en una expresion
 * @param expr : puntero a expresion
 */
void resolve_expression(struct expression *expr);

/**
 * @brief Realiza la resolucion de nombres en una expresion de tipo operacion binaria
 * @param expr : puntero a expresion (operacion binaria)
 */
void resolve_expression_binary_operation(struct expression *expr);

/**
 * @brief Realiza la resolucion de nombres en una expresion de tipo operacion unaria
 * @param expr : puntero a expresion (operacion unaria)
 */
void resolve_expression_unary_operation(struct expression *expr);

/**
 * @brief Realiza la resolucion de nombres en una expresion de tipo identificador
 * @param expr : puntero a expresion (identificador)
 */
void resolve_expression_identifier(struct expression *expr);

/**
 * @brief Realiza la resolucion de nombres en una expresion de tipo invocacion de funcion
 * @param expr : puntero a expresion (invocacion de funcion)
 */
void resolve_expression_function_inv(struct expression *expr);

/**
 * @brief Realiza la resolucion de nombres en una expresion entre parentesis
 * @param expr : puntero a expresion (expresion entre parentesis)
 */
void resolve_expression_grouped(struct expression *expr);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO SENTENCIAS) -----

/**
 * @brief Realiza la resolucion de nombres en una sentencia
 * @param stmt : puntero a sentencia
 */
void resolve_statement(struct statement *stmt);

/**
 * @brief Realiza la resolucion de nombres en una sentencia de tipo asignacion
 * @param stmt : puntero a sentencia (asignacion)
 */
void resolve_statement_assignment(struct statement *stmt);

/**
 * @brief Realiza la resolucion de nombres en una sentencia de tipo while
 * @param stmt : puntero a sentencia (while)
 */
void resolve_statement_while(struct statement *stmt);

/**
 * @brief Realiza la resolucion de nombres en una sentencia de tipo for
 * @param stmt : puntero a sentencia (for)
 */
void resolve_statement_for(struct statement *stmt);

/**
 * @brief Realiza la resolucion de nombres en una sentencia de tipo if else
 * @param stmt : puntero a sentencia (if else)
 */
void resolve_statement_if_else(struct statement *stmt);

/**
 * @brief Realiza la resolucion de nombres en una sentencia de tipo invocacion de procedimiento
 * @param stmt : puntero a sentencia (invocacion de procedimiento)
 */
void resolve_statement_procedure_inv(struct statement *stmt);

/**
 * @brief Realiza la resolucion de nombres en una sentencia de tipo bloque de sentencias
 * @param stmt : puntero a sentencia (bloque de sentencias: begin, cobegin, atomic)
 */
void resolve_statement_block(struct statement *stmt);

/**
 * @brief Realiza la resolucion de nombres en una sentencia de tipo fork
 * @param stmt : puntero a sentencia (fork)
 */
void resolve_statement_fork(struct statement *stmt);

/**
 * @brief Realiza la resolucion de nombres en una sentencia de tipo join
 * @param stmt : puntero a sentencia (join)
 */
void resolve_statement_join(struct statement *stmt);

/**
 * @brief Realiza la resolucion de nombres en una sentencia de tipo return
 * @param stmt : puntero a sentencia (return)
 */
void resolve_statement_return(struct statement *stmt);

/**
 * @brief Realiza la resolucion de nombres en una sentencia de tipo print
 * @param stmt : puntero a sentencia (print)
 */
void resolve_statement_print(struct statement *stmt);

/**
 * @brief Realiza la resolucion de nombres en una sentencia de tipo sem wait
 * @param stmt : puntero a sentencia (sem wait)
 */
void resolve_statement_sem_wait(struct statement *stmt);

/**
 * @brief Realiza la resolucion de nombres en una sentencia de tipo sem signal
 * @param stmt : puntero a sentencia (sem signal)
 */
void resolve_statement_sem_signal(struct statement *stmt);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO PROCESOS) -----

/**
 * @brief Realiza la resolucion de nombres en un proceso
 * @param proc : puntero a proceso
 */
void resolve_process(struct process *proc);

/**
 * @brief Realiza la resolucion de nombres en un proceso de tipo vector
 * @param proc : puntor a proceso (vector)
 */
void resolve_process_vector(struct process *proc);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO TIPO DE DATO) -----

/**
 * @brief Realiza la resolucion de nombres de un tipo de dato
 * @param type : puntero a tipo de dato
 */
void resolve_type(struct type *type);

/**
 * @brief Realiza la resolucion de nombres en un tipo de dato array
 * @param type : puntero a tipo de dato (array)
 */
void resolve_type_array(struct type *type);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO LISTA DE PARAMETROS) -----

/**
 * @brief Realiza la resolucion de nombres en un parametro de subprograma
 * @param parameter : puntero a parametro
 * @param position : posicion que ocupa el parametro en la lista de parametros
 */
void resolve_parameter(struct parameter *parameter, unsigned int position);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO SUBPROGRAMA) -----

/**
 * @brief Realiza la resolucion de nombres en un subprograma
 * @param subprog : puntero a subprograma
 */
void resolve_subprogram(struct subprogram *subprog);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE RESOLUCION DE NOMBRES (NODO PROGRAMA) -----

/**
 * @brief Realiza la resolucion de nombres en un programa
 * @param prog : puntero a programa
 */
void resolve_program(struct program *prog);

#ifdef __cplusplus
}
#endif

#endif //_LAMPORT_SEMANTIC_NAME_RESOLUTION_DPR_