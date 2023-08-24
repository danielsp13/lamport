/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file process.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO procesos
 */

#include "AST/process.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (PROCESOS) -----

struct process * create_process(char *name_process, struct declaration *declarations, struct statement *statements){
    struct process *proc = malloc(sizeof(*proc));

    if(!proc)
        return NULL;

    proc->name_process = name_process;
    proc->declarations = declarations;
    proc->statements = statements;
    proc->next = NULL;

    return proc;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO PROCESOS) -----

void free_list_process(struct process *process_list){
    struct process *current_process = process_list;
    while(current_process){
        // -- Seleccionar siguiente en la lista
        struct process *next = current_process->next;
        // -- Liberar nodo
        free_process(current_process);
        // -- Nodo actual -> siguiente
        current_process = next;
    }
}

void free_process(struct process *proc){
    // -- Si NULL, simplemente devolver
    if(!proc)
        return;

    // -- Liberar nombre de proceso
    if(proc->name_process)
        free(proc->name_process);

    // -- Liberar declaraciones de proceso
    if(proc->declarations)
        free_list_declarations(proc->declarations);

    // -- Liberar sentencias de proceso
    if(proc->statements){
        free_list_statements(proc->statements);
    }

    // -- Liberar nodo
    free(proc);
}