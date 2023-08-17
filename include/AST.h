/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file AST.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles)
 */

#ifndef _LAMPORT_AST_DPR_
#define _LAMPORT_AST_DPR_

// ===============================================================

// ----- DEFINICION DE TIPOS DE ESTRUCTURAS DEL AST -----

/**
 * @brief Estructura que representa los tipos de sentencias de lamport.
 */
typdef enum{
    STMT_ASSIGNMENT,     ///< Sentencia de asignacion de variables
    STMT_WHILE,          ///< Sentencia while
    STMT_FOR,            ///< Sentencia for
    STMT_IF_ELSE,        ///< Sentencia if-else
    STMT_PROCEDURE_INV,  ///< Sentencia de invocacion de proceso
    STMT_BLOCK,          ///< Sentencia de bloque begin-end
    STMT_BLOCK_COBEGIN,  ///< Sentencia de bloque cobegin-coend
    STMT_FORK,           ///< Sentencia fork
    STMT_ATOMIC,         ///< Sentencia atomica
    STMT_RETURN          ///< Sentencia de retorno (para funciones)
} statement_t;

// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DEL AST -----

/**
 * @brief Estructura que representa una declaración en Lamport.
 * 
 * Esta estructura almacena información sobre una declaración en el programa Lamport.
 * Puede contener el nombre de la declaración, su tipo, un valor (si es una expresión),
 * código asociado (si es una función), y un enlace a la siguiente declaración en el programa.
 */
struct declaration{
    char *name;                 ///< Nombre de la declaracion.
    struct type *type;          ///< Tipo de la declaracion.
    struct expression *value;   ///< Valor asociado (si es declaracion de variable)
    struct statement *code;     ///< Codigo asociado (si es la declaracion de una funcion)
    struct declaration *next;   ///< Puntero a la siguiente declaracion
};

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
 *          ///> name       -> NULL
 *          ///> decl       -> ACTIVE
 *          ///> init_expr  -> NULL
 *          ///> expr       -> NULL
 *          ///> next_expr  -> NULL
 *          ///> body       -> NULL
 *          ///> else_body  -> NULL
 *          ///> parameters -> NULL
 *          ///> next       -> NULL
 * 
 * STMT_WHILE :
 *    --> Descripcion: Indica la estructura completa de un while
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_WHILE
 *          ///> name       -> NULL
 *          ///> decl       -> NULL
 *          ///> init_expr  -> NULL
 *          ///> expr       -> ACTIVE
 *          ///> next_expr  -> NULL
 *          ///> body       -> ACTIVE
 *          ///> else_body  -> NULL
 *          ///> parameters -> NULL
 *          ///> next       -> NULL
 * 
 * STMT_FOR :
 *    --> Descripcion: Indica la estructura completa de un bucle for
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_FOR
 *          ///> name       -> NULL
 *          ///> decl       -> NULL
 *          ///> init_expr  -> ACTIVE
 *          ///> expr       -> ACTIVE
 *          ///> next_expr  -> ACTIVE
 *          ///> body       -> ACTIVE
 *          ///> else_body  -> NULL
 *          ///> parameters -> NULL
 *          ///> next       -> NULL
 * 
 * STMT_IF_ELSE :
 *    --> Descripcion: Indica la estructura completa de un if-else
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_IF_ELSE
 *          ///> name       -> NULL
 *          ///> decl       -> NULL
 *          ///> init_expr  -> NULL
 *          ///> expr       -> ACTIVE
 *          ///> next_expr  -> NULL
 *          ///> body       -> ACTIVE
 *          ///> else_body  -> ACTIVE
 *          ///> parameters -> NULL
 *          ///> next       -> NULL 
 * 
 * STMT_PROCEDURE_INV :
 *    --> Descripcion: Indica la invocacion de un procedimiento
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_PROCEDURE_INV
 *          ///> name       -> ACTIVE
 *          ///> decl       -> NULL
 *          ///> init_expr  -> NULL
 *          ///> expr       -> NULL
 *          ///> next_expr  -> NULL
 *          ///> body       -> NULL
 *          ///> else_body  -> NULL
 *          ///> parameters -> ACTIVE
 *          ///> next       -> NULL
 * 
 * STMT_BLOCK :
 *    --> Descripcion: Indica la consecucion de un bloque begin-end
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_BLOCK
 *          ///> name       -> NULL
 *          ///> decl       -> NULL
 *          ///> init_expr  -> NULL
 *          ///> expr       -> NULL
 *          ///> next_expr  -> NULL
 *          ///> body       -> ACTIVE
 *          ///> else_body  -> NULL
 *          ///> parameters -> NULL
 *          ///> next       -> NULL
 * 
 * STMT_BLOCK_COBEGIN :
 *    --> Descripcion: Indica la consecucion de un bloque begin-end
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_BLOCK_COBEGIN
 *          ///> name       -> NULL
 *          ///> decl       -> NULL
 *          ///> init_expr  -> NULL
 *          ///> expr       -> NULL
 *          ///> next_expr  -> NULL
 *          ///> body       -> ACTIVE
 *          ///> else_body  -> NULL
 *          ///> parameters -> NULL
 *          ///> next       -> NULL
 * 
 * STMT_FORK :
 *    --> Descripcion: Indica la realizacion de un fork a un proceso
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_FORK
 *          ///> name       -> ACTIVE
 *          ///> decl       -> NULL
 *          ///> init_expr  -> NULL
 *          ///> expr       -> NULL
 *          ///> next_expr  -> NULL
 *          ///> body       -> ACTIVE
 *          ///> else_body  -> NULL
 *          ///> parameters -> NULL
 *          ///> next       -> NULL
 * 
 * STMT_ATOMIC :
 *    --> Descripcion: Indica la consecucion de un bloque atomico
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_ATOMIC
 *          ///> name       -> NULL
 *          ///> decl       -> NULL
 *          ///> init_expr  -> NULL
 *          ///> expr       -> NULL
 *          ///> next_expr  -> NULL
 *          ///> body       -> ACTIVE
 *          ///> else_body  -> NULL
 *          ///> parameters -> NULL
 *          ///> next       -> NULL
 * 
 * STMT_RETURN :
 *    --> Descripcion: Indica el retorno de una funcion
 *    --> Estado de los atributos del struct:
 *          ///> kind       -> STMT_ATOMIC
 *          ///> name       -> NULL
 *          ///> decl       -> NULL
 *          ///> init_expr  -> NULL
 *          ///> expr       -> ACTIVE
 *          ///> next_expr  -> NULL
 *          ///> body       -> NULL
 *          ///> else_body  -> NULL
 *          ///> parameters -> NULL
 *          ///> next       -> NULL    
 */
