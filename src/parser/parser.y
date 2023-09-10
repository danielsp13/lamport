/* ============================================================== */
/* LAMPORT : SIMULADOR DE SISTEMAS CONCURRENTES Y DISTRIBUIDOS */
/*  -- Fichero : parser.y */
/*  -- Autor: Daniel Perez Ruiz */
/*  -- Descripcion: Definicion del analizador sintactico (bison) */
/* ============================================================== */

/* DECLARACIONES */

%{
    //Inclusion de cabeceras
    #include <stdio.h>

    //Inclusion de AST
    #include "AST/AST.h"

    //Inclusion de mensajes de errores de parser
    #include "parser/parser_errors.h"

    //Definir prototipos de funciones
    extern int yylex();
    extern FILE *yyin;
    extern int yylineno;

    void yyerror(const char* s);  
%}

/* Definiciones de tokens */

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
%token UNRECOGNIZED_TOKEN 319

/* Indicar a bison donde encontrar la cabecera de tokens */
%define api.header.include { "lexer/token.h" }


%left OP_OR
%left OP_AND
%left OP_REL_EQ OP_REL_NEQ
%left OP_REL_LT OP_REL_LTE OP_REL_GT OP_REL_GTE
%left OP_SUM OP_MINUS
%left OP_MULT OP_DIV OP_MOD
%right OP_NOT

/* Informacion para construccion de AST */
%union {
    struct program *prog;
    struct declaration *decl;
    struct subprogram *subprog;
    struct process *proc;
    struct statement *stmt;
    struct expression *expr;
    struct type *type;
    struct parameter_list *param;
    char *ident;
    char *literal_string;
    char literal_char;
    int literal_int;
    float literal_float;
    int literal_boolean;
};

// Especificacion de tipos de valor semantico

// ---- TIPO program
%type <prog> program

// ---- TIPO declaracion
%type <decl> list-declarations declaration 
%type <decl> declaration-var-with-assignment declaration-var

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
%type <expr> literal identifier
%type <expr> list-arguments argument
%type <expr> list-print

// ---- TIPO parameter_list
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
%type <ident> program-name declaration-name subprogram-procedure-name subprogram-function-name parameter-name process-name

// ---- TIPO LITERALS
%type <literal_string> LITERAL
%type <literal_char> L_CHAR
%type <literal_int> L_INTEGER
%type <literal_float> L_REAL
%type <literal_boolean> L_BOOLEAN_TRUE L_BOOLEAN_FALSE

%%

// Reglas de traduccion

// -- Regla de generacion de programa completo
program:
    S_PROGRAM program-name list-declarations list-subprograms list-process{
        AST_program = create_program($2,$3,$4,$5);
    }
    | error{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROGRAM_PROGRAM);

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
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROGRAM_IDENT);

        // -- Abortar inmediatamente el analisis
        YYABORT; 
    }
    ;

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
    S_VAR declaration-var-with-assignment{
        $$ = $2;
    }
    | S_VAR declaration-var{
        $$ = $2;
    }
    // <--> ERROR: Falta palabra var
    | error{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARARTION_VAR);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
    ;

declaration-var-with-assignment:
    declaration-name DELIM_2P type OP_ASSIGN expression DELIM_PC{
        $$ = create_declaration_variable($1, $3, $5, yylineno);
    }
    // <--> ERROR: Falta ':' en la declaracion
    | declaration-name error type OP_ASSIGN expression DELIM_PC{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_DELIM2P);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
    // <--> ERROR: Falta ';' en la declaracion
    | declaration-name DELIM_2P type OP_ASSIGN expression error{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_DELIMPC);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
    ;

declaration-var:
    declaration-name DELIM_2P type DELIM_PC{
        $$ = create_declaration_variable($1, $3, 0, yylineno);
    }
    // <--> ERROR: Falta ':' en la declaracion
    | declaration-name error type DELIM_PC{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_DELIM2P);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
    // <--> ERROR: Falta ';' en la declaracion
    | declaration-name DELIM_2P type error{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_DELIMPC);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
    ;

