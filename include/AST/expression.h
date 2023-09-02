/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file expression.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles) : NODO expresiones
 */

#ifndef _LAMPORT_AST_EXPRESSION_DPR_
#define _LAMPORT_AST_EXPRESSION_DPR_

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS DE NODO -----

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "type.h"           ///< Parametros (procedimientos y funciones)

// ===============================================================

// ----- DEFINICION DE TIPOS DE EXPRESIONES ----

/**
 * @brief Estructura que repesenta los tipos de expresiones de lamport.
 */
typedef enum{
    EXPR_BINARY,            ///< Expresion de operacion binaria
    EXPR_UNARY,             ///< Expresion de operacion unaria
    EXPR_IDENTIFIER,        ///< Expresion de identificador     
    EXPR_LITERAL,           ///< Expresion literal
    EXPR_FUNCTION_INV,      ///< Expresion de invocacion de funciones
    EXPR_GROUPED            ///< Expresion entre parentesis
} expression_t;

/**
 * @brief Estructura que representa los tipos de expresiones binarias de lamport.
 */
typedef enum{
    EXPR_ADD,               ///< Expresion de suma (binario)
    EXPR_SUB,               ///< Expresion de resta (binario)
    EXPR_MULT,              ///< Expresion de multiplicacion (binario)
    EXPR_DIV,               ///< Expresion de division (binario)
    EXPR_MOD,               ///< Expresion de modulo (binario)
    EXPR_GT,                ///< Expresion de comparacion mayor que (binario)
    EXPR_LT,                ///< Expresion de comparacion menor que (binario)
    EXPR_GTE,               ///< Expresion de comparacion mayor igual que (binario)
    EXPR_LTE,               ///< Expresion de comparacion menor igual que (binario)
    EXPR_EQ,                ///< Expresion de comparacion igual que (binario)
    EXPR_NEQ,               ///< Expresion de comparacion distinto que (binario)
    EXPR_AND,               ///< Expresion logica conjuncion (binario)
    EXPR_OR,                ///< Expresion logica de disyuncion (binario)
} expression_binary_t;

/**
 * @brief Estructura que representa los tipos de expresiones unarias de lamport.
 */
typedef enum{
    EXPR_NOT,               ///< Expresion logica de negacion (unario)
    EXPR_NEGATIVE,          ///< Expresion de signo negativo (unario)
} expression_unary_t;

/**
 * @brief Estructura que representa los tipos de expresiones literales de lamport.
 */
typedef enum{
    EXPR_LITERAL_INTEGER,   ///< Expresion de literal entero
    EXPR_LITERAL_REAL,      ///< Expresion de literal flotante
    EXPR_LITERAL_CHARACTER, ///< Expresion de literal de caracter
    EXPR_LITERAL_STRING,    ///< Expresion de literal de cadena de caracteres
    EXPR_LITERAL_BOOLEAN,   ///< Expresion de literal booleano
} expression_literal_t;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DEL AST (NODO EXPRESIONES) -----

/**
 * @brief Estructura que representa a una expresion de lamport.
 * 
 * 
 * Esta estructura almacena informacion sobre una expresion en el lenguaje lamport.
 * Dependiendo del tipo de expresion que sea, dispondra de una serie de campos
 * para su total descripcion.
 * 
 * EXPR_BINARY :
 *    --> Descripcion: Indica la expresion de una operacion binaria
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> EXPR_BINARY
 *          ///> expr       -> expression_binary_operation
 * 
 *    --> Tipos de operaciones binarias soportadas:
 *          ///> EXPR_ADD   : Suma de dos expresiones
 *          ///> EXPR_SUB   : Resta de dos expresiones
 *          ///> EXPR_MULT  : Multiplicacion de dos expresiones
 *          ///> EXPR_DIV   : Division de dos expresiones
 *          ///> EXPR_MOD   : Modulo de dos expresiones
 *          ///> EXPR_GT    : Comparacion "mayor que" entre dos expresiones
 *          ///> EXPR_LT    : Comparacion "menor que" entre dos expresiones
 *          ///> EXPR_GTE   : Comparacion "mayor igual que" entre dos expresiones
 *          ///> EXPR_LTE   : Comparacion "menor igual que" entre dos expresiones
 *          ///> EXPR_EQ    : Comparacion "igual que" entre dos expresiones
 *          ///> EXPR_NEQ   : Comparacion "distinto que" entre dos expresiones
 *          ///> EXPR_AND   : Conjuncion logica entre dos expresiones
 *          ///> EXPR_OR    : Disyuncion logica entre dos expresiones
 * 
 * EXPR_UNARY :
 *    --> Descripcion: Indica la expresion de una operacion unaria
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> EXPR_UNARY
 *          ///> expr       -> expression_unary_operation
 * 
 *    --> Tipos de operaciones unarias soportadas:
 *          ///> EXPR_NOT        : Negacion logica de una expresion
 *          ///> EXPR_NEGATIVE   : Signo negativo de una expresion
 * 
 * EXPR_LITERAL :
 *    --> Descripcion: Indica la expresion de un literal
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> EXPR_LITERAL
 *          ///> expr       -> expression_literal
 * 
 *    --> Tipos de literales soportados:
 *          ///> LITERAL_INTEGER     : Literal entero
 *          ///> LITERAL_REAL        : Literal flotante
 *          ///> LITERAL_BOOLEAN     : Literal booleano
 *          ///> LITERAL_CHARACTER   : Literal de caracter
 *          ///> LITERAL_STRING      : Literal de cadena de caracteres
 * 
 * EXPR_IDENTIFIER
 *    --> Descripcion: Indica la expresion de un identificador
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> EXPR_IDENTIFIER
 *          ///> expr       -> id
 * 
 * EXPR_FUNCTION_INV
 *    --> Descripcion: Indica la expresion de una invocacion de funcion
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> EXPR_FUNCTION_INV
 *          ///> expr       -> expression_function_inv
 * 
 * EXPR_GROUPED
 *    --> Descripcion: Indica la expresion de un identificador
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> EXPR_GROUPED
 *          ///> expr       -> grouped_expression
 */