struct statement{
    statement_t kind;
    char *name;
    struct declaration *decl;
    struct expression *init_expr;
    struct expression *expr;        
    struct expression *next_expr;
    struct statement *body;
    struct statement *else_body;
    struct parameter *parameters;
    struct statement *next;
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST -----

/**
 * @brief Crea y reserva memoria para una declaracion, inicialiando su contenido
 * @param name : Nombre de la declaracion
 * @param type : Tipo de la declaracion
 * @param value : Valor de una expresion (declaraciones de variables)
 * @param code : Cuerpo de una funcion (declaraciones de funciones)
 * @param next : Puntero a la siguiente declaracion
 */
struct declaration * create_declaration(
    char *name, 
    struct type *type, 
    struct statement *code, 
    struct declaration *next
);

/**
 * @brief Crea y reserva memoria para una sentencia, inicializando su contenido
 * @param kind : Tipo de sentencia
 * @param name : Nombre de declaracion (si kind = STMT_ASSIGNMENT | STMT_FORK)
 * @param decl : Declaraciones (si kind = STMT_ASSIGNMENT)
 * @param init_expr : Inicio de expresion (si kind = STMT_FOR)
 * @param expr : Expresiones (si kind = STMT_WHILE | STMT_FOR | STMT_IF_ELSE | STMT_RETURN)
 * @param next_expr : Expresion siguiente (si kind = STMT_FOR)
 * @param body : Cuerpo con lista de sentencias (si kind = )
 * @param else_body : Cuerpo con lista de sentencias (si kind = STMT_IF_ELSE)
 * @param parameters : Parametros de un procedimiento (si kind = STMT_PROCEDURE_INV)
 * @param next : Puntero a siguiente sentencia
 */
struct statement * create_statement(
    statement_t kind,
    char *name,
    struct declaration *decl,
    struct expression *init_expr,
    struct expression *expr,
    struct expression *next_expr,
    struct statement *body,
    struct statement *else_body,
    struct parameter *parameters,
    struct statement *next
);

#endif //_LAMPORT_AST_DPR_