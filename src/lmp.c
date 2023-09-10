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

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE COMPILADOR -----

/**
 * @brief Libera la memoria reservada por todos los modulos
 */
void lmp_free();

// ===============================================================

// ----- PROGRAMA PRINCIPAL -----

int main(int argc, char **argv){
    // -- 0. Comprobar numero de argumentos
    if(argc < N_ARGUMENTS_REQUIRED){
        // -- Imprimir mensaje de uso
        print_help(argv[0]);
        // -- Salir con error
        exit(EXIT_FAILURE);
    }

    // -- 1. Abrir fichero 
    if(abrir_fichero(argv[1]) < LMP_IO_SUCCESS){
        // -- Salir con error
        exit(EXIT_FAILURE);
    }

    // ---------------------------------------------------------

    // -- 2. Realizar parsing
    if(lmp_parsing_file() < LMP_PARSING_SUCCESS){
        // -- Imprimir mensaje de error
        fprintf(stdout,"%s %s : %s\n", LMP_PARSING_ERROR_MSG_HEADER, LMP_PARSING_ERROR_MSG, file_parsed_name);
        
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
    printf("\nRESOLUCION DE NOMBRES REALIZADA CON EXITO!!!\n");

    // -- Liberar memoria utilizada por los modulos
    lmp_free();

    // -- Retorno
    return EXIT_SUCCESS;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION DE COMPILADOR -----

void lmp_free(){
    // -- Liberar memoria utilizada por el AST
    lmp_free_AST();

    // -- Liberar registro de cadenas
    lmp_free_string_register();

    // -- Liberar tabla de simbolos
    lmp_free_symbol_table();

    // -- Liberar gestor de errores semanticos
    lmp_free_error_module();
}