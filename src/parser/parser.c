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
  YYSYMBOL_UNRECOGNIZED_TOKEN = 66,        /* UNRECOGNIZED_TOKEN  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_program = 68,                   /* program  */
  YYSYMBOL_69_program_name = 69,           /* program-name  */
  YYSYMBOL_70_list_declarations = 70,      /* list-declarations  */
  YYSYMBOL_declaration = 71,               /* declaration  */
  YYSYMBOL_72_list_subprograms = 72,       /* list-subprograms  */
  YYSYMBOL_subprogram = 73,                /* subprogram  */
  YYSYMBOL_74_subprogram_procedure = 74,   /* subprogram-procedure  */
  YYSYMBOL_75_subprogram_procedure_name = 75, /* subprogram-procedure-name  */
  YYSYMBOL_76_subprogram_function = 76,    /* subprogram-function  */
  YYSYMBOL_77_subprogram_function_name = 77, /* subprogram-function-name  */
  YYSYMBOL_78_list_parameters = 78,        /* list-parameters  */
  YYSYMBOL_parameter = 79,                 /* parameter  */
  YYSYMBOL_80_parameter_name = 80,         /* parameter-name  */
  YYSYMBOL_81_list_process = 81,           /* list-process  */
  YYSYMBOL_process = 82,                   /* process  */
  YYSYMBOL_83_process_def = 83,            /* process-def  */
  YYSYMBOL_84_process_def_array = 84,      /* process-def-array  */
  YYSYMBOL_85_process_name = 85,           /* process-name  */
  YYSYMBOL_type = 86,                      /* type  */
  YYSYMBOL_87_basic_or_array_type = 87,    /* basic-or-array-type  */
  YYSYMBOL_88_basic_type = 88,             /* basic-type  */
  YYSYMBOL_89_special_type = 89,           /* special-type  */
  YYSYMBOL_90_block_statements_begin_end = 90, /* block-statements-begin-end  */
  YYSYMBOL_91_block_statements_cobegin_coend = 91, /* block-statements-cobegin-coend  */
  YYSYMBOL_92_block_statements_atomic = 92, /* block-statements-atomic  */
  YYSYMBOL_93_block_statements_function = 93, /* block-statements-function  */
  YYSYMBOL_94_list_statements = 94,        /* list-statements  */
  YYSYMBOL_statement = 95,                 /* statement  */
  YYSYMBOL_96_assignment_statement = 96,   /* assignment-statement  */
  YYSYMBOL_97_while_statement = 97,        /* while-statement  */
  YYSYMBOL_98_for_statement = 98,          /* for-statement  */
  YYSYMBOL_99_if_statement = 99,           /* if-statement  */
  YYSYMBOL_100_fork_statement = 100,       /* fork-statement  */
  YYSYMBOL_101_join_statement = 101,       /* join-statement  */
  YYSYMBOL_102_return_statement = 102,     /* return-statement  */
  YYSYMBOL_103_print_statement = 103,      /* print-statement  */
  YYSYMBOL_104_list_print = 104,           /* list-print  */
  YYSYMBOL_105_sem_wait_statement = 105,   /* sem-wait-statement  */
  YYSYMBOL_106_sem_signal_statement = 106, /* sem-signal-statement  */
  YYSYMBOL_107_procedure_call_statement = 107, /* procedure-call-statement  */
  YYSYMBOL_expression = 108,               /* expression  */
  YYSYMBOL_109_binary_expression = 109,    /* binary-expression  */
  YYSYMBOL_110_unary_expression = 110,     /* unary-expression  */
  YYSYMBOL_term = 111,                     /* term  */
  YYSYMBOL_literal = 112,                  /* literal  */
  YYSYMBOL_113_expr_identifier = 113,      /* expr-identifier  */
  YYSYMBOL_114_function_call_expression = 114, /* function-call-expression  */
  YYSYMBOL_115_list_arguments = 115,       /* list-arguments  */
  YYSYMBOL_argument = 116                  /* argument  */
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
#define YYLAST   868

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  343

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322


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
      65,    66,     2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   240,   240,   246,   252,   260,   269,   278,   285,   295,
     305,   311,   316,   321,   326,   332,   337,   347,   356,   362,
     365,   372,   383,   395,   400,   407,   412,   418,   426,   433,
     455,   477,   482,   487,   492,   497,   502,   508,   516,   525,
     534,   546,   560,   569,   577,   589,   592,   599,   611,   616,
     624,   635,   640,   645,   652,   661,   664,   667,   674,   677,
     687,   694,   703,   712,   721,   730,   742,   751,   767,   777,
     785,   795,   803,   813,   821,   836,   846,   853,   862,   874,
     877,   880,   883,   886,   889,   892,   895,   898,   901,   904,
     907,   910,   917,   928,   939,   944,   949,   957,   970,   984,
     994,  1007,  1017,  1025,  1035,  1043,  1053,  1061,  1071,  1078,
    1087,  1098,  1110,  1123,  1133,  1148,  1151,  1154,  1157,  1165,
    1175,  1185,  1195,  1205,  1215,  1225,  1235,  1245,  1255,  1265,
    1276,  1286,  1299,  1309,  1321,  1324,  1327,  1330,  1343,  1352,
    1361,  1370,  1379,  1388,  1400,  1409,  1422,  1432,  1448,  1457,
    1468
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
  "SEM_SIGNAL", "UNRECOGNIZED_TOKEN", "$accept", "program", "program-name",
  "list-declarations", "declaration", "list-subprograms", "subprogram",
  "subprogram-procedure", "subprogram-procedure-name",
  "subprogram-function", "subprogram-function-name", "list-parameters",
  "parameter", "parameter-name", "list-process", "process", "process-def",
  "process-def-array", "process-name", "type", "basic-or-array-type",
  "basic-type", "special-type", "block-statements-begin-end",
  "block-statements-cobegin-coend", "block-statements-atomic",
  "block-statements-function", "list-statements", "statement",
  "assignment-statement", "while-statement", "for-statement",
  "if-statement", "fork-statement", "join-statement", "return-statement",
  "print-statement", "list-print", "sem-wait-statement",
  "sem-signal-statement", "procedure-call-statement", "expression",
  "binary-expression", "unary-expression", "term", "literal",
  "expr-identifier", "function-call-expression", "list-arguments",
  "argument", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-216)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-78)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     136,     7,  -216,    25,    11,    11,    11,  -216,    15,   -12,
     131,    11,   131,   131,    29,     1,   834,    17,    26,    91,
     131,  -216,  -216,  -216,    91,    91,  -216,    40,   234,  -216,
    -216,  -216,  -216,  -216,  -216,    76,  -216,  -216,    77,  -216,
    -216,  -216,    89,  -216,   113,   117,  -216,   125,    28,  -216,
      91,  -216,  -216,  -216,  -216,  -216,  -216,  -216,   388,   474,
    -216,    75,     8,    80,    97,    79,  -216,    78,  -216,   167,
     -22,  -216,  -216,  -216,  -216,  -216,  -216,   474,   186,   186,
     474,  -216,   567,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
     666,  -216,    86,   119,   127,   142,   141,    10,   143,   144,
     151,   152,    45,   160,    11,    65,    11,   197,   425,   474,
     360,  -216,  -216,   756,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,  -216,   202,    11,
     168,   194,   834,   175,    11,   197,    61,   181,   178,   189,
     181,   176,   154,   197,   198,     6,   197,   253,  -216,  -216,
     772,   196,   199,   684,  -216,  -216,  -216,   275,   275,   275,
     275,   820,   820,   128,   128,  -216,  -216,  -216,   809,   786,
    -216,   197,    11,  -216,  -216,    11,   197,  -216,    11,   197,
     203,   181,   181,    92,    11,   181,   204,  -216,   205,   201,
     474,  -216,   197,  -216,   267,   229,   235,   474,   474,   239,
     -26,   281,   212,   240,   243,  -216,  -216,   259,    93,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
     474,  -216,  -216,   197,   197,  -216,   197,  -216,    11,   227,
     228,    11,   277,   277,   138,    11,    11,   241,   328,  -216,
    -216,   272,   242,   244,   489,   511,   268,   474,   449,   474,
    -216,   246,   474,   249,   255,  -216,  -216,  -216,  -216,  -216,
    -216,   277,    11,    11,   277,   332,  -216,  -216,    11,   277,
     277,   197,    11,   474,   474,  -216,  -216,  -216,   197,   197,
     474,   587,   256,   257,   702,  -216,   262,   647,  -216,  -216,
    -216,   277,   277,  -216,   474,    84,   278,   277,  -216,  -216,
    -216,   197,   720,   738,   299,  -216,   553,  -216,  -216,   279,
     288,   280,   474,  -216,  -216,   607,  -216,   316,  -216,  -216,
    -216,   282,   283,   197,   474,  -216,   474,  -216,  -216,  -216,
    -216,    11,    11,  -216,   533,   627,   197,   197,   197,  -216,
    -216,  -216,  -216
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
      10,     0,     0,     0,     0,     0,    54,     7,    44,   118,
     144,   138,   139,   143,   140,   141,   142,     0,     0,     0,
       0,     9,     0,   115,   116,   117,   135,   134,   136,   118,
       0,    42,     0,     0,    40,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     7,     0,     7,     0,     0,     0,
       0,   133,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    60,     7,
       0,     0,     0,     0,     7,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,   147,
     150,     0,   149,     0,    16,     8,   137,   124,   126,   125,
     127,   128,   129,   119,   120,   121,   122,   123,   130,   131,
      59,     0,     7,    39,    41,     7,     0,    27,     7,     0,
       0,     0,     0,     7,     7,     0,     0,    48,     0,     0,
       0,    47,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    89,     0,     0,    79,
      80,    81,    82,    84,    85,    86,    87,    88,    83,   146,
       0,   145,    24,     0,     0,    22,     0,    26,     7,     0,
       0,     7,     0,     0,     7,     7,     7,     0,     0,    91,
      71,     0,   102,   104,     0,     0,     0,     0,     0,     0,
      73,     0,     0,     0,     0,    68,    78,   148,    23,    25,
      21,     0,     7,     7,     0,     0,    37,    35,     7,     0,
       0,     0,     7,     0,     0,    70,   101,   103,     0,     0,
       0,    95,     0,     0,     0,    72,     0,   110,   111,   112,
      32,     0,     0,    30,     0,     0,     0,     0,    36,    34,
      51,     0,     0,     0,    99,    97,     0,    92,   114,     0,
      94,   108,     0,    31,    33,   106,    76,     0,    75,    29,
      52,     0,     0,     0,     0,   113,     0,   107,   109,   105,
      74,     7,     7,   100,     0,    96,     0,     0,     0,    93,
      53,    50,    98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,  -216,   334,    -5,  -216,    23,  -216,  -216,  -216,  -216,
    -216,   -43,  -216,  -216,    -2,  -216,  -216,  -216,  -216,   -25,
     -98,   210,  -216,   -86,  -216,  -216,  -144,  -184,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,    46,  -216,    35,  -216,  -216,
    -216,   -46,  -216,  -216,   120,  -216,  -216,  -216,  -215,  -216
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    10,    11,    19,    20,    21,    44,    22,
      47,    93,    94,    95,    49,    50,    51,    52,    67,    38,
      39,    40,    41,   148,   205,   206,   266,   207,   208,   209,
     210,   211,   212,   213,   214,   296,   215,   286,   216,   217,
     218,   150,    83,    84,    85,    86,    87,    88,   151,   152
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    13,    27,    58,   141,   257,    23,   189,     5,    96,
     241,   247,    82,    90,     8,     8,    14,   251,    42,    98,
     100,   103,    54,    55,   256,     7,   248,    45,   249,    65,
     108,   110,   109,   283,   113,    24,    25,     2,    91,   180,
       9,     9,   183,    53,   186,    15,    16,    43,    68,   177,
      30,    31,    32,    33,    34,    35,    46,   187,    66,    28,
     191,    97,   107,   153,   190,     8,   144,   134,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   295,     8,   229,   230,   222,    26,   234,   173,   267,
     225,     9,   135,   227,   192,   145,     8,    56,   101,   143,
     294,   146,   316,   140,    48,    91,   239,   174,     9,   -77,
      91,   -77,   194,   -77,   195,   196,   197,   290,   178,   198,
     293,   199,     9,   200,   171,   298,   299,    91,    92,   176,
      59,   179,   105,    99,    60,   106,   104,   258,   259,     1,
     260,    61,     8,   129,   238,    17,    18,   313,   314,   231,
     102,   244,   245,   319,   201,   -77,   202,   203,   204,    30,
      31,    32,    33,    34,    35,    62,     2,   223,     9,    63,
     224,   -14,   130,   226,   122,   123,   124,    64,   232,   233,
     -14,   -14,   -14,   131,   -14,   300,    30,    31,    32,    33,
      34,    35,   304,   305,   133,   268,   136,   -14,   111,   112,
     132,   281,   137,   284,   138,   139,   287,    30,    31,    32,
      33,    34,   185,   142,   147,   320,    70,    71,    72,    73,
      74,    75,    76,   261,    91,   172,   264,   302,   303,   269,
     270,   271,   175,   184,   306,    29,   181,   333,    80,    30,
      31,    32,    33,    34,    35,    36,    37,   182,   315,   219,
     340,   341,   342,   188,   192,   220,   237,   291,   292,   242,
     228,   235,   236,   297,   252,   243,   287,   301,   192,   246,
     253,   193,   194,   254,   195,   196,   197,   255,   334,   198,
     335,   199,   192,   200,   262,   263,   194,   240,   195,   196,
     197,    57,   275,   198,   265,   199,   318,   200,   272,   276,
     194,   277,   195,   196,   197,   280,   288,   198,   285,   199,
     309,   200,   289,   308,   201,   311,   202,   203,   204,   120,
     121,   122,   123,   124,   323,   326,   336,   337,   201,   273,
     202,   203,   204,   192,   330,     6,   325,   327,   170,   331,
     332,   317,   201,   250,   202,   203,   204,   328,   294,     0,
       0,   194,     0,   195,   196,   197,     0,     0,   198,     0,
     199,   154,   200,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   126,
       0,     0,     0,     0,     0,     0,     0,   274,     0,    69,
       0,     0,     0,   201,     0,   202,   203,   204,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,     0,     0,     0,     0,     0,   155,    70,    71,
      72,    73,    74,    75,    76,    77,    89,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,    79,     0,     0,
      80,     0,     0,     0,     0,    81,     0,     0,     0,     0,
      89,     0,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,    79,    89,     0,    80,   149,    70,
      71,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,    79,     0,
       0,    80,   282,     0,    70,    71,    72,    73,    74,    75,
      76,     0,     0,   278,     0,     0,     0,     0,     0,    78,
       0,     0,     0,    79,     0,     0,    80,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   279,   125,
     126,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     338,   125,   126,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   324,   125,   126,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,   126,     0,
       0,     0,     0,     0,   127,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,   126,     0,
       0,     0,     0,     0,   307,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,   126,     0,
       0,     0,     0,     0,   329,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,   126,     0,
       0,     0,     0,     0,   339,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,   126,     0,
       0,     0,     0,   312,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,   126,     0,     0,
       0,   128,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,   126,     0,     0,     0,   221,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,   126,     0,     0,     0,   310,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,     0,     0,     0,   321,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   126,
       0,     0,     0,   322,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,   126,     0,   156,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,   126,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    29,   125,     0,     0,    30,
      31,    32,    33,    34,    35,    36,    37,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   114,   115,
     116,   117,     0,     0,   120,   121,   122,   123,   124
};

