// ======================================================================
// LAMPORT : SIMULADOR DE SISTEMAS CONCURRENTES Y DISTRIBUIDOS
// ======================================================================
// -- Fichero: parser.y
// -- Autor: Daniel Perez Ruiz
// -- Descripcion: Definicion del analizador sintactico (bison)
// ======================================================================

// ======================================================================
// DECLARACIONES

%{
    // -----------------------------------------------------------------
    // INCLUSION DE COMPONENTES DE LMP

    // -- Inclusion de AST
    #include "AST/AST.h"

    // -- Inclusion del manejador de errores
    #include "error/error_manager.h"

    // -- Inclusion del registro de bloques
    #include "parser/parser_register.h"

    // -----------------------------------------------------------------
    // DEFINICION DE FUNCIONES Y ESTRUCTURAS DE ASISTENCIA DE PARSING

    /**
     * @brief Comprueba si hay errores sintacticos
     * @return 1 (TRUE) si los hay, 0 (FALSE) si no
     */
    int have_syntax_errors();

    // -----------------------------------------------------------------
    // DEFINICION DE FUNCIONES DE MANEJO DE ERRORES

    // -- Directiva de debug interna
    //#define DEBUG_PARSER

    // -----------------------------------------------------------------
    // DEFINICION DE FUNCIONES Y ESTRUCTURAS PROPIAS DE BISON

    // -- Variables y funciones a utilizar por el analizador sintactico
    extern int yylex();
    extern FILE *yyin;
    extern int yylineno;

    void yyerror(const char* s);  
%}

// ======================================================================
// DEFINICION DE TOKENS

%token S_PROGRAM 258
%token S_VAR 259
%token T_INTEGER 260
%token T_BOOLEAN 261
%token T_CHAR 262
%token T_STRING 263
%token T_REAL 264
%token T_ARRAY 265
%token T_SEMAPHORE 266
%token T_DPROCESS 267
%token S_PROCESS 268
%token S_PROCEDURE 269
%token S_FUNCTION 270
%token RETURN 271
%token B_BEGIN 272
%token B_END 273
%token B_COBEGIN 274
%token B_COEND 275
%token S_FORK 276
%token JOIN 277
%token IF 278
%token THEN 279
%token ELSE 280
%token WHILE 281
%token DO 282
%token FOR 283
%token TO 284
%token IDENT 285
%token LITERAL 286
%token L_INTEGER 287
%token L_REAL 288
%token L_BOOLEAN_TRUE 289
%token L_BOOLEAN_FALSE 290
%token L_CHAR 291
%token OP_ASSIGN 292
%token OP_REL_LT 293
%token OP_REL_GT 294
%token OP_REL_LTE 295
%token OP_REL_GTE 296
%token OP_REL_EQ 297
%token OP_REL_NEQ 298
%token OP_SUM 299
%token OP_MINUS 300
%token OP_MULT 301
%token OP_DIV 302
%token OP_MOD 303
%token OP_NOT 304
%token OP_AND 305
%token OP_OR 306
%token PAR_IZDO 307
%token PAR_DCHO 308
%token CORCH_IZDO 309
%token CORCH_DCHO 310
%token DELIM_C 311
%token DELIM_PC 312
%token DELIM_2P 313
%token DELIM_ARR 314
%token DELIM_P 315
%token ATOM_INI 316
%token ATOM_FIN 317
%token PRINT 318
%token NEWLINE 319
%token UNRECOGNIZED_TOKEN 320

// ---- Indicar a bison donde encontrar la cabecera de tokens
%define api.header.include { "lexer/token.h" }


// ======================================================================
// ASOCIATIVIDAD DE OPERACIONES

%left OP_OR
%left OP_AND
%left OP_REL_EQ OP_REL_NEQ
%left OP_REL_LT OP_REL_LTE OP_REL_GT OP_REL_GTE
%left OP_SUM OP_MINUS
%left OP_MULT OP_DIV OP_MOD
%right OP_NOT

// ======================================================================
// ESTRUCTURAS PARA CONSTRUCCION DE AST


