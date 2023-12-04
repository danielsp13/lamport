/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file lmp_c_analysis_bridge.hpp
 * @author Daniel Perez Ruiz
 * @brief Cabecera puente entre implementaciones C y C++
 */

#ifndef _LMP_COMPILER_C_ANALYSIS_BRIDGE_DPR_
#define _LMP_COMPILER_C_ANALYSIS_BRIDGE_DPR_

#ifdef __cplusplus
extern "C" {
#endif

// ===============================================================

// ----- INCLUSION DE MODULOS -----

#include "parser/parser_register.h"     ///< Registro de cadenas de caracteres
#include "error/error_manager.h"        ///< Manejador de errores
#include "AST/AST.h"                    ///< Abstract Syntax Tree (AST)
#include "semantic/name_resolution.h"   ///< Semantic : Resolucion de nombres
#include "semantic/type_checking.h"     ///< Semantic : Type Checking

// ===============================================================

// ----- IMPORTACION DE FUNCIONES Y VARIABLES EXTERNAS (FLEX/BISON) -----

/**
 * @brief Funcion generada por Flex. Se encarga de realizar el analisis
 * lexico, reconociendo tokens a partir del texto fuente y retornando el
 * tipo de token reconocido.
 * 
 * Utilizada por yyparse()
 */
extern int yylex(void);

/**
 * @brief Funcion generada por Bison. Realiza el analisis sintactico del texto
 * fuente, estructurando los tokens reconocidos en la fase anterior por yylex().
 * @param program : Puntero a AST del programa
 */
extern int yyparse(void);

#ifdef __cplusplus
}
#endif

#endif //_LMP_COMPILER_C_ANALYSIS_BRIDGE_DPR_
