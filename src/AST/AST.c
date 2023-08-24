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

    prog->name_program = strdup(name_program);
    if(!prog->name_program){
        free(prog->name_program);
        return NULL;
    }

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

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST -----

void print_AST(struct program *prog){
    const char *IDENT_ARROW = "-->";

    // -- Si NULL, simplemente devolver
    if(!prog){
        printf(" %s <NONE>\n", IDENT_ARROW);
        return;
    }

    // -- Imprimir nombre de programa
    printf(" %s PROGRAMA LAMPORT DE NOMBRE: [%s]\n", IDENT_ARROW, prog->name_program);

    // -- Imprimir declaraciones
    printf(" %s DECLARACIONES DE PROGRAMA: [%s]\n", IDENT_ARROW, prog->name_program);
    print_AST_declarations(prog->declarations);

    printf("\n");

    // -- Imprimir subprogramas
    printf(" %s SUBPROGRAMAS DE PROGRAMA: [%s]\n", IDENT_ARROW, prog->name_program);
    print_AST_subprograms(prog->subprograms);

    printf("\n");

    // -- Imprimir sentencias
    printf(" %s PROCESOS DEL PROGRAMA: [%s]\n", IDENT_ARROW, prog->name_program);
    print_AST_process(prog->process);
}