/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file scope.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * de un ambito (scope)
 */

#ifndef _LAMPORT_SEMANTIC_SCOPE_DPR_
#define _LAMPORT_SEMANTIC_SCOPE_DPR_

#ifdef __cplusplus
extern "C" {
#endif

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "symbol.h"           ///< Simbolo

// ===============================================================

// ----- DEFINICION DE ESTRUCTURA HASH MAP (SCOPE) -----

/**
 * @brief Define la dimension maxima de la tabla hash (scope).
 * El hecho de que la dimension sea un numero primo es para reducir
 * el numero de colisiones que se puedan producir, ademas de ayudar
 * a que las claves se distribuyan uniformemente.
 * 
 * Se ha decidido elegir este numero en particular para proporcionar
 * un margen adecuado para la gestion de hast 100 simbolos por scope 
 */
#define MAX_SCOPE_SIZE 151          ///< Dimension de la tabla hash


#define SCOPE_OPERATION_SUCCESS 0   ///< Indica resultado de operacion exitosa sobre scope
#define SCOPE_OPERATION_FAILURE -1  ///< Indica resultado de operacion fallida sobre scope

/**
 * @brief Estructura que representa una entrada de la tabla hash.
 */
typedef struct entry{
    char * key;                     ///< Llave de entrada (nombre de simbolo/variable)
    struct symbol * value;          ///< Puntero al simbolo almacenado
    struct entry * next;            ///< 
} entry;

/**
 * @brief Estructura que representa un ambito (scope)
 */
typedef struct HashMap{
    entry * table[MAX_SCOPE_SIZE];  ///< Tabla hash
} scope;

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE ENTRADAS -----

/**
 * @brief Crea y reserva memoria para una entrada nueva de la tabla hash
 * @param key : clave de registro
 * @param value : valor de registro
 * @return puntero a entrada creado e inicializado, NULL en otro caso
 */
entry * create_entry(char * key, struct symbol * value);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE SCOPES -----

/**
 * @brief Funcion hash que obtiene la llave de la entrada y devuelve
 * el indice donde se encuentra la entrada dentro de la tabla (metodo de horner)
 * @param key : llave de la entrada
 * @return indice de tabla
 */
unsigned int hash(char * key);

/**
 * @brief Crea y reserva memoria para un nuevo scope
 * @return puntero a scope creado e inicializado
 */
scope * create_scope();

/**
 * @brief Inserta un nuevo simbolo en el scope
 * @param scope : tabla hash donde se realizara la insercion
 * @param value : simbolo a insertar
 * @return SCOPE_OPERATION_SUCCESS si se realizo con exito, SCOPE_OPERATION_FAILURE en otro caso
 */
int insert_symbol_into_scope(scope * scope, struct symbol * value);

/**
 * @brief Obtiene un slot completo del scope a partir de un indice de slot
 * @param scope : tabla hash
 * @param index : indice de slot
 * @return puntero a lista enlazada de entradas (slot) a las que corresponde dicha clave, NULL en otro caso
 */
entry * get_slot_from_scope_using_index(scope * scope, unsigned int index);

/**
 * @brief Obtiene un slot completo del scope a partir de una clave de registro
 * @param scope : tabla hash
 * @param key : clave de registro
 * @return puntero a la lista enlazada de entradas (slot) a las que corresponde dicha clave, NULL en otro aso
 */
entry * get_slot_from_scope_using_key(scope * scope, char * key);

/**
 * @brief Obtiene una entrada de la tabla hash a partir de su clave de registro
 * @param scope : tabla hash donde se realizara la busqueda
 * @param key : clave de registro de entrada
 * @return entrada pedida, NULL en otro caso
 */
entry * get_entry_from_scope(scope * scope, char * key);

/**
 * @brief Obtiene un simbolo de la tabla hash a partir de su clave de registro
 * @param scope : tabla hash donde se realizara la busqueda
 * @param key : clave de registro de entrada
 * @return simbolo pedido, NULL en otro caso
 */
struct symbol * get_symbol_from_scope(scope * scope, char * key);

/**
 * @brief Elimina un simbolo de la tabla hash a partir de su clave de registro
 * @param scope : tabla donde se realizara la eliminacion
 * @param key : clave de registro de entrada
 */
void remove_symbol_from_scope(scope * scope, char * key);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE LIBERACION DE ENTRADAS -----

/**
 * @brief Libera la memoria utilizada para una lista de entradas (slot)
 * @param list_entry : lista de entradas
 */
void free_list_entry(entry * list_entry);

/**
 * @brief Libera la memoria utilizada para una entrada
 * @param entry : entrada a liberar
 */
void free_entry(entry * entry);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE LIBERACION DE SCOPES -----

/**
 * @brief Libera la memoria utilizada para el scope
 * @param scope : tabla hash a liberar
 */
void free_scope(scope * scope);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE IMPRESION DE ENTRADAS -----

/**
 * @brief Imprime el contenido de una lista de entradas
 * @param list_entry : lista de entradas
 * @param index : Indice de entrada
 */
void print_list_entry(entry * list_entry, int index);

/**
 * @brief Imprime el contenido de una entrada
 * @param entry : entrada
 */
void print_entry(entry * entry);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE IMPRESION DE SCOPES -----

/**
 * @brief Imprime el contenido de la tabla hash
 * @param scope : tabla hash
 */
void print_scope(scope * scope);

#ifdef __cplusplus
}
#endif

#endif //_LAMPORT_SEMANTIC_SCOPE_DPR_