/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file statement.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO sentencias
 */

#ifndef _LAMPORT_AST_STATEMENT_DPR_
#define _LAMPORT_AST_STATEMENT_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE NODO -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "expression.h"     ///< Expresiones
#include "type.h"           ///< Parametros (procedimientos y funciones)

// ===============================================================

// ----- DEFINICION DE TIPOS DE SENTENCIAS -----

/**
 * @brief Estructura que representa los tipos de sentencias de lamport.
 */
typedef enum{
    STMT_ASSIGNMENT,     ///< Sentencia de asignacion de variables
    STMT_WHILE,          ///< Sentencia while
    STMT_FOR,            ///< Sentencia for
    STMT_IF_ELSE,        ///< Sentencia if-else
    STMT_PROCEDURE_INV,  ///< Sentencia de invocacion de proceso
    STMT_BLOCK_BEGIN,    ///< Sentencia de bloque begin-end
    STMT_BLOCK_COBEGIN,  ///< Sentencia de bloque cobegin-coend
    STMT_FORK,           ///< Sentencia fork
    STMT_ATOMIC,         ///< Sentencia atomica
    STMT_RETURN          ///< Sentencia de retorno (para funciones)
} statement_t;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DEL AST (NODO SENTENCIAS) -----

/**
 * @brief Estructura que representa una sentencia de lamport.
 * 
 * Esta estructura almacena informacion sobre una sentencia en el lenguaje Lamport.
 * Dependiendo del tipo de sentencia que sea, dispondra de una serie de campos 
 * para su total descripcion.
 * 
 * STMT_ASSIGNMENT :
 *    --> Descripcion: Indica la asignacion de una variable
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_ASSIGNMENT
 *          ///> stmt       -> statement_assignment
 * 
 * STMT_WHILE :
 *    --> Descripcion: Indica la estructura completa de un while
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_WHILE
 *          ///> stmt       -> statement_while
 * 
 * STMT_FOR :
 *    --> Descripcion: Indica la estructura completa de un bucle for
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_FOR
 *          ///> stmt       -> statement_for
 * 
 * STMT_IF_ELSE :
 *    --> Descripcion: Indica la estructura completa de un if-else
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_IF_ELSE
 *          ///> stmt       -> statement_if_else
 * 
 * STMT_PROCEDURE_INV :
 *    --> Descripcion: Indica la invocacion de un procedimiento
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_PROCEDURE_INV
 *          ///> stmt       -> statement_procedure_inv
 * 
 * STMT_BLOCK_BEGIN :
 *    --> Descripcion: Indica la consecucion de un bloque begin-end
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_BLOCK
 *          ///> stmt       -> statement_block
 *  
 * STMT_BLOCK_COBEGIN :
 *    --> Descripcion: Indica la consecucion de un bloque begin-end
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_BLOCK_COBEGIN
 *          ///> stmt       -> statement_block_cobegin
 * 
 * STMT_FORK :
 *    --> Descripcion: Indica la realizacion de un fork a un proceso
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_FORK
 *          ///> stmt       -> statement_fork
 * 
 * STMT_ATOMIC :
 *    --> Descripcion: Indica la consecucion de un bloque atomico
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_ATOMIC
 *          ///> stmt       -> statement_atomic
 * 
 * STMT_RETURN :
 *    --> Descripcion: Indica el retorno de una funcion
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_RETURN
 *          ///> stmt       -> statement_return
 */
struct statement{
    statement_t kind;                               ///< Tipo de sentencia
    char *kind_str;                                 ///< Tipo de sentencia (str)
    struct statement *next;                         ///< Puntero a siguiente sentencia
    union 
    {
        // Estructura de sentencia de asignacion
        struct {
            char *variable_name;                    ///< Nombre de la variable
            struct expression *expr;                ///< Expresion de la asignacion
        } statement_assignment;

        // Estructura de sentencia de bucle while
        struct {
            struct expression *condition;           ///< Condicion del bucle
            struct statement *body;                 ///< Cuerpo del bucle (conjunto de sentencias)
        } statement_while;

        // Estructura de sentencia de bucle for
        struct {
            char *counter_name;                     ///< Variable utiliada para el bucle for
            struct expression *intialization;       ///< Inicializacion de contador de bucle
            struct expression *finish;              ///< Finalizacion del bucle
            struct statement *body;                 ///< Cuerpo del bucle (conjunto de sentencias)
        } statement_for;
        
