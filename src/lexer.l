/* ============================================================== */
/* LAMPORT : SIMULADOR DE SISTEMAS CONCURRENTES Y DISTRIBUIDOS */
/*  -- Fichero : lexer.l */
/*  -- Autor: Daniel Perez Ruiz */
/*  -- Descripcion: Definicion del analizador lexico (flex) */
/* ============================================================== */

/* DECLARACIONES */

%{
    //Inclusion de los tipos de Token
    #include "token_type.h"
%}

/* Definiciones regulares */
delim       [ \t\n]
ws          {delim}+
letra       [A-Za-z]
digito      [0-9]
id          {letra}({letra}|{digito})*
literal     ^".*?"$
entero      ^-?{digito}+$
real        ^-?{digito}+(.{digito}+)$
caracter    ^'.'$
comentario  \{[^\}]*\}

%%

{ws}            {/*no se produce retorno*/}
{comentario}    {/*ignorar comentarios*/}
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
"if"            {return(IF);}
"then"          {return(THEN);}
"else"          {return(ELSE);}
"while"         {return(WHILE);}
"do"            {return(DO);}
"for"           {return(FOR);}
"to"            {return(TO);}
"true"          {return(L_BOOLEAN);}
"false"         {return(L_BOOLEAN);}
":="            {return(OP_ASSIGN);}
"<"             {return(OP_REL);}
"<="            {return(OP_REL);}
">"             {return(OP_REL);}
">="            {return(OP_REL);}
"=="            {return(OP_REL);}
"!="            {return(OP_REL);}
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
"<<"            {return(ATOM_INI);}
">>"            {return(ATOM_FIN);}
{id}            {return(IDENT);}
{literal}       {return(LITERAL);}
{entero}        {return(L_INTEGER);}
{real}          {return(L_REAL);}
{caracter}      {return(L_CHAR);}

%%

/* FUNCIONES AUXILIARES */