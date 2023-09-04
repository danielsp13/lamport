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

    // -- Comprobar reserva de memoria exitosa
    if(!proc)
        return NULL;

    // -- Asignar nombre de proceso
    proc->name_process = strdup(name_process);
    // -- Comprobar asignacion de nombre exitosa
    if(!proc->name_process){
        // -- Liberar memoria reservada para el proceso
        free(proc);
        return NULL;
    }

    // -- Asignar declaraciones del proceso
    proc->declarations = declarations;
    // -- Asignar sentencias del proceso
    proc->statements = statements;
    // -- Asignar puntero a siguiente proceso (NULL)
    proc->next = NULL;

    // -- Retornar proceso creado e inicializado
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
    if(proc->name_process){
        free(proc->name_process);
        proc->name_process = NULL;
    }

    // -- Liberar declaraciones de proceso
    if(proc->declarations){
        free_list_declarations(proc->declarations);
        proc->declarations = NULL;
    }

    // -- Liberar sentencias de proceso
    if(proc->statements){
        free_list_statements(proc->statements);
        proc->statements = NULL;
    }

    // -- Liberar nodo
    free(proc);
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO PROCESO) -----

void print_AST_process(struct process *process_list){
    const char *IDENT_ARROW = "---->";

    // -- Si NULL, simplemente devolver
    if(!process_list){
        printf(" %s <NONE>\n", IDENT_ARROW);
        return;
    }

    struct process *current_process = process_list;
    while(current_process){
        // -- Imprimir nombre de proceso
        printf(" %s NOMBRE DE PROCESO: [%s]\n", IDENT_ARROW, current_process->name_process);
        // -- Imprimir declaraciones de proceso
        printf(" %s DECLARACIONES DE PROCESO: [%s]\n", IDENT_ARROW, current_process->name_process);
        print_AST_declarations(current_process->declarations);
        // -- Imprimir sentencias de proceso
        printf(" %s SENTENCIAS DE PROCESO: [%s]\n", IDENT_ARROW, current_process->name_process);
        print_AST_statements(current_process->statements);

        printf("\n");

        // Ir al siguiente proceso
        current_process = current_process->next;
    }
}