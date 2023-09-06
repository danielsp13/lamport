/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file parameter_list.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO lista parametros
 */

#include "AST/parameter_list.h"

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

    // -- Asignar puntero a entrada en la tabla de simbolos (null)
    pl->symb = NULL;

    // -- Retornar lista de parametros reservada
    return pl;
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

    // -- Liberar simbolo de la tabla de simbolos
    if(parameter->symb){
        free_symbol(parameter->symb);
        parameter->symb = NULL;
    }


    // -- Liberar nodo
    free(parameter);
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