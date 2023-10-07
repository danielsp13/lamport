/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file parameter.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO parametro
 */

#ifndef _LAMPORT_AST_PARAMETER_LIST_DPR_
#define _LAMPORT_AST_PARAMETER_LIST_DPR_

#ifdef __cplusplus
extern "C" {
#endif

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE NODO -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "type.h"               ///< Tipos de dato
#include "print_assistant.h"    ///< Asistencia de impresion de AST

#include "semantic/symbol.h"    ///< Simbolo (para resolucion de nombres)

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DEL AST (NODO DE LISTA DE PARAMETROS) -----

/**
 * @brief Estructura que representa a una lista de parametros de una funcion/procedimiento en lamport.
 * 
 * Esta estructura almacena informacion sobre los parametros de los que dispone una funcion
 * o un procedimiento, indicando el tipo de dato de todas ellas
 */
struct parameter{
    char *name_parameter;                   ///< Nombre de parametro
    struct type *type;                      ///< Tipo de parametro
    unsigned long line;                     ///< Linea donde se declaro el parametro
    struct parameter *next;            ///< Puntero a siguiente parametro

    struct symbol *symb;                    ///< Referencia al símbolo asociado en la tabla de símbolos.
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (LISTA DE PARAMETROS) -----

/**
 * @brief Crea y reserva memoria para crear una lista de parametros de funciones o proc
 * @param name_parameter : nombre del parametro
 * @param type : tipo del parametro
 * @param line : linea donde se declaro el parametro
 * @return puntero con la lista de parametros inicializada
 */
struct parameter * create_parameter(char * name_parameter, struct type * type, unsigned long line);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO LISTA DE PARAMETROS) ------

/**
 * @brief Libera la memoria asignada para un nodo de tipo lista de parametros
 * @param list_parameters : Puntero a nodo lista de parametros
 */
void free_list_parameters(struct parameter *list_parameters);

/**
 * @brief Libera la memoria para un nodo de tipo parametro
 * @param parameter : nodo parametro
 */
void free_parameter(struct parameter *parameter);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO PARAMETROS) -----

/**
 * @brief Imprime una lista de nodos de parametros
 * @param list_parameters : Puntero a lista enlazada de parametros
 * @param depth : Profundidad en la impresion de la lista de nodos
 * @param output : destino de impresion
 */
void print_AST_parameters(struct parameter *list_parameters, unsigned int depth, FILE * output);

#ifdef __cplusplus
}
#endif

#endif //_LAMPORT_AST_PARAMETER_LIST_DPR_