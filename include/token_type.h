/**
 * LAMPORT. Simulador de Sistemas Concurrentes y Distribuidos
 * @file token_type.h
 * @author Daniel Perez Ruiz
 */

#ifndef _LAMPORT_TOKENTYPE_DPR_
#define _LAMPORT_TOKENTYPE_DPR_

//Enumerado con los diferentes tipos de tokens definidos
typedef enum{
    S_PROGRAM = 1,
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
    JOIN,
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
    OP_REL_LT,
    OP_REL_GT,
    OP_REL_LTE,
    OP_REL_GTE,
    OP_REL_EQ,
    OP_REL_NEQ,
    OP_SUM,
    OP_MINUS,
    OP_MULT,
    OP_DIV,
    OP_MOD,
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
    ATOM_FIN,
    UNRECOGNIZED_TOKEN
} TokenType;

#endif //_LAMPORT_TOKENTYPE_DPR_