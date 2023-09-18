/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_io.h
 * @author Daniel Perez Ruiz
 * @brief 
 */

#ifndef _LMP_COMPILER_IO_DPR_
#define _LMP_COMPILER_IO_DPR_

// ===============================================================

// ----- DEFINICION DE MACROS PARA GESTION DE I/O -----

#define LMP_IO_SUCCESS 0    ///< Indica el exito de suceso en un procedimiento de entrada/salida
#define LMP_IO_FAILURE -1   ///< Indica el fallo de suceso en un procedimiento de entrada/salida

#define LMP_IO_ERROR_MSG_HEADER "--- [LMP: I/O - ERROR]"
#define LMP_IO_FOPEN_ERROR_MSG "No se pudo abrir el archivo de entrada"
#define LMP_IO_FOPEN_NAMEFILE_ERROR_MSG "No se pudo recuperar el nombre de archivo de entrada"
#define LMP_IO_FCLOSE_ERROR_MSG "No se pudo cerrar el archivo"

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE C -----

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===============================================================

// ----- IMPORTACION DE FUNCIONES Y VARIABLES EXTERNAS (FLEX/BISON) -----

/**
 * @brief Variable global definida por Flex. Puntero al archivo de entrada del
 * que se leera el texto fuente para el analisis lexico.
 */
extern FILE *yyin;

// ===============================================================

// ----- VARIABLES GLOBALES DE GESTION (I/O) -----

/**
 * @brief Numero de argumentos requeridos para el funcionamiento del compilador.
 */
extern const int N_ARGUMENTS_REQUIRED; ///< Se requiere nombre de compilador + fichero de lectura

/**
 * @brief Puntero al archivo a analizar por el compilador.
 */
extern FILE * file_parsed;

/**
 * @brief Nombre del fichero a analizar por el compilador
 */
extern char * file_parsed_name;

// ===============================================================

// ----- VARIABLES COSMETICAS -----

// Cadena para separacion de contenidos
extern const char *HEADER_SEPARATOR;

// Cadena con la version actual de compilador
extern const char *COMPILER_VERSION;

// Cadena con el autor del compilador
extern const char *AUTHOR;

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE AYUDA -----

/**
 * @brief Imprime informacion del compilador
 * @param compiler : Nombre del compilador
 */
void print_header(const char *compiler);

/**
 * @brief Imprime la forma de uso de compilador
 * @param compiler : Nombre del compilador
 */
void print_help(const char *compiler);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION (I/O) -----

/**
 * @brief Dado el nombre de un fichero, esta funcion inicia el procedimiento
 * para abrirlo para el analisis del compilador
 * @param name_file : Nombre del fichero
 * @return LMP_IO_SUCCESS si se ha abierto el fichero adecuadamente, LMP_IO_FAILURE en otro caso
 */
int abrir_fichero(const char *name_file);

/**
 * @brief Cierra el fichero abierto para el analisis del compilador
 * @return LMP_IO_SUCCESS si se ha cerrado el fichero adecuadamente, LMP_IO_FAILURE en otro caso
 */
int cerrar_fichero();

#endif //_LMP_COMPILER_IO_DPR_