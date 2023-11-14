/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file statement.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO sentencias
 */

#ifndef _LAMPORT_AST_STATEMENT_DPR_
#define _LAMPORT_AST_STATEMENT_DPR_

#ifdef __cplusplus
extern "C" {
#endif

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE NODO -----

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "expression.h"          ///< Expresiones
#include "type.h"                ///< Tipos de dato
#include "print_assistant.h"     ///< Asistencia de impresion de AST

#include "semantic/symbol.h"    ///< Simbolo (para resolucion de nombres)

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
    STMT_JOIN,           ///< Sentencia join
    STMT_ATOMIC,         ///< Sentencia atomica
    STMT_RETURN,         ///< Sentencia de retorno (para funciones)
    STMT_PRINT,          ///< Sentencia de impresion de expresiones
    STMT_SEM_WAIT,       ///< Sentencia de wait de semaforo
    STMT_SEM_SIGNAL,     ///< Sentencia de signal de semaforo
    STMT_SLEEP,          ///< Sentencia de dormir proceso  
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
 * STMT_JOIN :
 *    --> Descripcion: Indica la realizacion de un join a un proceso
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_JOIN
 *          ///> stmt       -> statement_join
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
 * 
 * STMT_PRINT :
 *    --> Descripcion: Indica la impresion de una serie de expresiones en pantalla
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_PRINT
 *          ///> stmt       -> statement_print
 * 
 * STMT_WAIT :
 *    --> Descripcion: Indica la operacion wait sobre un semaforo
 *          ///> kind       -> STMT_WAIT
 *          ///> stmt       -> statement_sem_wait
 * 
 * STMT_SIGNAL :
 *    --> Descripcion: Indica la operacion signal sobre un semaforo
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_SIGNAL
 *          ///> stmt       -> statement_sem_signal
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
            struct expression *index_expr;          ///< Expresion del subindice. NULL si no hay subíndice.
            struct expression *expr;                ///< Expresion de la asignacion

            unsigned long line;                     ///< Linea donde se uso el identificador
            struct symbol *symb;                    ///< Referencia al símbolo asociado en la tabla de símbolos.
        } statement_assignment;

        // Estructura de sentencia de bucle while
        struct {
            struct expression *condition;           ///< Condicion del bucle
            struct statement *body;                 ///< Cuerpo del bucle (conjunto de sentencias)

            unsigned long line;                     ///< Linea donde se definio la sentencia
        } statement_while;

        // Estructura de sentencia de bucle for
        struct {
            char *counter_name;                     ///< Variable utiliada para el bucle for
            struct expression *intialization;       ///< Inicializacion de contador de bucle
            struct expression *finish;              ///< Finalizacion del bucle
            struct statement *body;                 ///< Cuerpo del bucle (conjunto de sentencias)

            unsigned long line;                     ///< Linea donde se uso el identificador
            struct symbol *symb;                    ///< Referencia al símbolo asociado en la tabla de símbolos.
        } statement_for;
        
        // Estructura de sentencia de if-else
        struct {           
            struct expression *condition;           ///< Condicion de if-else
            struct statement *if_body;              ///< Cuerpo del if [condition se evalua como verdadera] (conjunto de sentencias)
            struct statement *else_body;            ///< Cuerpo del else [condition se evalua como falsa] (conjunto de sentencias)

            unsigned long line;                     ///< Linea donde se definio la sentencia
        } statement_if_else;

        // Estructura de sentencia de invocacion de proceso
        struct {
            char *procedure_name;                   ///< Nombre del procedimiento
            struct expression *arguments_list;      ///< Argumentos de invocacion del procedimiento

            unsigned long line;                     ///< Linea donde se uso el identificador
            struct symbol *symb;                    ///< Referencia al símbolo asociado en la tabla de símbolos.
        } statement_procedure_inv;

        // Estructura de sentencia de bloque begin-end o cobegin-coend o atomic
        struct {
            struct statement *body;                 ///< Conjunto de sentencias
        } statement_block;

        // Estructura de sentencia fork
        struct {
            char *forked_procedure;                   ///< Nombre del procedimiento

            unsigned long line;                     ///< Linea donde se uso el identificador
            struct symbol *symb;                    ///< Referencia al símbolo asociado en la tabla de símbolos.
        } statement_fork;

        struct{
            unsigned long line;                     ///< Linea donde se uso el identificador
        } statement_join;

        struct{
            struct expression *sleep_expr;             ///< Milisegundos para dormir proceso
            unsigned long line;
        } statement_sleep;

        // Estructura de sentencia return (para funciones)
        struct {
            struct expression *returned_expr;       ///< Expresion de retorno
            unsigned long line;                     ///< Linea donde se definio la sentencia

            //char *function_name;                    ///< Nombre de funcion
            //struct symbol *symb;                    ///< Referencia al simbolo asociado en la tabla de simbolos
        } statement_return;

        // Estructura de sentencia de impresion
        struct{
            struct expression *expressions_list;    ///< Lista de expresiones a imprimir
        } statement_print;

        // Estructura de sentencia wait de semaforo
        struct{
            char * semaphore_name;
            unsigned long line;

            struct symbol *symb;        
        } statement_semaphore;

    } stmt;                                         ///< Sentencia
    
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (SENTENCIAS) -----

