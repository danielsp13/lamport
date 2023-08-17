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
 * @brief Estructura que repesenta los tipos de sentencias de lamport
 */
typedef enum{
    EXPR_ADD,
    EXPR_SUB,
    EXPR_MULT,
    EXPR_DIV,
    EXPR_MOD,
    EXPR_IDENTIFIER,
    EXPR_LITERAL_INTEGER,
    EXPR_LITERAL_REAL,
    EXPR_LITERAL_CHARACTER,
    EXPR_LITERAL_STRING,
} expression_t;



// ===============================================================

// ----- DEFINICION DE ESTRUCTURAS DEL AST -----

/**
 * @brief Estructura que representa una declaración en Lamport.
 * 
 * Esta estructura almacena información sobre una declaración en el programa Lamport.
 * Puede contener el nombre de la declaración, su tipo, un valor (si es una expresión),
 * código asociado (si es una función), y un enlace a la siguiente declaración en el programa.
 */
typedef struct declaration{
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
typedef struct statement{
    statement_t kind;                       ///< Tipo de sentencia
    statement *next;                        ///< Puntero a siguiente sentencia
    union 
    {
        // Estructura de sentencia de asignacion
        struct statement_assignment{
            const char *variable_name;      ///< Nombre de la variable
            expression *expr;               ///< Expresion de la asignacion
        };

        // Estructura de sentencia de bucle while
        struct statement_while{
            expression *condition;          ///< Condicion del bucle
            statement *body;                ///< Cuerpo del bucle (conjunto de sentencias)
        };

        // Estructura de sentencia de bucle for
        struct statement_for{
            expression *intialization;      ///< Inicializacion de contadores de bucle
            expression *condition;          ///< Condicion del bucle
            expression *increment;          ///< Incremento de contadores de bucle
            statement *body;                ///< Cuerpo del bucle (conjunto de sentencias)
        };
        
        // Estructura de sentencia de if-else
        struct statement_if_else{           
            expression *condition;          ///< Condicion de if-else
            statement *if_body;             ///< Cuerpo del if [condition se evalua como verdadera] (conjunto de sentencias)
            statement *else_body;           ///< Cuerpo del else [condition se evalua como falsa] (conjunto de sentencias)
        };

        // Estructura de sentencia de invocacion de proceso
        struct statement_procedure_inv{
            const char *procedure_name;     ///< Nombre del procedimiento
            parameters_list *parameters;    ///< Parametros del procedimiento
        };

        // Estructura de sentencia de bloque begin-end o cobegin-coend o atomic
        struct statement_block{
            statement *body;                ///< Conjunto de sentencias
        };

        // Estructura de sentencia fork
        struct statement_fork{
            const char *forked_process;     ///< Nombre del proceso
            statement *stmt;                ///< Sentencia
        };

        // Estructura de sentencia return (para funciones)
        struct statement_return{
            expression *returned_expr;      ///< Expresion de retorno
        };
    } stmt;                                 ///< Sentencia
    
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
declaration * create_declaration(char *name, type *type, statement *code);

// ===============================================================

// ----- PROTOTIPO DE FUNCIONES PARA CONSTRUCCION DEL AST (SENTENCIAS) -----

/**
 * @brief Crea y reserva memoria para una sentencia de asignacion (STMT_ASSIGNMENT).
 * @param variable_name : Nombre de la variable
 * @param expr : Expresion a asignar
 * @return puntero con la sentencia incializada
 */
statement * create_statement_assignment(char *variable_name, expression *expr);

/**
 * @brief Crea y reserva memoria para una sentencia de bucle while (STMT_WHILE)
 * @param condition : Condicion del bucle
 * @param body : Cuerpo del bucle (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
statement * create_statement_while(expression *condition, statement *body);

/**
 * @brief Crea y reserva memoria para una sentencia de bucle for (STMT_FOR)
 * @param initializacion : Expresion para inicializar los contadores del bucle
 * @param condition : Expresion de condicion del bucle for
 * @param increment : Expresion de incremento de condiciones
 * @param body : Cuerpo del bucle (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
statement * create_statement_for(expression *initialization, expression *condition, expression *increment, statement *body);

/**
 * @brief Crea y reserva memoria para una sentencia de control de flujo if-else
 * @param condition : Expresion de condicion de control
 * @param if_body : Cuerpo de if (conjunto de sentencias)
 * @param else_body : Cuerpo de else (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
statement * create_statement_if_else(expression *condition, statement *if_body, statement *else_body);

/**
 * @brief Crea y reserva memoria para una sentencia de invocacion de procedimiento
 * @param procedure_name : Nombre del procedimiento
 * @param parameters : Lista de parametros del procedimiento
 * @return puntero con la sentencia inicializada
 */
statement * create_statement_procedure_inv(char *procedure_name, parameters_list *parameters);

/**
 * @brief Crea y reserva memoria para una sentencia de construccion de bloques
 * @param block_type : Tipo de bloque (permitidos:  STMT_BLOCK_BEGIN | STMT_BLOCK_COBEGIN | STMT_ATOMIC)
 * @param body : Cuerpo del bloque (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
statement * create_block_of_statements(statement_t block_type, statement *body);

/**
 * @brief Crea y reserva memoria para una sentencia de bloques begin-end
 * @param body : Cuerpo del bloque (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
statement * create_statement_block_begin(statement *body);

/**
 * @brief Crea y reserva memoria para una sentencia de bloques cobegin-coend
 * @param body : Cuerpo del bloque (conjunto de sentencias)
 * @return puntero con la sentencia inicializada
 */
statement * create_statement_block_cobegin(statement *body);

/**
 * @brief Crea y reserva memoria para una sentencia atomica
 * @param body : Listado de sentencias atomicas
 * @return puntero con la sentencia inicializada
 */
statement * create_statement_atomic(statement *body);

/**
 * @brief Crea y reserva memoria para una sentencia fork
 * @param process_name : Nombre del proceso
 * @param stmt : Sentencia
 * @return puntero con la sentencia inicializada
 */
statement * create_statement_fork(char *process_name, statement *stmt);

/**
 * @brief Crea y reserva memoria para una sentencia de retorno (para funciones)
 * @param returned_expr : Expresion de retorno
 * @return puntero con la sentencia inicializada
 */
statement * create_statement_return(expression *returned_expr);

#endif //_LAMPORT_AST_DPR_