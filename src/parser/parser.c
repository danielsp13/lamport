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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   851

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  346

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
       0,   242,   242,   248,   254,   262,   271,   280,   287,   297,
     307,   313,   318,   323,   328,   334,   339,   349,   358,   364,
     367,   374,   385,   397,   402,   409,   414,   420,   428,   435,
     457,   479,   484,   489,   494,   499,   504,   510,   518,   527,
     536,   548,   562,   571,   579,   591,   594,   601,   613,   618,
     626,   637,   642,   647,   654,   663,   666,   669,   676,   679,
     689,   696,   705,   714,   723,   732,   744,   753,   769,   779,
     787,   797,   805,   815,   823,   838,   848,   855,   864,   876,
     879,   882,   885,   888,   891,   894,   897,   900,   903,   906,
     909,   912,   915,   922,   933,   944,   949,   954,   962,   975,
     989,   999,  1012,  1022,  1030,  1040,  1048,  1058,  1066,  1076,
    1084,  1094,  1101,  1110,  1121,  1133,  1146,  1156,  1171,  1174,
    1177,  1180,  1188,  1198,  1208,  1218,  1228,  1238,  1248,  1258,
    1268,  1278,  1288,  1299,  1309,  1322,  1332,  1344,  1347,  1350,
    1353,  1366,  1375,  1384,  1393,  1402,  1411,  1423,  1432,  1445,
    1455,  1471,  1480,  1491
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

