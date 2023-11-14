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
%token SEM_WAIT 319
%token SEM_SIGNAL 320
%token SLEEP 321
%token UNRECOGNIZED_TOKEN 322

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
%type <proc> list-process process 
%type <proc> process-def process-def-array

// ---- TIPO type
%type <type> type
%type <type> basic-or-array-type
%type <type> basic-type
%type <type> special-type

// ---- TIPO expression
%type <expr> expression 
%type <expr> binary-expression unary-expression term
%type <expr> function-call-expression 
%type <expr> literal 
%type <expr> expr-identifier
%type <expr> list-arguments argument
%type <expr> list-print

// ---- TIPO parameter
%type <param> list-parameters parameter

// ---- TIPO statement
%type <stmt> statement list-statements
%type <stmt> block-statements-begin-end
%type <stmt> block-statements-cobegin-coend
%type <stmt> block-statements-atomic
%type <stmt> block-statements-function
%type <stmt> assignment-statement 
%type <stmt> while-statement 
%type <stmt> for-statement
%type <stmt> if-statement 
%type <stmt> procedure-call-statement 
%type <stmt> fork-statement join-statement
%type <stmt> return-statement 
%type <stmt> print-statement
%type <stmt> sem-wait-statement
%type <stmt> sem-signal-statement
%type <stmt> sleep-statement

// ---- TIPO identifier
%type <ident> IDENT
%type <ident> program-name
%type <ident> subprogram-procedure-name 
%type <ident> subprogram-function-name 
%type <ident> parameter-name 
%type <ident> process-name

// ---- TIPO LITERALS
%type <literal_string> LITERAL
%type <literal_char> L_CHAR
%type <literal_int> L_INTEGER
%type <literal_float> L_REAL
%type <literal_boolean> L_BOOLEAN_TRUE L_BOOLEAN_FALSE

// ======================================================================
// ESPECIFICACION DE SIMBOLO INICIAL

%start program

%%

// ======================================================================
// ESPECIFICACION DE REGLAS DE TRADUCCION

// ----/////----------------------------------------------------------
// -- Reglas de generacion de programa completo

