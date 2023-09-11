/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file error_manager.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para gestion de errores
 * producidos en la compilacion. Gestor de errores general.
 */

#include "error/error_manager.h"

// ===============================================================

// ----- DEFINICION DE VARIABLES DE CONTROL -----

// Cuenta el total de errores sintacticos producidos
unsigned long TOTAL_SYNTAX_ERRORS = 0;

// Cuenta el total de errores semanticos producidos
unsigned long TOTAL_SEMANTIC_ERRORS = 0;

// ===============================================================

// ----- DEFINICION DE LISTAS ENLAZADAS DE CONTROL -----

// Lista enlazada de errores sintacticos
struct error *list_error_syntax = NULL;

// Lista enlazada de errores semanticos
struct error *list_error_semantic = NULL;

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE ERRORES -----

void add_error_to_list(struct error * err){
    // -- Comprobar si hay error
    if(!err)
        return;

    // -- Determinar a la lista a la que va el error
    switch (err->kind)
    {
    case ERROR_SYNTAX:
        add_error_syntax_to_list(err);
        break;

    case ERROR_SEMANTIC:
        add_error_semantic_to_list(err);
        break;
    
    default:
        break;
    }
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE ERRORES (SINTACTICOS) -----

void add_error_syntax_to_list(struct error * err){
    // -- Comprobar si hay error
    if(!err)
        return;

    // -- Comprobar si hay algun elemento en la lista
    if(!list_error_syntax){
        // -- Si no hay, se asigna como primero
        list_error_syntax = err;
    }
    else{
        // -- En caso contrario, busca la cola y se anida
        struct error *current_error = list_error_syntax;
        while(current_error->next){
            current_error = current_error->next;
        }

        // -- Asignar error al final del error actual
        current_error->next = err;
    }

    // -- Incrementar la lista de errores sintacticos
    TOTAL_SYNTAX_ERRORS++;
}

void free_list_error_syntax(){
    // -- Comprobar que la lista de errores es nula
    if(!list_error_syntax)
        return;

    // -- Liberar lista de errores
    free_list_errors(list_error_syntax);
    list_error_syntax = NULL;

    // -- Colocar a 0 el contador de errores
    TOTAL_SYNTAX_ERRORS = 0;
}

void report_list_error_syntax(){
    print_list_error_syntax(list_error_syntax);
}


// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE ERRORES (SEMANTICOS) -----

void add_error_semantic_to_list(struct error * err){
    // -- Comprobar si hay error
    if(!err)
        return;

    // -- Comprobar si hay algun elemento en la lista
    if(!list_error_semantic){
        // -- Si no hay, se asigna como primero
        list_error_semantic = err;
    }
    else{
        // -- En caso contrario, busca la cola y se anida
        struct error *current_error = list_error_semantic;
        while(current_error->next){
            current_error = current_error->next;
        }

        // -- Asignar error al final del error actual
        current_error->next = err;
    }

    // -- Incrementar la lista de errores semanticos
    TOTAL_SEMANTIC_ERRORS++;
}

void free_list_error_semantic(){
    // -- Comprobar que la lista de errores es nula
    if(!list_error_semantic)
        return;

    // -- Liberar lista de errores
    free_list_errors(list_error_semantic);
    list_error_semantic = NULL;

    // -- Colocar a 0 el contador de errores
    TOTAL_SEMANTIC_ERRORS = 0;
}

void report_list_error_semantic(){
    print_list_error_semantic(list_error_semantic);
}