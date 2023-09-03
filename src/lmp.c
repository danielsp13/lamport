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

// ----- INCLUSION DE MODULOS -----

#include "AST/AST.h"                ///< Importacion del AST

// ===============================================================

// ----- INCLUSION DE COMPONENTES DE GESTION DE COMPILADOR -----

#include "lmp_utils/lmp_io.h"         ///< Gestion de entrada/salida de lmp
#include "lmp_utils/lmp_analysis.h"   ///< Parsing de fichero de lmp

// ===============================================================

// ----- PROGRAMA PRINCIPAL -----

int main(int argc, char **argv){
    // -- 0. Comprobar numero de argumentos
    if(argc != N_ARGUMENTS_REQUIRED){
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
    if(lmp_parsing_file() < LMP_IO_SUCCESS){
        // -- Imprimir mensaje de error
        fprintf(stdout,"%s %s : %s\n", LMP_PARSING_ERROR_MSG_HEADER, LMP_PARSING_ERROR_MSG, file_parsed_name);
        
        // -- Cerrar fichero y limpiar AST
        cerrar_fichero();
        lmp_free_AST();

        // -- Liberar registro de cadenas
        free_string_register();

        // -- Salir con error
        exit(EXIT_FAILURE);
    }

    // -- . Cerrar fichero
    if(cerrar_fichero() < LMP_IO_SUCCESS){
        // -- Salir con error
        exit(EXIT_FAILURE);
    }

    // -- . Imprimir AST
    lmp_print_AST();

    // -- . Liberar memoria utilizada para el AST
    lmp_free_AST();

    // -- Liberar registro de cadenas
    free_string_register();

    // -- Retorno
    return EXIT_SUCCESS;
}