struct expression{
    expression_t kind;                                      ///< Tipo de expresion
    char *kind_str;                                         ///< Tipo de expresion (str)
    struct expression *next;                                ///< Puntero a siguiente expresion
    union
    {
        // Estructura de expresion de operacion binaria
        struct {
            expression_binary_t kind;                       ///< Tipo de operacion binaria
            char *operator;                                 ///< Operador de operacion
            struct expression *left;                        ///< Expresion izquierda de la operacion
            struct expression *right;                       ///< Expresion derecha de la operacion
        } expression_binary_operation;

        // Estructura de expresion de operacion unaria
        struct {
            expression_unary_t kind;                        ///< Tipo de la operacion unaria
            char *operator;                                 ///< Operador de operacion
            struct expression *left;                        ///< Expresion derecha de la operacion
        } expression_unary_operation;

        // Estructura de expresion de identificador
        struct{
            char *id;                                       ///< Valor de identificador
        } expression_identifier;

        // Estructura de expresion de literal
        struct {
            expression_literal_t kind;                      ///< Tipo de literal
            union{
                int integer_literal;                        ///< Valor para literal entero
                float real_literal;                         ///< Valor para literal flotante
                int boolean_literal;                        ///< Valor para literal booleano
                char character_literal;                     ///< Valor para literal de caracter
                char* string_literal;                       ///< Valor para literal de cadena de caracteres
            } value;
        } expression_literal;

        // Estructura de expresion de invocacion de funcion
        struct {
            char *function_name;                            ///< Nombre de funcion
            struct expression *arguments_list;              ///< Lista de argumentos para funciones
        } expression_function_inv;

        // Expresion entre parentesis
        struct expression *grouped_expression;              ///< Expresion entre parentesis
    } expr;
    
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (EXPRESIONES) -----

/**
 * @brief Crea y reserva memoria para una expresion de tipo operacion binaria
 * @param kind : Tipo de operacion binaria
 * @param operator : Simbolo de operacion
 * @param left : Operando izquierdo
 * @param right : Operando derecho
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_binary_operation(expression_binary_t kind, char *operator, struct expression *left, struct expression *right);

/**
 * @brief Crea y reserva memoria para una expresion de tipo operacion unaria
 * @param kind : Tipo de operacion unaria
 * @param left : Operando
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_unary_operation(expression_unary_t kind, char *operator, struct expression *left);

/**
 * @brief Crea y reserva memoria para una expresion de identificador
 * @param id : identificador
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_identifier(char *id);

/**
 * @brief Crea y reserva memoria para una expresion de tipo literal entero
 * @param value : Valor de literal
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_literal_integer(int value);

/**
 * @brief Crea y reserva memoria para una expresion de tipo literal real
 * @param value : Valor de literal
 * @return puntero con la expresion inicialiada
 */
struct expression * create_expression_literal_real(float value);

/**
 * @brief Crea y reserva memoria para una expresion de tipo literal string
 * @param value : Valor de literal
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_literal_string(char *value);

/**
 * @brief Crea y reserva memoria para una expresion de tipo literal char
 * @param value : Valor de literal
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_literal_char(char value);

/**
 * @brief Crea y reserva memoria para una expresion de tipo literal booleano
 * @param value : Valor de literal
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_literal_boolean(int value);

/**
 * @brief Crea y reserva memoria para una expresion de invocacion de funcion
 * @param function_name : Nombre de funcion
 * @param arguments_list : Argumentos de invocación de la funcion
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_function_invocation(char *function_name, struct expression *arguments_list);

/**
 * @brief Crea y reserva memoria para una expresion definida entre parentesis
 * @param grouped_expression : expresion
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_grouped(struct expression *grouped_expression);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA LIBERACION DE MEMORIA DEL AST (NODO EXPRESIONES) ------

/**
 * @brief Libera la memoria asignada para una lista de expresiones
 * @param expressions_list : Puntero a lista enlazada de expresiones
 */
void free_list_expressions(struct expression *expressions_list);

/**
 * @brief Libera la memoria asignada para un nodo de tipo expresion
 * @param expr : Puntero a nodo expresion
 */
void free_expression(struct expression *expr);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA IMPRIMIR AST (NODO EXPRESIONES) -----

/**
 * @brief Imprime una lista de nodos de expresiones
 * @param expressions_list : Puntero a lista enlazada de expresiones
 */
void print_AST_expressions(struct expression *expressions_list);


#endif //_LAMPORT_AST_EXPRESSION_DPR_