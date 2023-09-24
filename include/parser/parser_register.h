/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file parser_register.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para gestion
 * de registro de bloques en la fase de parsing
 */

#ifndef _LAMPORT_PARSER_REGISTER_DPR_
#define _LAMPORT_PARSER_REGISTER_DPR_

#ifdef __cplusplus
extern "C" {
#endif

// ===============================================================

// ----- INCLUSION DE DEPENDENCIAS -----

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "AST/AST.h"                ///< Abstract Syntax Tree (AST)

// ===============================================================

// ----- DEFINICION DE MACROS -----

#define REG_OPERATION_SUCCESS 1         ///< Operacion de registro efectuado correctamente
#define REG_OPERATION_FAILURE 0         ///< Operacion de registro fallida

// ===============================================================

// ----- DEFINICION DE TIPOS DE REGISTRO DE NODOS -----

/**
 * @brief Estructura que representa los diferentes tipos de registro
 * de nodos AST que genera el analizador sintactico
 */
typedef enum{
    AST_NODE_REG_DECLARATION,
    AST_NODE_REG_EXPRESSION,
    AST_NODE_REG_STATEMENT,
    AST_NODE_REG_PARAMETER,
    AST_NODE_REG_TYPE,
    AST_NODE_REG_SUBPROGRAM,
    AST_NODE_REG_PROCESS
} AST_node_register_t;

union AST_node_register{
    struct AST_declaration_register *decl_reg;
    struct AST_expression_register *expr_reg;
    struct AST_statement_register *stmt_reg;
    struct AST_parameter_register *param_reg;
    struct AST_type_register *type_reg;
    struct AST_subprogram_register *subprog_reg;
    struct AST_process_register *proc_reg;
};

union AST_node{
    struct declaration *decl;
    struct expression *expr;
    struct statement *stmt;
    struct parameter *param;
    struct type *type;
    struct subprogram *subprog;
    struct process *proc;
};

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DE REGISTROS DE BLOQUES -----

struct AST_declaration_register{
    struct declaration *decl;
    struct AST_declaration_register *next;
};

struct AST_expression_register{
    struct expression *expr;
    struct AST_expression_register *next;
};

struct AST_statement_register{
    struct statement *stmt;
    struct AST_statement_register *next;
};

struct AST_parameter_register{
    struct parameter *param;
    struct AST_parameter_register *next;
};

struct AST_type_register{
    struct type *type;
    struct AST_type_register *next;
};

struct AST_subprogram_register{
    struct subprogram *subprog;
    struct AST_subprogram_register *next;
};

struct AST_process_register{
    struct process *proc;
    struct AST_process_register *next;
};

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
struct string_register{
    char *str;                          ///< Contenido de registro (cadena de caracteres)
    struct string_register *next;       ///< Puntero a siguiente registro
};

// ===============================================================

// ----- DEFINICION DE REGISTROS DE CONTROL DE BLOQUES -----

// -- Registro de nodos de declaraciones
extern struct AST_declaration_register *list_AST_decl_reg;

// -- Ultimo registro efectuado en el registro de nodos de declaraciones
extern struct AST_declaration_register *last_reg_of_list_AST_decl_reg;

// -- Registro de nodos de expresiones
extern struct AST_expression_register *list_AST_expr_reg;

// -- Ultimo registro efectuado en el registro de nodos de expresiones
extern struct AST_expression_register *last_reg_of_list_AST_expr_reg;

// -- Registro de nodos de sentencias
extern struct AST_statement_register *list_AST_stmt_reg;

// -- Ultimo registro efectuado en el registro de nodos de sentencias
extern struct AST_statement_register *last_reg_of_list_AST_stmt_reg;

// -- Registro de nodos de parametros
extern struct AST_parameter_register *list_AST_param_reg;

// -- Ultimo registro efectuado en el registro de nodos de parametros
extern struct AST_parameter_register *last_reg_of_list_AST_param_reg;

// -- Registro de nodos de tipos
extern struct AST_type_register *list_AST_type_reg;

// -- Ultimo registro efectuado en el registro de nodos de tipos
extern struct AST_type_register *last_reg_of_list_AST_type_reg;

// -- Registro de nodos de subprogramas
extern struct AST_subprogram_register *list_AST_subprog_reg;

// -- Ultimo registro efectuado en el registro de nodos de subprogramas
extern struct AST_subprogram_register *last_reg_of_list_AST_subprog_reg;

// -- Registro de nodos de proceso
extern struct AST_process_register *list_AST_proc_reg;

// -- Ultimo registro efectuado en el registro de nodos de proceso
extern struct AST_process_register *last_reg_of_list_AST_proc_reg;

// -- Registro de cadenas de caracteres
extern struct string_register *list_string_reg;

// -- Ultimo registro efectuado en el registro de cadenas de caracteres
extern struct string_register *last_string_reg;

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE REGISTROS (GENERAL) -----

/**
 * @brief Crea y reserva memoria para un nuevo registro de nodo AST
 * @param kind : tipo de registro
 * @param data : contenido del registro
 * @return puntero a registro inicializado
 */
union AST_node_register create_AST_node_register(AST_node_register_t kind, union AST_node data);

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE REGISTROS (DECLARATION) -----

/**
 * @brief Crea y reserva memoria para un nuevo registro de nodo declaracion
 * @param decl : declaracion
 * @return puntero a registro inicializado
 */
struct AST_declaration_register * create_AST_declaration_reg(struct declaration *decl);

/**
 * @brief Incluye un nuevo nodo de declaracion en el registro
 * @param decl : declaracion
 * @return TRUE si se incluyo con exito, FALSE en otro caso
 */
int add_declaration_to_register(struct declaration *decl);

/**
 * @brief Libera la memoria del registro de nodos de declaraciones
 */
void free_AST_declaration_register();

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE REGISTROS (EXPRESIONES) -----

/**
 * @brief Crea y reserva memoria para un nuevo registro de nodo expresion
 * @param expr : expresion
 * @return puntero a registro inicializado
 */
struct AST_expression_register * create_AST_expression_reg(struct expression *expr);

/**
 * @brief Incluye un nuevo nodo de expresion en el registro
 * @param expr : expresion
 * @return TRUE si se incluyo con exito, FALSE en otro caso
 */
int add_expression_to_register(struct expression *expr);

/**
 * @brief Libera la memoria del registro de nodos de expresiones
 */
void free_AST_expression_register();

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE REGISTROS (SENTENCIAS) -----

/**
 * @brief Crea y reserva memoria para un nuevo registro de nodo sentencia
 * @param stmt : sentencia
 * @return puntero a registro inicializado
 */
struct AST_statement_register * create_AST_statement_reg(struct statement *stmt);

/**
 * @brief Incluye un nuevo nodo de sentencia en el registro
 * @param stmt : sentencia
 * @return TRUE si se incluyo con exito, FALSE en otro caso
 */
int add_statement_to_register(struct statement *stmt);

/**
 * @brief Libera la memoria del registro de nodos de sentencias
 */
void free_AST_statement_register();

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE REGISTROS (PARAMETROS) -----

/**
 * @brief Crea y reserva memoria para un nuevo registro de nodo parametro
 * @param param : parametro
 * @return puntero a registro inicializado
 */
struct AST_parameter_register * create_AST_parameter_reg(struct parameter *param);

/**
 * @brief Incluye un nuevo nodo de parametro en el registro
 * @param param : parametro
 * @return TRUE si se incluyo con exito, FALSE en otro caso
 */
int add_parameter_to_register(struct parameter *param);

/**
 * @brief Libera la memoria del registro de nodos de parametros
 */
void free_AST_parameter_register();

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE REGISTROS (TIPOS) -----

/**
 * @brief Crea y reserva memoria para un nuevo registro de nodo tipo
 * @param type : tipo
 * @return puntero a registro inicializado
 */
struct AST_type_register * create_AST_type_reg(struct type *type);

/**
 * @brief Incluye un nuevo nodo de tipo en el registro
 * @param type : tipo
 * @return TRUE si se incluyo con exito, FALSE en otro caso
 */
int add_type_to_register(struct type *type);

/**
 * @brief Libera la memoria del registro de nodos de tipos
 */
void free_AST_type_register();

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE REGISTROS (SUBPROGRAMAS) -----

/**
 * @brief Crea y reserva memoria para un nuevo registro de nodo subprograma
 * @param subprog : subprograma
 * @return puntero a registro inicializado
 */
struct AST_subprogram_register * create_AST_subprogram_reg(struct subprogram *subprog);

/**
 * @brief Incluye un nuevo nodo de subprograma en el registro
 * @param subprog : subprograma
 * @return TRUE si se incluyo con exito, FALSE en otro caso
 */
int add_subprogram_to_register(struct subprogram *subprog);

/**
 * @brief Libera la memoria del registro de nodos de subprogramas
 */
void free_AST_subprogram_register();

// ===============================================================

// ----- PROTOTIPOS DE FUNCIONES DE GESTION DE REGISTROS (PROCESOS) -----

/**
 * @brief Crea y reserva memoria para un nuevo registro de nodo proceso
 * @param proc : proceso
 * @return puntero a registro inicializado
 */
struct AST_process_register * create_AST_process_reg(struct process *proc);

/**
 * @brief Incluye un nuevo nodo de proceso en el registro
 * @param proc : proceso
 * @return TRUE si se incluyo con exito, FALSE en otro caso
 */
int add_process_to_register(struct process *proc);

/**
 * @brief Libera la memoria del registro de nodos de procesos
 */
void free_AST_process_register();

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES DE GESTION DE REGISTROS (STRING) -----

/**
 * @brief Crea y reserva memoria para el registro de una cadena
 * @param str : cadena de caracteres a registrar
 * @return puntero a registro inicializado
 */
struct string_register * create_string_register(char * str); 

/**
 * @brief Inserta una nueva cadena de caracteres al registro global
 * @param str : Cadena de caraceres
 * @return TRUE si se incluyo con exito, FALSE en otro caso
 */
int add_string_to_register(char * str);

/**
 * @brief Devuelve el ultimo registro efectuado en la lista
 * @return last_str_reg
 */
char * get_last_str_reg();

/**
 * @brief Libera toda la memoria reservada para el registro
 */
void free_string_register();

#ifdef __cplusplus
}
#endif

#endif //_LAMPORT_PARSER_REGISTER_DPR_