/**
 * @brief Crea y reserva memoria para una sentencia
 * @param kind : Tipo de sentencia
 * @return puntero con la sentencia creada
 */
struct statement * create_statement(statement_t kind);

/**
 * @brief Crea y reserva memoria para una sentencia de asignacion (STMT_ASSIGNMENT).
 * @param variable_name : Nombre de la variable
 * @param index_expr : Expresion de indice (si se esta realizando la asignacion sobre una posicion de array)
 * @param expr : Expresion a asignar
 * @param line : linea donde se uso el identificador de variable
 * @return puntero con la sentencia incializada
 */
struct statement * create_statement_assignment(char *variable_name, struct expression *index_expr, struct expression *expr, unsigned long line);

/**
 * @brief Crea y reserva memoria para una sentencia de bucle while (STMT_WHILE)
 * @param condition : Condicion del bucle
 * @param body : Cuerpo del bucle (conjunto de sentencias)
 * @param line : linea donde se definio la sentencia
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_while(struct expression *condition, struct statement *body, unsigned long line);

/**
 * @brief Crea y reserva memoria para una sentencia de bucle for (STMT_FOR)
 * @param counter_name : Identificador de contador utilizado para el bucle
 * @param initializacion : Expresion para inicializar el contador del bucle
 * @param finish : Expresion para finalizar el contador del bucle
 * @param body : Cuerpo del bucle (conjunto de sentencias)
 * @param line : linea donde se uso el identificador de contador
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_for(char *counter_name, struct expression *initialization, struct expression *finish, struct statement *body, unsigned long line);

/**
 * @brief Crea y reserva memoria para una sentencia de control de flujo if-else
 * @param condition : Expresion de condicion de control
 * @param if_body : Cuerpo de if (conjunto de sentencias)
 * @param else_body : Cuerpo de else (conjunto de sentencias)
 * @param line : linea donde se definio la sentencia
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_if_else(struct expression *condition, struct statement *if_body, struct statement *else_body, unsigned long line);

/**
 * @brief Crea y reserva memoria para una sentencia de invocacion de procedimiento
 * @param procedure_name : Nombre del procedimiento
 * @param arguments_list : Lista de argumentos de invocacion procedimiento
 * @param line : linea donde se uso el identificador de proceso
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_procedure_inv(char *procedure_name, struct expression *arguments_list, unsigned long line);

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
 * @param line : linea donde se uso el identificador de proceso
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_fork(char *process_name, unsigned long line);

/**
 * @brief Crea y reserva memoria para una sentencia join
 * @param line : linea donde se uso el identificador de proceso
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_join(unsigned long line);

/**
 * @brief Crea y reserva memoria para una sentencia de sleep
 * @param returned_expr : Expresion de milisegundos para dormir
 * @param line : linea donde se definio la sentencia
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_sleep(struct expression *sleep_expr, unsigned long line);

/**
 * @brief Crea y reserva memoria para una sentencia de retorno (para funciones)
 * @param returned_expr : Expresion de retorno
 * @param line : linea donde se definio la sentencia
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_return(struct expression *returned_expr, unsigned long line);

/**
 * @brief Crea y reserva memoria para una sentencia de impresion de expresiones
 * @param expressions_list : Lista de expresiones a imprimir
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_print(struct expression *expressions_list);

/**
 * @brief Crea y reserva memoria para una sentencia de wait de semaforo
 * @param semaphore_id : identificador de semaforo
 * @param line : linea de definicion de sentencia
 * @return puntero a sentencia creada e inicializada
 */
struct statement * create_statement_sem_wait(char * semaphore_id, unsigned long line);

/**
 * @brief Crea y reserva memoria para una sentencia de signal de semaforo
 * @param semaphore_id : identificador de semaforo
 * @param line : linea de definicion de sentencia
 * @return puntero a sentencia creada e inicializada
 */
struct statement * create_statement_sem_signal(char * semaphore_id, unsigned long line);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO SENTENCIAS) ------

/**
 * @brief Libera la memoria asignada para una lista de sentencias
 * @param statements_list : Puntero a lista enlazada de sentencias
 */
void free_list_statements(struct statement *statements_list);

/**
 * @brief Libera la memoria asignada para un nodo de tipo sentencia
 * @param stmt : nodo sentencia
 */
void free_statement(struct statement *stmt);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO SENTENCIAS) -----

/**
 * @brief Imprime una lista de nodos de sentencias
 * @param statements_list : Puntero a lista enlazada de sentencias
 * @param depth : Profundidad en la impresion de la lista de nodos
 * @param output : destino de impresion
 */
void print_AST_statements(struct statement *statements_list, unsigned int depth, FILE * output);

#ifdef __cplusplus
}
#endif

#endif //_LAMPORT_AST_STATEMENT_DPR_