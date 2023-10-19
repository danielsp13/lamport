/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file error_type.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de tipos de error
 */

#ifndef _LAMPORT_ERROR_TYPE_DPR_
#define _LAMPORT_ERROR_TYPE_DPR_

#ifdef __cplusplus
extern "C" {
#endif

// ===============================================================

// ----- DEFINICION DE TIPOS DE ERRORES (SINTACTICOS) -----

/**
 * @brief Estructura que representa los diferentes tipos de errores sintacticos
 * del lenguaje lamport
 */
typedef enum{
    ERR_SYNTAX_IN_DECLARATION,              ///< Error sintactico detectado en declaracion
    ERR_SYNTAX_IDENT_IN_DECLARATION,        ///< Error sintactico detectado en declaracion (identifier)
    ERR_SYNTAX_IN_PROCEDURE,                ///< Error sintactico detectado en procedimiento
    ERR_SYNTAX_IDENT_IN_PROCEDURE,          ///< Error sintactico detectado en procedimiento (identifier)
    ERR_SYNTAX_IN_FUNCTION,                 ///< Error sintactico detectado en funcion
    ERR_SYNTAX_IDENT_IN_FUNCTION,           ///< Error sintactico detectado en funcion (identifier)
    ERR_SYNTAX_IN_PARAMETER,                ///< Error sintactico detectado en parametro
    ERR_SYNTAX_IN_PROCESS,                  ///< Error sintactico detectado en proceso
    ERR_SYNTAX_IDENT_IN_PROCESS,            ///< Error sintactico detectado en proceso (identifier)
    ERR_SYNTAX_IN_TYPE,                     ///< Error sintactico detectado en tipo de dato
    ERR_SYNTAX_IN_EXPRESSION,               ///< Error sintactico detectado en expresion
    ERR_SYNTAX_IN_STATEMENT,                ///< Error sintactico detectado en sentencia
    ERR_SYNTAX_IN_PROGRAM,                  ///< Error sintactico detectado en programa
    ERR_SYNTAX_IDENT_IN_PROGRAM,            ///< Error sintactico detectado en programa (identifier)
} error_syntax_t;

// ===============================================================

// ----- DEFINICION DE TIPOS DE ERRORES (SEMANTICOS) -----

/**
 * @brief Estructura que representa los diferentes tipos de errores semanticos
 * del lenguaje lamport
 */
typedef enum{
    UNDEFINED_SYMBOL,                   ///< Se ha detectado el uso de un simbolo no definido
    DUPLICATED_SYMBOL,                  ///< Se ha detectado la declaracion de un mismo simbolo mas de una vez
    DUPLICATED_SYMBOL_PARAM,            ///< Se ha detectado la declaracion de un parametro mas de una vez
    UNMATCHED_TYPES,                    ///< Comparacion de tipos distintos
} error_semantic_t;

/**
 * @brief Estructura que representa los diferentes tipos de errores semanticos
 * producidos en el typechecking
 */
typedef enum{
    UNMATCHED_TYPES_EXPR_BINARY,
    UNMATCHED_TYPES_EXPR_UNARY,
    UNMATCHED_TYPES_EXPR_FUNCTION_INV,
    UNMATCHED_TYPES_DECLARATION,
    UNMATCHED_TYPES_DECLARATION_ARRAY,
    UNMATCHED_TYPES_STMT_ASSIGNMENT,
    UNMATCHED_TYPES_STMT_ASSIGNMENT_ARRAY_NO_INDEX,
    UNMATCHED_TYPES_STMT_ASSIGNMENT_INDEX,
    UNMATCHED_TYPES_STMT_WHILE,
    UNMATCHED_TYPES_STMT_FOR_INDEX,
    UNMATCHED_TYPES_STMT_FOR_INIT,
    UNMATCHED_TYPES_STMT_FOR_END_EXR,
    UNMATCHED_TYPES_STMT_IF_ELSE,
    UNMATCHED_TYPES_STMT_FORK,
    UNMATCHED_TYPES_STMT_JOIN,
    UNMATCHED_TYPES_STMT_SEMAPHORE,
    UNMATCHED_TYPES_STMT_PROCEDURE_INV,
    UNMATCHED_TYPES_PROC_VECTOR_INDEX,
    UNMATCHED_TYPES_PROC_VECTOR_START_RANGE,
    UNMATCHED_TYPES_PROC_VECTOR_END_RANGE,
    UNMATCHED_TYPES_SUBPROG_FUNCTION_RETURN,
} error_semantic_type_checking_t;

#ifdef __cplusplus
}
#endif

#endif //_LAMPORT_ERROR_TYPE_DPR_