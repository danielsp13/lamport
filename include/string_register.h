/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file string_register.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para manejo
 * de reconocimiento de cadenas de caracteres en el parser y lexer
 */

#ifndef _LMP_STRING_REGISTER_DPR_
#define _LMP_STRING_REGISTER_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// ===============================================================

// ----- DEFINICION DE MACROS -----

#define STRING_REGISTER_SUCCESS 0       ///< Registro de cadena correcto
#define STRING_REGISTER_FAILURE -1      ///< Registro de cadena incorrecto

// ===============================================================

// ----- DEFINICION DE HISTORIAL DE CADENAS DE CARACTERES -----

/**
 * @brief Estructura de datos que colecciona todas las cadenas de caracteres
 * que han sido reconocidas por el analizador lexico. El objetivo es duplicar
 * los valores en este registro para posteriormente manipularlas de forma adecuada,
 * ya sea en el uso del AST, o la liberacion de memoria en el caso de errores sintacticos
 * 
 * Se utilizara este registro cuando:
 * - Se reconozca un IDENT
 * - Se reconozca un LITERAL_STRING
 */
struct StringRegister{
    char * str;                     ///< Cadena de caracteres
    struct StringRegister * next;  ///< Puntero a siguiente registro de cadena
};

// ===============================================================

// ----- DEFINICION DE VARIABLE GLOBAL DE REGISTRO -----

// Variable global encargada de registrar todas las cadenas de caracteres reconocidas
extern struct StringRegister * string_register;

// Variable global encargada de almacenar el ultimo registro efectuado
extern struct StringRegister * last_string_register;

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE REGISTRO -----

/**
 * @brief Crea un nuevo registro de cadena de caracteres
 * @param str : Cadena de caracteres a registrar
 * @return nodo de registro
 */
struct StringRegister * create_string_register(char * str);

/**
 * @brief Inserta una nueva cadena de caracteres al registro global
 * @param str : Cadena de caraceres
 * @return STRING_REGISTER_SUCCESS si se inserto con exito, STRING_REGISTER_FAILURE en otro caso
 */
int add_string_to_register(char * str);

/**
 * @brief Libera toda la memoria reservada para el registro
 */
void free_string_register();

/**
 * @brief Imprime el registro de cadenas
 */
void print_string_register();


#endif //_LMP_PARSER_STRINGS_DPR_