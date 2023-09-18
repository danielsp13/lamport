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

struct error * create_error_syntax(error_syntax_t kind, char *identifier, unsigned long err_line, char *msg){
    struct error *err = create_error(ERROR_SYNTAX, err_line, msg);

    // -- Comprobar creacion de error exitoso
    if(!err)
        return NULL;

    
    // -- Asignar tipo de error sintactico
    err->err_data.error_syntax.kind = kind;

    // -- Asignar componente de error sintactico
    err->err_data.error_syntax.kind_str = NULL;
    switch (err->err_data.error_syntax.kind)
    {
    case ERR_SYNTAX_IN_DECLARATION:
        err->err_data.error_syntax.kind_str = strdup("declaracion de variable");
        break;
    case ERR_SYNTAX_IDENT_IN_DECLARATION:
        err->err_data.error_syntax.kind_str = strdup("declaracion de variable");
        break;
    case ERR_SYNTAX_IN_PROCEDURE:
        err->err_data.error_syntax.kind_str = strdup("procedimiento");
        break;
    case ERR_SYNTAX_IDENT_IN_PROCEDURE:
        err->err_data.error_syntax.kind_str = strdup("procedimiento");
        break;
    case ERR_SYNTAX_IN_FUNCTION:
        err->err_data.error_syntax.kind_str = strdup("funcion");
        break;
    case ERR_SYNTAX_IDENT_IN_FUNCTION:
        err->err_data.error_syntax.kind_str = strdup("funcion");
        break;
    case ERR_SYNTAX_IN_PARAMETER:
        err->err_data.error_syntax.kind_str = strdup("parametro");
        break;
    case ERR_SYNTAX_IN_PROCESS:
        err->err_data.error_syntax.kind_str = strdup("proceso");
        break;
    case ERR_SYNTAX_IDENT_IN_PROCESS:
        err->err_data.error_syntax.kind_str = strdup("proceso");
        break;
    case ERR_SYNTAX_IN_TYPE:
        err->err_data.error_syntax.kind_str = strdup("tipo de dato");
        break;
    case ERR_SYNTAX_IN_EXPRESSION:
        err->err_data.error_syntax.kind_str = strdup("expresion");
        break;
    case ERR_SYNTAX_IN_STATEMENT:
        err->err_data.error_syntax.kind_str = strdup("sentencia");
        break;
    case ERR_SYNTAX_IN_PROGRAM:
        err->err_data.error_syntax.kind_str = strdup("programa");
        break;
    case ERR_SYNTAX_IDENT_IN_PROGRAM:
        err->err_data.error_syntax.kind_str = strdup("programa");
        break;
    
    default:
        break;
    }

    if(!err->err_data.error_syntax.kind_str){
        free(err);
        return NULL;
    }
    

    // -- Asignar identificador de declaracion/subprograma/proceso
    err->err_data.error_syntax.identifier = strdup(identifier);
    // -- Comprobar que se asigno correctamente
    if(!err->err_data.error_syntax.identifier){
        free(err);
        return NULL;
    }


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
    while(current_error){
        printf("Error sintactico cerca de la linea [%ld], en %s", current_error->err_line,current_error->err_data.error_syntax.kind_str);
        switch (current_error->err_data.error_syntax.kind)
        {
        case ERR_SYNTAX_IN_DECLARATION:
            printf(" [%s]",current_error->err_data.error_syntax.identifier);
            break;
        case ERR_SYNTAX_IDENT_IN_DECLARATION:
            printf(" ");
            break;
        case ERR_SYNTAX_IN_PROCEDURE:
            printf(" [%s]",current_error->err_data.error_syntax.identifier);
            break;
        case ERR_SYNTAX_IDENT_IN_PROCEDURE:
            printf(" ");
            break;
        case ERR_SYNTAX_IN_FUNCTION:
            printf(" [%s]",current_error->err_data.error_syntax.identifier);
            break;
        case ERR_SYNTAX_IDENT_IN_FUNCTION:
            printf(" ");
            break;
        case ERR_SYNTAX_IN_PARAMETER:
            printf(" ");
            break;
        case ERR_SYNTAX_IN_PROCESS:
            printf(" [%s]",current_error->err_data.error_syntax.identifier);
            break;
        case ERR_SYNTAX_IDENT_IN_PROCESS:
            printf(" ");
            break;
        case ERR_SYNTAX_IN_TYPE:
            printf(" ");
            break;
        case ERR_SYNTAX_IN_EXPRESSION:
            printf(" ");
            break;
        case ERR_SYNTAX_IN_STATEMENT:
            printf(" ");
            break;
        case ERR_SYNTAX_IN_PROGRAM:
            printf(" [%s]",current_error->err_data.error_syntax.identifier);
            break;
        case ERR_SYNTAX_IDENT_IN_PROGRAM:
            printf(" ");
            break;
        
        default:
            break;
        }
        printf(": \n --> %s.\n\n", current_error->msg);

        // -- Ir al siguiente error
        current_error = current_error->next;
    }
}