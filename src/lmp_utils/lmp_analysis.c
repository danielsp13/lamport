/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_analysis.c
 * @author Daniel Perez Ruiz
 * @brief 
 */

#include "lmp_utils/lmp_analysis.h"

// ===============================================================

// ----- VARIABLES GLOBALES DE GESTION (AST) -----

struct program * AST_program = NULL;

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION (PARSING) -----

int lmp_parsing_file(){
    // -- Invocar a yyparse para realizar analisis
    int parse_result = yyparse();

    // -- Comprobar resultado (con la lista de errores sintacticos)
    if(get_total_error_syntax() > 0){
        return LMP_PARSING_FAILURE;
    }

    // -- Retornar exito
    return LMP_PARSING_SUCCESS;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION (SEMANTIC) -----


int lmp_semantic_name_resolution(){
    // -- Aplicar resolucion de nombres a programa completo
    resolve_program(AST_program);

    // -- Comprobar cuenta de errores de resolucion
    if(get_total_error_semantic() > 0){
        return LMP_SEMANTIC_FAILURE;
    }
    
    return LMP_SEMANTIC_SUCCESS;
}

int lmp_semantic_analysis(){
    int semantic_result = LMP_SEMANTIC_SUCCESS;

    // -- Fase previa, inicializar la tabla de simbolos
    semantic_result += initialize_symbol_table();

    // -- Realizar analisis: resolucion de nombres
    semantic_result += lmp_semantic_name_resolution();

    // -- Retornar resultado de analisis
    return semantic_result;
}

void lmp_free_symbol_table(){
    free_symbol_table();
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION (AST) -----

void lmp_print_AST(){
    print_AST(AST_program);
}

void lmp_free_AST(){
    free_program(AST_program);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION (STRING REGISTER) -----

void lmp_free_string_register(){
    free_string_register();
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION (ERRORES) -----

void lmp_print_error_syntax(){
    report_list_error_syntax();
}

void lmp_print_error_semantic(){
    report_list_error_semantic();
}

void lmp_free_error_module(){
    // -- Liberar listado de errores sintacticos
    free_list_error_syntax();

    // -- Liberar listado de errores semanticos
    free_list_error_semantic();
}