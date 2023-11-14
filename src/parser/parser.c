/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 12 "src/parser/parser.y"

    // -----------------------------------------------------------------
    // INCLUSION DE COMPONENTES DE LMP

    // -- Inclusion de AST
    #include "AST/AST.h"

    // -- Inclusion del manejador de errores
    #include "error/error_manager.h"

    // -- Inclusion del registro de bloques
    #include "parser/parser_register.h"

    // -----------------------------------------------------------------
    // DEFINICION DE FUNCIONES Y ESTRUCTURAS DE ASISTENCIA DE PARSING

    /**
     * @brief Comprueba si hay errores sintacticos
     * @return 1 (TRUE) si los hay, 0 (FALSE) si no
     */
    int have_syntax_errors();

    // -----------------------------------------------------------------
    // DEFINICION DE FUNCIONES DE MANEJO DE ERRORES

    // -- Directiva de debug interna
    //#define DEBUG_PARSER

    // -----------------------------------------------------------------
    // DEFINICION DE FUNCIONES Y ESTRUCTURAS PROPIAS DE BISON

    // -- Variables y funciones a utilizar por el analizador sintactico
    extern int yylex();
    extern FILE *yyin;
    extern int yylineno;

    void yyerror(const char* s);  

#line 110 "src/parser/parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include  "lexer/token.h" 
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_S_PROGRAM = 3,                  /* S_PROGRAM  */
  YYSYMBOL_S_VAR = 4,                      /* S_VAR  */
  YYSYMBOL_T_INTEGER = 5,                  /* T_INTEGER  */
  YYSYMBOL_T_BOOLEAN = 6,                  /* T_BOOLEAN  */
  YYSYMBOL_T_CHAR = 7,                     /* T_CHAR  */
  YYSYMBOL_T_STRING = 8,                   /* T_STRING  */
  YYSYMBOL_T_REAL = 9,                     /* T_REAL  */
  YYSYMBOL_T_ARRAY = 10,                   /* T_ARRAY  */
  YYSYMBOL_T_SEMAPHORE = 11,               /* T_SEMAPHORE  */
  YYSYMBOL_T_DPROCESS = 12,                /* T_DPROCESS  */
  YYSYMBOL_S_PROCESS = 13,                 /* S_PROCESS  */
  YYSYMBOL_S_PROCEDURE = 14,               /* S_PROCEDURE  */
  YYSYMBOL_S_FUNCTION = 15,                /* S_FUNCTION  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_B_BEGIN = 17,                   /* B_BEGIN  */
  YYSYMBOL_B_END = 18,                     /* B_END  */
  YYSYMBOL_B_COBEGIN = 19,                 /* B_COBEGIN  */
  YYSYMBOL_B_COEND = 20,                   /* B_COEND  */
  YYSYMBOL_S_FORK = 21,                    /* S_FORK  */
  YYSYMBOL_JOIN = 22,                      /* JOIN  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_THEN = 24,                      /* THEN  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_DO = 27,                        /* DO  */
  YYSYMBOL_FOR = 28,                       /* FOR  */
  YYSYMBOL_TO = 29,                        /* TO  */
  YYSYMBOL_IDENT = 30,                     /* IDENT  */
  YYSYMBOL_LITERAL = 31,                   /* LITERAL  */
  YYSYMBOL_L_INTEGER = 32,                 /* L_INTEGER  */
  YYSYMBOL_L_REAL = 33,                    /* L_REAL  */
  YYSYMBOL_L_BOOLEAN_TRUE = 34,            /* L_BOOLEAN_TRUE  */
  YYSYMBOL_L_BOOLEAN_FALSE = 35,           /* L_BOOLEAN_FALSE  */
  YYSYMBOL_L_CHAR = 36,                    /* L_CHAR  */
  YYSYMBOL_OP_ASSIGN = 37,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_REL_LT = 38,                 /* OP_REL_LT  */
  YYSYMBOL_OP_REL_GT = 39,                 /* OP_REL_GT  */
  YYSYMBOL_OP_REL_LTE = 40,                /* OP_REL_LTE  */
  YYSYMBOL_OP_REL_GTE = 41,                /* OP_REL_GTE  */
  YYSYMBOL_OP_REL_EQ = 42,                 /* OP_REL_EQ  */
  YYSYMBOL_OP_REL_NEQ = 43,                /* OP_REL_NEQ  */
  YYSYMBOL_OP_SUM = 44,                    /* OP_SUM  */
  YYSYMBOL_OP_MINUS = 45,                  /* OP_MINUS  */
  YYSYMBOL_OP_MULT = 46,                   /* OP_MULT  */
  YYSYMBOL_OP_DIV = 47,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 48,                    /* OP_MOD  */
  YYSYMBOL_OP_NOT = 49,                    /* OP_NOT  */
  YYSYMBOL_OP_AND = 50,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 51,                     /* OP_OR  */
  YYSYMBOL_PAR_IZDO = 52,                  /* PAR_IZDO  */
  YYSYMBOL_PAR_DCHO = 53,                  /* PAR_DCHO  */
  YYSYMBOL_CORCH_IZDO = 54,                /* CORCH_IZDO  */
  YYSYMBOL_CORCH_DCHO = 55,                /* CORCH_DCHO  */
  YYSYMBOL_DELIM_C = 56,                   /* DELIM_C  */
  YYSYMBOL_DELIM_PC = 57,                  /* DELIM_PC  */
  YYSYMBOL_DELIM_2P = 58,                  /* DELIM_2P  */
  YYSYMBOL_DELIM_ARR = 59,                 /* DELIM_ARR  */
  YYSYMBOL_DELIM_P = 60,                   /* DELIM_P  */
  YYSYMBOL_ATOM_INI = 61,                  /* ATOM_INI  */
  YYSYMBOL_ATOM_FIN = 62,                  /* ATOM_FIN  */
  YYSYMBOL_PRINT = 63,                     /* PRINT  */
  YYSYMBOL_SEM_WAIT = 64,                  /* SEM_WAIT  */
  YYSYMBOL_SEM_SIGNAL = 65,                /* SEM_SIGNAL  */
  YYSYMBOL_SLEEP = 66,                     /* SLEEP  */
  YYSYMBOL_UNRECOGNIZED_TOKEN = 67,        /* UNRECOGNIZED_TOKEN  */
  YYSYMBOL_YYACCEPT = 68,                  /* $accept  */
  YYSYMBOL_program = 69,                   /* program  */
  YYSYMBOL_70_program_name = 70,           /* program-name  */
  YYSYMBOL_71_list_declarations = 71,      /* list-declarations  */
  YYSYMBOL_declaration = 72,               /* declaration  */
  YYSYMBOL_73_list_subprograms = 73,       /* list-subprograms  */
  YYSYMBOL_subprogram = 74,                /* subprogram  */
  YYSYMBOL_75_subprogram_procedure = 75,   /* subprogram-procedure  */
  YYSYMBOL_76_subprogram_procedure_name = 76, /* subprogram-procedure-name  */
  YYSYMBOL_77_subprogram_function = 77,    /* subprogram-function  */
  YYSYMBOL_78_subprogram_function_name = 78, /* subprogram-function-name  */
  YYSYMBOL_79_list_parameters = 79,        /* list-parameters  */
  YYSYMBOL_parameter = 80,                 /* parameter  */
  YYSYMBOL_81_parameter_name = 81,         /* parameter-name  */
  YYSYMBOL_82_list_process = 82,           /* list-process  */
  YYSYMBOL_process = 83,                   /* process  */
  YYSYMBOL_84_process_def = 84,            /* process-def  */
  YYSYMBOL_85_process_def_array = 85,      /* process-def-array  */
  YYSYMBOL_86_process_name = 86,           /* process-name  */
  YYSYMBOL_type = 87,                      /* type  */
  YYSYMBOL_88_basic_or_array_type = 88,    /* basic-or-array-type  */
  YYSYMBOL_89_basic_type = 89,             /* basic-type  */
  YYSYMBOL_90_special_type = 90,           /* special-type  */
  YYSYMBOL_91_block_statements_begin_end = 91, /* block-statements-begin-end  */
  YYSYMBOL_92_block_statements_cobegin_coend = 92, /* block-statements-cobegin-coend  */
  YYSYMBOL_93_block_statements_atomic = 93, /* block-statements-atomic  */
  YYSYMBOL_94_block_statements_function = 94, /* block-statements-function  */
  YYSYMBOL_95_list_statements = 95,        /* list-statements  */
  YYSYMBOL_statement = 96,                 /* statement  */
  YYSYMBOL_97_assignment_statement = 97,   /* assignment-statement  */
  YYSYMBOL_98_while_statement = 98,        /* while-statement  */
  YYSYMBOL_99_for_statement = 99,          /* for-statement  */
  YYSYMBOL_100_if_statement = 100,         /* if-statement  */
  YYSYMBOL_101_fork_statement = 101,       /* fork-statement  */
  YYSYMBOL_102_join_statement = 102,       /* join-statement  */
  YYSYMBOL_103_sleep_statement = 103,      /* sleep-statement  */
  YYSYMBOL_104_return_statement = 104,     /* return-statement  */
  YYSYMBOL_105_print_statement = 105,      /* print-statement  */
  YYSYMBOL_106_list_print = 106,           /* list-print  */
  YYSYMBOL_107_sem_wait_statement = 107,   /* sem-wait-statement  */
  YYSYMBOL_108_sem_signal_statement = 108, /* sem-signal-statement  */
  YYSYMBOL_109_procedure_call_statement = 109, /* procedure-call-statement  */
  YYSYMBOL_expression = 110,               /* expression  */
  YYSYMBOL_111_binary_expression = 111,    /* binary-expression  */
  YYSYMBOL_112_unary_expression = 112,     /* unary-expression  */
  YYSYMBOL_term = 113,                     /* term  */
  YYSYMBOL_literal = 114,                  /* literal  */
  YYSYMBOL_115_expr_identifier = 115,      /* expr-identifier  */
  YYSYMBOL_116_function_call_expression = 116, /* function-call-expression  */
  YYSYMBOL_117_list_arguments = 117,       /* list-arguments  */
  YYSYMBOL_argument = 118                  /* argument  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   893

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  357

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   242,   242,   247,   252,   257,   294,   303,   312,   319,
     329,   339,   345,   350,   355,   360,   366,   371,   375,   379,
     390,   399,   405,   408,   415,   426,   438,   443,   450,   455,
     461,   466,   470,   477,   484,   506,   528,   533,   538,   543,
     548,   553,   559,   564,   568,   575,   584,   593,   605,   619,
     628,   636,   648,   651,   658,   670,   675,   679,   687,   698,
     703,   708,   712,   719,   728,   731,   734,   741,   744,   754,
     761,   770,   779,   788,   797,   809,   818,   834,   844,   848,
     856,   866,   874,   884,   892,   907,   917,   924,   933,   945,
     948,   951,   954,   957,   960,   963,   966,   969,   972,   975,
     978,   981,   988,   999,  1010,  1015,  1020,  1028,  1041,  1055,
    1065,  1078,  1088,  1096,  1106,  1114,  1124,  1132,  1142,  1150,
    1160,  1167,  1176,  1187,  1199,  1212,  1222,  1237,  1240,  1243,
    1246,  1254,  1264,  1274,  1284,  1294,  1304,  1314,  1324,  1334,
    1344,  1354,  1365,  1375,  1388,  1398,  1410,  1413,  1416,  1419,
    1432,  1441,  1450,  1459,  1468,  1477,  1489,  1498,  1511,  1521,
    1537,  1546,  1557
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "S_PROGRAM", "S_VAR",
  "T_INTEGER", "T_BOOLEAN", "T_CHAR", "T_STRING", "T_REAL", "T_ARRAY",
  "T_SEMAPHORE", "T_DPROCESS", "S_PROCESS", "S_PROCEDURE", "S_FUNCTION",
  "RETURN", "B_BEGIN", "B_END", "B_COBEGIN", "B_COEND", "S_FORK", "JOIN",
  "IF", "THEN", "ELSE", "WHILE", "DO", "FOR", "TO", "IDENT", "LITERAL",
  "L_INTEGER", "L_REAL", "L_BOOLEAN_TRUE", "L_BOOLEAN_FALSE", "L_CHAR",
  "OP_ASSIGN", "OP_REL_LT", "OP_REL_GT", "OP_REL_LTE", "OP_REL_GTE",
  "OP_REL_EQ", "OP_REL_NEQ", "OP_SUM", "OP_MINUS", "OP_MULT", "OP_DIV",
  "OP_MOD", "OP_NOT", "OP_AND", "OP_OR", "PAR_IZDO", "PAR_DCHO",
  "CORCH_IZDO", "CORCH_DCHO", "DELIM_C", "DELIM_PC", "DELIM_2P",
  "DELIM_ARR", "DELIM_P", "ATOM_INI", "ATOM_FIN", "PRINT", "SEM_WAIT",
  "SEM_SIGNAL", "SLEEP", "UNRECOGNIZED_TOKEN", "$accept", "program",
  "program-name", "list-declarations", "declaration", "list-subprograms",
  "subprogram", "subprogram-procedure", "subprogram-procedure-name",
  "subprogram-function", "subprogram-function-name", "list-parameters",
  "parameter", "parameter-name", "list-process", "process", "process-def",
  "process-def-array", "process-name", "type", "basic-or-array-type",
  "basic-type", "special-type", "block-statements-begin-end",
  "block-statements-cobegin-coend", "block-statements-atomic",
  "block-statements-function", "list-statements", "statement",
  "assignment-statement", "while-statement", "for-statement",
  "if-statement", "fork-statement", "join-statement", "sleep-statement",
  "return-statement", "print-statement", "list-print",
  "sem-wait-statement", "sem-signal-statement", "procedure-call-statement",
  "expression", "binary-expression", "unary-expression", "term", "literal",
  "expr-identifier", "function-call-expression", "list-arguments",
  "argument", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-169)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-16)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      48,    16,    20,    35,    24,    43,  -169,    87,  -169,    41,
      22,  -169,    43,  -169,  -169,    23,     7,   123,     1,   123,
     123,    54,  -169,    10,  -169,    55,    17,   859,     1,    27,
      65,    43,     1,  -169,  -169,  -169,     1,   123,    95,   269,
      42,  -169,    84,    36,  -169,  -169,  -169,  -169,  -169,  -169,
      88,  -169,  -169,    99,  -169,  -169,  -169,    43,    40,  -169,
     107,   121,  -169,   122,  -169,  -169,    43,    42,   105,    32,
    -169,    42,     8,  -169,  -169,  -169,    69,   308,  -169,  -169,
       2,   108,   109,   156,  -169,  -169,   125,   145,   308,  -169,
    -169,  -169,   364,   171,   146,   308,   308,   177,    91,   374,
     152,   178,   196,   308,  -169,  -169,   210,   394,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,   437,
     144,  -169,  -169,  -169,  -169,  -169,  -169,   308,   497,   497,
     308,   473,   552,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
     691,  -169,   173,   181,   175,   179,   190,    90,   192,   188,
     197,   202,   126,   203,   123,   215,    38,  -169,   229,   219,
    -169,   474,   496,   247,   308,   180,   308,  -169,   223,   308,
     234,   235,   572,  -169,  -169,   282,   308,   592,  -169,  -169,
     781,  -169,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,  -169,   184,   123,   238,   266,
     859,   244,   270,    42,   119,   545,   245,   252,   545,   248,
     159,    42,   123,   308,   308,  -169,  -169,    42,    42,   308,
     612,   254,   797,   249,   272,   709,  -169,   273,   672,  -169,
    -169,  -169,  -169,   277,   727,   479,  -169,   174,   174,   174,
     174,   845,   845,   206,   206,  -169,  -169,  -169,   834,   811,
    -169,    42,   123,  -169,  -169,   123,  -169,    42,  -169,   289,
      42,   265,   545,   545,   120,   123,   545,   268,  -169,    42,
     745,   763,   321,  -169,   538,  -169,  -169,   276,   308,   310,
     291,   308,  -169,  -169,  -169,  -169,    42,    42,  -169,  -169,
      42,  -169,   123,   294,   295,   319,   337,   337,   142,   123,
    -169,   298,   302,    42,   308,  -169,  -169,   308,  -169,  -169,
    -169,  -169,  -169,   337,   123,   123,  -169,   337,   346,  -169,
    -169,   320,   337,   337,   123,   328,  -169,   518,   632,  -169,
     337,   337,  -169,   308,    44,   343,  -169,   337,  -169,  -169,
      42,  -169,    42,    42,  -169,  -169,  -169,   652,  -169,   345,
    -169,  -169,  -169,  -169,  -169,  -169,  -169
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     6,     8,     1,     0,
       0,     5,    50,    52,    53,     0,     0,     8,    21,     8,
       8,     0,    63,     8,    51,     0,     0,     0,    21,     0,
       0,     0,    21,    22,    23,     7,    21,     8,     0,     0,
       0,    12,     0,     0,    66,    70,    71,    72,    73,    74,
       0,    75,    76,     0,    64,    67,    65,     0,     0,    33,
       0,     0,    45,     0,     3,    20,     0,     0,     0,     0,
      57,     0,     0,    56,    13,    14,     0,     0,    11,     2,
       0,     0,     0,     0,     4,    55,     0,     0,     0,    54,
      79,    78,     0,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   100,     0,    87,    89,    90,
      91,    92,    94,    95,    96,    97,    98,    99,    93,   130,
     156,   150,   151,   155,   152,   153,   154,     0,     0,     0,
       0,     0,     0,   127,   128,   129,   147,   146,   148,   130,
       0,    49,     0,     0,    47,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     8,     0,     0,    81,     0,   112,
     113,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,   116,    77,    88,     0,     0,    17,   145,   144,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    69,     8,     0,     0,
       0,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     0,    80,   111,     0,     0,     0,
     105,     0,   162,     0,   161,     0,    82,     0,   122,   123,
     124,   115,   159,     0,     0,     0,   149,   136,   138,   137,
     139,   140,   141,   131,   132,   133,   134,   135,   142,   143,
      68,     0,     8,    46,    48,     8,    32,     0,    30,     0,
       0,     0,     0,     0,     8,     8,     0,     0,    59,     0,
       0,     0,   109,   107,     0,   102,   126,     0,     0,   104,
     120,     0,   158,   157,    18,    27,     0,     0,    25,    31,
       0,    29,     8,     0,     0,     0,     0,     0,     8,     8,
      60,     0,     0,     0,     0,   125,   160,     0,   119,   121,
      26,    28,    24,     0,     8,     8,    44,     0,     0,    42,
      40,     0,     0,     0,     8,     0,   110,     0,   106,    37,
       0,     0,    35,     0,     0,     0,    43,     0,    41,    39,
       0,    62,     0,     0,   103,    36,    38,   118,    86,     0,
      85,    34,    61,    58,   108,   117,    84
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,   360,   -17,  -169,   147,  -169,  -169,  -169,  -169,
    -169,   -70,  -169,  -169,    56,  -169,  -169,  -169,  -169,   -42,
    -147,   170,  -169,   -63,  -169,  -169,   148,   -82,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,    37,  -169,    89,  -169,
    -169,  -169,    75,  -169,  -169,   -21,  -169,  -169,  -169,  -168,
    -169
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     7,    18,    19,    31,    32,    33,    60,    34,
      63,   143,   144,   145,    11,    12,    13,    14,    23,    53,
      54,    55,    56,    73,   104,   105,   319,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   335,   115,   227,   116,
     117,   118,   222,   133,   134,   135,   136,   137,   138,   223,
     224
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    76,    35,    36,    85,   209,    40,   233,    89,    90,
     158,   148,   150,   153,    15,    29,    30,   168,    42,     4,
      67,     5,    71,    21,    25,   174,    91,    92,    58,    93,
      94,    95,   141,    87,    96,     8,    97,    44,    98,   213,
      16,    45,    46,    47,    48,    49,    50,    51,    52,     1,
       6,     2,    22,    26,     6,   142,    10,    59,   261,    72,
     333,   264,   348,   267,    38,    27,    61,    39,    24,    99,
     119,   100,   101,   102,   103,    43,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    64,   193,   194,
      88,    15,    80,    75,    15,    62,    68,   214,    20,   120,
     121,   122,   123,   124,   125,   126,   127,   178,   179,   146,
     306,    37,    41,    79,   128,   293,   294,    16,   129,   298,
      16,   130,    84,    15,    15,    69,   131,    15,   164,   253,
     203,    45,    46,    47,    48,    49,    50,   211,   141,   141,
     258,    74,    77,   165,    17,   166,    15,   202,   268,    16,
      16,   132,   140,    16,   272,   273,    78,   151,   254,    81,
      86,   147,   149,   156,    45,    46,    47,    48,    49,    50,
     161,   162,    16,    82,    83,    57,   259,   295,   172,    65,
     251,   139,   154,    66,   208,   257,   141,   260,   285,    45,
      46,    47,    48,    49,   288,   269,   175,   291,   176,   321,
     155,   159,   177,   160,   169,   180,   300,   163,   170,   152,
     120,   121,   122,   123,   124,   125,   126,   266,   188,   189,
     190,   191,   192,   310,   311,   128,   171,   312,   173,   129,
     197,   199,   130,   221,   198,   286,   334,   200,   287,   220,
     326,   225,   290,   201,   228,   204,   205,   296,   297,   215,
     206,   234,   190,   191,   192,   207,   210,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      70,   256,   212,    15,    15,   313,   216,   352,   317,   353,
     354,   322,   323,   139,   219,   226,    -8,    -8,   270,   271,
     289,   229,   230,    15,   274,   252,   141,   330,   331,    16,
      16,   255,   277,   262,   337,   265,    -8,   340,   342,   139,
     263,   276,   120,   121,   122,   123,   124,   125,   126,    16,
     316,   336,   292,    15,    15,   299,   280,   128,   278,   341,
     282,   129,    15,   305,   130,   232,    -8,    -8,   120,   121,
     122,   123,   124,   125,   126,    -8,   303,   307,   308,    16,
      16,   314,   315,   128,   318,   324,   228,   129,    16,   325,
     130,   350,   333,   356,     9,    92,   250,    93,    94,    95,
     309,   349,    96,     0,    97,     0,    98,     0,     0,   327,
       0,     0,   328,    92,   157,    93,    94,    95,     0,     0,
      96,     0,    97,    92,    98,    93,    94,    95,     0,     0,
      96,     0,    97,     0,    98,     0,     0,    99,   347,   100,
     101,   102,   103,    92,     0,    93,    94,    95,     0,     0,
      96,     0,    97,     0,    98,    99,     0,   100,   101,   102,
     103,     0,     0,     0,     0,    99,   167,   100,   101,   102,
     103,   -15,     0,     0,     0,   320,     0,     0,     0,     0,
     -15,   -15,   -15,     0,   -15,    99,     0,   100,   101,   102,
     103,   329,     0,     0,     0,   332,     0,   -15,     0,     0,
     338,   339,     0,     0,   181,     0,     0,   -10,   345,   346,
     284,     0,     0,    -9,     0,   351,   -10,   -10,   -10,     0,
     -10,     0,    -9,    -9,    -9,     0,    -9,     0,   217,     0,
       0,     0,     0,   -10,     0,     0,     0,     0,     0,    -9,
       0,     0,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   218,   193,   194,     0,   120,   121,   122,
     123,   124,   125,   126,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   343,   193,   194,     0,   130,
      45,    46,    47,    48,    49,    50,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   304,   193,   194,
       0,     0,     0,     0,     0,     0,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,     0,     0,     0,     0,     0,   195,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,     0,     0,     0,     0,     0,   231,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,     0,     0,     0,     0,     0,   235,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,     0,     0,     0,     0,     0,   275,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,     0,     0,     0,     0,     0,   344,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,     0,     0,     0,     0,     0,   355,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,     0,     0,     0,     0,   281,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,     0,     0,     0,   196,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,     0,     0,     0,   279,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,     0,
       0,     0,   283,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,     0,     0,     0,
     301,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,     0,     0,     0,   302,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,     0,   236,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      44,   193,     0,     0,    45,    46,    47,    48,    49,    50,
      51,    52,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   182,   183,   184,   185,     0,     0,   188,
     189,   190,   191,   192
};

static const yytype_int16 yycheck[] =
{
      17,    43,    19,    20,    67,   152,    23,   175,    71,     1,
      92,    81,    82,    83,     4,    14,    15,    99,     1,     3,
      37,     1,    39,     1,     1,   107,    18,    19,     1,    21,
      22,    23,    30,     1,    26,     0,    28,     1,    30,     1,
      30,     5,     6,     7,     8,     9,    10,    11,    12,     1,
      30,     3,    30,    30,    30,    53,    13,    30,   205,    17,
      16,   208,    18,   210,    54,    58,     1,    57,    12,    61,
       1,    63,    64,    65,    66,    58,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    31,    50,    51,
      58,     4,    52,    57,     4,    30,     1,    59,    57,    30,
      31,    32,    33,    34,    35,    36,    37,   128,   129,     1,
     278,    57,    57,    57,    45,   262,   263,    30,    49,   266,
      30,    52,    66,     4,     4,    30,    57,     4,    37,   199,
     147,     5,     6,     7,     8,     9,    10,   154,    30,    30,
     203,    57,    54,    52,    57,    54,     4,    57,   211,    30,
      30,    76,    77,    30,   217,   218,    57,     1,   200,    52,
      55,    53,    53,    88,     5,     6,     7,     8,     9,    10,
      95,    96,    30,    52,    52,    28,    57,    57,   103,    32,
     197,     1,    57,    36,    58,   202,    30,   204,   251,     5,
       6,     7,     8,     9,   257,   212,    52,   260,    54,    57,
      55,    30,   127,    57,    52,   130,   269,    30,    30,    53,
      30,    31,    32,    33,    34,    35,    36,    58,    44,    45,
      46,    47,    48,   286,   287,    45,    30,   290,    18,    49,
      57,    56,    52,    53,    53,   252,   318,    58,   255,   164,
     303,   166,   259,    53,   169,    53,    58,   264,   265,    20,
      53,   176,    46,    47,    48,    53,    53,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       1,     1,    57,     4,     4,   292,    57,   340,   295,   342,
     343,   298,   299,     1,    37,    62,    17,    17,   213,   214,
       1,    57,    57,     4,   219,    57,    30,   314,   315,    30,
      30,    57,    53,    58,   321,    57,    17,   324,   325,     1,
      58,    57,    30,    31,    32,    33,    34,    35,    36,    30,
       1,     1,    57,     4,     4,    57,    53,    45,    56,     1,
      53,    49,     4,    57,    52,    53,    17,    17,    30,    31,
      32,    33,    34,    35,    36,    17,    25,    37,    57,    30,
      30,    57,    57,    45,    17,    57,   281,    49,    30,    57,
      52,    18,    16,    18,     4,    19,   196,    21,    22,    23,
     281,   334,    26,    -1,    28,    -1,    30,    -1,    -1,   304,
      -1,    -1,   307,    19,    20,    21,    22,    23,    -1,    -1,
      26,    -1,    28,    19,    30,    21,    22,    23,    -1,    -1,
      26,    -1,    28,    -1,    30,    -1,    -1,    61,   333,    63,
      64,    65,    66,    19,    -1,    21,    22,    23,    -1,    -1,
      26,    -1,    28,    -1,    30,    61,    -1,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,     4,    -1,    -1,    -1,   297,    -1,    -1,    -1,    -1,
      13,    14,    15,    -1,    17,    61,    -1,    63,    64,    65,
      66,   313,    -1,    -1,    -1,   317,    -1,    30,    -1,    -1,
     322,   323,    -1,    -1,     1,    -1,    -1,     4,   330,   331,
       1,    -1,    -1,     4,    -1,   337,    13,    14,    15,    -1,
      17,    -1,    13,    14,    15,    -1,    17,    -1,    24,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    27,    50,    51,    -1,    30,    31,    32,
      33,    34,    35,    36,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    27,    50,    51,    -1,    52,
       5,     6,     7,     8,     9,    10,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    29,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    57,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    -1,    -1,    -1,    55,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    -1,    -1,    -1,    55,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    -1,
      -1,    -1,    55,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    -1,    -1,    -1,
      55,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    -1,    -1,    -1,    55,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    -1,    53,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       1,    50,    -1,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    38,    39,    40,    41,    -1,    -1,    44,
      45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    69,     3,     1,    30,    70,     0,    70,
      13,    82,    83,    84,    85,     4,    30,    57,    71,    72,
      57,     1,    30,    86,    82,     1,    30,    58,    71,    14,
      15,    73,    74,    75,    77,    71,    71,    57,    54,    57,
      71,    57,     1,    58,     1,     5,     6,     7,     8,     9,
      10,    11,    12,    87,    88,    89,    90,    73,     1,    30,
      76,     1,    30,    78,    82,    73,    73,    71,     1,    30,
       1,    71,    17,    91,    57,    57,    87,    54,    57,    82,
      52,    52,    52,    52,    82,    91,    55,     1,    58,    91,
       1,    18,    19,    21,    22,    23,    26,    28,    30,    61,
      63,    64,    65,    66,    92,    93,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   105,   107,   108,   109,     1,
      30,    31,    32,    33,    34,    35,    36,    37,    45,    49,
      52,    57,   110,   111,   112,   113,   114,   115,   116,     1,
     110,    30,    53,    79,    80,    81,     1,    53,    79,    53,
      79,     1,    53,    79,    57,    55,   110,    20,    95,    30,
      57,   110,   110,    30,    37,    52,    54,    62,    95,    52,
      30,    30,   110,    18,    95,    52,    54,   110,   113,   113,
     110,     1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    50,    51,    57,    55,    57,    53,    56,
      58,    53,    57,    71,    53,    58,    53,    53,    58,    88,
      53,    71,    57,     1,    59,    20,    57,    24,    27,    37,
     110,    53,   110,   117,   118,   110,    62,   106,   110,    57,
      57,    57,    53,   117,   110,    57,    53,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
      89,    71,    57,    79,    87,    57,     1,    71,    91,    57,
      71,    88,    58,    58,    88,    57,    58,    88,    91,    71,
     110,   110,    91,    91,   110,    57,    57,    53,    56,    55,
      53,    56,    53,    55,     1,    91,    71,    71,    91,     1,
      71,    91,    57,    88,    88,    57,    71,    71,    88,    57,
      91,    55,    55,    25,    29,    57,   117,    37,    57,   106,
      91,    91,    91,    71,    57,    57,     1,    71,    17,    94,
      94,    57,    71,    71,    57,    57,    91,   110,   110,    94,
      71,    71,    94,    16,    95,   104,     1,    71,    94,    94,
      71,     1,    71,    27,    57,    94,    94,   110,    18,   104,
      18,    94,    91,    91,    91,    57,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    69,    69,    69,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    76,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    79,    79,    80,    81,
      82,    82,    83,    83,    84,    84,    84,    84,    85,    85,
      85,    85,    85,    86,    87,    87,    87,    88,    88,    88,
      89,    89,    89,    89,    89,    90,    90,    91,    91,    91,
      92,    92,    93,    93,    94,    94,    94,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    97,    97,    98,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   107,   108,   109,   109,   110,   110,   110,
     110,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   115,   115,   116,   116,
     117,   117,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     5,     7,     3,     1,     2,     0,     7,
       5,     4,     3,     4,     4,     5,     6,     6,     8,     6,
       2,     0,     1,     1,     8,     7,     8,     7,     8,     7,
       6,     7,     6,     1,    10,     9,    10,     9,    10,     9,
       8,     9,     8,     9,     8,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     5,     5,     4,     4,    12,     8,
       9,    12,    11,     1,     1,     1,     1,     1,     5,     4,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     2,
       3,     2,     3,     2,     4,     3,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     7,     4,     3,     6,     4,     8,     4,
       6,     3,     2,     2,     1,     3,     2,     3,     2,     5,
       4,     3,     1,     3,     3,     5,     4,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     3,
       3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: S_PROGRAM program-name DELIM_PC list-declarations list-subprograms list-process  */
