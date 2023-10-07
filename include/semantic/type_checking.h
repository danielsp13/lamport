/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file type_checking.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de funciones para implementar comprobacion de
 * tipos en el AST
 */

#ifndef _LAMPORT_SEMANTIC_TYPE_CHECKING_DPR_
#define _LAMPORT_SEMANTIC_TYPE_CHECKING_DPR_

#ifdef __cplusplus
extern "C" {
#endif

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "AST/AST.h"                ///< Abstract Syntax Tree (AST)
#include "error/error_manager.h"    ///< Gestor de errores

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE TYPE CHECKING (EXPRESIONES) -----

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a una expresion
 * @param expr : expresion a evaluar
 * @return puntero a tipo de dato resultante de evaluar la expresion
 */
struct type * typecheck_expression(struct expression *expr);

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a una expresion de operacion binaria
 * @param expr : expresion a evaluar
 * @return puntero a tipo de dato resultante de evaluar la expresion
 */
struct type * typecheck_expression_binary(struct expression *expr);

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a una expresion de tipo operacion unaria
 * @param expr : expresion a evaluar
 * @return puntero a tipo de dato resultante de evaluar la expresion
 */
struct type * typecheck_expression_unary(struct expression *expr);

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a una expresion de tipo identificador
 * @param expr : expresion a evaluar
 * @return puntero a tipo de dato resultante de evaluar la expresion
 */
struct type * typecheck_expression_identifier(struct expression *expr);

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a una expresion de tipo literal
 * @param expr : expresion a evaluar
 * @return puntero a tipo de dato resultante de evaluar la expresion
 */
struct type * typecheck_expression_literal(struct expression *expr);

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a una expresion de tipo invocacion de procedimiento
 * @param expr : expresion a evaluar
 * @return puntero a tipo de dato resultante de evaluar la expresion
 */
struct type * typecheck_expression_function_inv(struct expression *expr);

/**
 * @brief Aplicar el algoritmo de comprobacion de tipos a una expresion entre parentesis
 * @param expr : expresion a evaluar
 * @return puntero a tipo de dato resultante de evaluar la expresion
 */
struct type * typecheck_expression_grouped(struct expression *expr);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE TYPE CHECKING (EXPRESIONES : DELIBERACIONES) -----

/**
 * @brief Funcion evaluadora de expresiones de operacion binaria aritmetica
 * @param action : accion de operacion
 * @param type_left : tipo de dato del operando izquierdo de la expresion
 * @param type_right : tipo de dato del operando derecho de la expresion
 * @param line : linea donde se definio la expresion
 * @return puntero a tipo de dato resultante de la evaluacion de ambos miembros
 */
struct type * typecheck_expression_binary_arithmetic(char *action, struct type *type_left, struct type *type_right,unsigned long line);

/**
 * @brief Funcion evaluadora de expresiones de operacion binaria de comparacion
 * @param action : accion de operacion
 * @param type_left : tipo de dato del operando izquierdo de la expresion
 * @param type_right : tipo de dato del operando derecho de la expresion
 * @param line : linea donde se definio la expresion
 * @return puntero a tipo de dato resultante de la evaluacion de ambos miembros
 */
struct type * typecheck_expression_binary_comparison(char *action, struct type *type_left, struct type *type_right,unsigned long line);

/**
 * @brief Funcion evaluadora de expresiones de operacion unaria aritmetica
 * @param action : accion de operacion
 * @param type : tipo de dato del operando de la expresion
 * @param line : linea donde se definio la expresion
 * @return puntero a tipo de dato resultante de la evaluacion
 */
struct type * typecheck_expression_unary_arithmetic(char *action, struct type *type, unsigned long line);

/**
 * @brief Funcion evaluadora de expresiones de operacion unaria logica
 * @param action  : accion de operacion
 * @param type : tipo de dato del operando de la expresion
 * @param line : linea donde se definio la expresion
 * @return puntero a tipo de dato resultante de la evaluacion
 */
struct type * typecheck_expression_unary_logical(char *action, struct type *type, unsigned long line);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE TYPE CHECKING (NODOS AST) -----

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a una declaracion
 * @param decl : declaracion
 */
void typecheck_declaration(struct declaration *decl);

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a una sentencia
 * @param stmt : sentencia
 */
void typecheck_statement(struct statement *stmt);

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a un subprograma
 * @param subprog : subprograma
 */
void typecheck_subprogram(struct subprogram *subprog);

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a un proceso
 * @param proc : proceso
 */
void typecheck_process(struct process *proc);

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a un programa
 * @param prog : programa
 */
void typecheck_program(struct program *prog);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE TYPE CHECKING (LISTA NODOS AST) -----

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a una lista de declaraciones
 * @param list_decl : puntero a lista de declaraciones
 */
void typecheck_list_declarations(struct declaration *list_decl);

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a una lista de sentencias
 * @param list_statements : puntero a lista de sentencias
 */
void typecheck_list_statements(struct statement *list_statements);

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a una lista de subprogramas
 * @param list_subprograms : puntero a lista de subprogramas
 */
void typecheck_list_subprograms(struct subprogram *list_subprograms);

/**
 * @brief Aplica el algoritmo de comprobacion de tipos a una lista de procesos
 * @param list_process : puntero a lista de procesos
 */
void typecheck_list_process(struct process *list_process);

#ifdef __cplusplus
}
#endif

#endif //_LAMPORT_SEMANTIC_TYPE_CHECKING_DPR_