program:
    // ===== CORRECTO: Programa lamport completo
    S_PROGRAM program-name DELIM_PC list-declarations list-subprograms list-process{
        // -- Crear AST (solo si no hay errores sintacticos)
        if(!have_syntax_errors())
            AST_program = create_program($2,$4,$5,$6);
    }
    | S_PROGRAM program-name list-declarations list-subprograms list-process{
        // -- Crear AST (solo si no hay errores sintacticos)
        if(!have_syntax_errors())
            AST_program = create_program($2,$3,$4,$5);
    }
    | error S_PROGRAM program-name DELIM_PC list-declarations list-subprograms list-process{
        mark_error_syntax_program_unexpected_literal_in_header();
        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
    | S_PROGRAM error list-process{
        mark_error_syntax_program_unexpected_literal_in_header();
        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
    // <-> ERROR: Falta 'program' al comienzo del programa
    /*| program-name DELIM_PC list-declarations list-subprograms list-process{
        mark_error_syntax_program_expected_program($1);
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }
    | program-name list-declarations list-subprograms list-process{
        mark_error_syntax_program_expected_program($1);
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }
    | program-name DELIM_PC literal list-declarations list-subprograms list-process{
        mark_error_syntax_program_unexpected_literal();
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }
    | program-name literal list-declarations list-subprograms list-process{
        mark_error_syntax_program_unexpected_literal();
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }

    // <--> ERROR : Nombre de programa incorrecto
    | S_PROGRAM error DELIM_PC list-declarations list-subprograms list-process{
        mark_error_syntax_program_expected_identifier();
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }*/
    
    ;

program-name:
    IDENT{ 
        $$ = $1;
    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de declaraciones del programa

list-declarations:
    declaration list-declarations{
        if(!have_syntax_errors()){
            $$ = $1;
            $1->next = $2;
        }
        else{
            $$ = 0;
        }
    }
    | /* epsilon */{
        $$ = 0;
    }
    ;

declaration:
    // ===== CORRECTO: Declaracion completa con asignacion
    S_VAR IDENT DELIM_2P type OP_ASSIGN expression DELIM_PC{
        if(!have_syntax_errors()){
            $$ = create_declaration_variable($2, $4, $6, yylineno);
            add_declaration_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // ===== CORRECTO: Declaracion completa sin asignacion
    | S_VAR IDENT DELIM_2P type DELIM_PC{
        if(!have_syntax_errors()){
            $$ = create_declaration_variable($2, $4, 0, yylineno);
            add_declaration_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <-> ERROR: se esperaba 'var'
    | IDENT DELIM_2P type DELIM_PC{
        mark_error_syntax_declaration_expected_var($1);
        // Recuperar
        //YYABORT;
    }
    // <-> ERROR: se esperaba identificador despues de 'var'
    | S_VAR error DELIM_PC{
        mark_error_syntax_declaration_expected_identifier();
        //YYABORT;
    }
    // <-> ERROR: se esperaba ':'
    | S_VAR IDENT error DELIM_PC{
        mark_error_syntax_declaration_expected_delim2p($2);
        //YYABORT;
    };
    // <-> ERROR: se esperaba tipo de dato
    | S_VAR IDENT DELIM_2P DELIM_PC{
        mark_error_syntax_type_expected_type($2);
        //YYABORT;
    }
    // <-> ERROR: se esperaba ';'
    | S_VAR IDENT DELIM_2P type error{
        mark_error_syntax_declaration_expected_delimpc($2);
        free_AST_type_register($4);
        //YYABORT;
    }
    // <-> ERROR: se esperaba operador de asignacion
    | S_VAR IDENT DELIM_2P type expression DELIM_PC{
        mark_error_syntax_declaration_expected_opassign($2);
        //YYABORT;
    }
    // <-> ERROR: se esperaba ';'
    | S_VAR IDENT DELIM_2P type OP_ASSIGN expression{
        mark_error_syntax_declaration_expected_delimpc($2);
        //YYABORT;
    }
    | S_VAR IDENT DELIM_2P type OP_ASSIGN expression DELIM_PC error{
        mark_error_syntax_program_unexpected_literal_in_decl($2);
        YYABORT;
    }
    | S_VAR IDENT DELIM_2P type DELIM_PC error{
        mark_error_syntax_program_unexpected_literal_in_decl($2);
        YYABORT;
    }
    
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de subprogramas del programa

list-subprograms:
    subprogram list-subprograms{
        if(!have_syntax_errors()){
            $$ = $1;
            $1->next = $2;
        }
        else{
            $$ = 0;
        }
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
    S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statements-begin-end{
        // -- Creacion nodo SUBPROGRAMA (PROCEDURE)
        if(!have_syntax_errors()){
            $$ = create_subprogram_procedure($2, $4, $7, $8, yylineno);
            add_subprogram_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // ===== CORRECTO: Subprograma procedimiento completo (sin lista de parametros)
    | S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statements-begin-end{
        // -- Creacion nodo SUBPROGRAMA (PROCEDURE)
        if(!have_syntax_errors()){
            $$ = create_subprogram_procedure($2, 0, $6, $7, yylineno);
            add_subprogram_to_register($$);
        }
        else{
            $$ = 0;
        }
        
    }
    // <--> ERROR: Error de identificador de procedure
    | S_PROCEDURE error PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statements-begin-end{
        mark_error_syntax_subprogram_procedure_expected_identifier();
        //YYABORT;
    }
    // <--> ERROR: Error de identificador de procedure
    | S_PROCEDURE error PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statements-begin-end{
        // -- Mostrar error
        mark_error_syntax_subprogram_procedure_expected_identifier();
        // -- Abortar inmediatmente el analisis
        //YYABORT;
    }
    // <--> ERROR: Parametros mal definidos
    | S_PROCEDURE subprogram-procedure-name PAR_IZDO error PAR_DCHO DELIM_PC list-declarations block-statements-begin-end{
        mark_error_syntax_subprogram_procedure_expected_parameters($2);
        //YYABORT;
    }
    // <--> ERROR: Falta ';'
    | S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO list-declarations block-statements-begin-end{
        mark_error_syntax_subprogram_procedure_expected_delimpc($2);
        free_AST_parameter_register();
        //YYABORT;
    }
    // <--> ERROR: Falta ';'
    | S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO list-declarations block-statements-begin-end{
        mark_error_syntax_subprogram_procedure_expected_delimpc($2);
        free_AST_parameter_register();
        //YYABORT;
    } 
    | S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO DELIM_PC error{
        mark_error_syntax_program_unexpected_literal_in_decl($2);
        YYABORT;
    }
    | S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO DELIM_PC error{
        mark_error_syntax_program_unexpected_literal_in_decl($2);
        YYABORT;
    }
    ;

subprogram-procedure-name:
    IDENT{
        $$ = $1;
    }
    ;

subprogram-function:
    // ===== CORRECTO: Subprograma funcion completo (con lista de parametros)
    S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function{
        // -- Creacion de nodo SUBPROGRAMA (FUNCTION)
        if(!have_syntax_errors()){
            // --- Intermediate: Asignar el nombre de funcion a la sentencia de retorno
            /*struct statement * current_stmt = $10->stmt.statement_block.body;
            while(current_stmt->next){
                current_stmt = current_stmt->next;
            }

            current_stmt->stmt.statement_return.function_name = strdup($2);*/

            // --- Ahora si, crear nodo
            $$ = create_subprogram_function($2, $4, $9, $10, $7, yylineno);
            add_subprogram_to_register($$);
        }
        else{
            $$ = 0;
        }

        
    }
    // ===== CORRECTO: Subprograma funcion completo (sin lista de parametros)
    | S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function{
        // -- Creacion de nodo SUBPROGRAMA (FUNCTION)
        if(!have_syntax_errors()){
            // --- Intermediate: Asignar el nombre de funcion a la sentencia de retorno
            /*struct statement * current_stmt = $9->stmt.statement_block.body;
            while(current_stmt->next){
                current_stmt = current_stmt->next;
            }

            current_stmt->stmt.statement_return.function_name = strdup($2);*/


            $$ = create_subprogram_function($2, 0, $8, $9, $6, yylineno);
            add_subprogram_to_register($$);
        }
        else{
            $$ = 0;
        }

        
    }
    // <--> ERROR: Error de identificador de function
    | S_FUNCTION error PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function{
        mark_error_syntax_subprogram_function_expected_identifier();
        //YYABORT;
    }
    // <--> ERROR: Error de identificador de function
    | S_FUNCTION error PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function{
        mark_error_syntax_subprogram_function_expected_identifier();
        //YYABORT;
    }
    // <--> ERROR: Parametros mal definidos
    | S_FUNCTION subprogram-function-name PAR_IZDO error PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function{
        mark_error_syntax_subprogram_function_expected_parameters($2);
        //YYABORT;
    }
    // <--> ERROR: Falta ':'
    | S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO basic-or-array-type DELIM_PC list-declarations block-statements-function{
        mark_error_syntax_subprogram_function_expected_delim2p($2);
        //YYABORT;
    }
    // <--> ERROR: Falta ':'
    | S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO basic-or-array-type DELIM_PC list-declarations block-statements-function{
        mark_error_syntax_subprogram_function_expected_delim2p($2);
        //YYABORT;
    }
    // <--> ERROR: Falta ';'
    | S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type list-declarations block-statements-function{
        mark_error_syntax_subprogram_function_expected_delimpc($2);
        free_AST_parameter_register();
        //YYABORT;
    }
    // <--> ERROR: Falta ';'
    | S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type list-declarations block-statements-function{
        mark_error_syntax_subprogram_function_expected_delimpc($2);
        free_AST_parameter_register();
        //YYABORT;
    }
    | S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC error{
        mark_error_syntax_program_unexpected_literal_in_decl($2);
        YYABORT;
    }
    | S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC error{
        mark_error_syntax_program_unexpected_literal_in_decl($2);
        YYABORT;
    }
    ;

subprogram-function-name:
    IDENT{
        $$ = $1;
    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de parametros de subprograma

list-parameters:
    parameter DELIM_C list-parameters{
        if(!have_syntax_errors()){
            $$ = $1;
            $1->next = $3;
        }
        else{
            $$ = 0;
        }
    }
    | parameter{
        if(!have_syntax_errors()){
            $$ = $1;
        }
        else{
            $$ = 0;
        }
    }
    ;

parameter:
    // ===== CORRECTO: Parametro definido con su tipo de dato
    parameter-name DELIM_2P type{
        // -- Creacion de nodo PARAMETRO
        if(!have_syntax_errors()){
            $$ = create_parameter($1, $3, yylineno);
            add_parameter_to_register($$);
        }
        else{
            $$ = 0;
        }
        
    }
    ;

parameter-name:
    IDENT{
        $$ = $1;
    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de procesos de programa

list-process:
    process{
        if(!have_syntax_errors()){
            $$ = $1;
        }
        else{
            $$ = 0;
        }
    }
    | process list-process{
        if(!have_syntax_errors()){
            $$ = $1;
            $1->next = $2;
        }
        else{
            $$ = 0;
        }
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
    S_PROCESS process-name DELIM_PC list-declarations block-statements-begin-end{
        // -- Creacion de nodo PROCESO
        if(!have_syntax_errors()){
            $$ = create_process_single($2, $4, $5, yylineno);
            add_process_to_register($$);
        }
        else{
            $$ = 0;
        }
        
    }
    // <--> ERROR : Nombre de proceso incorrecto
    | S_PROCESS error DELIM_PC list-declarations block-statements-begin-end{
        mark_error_syntax_process_expected_identifier();
        //YYABORT;
    }
    // <--> ERROR : Falta ';'
    | S_PROCESS process-name list-declarations block-statements-begin-end{
        mark_error_syntax_process_expected_delimpc($2);
        //YYABORT;
    }
    | S_PROCESS process-name DELIM_PC error{
        mark_error_syntax_program_unexpected_literal_in_proc($2);
        YYABORT;
    }
    ;

process-def-array:
    // ===== CORRECTO: Proceso definido de tipo vector
    S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end{
        // -- Creacion de nodo PROCESO
        if(!have_syntax_errors()){
            $$ = create_process_vector($2, $11, $12, $4, $6, $8, yylineno);
            add_process_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Identificador de indexador de proceso incorrecto
    | S_PROCESS process-name CORCH_IZDO error CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end{
        mark_error_syntax_process_expected_index_identifier($2);
        //YYABORT;
    }
    // <--> ERROR: Falta ':'
    | S_PROCESS process-name CORCH_IZDO IDENT error CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end{
        mark_error_syntax_process_expected_delim2p($2);
        //YYABORT;
    }
    // <--> ERROR: Falta '..'
    | S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression error expression CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end{
        mark_error_syntax_process_expected_delimarr($2);
        //YYABORT;
    }
    | S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC error{
        mark_error_syntax_program_unexpected_literal_in_proc($2);
        YYABORT;
    }
    ;

process-name:
    IDENT{
        $$ = $1;
    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de tipos de dato

type:
    basic-or-array-type{
        $$ = $1;
    }
    | special-type{
        $$ = $1;
    }
    | error{
        mark_error_syntax_type_expected_type();
        //YYABORT;
    }
    ;

basic-or-array-type:
    basic-type{
        $$ = $1;
    }
    | T_ARRAY CORCH_IZDO expression CORCH_DCHO basic-type{
        if(!have_syntax_errors()){
            $$ = create_array_type($5,$3);
            add_type_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Tipo de dato incorrecto
    | T_ARRAY CORCH_IZDO expression CORCH_DCHO{
        mark_error_syntax_type_expected_type();
        //YYABORT;
    } 
    ;

basic-type:
    T_INTEGER{
        if(!have_syntax_errors()){
            $$ = create_basic_type(TYPE_INTEGER);
            add_type_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    | T_BOOLEAN{
        if(!have_syntax_errors()){
            $$ = create_basic_type(TYPE_BOOLEAN);
            add_type_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    | T_CHAR{
        if(!have_syntax_errors()){
            $$ = create_basic_type(TYPE_CHAR);
            add_type_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    | T_STRING{
        if(!have_syntax_errors()){
            $$ = create_basic_type(TYPE_STRING);
            add_type_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    | T_REAL{
        if(!have_syntax_errors()){
            $$ = create_basic_type(TYPE_REAL);
            add_type_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    ;

special-type:
    T_SEMAPHORE{
        if(!have_syntax_errors()){
            $$ = create_semaphore_type();
            add_type_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    | T_DPROCESS{
        if(!have_syntax_errors()){
            $$ = create_dprocess_type();
            add_type_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de sentencias de programa

block-statements-begin-end:
    // ===== CORRECTO: Bloque de sentencias
    B_BEGIN list-statements B_END{
        if(!have_syntax_errors()){
            $$ = create_statement_block_begin($2);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Bloque de sentencias vacio
    | B_BEGIN B_END{
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
    | B_BEGIN error{
        mark_error_syntax_program_unexpected_literal();
        YYABORT;
    }
    ;

block-statements-cobegin-coend:
    // ===== CORRECTO: Bloque de sentencias
    B_COBEGIN list-statements B_COEND{
        if(!have_syntax_errors()){
            $$ = create_statement_block_cobegin($2);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Bloque de sentencias vacio
    | B_COBEGIN B_COEND{
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
    ;

block-statements-atomic:
    // ===== CORRECTO: Bloque de sentencias
    ATOM_INI list-statements ATOM_FIN{
        if(!have_syntax_errors()){
            $$ = create_statement_atomic($2);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Bloque de sentencias vacio
    | ATOM_INI ATOM_FIN{
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
    ;

block-statements-function:
    // ===== CORRECTO: Bloque de sentencias + return
    B_BEGIN list-statements return-statement B_END{
        if(!have_syntax_errors()){
            struct statement * current_stmt = $2;
            while(current_stmt->next)
                current_stmt = current_stmt->next;
            current_stmt->next = $3;

            $$ = create_statement_block_begin($2);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // ===== CORRECTO: Bloque de sentencias + return
    | B_BEGIN return-statement B_END{
        if(!have_syntax_errors()){
            $$ = create_statement_block_begin($2);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Falta return
    | B_BEGIN list-statements B_END{
        mark_error_syntax_statement_non_return_in_block();
        //YYABORT;
    }
    ;

list-statements:
    statement{
        if(!have_syntax_errors()){
            $$ = $1;
        }
        else{
            $$ = 0;
        }
        
    }
    | statement list-statements{
        if(!have_syntax_errors()){
            $$ = $1;
            $1->next = $2;
        }
        else{
            $$ = 0;
        }
    }
    ;

statement:
    assignment-statement{
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
    | procedure-call-statement{
        $$ = $1;
    }
    | fork-statement{
        $$ = $1;
    }
    | join-statement{
        $$ = $1;
    }
    | sleep-statement{
        $$ = $1;
    }
    | print-statement{
        $$ = $1;
    }
    | sem-wait-statement{
        $$ = $1;
    }
    | sem-signal-statement{
        $$ = $1;
    }
    | block-statements-atomic{
        $$ = $1;
    }
    | block-statements-cobegin-coend{
        $$ = $1;
    }
    ;

assignment-statement:
    // ===== CORRECTO: Asignacion a variable
    IDENT OP_ASSIGN expression DELIM_PC{
        // -- Creacion de nodo STATEMENT (ASSIGNMENT)
        if(!have_syntax_errors()){
            $$ = create_statement_assignment($1, 0, $3, yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // ===== CORRECTO: Asignacion a variable indexada
    | IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression DELIM_PC{
        // -- Creacion de nodo STATEMENT (ASSIGNMENT)
        if(!have_syntax_errors()){
            $$ = create_statement_assignment($1, $3, $6, yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Sentencia invalida
    | IDENT CORCH_IZDO expression CORCH_DCHO{
        mark_error_syntax_statement_expected_statement();
        //YYABORT;
    }
    // <--> ERROR: Falta ';'
    | IDENT OP_ASSIGN expression{
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
    // <--> ERROR: Falta ';'
    | IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression{
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
    ;

while-statement:
    // ===== CORRECTO: Bucle while
    WHILE expression DO block-statements-begin-end{
        if(!have_syntax_errors()){
            $$ = create_statement_while($2, $4, yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    ;

for-statement:
    // ===== CORRECTO: Bucle for
    FOR IDENT OP_ASSIGN expression TO expression DO block-statements-begin-end{
        if(!have_syntax_errors()){
            $$ = create_statement_for($2, $4, $6, $8, yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Falta 'for'
    ;

if-statement:
    // ===== CORRECTO: Bloque if
    IF expression THEN block-statements-begin-end{
        if(!have_syntax_errors()){
            $$ = create_statement_if_else($2, $4, 0, yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // ===== CORRECTO: Bloque if-else
    | IF expression THEN block-statements-begin-end ELSE block-statements-begin-end{
        if(!have_syntax_errors()){
            $$ = create_statement_if_else($2, $4, $6, yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    ;

fork-statement:
    // ===== CORRECTO: Fork de proceso
    S_FORK IDENT DELIM_PC{
        if(!have_syntax_errors()){
            $$ = create_statement_fork($2, yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Falta ';'
    | S_FORK IDENT{
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
    ;

join-statement:
    // ===== CORRECTO: Join de proceso
    JOIN DELIM_PC{
        if(!have_syntax_errors()){
            $$ = create_statement_join(yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Falta ';'
    | JOIN{
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
    ;

sleep-statement:
    // ===== CORRECTO: Join de proceso
    SLEEP expression DELIM_PC{
        if(!have_syntax_errors()){
            $$ = create_statement_sleep($2,yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Falta ';'
    | SLEEP expression{
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
    ;

return-statement:
    // ===== CORRECTO: Sentencia de retorno
    RETURN expression DELIM_PC{
        if(!have_syntax_errors()){
            $$ = create_statement_return($2, yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Falta ';'
    | RETURN expression{
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
    ;

print-statement:
    // ===== CORRECTO: Sentencia de impresion
    PRINT PAR_IZDO list-print PAR_DCHO DELIM_PC{
        if(!have_syntax_errors()){
            $$ = create_statement_print($3);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // <--> ERROR: Falta ';'
    | PRINT PAR_IZDO list-print PAR_DCHO{
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
    ;

list-print:
    expression DELIM_C list-print{
        if(!have_syntax_errors()){
            $$ = $1;
            $1->next = $3;
        }
        else{
            $$ = 0;
        }
    }
    | expression{
        if(!have_syntax_errors()){
            $$ = $1;
        }
        else{
            $$ = 0;
        }
    }
    ;

sem-wait-statement:
    SEM_WAIT IDENT DELIM_PC{
        if(!have_syntax_errors()){
            $$ = create_statement_sem_wait($2, yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    ;

sem-signal-statement:
    SEM_SIGNAL IDENT DELIM_PC{
        if(!have_syntax_errors()){
            $$ = create_statement_sem_signal($2, yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    ;

procedure-call-statement:
    // ===== CORRECTO: Invocacion de proceso (Con argumentos)
    IDENT PAR_IZDO list-arguments PAR_DCHO DELIM_PC{
        if(!have_syntax_errors()){
            $$ = create_statement_procedure_inv($1, $3, yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // ===== CORRECTO: Invocacion de proceso (sin argumentos)
    | IDENT PAR_IZDO PAR_DCHO DELIM_PC{
        if(!have_syntax_errors()){
            $$ = create_statement_procedure_inv($1, 0, yylineno);
            add_statement_to_register($$);
        }
        else{
            $$ = 0;
        }
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
    | error {
        mark_error_syntax_expression_expected_expr();
        YYABORT;
    }
    ;

binary-expression:
    // expression + term
    expression OP_SUM expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_ADD, "+", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // expression - term
    | expression OP_MINUS expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_SUB, "-", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // expression * term
    | expression OP_MULT expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_MULT, "*", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // expression / term
    | expression OP_DIV expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_DIV, "/", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // expression % term
    | expression OP_MOD expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_MOD, "%", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // expression < term
    | expression OP_REL_LT expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_LT, "<", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // expression <= term
    | expression OP_REL_LTE expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_LTE, "<=", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // expression > term
    | expression OP_REL_GT expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_GT, ">", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // expression >= term
    | expression OP_REL_GTE expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_GTE, ">=", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // expression == term
    | expression OP_REL_EQ expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_EQ, "==", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // expression != term
    | expression OP_REL_NEQ expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_NEQ, "!=", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
       
    }
    // expression and term
    | expression OP_AND expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_AND, "and", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // expression or term
    | expression OP_OR expression{
        if(!have_syntax_errors()){
            $$ = create_expression_binary_operation(EXPR_OR, "or", $1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    ;
    
unary-expression:
    // not term
    OP_NOT term{
        if(!have_syntax_errors()){
            $$ = create_expression_unary_operation(EXPR_NOT, "not", $2,yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // - term
    | OP_MINUS term %prec OP_MINUS{
        if(!have_syntax_errors()){
            $$ = create_expression_unary_operation(EXPR_NEGATIVE, "-", $2,yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    ;

term:
    expr-identifier{
        $$ = $1;
    }
    | literal{
        $$ = $1;
    }
    | function-call-expression{
        $$ = $1;
    }
    | PAR_IZDO expression PAR_DCHO{
        if(!have_syntax_errors()){
            $$ = create_expression_grouped($2);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    ;
    
// -- Reglas de generacion de literales
literal:
    LITERAL{
        if(!have_syntax_errors()){
            $$ = create_expression_literal_string($1);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    | L_INTEGER{
        if(!have_syntax_errors()){
            $$ = create_expression_literal_integer($1);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    | L_BOOLEAN_TRUE{
        if(!have_syntax_errors()){
            $$ = create_expression_literal_boolean(1);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    | L_BOOLEAN_FALSE{
        if(!have_syntax_errors()){
            $$ = create_expression_literal_boolean(0);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    | L_CHAR{
        if(!have_syntax_errors()){
            $$ = create_expression_literal_char($1);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    | L_REAL{
        if(!have_syntax_errors()){
            $$ = create_expression_literal_real($1);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    ;

expr-identifier:
    IDENT{
        if(!have_syntax_errors()){
            $$ = create_expression_identifier($1,0, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    | IDENT CORCH_IZDO expression CORCH_DCHO{
        if(!have_syntax_errors()){
            $$ = create_expression_identifier($1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    ;

function-call-expression:
    // ===== CORRECTO: Invocacion de funcion (con argumentos)
    IDENT PAR_IZDO list-arguments PAR_DCHO{
        if(!have_syntax_errors()){
            $$ = create_expression_function_invocation($1, $3, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }
    }
    // ===== CORRECTO: Invocacion de funcion (sin argumentos)
    | IDENT PAR_IZDO PAR_DCHO{
        if(!have_syntax_errors()){
            $$ = create_expression_function_invocation($1, 0, yylineno);
            add_expression_to_register($$);
        }
        else{
            $$ = 0;
        }

    }
    ;

// ----/////----------------------------------------------------------
// -- Reglas de generacion de argumentos

list-arguments:
    argument DELIM_C list-arguments{
        if(!have_syntax_errors()){
            $$ = $1;
            $1->next = $3;
        }
        else{
            $$ = 0;
        }
    }
    | argument{
        if(!have_syntax_errors()){
            $$ = $1;
        }
        else{
            $$ = 0;
        }
    }
    ;

argument:
    expression{
        $$ = $1;
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

void mark_error_syntax_declaration_expected_var(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_DECLARATION, id, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_VAR_TOKEN_MSG);
}  

void mark_error_syntax_declaration_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_DECLARATION, "unknown", yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_IDENTIFIER_AFTER_VAR_MSG);
}

void mark_error_syntax_declaration_expected_delim2p(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_DECLARATION, id, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_DELIM2P_TOKEN_MSG);
}

void mark_error_syntax_declaration_expected_opassign(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_DECLARATION, id, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_OPASSIGN_TOKEN_MSG);
}

void mark_error_syntax_declaration_expected_delimpc(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_DECLARATION, id, yylineno-1, ERR_SYNTAX_DECLARATION_EXPECTED_DELIMPC_DECL_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (SUBPROGRAMAS)

void mark_error_syntax_subprogram_expected_procedure(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCEDURE, id, yylineno, ERR_SYNTAX_PROCEDURE_EXPECTED_PROCEDURE_TOKEN_MSG);
}

void mark_error_syntax_subprogram_procedure_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_PROCEDURE, "unknown", yylineno, ERR_SYNTAX_PROCEDURE_EXPECTED_IDENTIFIER_AFTER_PROCEDURE_MSG);
}

void mark_error_syntax_subprogram_procedure_expected_parameters(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCEDURE, id, yylineno, ERR_SYNTAX_PROCEDURE_EXPECTED_PARAMETERS_MSG);
}

void mark_error_syntax_subprogram_procedure_expected_delimpc(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCEDURE, id, yylineno, ERR_SYNTAX_SUBPROGRAM_EXPECTED_DELIMPC_TOKEN_MSG);
}

void mark_error_syntax_subprogram_function_expected_function(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_FUNCTION, id, yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_FUNCTION_TOKEN_MSG);
}

void mark_error_syntax_subprogram_function_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_FUNCTION, "unknown", yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_IDENTIFIER_AFTER_FUNCTION_MSG);
}

void mark_error_syntax_subprogram_function_expected_parameters(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_FUNCTION, id, yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_PARAMETERS_MSG);
}

void mark_error_syntax_subprogram_function_expected_delim2p(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_FUNCTION, id, yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_DELIM2P_TOKEN_MSG);
}

void mark_error_syntax_subprogram_function_expected_delimpc(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_FUNCTION, id, yylineno, ERR_SYNTAX_SUBPROGRAM_EXPECTED_DELIMPC_TOKEN_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (TIPOS)

void mark_error_syntax_type_expected_type(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_TYPE, "unknown", yylineno, ERR_SYNTAX_TYPE_EXPECTED_TYPE_TOKEN_MSG);
}


// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (PARAMETROS)

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (SENTENCIAS)

void mark_error_syntax_statement_expected_statement(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno, ERR_SYNTAX_STATEMENT_EXPECTED_STATEMENT_MSG);
}

void mark_error_syntax_statement_empty_block(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno, ERR_SYNTAX_STATEMENT_EXPECTED_NON_EMPTY_BLOCK_MSG);
}

void mark_error_syntax_statement_non_return_in_block(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno, ERR_SYNTAX_STATEMENT_EXPECTED_RETURN_STATEMENT_MSG);
}

void mark_error_syntax_statement_expected_delimpc(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno-1, ERR_SYNTAX_STATEMENT_EXPECTED_DELIMPC_MSG);
}

void mark_error_syntax_statement_while_expected_while(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno, ERR_SYNTAX_STATEMENT_WHILE_EXPECTED_WHILE_MSG);
}

void mark_error_syntax_statement_while_expected_do(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno, ERR_SYNTAX_STATEMENT_WHILE_EXPECTED_DO_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (EXPRESIONES)

void mark_error_syntax_expression_expected_expr(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_EXPRESSION, "unknown", yylineno, ERR_SYNTAX_EXPRESSION_EXPECTED_EXPRESSION_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (PROCESOS)

void mark_error_syntax_process_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_PROCESS, "unknown", yylineno, ERR_SYNTAX_PROCESS_EXPECTED_IDENTIFIER_AFTER_PROCESS_MSG);
}

void mark_error_syntax_process_expected_delimpc(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCESS, id, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_DELIMPC_MSG);
}

void mark_error_syntax_process_expected_index_identifier(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCESS, id, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_IDENTIFIER_INDEXER_MSG);
}

void mark_error_syntax_process_expected_delim2p(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCESS, id, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_DELIM2P_MSG);
}

void mark_error_syntax_process_expected_delimarr(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCESS, id, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_DELIMARR_MSG);
}

// ----/////----------------------------------------------------------
// FUNCIONES DE MANEJO DE ERRORES (PROGRAMAS)

void mark_error_syntax_program_expected_program(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROGRAM, id, yylineno, ERR_SYNTAX_PROGRAM_EXPECTED_PROGRAM_TOKEN_MSG);
}

void mark_error_syntax_program_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_PROGRAM, "unknown", yylineno, ERR_SYNTAX_PROGRAM_EXPECTED_IDENTIFIER_AFTER_PROGRAM_MSG);
}

void mark_error_syntax_program_unexpected_literal_in_header(){
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_PROGRAM, "unknown", yylineno-1, ERR_PROGRAM_UNEXPECTED_TOKEN_IN_HEADER);
}

void mark_error_syntax_program_unexpected_literal_in_decl(char * id){
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_DECLARATION, id, yylineno-1, ERR_PROGRAM_UNEXPECTED_TOKEN_IN_DECL);
}

void mark_error_syntax_program_unexpected_literal(){
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno-1, ERR_PROGRAM_UNEXPECTED_TOKEN);
}

void mark_error_syntax_program_unexpected_literal_in_proc(char *id){
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_PROCESS, id, yylineno-1, ERR_PROGRAM_UNEXPECTED_TOKEN_IN_PROC);
}