#define YYPACT_NINF (-199)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-78)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,     7,  -199,    30,    61,    61,    61,  -199,    13,   -25,
      80,    61,    80,    80,   -17,     2,   817,    20,    21,    36,
      80,  -199,  -199,  -199,    36,    36,  -199,    32,   108,  -199,
    -199,  -199,  -199,  -199,  -199,    44,  -199,  -199,    47,  -199,
    -199,  -199,    55,  -199,    83,    97,  -199,   101,    24,  -199,
      36,  -199,  -199,  -199,  -199,  -199,  -199,  -199,   360,   437,
    -199,   -21,    58,     4,    70,    65,  -199,     1,  -199,   445,
      56,  -199,  -199,  -199,  -199,  -199,  -199,   437,   475,   475,
     437,  -199,   530,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
     649,  -199,   102,   113,   115,   106,   116,     6,   127,   126,
     145,   151,   306,   152,    61,    63,    61,   184,   388,   437,
     331,  -199,  -199,   739,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,  -199,   236,    61,
     153,   172,   817,   154,    61,   184,     9,   318,   155,   156,
     318,   162,   328,   184,   160,     3,   184,   228,  -199,  -199,
     755,   167,   150,   667,  -199,  -199,  -199,   354,   354,   354,
     354,   803,   803,   149,   149,  -199,  -199,  -199,   792,   769,
    -199,   184,    61,  -199,  -199,    61,   184,  -199,    61,   184,
     166,   318,   318,    11,    61,   318,   169,  -199,   173,   181,
     437,  -199,   184,  -199,   256,   194,   180,   437,   437,   208,
      84,   279,   187,   218,   222,   437,  -199,  -199,   235,   124,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,   437,  -199,  -199,   184,   184,  -199,   184,  -199,
      61,   202,   205,    61,   246,   246,    40,    61,    61,   207,
     309,  -199,  -199,   245,   210,  -199,   452,   474,   231,   437,
     412,   437,  -199,   209,   437,   212,   215,   550,  -199,  -199,
    -199,  -199,  -199,  -199,   246,    61,    61,   246,   111,  -199,
    -199,    61,   246,   246,   184,    61,   437,   437,  -199,  -199,
     184,   184,   437,   570,   217,   230,   685,  -199,   237,   630,
    -199,  -199,  -199,  -199,   246,   246,  -199,   437,   110,   263,
     246,  -199,  -199,  -199,   184,   703,   721,   270,  -199,   516,
    -199,  -199,   239,   251,   240,   437,  -199,  -199,   590,  -199,
     281,  -199,  -199,  -199,   247,   249,   184,   437,  -199,   437,
    -199,  -199,  -199,  -199,    61,    61,  -199,   496,   610,   184,
     184,   184,  -199,  -199,  -199,  -199
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     5,     0,     7,     7,     7,     1,     0,     0,
      18,     7,    18,    18,     0,     0,     0,     0,     0,     0,
      18,    19,    20,     6,     0,     0,    11,     0,     0,    57,
      61,    62,    63,    64,    65,     0,    66,    67,     0,    55,
      58,    56,     0,    28,     0,     0,    38,     0,     0,     3,
      43,    45,    46,    17,     4,     2,    12,    13,     0,     0,
      10,     0,     0,     0,     0,     0,    54,     7,    44,   121,
     147,   141,   142,   146,   143,   144,   145,     0,     0,     0,
       0,     9,     0,   118,   119,   120,   138,   137,   139,   121,
       0,    42,     0,     0,    40,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     7,     0,     7,     0,     0,     0,
       0,   136,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    60,     7,
       0,     0,     0,     0,     7,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,   150,
     153,     0,   152,     0,    16,     8,   140,   127,   129,   128,
     130,   131,   132,   122,   123,   124,   125,   126,   133,   134,
      59,     0,     7,    39,    41,     7,     0,    27,     7,     0,
       0,     0,     0,     7,     7,     0,     0,    48,     0,     0,
       0,    47,     0,    69,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    90,     0,     0,
      79,    80,    81,    82,    84,    85,    86,    87,    88,    89,
      83,   149,     0,   148,    24,     0,     0,    22,     0,    26,
       7,     0,     0,     7,     0,     0,     7,     7,     7,     0,
       0,    92,    71,     0,   103,   104,     0,     0,     0,     0,
       0,     0,    73,     0,     0,     0,     0,   107,    68,    78,
     151,    23,    25,    21,     0,     7,     7,     0,     0,    37,
      35,     7,     0,     0,     0,     7,     0,     0,    70,   102,
       0,     0,     0,    96,     0,     0,     0,    72,     0,   113,
     114,   115,   106,    32,     0,     0,    30,     0,     0,     0,
       0,    36,    34,    51,     0,     0,     0,   100,    98,     0,
      93,   117,     0,    95,   111,     0,    31,    33,   109,    76,
       0,    75,    29,    52,     0,     0,     0,     0,   116,     0,
     110,   112,   108,    74,     7,     7,   101,     0,    97,     0,
       0,     0,    94,    53,    50,    99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -199,  -199,   302,    -5,  -199,   148,  -199,  -199,  -199,  -199,
    -199,   -35,  -199,  -199,   158,  -199,  -199,  -199,  -199,   -26,
     -95,   190,  -199,  -123,  -199,  -199,   -73,  -183,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,    10,  -199,    31,  -199,
    -199,  -199,   -42,  -199,  -199,   114,  -199,  -199,  -199,  -198,
    -199
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    10,    11,    19,    20,    21,    44,    22,
      47,    93,    94,    95,    49,    50,    51,    52,    67,    38,
      39,    40,    41,   148,   206,   207,   269,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   299,   217,   288,   218,
     219,   220,   150,    83,    84,    85,    86,    87,    88,   151,
     152
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    13,    58,    27,   189,     8,    23,   141,     5,    91,
       8,   243,   177,     8,    14,     8,    82,    90,   253,     1,
     187,    42,    45,   191,   260,    65,   259,    98,   100,   103,
       7,     9,    92,    16,    91,   110,     9,     2,   113,     9,
      26,     9,   180,    15,     8,   183,     2,   186,   224,    48,
      43,    46,   285,   227,    66,   105,   229,    99,   106,    96,
      28,   190,   107,   134,   144,     8,   178,   153,   233,   241,
       9,   101,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   298,   231,   232,    91,    56,
     236,     9,   135,   145,    17,    18,   173,   271,    59,   143,
      91,   146,   261,   262,    60,   263,   174,    61,   108,    29,
     109,    97,   192,    30,    31,    32,    33,    34,    35,    36,
      37,   249,   104,   102,   171,   192,   297,   297,   319,   176,
     194,   179,   195,   196,   197,    62,   250,   198,   251,   199,
     -77,   200,   -77,   194,   -77,   195,   196,   197,   240,    63,
     198,   303,   199,    64,   200,   246,   247,   307,   308,   129,
      24,    25,   270,   257,   132,    57,   130,   225,    53,   133,
     226,   131,   201,   228,   202,   203,   204,   205,   234,   235,
     136,   323,    54,    55,   137,   201,   -77,   202,   203,   204,
     205,   293,   111,   112,   296,   122,   123,   124,   138,   301,
     302,   147,    91,   336,   139,   142,   222,   283,    68,   286,
     172,   175,   289,   181,   182,   188,   343,   344,   345,   184,
     221,   316,   317,   230,   244,   264,   237,   322,   267,   192,
     238,   272,   273,   274,   305,   306,   239,   245,   248,   254,
     309,    30,    31,    32,    33,    34,   193,   194,   255,   195,
     196,   197,   256,   258,   198,   318,   199,   192,   200,   265,
     294,   295,   266,   268,   275,   278,   300,   279,   282,   290,
     304,   287,   291,   289,   311,   194,   242,   195,   196,   197,
     192,   321,   198,   312,   199,   337,   200,   338,   329,   201,
     314,   202,   203,   204,   205,   326,   328,   330,   194,   333,
     195,   196,   197,     6,   334,   198,   335,   199,   320,   200,
     276,    30,    31,    32,    33,    34,    35,   201,   170,   202,
     203,   204,   205,    30,    31,    32,    33,    34,    35,   339,
     340,     0,   154,    30,    31,    32,    33,    34,    35,     0,
     201,   252,   202,   203,   204,   205,   331,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
     126,    69,     0,     0,   140,     0,     0,     0,   277,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,   126,     0,     0,     0,   185,     0,   155,    89,
      70,    71,    72,    73,    74,    75,    76,    77,   120,   121,
     122,   123,   124,     0,     0,    78,     0,     0,     0,    79,
       0,     0,    80,    89,     0,     0,     0,    81,    70,    71,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,    79,    89,     0,
      80,   149,    70,    71,    72,    73,    74,    75,    76,   -14,
       0,     0,     0,     0,     0,     0,     0,    78,   -14,   -14,
     -14,    79,   -14,     0,    80,   284,     0,    70,    71,    72,
      73,    74,    75,    76,     0,   -14,   280,     0,     0,     0,
       0,     0,    78,     0,     0,     0,    79,     0,     0,    80,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   281,   125,   126,     0,    70,    71,    72,    73,    74,
      75,    76,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   341,   125,   126,     0,    80,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   327,   125,   126,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,   126,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,     0,     0,     0,     0,     0,   127,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,     0,     0,     0,     0,     0,   292,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,     0,     0,     0,     0,     0,   310,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,     0,     0,     0,     0,     0,   332,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,     0,     0,     0,     0,     0,   342,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,     0,     0,     0,     0,   315,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
     126,     0,     0,     0,   128,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,   126,     0,
       0,     0,   223,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,   126,     0,     0,     0,
     313,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,     0,     0,     0,   324,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,   126,     0,     0,     0,   325,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
     126,     0,   156,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,   126,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    29,   125,
       0,     0,    30,    31,    32,    33,    34,    35,    36,    37,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   114,   115,   116,   117,     0,     0,   120,   121,   122,
     123,   124
};

