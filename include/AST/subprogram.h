/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file subprogram.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO subprogramas
 */

#ifndef _LAMPORT_AST_SUBPROGRAM_DPR_
#define _LAMPORT_AST_SUBPROGRAM_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE NODO -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "declaration.h"    ///< Declaraciones
#include "statement.h"      ///< Sentencias
#include "type.h"           ///< Tipos

// ===============================================================

// ----- DEFINICION DE TIPOS DE SUBPROGRAMAS ----

/**
 * @brief Estructura que representa los tipos de subprogramas del lenguaje lamport.
 */
typedef enum{
    SUBPROGRAM_PROCEDURE,   ///< Definicion de un procedimiento
    SUBPROGRAM_FUNCTION     ///< Definicion de una funcion
} subprogram_t;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DEL AST (NODO SUBPROGRAMAS) -----

/**
 * @brief Estructura que representa a subprogramas de lamport
 * 
 * Esta estructura almacena informacion sobre un subprograma de lamport, que representa
 * a la declaracion de un proceso o de una funcion. Consta de un tipo, nombre de programa,
 * una lista de parametros y un conjunto de delcaraciones y sentencias. Si ademas es una
 * funcion, se indicara su tipo de retorno
 */
struct subprogram{
    subprogram_t kind;                      ///< Tipo de subprograma
    char *kind_str;                         ///< Tipo de subprograma (string)
    char *name_subprogram;                  ///< Nombre de subprograma
    struct parameter_list *parameters;      ///< Lista de parametros del subprograma
    struct declaration *declarations;       ///< Declaraciones del subprograma
    struct statement *statements;           ///< Sentencias del programa
    struct type *type;                      ///< Tipo de retorno (solo funciones)
    struct subprogram *next;                ///< Puntero a siguiente subprograma
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (SUBPROGRAMAS Y PROCESOS) -----

/**
 * @brief Crea y reserva memoria para crear un subprograma
 * @param kind : Tipo de subprograma (PROCEDURE o FUNCTION)
 * @param name_subprogram : Nombre de subprograma
 * @param parameters : Lista de parametros
 * @param declarations : Lista de declaraciones
 * @param statements : Lista de sentencias
 * @param type : Tipo de funcion
 * @return puntero con el subprograma inicializado
 */
struct subprogram * create_subprogram(subprogram_t kind, char *name_subprogram, struct parameter_list *parameters, struct declaration *declarations, struct statement *statements, struct type *type);

/**
 * @brief Crea y reserva memoria para crear un subprograma de tipo procedure
 * @param name_procedure : Nombre del procedimiento
 * @param parameters : Lista de parametros
 * @param declarations : Lista de declaraciones
 * @param statements : Lista de sentencias
 * @return puntero con el procedimiento inicializado
 */
struct subprogram * create_subprogram_procedure(char *name_procedure, struct parameter_list *parameters, struct declaration *declarations, struct statement *statements);

/**
 * @brief Crea y reserva memoria para crear un subprograma de tipo funcion
 * @param name_function : Nombre de funcion
 * @param parameters : Lista de parametros
 * @param declarations : Lista de declaraciones
 * @param statements : Lista de sentencias
 * @return puntero con la funcion inicializada
 */
struct subprogram * create_subprogram_function(char *name_function, struct parameter_list *parameters, struct declaration *declarations, struct statement *statements, struct type *type);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO SUBPROGRAMAS) ------

/**
 * @brief Libera la memoria asignada para una lista de subprogramas
 * @param subprograms_list : Puntero a lista enlazada de subprogramas
 */
void free_list_subprograms(struct subprogram *subprograms_list);

/**
 * @brief Libera la memoria asignada para un nodo de tipo subprograma
 * @param subprog : Puntero a nodo subprograma
 */
void free_subprogram(struct subprogram *subprog);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO EXPRESIONES) -----

/**
 * @brief Imprime una lista de nodos de subprogramas
 * @param subprograms_list : Puntero a lista enlazada de subprogramas
 */
void print_AST_subprograms(struct subprogram *subprograms_list);

#endif //_LAMPORT_AST_SUBPROGRAM_DPR_