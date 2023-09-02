/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_analysis.c
 * @author Daniel Perez Ruiz
 * @brief 
 */

#include "lmp_analysis.h"

// ===============================================================

// ----- VARIABLES GLOBALES DE GESTION (AST) -----

struct program * AST_program = NULL;

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION (PARSING) -----

int lmp_parsing_file(){
    // -- Invocar a yyparse para realizar analisis
    int parse_result = yyparse();

    // -- Comprobar resultado
    if(parse_result != LMP_PARSING_SUCCESS)
        return LMP_PARSING_FAILURE;

    // -- Retornar exito
    return LMP_PARSING_SUCCESS;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION (AST) -----

void lmp_print_AST(){
    print_AST(AST_program);
}

void lmp_free_AST(){
    free_program(AST_program);
}