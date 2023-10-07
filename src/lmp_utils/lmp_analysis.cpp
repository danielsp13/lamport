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
        tasker.task_semantic_name_resolution();
        resolve_program(AST_program);
        result_semantic = get_total_error_semantic() == 0;

        if(result_semantic)
            tasker.task_ok();
        else
            tasker.task_nop();
    }

    // -- Realizar typechecking
    if(result_semantic){
        tasker.task_semantic_type_checking();
        typecheck_program(AST_program);
        result_semantic = get_total_error_semantic() == 0;

        if(result_semantic)
            tasker.task_ok();
        else
            tasker.task_nop();
    }

    // -- Retornar exito de analisis
    return result_semantic;
}

// ===============================================================

// ----- IMPLEMENTACION DE METODOS PUBLICO [ANALYZER] -----

LMP_Analyzer& LMP_Analyzer::get_instance(){
    static LMP_Analyzer instance;
    return instance;
}

LMP_Analyzer::~LMP_Analyzer(){
    if(this->ANALYZER_STATE){
        // -- Desactivar analizador
        ANALYZER_STATE = false;

        tasker.task_free_resources();

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

        tasker.task_ok();
    }
}

int LMP_Analyzer::start(bool verbose_avaiable){
    // -- Realizar analisis sintactico
    tasker.task_parser();
    if(!this->exec_parser()){
        tasker.task_nop();
        report_list_error_syntax(stdout);
        return EXIT_FAILURE;
    }
    tasker.task_ok();

    // -- Realizar analisis semantico
    if(!this->exec_semantic()){
        report_list_error_semantic(stdout);
        return EXIT_FAILURE;
    }

    if(verbose_avaiable){
        // -- Imprimir AST
        print_AST(AST_program,stdout);

        // -- Imprimir mensaje de exito
        std::cout << "Resolucion de nombres (name_resolution) y comprobacion de tipos (type_checking) realizados correctamente!" << std::endl << std::endl;
    }

    // -- Retornar exito
    return EXIT_SUCCESS;
}