/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file error_semantic.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones para gestion de errores
 * producidos en el analizador semantico
 */

#include "error/error_semantic.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE ERRORES (SEMANTICOS : NAME RESOLUTION) ----

struct error * create_error_semantic(error_semantic_t kind, char *id, unsigned long err_line, char *msg){
    struct error *err = create_error(ERROR_SEMANTIC, err_line, msg);

    // -- Comprobar reserva de memoria exitosa
    if(!err)
        return NULL;


    // -- Asignar identificador de simbolo que produjo el error
    err->err_data.error_semantic.id = strdup(id);

    // -- Comprobar asginacion de id exitoso
    if(!err->err_data.error_semantic.id){
        // -- Liberar memoria reservada para el error
        free(err);
        return NULL;
    }

    // -- Asignar tipo de error semantico
    err->err_data.error_semantic.kind = kind;

    // -- Asignar linea donde se encontro simbolo definido (-1)
    err->err_data.error_semantic.def_line = -1;

    // -- Asignar posicion en lista de parametros donde se produjo error (-1)
    err->err_data.error_semantic.which = -1;

    // -- Asignar puntero a siguiente error (NULL)
    err->next = NULL;

    // -- Retornar error creado e inicializado
    return err;
}

struct error * create_error_semantic_undefined_symbol(char *id, unsigned long err_line, char *msg){
    return create_error_semantic(UNDEFINED_SYMBOL,id, err_line, msg);
}

struct error * create_error_semantic_duplicated_symbol(char *id, unsigned long err_line, unsigned long def_line, char *msg){
    struct error *err = create_error_semantic(DUPLICATED_SYMBOL,id, err_line, msg);

    // -- Comprobar que se creo el error
    if(!err)
        return NULL;

    // -- Asignar linea donde se encontro el simbolo anterior
    err->err_data.error_semantic.def_line = def_line;

    // -- Retornar error creado e inicializado
    return err;
}

struct error * create_error_semantic_duplicated_symbol_parameter(char *id, unsigned long err_line, int which , char *msg){
    struct error *err = create_error_semantic(DUPLICATED_SYMBOL_PARAM,id, err_line, msg);

    // -- Comprobar que se creo el error
    if(!err)
        return NULL;

    // -- Asignar posicion de parametro
    err->err_data.error_semantic.which = which;

