/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file symbol.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * de un simbolo
 */

#ifndef _LAMPORT_SEMANTIC_SYMBOL_DPR_
#define _LAMPORT_SEMANTIC_SYMBOL_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "AST/type.h"           ///< Tipos

// ===============================================================

// ----- DEFINICION DE TIPOS DE SIMBOLOS ----

/**
 * @brief Estructura que representa los tipos de simbolos del lenguaje lamport
 */
typedef enum{
    SYMBOL_LOCAL,       ///< El simbolo es una variable local
    SYMBOL_PARAM,       ///< El simbolo es el parametro de una funcion/procedimiento
    SYMBOL_GLOBAL       ///< El simbolo es una variable global
} symbol_t;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURA SIMBOLO -----

/**
 * @brief Estructura que representa un simbolo de lamport
 * 
 * Esta estructura almacena informacion sobre un simbolo, que representa a la declaracion
 * de una variable en el lenguaje lamport. Consta de un tipo, un puntero al tipo de dato
 * del simbolo, el nombre del mismo y, en caso de que se trate de un simbolo de un
 * parametro de una funcion/procedimiento, la posicion que este ocupa.
 */
struct symbol{
    symbol_t kind;          ///< Tipo de simbolo
    char * kind_str;        ///< Tipo de simbolo (en formato string)
    struct type * type;     ///< Tipo de dato del simbolo
    char * name;            ///< Nombre del simbolo
    unsigned long line;     ///< Linea donde aparece el simbolo
    int which;              ///< Posicion en la lista de parametros (solo si kind = SYMBOL_PARAM)
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE CONSTRUCCION DE SIMBOLOS -----

/**
 * @brief Crea y reserva memoria para un simbolo
 * @param kind : Tipo de simbolo
 * @param type : Tipo de dato del simbolo
 * @param name : Nombre del simbolo
 * @param which : Posicion que ocupa en la lista de parametros (solo si kind = SYMBOL_PARAM)
 * @param line : linea donde aparece el simbolo
 * @return puntero a simbolo inicializado, NULL en otro caso
 */
struct symbol * create_symbol(symbol_t kind, struct type * type, char * name, int which, unsigned long line);

/**
 * @brief Crea y reserva memoria para un simbolo local
 * @param type : Tipo de dato del simbolo
 * @param name : Nombre del simbolo
 * @param line : linea donde aparece el simbolo
 * @return puntero a simbolo inicializado, NULL en otro caso
 */
struct symbol * create_symbol_local(struct type * type, char * name, unsigned long line);

/**
 * @brief Crea y reserva memoria para un simbolo global
 * @param type : Tipo de de dato del simbolo
 * @param name : Nombre del simbolo
 * @param line : linea donde aparece el simbolo
 * @return puntero a simbolo inicializado, NULL en otro caso
 */
struct symbol * create_symbol_global(struct type * type, char * name, unsigned long line);

/**
 * @brief Crea y reserva memoria para un simbolo de parametro de funcion/procedimiento
 * @param type : Tipo de dato del simbolo
 * @param name : Nombre del simbolo
 * @param which : Posicion que ocupa en la lista de parametros
 * @param line : linea donde aparece el simbolo
 * @return puntero a simbolo inicializado, NULL en otro caso
 */
struct symbol * create_symbol_param(struct type * type, char * name, int which, unsigned long line);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE LIBERACION DE MEMORIA DE SIMBOLOS -----

/**
 * @brief Libera la memoria asignada para un simbolo
 * @param symb : Simbolo a liberar
 */
void free_symbol(struct symbol * symb);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE IMPRESION DE SIMBOLOS -----

/**
 * @brief Imprime la infomacion de un simbolo
 * @param symb : Simbolo a imprimir
 */
void print_symbol(struct symbol * symb);

#endif //_LAMPORT_SEMANTIC_SYMBOL_DPR_