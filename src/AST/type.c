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

    // -- Comprobar reserva de memoria exitosa
    if(!t)
        return NULL;

    // -- Asignar tipo de dato
    t->kind = kind;
    // -- Asignar subtipo de dato (NULL)
    t->subtype = NULL;
    // -- Asignar size de dato (NULL)
    t->size = NULL;

    // -- Asignar tipo de dato (str)
    switch (t->kind)
    {
    case TYPE_INTEGER:
        t->kind_str = strdup("integer");
        break;
    case TYPE_REAL:
        t->kind_str = strdup("real");
        break;
    case TYPE_BOOLEAN:
        t->kind_str = strdup("boolean");
        break;
    case TYPE_CHAR:
        t->kind_str = strdup("char");
        break;
    case TYPE_STRING:
        t->kind_str = strdup("string");
        break;
    case TYPE_ARRAY:
        t->kind_str = strdup("array");
        break;
    case TYPE_SEMAPHORE:
        t->kind_str = strdup("semaphore");
        break;
    case TYPE_DPROCESS:
        t->kind_str = strdup("dprocess");
        break;
    }

    // -- Comprobar asignacion de tipo de dato exitoso
    if(!t->kind_str){
        // -- Liberar memoria reservada al tipo de dato
        free(t);
        return NULL;
    }

    // -- Retornar tipo creado
    return t;
}

struct type * create_array_type(struct type *subtype, struct expression *size){
    struct type *t = create_basic_type(TYPE_ARRAY);

    // -- Comprobar reserva de memoria exitosa
    if(!t)
        return NULL;

    // -- Asignar subtipo de dato
    t->subtype = subtype;

    // -- Asignar size de array
    t->size = size;

    // -- Retornar tipo creado e inicializado
    return t;
}

struct type * create_semaphore_type(){
    struct type *t = create_basic_type(TYPE_SEMAPHORE);

    // -- Comprobar reserva de memoria exitosa
    if(!t)
        return NULL;

    // -- Retornar tipo creado e inicializado
    return t;
}

struct type * create_dprocess_type(){
    struct type *t = create_basic_type(TYPE_DPROCESS);

    // -- Comprobar reserva de memoria exitosa
    if(!t)
        return NULL;

    // -- Retornar tipo creado e inicializado
    return t;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO TIPOS) -----

void free_type(struct type *type){
    // -- Si NULL, simplemente devolver
    if(!type)
        return;

    // -- Liberar tipo de dato (str)
    free(type->kind_str);
    type->kind_str = NULL;

    // -- Liberar en funcion del tipo
    switch (type->kind)
    {
    case TYPE_ARRAY:
        free_type(type->subtype);
        type->subtype = NULL;

        free_expression(type->size);
        type->size = NULL;

        break;

    default:
        break;
    }

    // -- Liberar nodo
    free(type);
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO TIPO) -----

void print_AST_type(struct type *type, unsigned int depth){
    // -- Determinar identacion de nodo
    char * IDENT_NODE = build_identation_spaces(depth);
    // -- Determinar profundidad del siguiente nodo
    const unsigned int NEXT_NODE_DEPTH = depth+1;

    // -- Si NULL, simplemente devolver
    if(!type){
        printf("%s%s %s\n",IDENT_NODE, IDENT_ARROW, NULL_NODE_MSG);

        // -- Liberar memoria utilizada para la identacion
        free(IDENT_NODE); IDENT_NODE = NULL;
        
        return;
    }

    switch (type->kind)
    {
    case TYPE_ARRAY:
        printf("%s%s ARRAY DE TIPO: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, type->subtype->kind_str);
        printf("%s%s DIMENSION DEL ARRAY:\n", IDENT_NODE, IDENT_BLANK_ARROW);
        print_AST_expressions(type->size,NEXT_NODE_DEPTH);
        break;
    default:
        printf("%s%s TIPO: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, type->kind_str);
        break;
    }

    // -- Liberar memoria utilizada para la identacion
    free(IDENT_NODE); IDENT_NODE = NULL;
}