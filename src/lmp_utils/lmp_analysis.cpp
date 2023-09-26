/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_analysis.c
 * @author Daniel Perez Ruiz
 * @brief 
 */

#include "lmp_utils/lmp_analysis.hpp"

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PRIVADOS [ANALYZER] -----

bool LMP_Analyzer::exec_parser(){
    // -- Ejecutar parser
    yyparse();

    // -- Retornar exito de analisis
    return get_total_error_syntax() == 0;
}

bool LMP_Analyzer::exec_semantic(){
    // -- Definir resultado de operacion
    bool result_semantic = true;

    // -- Inicializar tabla de simbolos
    result_semantic = initialize_symbol_table() == 0;

    // -- Realizar resolucion de nombres
    if(result_semantic){
        resolve_program(AST_program);
        result_semantic = get_total_error_semantic() == 0;
    }

    // -- Realizar typechecking
    if(result_semantic){
        typecheck_program(AST_program);
        result_semantic = get_total_error_semantic() == 0;
    }

    // -- Retornar exito de analisis
    return result_semantic;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICO [ANALYZER] -----

LMP_Analyzer::~LMP_Analyzer(){
    // -- Liberar registro de cadenas
    free_string_register();

    // -- Liberar modulos de error (sintactico)
    free_list_error_syntax();

    // -- Liberar modulos de error (sintactico)
    free_list_error_semantic();

    // -- Liberar AST
    free_program(AST_program);

    // -- Liberar tabla de simbolos
    free_symbol_table();
}

int LMP_Analyzer::start(){
    // -- Realizar analisis sintactico
    if(!this->exec_parser()){
        report_list_error_syntax(stdout);
        return EXIT_FAILURE;
    }

    // -- Realizar analisis semantico
    if(!this->exec_semantic()){
        report_list_error_semantic(stdout);
        return EXIT_FAILURE;
    }

    // -- Imprimir AST
    print_AST(AST_program,stdout);

    // -- Imprimir mensaje de exito
    std::cout << "Resolucion de nombres (name_resolution) y comprobacion de tipos (type_checking) realizados correctamente!" << std::endl;

    // -- Retornar exito
    return EXIT_SUCCESS;
}