        // Estructura de sentencia de if-else
        struct {           
            struct expression *condition;           ///< Condicion de if-else
            struct statement *if_body;              ///< Cuerpo del if [condition se evalua como verdadera] (conjunto de sentencias)
            struct statement *else_body;            ///< Cuerpo del else [condition se evalua como falsa] (conjunto de sentencias)
        } statement_if_else;

        // Estructura de sentencia de invocacion de proceso
        struct {
            char *procedure_name;                   ///< Nombre del procedimiento
            struct parameter_list *parameters;      ///< Parametros del procedimiento
        } statement_procedure_inv;

        // Estructura de sentencia de bloque begin-end o cobegin-coend o atomic
        struct {
            struct statement *body;                 ///< Conjunto de sentencias
        } statement_block;

        // Estructura de sentencia fork
        struct {
            char *forked_process;                   ///< Nombre del proceso
            struct statement *stmt;                 ///< Sentencia
        } statement_fork;

        // Estructura de sentencia return (para funciones)
        struct {
            struct expression *returned_expr;       ///< Expresion de retorno
        } statement_return;
    } stmt;                                         ///< Sentencia
    
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (SENTENCIAS) -----

/**
 * @brief Crea y reserva memoria para una sentencia de asignacion (STMT_ASSIGNMENT).
 * @param variable_name : Nombre de la variable
 * @param expr : Expresion a asignar
 * @return puntero con la sentencia incializada
 */
struct statement * create_statement_assignment(char *variable_name, struct expression *expr);

/**
 * @brief Crea y reserva memoria para una sentencia de bucle while (STMT_WHILE)
 * @param condition : Condicion del bucle
 * @param body : Cuerpo del bucle (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_while(struct expression *condition, struct statement *body);

/**
 * @brief Crea y reserva memoria para una sentencia de bucle for (STMT_FOR)
 * @param counter_name : Identificador de contador utilizado para el bucle
 * @param initializacion : Expresion para inicializar el contador del bucle
 * @param finish : Expresion para finalizar el contador del bucle
 * @param body : Cuerpo del bucle (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_for(char *counter_name, struct expression *initialization, struct expression *finish, struct statement *body);

/**
 * @brief Crea y reserva memoria para una sentencia de control de flujo if-else
 * @param condition : Expresion de condicion de control
 * @param if_body : Cuerpo de if (conjunto de sentencias)
 * @param else_body : Cuerpo de else (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_if_else(struct expression *condition, struct statement *if_body, struct statement *else_body);

/**
 * @brief Crea y reserva memoria para una sentencia de invocacion de procedimiento
 * @param procedure_name : Nombre del procedimiento
 * @param parameters : Lista de parametros del procedimiento
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_procedure_inv(char *procedure_name, struct parameter_list *parameters);

/**
 * @brief Crea y reserva memoria para una sentencia de construccion de bloques
 * @param block_type : Tipo de bloque (permitidos:  STMT_BLOCK_BEGIN | STMT_BLOCK_COBEGIN | STMT_ATOMIC)
 * @param body : Cuerpo del bloque (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
struct statement * create_block_of_statements(statement_t block_type, struct statement *body);

/**
 * @brief Crea y reserva memoria para una sentencia de bloques begin-end
 * @param body : Cuerpo del bloque (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_block_begin(struct statement *body);

/**
 * @brief Crea y reserva memoria para una sentencia de bloques cobegin-coend
 * @param body : Cuerpo del bloque (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_block_cobegin(struct statement *body);

/**
 * @brief Crea y reserva memoria para una sentencia atomica
 * @param body : Listado de sentencias atomicas
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_atomic(struct statement *body);

/**
 * @brief Crea y reserva memoria para una sentencia fork
 * @param process_name : Nombre del proceso
 * @param stmt : Sentencia
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_fork(char *process_name, struct statement *stmt);

/**
 * @brief Crea y reserva memoria para una sentencia de retorno (para funciones)
 * @param returned_expr : Expresion de retorno
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_return(struct expression *returned_expr);



// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO SENTENCIAS) ------

/**
 * @brief Libera la memoria asignada para una lista de sentencias
 * @param statements_list : Puntero a lista enlazada de sentencias
 */
void free_list_statements(struct statement *statements_list);

/**
 * @brief Libera la memoria asignada para un nodo de tipo sentencia
 * @param stmt : Puntero a nodo sentencia
 */
void free_statement(struct statement *stmt);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO SENTENCIAS) -----

/**
 * @brief Imprime una lista de nodos de sentencias
 * @param statements_list : Puntero a lista enlazada de sentencias
 */
void print_AST_statements(struct statement *statements_list);


#endif //_LAMPORT_AST_STATEMENT_DPR_