%union {
    struct program *prog;
    struct declaration *decl;
    struct subprogram *subprog;
    struct process *proc;
    struct statement *stmt;
    struct expression *expr;
    struct type *type;
    struct parameter *param;
    char *ident;
    char *literal_string;
    char literal_char;
    int literal_int;
    float literal_float;
    int literal_boolean;

    struct declaration_body *decl_body;
};

// ======================================================================
// ESPECIFICACION DE TIPOS DE VALOR SEMANTICO (PARA CONSTRUCCION DE AST)

// ---- TIPO program
%type <prog> program

// ---- TIPO declaracion
%type <decl> declaration list-declarations

// ---- TIPO subprogram
%type <subprog> list-subprograms subprogram
%type <subprog> subprogram-procedure
%type <subprog> subprogram-function

// ---- TIPO process
%type <proc> list-process process process-def process-def-array

// ---- TIPO type
%type <type> type

// ---- TIPO expression
%type <expr> expression 
%type <expr> binary-expression unary-expression
%type <expr> term function-invocation 
%type <expr> literal expr-identifier
%type <expr> list-arguments argument
%type <expr> list-print

// ---- TIPO parameter
%type <param> list-parameters parameter

// ---- TIPO statement
%type <stmt> statement list-statements
%type <stmt> block-statement
%type <stmt> cobegin-statement 
%type <stmt> assignment-statement 
%type <stmt> while-statement for-statement
%type <stmt> if-statement procedure-invocation fork-statement atomic-statement return-statement print-statement

// ---- TIPO identifier
%type <ident> IDENT
%type <ident> program-name subprogram-procedure-name subprogram-function-name parameter-name process-name

// ---- TIPO LITERALS
%type <literal_string> LITERAL
%type <literal_char> L_CHAR
%type <literal_int> L_INTEGER
%type <literal_float> L_REAL
%type <literal_boolean> L_BOOLEAN_TRUE L_BOOLEAN_FALSE

%%

// ======================================================================
// ESPECIFICACION DE REGLAS DE TRADUCCION

// ----/////----------------------------------------------------------
// -- Reglas de generacion de programa completo

