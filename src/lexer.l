/* ============================================================== */
/* LAMPORT : SIMULADOR DE SISTEMAS CONCURRENTES Y DISTRIBUIDOS */
/*  -- Fichero : lexer.l */
/*  -- Autor: Daniel Perez Ruiz */
/*  -- Descripcion: Definicion del analizador lexico (flex) */
/* ============================================================== */

/* DECLARACIONES */

%{
    //Inclusion de los tipos de Token
    #include "parser.tab.h"

    //Definir macro para impresion de contenido en modo debug
    //#define LMP_VERBOSE

    // Definir funcion para devolver tokens
    void print_token(char* t_str);
%}

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

"program"       {print_token("S_PROGRAM"); return(S_PROGRAM);}
"var"           {print_token("S_VAR"); return(S_VAR);}
"integer"       {print_token("T_INTEGER"); return(T_INTEGER);}
"boolean"       {print_token("T_BOOLEAN"); return(T_BOOLEAN);}
"char"          {print_token("T_CHAR"); return(T_CHAR);}
"string"        {print_token("T_STRING"); return(T_STRING);}
"real"          {print_token("T_REAL"); return(T_REAL);}
"semaphore"     {print_token("T_SEMAPHORE"); return(T_SEMAPHORE);}
"dprocess"      {print_token("T_DPROCESS"); return(T_DPROCESS);}
"process"       {print_token("S_PROCESS"); return(S_PROCESS);}
"procedure"     {print_token("S_PROCEDURE"); return(S_PROCEDURE);}
"function"      {print_token("S_FUNCTION"); return(S_FUNCTION);}
"return"        {print_token("RETURN"); return(RETURN);}
"begin"         {print_token("B_BEGIN"); return(B_BEGIN);}
"end"           {print_token("B_END"); return(B_END);}
"cobegin"       {print_token("B_COBEGIN"); return(B_COBEGIN);}
"coend"         {print_token("B_COEND"); return(B_COEND);}
"fork"          {print_token("S_FORK"); return(S_FORK);}
"join"          {print_token("JOIN"); return(JOIN);}
"if"            {print_token("IF"); return(IF);}
"then"          {print_token("THEN"); return(THEN);}
"else"          {print_token("ELSE"); return(ELSE);}
"while"         {print_token("WHILE"); return(WHILE);}
"do"            {print_token("DO"); return(DO);}
"for"           {print_token("FOR"); return(FOR);}
"to"            {print_token("TO"); return(TO);}
"true"          {print_token("L_BOOLEAN_TRUE"); return(L_BOOLEAN_TRUE);}
"false"         {print_token("L_BOOLEAN_FALSE"); return(L_BOOLEAN_FALSE);}
":="            {print_token("OP_ASSIGN"); return(OP_ASSIGN);}
"<"             {print_token("OP_REL_LT"); return(OP_REL_LT);}
"<="            {print_token("OP_REL_LTE"); return(OP_REL_LTE);}
">"             {print_token("OP_REL_GT"); return(OP_REL_GT);}
">="            {print_token("OP_REL_GTE"); return(OP_REL_GTE);}
"=="            {print_token("OP_REL_EQ"); return(OP_REL_EQ);}
"!="            {print_token("OP_REL_NEQ"); return(OP_REL_NEQ);}
"+"             {print_token("OP_SUM"); return(OP_SUM);}
"-"             {print_token("OP_MINUS"); return(OP_MINUS);}
"*"             {print_token("OP_MULT"); return(OP_MULT);}
"/"             {print_token("OP_DIV"); return(OP_DIV);}
"%"             {print_token("OP_MOD"); return(OP_MOD);}
"not"           {print_token("OP_NOT"); return(OP_NOT);}
"and"           {print_token("OP_AND"); return(OP_AND);}
"or"            {print_token("OP_OR"); return(OP_OR);}
"("             {print_token("PAR_IZDO"); return(PAR_IZDO);}
")"             {print_token("PAR_DCHO"); return(PAR_DCHO);}
"["             {print_token("CORCH_IZDO"); return(CORCH_IZDO);}
"]"             {print_token("CORCH_DCHO"); return(CORCH_DCHO);}
","             {print_token("DELIM_C"); return(DELIM_C);}
";"             {print_token("DELIM_PC"); return(DELIM_PC);}
":"             {print_token("DELIM_2P"); return(DELIM_2P);}
".."            {print_token("DELIM_ARR"); return(DELIM_ARR);}
"."             {print_token("DELIM_P"); return(DELIM_P);}
"<<"            {print_token("ATOM_INI"); return(ATOM_INI);}
">>"            {print_token("ATOM_FIN"); return(ATOM_FIN);}
{id}            {print_token("IDENT"); return(IDENT);}
{literal}       {print_token("LITERAL"); return(LITERAL);}
{entero}        {print_token("L_INTEGER"); return(L_INTEGER);}
{real}          {print_token("L_REAL"); return(L_REAL);}
{caracter}      {print_token("L_CHAR"); return(L_CHAR);}
{comentario}    { /*IGNORAR*/ }
{ws}            { /*IGNORAR*/ }

.               {
    /*Regla para patrones no reconocidos */
    print_token("UNRECOGNIZED_TOKEN");
    return(UNRECOGNIZED_TOKEN);
}

%%

/**
 * @brief Imprime el token t especificado
 * @param t_str : Valor de token en cadena de caracteres
 */
void print_token(char* t_str){
    //Se imprime el valor de token, si esta en directiva debug
    #ifdef LMP_VERBOSE
        printf("%s\n",t_str);
    #endif
}

/* FUNCIONES AUXILIARES */
