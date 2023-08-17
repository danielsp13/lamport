/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file AST.h
 * @author Daniel Perez Ruiz
 * @brief Definicion de estructuras y funciones para creacion y mantenimiento
 * del Arbol Sintactico Abstracto (AST en ingles)
 */

#ifndef _LAMPORT_AST_DPR_
#define _LAMPORT_AST_DPR_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

// ===============================================================

// ----- DEFINICION DE TIPOS DE ESTRUCTURAS DEL AST -----

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

/**
 * @brief Estructura que representa los tipos de datos del lenguaje de lamport.
 */
typedef enum{
    TYPE_INTEGER,           ///< Tipo de dato entero
    TYPE_BOOLEAN,           ///< Tipo de dato booleano
    TYPE_CHAR,              ///< Tipo de dato caracter
    TYPE_STRING,            ///< Tipo de dato cadena de caracteres
    TYPE_REAL,              ///< Tipo de dato flotante
    TYPE_ARRAY,             ///< Tipo de dato array
    TYPE_SEMAPHORE,         ///< Tipo de dato semaforo
    TYPE_DPROCESS,          ///< Tipo de dato proceso dinamico
    TYPE_FUNCTION           ///< Tipo de dato de funciones
} type_t;

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
    struct statement *next;                         ///< Puntero a siguiente sentencia
    union 
    {
        // Estructura de sentencia de asignacion
        struct {
            const char *variable_name;              ///< Nombre de la variable
            struct expression *expr;                ///< Expresion de la asignacion
        } statement_assignment;

        // Estructura de sentencia de bucle while
        struct {
            struct expression *condition;           ///< Condicion del bucle
            struct statement *body;                 ///< Cuerpo del bucle (conjunto de sentencias)
        } statement_while;

        // Estructura de sentencia de bucle for
        struct {
            struct expression *intialization;       ///< Inicializacion de contadores de bucle
            struct expression *condition;           ///< Condicion del bucle
            struct expression *increment;           ///< Incremento de contadores de bucle
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
            const char *procedure_name;             ///< Nombre del procedimiento
            struct parameter_list *parameters;     ///< Parametros del procedimiento
        } statement_procedure_inv;

        // Estructura de sentencia de bloque begin-end o cobegin-coend o atomic
        struct {
            struct statement *body;                 ///< Conjunto de sentencias
        } statement_block;

        // Estructura de sentencia fork
        struct {
            const char *forked_process;             ///< Nombre del proceso
            struct statement *stmt;                 ///< Sentencia
        } statement_fork;

        // Estructura de sentencia return (para funciones)
        struct {
            struct expression *returned_expr;       ///< Expresion de retorno
        } statement_return;
    } stmt;                                         ///< Sentencia
    
};

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
    struct expression *next;                                ///< Puntero a siguiente expresion
    union
    {
        // Estructura de expresion de operacion binaria
        struct {
            expression_binary_t kind;                       ///< Tipo de operacion binaria
            const char *operator;                           ///< Operador de operacion
            struct expression *left;                        ///< Expresion izquierda de la operacion
            struct expression *right;                       ///< Expresion derecha de la operacion
        } expression_binary_operation;

        // Estructura de expresion de operacion unaria
        struct {
            expression_unary_t kind;                        ///< Tipo de la operacion unaria
            const char *operator;                           ///< Operador de operacion
            struct expression *left;                        ///< Expresion derecha de la operacion
        } expression_unary_operation;

        // Expresion de identificador
        const char *id;                                     ///< Valor de identificador

        // Estructura de expresion de literal
        struct {
            expression_literal_t kind;                      ///< Tipo de literal
            union{
                int integer_literal;                        ///< Valor para literal entero
                float real_literal;                         ///< Valor para literal flotante
                bool boolean_literal;                       ///< Valor para literal booleano
                char character_literal;                     ///< Valor para literal de caracter
                char* string_literal;                       ///< Valor para literal de cadena de caracteres
            } value;
        } expression_literal;

        // Estructura de expresion de invocacion de funcion
        struct {
            const char *function_name;                      ///< Nombre de funcion
            struct parameter_list *parameters;              ///< Lista de parametros para funciones
        } expression_function_inv;

        // Expresion entre parentesis
        struct expression *grouped_expression;              ///< Expresion entre parentesis
    } expr;
    
};