program:
    // ===== CORRECTO: Programa lamport completo
    S_PROGRAM program-name list-declarations list-subprograms list-process{
        // -- Crear AST (solo si no hay errores sintacticos)
        AST_program = create_program($2,$3,$4,$5);
    }
    // <-> ERROR: Falta 'program' al comienzo del programa
    | error{
        mark_error_syntax_program_expected_program();
        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
    ;

program-name:
    IDENT{ 
        $$ = $1;
    }
    // <--> ERROR : Nombre de programa incorrecto
    | error { 
        mark_error_syntax_program_expected_identifier();
        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de declaraciones del programa

list-declarations:
    declaration list-declarations{
        $$ = $1;
        $1->next = $2;
    }
    | /* epsilon */{
        $$ = 0;
    }
    ;

declaration:
    // ===== CORRECTO: Declaracion completa con asignacion
    S_VAR IDENT DELIM_2P type OP_ASSIGN expression DELIM_PC{
        char * decl_identifier = $2;
        struct type * decl_type = $4;
        struct expression *decl_expr = $6;

        // -- Crear nodo
        $$ = create_declaration_variable(decl_identifier, decl_type, decl_expr, yylineno);

        // -- Incluir en cache
        add_declaration_to_register($$);
    }
    // ===== CORRECTO: Declaracion completa sin asignacion
    | S_VAR IDENT DELIM_2P type DELIM_PC{
        char * decl_identifier = $2;
        struct type * decl_type = $4;

        // -- Crear nodo
        $$ = create_declaration_variable(decl_identifier, decl_type, 0, yylineno);

        // -- Incluir en cache
        add_declaration_to_register($$);
    }
    // <-> ERROR: se esperaba 'var'
    | error DELIM_PC{
        mark_error_syntax_declaration_expected_var();
        // Recuperar
        YYABORT;
    }
    // <-> ERROR: se esperaba identificador despues de 'var'
    | S_VAR error DELIM_PC{
        mark_error_syntax_declaration_expected_identifier();
        YYABORT;
    }
    // <-> ERROR: se esperaba ':'
    | S_VAR IDENT error DELIM_PC{
        mark_error_syntax_declaration_expected_delim2p();
        YYABORT;
    };
    // <-> ERROR: se esperaba tipo de dato
    | S_VAR IDENT DELIM_2P DELIM_PC{
        mark_error_syntax_type_expected_type();
        YYABORT;
    }
    // <-> ERROR: se esperaba ';'
    | S_VAR IDENT DELIM_2P type error{
        mark_error_syntax_declaration_expected_delimpc();
        free_AST_type_register();
        YYABORT;
    }
    // <-> ERROR: se esperaba operador de asignacion
    | S_VAR IDENT DELIM_2P type expression DELIM_PC{
        mark_error_syntax_declaration_expected_opassign();
        YYABORT;
    }
    // <-> ERROR: se esperaba ';'
    | S_VAR IDENT DELIM_2P type OP_ASSIGN expression error{
        mark_error_syntax_declaration_expected_delimpc();
        YYABORT;
    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de subprogramas del programa

list-subprograms:
    subprogram list-subprograms{
        $$ = $1;
        $1->next = $2;
    }
    | /* epsilon */{
        $$ = 0;
    }
    ;

subprogram:
    subprogram-procedure{
        $$ = $1;
    }
    | subprogram-function{
        $$ = $1;
    }
    ;

subprogram-procedure:
    // ===== CORRECTO: Subprograma procedimiento completo (con lista de parametros)
    S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statement{
        // -- Creacion nodo SUBPROGRAMA (PROCEDURE)
        $$ = create_subprogram_procedure($2, $4, $7, $8, yylineno);
        add_subprogram_to_register($$);
    }
    // ===== CORRECTO: Subprograma procedimiento completo (sin lista de parametros)
    | S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statement{
        // -- Creacion nodo SUBPROGRAMA (PROCEDURE)
        $$ = create_subprogram_procedure($2, 0, $6, $7, yylineno);
        add_subprogram_to_register($$);
    }
    // <--> ERROR: Falta '('
    | S_PROCEDURE subprogram-procedure-name error DELIM_PC{
        mark_error_syntax_subprogram_expected_parizdo();
        YYABORT;
    }
    // <--> ERROR: Falta ')'
    | S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters error {
        mark_error_syntax_subprogram_expected_pardcho();
        free_AST_parameter_register();
        YYABORT;
    }
    // <--> ERROR: Falta ')'
    | S_PROCEDURE subprogram-procedure-name PAR_IZDO error {
        mark_error_syntax_subprogram_expected_pardcho();
        free_AST_parameter_register();
        YYABORT;
    }
    // <--> ERROR: Falta ';'
    | S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO error{
        mark_error_syntax_subprogram_expected_delimpc();
        free_AST_parameter_register();
        YYABORT;
    }
    // <--> ERROR: Falta ';'
    | S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO error{
        mark_error_syntax_subprogram_expected_delimpc();
        free_AST_parameter_register();
        YYABORT;
    } 
    ;

subprogram-procedure-name:
    IDENT{
        $$ = $1;
    }
    // <--> ERROR : Nombre de subprograma procedimiento incorrecto
    | error{
        // -- Mostrar error
        mark_error_syntax_subprogram_procedure_expected_identifier();
        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

subprogram-function:
    // ===== CORRECTO: Subprograma funcion completo (con lista de parametros)
    S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P type DELIM_PC list-declarations block-statement{
        // -- Creacion de nodo SUBPROGRAMA (FUNCTION)
        $$ = create_subprogram_function($2, $4, $9, $10, $7, yylineno);
        add_subprogram_to_register($$);
    }
    // ===== CORRECTO: Subprograma funcion completo (sin lista de parametros)
    | S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P type DELIM_PC list-declarations block-statement{
        // -- Creacion de nodo SUBPROGRAMA (FUNCTION)
        $$ = create_subprogram_function($2, 0, $8, $9, $6, yylineno);
        add_subprogram_to_register($$);
    }
    // <--> ERROR: Falta '('
    | S_FUNCTION subprogram-function-name error DELIM_PC{
        mark_error_syntax_subprogram_expected_parizdo();
        YYABORT;
    }
    // <--> ERROR: Falta ')'
    | S_FUNCTION subprogram-function-name PAR_IZDO list-parameters error DELIM_PC{
        mark_error_syntax_subprogram_expected_pardcho();
        YYABORT;
    }
    // <--> ERROR: Falta ':'
    | S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO type DELIM_PC{
        mark_error_syntax_subprogram_function_expected_delim2p();
        YYABORT;
    }
    // <--> ERROR: Falta ';'
    | S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P type error{
        mark_error_syntax_subprogram_expected_delimpc();
        free_AST_parameter_register();
        YYABORT;
    }
    ;

subprogram-function-name:
    IDENT{
        $$ = $1;
    }
    // <--> ERROR : Nombre de subprograma funcion incorrecto
    | error{
        // -- Mostrar error
        mark_error_syntax_subprogram_function_expected_identifier();
        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de parametros de subprograma

list-parameters:
    parameter DELIM_C list-parameters{
        $$ = $1;
        $1->next = $3;
    }
    | parameter{
        $$ = $1;
    }
    ;

parameter:
    // ===== CORRECTO: Parametro definido con su tipo de dato
    parameter-name DELIM_2P type{
        // -- Creacion de nodo PARAMETRO
        $$ = create_parameter($1, $3, yylineno);
        add_parameter_to_register($$);
    }
    // <--> ERROR : Falta ':'
    | parameter-name error type{
        mark_error_syntax_parameter_expected_delim2p();
        YYABORT;
    }
    ;

parameter-name:
    IDENT{
        $$ = $1;
    }
    // <--> ERROR : Nombre de parametro incorrecto
    | error{
        // -- Mostrar error
        mark_error_syntax_parameter_expected_identifier();
        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de procesos de programa

list-process:
    process{
        $$ = $1;
    }
    | process list-process{
        $$ = $1;
        $1->next = $2;
    }
    ;

process:
    process-def{
        $$ = $1;
    }
    | process-def-array{
        $$ = $1;
    }
    ;

process-def:
    // ===== CORRECTO: Proceso definido de tipo single
    S_PROCESS process-name DELIM_PC list-declarations block-statement{
        // -- Creacion de nodo PROCESO
        $$ = create_process_single($2, $4, $5, yylineno);
        add_process_to_register($$);
    }
    // <--> ERROR : Falta ';'
    | S_PROCESS process-name{
        mark_error_syntax_process_expected_delimpc();
        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

process-def-array:
    // ===== CORRECTO: Proceso definido de tipo vector
    S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC list-declarations block-statement{
        // -- Creacion de nodo PROCESO
        $$ = create_process_vector($2, $11, $12, $4, $6, $8, yylineno);
        add_process_to_register($$);
    }
    // <--> ERROR: Falta '['
    | S_PROCESS process-name IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC{
        mark_error_syntax_process_expected_corchizdo();
        YYABORT;
    }
    // <--> ERROR: Identificador de indexador de proceso incorrecto
    | S_PROCESS process-name CORCH_IZDO error CORCH_DCHO{
        mark_error_syntax_process_expected_index_identifier();
        YYABORT;
    }
    // <--> ERROR: Falta ':'
    | S_PROCESS process-name CORCH_IZDO IDENT error CORCH_DCHO{
        mark_error_syntax_process_expected_delim2p();
        YYABORT;
    }
    // <--> ERROR: Falta '..'
    | S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression error expression CORCH_DCHO DELIM_PC{
        mark_error_syntax_process_expected_delimarr();
        YYABORT;
    }
    // <--> ERROR: Falta ']'
    | S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression{
        mark_error_syntax_process_expected_corchdcho();
        YYABORT;
    }
    ;

process-name:
    IDENT{
        $$ = $1;
    }
    // <--> ERROR : Nombre de variable incorrecto
    | error{
        mark_error_syntax_process_expected_identifier();
        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de tipos de dato

type:
    T_INTEGER{
        // -- Crear nodo de tipo
        $$ = create_basic_type(TYPE_INTEGER);

        // -- Incluir en el registro
        add_type_to_register($$);
    }
    | T_BOOLEAN{
        $$ = create_basic_type(TYPE_BOOLEAN);
        add_type_to_register($$);
    }
    | T_CHAR{
        $$ = create_basic_type(TYPE_CHAR);
        add_type_to_register($$);
    }
    | T_STRING{
        $$ = create_basic_type(TYPE_STRING);
        add_type_to_register($$);
    }
    | T_REAL{
        $$ = create_basic_type(TYPE_REAL);
        add_type_to_register($$);
    }
    | T_ARRAY CORCH_IZDO expression CORCH_DCHO type{
        $$ = create_array_type($5,$3);
        add_type_to_register($$);
    }
    | T_SEMAPHORE{
        $$ = create_semaphore_type();
        add_type_to_register($$);
    }
    | T_DPROCESS{
        $$ = create_dprocess_type();
        add_type_to_register($$);
    }
    | error{
        mark_error_syntax_type_expected_type();
        YYABORT;
    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de sentencias de programa

list-statements:
    statement{
        $$ = $1;
    }
    | statement list-statements{
        $$ = $1;
        $1->next = $2;
    }
    ;

statement:
    block-statement{
        $$ = $1;
    }
    | cobegin-statement{
        $$ = $1;
    }
    | assignment-statement{
        $$ = $1;
    }
    | while-statement{
        $$ = $1;
    }
    | for-statement{
        $$ = $1;
    }
    | if-statement{
        $$ = $1;
    }
    | procedure-invocation{
        $$ = $1;
    }
    | fork-statement{
        $$ = $1;
    }
    | atomic-statement{
        $$ = $1;
    }
    | return-statement{
        $$ = $1;
    }
    | print-statement{
        $$ = $1;
    }
    | error{
        mark_error_syntax_statement_expected_statement();
        YYABORT;
    }
    ;

block-statement:
    // ===== CORRECTO: Bloque de sentencias
    B_BEGIN list-statements B_END{
        $$ = create_statement_block_begin($2);
        add_statement_to_register($$);
    }
    // <--> ERROR: Bloque de sentencias vacio
    | B_BEGIN B_END{
        mark_error_syntax_statement_empty_block();
        YYABORT;
    }
    ;

cobegin-statement:
    // ===== CORRECTO: Bloque de sentencias paralelo
    B_COBEGIN list-statements B_COEND{
        $$ = create_statement_block_cobegin($2);
        add_statement_to_register($$);
    }
    // <--> ERROR: Bloque de sentencias vacio
    | B_COBEGIN B_COEND{
        mark_error_syntax_statement_empty_block();
        YYABORT;
    }
    ;

assignment-statement:
    // ===== CORRECTO: Asignacion a variable
    IDENT OP_ASSIGN expression DELIM_PC{
        // -- Creacion de nodo STATEMENT (ASSIGNMENT)
        $$ = create_statement_assignment($1, 0, $3, yylineno);
        add_statement_to_register($$);
    }
    // ===== CORRECTO: Asignacion a variable indexada
    | IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression DELIM_PC{
        // -- Creacion de nodo STATEMENT (ASSIGNMENT)
        $$ = create_statement_assignment($1, $3, $6, yylineno);
        add_statement_to_register($$);
    }
    // <--> ERROR: Falta ';'
    | IDENT OP_ASSIGN expression{
        mark_error_syntax_statement_expected_delimpc();
        YYABORT;
    }
    // <--> ERROR: Falta ';'
    | IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression{
        mark_error_syntax_statement_expected_delimpc();
        YYABORT;
    }
    ;

while-statement:
    // ===== CORRECTO: Bucle while
    WHILE expression DO block-statement{
        $$ = create_statement_while($2, $4);
        add_statement_to_register($$);
    }
    ;

for-statement:
    // ===== CORRECTO: Bucle for
    FOR IDENT OP_ASSIGN expression TO expression DO block-statement{
        // -- Creacion de nodo STATEMENT (FOR)
        $$ = create_statement_for($2, $4, $6, $8, yylineno);
        add_statement_to_register($$);
    }
    ;

if-statement:
    // ===== CORRECTO: Bloque if
    IF expression THEN block-statement{
        $$ = create_statement_if_else($2, $4, 0);
        add_statement_to_register($$);
    }
    // ===== CORRECTO: Bloque if-else
    | IF expression THEN block-statement ELSE block-statement{
        $$ = create_statement_if_else($2, $4, $6);
        add_statement_to_register($$);
    }
    ;

fork-statement:
    // ===== CORRECTO: Fork de proceso
    S_FORK IDENT DELIM_PC{
        // -- Creacion de nodo STATEMENT (FORK)
        $$ = create_statement_fork($2, yylineno);
        add_statement_to_register($$);
    }
    // <--> ERROR: Falta ';'
    | S_FORK IDENT{
        mark_error_syntax_statement_expected_delimpc();
        YYABORT;
    }
    ;

atomic-statement:
    // ===== CORRECTO: Bloque de sentencias atomicas
    ATOM_INI list-statements ATOM_FIN{
        $$ = create_statement_atomic($2);
        add_statement_to_register($$);
    }
    // ===== CORRECTO: Bloque de sentencias paralelo
    | ATOM_INI ATOM_FIN{
        mark_error_syntax_statement_empty_block();
        YYABORT;
    }
    ;

return-statement:
    // ===== CORRECTO: Sentencia de retorno
    RETURN expression DELIM_PC{
        $$ = create_statement_return($2);
        add_statement_to_register($$);
    }
    // <--> ERROR: Falta ';'
    | RETURN expression{
        mark_error_syntax_statement_expected_delimpc();
        YYABORT;
    }
    ;

print-statement:
    // ===== CORRECTO: Sentencia de impresion
    PRINT PAR_IZDO list-print PAR_DCHO DELIM_PC{
        $$ = create_statement_print($3);
        add_statement_to_register($$);
    }
    // <--> ERROR: Falta ';'
    | PRINT PAR_IZDO list-print PAR_DCHO{
        mark_error_syntax_statement_expected_delimpc();
        YYABORT;
    }
    ;

list-print:
    expression DELIM_C list-print{
        $$ = $1;
        $1->next = $3;
    }
    | expression{
        $$ = $1;
    }
    ;

procedure-invocation:
    // ===== CORRECTO: Invocacion de proceso (Con argumentos)
    IDENT PAR_IZDO list-arguments PAR_DCHO DELIM_PC{
        // -- Creacion de nodo STATEMENT (PROCEDURE INVOCATION)
        $$ = create_statement_procedure_inv($1, $3, yylineno);
        add_statement_to_register($$);
    }
    // ===== CORRECTO: Invocacion de proceso (sin argumentos)
    | IDENT PAR_IZDO PAR_DCHO DELIM_PC{
        // -- Creacion de nodo STATEMENT (PROCEDURE INVOCATION)
        $$ = create_statement_procedure_inv($1, 0, yylineno);
        add_statement_to_register($$);
    }
    ;

function-invocation:
    // ===== CORRECTO: Invocacion de funcion (con argumentos)
    IDENT PAR_IZDO list-arguments PAR_DCHO{
        // -- Creacion de nodo EXPRESSION
        $$ = create_expression_function_invocation($1, $3, yylineno);
        add_expression_to_register($$);

    }
    // ===== CORRECTO: Invocacion de funcion (sin argumentos)
    | IDENT PAR_IZDO PAR_DCHO{
        // -- Creacion de nodo EXPRESSION
        $$ = create_expression_function_invocation($1, 0, yylineno);
        add_expression_to_register($$);
    }
    ;

list-arguments:
    argument DELIM_C list-arguments{
        $$ = $1;
        $1->next = $3;
    }
    | argument{
        $$ = $1;
    }
    ;

argument:
    expression{
        $$ = $1;
    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de expresiones

expression:
    binary-expression{
        $$ = $1;
    }
    | unary-expression{
        $$ = $1;
    }
    | term{
        $$ = $1;
    }
    | error{
        mark_error_syntax_expression_expected_expr();
        YYABORT;
    }
    ;

binary-expression:
    // expression + term
    expression OP_SUM expression{
        $$ = create_expression_binary_operation(EXPR_ADD, "+", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    // expression - term
    | expression OP_MINUS expression{
        $$ = create_expression_binary_operation(EXPR_SUB, "-", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    // expression * term
    | expression OP_MULT expression{
        $$ = create_expression_binary_operation(EXPR_MULT, "*", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    // expression / term
    | expression OP_DIV expression{
        $$ = create_expression_binary_operation(EXPR_DIV, "/", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    // expression % term
    | expression OP_MOD expression{
        $$ = create_expression_binary_operation(EXPR_MOD, "%", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    // expression < term
    | expression OP_REL_LT expression{
        $$ = create_expression_binary_operation(EXPR_LT, "<", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    // expression <= term
    | expression OP_REL_LTE expression{
        $$ = create_expression_binary_operation(EXPR_LTE, "<=", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    // expression > term
    | expression OP_REL_GT expression{
        $$ = create_expression_binary_operation(EXPR_GT, ">", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    // expression >= term
    | expression OP_REL_GTE expression{
        $$ = create_expression_binary_operation(EXPR_GTE, ">=", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    // expression == term
    | expression OP_REL_EQ expression{
        $$ = create_expression_binary_operation(EXPR_EQ, "==", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    // expression != term
    | expression OP_REL_NEQ expression{
        $$ = create_expression_binary_operation(EXPR_NEQ, "!=", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    // expression and term
    | expression OP_AND expression{
        $$ = create_expression_binary_operation(EXPR_AND, "and", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    // expression or term
    | expression OP_OR expression{
        $$ = create_expression_binary_operation(EXPR_OR, "or", $1, $3, yylineno);
        add_expression_to_register($$);
    }
    ;
    
unary-expression:
    // not term
    OP_NOT term{
        $$ = create_expression_unary_operation(EXPR_NOT, "not", $2,yylineno);
        add_expression_to_register($$);
    }
    // - term
    | OP_MINUS term %prec OP_MINUS{
        $$ = create_expression_unary_operation(EXPR_NEGATIVE, "-", $2,yylineno);
        add_expression_to_register($$);
    }
    ;

term:
    expr-identifier{
        $$ = $1;
    }
    | literal{
        $$ = $1;
    }
    | function-invocation{
        $$ = $1;
    }
    | PAR_IZDO expression PAR_DCHO{
        $$ = create_expression_grouped($2);
        add_expression_to_register($$);
    }
    ;
    
// -- Reglas de generacion de literales
literal:
    LITERAL{
        // -- Crear expresion literal
        $$ = create_expression_literal_string($1);
        add_expression_to_register($$);
    }
    | L_INTEGER{
        $$ = create_expression_literal_integer($1);
        add_expression_to_register($$);
    }
    | L_BOOLEAN_TRUE{
        $$ = create_expression_literal_boolean(1);
        add_expression_to_register($$);
    }
    | L_BOOLEAN_FALSE{
        $$ = create_expression_literal_boolean(0);
        add_expression_to_register($$);
    }
    | L_CHAR{
        $$ = create_expression_literal_char($1);
        add_expression_to_register($$);
    }
    | L_REAL{
        $$ = create_expression_literal_real($1);
        add_expression_to_register($$);
    }
    ;

expr-identifier:
    IDENT{
        // -- Crear expresion
        $$ = create_expression_identifier($1,0, yylineno);
        add_expression_to_register($$);
    }
    | IDENT CORCH_IZDO expression CORCH_DCHO{
        // -- Crear expresion
        $$ = create_expression_identifier($1, $3, yylineno);
        add_expression_to_register($$);
    }
    ;

%%

// Soporte de las rutinas en C


void yyerror(const char *s) {
    if(strcmp(s, "syntax error") != 0)
        fprintf(stderr, "--- Error de sintaxis en la línea %d -> %s\n", yylineno, s);
}


int have_syntax_errors(){
    return get_total_error_syntax() > 0;
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (DECLARACIONES)

void mark_error_syntax_declaration_expected_var(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_VAR_TOKEN_MSG);
}  

void mark_error_syntax_declaration_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_IDENTIFIER_AFTER_VAR_MSG);
}

void mark_error_syntax_declaration_expected_delim2p(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_DELIM2P_TOKEN_MSG);
}

void mark_error_syntax_declaration_expected_opassign(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_EXPR, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_OPASSIGN_TOKEN_MSG);
}

void mark_error_syntax_declaration_expected_delimpc(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_DELIMPC_DECL_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (SUBPROGRAMAS)

void mark_error_syntax_subprogram_expected_procedure(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROCEDURE_EXPECTED_PROCEDURE_TOKEN_MSG);
}

void mark_error_syntax_subprogram_procedure_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_PROCEDURE_EXPECTED_IDENTIFIER_AFTER_PROCEDURE_MSG);
}

void mark_error_syntax_subprogram_function_expected_function(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_FUNCTION_TOKEN_MSG);
}

void mark_error_syntax_subprogram_function_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_IDENTIFIER_AFTER_FUNCTION_MSG);
}

void mark_error_syntax_subprogram_function_expected_delim2p(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_DELIM2P_TOKEN_MSG);
}

void mark_error_syntax_subprogram_expected_parizdo(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_SUBPROGRAM_EXPECTED_PARIZDO_TOKEN_MSG);
}

void mark_error_syntax_subprogram_expected_pardcho(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_SUBPROGRAM_EXPECTED_PARDCHO_TOKEN_MSG);
}

void mark_error_syntax_subprogram_expected_delimpc(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_SUBPROGRAM_EXPECTED_DELIMPC_TOKEN_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (TIPOS)

void mark_error_syntax_type_expected_type(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_TYPE_EXPECTED_TYPE_TOKEN_MSG);
}


// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (PARAMETROS)

void mark_error_syntax_parameter_expected_parameter(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PARAMETER_EXPECTED_PARAMETER_MSG);
}

void mark_error_syntax_parameter_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_PARAMETER_EXPECTED_IDENTIFIER_MSG);
}

void mark_error_syntax_parameter_expected_delim2p(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PARAMETER_EXPECTED_DELIM2P_MSG);
}

void mark_error_syntax_parameter_expected_delimc(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PARAMETER_EXPECTED_DELIMC_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (SENTENCIAS)

void mark_error_syntax_statement_expected_statement(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_STMT, yylineno, ERR_SYNTAX_STATEMENT_EXPECTED_STATEMENT_MSG);
}

void mark_error_syntax_statement_empty_block(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_STMT, yylineno, ERR_SYNTAX_STATEMENT_EXPECTED_NON_EMPTY_BLOCK_MSG);
}

void mark_error_syntax_statement_expected_delimpc(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_EXPR, yylineno, ERR_SYNTAX_STATEMENT_EXPECTED_DELIMPC_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (EXPRESIONES)

void mark_error_syntax_expression_expected_expr(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_EXPR, yylineno, ERR_SYNTAX_EXPRESSION_EXPECTED_EXPRESSION_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (PROCESOS)

void mark_error_syntax_process_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_IDENTIFIER_AFTER_PROCESS_MSG);
}

void mark_error_syntax_process_expected_delimpc(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_DELIMPC_MSG);
}

void mark_error_syntax_process_expected_corchizdo(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_CORCHIZDO_MSG);
}

void mark_error_syntax_process_expected_corchdcho(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_CORCHDCHO_MSG);
}

void mark_error_syntax_process_expected_index_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_IDENTIFIER_INDEXER_MSG);
}

void mark_error_syntax_process_expected_delim2p(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_DELIM2P_MSG);
}

void mark_error_syntax_process_expected_delimarr(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_DELIMARR_MSG);
}

// ----/////----------------------------------------------------------
// FUNCIONES DE MANEJO DE ERRORES (PROGRAMAS)

void mark_error_syntax_program_expected_program(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROGRAM_EXPECTED_PROGRAM_TOKEN_MSG);
}

void mark_error_syntax_program_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_PROGRAM_EXPECTED_IDENTIFIER_AFTER_PROGRAM_MSG);
}