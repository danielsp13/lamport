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

struct declaration * create_declaration_variable(char *name, struct type *type, struct expression *value, unsigned long line){
    struct declaration *d = malloc(sizeof(*d));

    // -- Comprobar reserva de memoria exitosa
    if(!d)
        return NULL;

    // -- Asignar nombre de variable
    d->name = strdup(name);
    // -- Comprobar asginacion de nombre exitosa
    if(!d->name){
        // -- Liberar memoria reservada para la declaracion
        free(d);
        return NULL;
    }

    // -- Asignar tipo de dato de la variable declarada
    d->type = type;
    // -- Asignar valor de inicializacion de variable
    d->value = value;
    // -- Asignar linea donde se realizo la declaracion de variable
    d->line = line;
    // -- Asignar referencia a simbolo de tabla de simbolos (NULL) 
    d->symb = NULL;
    // -- Asignar puntero a siguiente declaracion (NULL)
    d->next = NULL;

    // -- Retornar declaracion creada e inicializada
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
        free_declaration(&current_declaration);
        // -- Nodo actual -> siguiente
        current_declaration = next;
    }
}

void free_declaration(struct declaration **decl){
    // -- Obtener puntero de declaracion
    struct declaration *d = *decl;

    // -- Si NULL, simplemente devolver
    if(!d)
        return;

    // -- Liberar nombre de variable
    if(d->name){
        free(d->name);
        d->name = NULL;
    }

    // -- Liberar tipo de declaracion
    if(d->type){
        free_type(&d->type);
    }

    // -- Liberar expresion de valor
    if(d->value){
        free_expression(&d->value);
    }

    // -- Liberar referencia a simbolo
    d->symb = NULL;

    // -- Liberar nodo
    free(d);
    // -- Poner puntero de declaracion a NULL
    *decl = NULL;
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO DECLARACIONES) -----

void print_AST_declarations(struct declaration *declarations_list, unsigned int depth){
    // -- Determinar identacion de nodo
    char * IDENT_NODE_BRANCH = build_identation_branch(depth);
    char * IDENT_NODE = build_identation_spaces(depth);
    // -- Determinar profundidad del siguiente nodo
    const unsigned int NEXT_NODE_DEPTH = depth+2;

    // -- Si NULL, simplemente devolver
    if(!declarations_list){
        printf("%s%s %s\n",IDENT_NODE_BRANCH, IDENT_ARROW, NULL_NODE_MSG);

        // -- Liberar memoria utilizada para la identacion
        free(IDENT_NODE); IDENT_NODE = NULL;
        free(IDENT_NODE_BRANCH); IDENT_NODE_BRANCH = NULL;

        return;
    }

    // -- Recorrer la lista enlazada de declaraciones
    struct declaration * current_declaration = declarations_list;
    while(current_declaration){
        // -- Imprimir nombre de variable
        printf("%s%s DECLARACION DE VARIABLE: [%s]\n",IDENT_NODE_BRANCH, IDENT_ARROW, current_declaration->name);
        // -- Imprimir tipo de variable
        printf("%s%s TIPO DE DATO:\n",IDENT_NODE, IDENT_BLANK_ARROW);
        print_AST_type(current_declaration->type,NEXT_NODE_DEPTH);
        // -- Imprimir valor
        printf("%s%s VALOR DE INICIALIZACION:\n",IDENT_NODE, IDENT_BLANK_ARROW);
        print_AST_expressions(current_declaration->value,NEXT_NODE_DEPTH);

        printf("\n");

        // -- Ir a la siguiente declaracion
        current_declaration = current_declaration->next;
    }

    // -- Liberar memoria utilizada para la identacion
    free(IDENT_NODE); IDENT_NODE = NULL;
    free(IDENT_NODE_BRANCH); IDENT_NODE_BRANCH = NULL;
}