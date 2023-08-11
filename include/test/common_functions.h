/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file common_functions.h
 * @author Daniel Perez Ruiz
 * @brief Definicion del prototipo de funciones comunes a todos los ficheros de testeo
 */

#ifndef _LAMPORT_COMMON_FUNCTIONS_DPR_
#define _LAMPORT_COMMON_FUNCTIONS_DPR_

// -- Macro que define la capacidad maxima de lineas que lee el buffer
#define BUFF_MAX_LINES 1000 
// -- Macro que define la longitud maxima de linea
#define BUFF_MAX_LINE_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Tipo de dato que representa un buffer de almacenamiento de lineas
 * de un fichero. Consta de una matriz y un entero contador de lineas
 */
typedef struct{
    // -- Almacenador de lineas de fichero
    char lines[BUFF_MAX_LINES][BUFF_MAX_LINE_SIZE];
    // -- Contador de lineas leidas
    int total_lines;
} Buffer;

/**
 * @brief Crea un nuevo buffer
 * @return Puntero al buffer creado
 */
Buffer* crear_buffer();

/**
 * @brief Destruye el buffer, liberando los recursos asignados al mismo
 * @param buff : Puntero al buffer
 */
void destruir_buffer(Buffer* buff);

/**
 * @brief Lee el fichero pasado como parametro y almacena su contenido en memoria del buffer
 * @param filename : Nombre del fichero a leer
 * @param buff : Buffer de almacenamiento
 * @param remove_newline : Indicar si se debe eliminar el salto de linea final o no
 * @return numero de lineas leidas ; -1 en caso de fallo
 */
int leer_fichero(const char* filename, Buffer* buff, int remove_newline);

/**
 * @brief Condensa todas las lineas del buffer en una unica cadena de caracteres
 * @param buff : Buffer de almacenamiento
 * @return cadena de caracteres con todas las lineas conjuntas
 */
char* zip_buffer(Buffer* buff);

#endif //_LAMPORT_COMMON_FUNCTIONS_DPR_
