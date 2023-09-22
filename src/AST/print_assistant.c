/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file print_assistant.c
 * @author Daniel Perez Ruiz
 * @brief Implementacion de funciones de asistencia a la
 * impresion del AST del lenguaje lamport
 */

#include "AST/print_assistant.h"

// ===============================================================

// ----- DEFINICION DE CONSTANTES DE IMPRESION -----

// Define el simbolo de inicio de identacion (rama)
const char IDENT_INIT_BRANCH_SYMBOL = '|';

// Define el simbolo que se utilizara para la identacion (rama)
const char IDENT_BRANCH_SYMBOL = '-';

// Define el simbolo que se utilizara para la identacion
const char IDENT_SYMBOL = ' ';          ///< Espacio en blanco

// Define la cabecera de nodo
const char * IDENT_ARROW = "---->";     ///< Una flecha de longitud 4

// Define la identacion propia del nodo
const char * IDENT_BLANK_ARROW = "     ";

// Define un separador
const char * SEPARATOR = "================================================================";

// Define el mensaje por defecto cuando un nodo es nulo
const char * NULL_NODE_MSG = "<NONE>";  ///< Se indica NONE, para mayor claridad

// Define el mensaje por defecto para un valor indefinido
const char * UNDEFINED_VALUE_MSG = "<UNDEFINED>";

// Define la profundidad inicial para las declaraciones de un programa
const unsigned int DEPTH_PROGRAM_DECLARATIONS = 1;

// Define la profundidad inicial para los subprogramas de un programa
const unsigned int DEPTH_PROGRAM_SUBPROGRAMS = 1;

// Define la profundidad inicial para los procesos de un programa
const unsigned int DEPTH_PROGRAM_PROCESS = 1;

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE ASISTENCIA -----

char * build_identation_using_depth(unsigned int depth, char init_symbol, char symbol){
    // -- Definir numero de repeticiones de simbolo de identacion por hueco
    const unsigned int N_REP_IDENT_SYMBOL = 2;
    const unsigned int size_ident = N_REP_IDENT_SYMBOL*depth;

    // -- Almacenar memoria para la identacion
    char *ident = malloc((size_ident+2)*sizeof(*ident));

    // -- Comprobar reserva de memoria exitosa
    if(!ident)
        return NULL;

    // -- Definir simbolo de inicio
    ident[0] = init_symbol;

    // -- Realizar identacion
    for(unsigned int i=1; i<=size_ident; i++){
        ident[i] = symbol;
    }

    // -- Agregar al final la cadena de terminacion
    ident[size_ident] = '\0';

    // -- Retornar identacion adecuada
    return ident;
}

char * build_identation_spaces(unsigned int depth){
    return build_identation_using_depth(depth,IDENT_INIT_BRANCH_SYMBOL,IDENT_SYMBOL);
}

char * build_identation_branch(unsigned int depth){
    return build_identation_using_depth(depth,IDENT_INIT_BRANCH_SYMBOL,IDENT_BRANCH_SYMBOL);
}

void print_AST_separation(FILE * output){
    fprintf(output,"%s\n\n",SEPARATOR);
}