/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file process.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO procesos
 */

#ifndef _LAMPORT_AST_PROCESS_DPR_
#define _LAMPORT_AST_PROCESS_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE NODO -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "declaration.h"         ///< Declaraciones
#include "statement.h"           ///< Sentencias
#include "expression.h"          ///< Expresiones
#include "print_assistant.h"     ///< Asistencia de impresion de AST

#include "semantic/symbol.h"    ///< Simbolo (para resolucion de nombres)

// ===============================================================

// ----- DEFINICION DE TIPOS DE PROCESOS -----

/**
 * @brief Estructura que representa los diferentes tipos de procesos de lamport
 */
typedef enum{
   PROCESS_SINGLE,         ///< Indica un proceso individual
   PROCESS_VECTOR          ///< Indica un vector de procesos
} process_t;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DEL AST (NODO PROCESOS) -----

/**
 * @brief Estructura que representa un proceso de lamport.
 * 
 * Esta estructura almacena informacion sobre un proceso de lamport. Consta de un
 * nombre de proceso, seguido de una serie de declaraciones y un bloque de sentencias
 * de ejecucion del proceso
 */
struct process{
   process_t kind;                           ///< Tipo de proceso
   char *kind_str;                           ///< Tipo de proceso (str)

   char *name_process;                       ///< Nombre de proceso
   struct declaration *declarations;         ///< Declaraciones del proceso
   struct statement *statements;             ///< Sentencias del proceso

   char *index_identifier;                   ///< Identificador del índice (si es un vector)
   struct expression *index_start;           ///< Puntero al nodo de expresion de inicio
   struct expression *index_end;             ///< Puntero al nodo de expresion final

   struct symbol *symb_process;              ///< Referencia al símbolo asociado en la tabla de símbolos. (nombre de proceso)
   struct symbol *symb_index;                ///< Referencia al simbolo asociado en la tabla de simbolos. (indice)

   struct process *next;                     ///< Puntero a siguiente proceso
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (PROCESOS) -----

/**
 * @brief Crea y reserva memoria para un proceso
 * @param kind : Tipo de proceso
 * @param name_process : Nombre de proceso
 * @param declarations : Lista de declaraciones del proceso
 * @param statements : Lista de sentencias
 * @return puntero con el proceso inicializado
 */
struct process * create_process(process_t kind, char *name_process, struct declaration *declarations, struct statement *statements);

/**
 * @brief Crea y reserva memoria para un proceso individual
 * @param name_process : Nombre de proceso
 * @param declarations : Lista de declaraciones del proceso
 * @param statements : Lista de sentencias
 * @return puntero con el proceso inicializado
 */
struct process * create_process_single(char *name_process, struct declaration *declarations, struct statement *statements);

/**
 * @brief Crea y reserva memoria para un vector de procesos
 * @param name_process : Nombre de proceso
 * @param declarations : Lista de declaraciones del proceso
 * @param statements : Lista de sentencias del proceso
 * @param index_identifier : Identificador utilizado para indexar el vector de procesos.
 * @param index_start : Expresión que define el inicio del rango del vector de procesos (debe evaluarse a un valor entero).
 * @param index_end : Expresión que define el final del rango del vector de procesos (debe evaluarse a un valor entero).
 * @return puntero con el proceso inicializado
 */
struct process * create_process_vector(char *name_process, struct declaration *declarations, struct statement *statements, char *index_identifier, struct expression *index_start, struct expression *index_end);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO PROCESOS) ------

/**
 * @brief Libera la memoria asignada para una lista de procesos
 * @param process_list : Puntero a lista enlazada de procesos
 */
void free_list_process(struct process *process_list);

/**
 * @brief Libera la memoria asignada para un nodo de tipo proceso
 * @param proc : Puntero a nodo proceso
 */
void free_process(struct process *proc);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO PROCESOS) -----

/**
 * @brief Imprime una lista de nodos de procesos
 * @param process_list : Puntero a lista enlazada de procesos
 * @param depth : Profundidad en la impresion de la lista de nodos
 */
void print_AST_process(struct process *process_list, unsigned int depth);

#endif //_LAMPORT_AST_PROCESS_DPR_