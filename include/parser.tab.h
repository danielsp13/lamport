/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    S_PROGRAM = 258,               /* S_PROGRAM  */
    S_VAR = 259,                   /* S_VAR  */
    T_INTEGER = 260,               /* T_INTEGER  */
    T_BOOLEAN = 261,               /* T_BOOLEAN  */
    T_CHAR = 262,                  /* T_CHAR  */
    T_STRING = 263,                /* T_STRING  */
    T_REAL = 264,                  /* T_REAL  */
    T_ARRAY = 265,                 /* T_ARRAY  */
    T_SEMAPHORE = 266,             /* T_SEMAPHORE  */
    T_DPROCESS = 267,              /* T_DPROCESS  */
    S_PROCESS = 268,               /* S_PROCESS  */
    S_PROCEDURE = 269,             /* S_PROCEDURE  */
    S_FUNCTION = 270,              /* S_FUNCTION  */
    RETURN = 271,                  /* RETURN  */
    B_BEGIN = 272,                 /* B_BEGIN  */
    B_END = 273,                   /* B_END  */
    B_COBEGIN = 274,               /* B_COBEGIN  */
    B_COEND = 275,                 /* B_COEND  */
    S_FORK = 276,                  /* S_FORK  */
    JOIN = 277,                    /* JOIN  */
    IF = 278,                      /* IF  */
    THEN = 279,                    /* THEN  */
    ELSE = 280,                    /* ELSE  */
    WHILE = 281,                   /* WHILE  */
    DO = 282,                      /* DO  */
    FOR = 283,                     /* FOR  */
    TO = 284,                      /* TO  */
    IDENT = 285,                   /* IDENT  */
    LITERAL = 286,                 /* LITERAL  */
    L_INTEGER = 287,               /* L_INTEGER  */
    L_REAL = 288,                  /* L_REAL  */
    L_BOOLEAN_TRUE = 289,          /* L_BOOLEAN_TRUE  */
    L_BOOLEAN_FALSE = 290,         /* L_BOOLEAN_FALSE  */
    L_CHAR = 291,                  /* L_CHAR  */
    OP_ASSIGN = 292,               /* OP_ASSIGN  */
    OP_REL_LT = 293,               /* OP_REL_LT  */
    OP_REL_GT = 294,               /* OP_REL_GT  */
    OP_REL_LTE = 295,              /* OP_REL_LTE  */
    OP_REL_GTE = 296,              /* OP_REL_GTE  */
    OP_REL_EQ = 297,               /* OP_REL_EQ  */
    OP_REL_NEQ = 298,              /* OP_REL_NEQ  */
    OP_SUM = 299,                  /* OP_SUM  */
    OP_MINUS = 300,                /* OP_MINUS  */
    OP_MULT = 301,                 /* OP_MULT  */
    OP_DIV = 302,                  /* OP_DIV  */
    OP_MOD = 303,                  /* OP_MOD  */
    OP_NOT = 304,                  /* OP_NOT  */
    OP_AND = 305,                  /* OP_AND  */
    OP_OR = 306,                   /* OP_OR  */
    PAR_IZDO = 307,                /* PAR_IZDO  */
    PAR_DCHO = 308,                /* PAR_DCHO  */
    CORCH_IZDO = 309,              /* CORCH_IZDO  */
    CORCH_DCHO = 310,              /* CORCH_DCHO  */
    DELIM_C = 311,                 /* DELIM_C  */
    DELIM_PC = 312,                /* DELIM_PC  */
    DELIM_2P = 313,                /* DELIM_2P  */
    DELIM_ARR = 314,               /* DELIM_ARR  */
    DELIM_P = 315,                 /* DELIM_P  */
    ATOM_INI = 316,                /* ATOM_INI  */
    ATOM_FIN = 317,                /* ATOM_FIN  */
    UNRECOGNIZED_TOKEN = 318,      /* UNRECOGNIZED_TOKEN  */
    UNARY_MINUS = 319              /* UNARY_MINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
