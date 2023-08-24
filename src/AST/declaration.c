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

    d->name = strdup(name);
    if(!d->name){
        free(d->name);
        return NULL;
    }

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

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO DECLARACIONES) -----

void print_AST_declarations(struct declaration *declarations_list){
    const char *IDENT_ARROW = "------>";

    // -- Si NULL, simplemente devolver
    if(!declarations_list){
        printf(" %s <NONE>\n", IDENT_ARROW);
        return;
    }

    // -- Recorrer la lista enlazada de declaraciones
    struct declaration * current_declaration = declarations_list;
    while(current_declaration){
        // -- Imprimir nombre de variable
        printf(" %s DECLARACION DE VARIABLE: [%s]\n", IDENT_ARROW, current_declaration->name);
        // -- Imprimir tipo de variable
        printf(" %s TIPO DE DATO DE VARIABLE: [%s]\n", IDENT_ARROW, current_declaration->name);
        print_AST_type(current_declaration->type);
        // -- Imprimir valor
        printf(" %s VALOR DE VARIABLE: [%s]\n", IDENT_ARROW, current_declaration->name);
        print_AST_expressions(current_declaration->value);

        printf("\n");

        // -- Ir a la siguiente declaracion
        current_declaration = current_declaration->next;
    }
}