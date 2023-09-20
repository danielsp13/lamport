/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file symbol.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de estructuras y funciones para creacion y mantenimiento
 * de un simbolo
 */

#include "semantic/symbol.h"

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE CONSTRUCCION DE SIMBOLOS -----

struct symbol * create_symbol(symbol_t kind, struct type * type, char * name, int which, unsigned long line){
    struct symbol * symb = malloc(sizeof(*symb));

    // -- Comprobar reserva de memoria exitosa
    if(!symb)
        return NULL;

    // -- Asignar tipo de simbolo (symbol_t y str)
    symb->kind = kind;
    switch (symb->kind)
    {
    case SYMBOL_LOCAL:
    {
        symb->kind_str = strdup("SYMBOL_LOCAL");
        break;
    }
    
    case SYMBOL_GLOBAL:
    {
        symb->kind_str = strdup("SYMBOL_GLOBAL");
        break;
    }

    case SYMBOL_PARAM:
    {
        symb->kind_str = strdup("SYMBOL_PARAM");
        break;
    }
    }
    // -- Comprobar asignacion de tipo de simbolo (str) exitosa
    if(!symb->kind_str){
        // -- Liberar memoria reservada para simbolo
        free(symb);
        return NULL;
    }

    // -- Asignar tipo de dato de simbolo
    symb->type = copy_type(type);
    // -- Asignar lista de tipos de parametro
    symb->list_type_parameters = NULL;

    // -- Asignar nombre de variable de simbolo
    symb->name = strdup(name);
    // -- Comprobar asignacion de nombre exitosa
    if(!symb->name){
        // -- Liberar memoria reservada para simbolo
        free(symb);
        return NULL;
    }

    // -- Asignar posicion en la lista de parametros de simbolo
    symb->which = which;

    // -- Asignar linea en la que se encontro el simbolo
    symb->line = line;

    // -- Retornar simbolo creado e inicializado
    return symb;
}

struct symbol * create_symbol_local(struct type * type, char * name, unsigned long line){
    return create_symbol(SYMBOL_LOCAL, type, name, -1, line);
}

struct symbol * create_symbol_global(struct type * type, char * name, unsigned long line){
    return create_symbol(SYMBOL_GLOBAL, type, name, -1, line);
}

struct symbol * create_symbol_global_subprogram(struct type * type, char *name, unsigned long line, struct type *list_type_parameters){
    struct symbol * symb = create_symbol(SYMBOL_GLOBAL_SUBPROGRAM, type, name, -1, line);

    // -- Comprobar creacion de simbolo exitoso
    if(!symb)
        return NULL;

    // -- Definir lista de simbolos para subprograma (simplemente asignacion de punteros)
    symb->list_type_parameters = list_type_parameters;

    // -- Retornar creacion de simbolo
    return symb;
}

struct symbol * create_symbol_param(struct type * type, char * name, int which, unsigned long line){
    return create_symbol(SYMBOL_PARAM, type, name, which, line);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE LIBERACION DE MEMORIA DE SIMBOLOS -----

void free_symbol(struct symbol * symb){
    // -- Comprobar que symb apunta a algo
    if(!symb)
        return;

    // -- Liberar memoria de tipo de simbolo (str)
    if(symb->kind_str){
        free(symb->kind_str);
        symb->kind_str = NULL;
    }

    // -- Liberar memoria de nombre de variable
    if(symb->name){
        free(symb->name);
        symb->name = NULL;
    }

    if(symb->type){
        free_type(symb->type);
        symb->type = NULL;
    }

    // -- Apuntar a NULL la lista de tipos de parametros
    if(symb->list_type_parameters){
        free_list_types(symb->list_type_parameters);
        symb->list_type_parameters = NULL;
    }

    // -- Liberar simbolo
    free(symb);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE IMPRESION DE SIMBOLOS -----

void print_symbol(struct symbol * symb){
    const char *IDENT_ARROW = "== ";

    // -- Comprobar que symb apunta a algo
    if(!symb){
        printf(" %s <NONE>\n", IDENT_ARROW);
        return;
    }

    // -- Imprimir tipo y nombre de simbolo
    printf(" %s SIMBOLO DE TIPO: [%s] DE NOMBRE: [%s]\n", IDENT_ARROW, symb->kind_str, symb->name);
    // -- Imprimir posicion de la lista de parametros (si kind es acorde)
    if(symb->kind == SYMBOL_PARAM)
        printf(" %s POSICION EN LA LISTA DE PARAMETROS DE PROCEDENCIA: [%d]\n", IDENT_ARROW, symb->which);

    // -- Imprimir tipo de dato simbolo
    printf(" %s INFORMACION DEL TIPO DE DATO DE SIMBOLO: [%s]\n", IDENT_ARROW, symb->name);
    print_AST_type(symb->type,0);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE ASISTENCIA DE USO DE SIMBOLOS -----

struct symbol * copy_symbol(struct symbol *symb){
    if(!symb)
        return NULL;

    // -- Definir copia
    struct symbol *symbol_copy = NULL;

    // -- Obtener atributos originales de simbolo
    symbol_t copy_kind = symb->kind;
    struct type *copy_type_symb = symb->type;
    char *copy_name = symb->name;
    int copy_which = symb->which;
    unsigned long copy_line = symb->line;

    // -- Crear simbolo
    symbol_copy = create_symbol(copy_kind,copy_type_symb,copy_name,copy_which,copy_line);

    // -- Incluir informacion extra
    if(symb->list_type_parameters)
        symbol_copy->list_type_parameters = copy_list_types(symb->list_type_parameters);

    // -- Retornar copia
    return symbol_copy;
}