    // -- Retornar error creado e inicializado
    return err;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE ERRORES (SEMANTICOS : TYPE_CHECKING) ----

char * create_message_error_semantic_unmatched_types(error_semantic_type_checking_t kind, char *action, char *type_a, char *type_b){
    // -- Construir mensaje de error
    const unsigned int BUFF_SIZE = 2048; const unsigned int SUB_BUFF_SIZE = 1024;
    char buff[BUFF_SIZE];       /// < Buffer para construir mensaje
    char sub_buff[BUFF_SIZE];   /// < Subbuffer de asistencia

    memset(buff, 0, sizeof(buff));
    memset(sub_buff, 0, sizeof(sub_buff));

    // -- Costruir mensaje en buffer
    switch (kind)
    {
    case UNMATCHED_TYPES_EXPR_BINARY:
    {
        sprintf(sub_buff, "no se puede %s un (%s) con un (%s)",action,type_a,type_b);
        break;
    }
    case UNMATCHED_TYPES_EXPR_UNARY:
    {
        sprintf(sub_buff,"no se puede aplicar %s a un (%s)",action,type_a);
        break;
    }
    case UNMATCHED_TYPES_EXPR_FUNCTION_INV:
    {
        sprintf(sub_buff,"argumento de funcion [%s] es de tipo (%s). se encontro (%s)",action,type_a,type_b);
        break;
    }
    case UNMATCHED_TYPES_DECLARATION:
    {
        sprintf(sub_buff,"no se puede %s un (%s) a un (%s)",action,type_b,type_a);
        break;
    }
    case UNMATCHED_TYPES_DECLARATION_ARRAY:
    {
        sprintf(sub_buff,"declaracion de %s de array invalida. se encontro (%s)",action,type_a);
        break;
    }
    case UNMATCHED_TYPES_STMT_ASSIGNMENT:
    {
        sprintf(sub_buff,"no se puede %s un (%s) a un (%s)",action,type_b,type_a);
        break;
    }
    case UNMATCHED_TYPES_STMT_ASSIGNMENT_ARRAY_NO_INDEX:
    {
        sprintf(sub_buff,"no hay indice de indexacion para variable array");
        break;
    }
    case UNMATCHED_TYPES_STMT_ASSIGNMENT_INDEX:
    {
        sprintf(sub_buff,"no se puede %s con una expresion de tipo (%s)",action,type_a);
        break;
    }
    case UNMATCHED_TYPES_STMT_WHILE:
    {
        sprintf(sub_buff, "condicion de while no es expresion boolean. se encontro (%s)",type_a);
        break;
    }
    case UNMATCHED_TYPES_STMT_FOR_INDEX:
    {
        sprintf(sub_buff,"indexador de bucle no es de tipo integer. se encontro (%s)",type_a);
        break;
    }
    case UNMATCHED_TYPES_STMT_FOR_INIT:
    {
        sprintf(sub_buff,"no se puede %s un (%s) a un (%s)",action,type_b,type_a);
        break;
    }
    case UNMATCHED_TYPES_STMT_FOR_END_EXR:
    {
        sprintf(sub_buff,"%s de rango de for no es expresion integer. se encontro (%s)",action,type_a);
        break;
    }
    case UNMATCHED_TYPES_STMT_IF_ELSE:
    {
        sprintf(sub_buff,"condicion de if no es expresion boolean. se encontro (%s)",type_a);
        break;
    }
    case UNMATCHED_TYPES_STMT_FORK:
    {
        sprintf(sub_buff,"fork a un identificador que no es un proceso. se encontro (%s)",type_a);
        break;
    }
    case UNMATCHED_TYPES_STMT_JOIN:
    {
        sprintf(sub_buff,"join a un identificador que no es un proceso. se encontro (%s)",type_a);
        break;
    }
    case UNMATCHED_TYPES_STMT_PROCEDURE_INV:
    {
        sprintf(sub_buff,"argumento de funcion [%s] es de tipo (%s). se encontro (%s)",action,type_b,type_a);
        break;
    }
    case UNMATCHED_TYPES_PROC_VECTOR_INDEX:
    {
        sprintf(sub_buff,"indexador de proceso no es de tipo integer. se encontro (%s)",type_a);
        break;
    }
    case UNMATCHED_TYPES_PROC_VECTOR_START_RANGE:
    {
        sprintf(sub_buff,"%s de rango de vector de procesos no es expresion integer. se encontro (%s)",action,type_a);
        break;
    }
    case UNMATCHED_TYPES_PROC_VECTOR_END_RANGE:
    {
        sprintf(sub_buff,"%s de rango de vector de procesos no es expresion integer. se encontro (%s)",action,type_a);
        break;
    }
    case UNMATCHED_TYPES_SUBPROG_FUNCTION_RETURN:
    {
        sprintf(sub_buff,"retorno de funcion [%s] no coincide con valor de definicion. devuelve (%s) y se encontro (%s)",action,type_a,type_b);
        break;
    }
    default:
        break;
    }
    strcat(buff, sub_buff);

    // -- Crear copia dinamica con el contenido del mensaje
    char *msg = strndup(buff, strlen(buff));

    // -- Comprobar creacion de mensaje exitoso
    if(!msg)
        return NULL;

    // -- retornar mensaje
    return msg;
}

struct error * create_error_semantic_unmatched_types(unsigned long err_line, char **msg){
    // -- Crear error
    struct error *err = create_error_semantic(UNMATCHED_TYPES," ", err_line, *msg);

    // -- Comprobar creacion de error exitoso
    if(!err){
        free(msg);
        return NULL;
    }
    // -- Liberar memoria local para definicion de mensaje
    free(*msg); msg = NULL;

