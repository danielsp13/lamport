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

    // -- Comprobar reserva de memoria exitosa
    if(!prog)
        return NULL;

    // -- Asignar nombre de programa
    prog->name_program = strdup(name_program);
    // -- Comprobar asignacion de nombre de programa exitosa
    if(!prog->name_program){
        // -- Liberar memoria reservada al programa
        free(prog);
        return NULL;
    }

    // -- Asignar declaraciones del programa
    prog->declarations = declarations;
    // -- Asignar subprogramas del programa
    prog->subprograms = subprograms;
    // -- Asignar procesos del programa
    prog->process = process;

    // -- Retornar programa creado e inicializado
    return prog;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST -----

void free_program(struct program *prog){
    // -- Si NULL, simplemente devolver
    if(!prog)
        return;

    // -- Liberacion del nombre del programa
    if(prog->name_program){
        free(prog->name_program);
        prog->name_program = NULL;
    }

    // -- Liberacion de declaraciones
    if(prog->declarations){
        free_list_declarations(prog->declarations);
        prog->declarations = NULL;
    }

    // -- Liberacion de subprogramas
    if(prog->subprograms){
        free_list_subprograms(prog->subprograms);
        prog->subprograms = NULL;
    }

    // -- Liberacion de procesos
    if(prog->process){
        free_list_process(prog->process);
        prog->process = NULL;
    }

    // -- Liberar nodo raiz programa
    free(prog);
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST -----

void print_AST(struct program *prog, FILE * output){
    // -- Comprobar que hay salida valida
    if(!output)
        return;

    // -- Si NULL, simplemente devolver
    if(!prog){
        fprintf(output,"%s %s\n", IDENT_ARROW, NULL_NODE_MSG);
        return;
    }

    // -- Imprimir nombre de programa
    fprintf(output,"%s PROGRAMA LAMPORT DE NOMBRE: [%s]\n", IDENT_ARROW, prog->name_program);

    print_AST_separation(output);

    // -- Imprimir declaraciones
    fprintf(output,"%s %c DECLARACIONES DE PROGRAMA: [%s]\n", IDENT_ARROW, IDENT_INIT_BRANCH_SYMBOL, prog->name_program);
    print_AST_declarations(prog->declarations, DEPTH_PROGRAM_DECLARATIONS,output);

    print_AST_separation(output);

    // -- Imprimir subprogramas
    fprintf(output,"%s %c SUBPROGRAMAS DE PROGRAMA: [%s]\n", IDENT_ARROW, IDENT_INIT_BRANCH_SYMBOL, prog->name_program);
    print_AST_subprograms(prog->subprograms, DEPTH_PROGRAM_SUBPROGRAMS,output);

    print_AST_separation(output);

    // -- Imprimir sentencias
    fprintf(output,"%s %c PROCESOS DEL PROGRAMA: [%s]\n", IDENT_ARROW, IDENT_INIT_BRANCH_SYMBOL, prog->name_program);
    print_AST_process(prog->process, DEPTH_PROGRAM_PROCESS,output);
}