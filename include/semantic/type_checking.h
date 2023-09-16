/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file type_checking.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de funciones para implementar comprobacion de
 * tipos en el AST
 */

#ifndef _LAMPORT_SEMANTIC_TYPE_CHECKING_DPR_
#define _LAMPORT_SEMANTIC_TYPE_CHECKING_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "AST/AST.h"                ///< Abstract Syntax Tree (AST)
#include "error/error_manager.h"    ///< Gestor de errores

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE TYPE CHECKING (EXPRESIONES) -----

struct type * typecheck_expression(struct expression *expr);

struct type * typecheck_expression_binary(struct expression *expr);

struct type * typecheck_expression_unary(struct expression *expr);

struct type * typecheck_expression_identifier(struct expression *expr);

struct type * typecheck_expression_literal(struct expression *expr);

struct type * typecheck_expression_function_inv(struct expression *expr);

struct type * typecheck_expression_grouped(struct expression *expr);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE TYPE CHECKING (EXPRESIONES : DELIBERACIONES) -----

struct type * typecheck_expression_binary_arithmetic(char *action, struct type *type_left, struct type *type_right,unsigned long line);

struct type * typecheck_expression_binary_comparison(char *action, struct type *type_left, struct type *type_right,unsigned long line);

struct type * typecheck_expression_unary_arithmetic(char *action, struct type *type, unsigned long line);

struct type * typecheck_expression_unary_logical(char *action, struct type *type, unsigned long line);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE TYPE CHECKING (NODOS AST) -----

void typecheck_declaration(struct declaration *decl);

void typecheck_statement(struct statement *stmt);

void typecheck_subprogram(struct subprogram *subprog);

void typecheck_process(struct process *proc);

void typecheck_program(struct program *prog);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE TYPE CHECKING (LISTA NODOS AST) -----

void typecheck_list_declarations(struct declaration *list_decl);

void typecheck_list_statements(struct statement *list_statements);

void typecheck_list_subprograms(struct subprogram *list_subprograms);

void typecheck_list_process(struct process *list_process);


#endif //_LAMPORT_SEMANTIC_TYPE_CHECKING_DPR_