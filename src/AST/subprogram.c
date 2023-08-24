/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file subprogram.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO subprogramas
 */

#include "AST/subprogram.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (SUBPROGRAMAS) -----

struct subprogram * create_subprogram(subprogram_t kind, char *name_subprogram, struct parameter_list *parameters, struct declaration *declarations, struct statement *statements, struct type *type){
    struct subprogram *subprog = malloc(sizeof(*subprog));

    if(!subprog)
        return NULL;

    subprog->kind = kind;
    subprog->name_subprogram = name_subprogram;
    subprog->parameters = parameters;
    subprog->declarations = declarations;
    subprog->statements = statements;
    subprog->type = type;
    subprog->next = NULL;

    return subprog;
}

struct subprogram * create_subprogram_procedure(char *name_procedure, struct parameter_list *parameters, struct declaration *declarations, struct statement *statements){
    return create_subprogram(SUBPROGRAM_PROCEDURE, name_procedure, parameters, declarations, statements, NULL);
}

struct subprogram * create_subprogram_function(char *name_function, struct parameter_list *parameters, struct declaration *declarations, struct statement *statements, struct type *type){
    return create_subprogram(SUBPROGRAM_FUNCTION, name_function, parameters, declarations, statements, type);   
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO SUBPROGRAMAS) -----

void free_list_subprograms(struct subprogram *subprograms_list){
    struct subprogram *current_subprogram = subprograms_list;
    while(current_subprogram){
        // -- Seleccionar siguiente en la lista
        struct subprogram *next = current_subprogram->next;
        // -- Liberar nodo
        free_subprogram(current_subprogram);
        // -- Nodo actual -> siguiente
        current_subprogram = next;
    }
}

void free_subprogram(struct subprogram *subprog){
    // -- Si NULL, simplemente devolver
    if(!subprog)
        return;

    // -- Liberar nombre de subprograma
    if(subprog->name_subprogram)
        free(subprog->name_subprogram);

    // -- Liberar tipo de subprograma (solo para funciones)
    if(subprog->type)
        free_type(subprog->type);

    // -- Liberar declaraciones del subprograma
    if(subprog->declarations)
        free_list_declarations(subprog->declarations);

    // -- Liberar
    if(subprog->parameters)
        free_list_parameters(subprog->parameters);

    // -- Liberar
    if(subprog->statements)
        free_list_statements(subprog->statements);

    
    // -- Liberar nodo
    free(subprog);
}