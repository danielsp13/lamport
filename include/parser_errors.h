/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file parser_errors.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de mensajes de error reconocidos por el analizador
 * sintactico de Bison (parser)
 */

#ifndef _LMP_PARSER_ERRORS_DPR_
#define _LMP_PARSER_ERRORS_DPR_

// -- Definicion de errores de reconocimiento de programa (program)
#define PARSER_ERROR_MSG_PROGRAM_PROGRAM "Se esperaba 'program' al inicio de definición del programa."
#define PARSER_ERROR_MSG_PROGRAM_IDENT "Se esperaba IDENT después de: program."

// -- Definicion de errores de reconocimiento de declaraciones (declaration)
#define PARSER_ERROR_MSG_DECLARARTION_VAR "Se esperaba 'var' al principio de la declaracion."
#define PARSER_ERROR_MSG_DECLARATION_IDENT "Se esperaba IDENT despues de: var."
#define PARSER_ERROR_MSG_DECLARATION_DELIM2P "Falta ':' en la declaración."
#define PARSER_ERROR_MSG_DECLARATION_ASSIGNMENT_EXPR "Falta expresión de asignación / expresión incorrecta."
#define PARSER_ERROR_MSG_DECLARATION_DELIMPC "Falta ';' al final de la declaración."

//  -- Definicion de errores de reconocimiento de subprogramas (procedure/function)
#define PARSER_ERROR_MSG_PROC_PROCEDURE_FUNCTION_DEF "Definición de procedimiento / función incorrecta."

// -- Definicion de errores de reconocimiento de subprogramas (subprogram-procedure)
#define PARSER_ERROR_MSG_PROC_PROCEDURE_IDENT "Se esperaba IDENT despues de: procedure."
#define PARSER_ERROR_MSG_PROC_PROCEDURE_MALFORMED "Definición de procedimiento malformada."

// -- Definicion de errores de reconocimiento de subprogramas (subprogram-function)
#define PARSER_ERROR_MSG_PROC_FUNCTION_IDENT "Se esperaba IDENT despues de: function."
#define PARSER_ERROR_MSG_PROC_FUNCTION_MALFORMED "Definición de función malformada."

// -- Definicion de errores de reconocimiento de parametros de subprogramas
#define PARSER_ERROR_MSG_PROC_PARAMETER_IDENT "IDENT de parámetro no válido."
#define PARSER_ERROR_MSG_PROC_PARAMETER_DELIM2P "Falta ':' en el parámetro."

// -- Definicion de errores de reconocimiento de procesos
#define PARSER_ERROR_MSG_PROCESS_IDENT "Se esperaba IDENT despues de: process."
#define PARSER_ERROR_MSG_PROCESS_DELIMPC "Falta ';' al final de definición de proceso."

// -- Definicion de errores de reconocimiento de sentencias 
#define PARSER_ERROR_MSG_STMT_MALFORMED "Sentencia malformada."

// -- Definicion de errores de reconocimiento de expresiones
#define PARSER_ERROR_MSG_EXPR_MALFORMED "Expresión malformada."

// -- Definicion de errores de reconocimiento de tipos (type)
#define PARSER_ERROR_MSG_TYPE "Tipo de dato no reconocido."


#endif //_LMP_PARSER_ERRORS_DPR_