declaration-name:
    IDENT{
        $$ = $1;
    }
    // <--> ERROR : Nombre de variable incorrecto
    | error{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

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
    // -- Generacion de subprogramas de tipo procedimiento (Con parametros)
    S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO list-declarations block-statement{
        $$ = create_subprogram_procedure($2, $4, $6, $7, yylineno);
    }
    // -- Generacion de subprogramas de tipo procedimiento (sin parametros)
    | S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO list-declarations block-statement{
        $$ = create_subprogram_procedure($2, 0, $5, $6, yylineno);
    }
    // <--> ERROR: Procedimiento mal formado
    | S_PROCEDURE error{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_PROCEDURE_MALFORMED);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

subprogram-procedure-name:
    IDENT{
        $$ = $1;
    }
    // <--> ERROR : Nombre de variable incorrecto
    | error{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_PROCEDURE_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

subprogram-function:
    // -- Generacion de subprogramas de tipo funcion (con parametros)
    S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P type DELIM_PC list-declarations block-statement{
        $$ = create_subprogram_function($2, $4, $9, $10, $7, yylineno);
    }
    // -- Generacion de subprogramas de tipo funcion (sin parametros)
    | S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P type DELIM_PC list-declarations block-statement{
        $$ = create_subprogram_function($2, 0, $8, $9, $6, yylineno);
    }
    // <--> ERROR: Funcion mal formado
    | S_FUNCTION error{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_FUNCTION_MALFORMED);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

subprogram-function-name:
    IDENT{
        $$ = $1;
    }
    // <--> ERROR : Nombre de variable incorrecto
    | error{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_FUNCTION_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

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
    parameter-name DELIM_2P type{
        $$ = create_parameter_list($1, $3, yylineno);
    }
    // <--> ERROR : Nombre de parametro incorrecto
    | parameter-name error type{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_PARAMETER_DELIM2P);

        // -- Abortar inmediatmente el analisis
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
        yyerror(PARSER_ERROR_MSG_PROC_PARAMETER_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

// -- Reglas de generacion de procesos del programa
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
    // process proc_name ....
    S_PROCESS process-name DELIM_PC list-declarations block-statement{
        $$ = create_process_single($2, $4, $5, yylineno);
    }
    // <--> ERROR : Falta ';'
    | S_PROCESS process-name error list-declarations block-statement{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROCESS_DELIMPC);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

process-def-array:
    // process proc_array_name[expr..expr] (?) ...
    S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC list-declarations block-statement{
        $$ = create_process_vector($2, $11, $12, $4, $6, $8, yylineno);
    }
    ;

process-name:
    IDENT{
        $$ = $1;
    }
    // <--> ERROR : Nombre de variable incorrecto
    | error{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROCESS_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;


// -- Reglas de generacion de tipos de dato
type:
    T_INTEGER{
        $$ = create_basic_type(TYPE_INTEGER);
    }
    | T_BOOLEAN{
        $$ = create_basic_type(TYPE_BOOLEAN);
    }
    | T_CHAR{
        $$ = create_basic_type(TYPE_CHAR);
    }
    | T_STRING{
        $$ = create_basic_type(TYPE_STRING);
    }
    | T_REAL{
        $$ = create_basic_type(TYPE_REAL);
    }
    | T_ARRAY CORCH_IZDO expression CORCH_DCHO type{
        $$ = create_array_type($5,$3);
    }
    | T_SEMAPHORE{
        $$ = create_semaphore_type();
    }
    | T_DPROCESS{
        $$ = create_dprocess_type();
    }
    // <--> ERROR : Tipo de dato no reconocido
    | error{
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_TYPE);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

// -- Reglas de generacion de sentencias
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
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_STMT_MALFORMED);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

block-statement:
    B_BEGIN list-statements B_END{
        $$ = create_statement_block_begin($2);
    }
    ;

cobegin-statement:
    B_COBEGIN list-statements B_COEND{
        $$ = create_statement_block_cobegin($2);
    }
    ;

assignment-statement:
    // var_name = expr;
    IDENT OP_ASSIGN expression DELIM_PC{
        $$ = create_statement_assignment($1, 0, $3, yylineno);
    }
    // var_array_name[index] = expr;
    | IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression DELIM_PC{
        $$ = create_statement_assignment($1, $3, $6, yylineno);
    }
    ;

while-statement:
    WHILE expression DO block-statement{
        $$ = create_statement_while($2, $4);
    }
    ;

for-statement:
    FOR IDENT OP_ASSIGN expression TO expression DO block-statement{
        $$ = create_statement_for($2, $4, $6, $8, yylineno);
    }
    ;

if-statement:
    IF expression THEN block-statement{
        $$ = create_statement_if_else($2, $4, 0);
    }
    | IF expression THEN block-statement ELSE block-statement{
        $$ = create_statement_if_else($2, $4, $6);
    }
    ;

fork-statement:
    S_FORK IDENT DELIM_PC{
        $$ = create_statement_fork($2, yylineno);
    }
    ;

atomic-statement:
    ATOM_INI list-statements ATOM_FIN{
        $$ = create_statement_atomic($2);
    }
    ;

return-statement:
    RETURN expression DELIM_PC{
        $$ = create_statement_return($2);
    }
    ;

print-statement:
    PRINT PAR_IZDO list-print PAR_DCHO DELIM_PC{
        $$ = create_statement_print($3);
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

// -- Reglas de generacion de invocaciones de funciones y procedimientos
procedure-invocation:
    IDENT PAR_IZDO list-arguments PAR_DCHO DELIM_PC{
        $$ = create_statement_procedure_inv($1, $3, yylineno);
    }
    | IDENT PAR_IZDO PAR_DCHO DELIM_PC{
        $$ = create_statement_procedure_inv($1, 0, yylineno);
    }
    ;

function-invocation:
    IDENT PAR_IZDO list-arguments PAR_DCHO{
        $$ = create_expression_function_invocation($1, $3, yylineno);
    }
    | IDENT PAR_IZDO PAR_DCHO{
        $$ = create_expression_function_invocation($1, 0, yylineno);
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
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_EXPR_MALFORMED);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
    ;

binary-expression:
    // term + expression
    term OP_SUM expression{
        $$ = create_expression_binary_operation(EXPR_ADD, "+", $1, $3);
    }
    // term - expression
    | term OP_MINUS expression{
        $$ = create_expression_binary_operation(EXPR_SUB, "-", $1, $3);
    }
    // term * expression
    | term OP_MULT expression{
        $$ = create_expression_binary_operation(EXPR_MULT, "*", $1, $3);
    }
    // term / expression
    | term OP_DIV expression{
        $$ = create_expression_binary_operation(EXPR_DIV, "/", $1, $3);
    }
    // term % expression
    | term OP_MOD expression{
        $$ = create_expression_binary_operation(EXPR_MOD, "%", $1, $3);
    }
    // term < expression
    | term OP_REL_LT expression{
        $$ = create_expression_binary_operation(EXPR_LT, "<", $1, $3);
    }
    // term <= expression
    | term OP_REL_LTE expression{
        $$ = create_expression_binary_operation(EXPR_LTE, "<=", $1, $3);
    }
    // term > expression
    | term OP_REL_GT expression{
        $$ = create_expression_binary_operation(EXPR_GT, ">", $1, $3);
    }
    // term >= expression
    | term OP_REL_GTE expression{
        $$ = create_expression_binary_operation(EXPR_GTE, ">=", $1, $3);
    }
    // term == expression
    | term OP_REL_EQ expression{
        $$ = create_expression_binary_operation(EXPR_EQ, "==", $1, $3);
    }
    // term != expression
    | term OP_REL_NEQ expression{
        $$ = create_expression_binary_operation(EXPR_NEQ, "!=", $1, $3);
    }
    // term and expression
    | term OP_AND expression{
        $$ = create_expression_binary_operation(EXPR_AND, "and", $1, $3);
    }
    // term or expression
    | term OP_OR expression{
        $$ = create_expression_binary_operation(EXPR_OR, "or", $1, $3);
    }
    ;
    
unary-expression:
    // not term
    OP_NOT term{
        $$ = create_expression_unary_operation(EXPR_NOT, "not", $2);
    }
    // - term
    | OP_MINUS term{
        $$ = create_expression_unary_operation(EXPR_NEGATIVE, "-", $2);
    }
    ;

term:
    identifier{
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
    }
    ;
    
// -- Reglas de generacion de literales
literal:
    LITERAL{
        $$ = create_expression_literal_string($1);
    }
    | L_INTEGER{
        $$ = create_expression_literal_integer($1);
    }
    | L_BOOLEAN_TRUE{
        $$ = create_expression_literal_boolean(1);
    }
    | L_BOOLEAN_FALSE{
        $$ = create_expression_literal_boolean(0);
    }
    | L_CHAR{
        $$ = create_expression_literal_char($1);
    }
    | L_REAL{
        $$ = create_expression_literal_real($1);
    }
    ;

identifier:
    IDENT{
        $$ = create_expression_identifier($1,0, yylineno);
    }
    | IDENT CORCH_IZDO expression CORCH_DCHO{
        $$ = create_expression_identifier($1, $3, yylineno);
    }
    ;

%%

// Soporte de las rutinas en C


void yyerror(const char *s) {
    if(strcmp(s, "syntax error") != 0)
        fprintf(stderr, "--- Error de sintaxis en la línea %d -> %s\n", yylineno, s);
}