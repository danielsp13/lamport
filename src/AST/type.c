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
    {
        t->kind_str = strdup("integer");
        break;
    }
    case TYPE_REAL:
    {
        t->kind_str = strdup("real");
        break;
    }
    case TYPE_BOOLEAN:
    {
        t->kind_str = strdup("boolean");
        break;
    }
    case TYPE_CHAR:
    {
        t->kind_str = strdup("char");
        break;
    }
    case TYPE_STRING:
    {
        t->kind_str = strdup("string");
        break;
    }
    case TYPE_ARRAY:
    {
        t->kind_str = strdup("array");
        break;
    }
    case TYPE_SEMAPHORE:
    {
        t->kind_str = strdup("semaphore");
        break;
    }
    case TYPE_DPROCESS:
    {
        t->kind_str = strdup("dinamic process");
        break;
    }
    }

    // -- Comprobar asignacion de tipo de dato exitoso
    if(!t->kind_str){
        // -- Liberar memoria reservada al tipo de dato
        free(t);
        return NULL;
    }

    // -- Asignar puntero a siguiente tipo (NULL)
    t->next = NULL;

    // -- Retornar tipo creado
    return t;
}

struct type * create_array_type(struct type *subtype, struct expression *size){
    struct type *t = create_basic_type(TYPE_ARRAY);

    // -- Comprobar reserva de memoria exitosa
    if(!t)
        return NULL;

    // -- Asignar subtipo de dato
    t->subtype = copy_type(subtype);

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

void free_list_types(struct type *list_types){
    if(!list_types)
        return;

    struct type * current_type = list_types;
    while(current_type){
        struct type * next = current_type->next;
        free_type(current_type);
        current_type = next;
    }
}

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
    {
        // -- Liberar tipo
        if(type->size){
            free_expression(type->size);
            type->size = NULL;
        }
        if(type->subtype){
            free_type(type->subtype);
            type->subtype = NULL;
        }
        
        break;
    }

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
    {
        printf("%s%s ARRAY DE TIPO: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, type->subtype->kind_str);
        printf("%s%s DIMENSION DEL ARRAY:\n", IDENT_NODE, IDENT_BLANK_ARROW);
        print_AST_expressions(type->size,NEXT_NODE_DEPTH);
        break;
    }
    default:
    {
        printf("%s%s TIPO: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, type->kind_str);
        break;
    }
    }

    // -- Liberar memoria utilizada para la identacion
    free(IDENT_NODE); IDENT_NODE = NULL;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE ASISTENCIA DE USO DE TIPOS -----

bool equals_type(struct type *type_a, struct type *type_b){
    // -- Resultado de comprobacion
    bool result = false;    ///< Se inicializa como falso buscando casos correctos

    // -- Comprobacion 0: Comprobamos que hay dos tipos
    if(!type_a || !type_b)
        return result;

    // -- Comprobacion 1: Comprobamos que los tipos son iguales
    if(type_a->kind == type_b->kind){
        // -- Comprobacion 2: Comprobamos si son array 
        //(con referirnos a un tipo es suficiente, pero se comprueban los dos para mayor legibilidad)
        if(type_a->kind == TYPE_ARRAY && type_b->kind == TYPE_ARRAY){
            // -- Comprobacion 3: Comprobamos los subtipos de dato (RECURSIVO)
            return equals_type(type_a->subtype, type_b->subtype);
        }
        else{
            // -- Son datos atomicos (INTEGER, CHAR, STRING,...)
            // -- Actualizar resultado a true
            result = true;
        }
    }
    // -- Comprobacion 3: Uno es un array y otro no
    else if(type_a->kind == TYPE_ARRAY){
        return equals_type(type_a->subtype,type_b);
    }
    else if(type_b->kind == TYPE_ARRAY){
        return equals_type(type_a,type_b->subtype);
    }

    // -- Retornar resultado de comprobacion
    return result;
}

struct type * copy_type(struct type *type){
    // -- Comprobar que hay tipo
    if(!type)
        return NULL;

    // -- Definir estructura nueva de tipo
    struct type *type_copy = malloc(sizeof(*type_copy));

    // -- Comprobar creacion exitosa
    if(!type_copy)
        return NULL;

    // -- Copiar tipo de dato (kind)
    type_copy->kind = type->kind;
    // -- Copiar tipo de dato kind_str (kind_str)
    type_copy->kind_str = strdup(type->kind_str);
    // -- Comprobar que se copio el tipo str exitosamente
    if(!type_copy->kind_str){
        free(type_copy);
        return NULL;
    }

    // -- Copiar subtipo de dato (recursivamete)
    type_copy->subtype = copy_type(type->subtype);

    // -- Copiar expresion (solo si tipo es array)
    type_copy->size = NULL;
    if(type_copy->kind == TYPE_ARRAY)
        type_copy->size = copy_expression(type->size);

    // -- Asignar puntero siguiente a NULL
    type_copy->next = NULL;

    // -- Retornar copia de tipo
    return type_copy;
}

struct type * copy_list_types(struct type *list_types){
    if(!list_types)
        return NULL;

    struct type *list_copy = NULL;
    struct type *last_copy = NULL;

    struct type *current_type = list_types;
    while(current_type){
        if(!list_copy){
            list_copy = copy_type(current_type);
            last_copy = list_copy;
        }
        else{
            last_copy->next = copy_type(current_type);
            last_copy = last_copy->next;
        }

        current_type = current_type->next;
    }

    // -- Retornar copia
    return list_copy;
}