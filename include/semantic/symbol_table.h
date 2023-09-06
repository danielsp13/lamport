/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file symbol_table.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * de una tabla de simbolos
 */

#ifndef _LAMPORT_SEMANTIC_SYMBOL_TABLE_DPR_
#define _LAMPORT_SEMANTIC_SYMBOL_TABLE_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "scope_stack.h"        ///< Pila de tablas hash
#include "symbol.h"             ///< Simbolo

// ===============================================================

// ----- DEFINICION DE CONSTANTES DE CONTROL -----

#define SYMB_TABLE_OPERATION_SUCCESS 0          ///< Resultado de operacion en tabla de simbolos exitosa
#define SYMB_TABLE_INIT_FAILURE -1              ///< Resultado de inicializacion de tabla de simbolos fallida
#define SYMB_TABLE_PUSH_SCOPE_FAILURE -2        ///< Resultado de insercion de scope en tabla de simbolos fallido
#define SYMB_TABLE_POP_SCOPE_FAILURE -3         ///< Resultado de eliminacion de scope actual de tabla de simbolos fallida
#define SYMB_TABLE_SCOPE_LEVEL_FAILURE -4       ///< Resultado de obtencion de niveles de scope fallido
#define SYMB_TABLE_FREE_FAILURE -5              ///< Resultado de liberacion de tabla de simbolos fallida
#define SYMB_TABLE_BIND_SYMBOL_FAILURE -6       ///< Resultado de inclusion de simbolo en scope fallida

// ===============================================================

// ----- DEFINICION DE VARIABLE GLOBAL TABLA DE SIMBOLOS (SYMBOL_TABLE) -----

// Variable global encargada de definir la tabla de simbolos
extern struct scope_stack * symbol_table;

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE TABLA DE SIMBOLOS -----

/**
 * @brief Inicializa la tabla de simbolos
 */
int initialize_symbol_table();

/**
 * @brief Crea un nuevo scope y lo inserta en la tabla de simbolos
 */
int push_scope_to_symbol_table();

/**
 * @brief Elimina el scope actual del tope de pila
 */
int remove_current_scope_from_symbol_table();

/**
 * @brief Obtiene el numero de scopes actuales existentes en la pila
 * @return numero de scopes
 */
int scope_level();

/**
 * @brief Obtiene el scope actual
 * @return scope actual (tope de la pila), NULL en otro caso
 */
scope * get_current_scope();

/**
 * @brief Obtiene el scope de la pila a partir de su posicion en la misma
 * @param index : posicion del scope
 * @return scope requerido, NULL en otro caso
 */
scope * get_scope_from_index(unsigned int index);

/**
 * @brief Incluye un nuevo simbolo en el scope actual (el tope de la tabla de simbolos)
 * @param symb : simbolo a incluir
 */
int bind_symbol_to_scope(struct symbol * symb);

/**
 * @brief Busca un determinado simbolo a partir de su nombre en el scope actual
 * @param name : nombre de simbolo (actua como llave de registro de tabla hash)
 * @return puntero a simbolo que coincide con la busqueda, NULL en otro caso
 */
struct symbol * lookup_symbol_from_current_scope(char * name);

/**
 * @brief Busca un determinado simbolo a partir de su nombre en un scope especifico
 * @param name : nombre de simbolo (actua como llave de registro de tabla hash)
 * @param index : indice de scope sobre el que buscar
 * @return puntero a simbolo que coincide con la busqueda, NULL en otro caso
 */
struct symbol * lookup_symbol_from_specific_scope(char * name, int index);

/**
 * @brief Busca un determinado simbolo a partir de su nombre en todos los scopes
 * Empieza primero buscando en el scope actual, y si no hay resultado, busca en el resto
 * @param name : nombre del simbolo (actua como llave de registro de tabla hash)
 * @return puntero a simbolo que coincide con la busqueda, NULL en otro caso
 */
struct symbol * lookup_symbol_from_all_scopes(char * name);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE LIBERACION DE TABLA DE SIMBOLOS -----

/**
 * @brief Libera la tabla de simbolos utilizada
 */
int free_symbol_table();

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE IMPRESION DE TABLA DE SIMBOLOS -----

/**
 * @brief Imprime la tabla de simbolos
 */
void print_symbol_table();

#endif //_LAMPORT_SEMANTIC_SYMBOL_TABLE_DPR_