    // -- Retornar error creado e inicializado
    return err; 
}

struct error * create_error_semantic_unmatched_types_expression_binary(unsigned long err_line, char *type_a, char *type_b, char *operation){
    // -- Construir mensaje de error
    char *msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_EXPR_BINARY, operation, type_a, type_b);
    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_unmatched_types_expression_unary(unsigned long err_line, char *type, char *operation){
    // -- Construir mensaje de error
    char *msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_EXPR_UNARY, operation, type, NULL);
    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_unmatched_types_declaration(unsigned long err_line, char *type_a, char *type_b){
    // -- Construir mensaje de error
    char *msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_DECLARATION, "asignar", type_a, type_b);
    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_invalid_array_size(unsigned long err_line, char *type_a){
    // -- Construir mensaje de error
    char *msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_DECLARATION_ARRAY,"size",type_a,NULL);
    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_unmatched_types_statement_assignment(error_semantic_type_checking_t kind, unsigned long err_line,char *type_a, char *type_b){
    // -- Construir mensaje de error
    char *msg;
    switch (kind)
    {
    case UNMATCHED_TYPES_STMT_ASSIGNMENT:
    {
        msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_STMT_ASSIGNMENT,"asignar",type_a,type_b);
        break;
    }
    case UNMATCHED_TYPES_STMT_ASSIGNMENT_ARRAY_NO_INDEX:
    {
        msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_STMT_ASSIGNMENT_ARRAY_NO_INDEX, NULL, NULL, NULL);
        break;
    }
    case UNMATCHED_TYPES_STMT_ASSIGNMENT_INDEX:
    {
        msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_STMT_ASSIGNMENT_INDEX,"indexar",type_a,NULL);
        break;
    }
    default:
        break;
    }

    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_unmatched_types_statement_while(unsigned long err_line, char *type){
    // -- Construir mensaje de error
    char *msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_STMT_WHILE, NULL, type, NULL);

    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_unmatched_types_statement_for(error_semantic_type_checking_t kind,unsigned long err_line, char *type_a, char *type_b){
    // -- Construir mensaje de error 
    char *msg = NULL;
    switch (kind)
    {
    case UNMATCHED_TYPES_STMT_FOR_INDEX:
    {
        msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_STMT_FOR_INDEX,NULL,type_a,NULL);
        break;
    }
    case UNMATCHED_TYPES_STMT_FOR_INIT:
    {
        msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_STMT_FOR_INIT,"asignar",type_a,type_b);
        break;
    }
    case UNMATCHED_TYPES_STMT_FOR_END_EXR:
    {
        msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_STMT_FOR_END_EXR,"fin",type_a,NULL);
        break;
    }
    default:
        msg = NULL;
    }

    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_unmatched_types_statement_ifelse(unsigned long err_line, char *type){
    // -- Construir mensaje de error
    char *msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_STMT_IF_ELSE,NULL,type,NULL);

    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_unmatched_types_statement_fork(unsigned long err_line, char *type){
    // -- Construir mensaje de error
    char *msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_STMT_FORK,NULL,type,NULL);
    
    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_unmatched_types_statement_join(unsigned long err_line, char *type){
    // -- Construir mensaje de error
    char *msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_STMT_JOIN,NULL,type,NULL);
    
    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_unmatched_types_statement_procedure_inv(unsigned long err_line, char *name, int position, char *type_a, char *type_b){
    // -- Construir mensaje de error
    const unsigned int BUFF_SIZE = 512;
    char sub_buff[BUFF_SIZE];

    sprintf(sub_buff, "%s (argumento: %d)",name,position);
    char *action = strndup(sub_buff, strlen(sub_buff));

    char *msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_STMT_PROCEDURE_INV,action,type_a,type_b);

    free(action); action = NULL;

    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_unmatched_types_expression_function_inv(unsigned long err_line, char *name , int position, char *type_a, char *type_b){
    // -- Construir mensaje de error
    const unsigned int BUFF_SIZE = 512;
    char sub_buff[BUFF_SIZE];

    sprintf(sub_buff, "%s (argumento: %d)",name,position);
    char *action = strndup(sub_buff, strlen(sub_buff));

    char *msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_EXPR_FUNCTION_INV,action,type_a,type_b);

    free(action);

    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_unmatched_types_process_vector(error_semantic_type_checking_t kind, unsigned long err_line, char *type){
    // -- Construir mensaje de error
    char *msg;
    switch (kind)
    {
    case UNMATCHED_TYPES_PROC_VECTOR_INDEX:
    {
        msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_PROC_VECTOR_INDEX, NULL, type,NULL);
        break;
    }
    case UNMATCHED_TYPES_PROC_VECTOR_START_RANGE:
    {
        msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_PROC_VECTOR_START_RANGE, NULL, type,NULL);
        break;
    }
    case UNMATCHED_TYPES_PROC_VECTOR_END_RANGE:
    {
        msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_PROC_VECTOR_END_RANGE, NULL, type,NULL);
        break;
    }
    
    default:
        break;
    }

    return create_error_semantic_unmatched_types(err_line, &msg);
}

struct error * create_error_semantic_unmatched_types_subprogram_function_return(unsigned long err_line, char *name, char *type_a, char *type_b){
    // -- Construir mensaje de error
    char *msg = create_message_error_semantic_unmatched_types(UNMATCHED_TYPES_SUBPROG_FUNCTION_RETURN,name,type_a,type_b);

    return create_error_semantic_unmatched_types(err_line, &msg);
}


// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE IMPRESION DE ERRORES (SEMANTICOS) ----

void print_list_error_semantic(struct error *list_errors, FILE * output){
    // -- Si NULL, simplemente devolver
    if(!list_errors){
        fprintf(output," <NONE>\n");
        return;
    }

    // -- Recorrer la lista enlazada de errores
    struct error * current_error = list_errors;
    while(current_error){
        // -- Imprimir mensaje de error
        fprintf(output,"Error semantico en la linea [%ld]: \n --> %s", current_error->err_line, current_error->msg);

        switch (current_error->err_data.error_semantic.kind)
        {
        case UNMATCHED_TYPES:
        {
            fprintf(output,".\n");
            break;
        }
        
        default:
        {
            fprintf(output,": [%s].", current_error->err_data.error_semantic.id);
            // -- Especificar mas detalles del error dependiendo de casos
            switch (current_error->err_data.error_semantic.kind)
            {
            case DUPLICATED_SYMBOL:
                fprintf(output," Primero se definio aqui: linea [%ld].\n", current_error->err_data.error_semantic.def_line);
                break;

            case DUPLICATED_SYMBOL_PARAM:
                fprintf(output," Primero se definio aqui: posicion de lista [%d].\n", current_error->err_data.error_semantic.which);
                break;
            
            default:
                fprintf(output,"\n");
                break;
            }
            break;
        }
        }
        
        fprintf(output,"\n");
        

        // -- Ir al siguiente error
        current_error = current_error->next;
    }
}
