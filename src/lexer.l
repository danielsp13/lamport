/* ============================================================== */
/* LAMPORT : SIMULADOR DE SISTEMAS CONCURRENTES Y DISTRIBUIDOS */
/*  -- Fichero : lexer.l */
/*  -- Autor: Daniel Perez Ruiz */
/*  -- Descripcion: Definicion del analizador lexico (flex) */
/* ============================================================== */

/* DECLARACIONES */

%{
    //Inclusion de los tipos de Token
    #include "token.h"

    //Inclusion de registro de cadenas de caracteres
    #include "string_register.h"
%}

/* Habilitar seguimiento de errores en la linea especifica del programa */
%option yylineno

/* Definiciones regulares */
delim       [ \t\r\n]
ws          {delim}+
letra       [A-Za-z]
digito      [0-9]
id          {letra}({letra}|{digito})*
literal     \"[^"]*\"
entero      -?{digito}+
real        -?{digito}+\.{digito}+
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
{id}            {
    #ifndef LEXER_TEST 
        // -- Incluir cadena al registro de cadenas
        if(add_string_to_register(strdup(yytext)) == STRING_REGISTER_SUCCESS)
            yylval.ident = last_string_register->str;
        
    #endif
    return(IDENT);
    }
{literal}       {
    #ifndef LEXER_TEST
        // -- Incluir cadena al registro de cadenas
        if(add_string_to_register(strdup(yytext)) == STRING_REGISTER_SUCCESS)
            yylval.literal_string = last_string_register->str;
            
    #endif
    return(LITERAL);
    }
{entero}        {
    #ifndef LEXER_TEST
        yylval.literal_int = atoi(yytext); 
    #endif 
    return(L_INTEGER);
    }
{real}          {
    #ifndef LEXER_TEST
        yylval.literal_float = atof(yytext); 
    #endif
    return(L_REAL);
    }
{caracter}      {
    #ifndef LEXER_TEST
        yylval.literal_char = yytext[1]; 
    #endif
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
