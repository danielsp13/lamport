/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file error_semantic.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para gestion de errores
 * producidos en el analizador semantico
 */

#ifndef _LAMPORT_ERROR_SEMANTIC_DPR_
#define _LAMPORT_ERROR_SEMANTIC_DPR_

#ifdef __cplusplus
extern "C" {
#endif

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "error.h"              ///< Estructura de error

// ===============================================================

// ----- DEFINICION DE MENSAJES DE ERROR ----

// Se indica que se ha usado una variable que no ha sido declarada antes
#define ERR_UNDEFINED_VARIABLE_MSG "uso de variable no declarada"

// Se indica que se ha usado una funcion que no ha sido definida antes
#define ERR_UNDEFINED_FUNCTION_MSG "uso de funcion no definida"

// Se indica que se ha usado un procedimiento que no ha sido definido antes
#define ERR_UNDEFINED_PROCEDURE_MSG "uso de procedimiento no definido"

// Se indica que el numero de argumentos encontrado no es el esperado
#define ERR_UNDEFINED_PARAMETERS_MSG "llamada a subprograma no coincidente con declaracion (faltan/sobran argumentos)"

// Se indica que se definio un array de forma indebida
#define ERR_INVALID_ARRAY_DECLARATION_MSG "no se puede definir un array estatico con una expresion que no es un literal puro."

// Se indica que se ha usado un proceso que no ha sido definido antes
#define ERR_UNDEFINED_PROCESS_MSG "proceso no definido"

// Se indica que se ha redefinido una variable
#define ERR_DUPLICATED_VARIABLE_MSG "redefinicion de variable"

// Se indica que se ha redefinido un proceso
#define ERR_DUPLICATED_PROCESS_MSG "redefinicion de proceso"

// Se indica que se ha redefinido un subprograma
#define ERR_DUPLICATED_SUBPROGRAM_MSG "redefinicion de subprograma"

// Se indica que se ha redefinido un parametro
#define ERR_DUPLICATED_PARAMETER_MSG "redefinicion de parametro"

// Se indica que se ha redefinido un indice
#define ERR_DUPLICATED_INDEX_MSG "redefinicion de indice"

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE ERRORES (SEMANTICOS : NAME RESOLUTION) ----

/**
 * @brief Crea y reserva memoria para un error semantico
 * @param kind : tipo de error semantico
 * @param id : identificador de simbolo
 * @param err_line : linea donde se produjo el error semantico
 * @param msg : mensaje de error
 * @return puntero a error semantico inicializado
 */
struct error * create_error_semantic(error_semantic_t kind, char *id, unsigned long err_line, char *msg);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo: USO DE SIMBOLO NO DEFINIDO
 * @param id : identificador de simbolo
 * @param err_line : linea donde se produjo el error semantico
 * @param msg : mensaje de error
 * @return puntero a error semantico inicializado
 */
struct error * create_error_semantic_undefined_symbol(char *id, unsigned long err_line, char *msg);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo: TOTAL DE ARGUMENTOS DE SUBPROGAMA NO COINCIDENTE
 * @param id : identificador de simbolo
 * @param err_line : linea donde se produjo el error semantico
 * @param msg : mensaje de error
 * @return puntero a error semantico inicializado
 */
struct error * create_error_semantic_invalid_parameters(char *id, unsigned long err_line, char *msg);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo: DEFINCION DE SIMBOLO DUPLICADO
 * @param id : identificador de simbolo
 * @param err_line : linea donde se produjo el error semantico
 * @param def_line : linea donde se definio el simbolo
 * @param msg : mensaje de error
 * @return puntero a error semantico inicializado
 */
struct error * create_error_semantic_duplicated_symbol(char *id, unsigned long err_line, unsigned long def_line, char *msg);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo: DEFINCION DE PARAMETRO DUPLICADO
 * @param id : identificador de simbolo
 * @param line : linea donde se produjo el error semantico
 * @param which : posicion en la lista de parametros donde se encontro el simbolo
 * @param msg : mensaje de error
 */
struct error * create_error_semantic_duplicated_symbol_parameter(char *id, unsigned long line, int which, char *msg);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE ERRORES (SEMANTICOS : TYPE CHECKING) ----

/**
 * @brief Crea y reserva memoria para un MENSAJE de error semantico de tipo: comparacion de tipos incorrecta
 * @param kind : tipo de error semantico de typechecking
 * @param action : accion de operacion
 * @param type_a : nombre de tipo de dato
 * @param type_b : nombre de tipo de dato
 * @return mensaje especificando error semantico de typechecking
 */
char * create_message_error_semantic_unmatched_types(error_semantic_type_checking_t kind, char *action, char *type_a, char *type_b);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo: comparacion de tipos incorrecta
 * @param err_line : linea donde se produjo el error
 * @param msg : mensaje de error
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types(unsigned long err_line, char **msg);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo: definicion de size de array invalido
 * @param err_line : linea donde se produjo el error
 * @param msg : mensaje de error
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_invalid_array_size(unsigned long err_line, char *type_a);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo: definicion de size de array invalido (no literal)
 * @param err_line : linea donde se produjo el error
 * @param msg : mensaje de error
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_invalid_static_array(unsigned long err_line);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo: comparacion de tipos incorrecta (OPERACIONES BINARIAS)
 * @param err_line : linea donde se produjo el error
 * @param type_a : nombre de tipo de dato de operando izquierdo
 * @param type_b : nombre de tipo de dato de operando derecho
 * @param operation : operacion
 * @return puntero a error incializado
 */
struct error * create_error_semantic_unmatched_types_expression_binary(unsigned long err_line, char *type_a, char *type_b, char *operation);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (OPERACIONES UNARIAS)
 * @param err_line : linea donde se produjo el error
 * @param type : nombre de tipo de dato de operando
 * @param operation : operacion
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_expression_unary(unsigned long err_line, char *type, char *operation);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (DECLARACIONES DE VARIABLE)
 * @param err_line : linea donde se produjo el error
 * @param type_a : nombre de tipo de dato de variable
 * @param type_b : nombre de tipo de dato de expresion de asignacion
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_declaration(unsigned long err_line, char *type_a, char *type_b);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (SENTENCIA DE ASIGNACION)
 * @param kind : tipo de asignacion
 * @param err_line : linea donde se produjo el error
 * @param type_a : nombre de tipo de dato de miembro izquierdo
 * @param type_b : nombre de tipo de dato de miembro derecho
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_statement_assignment(error_semantic_type_checking_t kind, unsigned long err_line,char *type_a, char *type_b);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (SENTENCIA WHILE)
 * @param err_line : linea donde se produjo el error
 * @param type : nombre de tipo de dato de condicion de bucle
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_statement_while(unsigned long err_line, char *type);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (SENTENCIA FOR)
 * @param kind : tipo de error en bucle
 * @param err_line : linea donde se produjo el error
 * @param type_a : nombre de tipo de dato
 * @param type_b : nombre de tipo de dato
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_statement_for(error_semantic_type_checking_t kind, unsigned long err_line, char *type_a, char *type_b);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (SENTENCIA IF/ELSE)
 * @param err_line : linea donde se produjo el error
 * @param type : nombre de tipo de dato
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_statement_ifelse(unsigned long err_line, char *type);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (SENTENCIA FORK)
 * @param err_line : linea donde se produjo el error
 * @param type : nombre de tipo de dato
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_statement_fork(unsigned long err_line, char *type);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (SENTENCIA JOIN)
 * @param err_line : linea donde se produjo el error
 * @param type : nombre de tipo de dato
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_statement_join(unsigned long err_line, char *type);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (SEMAPHORE)
 * @param err_line : linea donde se produjo un error
 * @param type : nombre de tipo de dato
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_statement_semaphore(unsigned long err_line, char *type);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (SENTENCIA PROCEDURE INV)
 * @param err_line : linea donde se produjo el error
 * @param name : nombre de procedimiento
 * @param position : posicion de parametro
 * @param type_a : nombre de tipo de dato
 * @param type_b : nombre de tipo de dato
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_statement_procedure_inv(unsigned long err_line, char *name, int position, char *type_a, char *type_b);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (EXPRESION FUNCTION INV)
 * @param err_line : linea donde se produjo el error
 * @param name : nombre de procedimiento
 * @param position : posicion de parametro
 * @param type_a : nombre de tipo de dato
 * @param type_b : nombre de tipo de dato
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_expression_function_inv(unsigned long err_line, char *name , int position, char *type_a, char *type_b);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (PROCESO VECTOR)
 * @param kind : tipo de error en proceso
 * @param line : linea donde se produjo el error
 * @param type : nombre de tipo de dato
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_process_vector(error_semantic_type_checking_t kind, unsigned long line, char *type);

/**
 * @brief Crea y reserva memoria para un error semantico de tipo : comparacion de tipos incorrecta (FUNCTION VS RETURN STATEMENT)
 * @param err_line : linea donde se produjo el error semantico
 * @param name : nombre de funcion
 * @param type_a : nombre de tipo de dato de funcion
 * @param type_b : nombre de tipo de dato de return
 * @return puntero a error inicializado
 */
struct error * create_error_semantic_unmatched_types_subprogram_function_return(unsigned long err_line, char *name, char *type_a, char *type_b);


// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE IMPRESION DE ERRORES (SEMANTICOS) ----

/**
 * @brief Imprime la lista de errores semanticos
 * @param list_errors : lista de errores
 * @param output : destino de impresion
 */
void print_list_error_semantic(struct error *list_errors, FILE * output);

#ifdef __cplusplus
}
#endif

#endif //_LAMPORT_ERROR_SEMANTIC_DPR_