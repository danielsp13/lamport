/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_logging.h
 * @author Daniel Perez Ruiz
 * @brief Gestor de registro de eventos de lamport
 */

#ifndef _LMP_COMPILER_LOGGING_DPR_
#define _LMP_COMPILER_LOGGING_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE C -----

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

// ===============================================================

// ----- INCLUSION DE MODULOS -----

#include "lmp_analysis.h"       ///< Modulo de analisis de codigo lamport

// ===============================================================

// ----- DEFINICION DE ESTADOS -----

#define LMP_LOGGING_SUCCESS 0        ///< Operacion de logging efectuada con exito
#define LMP_LOGGING_FAILURE -1       ///< Operacion de logging fallida

#define LMP_ERR_LOGGING_CREATE_DIR_MSG "no se pudo crear el directorio de logging:"
#define LMP_ERR_LOGGING_CREATE_FILE_MSG "no se pudo crear el fichero de logging:"

// ===============================================================

// ----- VARIABLES GLOBALES DE LOGGING -----

// Variable que contiene el fichero de registro de eventos
extern FILE * LMP_LOGGING_EVENTS_FILE;

// Variable que contiene el fichero de registro de Errores
extern FILE * LMP_LOGGING_ERRORS_FILE;

// Variable que contiene el fichero de registro de AST
extern FILE * LMP_LOGGING_AST_FILE;

// Variable que contiene el fichero de registro de IR
extern FILE * LMP_LOGGING_IR_FILE;

// ===============================================================

// ----- VARIABLES GLOBALES DE GESTION -----

// Variable que contiene el nombre del directorio donde se guardaran los ficheros de logging
extern const char * LMP_LOGGING_DIR;

// Variable que contiene el nombre del directorio donde se almacenara el registro de eventos
extern const char * LMP_EVENTS_DIR;

// Variable que contiene el nombre del directorio donde se almacenaran los errores encontrados
extern const char * LMP_ERRORS_DIR;

// Variable que contiene el nombre del directorio donde se almacenara el AST del programa
extern const char * LMP_AST_DIR;

// Variable que contiene el nombre del directorio donde se almacenara la representacion intermedia del programa
extern const char * LMP_IR_DIR;

// Variable que contiene el nombre de la extension de fichero de logging
extern const char * LMP_LOGGING_FILE_EXT;

// Variable que contiene el nombre de cabecera de fichero de logging de eventos
extern const char * LMP_LOGGING_FILE_EVENTS_HEADER;

// Variable que contiene el nombre de cabecera de fichero de logging de errores
extern const char * LMP_LOGGING_FILE_ERRORS_HEADER;

// Variable que contiene el nombre de cabecera de fichero de logging de AST
extern const char * LMP_LOGGING_FILE_AST_HEADER;

// Variable que contiene el nombre de cabecera de fichero de logging de IR
extern const char * LMP_LOGGING_FILE_IR_HEADER;

// Variable que contiene el nombre de fichero que se va a crear para los registros
extern char * LMP_LOGGING_NAME_FILE;

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE DIRECTORIOS -----

/**
 * @brief Crea un directorio en el sistema
 * @param dirname : nombre de directorio
 * @return LMP_LOGGING_SUCCESS si se realizo con exito, LMP_LOGGING_FAILURE en otro caso
 */
int create_dir(const char * dirname);

/**
 * @brief Comprueba si un directorio existe
 * @param dirname : nombre de directorio
 * @return TRUE (1) si directorio existe, FALSE (0) si directorio no existe
 */
int check_dir(const char * dirname);

/**
 * @brief Crea el directorio de logging para compilador
 * @param lmp_file : nombre de fichero con el que se crearan los registros de compilador
 * @return LMP_LOGGING_SUCCESS si se crea con exito, LMP_LOGGING_FAILURE en otro caso
 */
int lmp_create_logging_dir(char *lmp_file);

/**
 * @brief Crea el directorio de logging de eventos para compilador
 * @return LMP_LOGGING_SUCCESS si se crea con exito, LMP_LOGGING_FAILURE en otro caso
 */
