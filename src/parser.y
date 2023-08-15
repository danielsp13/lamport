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

%token S_PROGRAM
%token S_VAR
%token T_INTEGER
%token T_BOOLEAN
%token T_CHAR
%token T_STRING
%token T_REAL
%token T_ARRAY
%token T_SEMAPHORE
%token T_DPROCESS
%token S_PROCESS
%token S_PROCEDURE
%token S_FUNCTION
%token RETURN
%token B_BEGIN
%token B_END
%token B_COBEGIN
%token B_COEND
%token S_FORK
%token JOIN
%token IF
%token THEN
%token ELSE
%token WHILE
%token DO
%token FOR
%token TO
%token IDENT
%token LITERAL
%token L_INTEGER
%token L_REAL
%token L_BOOLEAN_TRUE
%token L_BOOLEAN_FALSE
%token L_CHAR
%token OP_ASSIGN
%token OP_REL_LT
%token OP_REL_GT
%token OP_REL_LTE
%token OP_REL_GTE
%token OP_REL_EQ
%token OP_REL_NEQ
%token OP_SUM
%token OP_MINUS
%token OP_MULT
%token OP_DIV
%token OP_MOD
%token OP_NOT
%token OP_AND
%token OP_OR
%token PAR_IZDO
%token PAR_DCHO
%token CORCH_IZDO
%token CORCH_DCHO
%token DELIM_C
%token DELIM_PC
%token DELIM_2P
%token DELIM_ARR
%token DELIM_P
%token ATOM_INI
%token ATOM_FIN
%token UNRECOGNIZED_TOKEN
%token UNARY_MINUS

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