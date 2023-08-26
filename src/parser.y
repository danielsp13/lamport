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

    //Definir directiva para testeo
    #define VERBOSE

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
%token UNRECOGNIZED_TOKEN 318

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

%type <prog> program
%type <decl> list-declarations declaration
%type <subprog> list-subprograms subprogram
%type <proc> list-process process
%type <type> type
%type <expr> expression binary-expression unary-expression
%type <expr> term function-invocation literal identifier
%type <param> list-parameters parameter
%type <stmt> statement list-statements
%type <stmt> block-statement cobegin-statement assignment-statement while-statement for-statement if-statement procedure-invocation fork-statement atomic-statement return-statement
%type <ident> IDENT
%type <literal_string> LITERAL
%type <literal_char> L_CHAR
%type <literal_int> L_INTEGER
%type <literal_float> L_REAL
%type <literal_boolean> L_BOOLEAN_TRUE L_BOOLEAN_FALSE

%%

// Reglas de traduccion

// -- Regla de generacion de programa completo
program:
    S_PROGRAM IDENT list-declarations list-subprograms list-process{
        AST_program = create_program($2,$3,$4,$5);

        // -- Liberar memoria dinamica usada
        free($2);
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
    S_VAR IDENT DELIM_2P type OP_ASSIGN expression DELIM_PC{
        $$ = create_declaration_variable($2, $4, $6);

        // -- Liberar memoria dinamica usada
        free($2);
    }
    | S_VAR IDENT DELIM_2P type DELIM_PC{
        $$ = create_declaration_variable($2, $4, 0);

        // -- Liberar memoria dinamica usada
        free($2);
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
    // -- Generacion de subprogramas de tipo procedimiento
    S_PROCEDURE IDENT PAR_IZDO list-parameters PAR_DCHO list-declarations block-statement{
        $$ = create_subprogram_procedure($2, $4, $6, $7);

        // -- Liberar memoria dinamica usada
        free($2);
    }
    // -- Generacion de subprogramas de tipo funcion
    | S_FUNCTION IDENT PAR_IZDO list-parameters PAR_DCHO DELIM_2P type DELIM_PC list-declarations block-statement{
        $$ = create_subprogram_function($2, $4, $9, $10, $7);

        // -- Liberar memoria dinamica usada
        free($2);
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
    | /* epsilon */{
        $$ = 0;
    }
    ;

parameter:
    IDENT DELIM_2P type{
        $$ = create_parameter_list($1, $3);

        // -- Liberar memoria dinamica usada
        free($1);
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
    // process proc_name ....
    S_PROCESS IDENT DELIM_PC list-declarations block-statement{
        $$ = create_process($2, $4, $5);

        // -- Liberar memoria dinamica usada
        free($2);
    }
    // process proc_array_name[expr..expr] (?) ...
    //| S_PROCESS identifier CORCH_IZDO identifier DELIM_2P L_INTEGER DELIM_ARR L_INTEGER CORCH_DCHO DELIM_PC list-declarations block-statement
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
        $$ = create_array_type($5);
    }
    | T_SEMAPHORE{
        $$ = create_semaphore_type();
    }
    | T_DPROCESS{
        $$ = create_dprocess_type();
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
        $$ = create_statement_assignment($1, $3);

        // -- Liberar memoria dinamica usada
        free($1);
    }
    // var_array_name[index] = expr;
    //| identifier CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression DELIM_PC
    ;

while-statement:
    WHILE expression DO block-statement{
        $$ = create_statement_while($2, $4);
    }
    ;

for-statement:
    FOR expression OP_ASSIGN expression TO expression DO block-statement{
        $$ = create_statement_for($2, $4, $6, $8);
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
    S_FORK IDENT statement{
        $$ = create_statement_fork($2, $3);

        // -- Liberar memoria dinamica usada
        free($2);
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

// -- Reglas de generacion de invocaciones de funciones y procedimientos
procedure-invocation:
    IDENT PAR_IZDO list-parameters PAR_DCHO DELIM_PC{
        $$ = create_statement_procedure_inv($1, $3);

        // -- Liberar memoria dinamica usada
        free($1);
    }
    ;

function-invocation:
    IDENT PAR_IZDO list-parameters PAR_DCHO{
        $$ = create_expression_function_invocation($1, $3);

        // -- Liberar memoria dinamica usada
        free($1);
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

        free(yylval.literal_string);
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
        $$ = create_expression_identifier($1);

        free(yylval.ident);
    }
    ;

%%

// Soporte de las rutinas en C


void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis en la línea %d: %s\n", yylineno, s);
}