int lmp_create_logging_events_dir();

/**
 * @brief Crea el directorio de logging de errores para compilador
 * @return LMP_LOGGING_SUCCESS si se crea con exito, LMP_LOGGING_FAILURE en otro caso
 */
int lmp_create_logging_errors_dir();

/**
 * @brief Crea el directorio de logging de AST para compilador
 * @return LMP_LOGGING_SUCCESS si se crea con exito, LMP_LOGGING_FAILURE en otro caso
 */
int lmp_create_logging_ast_dir();

/**
 * @brief Crea el directorio de logging de representacion intermedia para compilador
 * @return LMP_LOGGING_SUCCESS si se crea con exito, LMP_LOGGING_FAILURE en otro caso
 */
int lmp_create_logging_ir_dir();

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE FICHEROS DE LOGGING -----

/**
 * @brief Asigna el nombre de fichero analizado por el compilador al buffer de nombre de logging
 * @param namefile : fichero lamport analizado por el compilador
 * @return LMP_LOGGING_SUCCESS si se asigno con exito, LMP_LOGGING_FAILURE en otro caso
 */
int assign_name_file_to_buff(char *namefile);

/**
 * @brief Libera la memoria reservada para el almacenamiento del nombre de fichero lamport
 */
void free_name_file_from_buff();

/**
 * @brief Construye un nombre de fichero de logging
 * @param logging_dir : directorio de destino del fichero logging
 * @param logging_header : nombre de cabecera de logging
 * @return cadena dinamica de caracteres con el nombre creado (NULL en otro caso)
 */
char * create_logging_name_file(const char * logging_dir, const char * logging_header);

/**
 * @brief Crea un fichero de logging e inicializa su puntero
 * @param namefile : puntero a nombre de fichero de logging
 * @param f : puntero a fichero
 * @return LMP_LOGGING_SUCCESS si se creo con exito, LMP_LOGGING_FAILURE en otro caso
 */
int create_logging_file(char **namefile, FILE ** f);

/**
 * @brief Crea el fichero de logging de eventos de compilador
 * @return LMP_LOGGING_SUCCESS si se creo con exito, LMP_LOGGING_FAILURE en otro caso
 */
int lmp_create_logging_events_file();

/**
 * @brief Crea el fichero de logging de errores de compilacion
 * @return LMP_LOGGING_SUCCESS si se creo con exito, LMP_LOGGING_FAILURE en otro caso
 */
int lmp_create_logging_errors_file();

/**
 * @brief Crea el fichero de logging de generacion de AST
 * @return LMP_LOGGING_SUCCESS si se creo con exito, LMP_LOGGING_FAILURE en otro caso
 */
int lmp_create_logging_AST_file();

/**
 * @brief Crea el fichero de logging de generacion de IR
 * @return LMP_LOGGING_SUCCESS si se creo con exito, LMP_LOGGING_FAILURE en otro caso
 */
int lmp_create_logging_IR_file();

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE USO DE LOGGING -----

void lmp_initialize_logging(char *lmp_file);

void lmp_initialize_logging_events();

void lmp_initialize_logging_errors();

void lmp_initialize_logging_AST();

void lmp_initialize_logging_IR();

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE LIBERACION -----

/**
 * @brief Libera la memoria utilizada para el registro de eventos
 */
void free_logging_events_file();

/**
 * @brief Libera la memoria utilizada para el registro de errores
 */
void free_logging_errors_file();

/**
 * @brief Libera la memoria utilizada para el registro de AST
 */
void free_logging_AST_file();

/**
 * @brief Libera la memoria utilizada para el registro de IR
 */
void free_logging_IR_file();

/**
 * @brief Libera la memoria utilizada para todos los registros
 */
void free_logging_files();

/**
 * @brief Libera todo los recursos utilizados por el logging
 */
void lmp_free_logging();


#endif //_LMP_COMPILER_LOGGING_DPR_