static const yytype_int16 yycheck[] =
{
       5,     6,    28,     1,     1,     4,    11,   102,     1,    30,
       4,   194,   135,     4,     1,     4,    58,    59,   201,     3,
     143,     1,     1,   146,   222,     1,   209,    62,    63,    64,
       0,    30,    53,    58,    30,    77,    30,    30,    80,    30,
      57,    30,   137,    30,     4,   140,    30,   142,   171,    13,
      30,    30,   250,   176,    30,    54,   179,    53,    57,     1,
      58,    58,    67,    57,     1,     4,    57,   109,    57,   192,
      30,     1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   268,   181,   182,    30,    57,
     185,    30,    97,    30,    14,    15,   131,    57,    54,   104,
      30,   106,   225,   226,    57,   228,   132,    52,    52,     1,
      54,    53,     1,     5,     6,     7,     8,     9,    10,    11,
      12,    37,    57,    53,   129,     1,    16,    16,    18,   134,
      19,   136,    21,    22,    23,    52,    52,    26,    54,    28,
      16,    30,    18,    19,    20,    21,    22,    23,   190,    52,
      26,   274,    28,    52,    30,   197,   198,   280,   281,    57,
      12,    13,   235,   205,    58,    57,    53,   172,    20,    53,
     175,    56,    61,   178,    63,    64,    65,    66,   183,   184,
      53,   304,    24,    25,    58,    61,    62,    63,    64,    65,
      66,   264,    78,    79,   267,    46,    47,    48,    53,   272,
     273,    17,    30,   326,    53,    53,    56,   249,    50,   251,
      57,    57,   254,    58,    58,    55,   339,   340,   341,    57,
      53,   294,   295,    57,    30,   230,    57,   300,   233,     1,
      57,   236,   237,   238,   276,   277,    55,    57,    30,    52,
     282,     5,     6,     7,     8,     9,    18,    19,    30,    21,
      22,    23,    30,    18,    26,   297,    28,     1,    30,    57,
     265,   266,    57,    17,    57,    20,   271,    57,    37,    57,
     275,    62,    57,   315,    57,    19,    20,    21,    22,    23,
       1,    18,    26,    53,    28,   327,    30,   329,    37,    61,
      53,    63,    64,    65,    66,    25,    57,    57,    19,    18,
      21,    22,    23,     1,    57,    26,    57,    28,   298,    30,
       1,     5,     6,     7,     8,     9,    10,    61,   128,    63,
      64,    65,    66,     5,     6,     7,     8,     9,    10,   334,
     335,    -1,     1,     5,     6,     7,     8,     9,    10,    -1,
      61,    62,    63,    64,    65,    66,   315,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,     1,    -1,    -1,    58,    -1,    -1,    -1,    59,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    -1,    -1,    -1,    58,    -1,    57,     1,
      30,    31,    32,    33,    34,    35,    36,    37,    44,    45,
      46,    47,    48,    -1,    -1,    45,    -1,    -1,    -1,    49,
      -1,    -1,    52,     1,    -1,    -1,    -1,    57,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    49,     1,    -1,
      52,    53,    30,    31,    32,    33,    34,    35,    36,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    13,    14,
      15,    49,    17,    -1,    52,    53,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    30,    24,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    27,    50,    51,    -1,    30,    31,    32,    33,    34,
      35,    36,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    27,    50,    51,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    29,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    -1,    -1,    -1,    -1,    -1,    57,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    -1,    -1,    -1,    -1,    -1,    57,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    -1,    -1,    -1,    -1,    -1,    57,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    -1,    -1,    -1,    -1,    -1,    57,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    -1,    -1,    -1,    -1,    -1,    57,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    -1,    -1,    -1,    -1,    56,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    -1,    -1,    -1,    55,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    -1,
      -1,    -1,    55,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    -1,    -1,    -1,
      55,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    -1,    -1,    -1,    55,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    -1,    -1,    -1,    55,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    -1,    53,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     1,    50,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    38,    39,    40,    41,    -1,    -1,    44,    45,    46,
      47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    30,    69,    70,     1,    70,     0,     4,    30,
      71,    72,    71,    71,     1,    30,    58,    14,    15,    73,
      74,    75,    77,    71,    73,    73,    57,     1,    58,     1,
       5,     6,     7,     8,     9,    10,    11,    12,    87,    88,
      89,    90,     1,    30,    76,     1,    30,    78,    13,    82,
      83,    84,    85,    73,    82,    82,    57,    57,    87,    54,
      57,    52,    52,    52,    52,     1,    30,    86,    82,     1,
      30,    31,    32,    33,    34,    35,    36,    37,    45,    49,
      52,    57,   110,   111,   112,   113,   114,   115,   116,     1,
     110,    30,    53,    79,    80,    81,     1,    53,    79,    53,
      79,     1,    53,    79,    57,    54,    57,    71,    52,    54,
     110,   113,   113,   110,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    50,    51,    57,    55,    57,
      53,    56,    58,    53,    57,    71,    53,    58,    53,    53,
      58,    88,    53,    71,     1,    30,    71,    17,    91,    53,
     110,   117,   118,   110,     1,    57,    53,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
      89,    71,    57,    79,    87,    57,    71,    91,    57,    71,
      88,    58,    58,    88,    57,    58,    88,    91,    55,     1,
      58,    91,     1,    18,    19,    21,    22,    23,    26,    28,
      30,    61,    63,    64,    65,    66,    92,    93,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   105,   107,   108,
     109,    53,    56,    55,    91,    71,    71,    91,    71,    91,
      57,    88,    88,    57,    71,    71,    88,    57,    57,    55,
     110,    91,    20,    95,    30,    57,   110,   110,    30,    37,
      52,    54,    62,    95,    52,    30,    30,   110,    18,    95,
     117,    91,    91,    91,    71,    57,    57,    71,    17,    94,
      94,    57,    71,    71,    71,    57,     1,    59,    20,    57,
      24,    27,    37,   110,    53,   117,   110,    62,   106,   110,
      57,    57,    57,    94,    71,    71,    94,    16,    95,   104,
      71,    94,    94,    91,    71,   110,   110,    91,    91,   110,
      57,    57,    53,    55,    53,    56,    94,    94,   110,    18,
     104,    18,    94,    91,    55,    55,    25,    29,    57,    37,
      57,   106,    57,    18,    57,    57,    91,   110,   110,    71,
      71,    27,    57,    91,    91,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    69,    69,    70,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    79,
      79,    80,    81,    82,    82,    83,    83,    84,    84,    84,
      85,    85,    85,    85,    86,    87,    87,    87,    88,    88,
      88,    89,    89,    89,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    94,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    97,    97,    97,    97,    97,    98,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   108,   109,   109,   110,   110,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   112,   112,   113,   113,   113,
     113,   114,   114,   114,   114,   114,   114,   115,   115,   116,
     116,   117,   117,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     5,     1,     2,     0,     7,     5,
       4,     3,     4,     4,     5,     6,     7,     2,     0,     1,
       1,     8,     7,     8,     7,     8,     7,     6,     1,    10,
       9,    10,     9,    10,     9,     8,     9,     8,     1,     3,
       1,     3,     1,     1,     2,     1,     1,     5,     5,     4,
      12,     8,     9,    12,     1,     1,     1,     1,     1,     5,
       4,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     2,     3,     2,     4,     3,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     7,     4,     3,     6,     4,     8,
       4,     6,     3,     2,     2,     1,     3,     2,     3,     2,
       5,     4,     3,     1,     3,     3,     5,     4,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       3,     3,     1,     1
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
  case 2: /* program: S_PROGRAM program-name list-declarations list-subprograms list-process  */
#line 242 "src/parser/parser.y"
                                                                          {
        // -- Crear AST (solo si no hay errores sintacticos)
        if(!have_syntax_errors())
            AST_program = create_program((yyvsp[-3].ident),(yyvsp[-2].decl),(yyvsp[-1].subprog),(yyvsp[0].proc));
    }
#line 1564 "src/parser/parser.c"
    break;

  case 3: /* program: program-name list-declarations list-subprograms list-process  */
#line 248 "src/parser/parser.y"
                                                                  {
        mark_error_syntax_program_expected_program((yyvsp[-3].ident));
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }
#line 1574 "src/parser/parser.c"
    break;

  case 4: /* program: S_PROGRAM error list-declarations list-subprograms list-process  */
#line 254 "src/parser/parser.y"
                                                                     {
        mark_error_syntax_program_expected_identifier();
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }
#line 1584 "src/parser/parser.c"
    break;

  case 5: /* program-name: IDENT  */
#line 262 "src/parser/parser.y"
         { 
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1592 "src/parser/parser.c"
    break;

  case 6: /* list-declarations: declaration list-declarations  */
#line 271 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.decl) = (yyvsp[-1].decl);
            (yyvsp[-1].decl)->next = (yyvsp[0].decl);
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1606 "src/parser/parser.c"
    break;

  case 7: /* list-declarations: %empty  */
#line 280 "src/parser/parser.y"
                   {
        (yyval.decl) = 0;
    }
#line 1614 "src/parser/parser.c"
    break;

  case 8: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression DELIM_PC  */
#line 287 "src/parser/parser.y"
                                                           {
        if(!have_syntax_errors()){
            (yyval.decl) = create_declaration_variable((yyvsp[-5].ident), (yyvsp[-3].type), (yyvsp[-1].expr), yylineno);
            add_declaration_to_register((yyval.decl));
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1628 "src/parser/parser.c"
    break;

  case 9: /* declaration: S_VAR IDENT DELIM_2P type DELIM_PC  */
#line 297 "src/parser/parser.y"
                                        {
        if(!have_syntax_errors()){
            (yyval.decl) = create_declaration_variable((yyvsp[-3].ident), (yyvsp[-1].type), 0, yylineno);
            add_declaration_to_register((yyval.decl));
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1642 "src/parser/parser.c"
    break;

  case 10: /* declaration: IDENT DELIM_2P type DELIM_PC  */
#line 307 "src/parser/parser.y"
                                  {
        mark_error_syntax_declaration_expected_var((yyvsp[-3].ident));
        // Recuperar
        //YYABORT;
    }
#line 1652 "src/parser/parser.c"
    break;

  case 11: /* declaration: S_VAR error DELIM_PC  */
#line 313 "src/parser/parser.y"
                          {
        mark_error_syntax_declaration_expected_identifier();
        //YYABORT;
    }
#line 1661 "src/parser/parser.c"
    break;

  case 12: /* declaration: S_VAR IDENT error DELIM_PC  */
#line 318 "src/parser/parser.y"
                                {
        mark_error_syntax_declaration_expected_delim2p((yyvsp[-2].ident));
        //YYABORT;
    }
#line 1670 "src/parser/parser.c"
    break;

  case 13: /* declaration: S_VAR IDENT DELIM_2P DELIM_PC  */
#line 323 "src/parser/parser.y"
                                   {
        mark_error_syntax_type_expected_type((yyvsp[-2].ident));
        //YYABORT;
    }
#line 1679 "src/parser/parser.c"
    break;

  case 14: /* declaration: S_VAR IDENT DELIM_2P type error  */
#line 328 "src/parser/parser.y"
                                     {
        mark_error_syntax_declaration_expected_delimpc((yyvsp[-3].ident));
        free_AST_type_register((yyvsp[-1].type));
        //YYABORT;
    }
#line 1689 "src/parser/parser.c"
    break;

  case 15: /* declaration: S_VAR IDENT DELIM_2P type expression DELIM_PC  */
#line 334 "src/parser/parser.y"
                                                   {
        mark_error_syntax_declaration_expected_opassign((yyvsp[-4].ident));
        //YYABORT;
    }
#line 1698 "src/parser/parser.c"
    break;

  case 16: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression error  */
#line 339 "src/parser/parser.y"
                                                          {
        mark_error_syntax_declaration_expected_delimpc((yyvsp[-5].ident));
        //YYABORT;
    }
#line 1707 "src/parser/parser.c"
    break;

  case 17: /* list-subprograms: subprogram list-subprograms  */
#line 349 "src/parser/parser.y"
                               {
        if(!have_syntax_errors()){
            (yyval.subprog) = (yyvsp[-1].subprog);
            (yyvsp[-1].subprog)->next = (yyvsp[0].subprog);
        }
        else{
            (yyval.subprog) = 0;
        }
    }
#line 1721 "src/parser/parser.c"
    break;

  case 18: /* list-subprograms: %empty  */
#line 358 "src/parser/parser.y"
                   {
        (yyval.subprog) = 0;
    }
#line 1729 "src/parser/parser.c"
    break;

  case 19: /* subprogram: subprogram-procedure  */
#line 364 "src/parser/parser.y"
                        {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1737 "src/parser/parser.c"
    break;

  case 20: /* subprogram: subprogram-function  */
#line 367 "src/parser/parser.y"
                         {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1745 "src/parser/parser.c"
    break;

  case 21: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 374 "src/parser/parser.y"
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
#line 1760 "src/parser/parser.c"
    break;

  case 22: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 385 "src/parser/parser.y"
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
#line 1776 "src/parser/parser.c"
    break;

  case 23: /* subprogram-procedure: S_PROCEDURE error PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 397 "src/parser/parser.y"
                                                                                                               {
        mark_error_syntax_subprogram_procedure_expected_identifier();
        //YYABORT;
    }
#line 1785 "src/parser/parser.c"
    break;

  case 24: /* subprogram-procedure: S_PROCEDURE error PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 402 "src/parser/parser.y"
                                                                                               {
        // -- Mostrar error
        mark_error_syntax_subprogram_procedure_expected_identifier();
        // -- Abortar inmediatmente el analisis
        //YYABORT;
    }
#line 1796 "src/parser/parser.c"
    break;

  case 25: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO error PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 409 "src/parser/parser.y"
                                                                                                                         {
        mark_error_syntax_subprogram_procedure_expected_parameters((yyvsp[-6].ident));
        //YYABORT;
    }
#line 1805 "src/parser/parser.c"
    break;

  case 26: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO list-declarations block-statements-begin-end  */
#line 414 "src/parser/parser.y"
                                                                                                                          {
        mark_error_syntax_subprogram_procedure_expected_delimpc((yyvsp[-5].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1815 "src/parser/parser.c"
    break;

  case 27: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO list-declarations block-statements-begin-end  */
#line 420 "src/parser/parser.y"
                                                                                                          {
        mark_error_syntax_subprogram_procedure_expected_delimpc((yyvsp[-4].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1825 "src/parser/parser.c"
    break;

  case 28: /* subprogram-procedure-name: IDENT  */
#line 428 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1833 "src/parser/parser.c"
    break;

  case 29: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 435 "src/parser/parser.y"
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
#line 1859 "src/parser/parser.c"
    break;

  case 30: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 457 "src/parser/parser.y"
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
#line 1885 "src/parser/parser.c"
    break;

  case 31: /* subprogram-function: S_FUNCTION error PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 479 "src/parser/parser.y"
                                                                                                                                          {
        mark_error_syntax_subprogram_function_expected_identifier();
        //YYABORT;
    }
#line 1894 "src/parser/parser.c"
    break;

  case 32: /* subprogram-function: S_FUNCTION error PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 484 "src/parser/parser.y"
                                                                                                                          {
        mark_error_syntax_subprogram_function_expected_identifier();
        //YYABORT;
    }
#line 1903 "src/parser/parser.c"
    break;

  case 33: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO error PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 489 "src/parser/parser.y"
                                                                                                                                                   {
        mark_error_syntax_subprogram_function_expected_parameters((yyvsp[-8].ident));
        //YYABORT;
    }
#line 1912 "src/parser/parser.c"
    break;

  case 34: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 494 "src/parser/parser.y"
                                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delim2p((yyvsp[-7].ident));
        //YYABORT;
    }
#line 1921 "src/parser/parser.c"
    break;

  case 35: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 499 "src/parser/parser.y"
                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delim2p((yyvsp[-6].ident));
        //YYABORT;
    }
#line 1930 "src/parser/parser.c"
    break;

  case 36: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type list-declarations block-statements-function  */
#line 504 "src/parser/parser.y"
                                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delimpc((yyvsp[-7].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1940 "src/parser/parser.c"
    break;

  case 37: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type list-declarations block-statements-function  */
#line 510 "src/parser/parser.y"
                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delimpc((yyvsp[-6].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1950 "src/parser/parser.c"
    break;

  case 38: /* subprogram-function-name: IDENT  */
#line 518 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1958 "src/parser/parser.c"
    break;

  case 39: /* list-parameters: parameter DELIM_C list-parameters  */
#line 527 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.param) = (yyvsp[-2].param);
            (yyvsp[-2].param)->next = (yyvsp[0].param);
        }
        else{
            (yyval.param) = 0;
        }
    }
#line 1972 "src/parser/parser.c"
    break;

  case 40: /* list-parameters: parameter  */
#line 536 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.param) = (yyvsp[0].param);
        }
        else{
            (yyval.param) = 0;
        }
    }
#line 1985 "src/parser/parser.c"
    break;

  case 41: /* parameter: parameter-name DELIM_2P type  */
#line 548 "src/parser/parser.y"
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
#line 2001 "src/parser/parser.c"
    break;

  case 42: /* parameter-name: IDENT  */
#line 562 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 2009 "src/parser/parser.c"
    break;

  case 43: /* list-process: process  */
#line 571 "src/parser/parser.y"
           {
        if(!have_syntax_errors()){
            (yyval.proc) = (yyvsp[0].proc);
        }
        else{
            (yyval.proc) = 0;
        }
    }
#line 2022 "src/parser/parser.c"
    break;

  case 44: /* list-process: process list-process  */
#line 579 "src/parser/parser.y"
                          {
        if(!have_syntax_errors()){
            (yyval.proc) = (yyvsp[-1].proc);
            (yyvsp[-1].proc)->next = (yyvsp[0].proc);
        }
        else{
            (yyval.proc) = 0;
        }
    }
#line 2036 "src/parser/parser.c"
    break;

  case 45: /* process: process-def  */
#line 591 "src/parser/parser.y"
               {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 2044 "src/parser/parser.c"
    break;

  case 46: /* process: process-def-array  */
#line 594 "src/parser/parser.y"
                       {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 2052 "src/parser/parser.c"
    break;

  case 47: /* process-def: S_PROCESS process-name DELIM_PC list-declarations block-statements-begin-end  */
#line 601 "src/parser/parser.y"
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
#line 2068 "src/parser/parser.c"
    break;

  case 48: /* process-def: S_PROCESS error DELIM_PC list-declarations block-statements-begin-end  */
#line 613 "src/parser/parser.y"
                                                                           {
        mark_error_syntax_process_expected_identifier();
        //YYABORT;
    }
#line 2077 "src/parser/parser.c"
    break;

  case 49: /* process-def: S_PROCESS process-name list-declarations block-statements-begin-end  */
#line 618 "src/parser/parser.y"
                                                                         {
        mark_error_syntax_process_expected_delimpc((yyvsp[-2].ident));
        //YYABORT;
    }
#line 2086 "src/parser/parser.c"
    break;

  case 50: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 626 "src/parser/parser.y"
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
#line 2101 "src/parser/parser.c"
    break;

  case 51: /* process-def-array: S_PROCESS process-name CORCH_IZDO error CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 637 "src/parser/parser.y"
                                                                                                              {
        mark_error_syntax_process_expected_index_identifier((yyvsp[-6].ident));
        //YYABORT;
    }
#line 2110 "src/parser/parser.c"
    break;

  case 52: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT error CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 642 "src/parser/parser.y"
                                                                                                                    {
        mark_error_syntax_process_expected_delim2p((yyvsp[-7].ident));
        //YYABORT;
    }
#line 2119 "src/parser/parser.c"
    break;

  case 53: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression error expression CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 647 "src/parser/parser.y"
                                                                                                                                                   {
        mark_error_syntax_process_expected_delimarr((yyvsp[-10].ident));
        //YYABORT;
    }
#line 2128 "src/parser/parser.c"
    break;

  case 54: /* process-name: IDENT  */
#line 654 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 2136 "src/parser/parser.c"
    break;

  case 55: /* type: basic-or-array-type  */
#line 663 "src/parser/parser.y"
                       {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2144 "src/parser/parser.c"
    break;

  case 56: /* type: special-type  */
#line 666 "src/parser/parser.y"
                  {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2152 "src/parser/parser.c"
    break;

  case 57: /* type: error  */
#line 669 "src/parser/parser.y"
           {
        mark_error_syntax_type_expected_type();
        //YYABORT;
    }
#line 2161 "src/parser/parser.c"
    break;

  case 58: /* basic-or-array-type: basic-type  */
#line 676 "src/parser/parser.y"
              {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2169 "src/parser/parser.c"
    break;

  case 59: /* basic-or-array-type: T_ARRAY CORCH_IZDO expression CORCH_DCHO basic-type  */
#line 679 "src/parser/parser.y"
                                                         {
        if(!have_syntax_errors()){
            (yyval.type) = create_array_type((yyvsp[0].type),(yyvsp[-2].expr));
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2183 "src/parser/parser.c"
    break;

  case 60: /* basic-or-array-type: T_ARRAY CORCH_IZDO expression CORCH_DCHO  */
#line 689 "src/parser/parser.y"
                                              {
        mark_error_syntax_type_expected_type();
        //YYABORT;
    }
#line 2192 "src/parser/parser.c"
    break;

  case 61: /* basic-type: T_INTEGER  */
#line 696 "src/parser/parser.y"
             {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_INTEGER);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2206 "src/parser/parser.c"
    break;

  case 62: /* basic-type: T_BOOLEAN  */
#line 705 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_BOOLEAN);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2220 "src/parser/parser.c"
    break;

  case 63: /* basic-type: T_CHAR  */
#line 714 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_CHAR);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2234 "src/parser/parser.c"
    break;

  case 64: /* basic-type: T_STRING  */
#line 723 "src/parser/parser.y"
              {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_STRING);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2248 "src/parser/parser.c"
    break;

  case 65: /* basic-type: T_REAL  */
#line 732 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_REAL);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2262 "src/parser/parser.c"
    break;

  case 66: /* special-type: T_SEMAPHORE  */
#line 744 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.type) = create_semaphore_type();
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2276 "src/parser/parser.c"
    break;

  case 67: /* special-type: T_DPROCESS  */
#line 753 "src/parser/parser.y"
                {
        if(!have_syntax_errors()){
            (yyval.type) = create_dprocess_type();
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2290 "src/parser/parser.c"
    break;

  case 68: /* block-statements-begin-end: B_BEGIN list-statements B_END  */
#line 769 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2304 "src/parser/parser.c"
    break;

  case 69: /* block-statements-begin-end: B_BEGIN B_END  */
#line 779 "src/parser/parser.y"
                   {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2313 "src/parser/parser.c"
    break;

  case 70: /* block-statements-cobegin-coend: B_COBEGIN list-statements B_COEND  */
#line 787 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_cobegin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2327 "src/parser/parser.c"
    break;

  case 71: /* block-statements-cobegin-coend: B_COBEGIN B_COEND  */
#line 797 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2336 "src/parser/parser.c"
    break;

  case 72: /* block-statements-atomic: ATOM_INI list-statements ATOM_FIN  */
#line 805 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_atomic((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2350 "src/parser/parser.c"
    break;

  case 73: /* block-statements-atomic: ATOM_INI ATOM_FIN  */
#line 815 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2359 "src/parser/parser.c"
    break;

  case 74: /* block-statements-function: B_BEGIN list-statements return-statement B_END  */
#line 823 "src/parser/parser.y"
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
#line 2378 "src/parser/parser.c"
    break;

  case 75: /* block-statements-function: B_BEGIN return-statement B_END  */
#line 838 "src/parser/parser.y"
                                    {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2392 "src/parser/parser.c"
    break;

  case 76: /* block-statements-function: B_BEGIN list-statements B_END  */
#line 848 "src/parser/parser.y"
                                   {
        mark_error_syntax_statement_non_return_in_block();
        //YYABORT;
    }
#line 2401 "src/parser/parser.c"
    break;

  case 77: /* list-statements: statement  */
#line 855 "src/parser/parser.y"
             {
        if(!have_syntax_errors()){
            (yyval.stmt) = (yyvsp[0].stmt);
        }
        else{
            (yyval.stmt) = 0;
        }
        
    }
#line 2415 "src/parser/parser.c"
    break;

  case 78: /* list-statements: statement list-statements  */
#line 864 "src/parser/parser.y"
                               {
        if(!have_syntax_errors()){
            (yyval.stmt) = (yyvsp[-1].stmt);
            (yyvsp[-1].stmt)->next = (yyvsp[0].stmt);
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2429 "src/parser/parser.c"
    break;

  case 79: /* statement: assignment-statement  */
#line 876 "src/parser/parser.y"
                        {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2437 "src/parser/parser.c"
    break;

  case 80: /* statement: while-statement  */
#line 879 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2445 "src/parser/parser.c"
    break;

  case 81: /* statement: for-statement  */
#line 882 "src/parser/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2453 "src/parser/parser.c"
    break;

  case 82: /* statement: if-statement  */
#line 885 "src/parser/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2461 "src/parser/parser.c"
    break;

  case 83: /* statement: procedure-call-statement  */
#line 888 "src/parser/parser.y"
                              {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2469 "src/parser/parser.c"
    break;

  case 84: /* statement: fork-statement  */
#line 891 "src/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2477 "src/parser/parser.c"
    break;

  case 85: /* statement: join-statement  */
#line 894 "src/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2485 "src/parser/parser.c"
    break;

  case 86: /* statement: sleep-statement  */
#line 897 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2493 "src/parser/parser.c"
    break;

  case 87: /* statement: print-statement  */
#line 900 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2501 "src/parser/parser.c"
    break;

  case 88: /* statement: sem-wait-statement  */
#line 903 "src/parser/parser.y"
                        {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2509 "src/parser/parser.c"
    break;

  case 89: /* statement: sem-signal-statement  */
#line 906 "src/parser/parser.y"
                          {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2517 "src/parser/parser.c"
    break;

  case 90: /* statement: block-statements-atomic  */
#line 909 "src/parser/parser.y"
                             {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2525 "src/parser/parser.c"
    break;

  case 91: /* statement: block-statements-cobegin-coend  */
#line 912 "src/parser/parser.y"
                                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2533 "src/parser/parser.c"
    break;

  case 92: /* statement: error block-statements-begin-end  */
#line 915 "src/parser/parser.y"
                                      {
        mark_error_syntax_statement_expected_statement();
    }
#line 2541 "src/parser/parser.c"
    break;

  case 93: /* assignment-statement: IDENT OP_ASSIGN expression DELIM_PC  */
#line 922 "src/parser/parser.y"
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
#line 2556 "src/parser/parser.c"
    break;

  case 94: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression DELIM_PC  */
#line 933 "src/parser/parser.y"
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
#line 2571 "src/parser/parser.c"
    break;

  case 95: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO  */
#line 944 "src/parser/parser.y"
                                            {
        mark_error_syntax_statement_expected_statement();
        //YYABORT;
    }
#line 2580 "src/parser/parser.c"
    break;

  case 96: /* assignment-statement: IDENT OP_ASSIGN expression  */
#line 949 "src/parser/parser.y"
                                {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2589 "src/parser/parser.c"
    break;

  case 97: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression  */
#line 954 "src/parser/parser.y"
                                                                 {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2598 "src/parser/parser.c"
    break;

  case 98: /* while-statement: WHILE expression DO block-statements-begin-end  */
#line 962 "src/parser/parser.y"
                                                  {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_while((yyvsp[-2].expr), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2612 "src/parser/parser.c"
    break;

  case 99: /* for-statement: FOR IDENT OP_ASSIGN expression TO expression DO block-statements-begin-end  */
#line 975 "src/parser/parser.y"
                                                                              {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_for((yyvsp[-6].ident), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2626 "src/parser/parser.c"
    break;

  case 100: /* if-statement: IF expression THEN block-statements-begin-end  */
#line 989 "src/parser/parser.y"
                                                 {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_if_else((yyvsp[-2].expr), (yyvsp[0].stmt), 0, yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2640 "src/parser/parser.c"
    break;

  case 101: /* if-statement: IF expression THEN block-statements-begin-end ELSE block-statements-begin-end  */
#line 999 "src/parser/parser.y"
                                                                                   {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_if_else((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2654 "src/parser/parser.c"
    break;

  case 102: /* fork-statement: S_FORK IDENT DELIM_PC  */
#line 1012 "src/parser/parser.y"
                         {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_fork((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2668 "src/parser/parser.c"
    break;

  case 103: /* fork-statement: S_FORK IDENT  */
#line 1022 "src/parser/parser.y"
                  {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2677 "src/parser/parser.c"
    break;

  case 104: /* join-statement: JOIN DELIM_PC  */
#line 1030 "src/parser/parser.y"
                 {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_join(yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2691 "src/parser/parser.c"
    break;

  case 105: /* join-statement: JOIN  */
#line 1040 "src/parser/parser.y"
          {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2700 "src/parser/parser.c"
    break;

  case 106: /* sleep-statement: SLEEP expression DELIM_PC  */
#line 1048 "src/parser/parser.y"
                             {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_sleep((yyvsp[-1].expr),yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2714 "src/parser/parser.c"
    break;

  case 107: /* sleep-statement: SLEEP expression  */
#line 1058 "src/parser/parser.y"
                      {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2723 "src/parser/parser.c"
    break;

  case 108: /* return-statement: RETURN expression DELIM_PC  */
#line 1066 "src/parser/parser.y"
                              {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_return((yyvsp[-1].expr), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2737 "src/parser/parser.c"
    break;

  case 109: /* return-statement: RETURN expression  */
#line 1076 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2746 "src/parser/parser.c"
    break;

  case 110: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO DELIM_PC  */
#line 1084 "src/parser/parser.y"
                                               {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_print((yyvsp[-2].expr));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2760 "src/parser/parser.c"
    break;

  case 111: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO  */
#line 1094 "src/parser/parser.y"
                                        {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2769 "src/parser/parser.c"
    break;

  case 112: /* list-print: expression DELIM_C list-print  */
#line 1101 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[-2].expr);
            (yyvsp[-2].expr)->next = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2783 "src/parser/parser.c"
    break;

  case 113: /* list-print: expression  */
#line 1110 "src/parser/parser.y"
                {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2796 "src/parser/parser.c"
    break;

  case 114: /* sem-wait-statement: SEM_WAIT IDENT DELIM_PC  */
#line 1121 "src/parser/parser.y"
                           {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_sem_wait((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2810 "src/parser/parser.c"
    break;

  case 115: /* sem-signal-statement: SEM_SIGNAL IDENT DELIM_PC  */
#line 1133 "src/parser/parser.y"
                             {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_sem_signal((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2824 "src/parser/parser.c"
    break;

  case 116: /* procedure-call-statement: IDENT PAR_IZDO list-arguments PAR_DCHO DELIM_PC  */
#line 1146 "src/parser/parser.y"
                                                   {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_procedure_inv((yyvsp[-4].ident), (yyvsp[-2].expr), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2838 "src/parser/parser.c"
    break;

  case 117: /* procedure-call-statement: IDENT PAR_IZDO PAR_DCHO DELIM_PC  */
#line 1156 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_procedure_inv((yyvsp[-3].ident), 0, yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2852 "src/parser/parser.c"
    break;

  case 118: /* expression: binary-expression  */
#line 1171 "src/parser/parser.y"
                     {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2860 "src/parser/parser.c"
    break;

  case 119: /* expression: unary-expression  */
#line 1174 "src/parser/parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2868 "src/parser/parser.c"
    break;

  case 120: /* expression: term  */
#line 1177 "src/parser/parser.y"
          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2876 "src/parser/parser.c"
    break;

  case 121: /* expression: error  */
#line 1180 "src/parser/parser.y"
            {
        mark_error_syntax_expression_expected_expr();
        YYABORT;
    }
#line 2885 "src/parser/parser.c"
    break;

  case 122: /* binary-expression: expression OP_SUM expression  */
#line 1188 "src/parser/parser.y"
                                {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_ADD, "+", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2899 "src/parser/parser.c"
    break;

  case 123: /* binary-expression: expression OP_MINUS expression  */
#line 1198 "src/parser/parser.y"
                                    {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_SUB, "-", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2913 "src/parser/parser.c"
    break;

  case 124: /* binary-expression: expression OP_MULT expression  */
#line 1208 "src/parser/parser.y"
                                   {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_MULT, "*", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2927 "src/parser/parser.c"
    break;

  case 125: /* binary-expression: expression OP_DIV expression  */
#line 1218 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_DIV, "/", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2941 "src/parser/parser.c"
    break;

  case 126: /* binary-expression: expression OP_MOD expression  */
#line 1228 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_MOD, "%", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2955 "src/parser/parser.c"
    break;

  case 127: /* binary-expression: expression OP_REL_LT expression  */
#line 1238 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_LT, "<", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2969 "src/parser/parser.c"
    break;

  case 128: /* binary-expression: expression OP_REL_LTE expression  */
#line 1248 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_LTE, "<=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2983 "src/parser/parser.c"
    break;

  case 129: /* binary-expression: expression OP_REL_GT expression  */
#line 1258 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_GT, ">", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2997 "src/parser/parser.c"
    break;

  case 130: /* binary-expression: expression OP_REL_GTE expression  */
#line 1268 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_GTE, ">=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3011 "src/parser/parser.c"
    break;

  case 131: /* binary-expression: expression OP_REL_EQ expression  */
#line 1278 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_EQ, "==", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3025 "src/parser/parser.c"
    break;

  case 132: /* binary-expression: expression OP_REL_NEQ expression  */
#line 1288 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_NEQ, "!=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
       
    }
#line 3040 "src/parser/parser.c"
    break;

  case 133: /* binary-expression: expression OP_AND expression  */
#line 1299 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_AND, "and", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3054 "src/parser/parser.c"
    break;

  case 134: /* binary-expression: expression OP_OR expression  */
#line 1309 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_OR, "or", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3068 "src/parser/parser.c"
    break;

  case 135: /* unary-expression: OP_NOT term  */
#line 1322 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_unary_operation(EXPR_NOT, "not", (yyvsp[0].expr),yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3082 "src/parser/parser.c"
    break;

  case 136: /* unary-expression: OP_MINUS term  */
#line 1332 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_unary_operation(EXPR_NEGATIVE, "-", (yyvsp[0].expr),yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3096 "src/parser/parser.c"
    break;

  case 137: /* term: expr-identifier  */
#line 1344 "src/parser/parser.y"
                   {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3104 "src/parser/parser.c"
    break;

  case 138: /* term: literal  */
#line 1347 "src/parser/parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3112 "src/parser/parser.c"
    break;

  case 139: /* term: function-call-expression  */
#line 1350 "src/parser/parser.y"
                              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3120 "src/parser/parser.c"
    break;

  case 140: /* term: PAR_IZDO expression PAR_DCHO  */
#line 1353 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_grouped((yyvsp[-1].expr));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3134 "src/parser/parser.c"
    break;

  case 141: /* literal: LITERAL  */
#line 1366 "src/parser/parser.y"
           {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_string((yyvsp[0].literal_string));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3148 "src/parser/parser.c"
    break;

  case 142: /* literal: L_INTEGER  */
#line 1375 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_integer((yyvsp[0].literal_int));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3162 "src/parser/parser.c"
    break;

  case 143: /* literal: L_BOOLEAN_TRUE  */
#line 1384 "src/parser/parser.y"
                    {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_boolean(1);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3176 "src/parser/parser.c"
    break;

  case 144: /* literal: L_BOOLEAN_FALSE  */
#line 1393 "src/parser/parser.y"
                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_boolean(0);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3190 "src/parser/parser.c"
    break;

  case 145: /* literal: L_CHAR  */
#line 1402 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_char((yyvsp[0].literal_char));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3204 "src/parser/parser.c"
    break;

  case 146: /* literal: L_REAL  */
#line 1411 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_real((yyvsp[0].literal_float));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3218 "src/parser/parser.c"
    break;

  case 147: /* expr-identifier: IDENT  */
#line 1423 "src/parser/parser.y"
         {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_identifier((yyvsp[0].ident),0, yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3232 "src/parser/parser.c"
    break;

  case 148: /* expr-identifier: IDENT CORCH_IZDO expression CORCH_DCHO  */
#line 1432 "src/parser/parser.y"
                                            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_identifier((yyvsp[-3].ident), (yyvsp[-1].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3246 "src/parser/parser.c"
    break;

  case 149: /* function-call-expression: IDENT PAR_IZDO list-arguments PAR_DCHO  */
#line 1445 "src/parser/parser.y"
                                          {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_function_invocation((yyvsp[-3].ident), (yyvsp[-1].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3260 "src/parser/parser.c"
    break;

  case 150: /* function-call-expression: IDENT PAR_IZDO PAR_DCHO  */
#line 1455 "src/parser/parser.y"
                             {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_function_invocation((yyvsp[-2].ident), 0, yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }

    }
#line 3275 "src/parser/parser.c"
    break;

  case 151: /* list-arguments: argument DELIM_C list-arguments  */
#line 1471 "src/parser/parser.y"
                                   {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[-2].expr);
            (yyvsp[-2].expr)->next = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3289 "src/parser/parser.c"
    break;

  case 152: /* list-arguments: argument  */
#line 1480 "src/parser/parser.y"
              {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3302 "src/parser/parser.c"
    break;

  case 153: /* argument: expression  */
#line 1491 "src/parser/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3310 "src/parser/parser.c"
    break;


#line 3314 "src/parser/parser.c"

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

#line 1496 "src/parser/parser.y"


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
