/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file subprogram.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO subprogramas
 */

#include "AST/subprogram.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA CONSTRUCCION DEL AST (SUBPROGRAMAS) -----

struct subprogram * create_subprogram(subprogram_t kind, char *name_subprogram, struct parameter_list *parameters, struct declaration *declarations, struct statement *statements, struct type *type){
    struct subprogram *subprog = malloc(sizeof(*subprog));

    // -- Comprobar reserva de memoria exitosa
    if(!subprog)
        return NULL;

    // -- Asignar tipo de subprograma (subprogram_t y str)
    subprog->kind = kind;
    switch (subprog->kind)
    {
    case SUBPROGRAM_PROCEDURE:
        subprog->kind_str = strdup("procedure");
        break;
    case SUBPROGRAM_FUNCTION:
        subprog->kind_str = strdup("function");
        break;
    default:
        subprog->kind_str = NULL;
        break;
    }

    // -- Comprobar asignacion de tipo de subprograma (str) exitosa
    if(!subprog->kind_str){
        // -- Liberar memoria reservada al subprograma
        free(subprog);
        return NULL;
    }

    // -- Asignar nombre de subprograma
    subprog->name_subprogram = strdup(name_subprogram);
    // -- Comprobar asignacion de nombre de subprograma exitosa
    if(!subprog->name_subprogram){
        // -- Liberar memoria reservada al subprograma
        free(subprog);
        return NULL;
    }

    // -- Asignar parametros del subprograma
    subprog->parameters = parameters;
    // -- Asignar declaraciones del subprograma
    subprog->declarations = declarations;
    // -- Asignar sentencias del subprograma
    subprog->statements = statements;
    // -- Asignar tipo de retorno de subprograma (funciones)
    subprog->type = type;
    // -- Asignar puntero a siguiente subprograma (NULL)
    subprog->next = NULL;

    // -- Asignar puntero de simbolo de tabla de simbolos (NULL)
    subprog->symb = NULL;

    // -- Retornar subprograma creado e inicializado
    return subprog;
}

struct subprogram * create_subprogram_procedure(char *name_procedure, struct parameter_list *parameters, struct declaration *declarations, struct statement *statements){
    return create_subprogram(SUBPROGRAM_PROCEDURE, name_procedure, parameters, declarations, statements, NULL);
}

struct subprogram * create_subprogram_function(char *name_function, struct parameter_list *parameters, struct declaration *declarations, struct statement *statements, struct type *type){
    return create_subprogram(SUBPROGRAM_FUNCTION, name_function, parameters, declarations, statements, type);   
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO SUBPROGRAMAS) -----

void free_list_subprograms(struct subprogram *subprograms_list){
    struct subprogram *current_subprogram = subprograms_list;
    while(current_subprogram){
        // -- Seleccionar siguiente en la lista
        struct subprogram *next = current_subprogram->next;
        // -- Liberar nodo
        free_subprogram(current_subprogram);
        // -- Nodo actual -> siguiente
        current_subprogram = next;
    }
}

void free_subprogram(struct subprogram *subprog){
    // -- Si NULL, simplemente devolver
    if(!subprog)
        return;

    // -- Liberar nombre de subprograma
    if(subprog->name_subprogram){
        free(subprog->name_subprogram);
        subprog->name_subprogram = NULL;
    }

    if(subprog->kind_str){
        free(subprog->kind_str);
        subprog->kind_str = NULL;
    }

    // -- Liberar tipo de subprograma (solo para funciones)
    if(subprog->type){
        free_type(subprog->type);
        subprog->type = NULL;
    }

    // -- Liberar declaraciones del subprograma
    if(subprog->declarations){
        free_list_declarations(subprog->declarations);
        subprog->declarations = NULL;
    }

    // -- Liberar parametros de subprograma (si los tiene)
    if(subprog->parameters){
        free_list_parameters(subprog->parameters);
        subprog->parameters = NULL;
    }

    // -- Liberar sentencias de subprograma (si los tiene)
    if(subprog->statements){
        free_list_statements(subprog->statements);
        subprog->statements = NULL;
    }

    // -- Liberar simbolo de la tabla de simbolos
    subprog->symb = NULL;
    
    // -- Liberar nodo
    free(subprog);
}

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO SUBPROGRAMAS) -----

void print_AST_subprograms(struct subprogram *subprograms_list, unsigned int depth){
    // -- Determinar identacion de nodo
    char * IDENT_NODE_BRANCH = build_identation_branch(depth);
    char * IDENT_NODE = build_identation_spaces(depth);
    // -- Determinar profundidad del siguiente nodo
    const unsigned int NEXT_NODE_DEPTH = depth+1;

    // -- Si NULL, simplemente devolver
    if(!subprograms_list){
        printf("%s%s %s\n",IDENT_NODE_BRANCH, IDENT_ARROW, NULL_NODE_MSG);

        // -- Liberar memoria utilizada para la identacion
        free(IDENT_NODE); IDENT_NODE = NULL; 
        free(IDENT_NODE_BRANCH); IDENT_NODE_BRANCH = NULL;
        
        return;
    }

    struct subprogram *current_subprogram = subprograms_list;
    while(current_subprogram){
        // -- Imprimir nombre y tipo de subprograma
        printf("%s%s NOMBRE DE SUBPROGRAMA: [%s] DE TIPO: [%s]\n",IDENT_NODE_BRANCH, IDENT_ARROW, current_subprogram->name_subprogram, current_subprogram->kind_str);
        // -- Imprimir tipo de funcion
        printf("%s%s TIPO DE DATO DE RETORNO:\n",IDENT_NODE, IDENT_BLANK_ARROW);
        print_AST_type(current_subprogram->type,NEXT_NODE_DEPTH);
        // -- Imprimir parametros de subprograma
        printf("%s%s PARAMETROS DE SUBPROGRAMA:\n",IDENT_NODE, IDENT_BLANK_ARROW);
        print_AST_parameters(current_subprogram->parameters,NEXT_NODE_DEPTH);
        // -- Imprimir declaraciones de subprograma
        printf("%s%s DECLARACIONES DE SUBPROGRAMA:\n",IDENT_NODE, IDENT_BLANK_ARROW);
        print_AST_declarations(current_subprogram->declarations,NEXT_NODE_DEPTH);
        // -- Imprimir sentencias del subprograma
        printf("%s%s SENTENCIAS DE SUBPROGRAMA:\n",IDENT_NODE, IDENT_BLANK_ARROW);
        print_AST_statements(current_subprogram->statements,NEXT_NODE_DEPTH);

        printf("\n");


        // Ir al siguiente subprograma
        current_subprogram = current_subprogram->next;
    }

    // -- Liberar memoria utilizada para la identacion
    free(IDENT_NODE); IDENT_NODE = NULL; 
    free(IDENT_NODE_BRANCH); IDENT_NODE_BRANCH = NULL;
}