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

    //Definir directiva para testeo
    #define VERBOSE

    //Definir prototipos de funciones
    extern int yylex();  
    extern FILE *yyin;

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

%%

// Reglas de traduccion

// -- Regla de generacion de programa completo
program:
    S_PROGRAM identifier opt-declarations opt-subprograms program-process
    ;

// -- Reglas de generacion de declaraciones del programa
opt-declarations:
    declarations
    | /* epsilon */
    ;

declarations:
    S_VAR list-variable-declarations
    ;

list-variable-declarations:
    variable-declaration
    | list-variable-declarations variable-declaration
    ;

variable-declaration:
    identifier DELIM_2P type variable-assignation DELIM_PC
    ;

variable-assignation:
    OP_ASSIGN expression
    | /* epsilon */
    ;

// -- Reglas de generacion de subprogramas del programa
opt-subprograms:
    list-subprograms
    | /* epsilon */
    ;

list-subprograms:
    subprogram
    | list-subprograms subprogram
    ;

subprogram:
    procedure-definition
    | function-definition
    ;

// -- Reglas de generacion de procesos del programa
program-process:
    process
    | program-process process
    ;

process:
    S_PROCESS identifier array-of-process DELIM_PC opt-declarations block-statement
    ;

array-of-process:
    CORCH_IZDO identifier DELIM_2P L_INTEGER DELIM_ARR L_INTEGER CORCH_DCHO
    | /* epsilon */
    ;

// -- Reglas de generacion de tipos de dato
type:
    T_INTEGER
    | T_BOOLEAN
    | T_CHAR
    | T_STRING
    | T_REAL
    | T_ARRAY CORCH_IZDO expression CORCH_DCHO type
    | T_SEMAPHORE
    | T_DPROCESS
    ;

// -- Reglas de generacion de definicion de funciones y procedimientos
procedure-definition:
    S_PROCEDURE identifier PAR_IZDO opt-parameters PAR_DCHO opt-declarations block-statement
    ;

function-definition:
    S_FUNCTION identifier PAR_IZDO opt-parameters PAR_DCHO DELIM_2P type DELIM_PC opt-declarations block-statement
    ;

opt-parameters:
    list-parameters
    | /* epsilon */
    ;

list-parameters:
    parameter
    | list-parameters DELIM_C parameter
    ;

parameter:
    identifier DELIM_2P type
    ;

// -- Reglas de generacion de sentencias
list-statements:
    statement
    | list-statements statement
    ;

statement:
    block-statement
    | cobegin-statement
    | assignment-statement
    | while-statement
    | for-statement
    | if-statement
    | procedure-invocation
    | fork-statement
    | atomic-statement
    | return-statement
    ;

block-statement:
    B_BEGIN list-statements B_END
    ;

cobegin-statement:
    B_COBEGIN list-statements B_COEND
    ;

assignment-statement:
    identifier array-assignment-statement OP_ASSIGN expression DELIM_PC
    ;

array-assignment-statement:
    CORCH_IZDO expression CORCH_DCHO
    | /* epsilon */
    ;

while-statement:
    WHILE expression DO block-statement
    ;

for-statement:
    FOR identifier OP_ASSIGN expression TO expression DO block-statement
    ;

if-statement:
    IF expression THEN block-statement
    | IF expression THEN block-statement ELSE block-statement
    ;

fork-statement:
    S_FORK identifier statement
    ;

atomic-statement:
    ATOM_INI list-statements ATOM_FIN
    ;

return-statement:
    RETURN expression DELIM_PC
    ;

// -- Reglas de generacion de invocaciones de funciones y procedimientos
procedure-invocation:
    identifier PAR_IZDO opt-parameters PAR_DCHO DELIM_PC
    ;

function-invocation:
    identifier PAR_IZDO opt-parameters PAR_DCHO
    ;

// -- Reglas de generacion de expresiones
expression:
    term binary-operator expression
    | unary-operator term
    ;

term:
    identifier
    | literal
    | function-invocation
    | PAR_IZDO expression PAR_DCHO
    ;
    
// -- Reglas de generacion de literales
literal:
    LITERAL
    | L_INTEGER
    | L_BOOLEAN_TRUE
    | L_BOOLEAN_FALSE
    | L_CHAR
    | L_REAL
    ;

identifier:
    IDENT
    ;

// -- Reglas de generacion de operadores binarios y unarios
binary-operator:
    OP_MULT
    | OP_DIV
    | OP_SUM
    | OP_MINUS
    | OP_MOD
    | OP_REL_GT
    | OP_REL_LT
    | OP_REL_GTE
    | OP_REL_LTE
    | OP_REL_EQ
    | OP_REL_NEQ
    | OP_AND
    | OP_OR
    ;

unary-operator:
    OP_MINUS
    | OP_NOT
    ;

%%

// Soporte de las rutinas en C


void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}