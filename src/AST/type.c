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
    // -- Asignar parametros (si tipo funcion)
    t->parameters = NULL;

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
    case TYPE_FUNCTION:
        t->kind_str = strdup("function");
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

struct type * create_function_type(struct type *subtype, struct parameter_list *parameters){
    struct type *t = create_basic_type(TYPE_FUNCTION);

    // -- Comprobar reserva de memoria exitosa
    if(!t)
        return NULL;

    // -- Asignar subtipo de dato (retorno de funcion)
    t->subtype = subtype;
    // -- Asignar parametros de funcion
    t->parameters = parameters;

    // -- Retornar tipo creado e inicializado
    return t;
}

struct type * create_array_type(struct type *subtype){
    struct type *t = create_basic_type(TYPE_ARRAY);

    // -- Comprobar reserva de memoria exitosa
    if(!t)
        return NULL;

    // -- Asignar subtipo de dato
    t->subtype = subtype;

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

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (PARAMETROS) -----

struct parameter_list * create_parameter_list(char * name_parameter, struct type * type){
    struct parameter_list *pl = malloc(sizeof(*pl));

    // -- Comprobar reserva de memoria exitosa
    if(!pl)
        return NULL;

    // -- Asignar nombre de parametro
    pl->name_parameter = strdup(name_parameter);
    // -- Comprobar asignacion de nombre de parametro exitosa
    if(!pl->name_parameter){
        // -- Liberar memoria reservada al parametro
        free(pl);
        return NULL;
    }

    // -- Asignar tipo de dato del parametro
    pl->type = type;
    // -- Asignar puntero al siguiente parametro (null)
    pl->next = NULL;

    // -- Retornar lista de parametros reservada
    return pl;
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

        break;

    case TYPE_FUNCTION:
        free_type(type->subtype);
        type->subtype = NULL;

        free_list_parameters(type->parameters);
        type->parameters = NULL;

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
    if(parameter->name_parameter){
        free(parameter->name_parameter);
        parameter->name_parameter = NULL;
    }

    // -- Liberar tipo de parametro
    if(parameter->type){
        free_type(parameter->type);
        parameter->type = NULL;
    }


    // -- Liberar nodo
    free(parameter);
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO TIPO) -----

void print_AST_type(struct type *type){
    const char *IDENT_ARROW = "------------>";

    // -- Si NULL, simplemente devolver
    if(!type){
        printf(" %s <NONE>\n", IDENT_ARROW);
        return;
    }

    switch (type->kind)
    {
    case TYPE_ARRAY:
        printf(" %s ARRAY DE TIPO: [%s]\n", IDENT_ARROW, type->subtype->kind_str);
        break;

    case TYPE_FUNCTION:
        printf(" %s FUNCION DE TIPO: [%s]\n", IDENT_ARROW, type->subtype->kind_str);
        break;

    default:
        printf(" %s TIPO: [%s]\n", IDENT_ARROW, type->kind_str);
        break;
    }
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO SUBPROGRAMAS) -----

void print_AST_parameters(struct parameter_list *parameters_list){
    const char *IDENT_ARROW = "---------->";

    // -- Si NULL, simplemente devolver
    if(!parameters_list){
        printf(" %s <NONE>\n", IDENT_ARROW);
        return;
    }

    struct parameter_list *current_parameter = parameters_list;
    while(current_parameter){
        // -- Imprimir nombre de parametro
        printf(" %s PARAMETRO: [%s] \n", IDENT_ARROW, current_parameter->name_parameter);

        // -- Imprimir tipo de parametro
        printf(" %s TIPO DE DATO DEL PARAMETRO: [%s]\n", IDENT_ARROW, current_parameter->name_parameter);
        print_AST_type(current_parameter->type);

        printf("\n");

        // -- Ir al siguiente parametro
        current_parameter = current_parameter->next;
    }
}