#line 242 "src/parser/parser.y"
                                                                                   {
        // -- Crear AST (solo si no hay errores sintacticos)
        if(!have_syntax_errors())
            AST_program = create_program((yyvsp[-4].ident),(yyvsp[-2].decl),(yyvsp[-1].subprog),(yyvsp[0].proc));
    }
#line 1578 "src/parser/parser.c"
    break;

  case 3: /* program: S_PROGRAM program-name list-declarations list-subprograms list-process  */
#line 247 "src/parser/parser.y"
                                                                            {
        // -- Crear AST (solo si no hay errores sintacticos)
        if(!have_syntax_errors())
            AST_program = create_program((yyvsp[-3].ident),(yyvsp[-2].decl),(yyvsp[-1].subprog),(yyvsp[0].proc));
    }
#line 1588 "src/parser/parser.c"
    break;

  case 4: /* program: error S_PROGRAM program-name DELIM_PC list-declarations list-subprograms list-process  */
#line 252 "src/parser/parser.y"
                                                                                           {
        mark_error_syntax_program_unexpected_literal_in_header();
        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1598 "src/parser/parser.c"
    break;

  case 5: /* program: S_PROGRAM error list-process  */
#line 257 "src/parser/parser.y"
                                  {
        mark_error_syntax_program_unexpected_literal_in_header();
        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1608 "src/parser/parser.c"
    break;

  case 6: /* program-name: IDENT  */
#line 294 "src/parser/parser.y"
         { 
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1616 "src/parser/parser.c"
    break;

  case 7: /* list-declarations: declaration list-declarations  */
#line 303 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.decl) = (yyvsp[-1].decl);
            (yyvsp[-1].decl)->next = (yyvsp[0].decl);
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1630 "src/parser/parser.c"
    break;

  case 8: /* list-declarations: %empty  */
#line 312 "src/parser/parser.y"
                   {
        (yyval.decl) = 0;
    }
#line 1638 "src/parser/parser.c"
    break;

  case 9: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression DELIM_PC  */
#line 319 "src/parser/parser.y"
                                                           {
        if(!have_syntax_errors()){
            (yyval.decl) = create_declaration_variable((yyvsp[-5].ident), (yyvsp[-3].type), (yyvsp[-1].expr), yylineno);
            add_declaration_to_register((yyval.decl));
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1652 "src/parser/parser.c"
    break;

  case 10: /* declaration: S_VAR IDENT DELIM_2P type DELIM_PC  */
#line 329 "src/parser/parser.y"
                                        {
        if(!have_syntax_errors()){
            (yyval.decl) = create_declaration_variable((yyvsp[-3].ident), (yyvsp[-1].type), 0, yylineno);
            add_declaration_to_register((yyval.decl));
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1666 "src/parser/parser.c"
    break;

  case 11: /* declaration: IDENT DELIM_2P type DELIM_PC  */
#line 339 "src/parser/parser.y"
                                  {
        mark_error_syntax_declaration_expected_var((yyvsp[-3].ident));
        // Recuperar
        //YYABORT;
    }
#line 1676 "src/parser/parser.c"
    break;

  case 12: /* declaration: S_VAR error DELIM_PC  */
#line 345 "src/parser/parser.y"
                          {
        mark_error_syntax_declaration_expected_identifier();
        //YYABORT;
    }
#line 1685 "src/parser/parser.c"
    break;

  case 13: /* declaration: S_VAR IDENT error DELIM_PC  */
#line 350 "src/parser/parser.y"
                                {
        mark_error_syntax_declaration_expected_delim2p((yyvsp[-2].ident));
        //YYABORT;
    }
#line 1694 "src/parser/parser.c"
    break;

  case 14: /* declaration: S_VAR IDENT DELIM_2P DELIM_PC  */
#line 355 "src/parser/parser.y"
                                   {
        mark_error_syntax_type_expected_type((yyvsp[-2].ident));
        //YYABORT;
    }
#line 1703 "src/parser/parser.c"
    break;

  case 15: /* declaration: S_VAR IDENT DELIM_2P type error  */
#line 360 "src/parser/parser.y"
                                     {
        mark_error_syntax_declaration_expected_delimpc((yyvsp[-3].ident));
        free_AST_type_register((yyvsp[-1].type));
        //YYABORT;
    }
#line 1713 "src/parser/parser.c"
    break;

  case 16: /* declaration: S_VAR IDENT DELIM_2P type expression DELIM_PC  */
#line 366 "src/parser/parser.y"
                                                   {
        mark_error_syntax_declaration_expected_opassign((yyvsp[-4].ident));
        //YYABORT;
    }
#line 1722 "src/parser/parser.c"
    break;

  case 17: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression  */
#line 371 "src/parser/parser.y"
                                                    {
        mark_error_syntax_declaration_expected_delimpc((yyvsp[-4].ident));
        //YYABORT;
    }
#line 1731 "src/parser/parser.c"
    break;

  case 18: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression DELIM_PC error  */
#line 375 "src/parser/parser.y"
                                                                   {
        mark_error_syntax_program_unexpected_literal_in_decl((yyvsp[-6].ident));
        YYABORT;
    }
#line 1740 "src/parser/parser.c"
    break;

  case 19: /* declaration: S_VAR IDENT DELIM_2P type DELIM_PC error  */
#line 379 "src/parser/parser.y"
                                              {
        mark_error_syntax_program_unexpected_literal_in_decl((yyvsp[-4].ident));
        YYABORT;
    }
#line 1749 "src/parser/parser.c"
    break;

  case 20: /* list-subprograms: subprogram list-subprograms  */
#line 390 "src/parser/parser.y"
                               {
        if(!have_syntax_errors()){
            (yyval.subprog) = (yyvsp[-1].subprog);
            (yyvsp[-1].subprog)->next = (yyvsp[0].subprog);
        }
        else{
            (yyval.subprog) = 0;
        }
    }
#line 1763 "src/parser/parser.c"
    break;

  case 21: /* list-subprograms: %empty  */
#line 399 "src/parser/parser.y"
                   {
        (yyval.subprog) = 0;
    }
#line 1771 "src/parser/parser.c"
    break;

  case 22: /* subprogram: subprogram-procedure  */
#line 405 "src/parser/parser.y"
                        {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1779 "src/parser/parser.c"
    break;

  case 23: /* subprogram: subprogram-function  */
#line 408 "src/parser/parser.y"
                         {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1787 "src/parser/parser.c"
    break;

  case 24: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 415 "src/parser/parser.y"
                                                                                                                                 {
        // -- Creacion nodo SUBPROGRAMA (PROCEDURE)
        if(!have_syntax_errors()){
            (yyval.subprog) = create_subprogram_procedure((yyvsp[-6].ident), (yyvsp[-4].param), (yyvsp[-1].decl), (yyvsp[0].stmt), yylineno);
            add_subprogram_to_register((yyval.subprog));
        }
        else{
            (yyval.subprog) = 0;
        }
    }
#line 1802 "src/parser/parser.c"
    break;

  case 25: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 426 "src/parser/parser.y"
                                                                                                                   {
        // -- Creacion nodo SUBPROGRAMA (PROCEDURE)
        if(!have_syntax_errors()){
            (yyval.subprog) = create_subprogram_procedure((yyvsp[-5].ident), 0, (yyvsp[-1].decl), (yyvsp[0].stmt), yylineno);
            add_subprogram_to_register((yyval.subprog));
        }
        else{
            (yyval.subprog) = 0;
        }
        
    }
#line 1818 "src/parser/parser.c"
    break;

  case 26: /* subprogram-procedure: S_PROCEDURE error PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 438 "src/parser/parser.y"
                                                                                                               {
        mark_error_syntax_subprogram_procedure_expected_identifier();
        //YYABORT;
    }
#line 1827 "src/parser/parser.c"
    break;

  case 27: /* subprogram-procedure: S_PROCEDURE error PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 443 "src/parser/parser.y"
                                                                                               {
        // -- Mostrar error
        mark_error_syntax_subprogram_procedure_expected_identifier();
        // -- Abortar inmediatmente el analisis
        //YYABORT;
    }
#line 1838 "src/parser/parser.c"
    break;

  case 28: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO error PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 450 "src/parser/parser.y"
                                                                                                                         {
        mark_error_syntax_subprogram_procedure_expected_parameters((yyvsp[-6].ident));
        //YYABORT;
    }
#line 1847 "src/parser/parser.c"
    break;

  case 29: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO list-declarations block-statements-begin-end  */
#line 455 "src/parser/parser.y"
                                                                                                                          {
        mark_error_syntax_subprogram_procedure_expected_delimpc((yyvsp[-5].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1857 "src/parser/parser.c"
    break;

  case 30: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO list-declarations block-statements-begin-end  */
#line 461 "src/parser/parser.y"
                                                                                                          {
        mark_error_syntax_subprogram_procedure_expected_delimpc((yyvsp[-4].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1867 "src/parser/parser.c"
    break;

  case 31: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO DELIM_PC error  */
#line 466 "src/parser/parser.y"
                                                                                            {
        mark_error_syntax_program_unexpected_literal_in_decl((yyvsp[-5].ident));
        YYABORT;
    }
#line 1876 "src/parser/parser.c"
    break;

  case 32: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO DELIM_PC error  */
#line 470 "src/parser/parser.y"
                                                                            {
        mark_error_syntax_program_unexpected_literal_in_decl((yyvsp[-4].ident));
        YYABORT;
    }
#line 1885 "src/parser/parser.c"
    break;

  case 33: /* subprogram-procedure-name: IDENT  */
#line 477 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1893 "src/parser/parser.c"
    break;

  case 34: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 484 "src/parser/parser.y"
                                                                                                                                                           {
        // -- Creacion de nodo SUBPROGRAMA (FUNCTION)
        if(!have_syntax_errors()){
            // --- Intermediate: Asignar el nombre de funcion a la sentencia de retorno
            /*struct statement * current_stmt = $10->stmt.statement_block.body;
            while(current_stmt->next){
                current_stmt = current_stmt->next;
            }

            current_stmt->stmt.statement_return.function_name = strdup($2);*/

            // --- Ahora si, crear nodo
            (yyval.subprog) = create_subprogram_function((yyvsp[-8].ident), (yyvsp[-6].param), (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-3].type), yylineno);
            add_subprogram_to_register((yyval.subprog));
        }
        else{
            (yyval.subprog) = 0;
        }

        
    }
#line 1919 "src/parser/parser.c"
    break;

  case 35: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 506 "src/parser/parser.y"
                                                                                                                                             {
        // -- Creacion de nodo SUBPROGRAMA (FUNCTION)
        if(!have_syntax_errors()){
            // --- Intermediate: Asignar el nombre de funcion a la sentencia de retorno
            /*struct statement * current_stmt = $9->stmt.statement_block.body;
            while(current_stmt->next){
                current_stmt = current_stmt->next;
            }

            current_stmt->stmt.statement_return.function_name = strdup($2);*/


            (yyval.subprog) = create_subprogram_function((yyvsp[-7].ident), 0, (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-3].type), yylineno);
            add_subprogram_to_register((yyval.subprog));
        }
        else{
            (yyval.subprog) = 0;
        }

        
    }
#line 1945 "src/parser/parser.c"
    break;

  case 36: /* subprogram-function: S_FUNCTION error PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 528 "src/parser/parser.y"
                                                                                                                                          {
        mark_error_syntax_subprogram_function_expected_identifier();
        //YYABORT;
    }
#line 1954 "src/parser/parser.c"
    break;

  case 37: /* subprogram-function: S_FUNCTION error PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 533 "src/parser/parser.y"
                                                                                                                          {
        mark_error_syntax_subprogram_function_expected_identifier();
        //YYABORT;
    }
#line 1963 "src/parser/parser.c"
    break;

  case 38: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO error PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 538 "src/parser/parser.y"
                                                                                                                                                   {
        mark_error_syntax_subprogram_function_expected_parameters((yyvsp[-8].ident));
        //YYABORT;
    }
#line 1972 "src/parser/parser.c"
    break;

  case 39: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 543 "src/parser/parser.y"
                                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delim2p((yyvsp[-7].ident));
        //YYABORT;
    }
#line 1981 "src/parser/parser.c"
    break;

  case 40: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 548 "src/parser/parser.y"
                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delim2p((yyvsp[-6].ident));
        //YYABORT;
    }
#line 1990 "src/parser/parser.c"
    break;

  case 41: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type list-declarations block-statements-function  */
#line 553 "src/parser/parser.y"
                                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delimpc((yyvsp[-7].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 2000 "src/parser/parser.c"
    break;

  case 42: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type list-declarations block-statements-function  */
#line 559 "src/parser/parser.y"
                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delimpc((yyvsp[-6].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 2010 "src/parser/parser.c"
    break;

  case 43: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC error  */
#line 564 "src/parser/parser.y"
                                                                                                                       {
        mark_error_syntax_program_unexpected_literal_in_decl((yyvsp[-7].ident));
        YYABORT;
    }
#line 2019 "src/parser/parser.c"
    break;

  case 44: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC error  */
#line 568 "src/parser/parser.y"
                                                                                                       {
        mark_error_syntax_program_unexpected_literal_in_decl((yyvsp[-6].ident));
        YYABORT;
    }
#line 2028 "src/parser/parser.c"
    break;

  case 45: /* subprogram-function-name: IDENT  */
#line 575 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 2036 "src/parser/parser.c"
    break;

  case 46: /* list-parameters: parameter DELIM_C list-parameters  */
#line 584 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.param) = (yyvsp[-2].param);
            (yyvsp[-2].param)->next = (yyvsp[0].param);
        }
        else{
            (yyval.param) = 0;
        }
    }
#line 2050 "src/parser/parser.c"
    break;

  case 47: /* list-parameters: parameter  */
#line 593 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.param) = (yyvsp[0].param);
        }
        else{
            (yyval.param) = 0;
        }
    }
#line 2063 "src/parser/parser.c"
    break;

  case 48: /* parameter: parameter-name DELIM_2P type  */
#line 605 "src/parser/parser.y"
                                {
        // -- Creacion de nodo PARAMETRO
        if(!have_syntax_errors()){
            (yyval.param) = create_parameter((yyvsp[-2].ident), (yyvsp[0].type), yylineno);
            add_parameter_to_register((yyval.param));
        }
        else{
            (yyval.param) = 0;
        }
        
    }
#line 2079 "src/parser/parser.c"
    break;

  case 49: /* parameter-name: IDENT  */
#line 619 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 2087 "src/parser/parser.c"
    break;

  case 50: /* list-process: process  */
#line 628 "src/parser/parser.y"
           {
        if(!have_syntax_errors()){
            (yyval.proc) = (yyvsp[0].proc);
        }
        else{
            (yyval.proc) = 0;
        }
    }
#line 2100 "src/parser/parser.c"
    break;

  case 51: /* list-process: process list-process  */
#line 636 "src/parser/parser.y"
                          {
        if(!have_syntax_errors()){
            (yyval.proc) = (yyvsp[-1].proc);
            (yyvsp[-1].proc)->next = (yyvsp[0].proc);
        }
        else{
            (yyval.proc) = 0;
        }
    }
#line 2114 "src/parser/parser.c"
    break;

  case 52: /* process: process-def  */
#line 648 "src/parser/parser.y"
               {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 2122 "src/parser/parser.c"
    break;

  case 53: /* process: process-def-array  */
#line 651 "src/parser/parser.y"
                       {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 2130 "src/parser/parser.c"
    break;

  case 54: /* process-def: S_PROCESS process-name DELIM_PC list-declarations block-statements-begin-end  */
#line 658 "src/parser/parser.y"
                                                                                {
        // -- Creacion de nodo PROCESO
        if(!have_syntax_errors()){
            (yyval.proc) = create_process_single((yyvsp[-3].ident), (yyvsp[-1].decl), (yyvsp[0].stmt), yylineno);
            add_process_to_register((yyval.proc));
        }
        else{
            (yyval.proc) = 0;
        }
        
    }
#line 2146 "src/parser/parser.c"
    break;

  case 55: /* process-def: S_PROCESS error DELIM_PC list-declarations block-statements-begin-end  */
#line 670 "src/parser/parser.y"
                                                                           {
        mark_error_syntax_process_expected_identifier();
        //YYABORT;
    }
#line 2155 "src/parser/parser.c"
    break;

  case 56: /* process-def: S_PROCESS process-name list-declarations block-statements-begin-end  */
#line 675 "src/parser/parser.y"
                                                                         {
        mark_error_syntax_process_expected_delimpc((yyvsp[-2].ident));
        //YYABORT;
    }
#line 2164 "src/parser/parser.c"
    break;

  case 57: /* process-def: S_PROCESS process-name DELIM_PC error  */
#line 679 "src/parser/parser.y"
                                           {
        mark_error_syntax_program_unexpected_literal_in_proc((yyvsp[-2].ident));
        YYABORT;
    }
#line 2173 "src/parser/parser.c"
    break;

  case 58: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 687 "src/parser/parser.y"
                                                                                                                                                     {
        // -- Creacion de nodo PROCESO
        if(!have_syntax_errors()){
            (yyval.proc) = create_process_vector((yyvsp[-10].ident), (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-8].ident), (yyvsp[-6].expr), (yyvsp[-4].expr), yylineno);
            add_process_to_register((yyval.proc));
        }
        else{
            (yyval.proc) = 0;
        }
    }
#line 2188 "src/parser/parser.c"
    break;

  case 59: /* process-def-array: S_PROCESS process-name CORCH_IZDO error CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 698 "src/parser/parser.y"
                                                                                                              {
        mark_error_syntax_process_expected_index_identifier((yyvsp[-6].ident));
        //YYABORT;
    }
#line 2197 "src/parser/parser.c"
    break;

  case 60: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT error CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 703 "src/parser/parser.y"
                                                                                                                    {
        mark_error_syntax_process_expected_delim2p((yyvsp[-7].ident));
        //YYABORT;
    }
#line 2206 "src/parser/parser.c"
    break;

  case 61: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression error expression CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 708 "src/parser/parser.y"
                                                                                                                                                   {
        mark_error_syntax_process_expected_delimarr((yyvsp[-10].ident));
        //YYABORT;
    }
#line 2215 "src/parser/parser.c"
    break;

  case 62: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC error  */
#line 712 "src/parser/parser.y"
                                                                                                                {
        mark_error_syntax_program_unexpected_literal_in_proc((yyvsp[-9].ident));
        YYABORT;
    }
#line 2224 "src/parser/parser.c"
    break;

  case 63: /* process-name: IDENT  */
#line 719 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 2232 "src/parser/parser.c"
    break;

  case 64: /* type: basic-or-array-type  */
#line 728 "src/parser/parser.y"
                       {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2240 "src/parser/parser.c"
    break;

  case 65: /* type: special-type  */
#line 731 "src/parser/parser.y"
                  {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2248 "src/parser/parser.c"
    break;

  case 66: /* type: error  */
#line 734 "src/parser/parser.y"
           {
        mark_error_syntax_type_expected_type();
        //YYABORT;
    }
#line 2257 "src/parser/parser.c"
    break;

  case 67: /* basic-or-array-type: basic-type  */
#line 741 "src/parser/parser.y"
              {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2265 "src/parser/parser.c"
    break;

  case 68: /* basic-or-array-type: T_ARRAY CORCH_IZDO expression CORCH_DCHO basic-type  */
#line 744 "src/parser/parser.y"
                                                         {
        if(!have_syntax_errors()){
            (yyval.type) = create_array_type((yyvsp[0].type),(yyvsp[-2].expr));
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2279 "src/parser/parser.c"
    break;

  case 69: /* basic-or-array-type: T_ARRAY CORCH_IZDO expression CORCH_DCHO  */
#line 754 "src/parser/parser.y"
                                              {
        mark_error_syntax_type_expected_type();
        //YYABORT;
    }
#line 2288 "src/parser/parser.c"
    break;

  case 70: /* basic-type: T_INTEGER  */
#line 761 "src/parser/parser.y"
             {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_INTEGER);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2302 "src/parser/parser.c"
    break;

  case 71: /* basic-type: T_BOOLEAN  */
#line 770 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_BOOLEAN);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2316 "src/parser/parser.c"
    break;

  case 72: /* basic-type: T_CHAR  */
#line 779 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_CHAR);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2330 "src/parser/parser.c"
    break;

  case 73: /* basic-type: T_STRING  */
#line 788 "src/parser/parser.y"
              {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_STRING);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2344 "src/parser/parser.c"
    break;

  case 74: /* basic-type: T_REAL  */
#line 797 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_REAL);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2358 "src/parser/parser.c"
    break;

  case 75: /* special-type: T_SEMAPHORE  */
#line 809 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.type) = create_semaphore_type();
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2372 "src/parser/parser.c"
    break;

  case 76: /* special-type: T_DPROCESS  */
#line 818 "src/parser/parser.y"
                {
        if(!have_syntax_errors()){
            (yyval.type) = create_dprocess_type();
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2386 "src/parser/parser.c"
    break;

  case 77: /* block-statements-begin-end: B_BEGIN list-statements B_END  */
#line 834 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2400 "src/parser/parser.c"
    break;

  case 78: /* block-statements-begin-end: B_BEGIN B_END  */
#line 844 "src/parser/parser.y"
                   {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2409 "src/parser/parser.c"
    break;

  case 79: /* block-statements-begin-end: B_BEGIN error  */
#line 848 "src/parser/parser.y"
                   {
        mark_error_syntax_program_unexpected_literal();
        YYABORT;
    }
#line 2418 "src/parser/parser.c"
    break;

  case 80: /* block-statements-cobegin-coend: B_COBEGIN list-statements B_COEND  */
#line 856 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_cobegin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2432 "src/parser/parser.c"
    break;

  case 81: /* block-statements-cobegin-coend: B_COBEGIN B_COEND  */
#line 866 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2441 "src/parser/parser.c"
    break;

  case 82: /* block-statements-atomic: ATOM_INI list-statements ATOM_FIN  */
#line 874 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_atomic((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2455 "src/parser/parser.c"
    break;

  case 83: /* block-statements-atomic: ATOM_INI ATOM_FIN  */
#line 884 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2464 "src/parser/parser.c"
    break;

  case 84: /* block-statements-function: B_BEGIN list-statements return-statement B_END  */
#line 892 "src/parser/parser.y"
                                                  {
        if(!have_syntax_errors()){
            struct statement * current_stmt = (yyvsp[-2].stmt);
            while(current_stmt->next)
                current_stmt = current_stmt->next;
            current_stmt->next = (yyvsp[-1].stmt);

            (yyval.stmt) = create_statement_block_begin((yyvsp[-2].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2483 "src/parser/parser.c"
    break;

  case 85: /* block-statements-function: B_BEGIN return-statement B_END  */
#line 907 "src/parser/parser.y"
                                    {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2497 "src/parser/parser.c"
    break;

  case 86: /* block-statements-function: B_BEGIN list-statements B_END  */
#line 917 "src/parser/parser.y"
                                   {
        mark_error_syntax_statement_non_return_in_block();
        //YYABORT;
    }
#line 2506 "src/parser/parser.c"
    break;

  case 87: /* list-statements: statement  */
#line 924 "src/parser/parser.y"
             {
        if(!have_syntax_errors()){
            (yyval.stmt) = (yyvsp[0].stmt);
        }
        else{
            (yyval.stmt) = 0;
        }
        
    }
#line 2520 "src/parser/parser.c"
    break;

  case 88: /* list-statements: statement list-statements  */
#line 933 "src/parser/parser.y"
                               {
        if(!have_syntax_errors()){
            (yyval.stmt) = (yyvsp[-1].stmt);
            (yyvsp[-1].stmt)->next = (yyvsp[0].stmt);
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2534 "src/parser/parser.c"
    break;

  case 89: /* statement: assignment-statement  */
#line 945 "src/parser/parser.y"
                        {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2542 "src/parser/parser.c"
    break;

  case 90: /* statement: while-statement  */
#line 948 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2550 "src/parser/parser.c"
    break;

  case 91: /* statement: for-statement  */
#line 951 "src/parser/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2558 "src/parser/parser.c"
    break;

  case 92: /* statement: if-statement  */
#line 954 "src/parser/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2566 "src/parser/parser.c"
    break;

  case 93: /* statement: procedure-call-statement  */
#line 957 "src/parser/parser.y"
                              {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2574 "src/parser/parser.c"
    break;

  case 94: /* statement: fork-statement  */
#line 960 "src/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2582 "src/parser/parser.c"
    break;

  case 95: /* statement: join-statement  */
#line 963 "src/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2590 "src/parser/parser.c"
    break;

  case 96: /* statement: sleep-statement  */
#line 966 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2598 "src/parser/parser.c"
    break;

  case 97: /* statement: print-statement  */
#line 969 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2606 "src/parser/parser.c"
    break;

  case 98: /* statement: sem-wait-statement  */
#line 972 "src/parser/parser.y"
                        {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2614 "src/parser/parser.c"
    break;

  case 99: /* statement: sem-signal-statement  */
#line 975 "src/parser/parser.y"
                          {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2622 "src/parser/parser.c"
    break;

  case 100: /* statement: block-statements-atomic  */
#line 978 "src/parser/parser.y"
                             {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2630 "src/parser/parser.c"
    break;

  case 101: /* statement: block-statements-cobegin-coend  */
#line 981 "src/parser/parser.y"
                                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2638 "src/parser/parser.c"
    break;

  case 102: /* assignment-statement: IDENT OP_ASSIGN expression DELIM_PC  */
#line 988 "src/parser/parser.y"
                                       {
        // -- Creacion de nodo STATEMENT (ASSIGNMENT)
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_assignment((yyvsp[-3].ident), 0, (yyvsp[-1].expr), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2653 "src/parser/parser.c"
    break;

  case 103: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression DELIM_PC  */
#line 999 "src/parser/parser.y"
                                                                          {
        // -- Creacion de nodo STATEMENT (ASSIGNMENT)
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_assignment((yyvsp[-6].ident), (yyvsp[-4].expr), (yyvsp[-1].expr), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2668 "src/parser/parser.c"
    break;

  case 104: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO  */
#line 1010 "src/parser/parser.y"
                                            {
        mark_error_syntax_statement_expected_statement();
        //YYABORT;
    }
#line 2677 "src/parser/parser.c"
    break;

  case 105: /* assignment-statement: IDENT OP_ASSIGN expression  */
#line 1015 "src/parser/parser.y"
                                {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2686 "src/parser/parser.c"
    break;

  case 106: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression  */
#line 1020 "src/parser/parser.y"
                                                                 {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2695 "src/parser/parser.c"
    break;

  case 107: /* while-statement: WHILE expression DO block-statements-begin-end  */
#line 1028 "src/parser/parser.y"
                                                  {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_while((yyvsp[-2].expr), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2709 "src/parser/parser.c"
    break;

  case 108: /* for-statement: FOR IDENT OP_ASSIGN expression TO expression DO block-statements-begin-end  */
#line 1041 "src/parser/parser.y"
                                                                              {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_for((yyvsp[-6].ident), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2723 "src/parser/parser.c"
    break;

  case 109: /* if-statement: IF expression THEN block-statements-begin-end  */
#line 1055 "src/parser/parser.y"
                                                 {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_if_else((yyvsp[-2].expr), (yyvsp[0].stmt), 0, yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2737 "src/parser/parser.c"
    break;

  case 110: /* if-statement: IF expression THEN block-statements-begin-end ELSE block-statements-begin-end  */
#line 1065 "src/parser/parser.y"
                                                                                   {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_if_else((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2751 "src/parser/parser.c"
    break;

  case 111: /* fork-statement: S_FORK IDENT DELIM_PC  */
#line 1078 "src/parser/parser.y"
                         {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_fork((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2765 "src/parser/parser.c"
    break;

  case 112: /* fork-statement: S_FORK IDENT  */
#line 1088 "src/parser/parser.y"
                  {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2774 "src/parser/parser.c"
    break;

  case 113: /* join-statement: JOIN DELIM_PC  */
#line 1096 "src/parser/parser.y"
                 {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_join(yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2788 "src/parser/parser.c"
    break;

  case 114: /* join-statement: JOIN  */
#line 1106 "src/parser/parser.y"
          {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2797 "src/parser/parser.c"
    break;

  case 115: /* sleep-statement: SLEEP expression DELIM_PC  */
#line 1114 "src/parser/parser.y"
                             {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_sleep((yyvsp[-1].expr),yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2811 "src/parser/parser.c"
    break;

  case 116: /* sleep-statement: SLEEP expression  */
#line 1124 "src/parser/parser.y"
                      {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2820 "src/parser/parser.c"
    break;

  case 117: /* return-statement: RETURN expression DELIM_PC  */
#line 1132 "src/parser/parser.y"
                              {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_return((yyvsp[-1].expr), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2834 "src/parser/parser.c"
    break;

  case 118: /* return-statement: RETURN expression  */
#line 1142 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2843 "src/parser/parser.c"
    break;

  case 119: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO DELIM_PC  */
#line 1150 "src/parser/parser.y"
                                               {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_print((yyvsp[-2].expr));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2857 "src/parser/parser.c"
    break;

  case 120: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO  */
#line 1160 "src/parser/parser.y"
                                        {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2866 "src/parser/parser.c"
    break;

  case 121: /* list-print: expression DELIM_C list-print  */
#line 1167 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[-2].expr);
            (yyvsp[-2].expr)->next = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2880 "src/parser/parser.c"
    break;

  case 122: /* list-print: expression  */
#line 1176 "src/parser/parser.y"
                {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2893 "src/parser/parser.c"
    break;

  case 123: /* sem-wait-statement: SEM_WAIT IDENT DELIM_PC  */
#line 1187 "src/parser/parser.y"
                           {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_sem_wait((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2907 "src/parser/parser.c"
    break;

  case 124: /* sem-signal-statement: SEM_SIGNAL IDENT DELIM_PC  */
#line 1199 "src/parser/parser.y"
                             {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_sem_signal((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2921 "src/parser/parser.c"
    break;

  case 125: /* procedure-call-statement: IDENT PAR_IZDO list-arguments PAR_DCHO DELIM_PC  */
#line 1212 "src/parser/parser.y"
                                                   {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_procedure_inv((yyvsp[-4].ident), (yyvsp[-2].expr), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2935 "src/parser/parser.c"
    break;

  case 126: /* procedure-call-statement: IDENT PAR_IZDO PAR_DCHO DELIM_PC  */
#line 1222 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_procedure_inv((yyvsp[-3].ident), 0, yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2949 "src/parser/parser.c"
    break;

  case 127: /* expression: binary-expression  */
#line 1237 "src/parser/parser.y"
                     {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2957 "src/parser/parser.c"
    break;

  case 128: /* expression: unary-expression  */
#line 1240 "src/parser/parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2965 "src/parser/parser.c"
    break;

  case 129: /* expression: term  */
#line 1243 "src/parser/parser.y"
          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2973 "src/parser/parser.c"
    break;

  case 130: /* expression: error  */
#line 1246 "src/parser/parser.y"
            {
        mark_error_syntax_expression_expected_expr();
        YYABORT;
    }
#line 2982 "src/parser/parser.c"
    break;

  case 131: /* binary-expression: expression OP_SUM expression  */
#line 1254 "src/parser/parser.y"
                                {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_ADD, "+", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2996 "src/parser/parser.c"
    break;

  case 132: /* binary-expression: expression OP_MINUS expression  */
#line 1264 "src/parser/parser.y"
                                    {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_SUB, "-", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3010 "src/parser/parser.c"
    break;

  case 133: /* binary-expression: expression OP_MULT expression  */
#line 1274 "src/parser/parser.y"
                                   {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_MULT, "*", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3024 "src/parser/parser.c"
    break;

  case 134: /* binary-expression: expression OP_DIV expression  */
#line 1284 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_DIV, "/", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3038 "src/parser/parser.c"
    break;

  case 135: /* binary-expression: expression OP_MOD expression  */
#line 1294 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_MOD, "%", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3052 "src/parser/parser.c"
    break;

  case 136: /* binary-expression: expression OP_REL_LT expression  */
#line 1304 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_LT, "<", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3066 "src/parser/parser.c"
    break;

  case 137: /* binary-expression: expression OP_REL_LTE expression  */
#line 1314 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_LTE, "<=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3080 "src/parser/parser.c"
    break;

  case 138: /* binary-expression: expression OP_REL_GT expression  */
#line 1324 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_GT, ">", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3094 "src/parser/parser.c"
    break;

  case 139: /* binary-expression: expression OP_REL_GTE expression  */
#line 1334 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_GTE, ">=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3108 "src/parser/parser.c"
    break;

  case 140: /* binary-expression: expression OP_REL_EQ expression  */
#line 1344 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_EQ, "==", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3122 "src/parser/parser.c"
    break;

  case 141: /* binary-expression: expression OP_REL_NEQ expression  */
#line 1354 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_NEQ, "!=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
       
    }
#line 3137 "src/parser/parser.c"
    break;

  case 142: /* binary-expression: expression OP_AND expression  */
#line 1365 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_AND, "and", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3151 "src/parser/parser.c"
    break;

  case 143: /* binary-expression: expression OP_OR expression  */
#line 1375 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_OR, "or", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3165 "src/parser/parser.c"
    break;

  case 144: /* unary-expression: OP_NOT term  */
#line 1388 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_unary_operation(EXPR_NOT, "not", (yyvsp[0].expr),yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3179 "src/parser/parser.c"
    break;

  case 145: /* unary-expression: OP_MINUS term  */
#line 1398 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_unary_operation(EXPR_NEGATIVE, "-", (yyvsp[0].expr),yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3193 "src/parser/parser.c"
    break;

  case 146: /* term: expr-identifier  */
#line 1410 "src/parser/parser.y"
                   {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3201 "src/parser/parser.c"
    break;

  case 147: /* term: literal  */
#line 1413 "src/parser/parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3209 "src/parser/parser.c"
    break;

  case 148: /* term: function-call-expression  */
#line 1416 "src/parser/parser.y"
                              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3217 "src/parser/parser.c"
    break;

  case 149: /* term: PAR_IZDO expression PAR_DCHO  */
#line 1419 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_grouped((yyvsp[-1].expr));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3231 "src/parser/parser.c"
    break;

  case 150: /* literal: LITERAL  */
#line 1432 "src/parser/parser.y"
           {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_string((yyvsp[0].literal_string));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3245 "src/parser/parser.c"
    break;

  case 151: /* literal: L_INTEGER  */
#line 1441 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_integer((yyvsp[0].literal_int));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3259 "src/parser/parser.c"
    break;

  case 152: /* literal: L_BOOLEAN_TRUE  */
#line 1450 "src/parser/parser.y"
                    {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_boolean(1);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3273 "src/parser/parser.c"
    break;

  case 153: /* literal: L_BOOLEAN_FALSE  */
#line 1459 "src/parser/parser.y"
                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_boolean(0);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3287 "src/parser/parser.c"
    break;

  case 154: /* literal: L_CHAR  */
#line 1468 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_char((yyvsp[0].literal_char));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3301 "src/parser/parser.c"
    break;

  case 155: /* literal: L_REAL  */
#line 1477 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_real((yyvsp[0].literal_float));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3315 "src/parser/parser.c"
    break;

  case 156: /* expr-identifier: IDENT  */
#line 1489 "src/parser/parser.y"
         {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_identifier((yyvsp[0].ident),0, yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3329 "src/parser/parser.c"
    break;

  case 157: /* expr-identifier: IDENT CORCH_IZDO expression CORCH_DCHO  */
#line 1498 "src/parser/parser.y"
                                            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_identifier((yyvsp[-3].ident), (yyvsp[-1].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3343 "src/parser/parser.c"
    break;

  case 158: /* function-call-expression: IDENT PAR_IZDO list-arguments PAR_DCHO  */
#line 1511 "src/parser/parser.y"
                                          {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_function_invocation((yyvsp[-3].ident), (yyvsp[-1].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3357 "src/parser/parser.c"
    break;

  case 159: /* function-call-expression: IDENT PAR_IZDO PAR_DCHO  */
#line 1521 "src/parser/parser.y"
                             {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_function_invocation((yyvsp[-2].ident), 0, yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }

    }
#line 3372 "src/parser/parser.c"
    break;

  case 160: /* list-arguments: argument DELIM_C list-arguments  */
#line 1537 "src/parser/parser.y"
                                   {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[-2].expr);
            (yyvsp[-2].expr)->next = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3386 "src/parser/parser.c"
    break;

  case 161: /* list-arguments: argument  */
#line 1546 "src/parser/parser.y"
              {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3399 "src/parser/parser.c"
    break;

  case 162: /* argument: expression  */
#line 1557 "src/parser/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3407 "src/parser/parser.c"
    break;


#line 3411 "src/parser/parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1562 "src/parser/parser.y"


// Soporte de las rutinas en C


void yyerror(const char *s) {
    if(strcmp(s, "syntax error") != 0)
        fprintf(stderr, "--- Error de sintaxis en la línea %d -> %s\n", yylineno, s);
}


int have_syntax_errors(){
    return get_total_error_syntax() > 0;
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (DECLARACIONES)

void mark_error_syntax_declaration_expected_var(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_DECLARATION, id, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_VAR_TOKEN_MSG);
}  

void mark_error_syntax_declaration_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_DECLARATION, "unknown", yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_IDENTIFIER_AFTER_VAR_MSG);
}

void mark_error_syntax_declaration_expected_delim2p(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_DECLARATION, id, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_DELIM2P_TOKEN_MSG);
}

void mark_error_syntax_declaration_expected_opassign(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_DECLARATION, id, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_OPASSIGN_TOKEN_MSG);
}

void mark_error_syntax_declaration_expected_delimpc(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_DECLARATION, id, yylineno-1, ERR_SYNTAX_DECLARATION_EXPECTED_DELIMPC_DECL_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (SUBPROGRAMAS)

void mark_error_syntax_subprogram_expected_procedure(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCEDURE, id, yylineno, ERR_SYNTAX_PROCEDURE_EXPECTED_PROCEDURE_TOKEN_MSG);
}

void mark_error_syntax_subprogram_procedure_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_PROCEDURE, "unknown", yylineno, ERR_SYNTAX_PROCEDURE_EXPECTED_IDENTIFIER_AFTER_PROCEDURE_MSG);
}

void mark_error_syntax_subprogram_procedure_expected_parameters(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCEDURE, id, yylineno, ERR_SYNTAX_PROCEDURE_EXPECTED_PARAMETERS_MSG);
}

void mark_error_syntax_subprogram_procedure_expected_delimpc(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCEDURE, id, yylineno, ERR_SYNTAX_SUBPROGRAM_EXPECTED_DELIMPC_TOKEN_MSG);
}

void mark_error_syntax_subprogram_function_expected_function(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_FUNCTION, id, yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_FUNCTION_TOKEN_MSG);
}

void mark_error_syntax_subprogram_function_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_FUNCTION, "unknown", yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_IDENTIFIER_AFTER_FUNCTION_MSG);
}

void mark_error_syntax_subprogram_function_expected_parameters(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_FUNCTION, id, yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_PARAMETERS_MSG);
}

void mark_error_syntax_subprogram_function_expected_delim2p(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_FUNCTION, id, yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_DELIM2P_TOKEN_MSG);
}

void mark_error_syntax_subprogram_function_expected_delimpc(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_FUNCTION, id, yylineno, ERR_SYNTAX_SUBPROGRAM_EXPECTED_DELIMPC_TOKEN_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (TIPOS)

void mark_error_syntax_type_expected_type(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_TYPE, "unknown", yylineno, ERR_SYNTAX_TYPE_EXPECTED_TYPE_TOKEN_MSG);
}


// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (PARAMETROS)

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (SENTENCIAS)

void mark_error_syntax_statement_expected_statement(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno, ERR_SYNTAX_STATEMENT_EXPECTED_STATEMENT_MSG);
}

void mark_error_syntax_statement_empty_block(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno, ERR_SYNTAX_STATEMENT_EXPECTED_NON_EMPTY_BLOCK_MSG);
}

void mark_error_syntax_statement_non_return_in_block(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno, ERR_SYNTAX_STATEMENT_EXPECTED_RETURN_STATEMENT_MSG);
}

void mark_error_syntax_statement_expected_delimpc(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno-1, ERR_SYNTAX_STATEMENT_EXPECTED_DELIMPC_MSG);
}

void mark_error_syntax_statement_while_expected_while(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno, ERR_SYNTAX_STATEMENT_WHILE_EXPECTED_WHILE_MSG);
}

void mark_error_syntax_statement_while_expected_do(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno, ERR_SYNTAX_STATEMENT_WHILE_EXPECTED_DO_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (EXPRESIONES)

void mark_error_syntax_expression_expected_expr(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_EXPRESSION, "unknown", yylineno, ERR_SYNTAX_EXPRESSION_EXPECTED_EXPRESSION_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (PROCESOS)

void mark_error_syntax_process_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_PROCESS, "unknown", yylineno, ERR_SYNTAX_PROCESS_EXPECTED_IDENTIFIER_AFTER_PROCESS_MSG);
}

void mark_error_syntax_process_expected_delimpc(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCESS, id, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_DELIMPC_MSG);
}

void mark_error_syntax_process_expected_index_identifier(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCESS, id, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_IDENTIFIER_INDEXER_MSG);
}

void mark_error_syntax_process_expected_delim2p(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCESS, id, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_DELIM2P_MSG);
}

void mark_error_syntax_process_expected_delimarr(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROCESS, id, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_DELIMARR_MSG);
}

// ----/////----------------------------------------------------------
// FUNCIONES DE MANEJO DE ERRORES (PROGRAMAS)

void mark_error_syntax_program_expected_program(char *id){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_PROGRAM, id, yylineno, ERR_SYNTAX_PROGRAM_EXPECTED_PROGRAM_TOKEN_MSG);
}

void mark_error_syntax_program_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_PROGRAM, "unknown", yylineno, ERR_SYNTAX_PROGRAM_EXPECTED_IDENTIFIER_AFTER_PROGRAM_MSG);
}

void mark_error_syntax_program_unexpected_literal_in_header(){
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_PROGRAM, "unknown", yylineno-1, ERR_PROGRAM_UNEXPECTED_TOKEN_IN_HEADER);
}

void mark_error_syntax_program_unexpected_literal_in_decl(char * id){
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_DECLARATION, id, yylineno-1, ERR_PROGRAM_UNEXPECTED_TOKEN_IN_DECL);
}

void mark_error_syntax_program_unexpected_literal(){
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IN_STATEMENT, "unknown", yylineno-1, ERR_PROGRAM_UNEXPECTED_TOKEN);
}

void mark_error_syntax_program_unexpected_literal_in_proc(char *id){
    create_and_add_error_syntax_to_list(ERR_SYNTAX_IDENT_IN_PROCESS, id, yylineno-1, ERR_PROGRAM_UNEXPECTED_TOKEN_IN_PROC);
}
