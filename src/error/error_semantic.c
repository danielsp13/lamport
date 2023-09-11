/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file error_semantic.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para gestion de errores
 * producidos en el analizador semantico
 */

#include "error/error_semantic.h"


// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE ERRORES (SEMANTICOS) ----

struct error_semantic * create_error_semantic(error_semantic_t kind, char *id, unsigned long err_line, char *msg){
    struct error_semantic *err = malloc(sizeof(*err));

    // -- Comprobar reserva de memoria exitosa
    if(!err)
        return NULL;

    // -- Asignar tipo de error
    err->kind = kind;
    // -- Asignar identificador de simbolo que produjo el error
    err->id = strdup(id);

    // -- Comprobar asginacion de id exitoso
    if(!err->id){
        // -- Liberar memoria reservada para el error
        free(err);
        return NULL;
    }


    // -- Asignar linea de error
    err->err_line = err_line;
    // -- Asignar mensaje de error
    err->msg = strdup(msg);

    // -- Comprobar asignacion de mensaje exitoso
    if(!err->msg){
        // -- Liberar memoria reservada para el error
        free(err);
        return NULL;
    }

    // -- Asignar linea donde se encontro simbolo definido (-1)
    err->def_line = -1;

    // -- Asignar posicion en lista de parametros donde se produjo error (-1)
    err->which = -1;

    // -- Asignar puntero a siguiente error (NULL)
    err->next = NULL;

    // -- Retornar error creado e inicializado
    return err;
}

struct error_semantic * create_error_semantic_undefined_symbol(char *id, unsigned long err_line, char *msg){
    return create_error_semantic(UNDEFINED_SYMBOL,id, err_line, msg);
}

struct error_semantic * create_error_semantic_duplicated_symbol(char *id, unsigned long err_line, unsigned long def_line, char *msg){
    struct error_semantic *err = create_error_semantic(DUPLICATED_SYMBOL,id, err_line, msg);

    // -- Comprobar que se creo el error
    if(!err)
        return NULL;

    // -- Asignar linea donde se encontro el simbolo anterior
    err->def_line = def_line;

    // -- Retornar error creado e inicializado
    return err;
}

struct error_semantic * create_error_semantic_duplicated_symbol_parameter(char *id, unsigned long err_line, int which , char *msg){
    struct error_semantic *err = create_error_semantic(DUPLICATED_SYMBOL_PARAM,id, err_line, msg);

    // -- Comprobar que se creo el error
    if(!err)
        return NULL;

    // -- Asignar posicion de parametro
    err->which = which;

    // -- Retornar error creado e inicializado
    return err;
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE LIBERACION DE ERRORES (SEMANTICOS) ----

void free_list_error_semantic(struct error_semantic *list_errors){
    struct error_semantic *current_error = list_errors;

    while(current_error){
        // -- Seleccionar siguiente en la lista
        struct error_semantic *next = current_error->next;
        // -- Liberar nodo
        free_error_semantic(current_error);
        // -- Nodo actual -> siguiente
        current_error = next;
    }
}

void free_error_semantic(struct error_semantic *error){
    // -- Si NULL, simplemente devolver
    if(!error)
        return;

    // -- Liberar id
    if(error->id){
        free(error->id);
        error->id = NULL;
    }

    // -- Liberar mensaje de error
    if(error->msg){
        free(error->msg);
        error->msg = NULL;
    }

    // -- Liberar nodo
    free(error);
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE IMPRESION DE ERRORES (SEMANTICOS) ----

void print_list_error_semantic(struct error_semantic *list_errors){
    // -- Si NULL, simplemente devolver
    if(!list_errors){
        printf(" <NONE>\n");
        return;
    }

    // -- Recorrer la lista enlazada de errores
    struct error_semantic * current_error = list_errors;
    while(current_error){
        // -- Imprimir mensaje de error
        printf("Error semantico en la linea [%ld]: %s\t: [%s]. ", current_error->err_line, current_error->msg, current_error->id);

        // -- Especificar mas detalles del error dependiendo de casos
        switch (current_error->kind)
        {
        case DUPLICATED_SYMBOL:
            printf("Primero se definio aqui: linea [%ld].\n", current_error->def_line);
            break;

        case DUPLICATED_SYMBOL_PARAM:
            printf("Primero se definio aqui: posicion de lista [%d].\n", current_error->which);
            break;
        
        default:
            printf("\n");
            break;
        }

        // -- Ir al siguiente error
        current_error = current_error->next;
    }
}
