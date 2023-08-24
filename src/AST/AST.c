/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file AST.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles)
 */

#include "AST/AST.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (PROGRAMAS) -----

struct program * create_program(char *name_program, struct declaration *declarations, struct subprogram *subprograms, struct process *process){
    struct program *prog = malloc(sizeof(*prog));

    if(!prog)
        return NULL;

    prog->name_program = name_program;
    prog->declarations = declarations;
    prog->subprograms = subprograms;
    prog->process = process;

    return prog;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST -----

void free_program(struct program *prog){
    // -- Si NULL, simplemente devolver
    if(!prog)
        return;

    // -- Liberacion del nombre del programa
    if(prog->name_program)
        free(prog->name_program);

    // -- Liberacion de declaraciones
    if(prog->declarations)
        free_list_declarations(prog->declarations);

    // -- Liberacion de subprogramas
    if(prog->subprograms)
        free_list_subprograms(prog->subprograms);

    // -- Liberacion de procesos
    if(prog->process)
        free_list_process(prog->process);

    // -- Liberar nodo raiz programa
    free(prog);
}