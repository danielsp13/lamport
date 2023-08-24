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

#include "declaration.h"        ///< Declaraciones
#include "statement.h"          ///< Sentencias

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
   char *name_process;                      ///< Nombre de proceso
   struct declaration *declarations;        ///< Declaraciones del proceso
   struct statement *statements;            ///< Sentencias del proceso
   struct process *next;                    ///< Puntero a siguiente proceso
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (PROCESOS) -----

/**
 * @brief Crea y reserva memoria para un proceso
 * @param name_process : Nombre de proceso
 * @param declarations : Lista de declaraciones del proceso
 * @param statements : Lista de sentencias
 * @return puntero con el proceso inicializado
 */
struct process * create_process(char *name_process, struct declaration *declarations, struct statement *statements);

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


#endif //_LAMPORT_AST_PROCESS_DPR_