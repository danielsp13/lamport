/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file error_syntax.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion funciones para gestion de errores
 * producidos en el analizador sintactico
 */

#include "error/error_syntax.h"

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE ERRORES (SINTACTICOS) ----

struct error * create_error_syntax(error_syntax_t kind, unsigned long err_line, char *msg){
    struct error *err = create_error(ERROR_SYNTAX, err_line, msg);

    // -- Comprobar creacion de error exitoso
    if(!err)
        return NULL;

    // -- Asignar tipo de error sintactico
    err->err_data.error_syntax.kind = kind;

    // -- Retornar error creado e inicializado
    return err;
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE IMPRESION DE ERRORES (SINTACTICOS) ----

void print_list_error_syntax(struct error *list_errors){
    // -- Si NULL, simplemente devolver
    if(!list_errors){
        printf(" <NONE>\n");
        return;
    }

    // -- Recorrer la lista enlazada de errores
    struct error * current_error = list_errors;
    char * localized;
    while(current_error){
        // -- Imprimir mensaje de error
        switch (current_error->err_data.error_syntax.kind)
        {
        case EXPECTED_STMT:
            localized = strdup("cerca de");
            break;
        
        default:
            localized = strdup("en");
            break;
        }
        printf("Error sintactico %s la linea [%ld]: %s.\n", localized, current_error->err_line, current_error->msg);
        free(localized);

        // -- Ir al siguiente error
        current_error = current_error->next;
    }
}