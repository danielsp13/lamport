/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file type.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO tipos
 */

#include "AST/type.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (TIPOS) -----

struct type * create_basic_type(type_t kind){
    struct type *t = malloc(sizeof(*t));

    if(!t)
        return NULL;

    t->kind = kind;
    t->subtype = NULL;
    t->parameters = NULL;

    return t;
}

struct type * create_function_type(struct type *subtype, struct parameter_list *parameters){
    struct type *t = malloc(sizeof(*t));

    if(!t)
        return NULL;

    t->kind = TYPE_FUNCTION;
    t->subtype = subtype;
    t->parameters = parameters;

    return t;
}

struct type * create_array_type(struct type *subtype){
    struct type *t = malloc(sizeof(*t));

    if(!t)
        return NULL;

    t->kind = TYPE_ARRAY;
    t->subtype = subtype;
    t->parameters = NULL;

    return t;
}

struct type * create_semaphore_type(){
    struct type *t = malloc(sizeof(*t));

    if(!t)
        return NULL;

    t->kind = TYPE_SEMAPHORE;
    t->subtype = NULL;
    t->parameters = NULL;

    return t;
}

struct type * create_dprocess_type(){
    struct type *t = malloc(sizeof(*t));

    if(!t)
        return NULL;

    t->kind = TYPE_DPROCESS;
    t->subtype = NULL;
    t->parameters = NULL;

    return t;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (PARAMETROS) -----

struct parameter_list * create_parameter_list(char * name_parameter, struct type * type){
    struct parameter_list *pl = malloc(sizeof(*pl));

    if(!pl)
        return NULL;

    pl->name_parameter = name_parameter;
    pl->type = type;
    pl->next = NULL;

    return pl;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO TIPOS) -----

void free_type(struct type *type){
    // -- Si NULL, simplemente devolver
    if(!type)
        return;

    // -- Liberar en funcion del tipo
    switch (type->kind)
    {
    case TYPE_ARRAY:
        free_type(type->subtype);
        break;

    case TYPE_FUNCTION:
        free_type(type->subtype);
        free_list_parameters(type->parameters);
        break;

    default:
        break;
    }

    // -- Liberar nodo
    free(type);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO PARAMETROS) -----

void free_list_parameters(struct parameter_list *parameter_list){
    struct parameter_list *current_parameter_list = parameter_list;
    while(current_parameter_list){
        // -- Seleccionar siguiente en la lista
        struct parameter_list *next = current_parameter_list->next;
        // -- Liberar nodo
        free_parameter(current_parameter_list);
        // -- Nodo actual -> siguiente
        current_parameter_list = next;
    }
}

void free_parameter(struct parameter_list *parameter){
    // -- Si NULL, simplemente devolver
    if(!parameter)
        return;

    // -- Liberar nombre de parametro
    if(parameter->name_parameter)
        free(parameter->name_parameter);

    // -- Liberar tipo de parametro
    if(parameter->type)
        free_type(parameter->type);


    // -- Liberar nodo
    free(parameter);
}