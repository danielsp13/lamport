/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file AST.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles)
 */

#ifndef _LAMPORT_AST_DPR_
#define _LAMPORT_AST_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DEL AST -----

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "declaration.h"        ///< Declaraciones
#include "subprogram.h"         ///< Subprogramas
#include "process.h"            ///< Procesos
#include "print_assistant.h"    ///< Asistencia de impresion de AST

// ===============================================================

// ----- DEFINICION DE TIPOS DE ESTRUCTURAS DEL AST (NODO RAIZ) -----

/**
 * @brief Estructura que representa a un programa completo en lamport.
 * 
 * Esta estructura almacena informacion sobre un programa escrito en el lenguaje lamport.
 * Consta de un nombre de programa, seguido de una lista de declaraciones, subprogramas
 * y procesos. Es el nodo principal del AST.
 */
struct program{
    char *name_program;                     ///< Nombre de programa
    struct declaration *declarations;       ///< Declaraciones del programa
    struct subprogram *subprograms;         ///< Subprogramas
    struct process *process;                ///< Procesos del programa
};

// ===============================================================

// ----- DEFINICION DE AST -----

extern struct program * AST_program;

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (PROGRAMAS) -----

/**
 * @brief Crea y reserva memoria para un programa
 * @param name_program : Nombre de programa
 * @param declarations : Lista de declaraciones
 * @param subprograms : Lista de subprogramas
 * @param process : Lista de procesos
 * @return puntero con el programa inicializado
 */
struct program * create_program(char *name_program, struct declaration *declarations, struct subprogram *subprograms, struct process *process);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST -----

/**
 * @brief Libera la memoria asignada para la construccion del AST del programa completo
 * @param prog : Puntero a AST (prog -> nodo raiz)
 */
void free_program(struct program *prog);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST -----

/**
 * @brief Imprime el AST en pantalla
 * @param prog : Puntero a AST (prog -> nodo raiz)
 */
void print_AST(struct program *prog);


#endif //_LAMPORT_AST_DPR_