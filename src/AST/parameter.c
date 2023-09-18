/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file parameter.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO parametro
 */

#include "AST/parameter.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (PARAMETROS) -----

struct parameter * create_parameter(char * name_parameter, struct type * type, unsigned long line){
    struct parameter *pl = malloc(sizeof(*pl));

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
    // -- Asignar linea donde se declaro el parametro
    pl->line = line;
    // -- Asignar puntero al siguiente parametro (null)
    pl->next = NULL;

    // -- Asignar puntero a entrada en la tabla de simbolos (null)
    pl->symb = NULL;

    // -- Retornar lista de parametros reservada
    return pl;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO PARAMETROS) -----

void free_list_parameters(struct parameter *list_parameters){
    struct parameter *current_parameter = list_parameters;
    while(current_parameter){
        // -- Seleccionar siguiente en la lista
        struct parameter *next = current_parameter->next;
        // -- Liberar nodo
        free_parameter(current_parameter);
        // -- Nodo actual -> siguiente
        current_parameter = next;
    }
}

void free_parameter(struct parameter *parameter){

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

void print_AST_parameters(struct parameter *list_parameters, unsigned int depth){
    // -- Determinar identacion de nodo
    char * IDENT_NODE = build_identation_spaces(depth);
    // -- Determinar profundidad del siguiente nodo
    const unsigned int NEXT_NODE_DEPTH = depth+1;

    // -- Si NULL, simplemente devolver
    if(!list_parameters){
        printf("%s%s %s\n",IDENT_NODE, IDENT_BLANK_ARROW, NULL_NODE_MSG);

        // -- Liberar memoria utilizada para la identacion
        free(IDENT_NODE); IDENT_NODE = NULL;

        return;
    }

    struct parameter *current_parameter = list_parameters;
    while(current_parameter){
        // -- Imprimir nombre de parametro
        printf("%s%s NOMBRE DE PARAMETRO: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, current_parameter->name_parameter);

        // -- Imprimir tipo de parametro
        printf("%s%s TIPO DE DATO: [%s]\n",IDENT_NODE, IDENT_BLANK_ARROW, current_parameter->name_parameter);
        print_AST_type(current_parameter->type,NEXT_NODE_DEPTH);

        printf("\n");

        // -- Ir al siguiente parametro
        current_parameter = current_parameter->next;
    }

    // -- Liberar memoria utilizada para la identacion
    free(IDENT_NODE); IDENT_NODE = NULL;
}