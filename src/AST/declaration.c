/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file declaration.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO declaraciones
 */

#include "AST/declaration.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (DECLARACIONES) -----

struct declaration * create_declaration_variable(char *name, struct type *type, struct expression *value){
    struct declaration *d = malloc(sizeof(*d));

    if(!d)
        return NULL;

    d->name = name;
    d->type = type;
    d->value = value; 
    d->next = NULL;

    return d;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO DECLARACIONES) -----

void free_list_declarations(struct declaration *declarations_list){
    struct declaration *current_declaration = declarations_list;
    while(current_declaration){
        // -- Seleccionar siguiente en la lista
        struct declaration *next = current_declaration->next;
        // -- Liberar nodo
        free_declaration(current_declaration);
        // -- Nodo actual -> siguiente
        current_declaration = next;
    }
}

void free_declaration(struct declaration *decl){
    // -- Si NULL, simplemente devolver
    if(!decl)
        return;

    // -- Liberar nombre de variable
    if(decl->name)
        free(decl->name);

    // -- Liberar tipo de declaracion
    if(decl->type)
        free_type(decl->type);

    // -- Liberar expresion de valor
    if(decl->value)
        free_expression(decl->value);

    // -- Liberar nodo
    free(decl);
}