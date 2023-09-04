/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file scope_stack.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * de una pila de tablas hash (scope)
 */

#ifndef _LAMPORT_SEMANTIC_SCOPE_STACK_DPR_
#define _LAMPORT_SEMANTIC_SCOPE_STACK_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "scope.h"            ///< Ambito de simbolo (scope)

// ===============================================================

// ----- DEFINICION DE ESTRUCTURA STACK (SCOPE_STACK) -----

/**
 * @brief Estructura que representa un nodo de la pila utilizada para
 * definir la tabla de simbolos.
 * 
 * Consta del almacenamiento de un scope y de un puntero al siguiente
 * nodo de la pila
 */
struct node_stack{
    scope * scope;              ///< Puntero a scope
    struct node_stack * next;   ///< Puntero a siguiente nodo de pila
};

/**
 * @brief Estructura que representa a una pila en C, utilizada para
 * definir la tabla de simbolos del lenguaje
 * 
 * Consta de un puntero al tope de pila y un contador del total
 * de scopes existentes en un mismo momento.
 */
struct scope_stack{
    unsigned int num_scopes;    ///< Total de scopes actuales en la pila
    struct node_stack * top;           ///< Puntero al tope de pila
} ;

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE UN NODO (NODE_STACK) -----

/**
 * @brief Crea un nuevo nodo para la pila
 * @param scope : scope (tabla hash)
 * @return puntero a nodo de pila creado e inicializado, NULL en otro caso
 */
struct node_stack * create_node_stack(scope * scope);


// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE UNA PILA (STACK) -----

/**
 * @brief Crea y reserva memoria para crear una pila nuea
 * @return puntero a la pila creado e inicializado, NULL en otro caso
 */
struct scope_stack* create_scope_stack();

/**
 * @brief Inserta un nuevo nodo en el tope de la pila
 * @param st : pila donde se realizara la insercion
 * @param node : nodo a insertar en la pila
 */
void push_scope_stack(struct scope_stack* st, struct node_stack * node);

/**
 * @brief Elimina el tope de pila
 * @param st : pila donde se realizara la eliminacion
 */
void pop_scope_stack(struct scope_stack* st);

/**
 * @brief Obtiene el total de elementos de la pila
 * @param st : pila
 * @return numero de elementos de la pila
 */
unsigned int get_size_scope_stack(struct scope_stack* st);

/**
 * @brief Obtiene el tope de la pila
 * @param st : pila
 * @return puntero al tope de la pila
 */
struct node_stack * get_top_scope_stack(struct scope_stack* st);

/**
 * @brief Comprueba si la pila esta vacia
 * @param st : pila
 * @return true (1) si pila vacia, false (0) en otro caso
 */
unsigned int empty_scope_stack(struct scope_stack* st);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE LIBERACION DE UN NODO (NODE_STACK) -----

/**
 * @brief Libera la memoria reservada para un nodo de pila
 * @param node : nodo de pila
 */
void free_node_stack(struct node_stack * node);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE LIBERACION DE UNA PILA (STACK) -----

/**
 * @brief Libera la memoria reservada para la pila
 * @param st : pila
 */
void free_scope_stack(struct scope_stack * st);


// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE IMPRESION DE UNA PILA (STACK) -----

/**
 * @brief Imprime la pila de scopes
 * @param st : pila
 */
void print_scope_stack(struct scope_stack * st);


#endif //_LAMPORT_SEMANTIC_SCOPE_STACK_DPR_