/**
 * @brief Estructura que representa a un tipo de dato en lamport.
 * 
 * Esta estructura almacena informacion sobre un tipo de dato de una variable
 * o de una funcion mencionada en una declaracion, en el lenguaje lamport.
 * 
 * Dependiendo del tipo de dato, se requerira mas informacion adicional
 * para describir adecuadamente el valor de la variable o el retorno de la funcion.
 * 
 * TIPOS DE DATO BASICOS
 *   -> Son tipos de datos simples, conocidos:
 *   -> Lista:
 *      ///> INTEGERstruct declaration * creat
 *      ///> REAL
 *      ///> BOOLEAN
 *      ///> CHAR
 *      ///> STRING
 * 
 * TIPOS DE DATO COMPUESTOS
 *   -> Son tipos de datos especiales que requieren mas informacion
 *   -> Lista:
 *      ///> ARRAY
 *      ///> SEMAPHORE
 *      ///> DPROCESS
 */
struct type{
    type_t kind;
    struct type *subtype;
    struct parameter_list *parameters;
};

/**
 * @brief Estructura que representa a una lista de parametros de una funcion/procedimiento en lamport.
 * 
 * Esta estructura almacena informacion sobre los parametros de los que dispone una funcion
 * o un procedimiento, indicando el tipo de dato de todas ellas
 */
struct parameter_list{
    char *name_parameter;
    struct type *type;
    struct parameter_list *next;
};

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (DECLARACIONES) -----

/**
 * @brief Crea y reserva memoria para una declaracion, inicialiando su contenido
 * @param name : Nombre de la declaracion
 * @param type : Tipo de la declaracion
 * @param value : Valor de una expresion (declaraciones de variables)
 * @param code : Cuerpo de una funcion (declaraciones de funciones)
 * @return puntero a la declaracion creada
 */
struct declaration * create_declaration(char *name, struct type *type, struct statement *code);

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
 * @param initializacion : Expresion para inicializar los contadores del bucle
 * @param condition : Expresion de condicion del bucle for
 * @param increment : Expresion de incremento de condiciones
 * @param body : Cuerpo del bucle (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
struct statement * create_statement_for(struct expression *initialization, struct expression *condition, struct expression *increment, struct statement *body);

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
struct expression * create_expression_unary_operator(expression_unary_t kind, char *operator, struct expression *left);

/**
 * @brief Crea y reserva memoria para una expresion de identificador
 * @param id : identificador
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_identifier(char *id);

/**
 * @brief Crea y reserva memoria para una expresion de tipo literal
 * @param kind : Tipo de literal
 * @param value : Valor de literal (se realizara un casteo al tipo de literal adecuado)
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_literal(expression_literal_t kind, void *value);

/**
 * @brief Crea y reserva memoria para una expresion de invocacion de funcion
 * @param function_name : Nombre de funcion
 * @param parameters : Parametros de la funcion
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_function_invocation(char *function_name, struct parameter_list *parameters);

/**
 * @brief Crea y reserva memoria para una expresion definida entre parentesis
 * @param grouped_expression : expresion
 * @return puntero con la expresion inicializada
 */
struct expression * create_expression_grouped(struct expression *grouped_expression);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (TIPOS) -----

/**
 * @brief Crea y reserva memoria para un tipo de dato de tipo basico
 * @param kind : tipo de dato
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_basic_type(type_t kind);

/**
 * @brief Crea y reserva memoria para el tipo de dato de una funcion
 * @param subtype : subtipo de dato (para especificar el retorno de la funcion)
 * @param parameters : parametros de la funcion
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_function_type(struct type *subtype, struct parameter_list *parameters);

/**
 * @brief Crea y reserva memoria para el tipo de dato de array
 * @param subtype : tipo de dato almacenado en el array
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_array_type(struct type *subtype);

/**
 * @brief Crea y reserva memoria para el tipo de dato semaphore
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_semaphore_type();

/**
 * @brief Crea y reserva memoria para el tipo de dato proceso dinamico
 * @return puntero con el tipo de dato inicializado
 */
struct type * create_dprocess_type();

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (LISTA DE PARAMETROS) -----

/**
 * @brief Crea y reserva memoria para crear una lista de parametros de funciones o proc
 * @param name_parameter : nombre del parametro
 * @param type : tipo del parametro
 * @return puntero con la lista de parametros inicializada
 */
struct parameter_list * create_parameter_list(char * name_parameter, struct type * type);

#endif //_LAMPORT_AST_DPR_