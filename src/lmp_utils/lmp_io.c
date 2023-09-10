/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_io.h
 * @author Daniel Perez Ruiz
 * @brief 
 */

#include "lmp_utils/lmp_io.h"

// ===============================================================

// ----- VARIABLES GLOBALES DE GESTION (I/O) -----

// Numero de argumentos requeridos por el compilador
const int N_ARGUMENTS_REQUIRED = 2;

// Puntero a fichero a analizar por el compilador
FILE * file_parsed = NULL;

// Nombre de fichero
char * file_parsed_name = NULL;

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE AYUDA -----

void print_help(const char *compiler){
    printf(">>>> USO DE COMPILADOR: %s <nombre_fichero.lmp>\n", compiler);
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION (I/O) -----

int abrir_fichero(const char *name_file){
    // -- Definir tipo de apertura de fichero
    const char * FOPEN_MODE = "r";

    // -- Abrir fichero e intentar asignar a puntero
    file_parsed = fopen(name_file, FOPEN_MODE);

    // -- Comprobar exito de apertura de fichero
    if(!file_parsed){
        printf("%s %s : %s\n", LMP_IO_ERROR_MSG_HEADER, LMP_IO_FOPEN_ERROR_MSG, name_file);
        return LMP_IO_FAILURE;
    }

    // -- Almacenar nombre de fichero
    file_parsed_name = strdup(name_file);
    if(!file_parsed_name){
        printf("%s %s : %s\n", LMP_IO_ERROR_MSG_HEADER, LMP_IO_FOPEN_NAMEFILE_ERROR_MSG, name_file);
        return LMP_IO_FAILURE;
    }

    // -- Indicar a flex el fichero
    yyin = file_parsed;

    // -- Retornar exito
    return LMP_IO_SUCCESS;
}

int cerrar_fichero(){
    // -- Liberar el nombre de archivo
    if(file_parsed_name){
        free(file_parsed_name);
        file_parsed_name = NULL;
    }

    // -- Intentar cerrar fichero
    if(fclose(file_parsed) == EOF){
        printf("%s %s\n", LMP_IO_ERROR_MSG_HEADER, LMP_IO_FCLOSE_ERROR_MSG);
        return LMP_IO_FAILURE;
    }

    // -- Retornar exito
    return LMP_IO_SUCCESS;
}

// ===============================================================

// ----- IMPLEMENTACION DE FUNCIONES DE GESTION (STRING REGISTER) -----

void lmp_free_string_register(){
    free_string_register();
}