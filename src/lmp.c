/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp.c
 * @author Daniel Perez Ruiz
 * @brief Programa principal del compilador de lamport
 */

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE C -----

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===============================================================

// ----- INCLUSION DE COMPONENTES DE GESTION DE COMPILADOR -----

#include "lmp_utils/lmp_io.h"         ///< Gestion de entrada/salida de lmp
#include "lmp_utils/lmp_analysis.h"   ///< Parsing de fichero de lmp

// ===============================================================

// ----- DEFINICION DE VARIABLES DE CONTROL -----

// -- Variable de control de errores sintacticos
// ---- 0 : No hay errores sintacticos
// ---- 1 : Hay errores sintacticos
unsigned int LMP_SYNTAX_ERROR = 0;

// -- Variable de control de errores semanticos
// ---- 0 : No hay errores semanticos
// ---- 1 : Hay errores semanticos
unsigned int LMP_SEMANTIC_ERROR = 0;

// ===============================================================

// ----- PROTOTIPO DE FUNCION COMPILADOR -----

/**
 * @brief Funcion principal compilador
 * @param num_args : numero de argumentos
 * @param compiler_name : nombre de compilador
 * @param lmp_file : nombre de fichero lamport
 * @return LMP_SUCCESS si la compilacion es exitosa
 */
int lmp(int num_args, char *compiler_name, char *lmp_file);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE COMPILADOR -----

/**
 * @brief Activa el flag de error sintactico a 1
 */
void active_compiler_error_syntax_flag();

/**
 * @brief Activa el flag de error semantico a 1
 */
void active_compiler_error_semantic_flag();

/**
 * @brief Comprueba si se han producido errores sintacticos
 * @return LMP_COMPILER_STATE
 */
unsigned int error_syntax_flag();

/**
 * @brief Libera la memoria reservada por todos los modulos
 */
void lmp_free();

// ===============================================================

// ----- PROGRAMA PRINCIPAL -----

int main(int argc, char **argv){
    //test();
    // -- Utilizar compilador
    return lmp(argc,argv[0],argv[1]);
}

// ===============================================================

// ----- PROTOTIPO DE FUNCION COMPILADOR -----

int lmp(int num_args, char *compiler_name, char *lmp_file){
    // -- 0.A Imprimir cabecera
    print_header(compiler_name);

    // -- 0.B Comprobar numero de argumentos
    if(num_args < N_ARGUMENTS_REQUIRED){
        // -- Imprimir mensaje de uso
        print_help(compiler_name);
        // -- Salir con error
        exit(EXIT_FAILURE);
    }

    // -- 1. Abrir fichero 
    if(abrir_fichero(lmp_file) < LMP_IO_SUCCESS){
        // -- Salir con error
        exit(EXIT_FAILURE);
    }

    // ---------------------------------------------------------

    // -- 2. Realizar parsing
    if(lmp_parsing_file() < LMP_PARSING_SUCCESS){
        // -- Activar flag
        active_compiler_error_syntax_flag();

        // -- Reportar errores sintacticos
        lmp_print_error_syntax();

        // -- Cerrar fichero y limpiar AST
        cerrar_fichero();

        // -- Liberar memoria de todos los modulos
        lmp_free();

        // -- Salir con error
        exit(EXIT_FAILURE);
    }

    // -- 3. Cerrar fichero
    if(cerrar_fichero() < LMP_IO_SUCCESS){
        // -- Salir con error
        exit(EXIT_FAILURE);
    }

    // -- 4. Realizar analisis semantico
    if(lmp_semantic_analysis() < LMP_SEMANTIC_SUCCESS){
        // -- Activar flag
        //active_compiler_error_semantic_flag();

        // -- Reportar errores semanticos
        lmp_print_error_semantic();

        // -- Liberar memoria de todos los modulos
        lmp_free();

        // -- Salir con error
        exit(EXIT_FAILURE);
    }

    // -- . Imprimir AST
    lmp_print_AST();

    // -- Imprimir exito en la resolucion de nombres
    printf("\nRESOLUCION DE NOMBRES Y TYPE_CHECKING REALIZADOS CON EXITO!!!\n");

    // -- Liberar memoria utilizada por los modulos
    lmp_free();

    // -- Retorno
    return EXIT_SUCCESS;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE COMPILADOR -----

void active_compiler_error_syntax_flag(){
    LMP_SYNTAX_ERROR = 1;
}

unsigned int error_syntax_flag(){
    return LMP_SYNTAX_ERROR;
}

void lmp_free(){
    // -- Liberar registro de cadenas
    lmp_free_string_register();

    // -- Liberar memoria utilizada por el AST
    lmp_free_AST();
    
    // -- Liberar tabla de simbolos
    lmp_free_symbol_table();

    // -- Liberar gestor de errores semanticos
    lmp_free_error_module();
}