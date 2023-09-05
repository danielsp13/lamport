/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file type.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO tipos y NODO lista parametros
 */

#ifndef _LAMPORT_AST_TYPE_DPR_
#define _LAMPORT_AST_TYPE_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE NODO -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "expression.h"         ///< Expresiones

// ===============================================================

// ----- DEFINICION DE TIPOS DE DATO -----

/**
 * @brief Estructura que representa los tipos de datos del lenguaje de lamport.
 */
typedef enum{
    TYPE_INTEGER,           ///< Tipo de dato entero
    TYPE_BOOLEAN,           ///< Tipo de dato booleano
    TYPE_CHAR,              ///< Tipo de dato caracter
    TYPE_STRING,            ///< Tipo de dato cadena de caracteres
    TYPE_REAL,              ///< Tipo de dato flotante
    TYPE_ARRAY,             ///< Tipo de dato array
    TYPE_SEMAPHORE,         ///< Tipo de dato semaforo
    TYPE_DPROCESS,          ///< Tipo de dato proceso dinamico
    TYPE_FUNCTION           ///< Tipo de dato de funciones
} type_t;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DEL AST (NODO DE TIPOS) -----

/**
 * @brief Estructura que representa a un tipo de dato en lamport.
 * 
 * Esta estructura almacena informacion sobre un tipo de dato de una variable
 * o de una funcion mencionada en una declaracion, en el lenguaje lamport.
 * 
 * Dependiendo del tipo de dato, se requerira mas informacion adicional
 * para describir adecuadamente el valor de la variable o el retorno de la funcion.
 * 
 * TIPOS DE DATO BASICOS
 *   -> Son tipos de datos simples, conocidos:
 *   -> Lista:
 *      ///> INTEGER
 *      ///> REAL
 *      ///> BOOLEAN
 *      ///> CHAR
 *      ///> STRING
 * 
 * TIPOS DE DATO COMPUESTOS
 *   -> Son tipos de datos especiales que requieren mas informacion
 *   -> Lista:
 *      ///> ARRAY
 *      ///> SEMAPHORE
 *      ///> DPROCESS
 */
struct type{
    type_t kind;                            ///< Tipo de dato
    char *kind_str;                         ///< Tipo de dato (en formato string)
    struct type *subtype;                   ///< Subtipo de dato (arrays y funciones)
    struct expression *size;                ///< Size de dato (arrays)
    struct parameter_list *parameters;      ///< Lista de parametros (para funciones)
};

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DEL AST (NODO DE LISTA DE PARAMETROS) -----

/**
 * @brief Estructura que representa a una lista de parametros de una funcion/procedimiento en lamport.
 * 
 * Esta estructura almacena informacion sobre los parametros de los que dispone una funcion
 * o un procedimiento, indicando el tipo de dato de todas ellas
 */
struct parameter_list{
    char *name_parameter;                   ///< Nombre de parametro
    struct type *type;                      ///< Tipo de parametro
    struct parameter_list *next;            ///< Puntero a siguiente parametro
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (TIPOS) -----

/**
 * @brief Crea y reserva memoria para un tipo de dato de tipo basico
 * @param kind : tipo de dato
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_basic_type(type_t kind);

/**
 * @brief Crea y reserva memoria para el tipo de dato de una funcion
 * @param subtype : subtipo de dato (para especificar el retorno de la funcion)
 * @param parameters : parametros de la funcion
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_function_type(struct type *subtype, struct parameter_list *parameters);

/**
 * @brief Crea y reserva memoria para el tipo de dato de array
 * @param subtype : tipo de dato almacenado en el array
 * @param size : dimension del array
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_array_type(struct type *subtype, struct expression *size);

/**
 * @brief Crea y reserva memoria para el tipo de dato semaphore
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_semaphore_type();

/**
 * @brief Crea y reserva memoria para el tipo de dato proceso dinamico
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_dprocess_type();

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (LISTA DE PARAMETROS) -----

/**
 * @brief Crea y reserva memoria para crear una lista de parametros de funciones o proc
 * @param name_parameter : nombre del parametro
 * @param type : tipo del parametro
 * @return puntero con la lista de parametros inicializada
 */
struct parameter_list * create_parameter_list(char * name_parameter, struct type * type);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO TIPOS) ------

/**
 * @brief Libera la memoria asignada para un nodo de tipo type
 * @param type : Puntero a nodo tipo
 */
void free_type(struct type *type);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO LISTA DE PARAMETROS) ------

/**
 * @brief Libera la memoria asignada para un nodo de tipo lista de parametros
 * @param parameter_list : Puntero a nodo lista de parametros
 */
void free_list_parameters(struct parameter_list *parameter_list);

/**
 * @brief Libera la memoria para un nodo de tipo parametro
 * @param parameter : Puntero a nodo parametro
 */
void free_parameter(struct parameter_list *parameter);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO TIPOS) -----

/**
 * @brief Imprime un nodo de tipo de dato
 * @param type : Puntero a nodo tipo
 */
void print_AST_type(struct type *type);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO PARAMETROS) -----

/**
 * @brief Imprime una lista de nodos de parametros
 * @param parameters_list : Puntero a lista enlazada de parametros
 */
void print_AST_parameters(struct parameter_list *parameters_list);


#endif //_LAMPORT_AST_TYPE_DPR_