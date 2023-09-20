/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file error.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para gestion de errores
 * producidos en la compilacion.
 */

#include "error/error.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE ERRORES ----

struct error * create_error(error_t kind, unsigned long err_line, char *msg){
    struct error *err = malloc(sizeof(*err));

    // -- Comprobar reserva de memoria exitosa
    if(!err)
        return NULL;

    // -- Asignar tipo de error
    err->kind = kind;

    // -- Asignar tipo de error (str)
    switch (err->kind)
    {
    case ERROR_SYNTAX:
    {
        err->kind_str = strdup("sintactico");
        break;
    }

    case ERROR_SEMANTIC:
    {
        err->kind_str = strdup("semantico");
        break;
    }
    
    default:
    {
        err->kind_str = NULL;
        break;
    }
    }

    // -- Comprobar asignacion de tipo de error exitoso
    if(!err->kind_str){
        // -- Liberar memoria reservada para el error
        free(err);
        return NULL;
    }

    // -- Asignar linea de error
    err->err_line = err_line;

    // -- Asignar mensaje de error
    err->msg = strdup(msg);

    // -- Comprobar asignacion de mensaje de error exitoso
    if(!err->msg){
        // -- Liberar memoria reservada para el error
        free(err);
        return NULL;
    }

    // -- Asignar puntero a siguiente error (NULL)
    err->next = NULL;

    // -- Retornar error creado e inicializado
    return err;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE LIBERACION DE ERRORES ----

void free_list_errors(struct error *list_errors){
    struct error *current_error = list_errors;

    while(current_error){
        // -- Seleccionar siguiente en la lista
        struct error *next = current_error->next;
        // -- Liberar nodo
        free_error(current_error);
        // -- Nodo actual -> siguiente
        current_error = next;
    }
}

void free_error(struct error *error){
    // -- Si NULL, simplemente devolver
    if(!error)
        return;

    // -- Liberar tipo de error (str)
    if(error->kind_str){
        free(error->kind_str);
        error->kind_str = NULL;
    }

    // -- Liberar mensaje de error
    if(error->msg){
        free(error->msg);
        error->msg = NULL;
    }

    // -- Liberar informacion adicional de error
    switch (error->kind)
    {
    case ERROR_SYNTAX:
    {
        // -- Liberar identificador de declaracion/subprograma/proceso
        free(error->err_data.error_syntax.identifier);
        error->err_data.error_syntax.identifier = NULL;

        free(error->err_data.error_syntax.kind_str);
        error->err_data.error_syntax.kind_str = NULL;
        break;
    }

    case ERROR_SEMANTIC:
    {
        // -- Liberar identificador de simbolo
        free(error->err_data.error_semantic.id);
        error->err_data.error_semantic.id = NULL;

        break;
    }
    
    default:
        break;
    }

    // -- Liberar nodo
    free(error);
}

