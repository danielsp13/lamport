/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file token_type.h
 * @author Daniel Perez Ruiz
 */

#ifndef _LAMPORT_TOKENTYPE_DPR_
#define _LAMPORT_TOKENTYPE_DPR_

//Enumerado con los diferentes tipos de tokens definidos
typedef enum{
    S_PROGRAM,
    S_VAR,
    T_INTEGER,
    T_BOOLEAN,
    T_CHAR,
    T_STRING,
    T_REAL,
    T_ARRAY,
    T_SEMAPHORE,
    T_DPROCESS,
    S_PROCESS,
    S_PROCEDURE,
    S_FUNCTION,
    RETURN,
    B_BEGIN,
    B_END,
    B_COBEGIN,
    B_COEND,
    S_FORK,
    IF,
    THEN,
    ELSE,
    WHILE,
    DO,
    FOR,
    TO,
    IDENT,
    LITERAL,
    L_INTEGER,
    L_REAL,
    L_BOOLEAN,
    L_CHAR,
    OP_ASSIGN,
    OP_REL,
    OP_NOT,
    OP_AND,
    OP_OR,
    PAR_IZDO,
    PAR_DCHO,
    CORCH_IZDO,
    CORCH_DCHO,
    DELIM_C,
    DELIM_PC,
    DELIM_2P,
    DELIM_ARR,
    ATOM_INI,
    ATOM_FIN
} TokenType;

//Enumerado con los diferentes tipos de operadores relacionales
typedef enum{
    LT,
    GT,
    LE,
    GE,
    EQ,
    NE
} OpRelType;

#endif //_LAMPORT_TOKENTYPE_DPR_