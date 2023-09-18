/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file print_assistant.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones de asistencia a la
 * impresion del AST del lenguaje lamport
 */

#ifndef _LAMPORT_AST_PRINT_ASSISTANT_DPR_
#define _LAMPORT_AST_PRINT_ASSISTANT_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ===============================================================

// ----- DEFINICION DE CONSTANTES DE IMPRESION -----

// Define el simbolo de inicio de identacion
extern const char IDENT_INIT_BRANCH_SYMBOL;

// Define el simbolo que se utilizara para la identacion (rama)
extern const char IDENT_BRANCH_SYMBOL;

// Define el simbolo que se utilizara para la identacion
extern const char IDENT_SYMBOL;

// Define la cabecera de nodo
extern const char * IDENT_ARROW;

// Define la identacion propia del nodo
extern const char * IDENT_BLANK_ARROW;

// Define un separador
extern const char * SEPARATOR;

// Define el mensaje por defecto cuando un nodo es nulo
extern const char * NULL_NODE_MSG;

// Define el mensaje por defecto para un valor indefinido
extern const char * UNDEFINED_VALUE_MSG;

// Define la profundidad inicial para las declaraciones de un programa
extern const unsigned int DEPTH_PROGRAM_DECLARATIONS;

// Define la profundidad inicial para los subprogramas de un programa
extern const unsigned int DEPTH_PROGRAM_SUBPROGRAMS;

// Define la profundidad inicial para los procesos de un programa
extern const unsigned int DEPTH_PROGRAM_PROCESS;

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE ASISTENCIA -----

/**
 * @brief Define la identacion de impresion de un nodo determinado a partir
 * de la profundidad a la que se encuentra
 * @param depth : profundidad del nodo
 * @param init_symbol : simbolo de inicio
 * @param symbol : simbolo de identacion
 * @return secuencia de symbol: 2*symbol*depth
 */
char * build_identation_using_depth(unsigned int depth, char init_symbol, char symbol);

/**
 * @brief Define la identacion de impresion de componentes de un nodo (espacios)
 * a partir de la profundidad a la que se espera
 * @param depth : profundidad del nodo
 * @return secuencia de IDENT_SYMBOL
 */
char * build_identation_spaces(unsigned int depth);

/**
 * @brief Define la identacion de cabecera de un nodo a partir de la profundidad
 * a la que se encuentra
 * @param depth : profundidad del nodo
 * @return secuencia de IDENT_BRANCH_SYMBOL
 */
char * build_identation_branch(unsigned int depth);

/**
 * @brief Imprime una separacion entre bloques del AST
 */
void print_AST_separation();

#endif //_LAMPORT_AST_PRINT_ASSISTANT_DPR_