static const yytype_int16 yycheck[] =
{
       5,     6,     1,    28,   102,   220,    11,     1,     1,     1,
     194,    37,    58,    59,     4,     4,     1,   201,     1,    62,
      63,    64,    24,    25,   208,     0,    52,     1,    54,     1,
      52,    77,    54,   248,    80,    12,    13,    30,    30,   137,
      30,    30,   140,    20,   142,    30,    58,    30,    50,   135,
       5,     6,     7,     8,     9,    10,    30,   143,    30,    58,
     146,    53,    67,   109,    58,     4,     1,    57,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   265,     4,   181,   182,   171,    57,   185,   131,   233,
     176,    30,    97,   179,     1,    30,     4,    57,     1,   104,
      16,   106,    18,    58,    13,    30,   192,   132,    30,    16,
      30,    18,    19,    20,    21,    22,    23,   261,    57,    26,
     264,    28,    30,    30,   129,   269,   270,    30,    53,   134,
      54,   136,    54,    53,    57,    57,    57,   223,   224,     3,
     226,    52,     4,    57,   190,    14,    15,   291,   292,    57,
      53,   197,   198,   297,    61,    62,    63,    64,    65,     5,
       6,     7,     8,     9,    10,    52,    30,   172,    30,    52,
     175,     4,    53,   178,    46,    47,    48,    52,   183,   184,
      13,    14,    15,    56,    17,   271,     5,     6,     7,     8,
       9,    10,   278,   279,    53,    57,    53,    30,    78,    79,
      58,   247,    58,   249,    53,    53,   252,     5,     6,     7,
       8,     9,    58,    53,    17,   301,    30,    31,    32,    33,
      34,    35,    36,   228,    30,    57,   231,   273,   274,   234,
     235,   236,    57,    57,   280,     1,    58,   323,    52,     5,
       6,     7,     8,     9,    10,    11,    12,    58,   294,    53,
     336,   337,   338,    55,     1,    56,    55,   262,   263,    30,
      57,    57,    57,   268,    52,    30,   312,   272,     1,    30,
      30,    18,    19,    30,    21,    22,    23,    18,   324,    26,
     326,    28,     1,    30,    57,    57,    19,    20,    21,    22,
      23,    57,    20,    26,    17,    28,    18,    30,    57,    57,
      19,    57,    21,    22,    23,    37,    57,    26,    62,    28,
      53,    30,    57,    57,    61,    53,    63,    64,    65,    44,
      45,    46,    47,    48,    25,    37,   331,   332,    61,     1,
      63,    64,    65,     1,    18,     1,    57,    57,   128,    57,
      57,   295,    61,    62,    63,    64,    65,   312,    16,    -1,
      -1,    19,    -1,    21,    22,    23,    -1,    -1,    26,    -1,
      28,     1,    30,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,     1,
      -1,    -1,    -1,    61,    -1,    63,    64,    65,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    -1,    -1,    -1,    -1,    -1,    57,    30,    31,
      32,    33,    34,    35,    36,    37,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    49,     1,    -1,    52,    53,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    49,    -1,    -1,    52,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    27,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      27,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    29,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    57,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    57,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    57,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    57,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    -1,
      -1,    -1,    -1,    56,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    -1,    -1,
      -1,    55,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    -1,    -1,    -1,    55,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    -1,    -1,    55,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    -1,    -1,    -1,    55,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    -1,    55,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    -1,    53,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     1,    50,    -1,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    38,    39,
      40,    41,    -1,    -1,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    30,    68,    69,     1,    69,     0,     4,    30,
      70,    71,    70,    70,     1,    30,    58,    14,    15,    72,
      73,    74,    76,    70,    72,    72,    57,     1,    58,     1,
       5,     6,     7,     8,     9,    10,    11,    12,    86,    87,
      88,    89,     1,    30,    75,     1,    30,    77,    13,    81,
      82,    83,    84,    72,    81,    81,    57,    57,    86,    54,
      57,    52,    52,    52,    52,     1,    30,    85,    81,     1,
      30,    31,    32,    33,    34,    35,    36,    37,    45,    49,
      52,    57,   108,   109,   110,   111,   112,   113,   114,     1,
     108,    30,    53,    78,    79,    80,     1,    53,    78,    53,
      78,     1,    53,    78,    57,    54,    57,    70,    52,    54,
     108,   111,   111,   108,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    50,    51,    57,    55,    57,
      53,    56,    58,    53,    57,    70,    53,    58,    53,    53,
      58,    87,    53,    70,     1,    30,    70,    17,    90,    53,
     108,   115,   116,   108,     1,    57,    53,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
      88,    70,    57,    78,    86,    57,    70,    90,    57,    70,
      87,    58,    58,    87,    57,    58,    87,    90,    55,     1,
      58,    90,     1,    18,    19,    21,    22,    23,    26,    28,
      30,    61,    63,    64,    65,    91,    92,    94,    95,    96,
      97,    98,    99,   100,   101,   103,   105,   106,   107,    53,
      56,    55,    90,    70,    70,    90,    70,    90,    57,    87,
      87,    57,    70,    70,    87,    57,    57,    55,   108,    90,
      20,    94,    30,    30,   108,   108,    30,    37,    52,    54,
      62,    94,    52,    30,    30,    18,    94,   115,    90,    90,
      90,    70,    57,    57,    70,    17,    93,    93,    57,    70,
      70,    70,    57,     1,    59,    20,    57,    57,    24,    27,
      37,   108,    53,   115,   108,    62,   104,   108,    57,    57,
      93,    70,    70,    93,    16,    94,   102,    70,    93,    93,
      90,    70,   108,   108,    90,    90,   108,    57,    57,    53,
      55,    53,    56,    93,    93,   108,    18,   102,    18,    93,
      90,    55,    55,    25,    29,    57,    37,    57,   104,    57,
      18,    57,    57,    90,   108,   108,    70,    70,    27,    57,
      90,    90,    90
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    68,    68,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    78,
      78,    79,    80,    81,    81,    82,    82,    83,    83,    83,
      84,    84,    84,    84,    85,    86,    86,    86,    87,    87,
      87,    88,    88,    88,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    93,    93,    93,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    96,    96,    96,    96,    97,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   106,   107,   107,   108,   108,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   110,   110,   111,   111,   111,   111,   112,   112,
     112,   112,   112,   112,   113,   113,   114,   114,   115,   115,
     116
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
       1,     2,     4,     7,     4,     3,     6,     4,     8,     4,
       6,     3,     2,     3,     2,     3,     2,     5,     4,     3,
       1,     3,     3,     5,     4,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     3,     3,     1,
       1
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
#line 240 "src/parser/parser.y"
                                                                          {
        // -- Crear AST (solo si no hay errores sintacticos)
        if(!have_syntax_errors())
            AST_program = create_program((yyvsp[-3].ident),(yyvsp[-2].decl),(yyvsp[-1].subprog),(yyvsp[0].proc));
    }
#line 1562 "src/parser/parser.c"
    break;

  case 3: /* program: program-name list-declarations list-subprograms list-process  */
#line 246 "src/parser/parser.y"
                                                                  {
        mark_error_syntax_program_expected_program((yyvsp[-3].ident));
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }
#line 1572 "src/parser/parser.c"
    break;

  case 4: /* program: S_PROGRAM error list-declarations list-subprograms list-process  */
#line 252 "src/parser/parser.y"
                                                                     {
        mark_error_syntax_program_expected_identifier();
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }
#line 1582 "src/parser/parser.c"
    break;

  case 5: /* program-name: IDENT  */
#line 260 "src/parser/parser.y"
         { 
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1590 "src/parser/parser.c"
    break;

  case 6: /* list-declarations: declaration list-declarations  */
#line 269 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.decl) = (yyvsp[-1].decl);
            (yyvsp[-1].decl)->next = (yyvsp[0].decl);
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1604 "src/parser/parser.c"
    break;

  case 7: /* list-declarations: %empty  */
#line 278 "src/parser/parser.y"
                   {
        (yyval.decl) = 0;
    }
#line 1612 "src/parser/parser.c"
    break;

  case 8: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression DELIM_PC  */
#line 285 "src/parser/parser.y"
                                                           {
        if(!have_syntax_errors()){
            (yyval.decl) = create_declaration_variable((yyvsp[-5].ident), (yyvsp[-3].type), (yyvsp[-1].expr), yylineno);
            add_declaration_to_register((yyval.decl));
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1626 "src/parser/parser.c"
    break;

  case 9: /* declaration: S_VAR IDENT DELIM_2P type DELIM_PC  */
#line 295 "src/parser/parser.y"
                                        {
        if(!have_syntax_errors()){
            (yyval.decl) = create_declaration_variable((yyvsp[-3].ident), (yyvsp[-1].type), 0, yylineno);
            add_declaration_to_register((yyval.decl));
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1640 "src/parser/parser.c"
    break;

  case 10: /* declaration: IDENT DELIM_2P type DELIM_PC  */
#line 305 "src/parser/parser.y"
                                  {
        mark_error_syntax_declaration_expected_var((yyvsp[-3].ident));
        // Recuperar
        //YYABORT;
    }
#line 1650 "src/parser/parser.c"
    break;

  case 11: /* declaration: S_VAR error DELIM_PC  */
#line 311 "src/parser/parser.y"
                          {
        mark_error_syntax_declaration_expected_identifier();
        //YYABORT;
    }
#line 1659 "src/parser/parser.c"
    break;

  case 12: /* declaration: S_VAR IDENT error DELIM_PC  */
#line 316 "src/parser/parser.y"
                                {
        mark_error_syntax_declaration_expected_delim2p((yyvsp[-2].ident));
        //YYABORT;
    }
#line 1668 "src/parser/parser.c"
    break;

  case 13: /* declaration: S_VAR IDENT DELIM_2P DELIM_PC  */
#line 321 "src/parser/parser.y"
                                   {
        mark_error_syntax_type_expected_type((yyvsp[-2].ident));
        //YYABORT;
    }
#line 1677 "src/parser/parser.c"
    break;

  case 14: /* declaration: S_VAR IDENT DELIM_2P type error  */
#line 326 "src/parser/parser.y"
                                     {
        mark_error_syntax_declaration_expected_delimpc((yyvsp[-3].ident));
        free_AST_type_register((yyvsp[-1].type));
        //YYABORT;
    }
#line 1687 "src/parser/parser.c"
    break;

  case 15: /* declaration: S_VAR IDENT DELIM_2P type expression DELIM_PC  */
#line 332 "src/parser/parser.y"
                                                   {
        mark_error_syntax_declaration_expected_opassign((yyvsp[-4].ident));
        //YYABORT;
    }
#line 1696 "src/parser/parser.c"
    break;

  case 16: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression error  */
#line 337 "src/parser/parser.y"
                                                          {
        mark_error_syntax_declaration_expected_delimpc((yyvsp[-5].ident));
        //YYABORT;
    }
#line 1705 "src/parser/parser.c"
    break;

  case 17: /* list-subprograms: subprogram list-subprograms  */
#line 347 "src/parser/parser.y"
                               {
        if(!have_syntax_errors()){
            (yyval.subprog) = (yyvsp[-1].subprog);
            (yyvsp[-1].subprog)->next = (yyvsp[0].subprog);
        }
        else{
            (yyval.subprog) = 0;
        }
    }
#line 1719 "src/parser/parser.c"
    break;

  case 18: /* list-subprograms: %empty  */
#line 356 "src/parser/parser.y"
                   {
        (yyval.subprog) = 0;
    }
#line 1727 "src/parser/parser.c"
    break;

  case 19: /* subprogram: subprogram-procedure  */
#line 362 "src/parser/parser.y"
                        {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1735 "src/parser/parser.c"
    break;

  case 20: /* subprogram: subprogram-function  */
#line 365 "src/parser/parser.y"
                         {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1743 "src/parser/parser.c"
    break;

  case 21: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 372 "src/parser/parser.y"
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
#line 1758 "src/parser/parser.c"
    break;

  case 22: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 383 "src/parser/parser.y"
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
#line 1774 "src/parser/parser.c"
    break;

  case 23: /* subprogram-procedure: S_PROCEDURE error PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 395 "src/parser/parser.y"
                                                                                                               {
        mark_error_syntax_subprogram_procedure_expected_identifier();
        //YYABORT;
    }
#line 1783 "src/parser/parser.c"
    break;

  case 24: /* subprogram-procedure: S_PROCEDURE error PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 400 "src/parser/parser.y"
                                                                                               {
        // -- Mostrar error
        mark_error_syntax_subprogram_procedure_expected_identifier();
        // -- Abortar inmediatmente el analisis
        //YYABORT;
    }
#line 1794 "src/parser/parser.c"
    break;

  case 25: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO error PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 407 "src/parser/parser.y"
                                                                                                                         {
        mark_error_syntax_subprogram_procedure_expected_parameters((yyvsp[-6].ident));
        //YYABORT;
    }
#line 1803 "src/parser/parser.c"
    break;

  case 26: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO list-declarations block-statements-begin-end  */
#line 412 "src/parser/parser.y"
                                                                                                                          {
        mark_error_syntax_subprogram_procedure_expected_delimpc((yyvsp[-5].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1813 "src/parser/parser.c"
    break;

  case 27: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO list-declarations block-statements-begin-end  */
#line 418 "src/parser/parser.y"
                                                                                                          {
        mark_error_syntax_subprogram_procedure_expected_delimpc((yyvsp[-4].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1823 "src/parser/parser.c"
    break;

  case 28: /* subprogram-procedure-name: IDENT  */
#line 426 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1831 "src/parser/parser.c"
    break;

  case 29: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 433 "src/parser/parser.y"
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
#line 1857 "src/parser/parser.c"
    break;

  case 30: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 455 "src/parser/parser.y"
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
#line 1883 "src/parser/parser.c"
    break;

  case 31: /* subprogram-function: S_FUNCTION error PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 477 "src/parser/parser.y"
                                                                                                                                          {
        mark_error_syntax_subprogram_function_expected_identifier();
        //YYABORT;
    }
#line 1892 "src/parser/parser.c"
    break;

  case 32: /* subprogram-function: S_FUNCTION error PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 482 "src/parser/parser.y"
                                                                                                                          {
        mark_error_syntax_subprogram_function_expected_identifier();
        //YYABORT;
    }
#line 1901 "src/parser/parser.c"
    break;

  case 33: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO error PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 487 "src/parser/parser.y"
                                                                                                                                                   {
        mark_error_syntax_subprogram_function_expected_parameters((yyvsp[-8].ident));
        //YYABORT;
    }
#line 1910 "src/parser/parser.c"
    break;

  case 34: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 492 "src/parser/parser.y"
                                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delim2p((yyvsp[-7].ident));
        //YYABORT;
    }
#line 1919 "src/parser/parser.c"
    break;

  case 35: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 497 "src/parser/parser.y"
                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delim2p((yyvsp[-6].ident));
        //YYABORT;
    }
#line 1928 "src/parser/parser.c"
    break;

  case 36: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type list-declarations block-statements-function  */
#line 502 "src/parser/parser.y"
                                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delimpc((yyvsp[-7].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1938 "src/parser/parser.c"
    break;

  case 37: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type list-declarations block-statements-function  */
#line 508 "src/parser/parser.y"
                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delimpc((yyvsp[-6].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1948 "src/parser/parser.c"
    break;

  case 38: /* subprogram-function-name: IDENT  */
#line 516 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1956 "src/parser/parser.c"
    break;

  case 39: /* list-parameters: parameter DELIM_C list-parameters  */
#line 525 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.param) = (yyvsp[-2].param);
            (yyvsp[-2].param)->next = (yyvsp[0].param);
        }
        else{
            (yyval.param) = 0;
        }
    }
#line 1970 "src/parser/parser.c"
    break;

  case 40: /* list-parameters: parameter  */
#line 534 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.param) = (yyvsp[0].param);
        }
        else{
            (yyval.param) = 0;
        }
    }
#line 1983 "src/parser/parser.c"
    break;

  case 41: /* parameter: parameter-name DELIM_2P type  */
#line 546 "src/parser/parser.y"
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
#line 1999 "src/parser/parser.c"
    break;

  case 42: /* parameter-name: IDENT  */
#line 560 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 2007 "src/parser/parser.c"
    break;

  case 43: /* list-process: process  */
#line 569 "src/parser/parser.y"
           {
        if(!have_syntax_errors()){
            (yyval.proc) = (yyvsp[0].proc);
        }
        else{
            (yyval.proc) = 0;
        }
    }
#line 2020 "src/parser/parser.c"
    break;

  case 44: /* list-process: process list-process  */
#line 577 "src/parser/parser.y"
                          {
        if(!have_syntax_errors()){
            (yyval.proc) = (yyvsp[-1].proc);
            (yyvsp[-1].proc)->next = (yyvsp[0].proc);
        }
        else{
            (yyval.proc) = 0;
        }
    }
#line 2034 "src/parser/parser.c"
    break;

  case 45: /* process: process-def  */
#line 589 "src/parser/parser.y"
               {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 2042 "src/parser/parser.c"
    break;

  case 46: /* process: process-def-array  */
#line 592 "src/parser/parser.y"
                       {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 2050 "src/parser/parser.c"
    break;

  case 47: /* process-def: S_PROCESS process-name DELIM_PC list-declarations block-statements-begin-end  */
#line 599 "src/parser/parser.y"
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
#line 2066 "src/parser/parser.c"
    break;

  case 48: /* process-def: S_PROCESS error DELIM_PC list-declarations block-statements-begin-end  */
#line 611 "src/parser/parser.y"
                                                                           {
        mark_error_syntax_process_expected_identifier();
        //YYABORT;
    }
#line 2075 "src/parser/parser.c"
    break;

  case 49: /* process-def: S_PROCESS process-name list-declarations block-statements-begin-end  */
#line 616 "src/parser/parser.y"
                                                                         {
        mark_error_syntax_process_expected_delimpc((yyvsp[-2].ident));
        //YYABORT;
    }
#line 2084 "src/parser/parser.c"
    break;

  case 50: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 624 "src/parser/parser.y"
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
#line 2099 "src/parser/parser.c"
    break;

  case 51: /* process-def-array: S_PROCESS process-name CORCH_IZDO error CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 635 "src/parser/parser.y"
                                                                                                              {
        mark_error_syntax_process_expected_index_identifier((yyvsp[-6].ident));
        //YYABORT;
    }
#line 2108 "src/parser/parser.c"
    break;

  case 52: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT error CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 640 "src/parser/parser.y"
                                                                                                                    {
        mark_error_syntax_process_expected_delim2p((yyvsp[-7].ident));
        //YYABORT;
    }
#line 2117 "src/parser/parser.c"
    break;

  case 53: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression error expression CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 645 "src/parser/parser.y"
                                                                                                                                                   {
        mark_error_syntax_process_expected_delimarr((yyvsp[-10].ident));
        //YYABORT;
    }
#line 2126 "src/parser/parser.c"
    break;

  case 54: /* process-name: IDENT  */
#line 652 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 2134 "src/parser/parser.c"
    break;

  case 55: /* type: basic-or-array-type  */
#line 661 "src/parser/parser.y"
                       {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2142 "src/parser/parser.c"
    break;

  case 56: /* type: special-type  */
#line 664 "src/parser/parser.y"
                  {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2150 "src/parser/parser.c"
    break;

  case 57: /* type: error  */
#line 667 "src/parser/parser.y"
           {
        mark_error_syntax_type_expected_type();
        //YYABORT;
    }
#line 2159 "src/parser/parser.c"
    break;

  case 58: /* basic-or-array-type: basic-type  */
#line 674 "src/parser/parser.y"
              {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2167 "src/parser/parser.c"
    break;

  case 59: /* basic-or-array-type: T_ARRAY CORCH_IZDO expression CORCH_DCHO basic-type  */
#line 677 "src/parser/parser.y"
                                                         {
        if(!have_syntax_errors()){
            (yyval.type) = create_array_type((yyvsp[0].type),(yyvsp[-2].expr));
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2181 "src/parser/parser.c"
    break;

  case 60: /* basic-or-array-type: T_ARRAY CORCH_IZDO expression CORCH_DCHO  */
#line 687 "src/parser/parser.y"
                                              {
        mark_error_syntax_type_expected_type();
        //YYABORT;
    }
#line 2190 "src/parser/parser.c"
    break;

  case 61: /* basic-type: T_INTEGER  */
#line 694 "src/parser/parser.y"
             {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_INTEGER);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2204 "src/parser/parser.c"
    break;

  case 62: /* basic-type: T_BOOLEAN  */
#line 703 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_BOOLEAN);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2218 "src/parser/parser.c"
    break;

  case 63: /* basic-type: T_CHAR  */
#line 712 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_CHAR);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2232 "src/parser/parser.c"
    break;

  case 64: /* basic-type: T_STRING  */
#line 721 "src/parser/parser.y"
              {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_STRING);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2246 "src/parser/parser.c"
    break;

  case 65: /* basic-type: T_REAL  */
#line 730 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_REAL);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2260 "src/parser/parser.c"
    break;

  case 66: /* special-type: T_SEMAPHORE  */
#line 742 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.type) = create_semaphore_type();
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2274 "src/parser/parser.c"
    break;

  case 67: /* special-type: T_DPROCESS  */
#line 751 "src/parser/parser.y"
                {
        if(!have_syntax_errors()){
            (yyval.type) = create_dprocess_type();
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2288 "src/parser/parser.c"
    break;

  case 68: /* block-statements-begin-end: B_BEGIN list-statements B_END  */
#line 767 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2302 "src/parser/parser.c"
    break;

  case 69: /* block-statements-begin-end: B_BEGIN B_END  */
#line 777 "src/parser/parser.y"
                   {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2311 "src/parser/parser.c"
    break;

  case 70: /* block-statements-cobegin-coend: B_COBEGIN list-statements B_COEND  */
#line 785 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_cobegin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2325 "src/parser/parser.c"
    break;

  case 71: /* block-statements-cobegin-coend: B_COBEGIN B_COEND  */
#line 795 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2334 "src/parser/parser.c"
    break;

  case 72: /* block-statements-atomic: ATOM_INI list-statements ATOM_FIN  */
#line 803 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_atomic((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2348 "src/parser/parser.c"
    break;

  case 73: /* block-statements-atomic: ATOM_INI ATOM_FIN  */
#line 813 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2357 "src/parser/parser.c"
    break;

  case 74: /* block-statements-function: B_BEGIN list-statements return-statement B_END  */
#line 821 "src/parser/parser.y"
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
#line 2376 "src/parser/parser.c"
    break;

  case 75: /* block-statements-function: B_BEGIN return-statement B_END  */
#line 836 "src/parser/parser.y"
                                    {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2390 "src/parser/parser.c"
    break;

  case 76: /* block-statements-function: B_BEGIN list-statements B_END  */
#line 846 "src/parser/parser.y"
                                   {
        mark_error_syntax_statement_non_return_in_block();
        //YYABORT;
    }
#line 2399 "src/parser/parser.c"
    break;

  case 77: /* list-statements: statement  */
#line 853 "src/parser/parser.y"
             {
        if(!have_syntax_errors()){
            (yyval.stmt) = (yyvsp[0].stmt);
        }
        else{
            (yyval.stmt) = 0;
        }
        
    }
#line 2413 "src/parser/parser.c"
    break;

  case 78: /* list-statements: statement list-statements  */
#line 862 "src/parser/parser.y"
                               {
        if(!have_syntax_errors()){
            (yyval.stmt) = (yyvsp[-1].stmt);
            (yyvsp[-1].stmt)->next = (yyvsp[0].stmt);
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2427 "src/parser/parser.c"
    break;

  case 79: /* statement: assignment-statement  */
#line 874 "src/parser/parser.y"
                        {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2435 "src/parser/parser.c"
    break;

  case 80: /* statement: while-statement  */
#line 877 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2443 "src/parser/parser.c"
    break;

  case 81: /* statement: for-statement  */
#line 880 "src/parser/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2451 "src/parser/parser.c"
    break;

  case 82: /* statement: if-statement  */
#line 883 "src/parser/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2459 "src/parser/parser.c"
    break;

  case 83: /* statement: procedure-call-statement  */
#line 886 "src/parser/parser.y"
                              {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2467 "src/parser/parser.c"
    break;

  case 84: /* statement: fork-statement  */
#line 889 "src/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2475 "src/parser/parser.c"
    break;

  case 85: /* statement: join-statement  */
#line 892 "src/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2483 "src/parser/parser.c"
    break;

  case 86: /* statement: print-statement  */
#line 895 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2491 "src/parser/parser.c"
    break;

  case 87: /* statement: sem-wait-statement  */
#line 898 "src/parser/parser.y"
                        {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2499 "src/parser/parser.c"
    break;

  case 88: /* statement: sem-signal-statement  */
#line 901 "src/parser/parser.y"
                          {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2507 "src/parser/parser.c"
    break;

  case 89: /* statement: block-statements-atomic  */
#line 904 "src/parser/parser.y"
                             {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2515 "src/parser/parser.c"
    break;

  case 90: /* statement: block-statements-cobegin-coend  */
#line 907 "src/parser/parser.y"
                                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2523 "src/parser/parser.c"
    break;

  case 91: /* statement: error block-statements-begin-end  */
#line 910 "src/parser/parser.y"
                                      {
        mark_error_syntax_statement_expected_statement();
    }
#line 2531 "src/parser/parser.c"
    break;

  case 92: /* assignment-statement: IDENT OP_ASSIGN expression DELIM_PC  */
#line 917 "src/parser/parser.y"
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
#line 2546 "src/parser/parser.c"
    break;

  case 93: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression DELIM_PC  */
#line 928 "src/parser/parser.y"
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
#line 2561 "src/parser/parser.c"
    break;

  case 94: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO  */
#line 939 "src/parser/parser.y"
                                            {
        mark_error_syntax_statement_expected_statement();
        //YYABORT;
    }
#line 2570 "src/parser/parser.c"
    break;

  case 95: /* assignment-statement: IDENT OP_ASSIGN expression  */
#line 944 "src/parser/parser.y"
                                {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2579 "src/parser/parser.c"
    break;

  case 96: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression  */
#line 949 "src/parser/parser.y"
                                                                 {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2588 "src/parser/parser.c"
    break;

  case 97: /* while-statement: WHILE expression DO block-statements-begin-end  */
#line 957 "src/parser/parser.y"
                                                  {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_while((yyvsp[-2].expr), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2602 "src/parser/parser.c"
    break;

  case 98: /* for-statement: FOR IDENT OP_ASSIGN expression TO expression DO block-statements-begin-end  */
#line 970 "src/parser/parser.y"
                                                                              {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_for((yyvsp[-6].ident), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2616 "src/parser/parser.c"
    break;

  case 99: /* if-statement: IF expression THEN block-statements-begin-end  */
#line 984 "src/parser/parser.y"
                                                 {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_if_else((yyvsp[-2].expr), (yyvsp[0].stmt), 0, yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2630 "src/parser/parser.c"
    break;

  case 100: /* if-statement: IF expression THEN block-statements-begin-end ELSE block-statements-begin-end  */
#line 994 "src/parser/parser.y"
                                                                                   {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_if_else((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2644 "src/parser/parser.c"
    break;

  case 101: /* fork-statement: S_FORK IDENT DELIM_PC  */
#line 1007 "src/parser/parser.y"
                         {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_fork((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2658 "src/parser/parser.c"
    break;

  case 102: /* fork-statement: S_FORK IDENT  */
#line 1017 "src/parser/parser.y"
                  {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2667 "src/parser/parser.c"
    break;

  case 103: /* join-statement: JOIN IDENT DELIM_PC  */
#line 1025 "src/parser/parser.y"
                       {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_join((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2681 "src/parser/parser.c"
    break;

  case 104: /* join-statement: JOIN IDENT  */
#line 1035 "src/parser/parser.y"
                {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2690 "src/parser/parser.c"
    break;

  case 105: /* return-statement: RETURN expression DELIM_PC  */
#line 1043 "src/parser/parser.y"
                              {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_return((yyvsp[-1].expr), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2704 "src/parser/parser.c"
    break;

  case 106: /* return-statement: RETURN expression  */
#line 1053 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2713 "src/parser/parser.c"
    break;

  case 107: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO DELIM_PC  */
#line 1061 "src/parser/parser.y"
                                               {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_print((yyvsp[-2].expr));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2727 "src/parser/parser.c"
    break;

  case 108: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO  */
#line 1071 "src/parser/parser.y"
                                        {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2736 "src/parser/parser.c"
    break;

  case 109: /* list-print: expression DELIM_C list-print  */
#line 1078 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[-2].expr);
            (yyvsp[-2].expr)->next = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2750 "src/parser/parser.c"
    break;

  case 110: /* list-print: expression  */
#line 1087 "src/parser/parser.y"
                {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2763 "src/parser/parser.c"
    break;

  case 111: /* sem-wait-statement: SEM_WAIT IDENT DELIM_PC  */
#line 1098 "src/parser/parser.y"
                           {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_sem_wait((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2777 "src/parser/parser.c"
    break;

  case 112: /* sem-signal-statement: SEM_SIGNAL IDENT DELIM_PC  */
#line 1110 "src/parser/parser.y"
                             {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_sem_signal((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2791 "src/parser/parser.c"
    break;

  case 113: /* procedure-call-statement: IDENT PAR_IZDO list-arguments PAR_DCHO DELIM_PC  */
#line 1123 "src/parser/parser.y"
                                                   {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_procedure_inv((yyvsp[-4].ident), (yyvsp[-2].expr), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2805 "src/parser/parser.c"
    break;

  case 114: /* procedure-call-statement: IDENT PAR_IZDO PAR_DCHO DELIM_PC  */
#line 1133 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_procedure_inv((yyvsp[-3].ident), 0, yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2819 "src/parser/parser.c"
    break;

  case 115: /* expression: binary-expression  */
#line 1148 "src/parser/parser.y"
                     {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2827 "src/parser/parser.c"
    break;

  case 116: /* expression: unary-expression  */
#line 1151 "src/parser/parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2835 "src/parser/parser.c"
    break;

  case 117: /* expression: term  */
#line 1154 "src/parser/parser.y"
          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2843 "src/parser/parser.c"
    break;

  case 118: /* expression: error  */
#line 1157 "src/parser/parser.y"
            {
        mark_error_syntax_expression_expected_expr();
        YYABORT;
    }
#line 2852 "src/parser/parser.c"
    break;

  case 119: /* binary-expression: expression OP_SUM expression  */
#line 1165 "src/parser/parser.y"
                                {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_ADD, "+", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2866 "src/parser/parser.c"
    break;

  case 120: /* binary-expression: expression OP_MINUS expression  */
#line 1175 "src/parser/parser.y"
                                    {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_SUB, "-", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2880 "src/parser/parser.c"
    break;

  case 121: /* binary-expression: expression OP_MULT expression  */
#line 1185 "src/parser/parser.y"
                                   {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_MULT, "*", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2894 "src/parser/parser.c"
    break;

  case 122: /* binary-expression: expression OP_DIV expression  */
#line 1195 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_DIV, "/", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2908 "src/parser/parser.c"
    break;

  case 123: /* binary-expression: expression OP_MOD expression  */
#line 1205 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_MOD, "%", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2922 "src/parser/parser.c"
    break;

  case 124: /* binary-expression: expression OP_REL_LT expression  */
#line 1215 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_LT, "<", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2936 "src/parser/parser.c"
    break;

  case 125: /* binary-expression: expression OP_REL_LTE expression  */
#line 1225 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_LTE, "<=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2950 "src/parser/parser.c"
    break;

  case 126: /* binary-expression: expression OP_REL_GT expression  */
#line 1235 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_GT, ">", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2964 "src/parser/parser.c"
    break;

  case 127: /* binary-expression: expression OP_REL_GTE expression  */
#line 1245 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_GTE, ">=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2978 "src/parser/parser.c"
    break;

  case 128: /* binary-expression: expression OP_REL_EQ expression  */
#line 1255 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_EQ, "==", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2992 "src/parser/parser.c"
    break;

  case 129: /* binary-expression: expression OP_REL_NEQ expression  */
#line 1265 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_NEQ, "!=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
       
    }
#line 3007 "src/parser/parser.c"
    break;

  case 130: /* binary-expression: expression OP_AND expression  */
#line 1276 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_AND, "and", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3021 "src/parser/parser.c"
    break;

  case 131: /* binary-expression: expression OP_OR expression  */
#line 1286 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_OR, "or", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3035 "src/parser/parser.c"
    break;

  case 132: /* unary-expression: OP_NOT term  */
#line 1299 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_unary_operation(EXPR_NOT, "not", (yyvsp[0].expr),yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3049 "src/parser/parser.c"
    break;

  case 133: /* unary-expression: OP_MINUS term  */
#line 1309 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_unary_operation(EXPR_NEGATIVE, "-", (yyvsp[0].expr),yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3063 "src/parser/parser.c"
    break;

  case 134: /* term: expr-identifier  */
#line 1321 "src/parser/parser.y"
                   {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3071 "src/parser/parser.c"
    break;

  case 135: /* term: literal  */
#line 1324 "src/parser/parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3079 "src/parser/parser.c"
    break;

  case 136: /* term: function-call-expression  */
#line 1327 "src/parser/parser.y"
                              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3087 "src/parser/parser.c"
    break;

  case 137: /* term: PAR_IZDO expression PAR_DCHO  */
#line 1330 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_grouped((yyvsp[-1].expr));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3101 "src/parser/parser.c"
    break;

  case 138: /* literal: LITERAL  */
#line 1343 "src/parser/parser.y"
           {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_string((yyvsp[0].literal_string));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3115 "src/parser/parser.c"
    break;

  case 139: /* literal: L_INTEGER  */
#line 1352 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_integer((yyvsp[0].literal_int));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3129 "src/parser/parser.c"
    break;

  case 140: /* literal: L_BOOLEAN_TRUE  */
#line 1361 "src/parser/parser.y"
                    {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_boolean(1);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3143 "src/parser/parser.c"
    break;

  case 141: /* literal: L_BOOLEAN_FALSE  */
#line 1370 "src/parser/parser.y"
                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_boolean(0);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3157 "src/parser/parser.c"
    break;

  case 142: /* literal: L_CHAR  */
#line 1379 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_char((yyvsp[0].literal_char));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3171 "src/parser/parser.c"
    break;

  case 143: /* literal: L_REAL  */
#line 1388 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_real((yyvsp[0].literal_float));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3185 "src/parser/parser.c"
    break;

  case 144: /* expr-identifier: IDENT  */
#line 1400 "src/parser/parser.y"
         {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_identifier((yyvsp[0].ident),0, yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3199 "src/parser/parser.c"
    break;

  case 145: /* expr-identifier: IDENT CORCH_IZDO expression CORCH_DCHO  */
#line 1409 "src/parser/parser.y"
                                            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_identifier((yyvsp[-3].ident), (yyvsp[-1].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3213 "src/parser/parser.c"
    break;

  case 146: /* function-call-expression: IDENT PAR_IZDO list-arguments PAR_DCHO  */
#line 1422 "src/parser/parser.y"
                                          {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_function_invocation((yyvsp[-3].ident), (yyvsp[-1].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3227 "src/parser/parser.c"
    break;

  case 147: /* function-call-expression: IDENT PAR_IZDO PAR_DCHO  */
#line 1432 "src/parser/parser.y"
                             {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_function_invocation((yyvsp[-2].ident), 0, yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }

    }
#line 3242 "src/parser/parser.c"
    break;

  case 148: /* list-arguments: argument DELIM_C list-arguments  */
#line 1448 "src/parser/parser.y"
                                   {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[-2].expr);
            (yyvsp[-2].expr)->next = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3256 "src/parser/parser.c"
    break;

  case 149: /* list-arguments: argument  */
#line 1457 "src/parser/parser.y"
              {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3269 "src/parser/parser.c"
    break;

  case 150: /* argument: expression  */
#line 1468 "src/parser/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3277 "src/parser/parser.c"
    break;


#line 3281 "src/parser/parser.c"

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

#line 1473 "src/parser/parser.y"


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
