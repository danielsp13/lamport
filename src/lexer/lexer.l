/* ============================================================== */
/* LAMPORT : SIMULADOR DE SISTEMAS CONCURRENTES Y DISTRIBUIDOS */
/*  -- Fichero : lexer.l */
/*  -- Autor: Daniel Perez Ruiz */
/*  -- Descripcion: Definicion del analizador lexico (flex) */
/* ============================================================== */

/* DECLARACIONES */

%{
    //Inclusion de los tipos de Token
    #include "lexer/token.h"

    // -- Inclusion de funcion de insercion de cadena a registro de cadenas
    extern int add_string_to_register(char *str);
    // -- Inclusion de funcion de obtencion de registro de cadenas
    extern char * get_last_str_reg();
%}

/* Habilitar seguimiento de errores en la linea especifica del programa */
%option yylineno

/* Definiciones regulares */
delim       [ \t\r\n]
nl          \n
ws          {delim}+
letra       [A-Za-z]
digito      [0-9]
id          {letra}({letra}|{digito})*
literal     \"[^"]*\"
entero      {digito}+
real        {digito}+\.{digito}+
caracter    \'.\'
comentario  "{"[^}]*"}"

%%

"program"       {return(S_PROGRAM);}
"var"           {return(S_VAR);}
"integer"       {return(T_INTEGER);}
"boolean"       {return(T_BOOLEAN);}
"char"          {return(T_CHAR);}
"string"        {return(T_STRING);}
"real"          {return(T_REAL);}
"semaphore"     {return(T_SEMAPHORE);}
"dprocess"      {return(T_DPROCESS);}
"array"         {return(T_ARRAY);}
"process"       {return(S_PROCESS);}
"procedure"     {return(S_PROCEDURE);}
"function"      {return(S_FUNCTION);}
"return"        {return(RETURN);}
"begin"         {return(B_BEGIN);}
"end"           {return(B_END);}
"cobegin"       {return(B_COBEGIN);}
"coend"         {return(B_COEND);}
"fork"          {return(S_FORK);}
"join"          {return(JOIN);}
"sleep"         {return(SLEEP);}
"print"         {return(PRINT);}
"if"            {return(IF);}
"then"          {return(THEN);}
"else"          {return(ELSE);}
"while"         {return(WHILE);}
"do"            {return(DO);}
"for"           {return(FOR);}
"to"            {return(TO);}
"true"          {return(L_BOOLEAN_TRUE);}
"false"         {return(L_BOOLEAN_FALSE);}
":="            {return(OP_ASSIGN);}
"<"             {return(OP_REL_LT);}
"<="            {return(OP_REL_LTE);}
">"             {return(OP_REL_GT);}
">="            {return(OP_REL_GTE);}
"=="            {return(OP_REL_EQ);}
"!="            {return(OP_REL_NEQ);}
"+"             {return(OP_SUM);}
"-"             {return(OP_MINUS);}
"*"             {return(OP_MULT);}
"/"             {return(OP_DIV);}
"%"             {return(OP_MOD);}
"not"           {return(OP_NOT);}
"and"           {return(OP_AND);}
"or"            {return(OP_OR);}
"("             {return(PAR_IZDO);}
")"             {return(PAR_DCHO);}
"["             {return(CORCH_IZDO);}
"]"             {return(CORCH_DCHO);}
","             {return(DELIM_C);}
";"             {return(DELIM_PC);}
":"             {return(DELIM_2P);}
".."            {return(DELIM_ARR);}
"."             {return(DELIM_P);}
"<<"            {return(ATOM_INI);}
">>"            {return(ATOM_FIN);}
"WAIT"          {return(SEM_WAIT);}
"SIGNAL"        {return(SEM_SIGNAL);}
{id}            {
    // -- Incluir cadena al registro de cadenas
    if(add_string_to_register(strdup(yytext)))
        yylval.ident = get_last_str_reg();
    return(IDENT);
    }
{literal}       {
    if(add_string_to_register(strdup(yytext)))
        yylval.literal_string = get_last_str_reg();
    return(LITERAL);
    }
{entero}        {
    yylval.literal_int = atoi(yytext); 
    return(L_INTEGER);
    }
{real}          {
    yylval.literal_float = atof(yytext); 
    return(L_REAL);
    }
{caracter}      {
    yylval.literal_char = yytext[1]; 
    return(L_CHAR);
    }
{comentario}    { /*IGNORAR*/ }
{ws}            { /*IGNORAR*/ }
.               {
    /*Regla para patrones no reconocidos */
    return(UNRECOGNIZED_TOKEN);
}

%%

/* FUNCIONES AUXILIARES */
