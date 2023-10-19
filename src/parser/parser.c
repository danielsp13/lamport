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
  YYSYMBOL_NEWLINE = 64,                   /* NEWLINE  */
  YYSYMBOL_UNRECOGNIZED_TOKEN = 65,        /* UNRECOGNIZED_TOKEN  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_program = 67,                   /* program  */
  YYSYMBOL_68_program_name = 68,           /* program-name  */
  YYSYMBOL_69_list_declarations = 69,      /* list-declarations  */
  YYSYMBOL_declaration = 70,               /* declaration  */
  YYSYMBOL_71_list_subprograms = 71,       /* list-subprograms  */
  YYSYMBOL_subprogram = 72,                /* subprogram  */
  YYSYMBOL_73_subprogram_procedure = 73,   /* subprogram-procedure  */
  YYSYMBOL_74_subprogram_procedure_name = 74, /* subprogram-procedure-name  */
  YYSYMBOL_75_subprogram_function = 75,    /* subprogram-function  */
  YYSYMBOL_76_subprogram_function_name = 76, /* subprogram-function-name  */
  YYSYMBOL_77_list_parameters = 77,        /* list-parameters  */
  YYSYMBOL_parameter = 78,                 /* parameter  */
  YYSYMBOL_79_parameter_name = 79,         /* parameter-name  */
  YYSYMBOL_80_list_process = 80,           /* list-process  */
  YYSYMBOL_process = 81,                   /* process  */
  YYSYMBOL_82_process_def = 82,            /* process-def  */
  YYSYMBOL_83_process_def_array = 83,      /* process-def-array  */
  YYSYMBOL_84_process_name = 84,           /* process-name  */
  YYSYMBOL_type = 85,                      /* type  */
  YYSYMBOL_86_basic_or_array_type = 86,    /* basic-or-array-type  */
  YYSYMBOL_87_basic_type = 87,             /* basic-type  */
  YYSYMBOL_88_special_type = 88,           /* special-type  */
  YYSYMBOL_89_block_statements_begin_end = 89, /* block-statements-begin-end  */
  YYSYMBOL_90_block_statements_cobegin_coend = 90, /* block-statements-cobegin-coend  */
  YYSYMBOL_91_block_statements_atomic = 91, /* block-statements-atomic  */
  YYSYMBOL_92_block_statements_function = 92, /* block-statements-function  */
  YYSYMBOL_93_list_statements = 93,        /* list-statements  */
  YYSYMBOL_statement = 94,                 /* statement  */
  YYSYMBOL_95_assignment_statement = 95,   /* assignment-statement  */
  YYSYMBOL_96_while_statement = 96,        /* while-statement  */
  YYSYMBOL_97_for_statement = 97,          /* for-statement  */
  YYSYMBOL_98_if_statement = 98,           /* if-statement  */
  YYSYMBOL_99_fork_statement = 99,         /* fork-statement  */
  YYSYMBOL_100_join_statement = 100,       /* join-statement  */
  YYSYMBOL_101_return_statement = 101,     /* return-statement  */
  YYSYMBOL_102_print_statement = 102,      /* print-statement  */
  YYSYMBOL_103_list_print = 103,           /* list-print  */
  YYSYMBOL_104_procedure_call_statement = 104, /* procedure-call-statement  */
  YYSYMBOL_expression = 105,               /* expression  */
  YYSYMBOL_106_binary_expression = 106,    /* binary-expression  */
  YYSYMBOL_107_unary_expression = 107,     /* unary-expression  */
  YYSYMBOL_term = 108,                     /* term  */
  YYSYMBOL_literal = 109,                  /* literal  */
  YYSYMBOL_110_expr_identifier = 110,      /* expr-identifier  */
  YYSYMBOL_111_function_call_expression = 111, /* function-call-expression  */
  YYSYMBOL_112_list_arguments = 112,       /* list-arguments  */
  YYSYMBOL_argument = 113                  /* argument  */
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
#define YYLAST   804

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  335

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


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
      65,     2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   237,   237,   243,   249,   257,   266,   275,   282,   292,
     302,   308,   313,   318,   323,   329,   334,   344,   353,   359,
     362,   369,   380,   392,   397,   404,   409,   415,   423,   430,
     452,   474,   479,   484,   489,   494,   499,   505,   513,   522,
     531,   543,   557,   566,   574,   586,   589,   596,   608,   613,
     621,   632,   637,   642,   649,   658,   661,   664,   671,   674,
     684,   691,   700,   709,   718,   727,   739,   748,   764,   774,
     782,   792,   800,   810,   818,   833,   843,   850,   859,   871,
     874,   877,   880,   883,   886,   889,   892,   895,   898,   901,
     908,   919,   930,   935,   940,   948,   961,   975,   985,   998,
    1008,  1016,  1026,  1034,  1044,  1052,  1062,  1069,  1078,  1090,
    1100,  1115,  1118,  1121,  1124,  1132,  1142,  1152,  1162,  1172,
    1182,  1192,  1202,  1212,  1222,  1232,  1243,  1253,  1266,  1276,
    1288,  1291,  1294,  1297,  1310,  1319,  1328,  1337,  1346,  1355,
    1367,  1376,  1389,  1399,  1415,  1424,  1435
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
  "DELIM_ARR", "DELIM_P", "ATOM_INI", "ATOM_FIN", "PRINT", "NEWLINE",
  "UNRECOGNIZED_TOKEN", "$accept", "program", "program-name",
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
  "print-statement", "list-print", "procedure-call-statement",
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

#define YYPACT_NINF (-212)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-78)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      91,    12,  -212,    36,    10,    10,    10,  -212,    14,   -41,
       7,    10,     7,     7,    24,     3,   770,    17,    22,    82,
       7,  -212,  -212,  -212,    82,    82,  -212,    46,   366,  -212,
    -212,  -212,  -212,  -212,  -212,    78,  -212,  -212,    99,  -212,
    -212,  -212,   106,  -212,   107,   113,  -212,   114,    26,  -212,
      82,  -212,  -212,  -212,  -212,  -212,  -212,  -212,   313,   410,
    -212,   -14,   180,    66,   219,   111,  -212,   100,  -212,   375,
      61,  -212,  -212,  -212,  -212,  -212,  -212,   410,   448,   448,
     410,  -212,   503,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
     602,  -212,   115,   116,   108,   117,   118,    96,   121,   124,
     123,   140,   181,   143,    10,    92,    10,   182,   350,   410,
     285,  -212,  -212,   692,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,  -212,   238,    10,
     147,   178,   770,   154,    10,   182,    98,   347,   157,   160,
     347,   155,   301,   182,   169,    33,   182,    27,  -212,  -212,
     708,   175,   176,   620,  -212,  -212,  -212,   293,   293,   293,
     293,   756,   756,   -16,   -16,  -212,  -212,  -212,   745,   722,
    -212,   182,    10,  -212,  -212,    10,   182,  -212,    10,   182,
     172,   347,   347,   173,    10,   347,   174,  -212,   193,   183,
     410,  -212,   182,  -212,    88,   206,   207,   410,   410,   225,
     -17,   179,   210,  -212,  -212,   240,   122,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,   410,  -212,  -212,   182,
     182,  -212,   182,  -212,    10,   202,   209,    10,   246,   246,
     191,    10,    10,   211,   253,  -212,  -212,   244,   216,   217,
     425,   447,   239,   410,   386,   410,  -212,   215,   410,  -212,
    -212,  -212,  -212,  -212,  -212,   246,    10,    10,   246,   259,
    -212,  -212,    10,   246,   246,   182,    10,   410,   410,  -212,
    -212,  -212,   182,   182,   410,   523,   222,   230,   638,  -212,
     231,   583,  -212,   246,   246,  -212,   410,   109,   270,   246,
    -212,  -212,  -212,   182,   656,   674,   265,  -212,   489,  -212,
    -212,   245,   268,   256,   410,  -212,  -212,   543,  -212,   297,
    -212,  -212,  -212,   260,   264,   182,   410,  -212,   410,  -212,
    -212,  -212,  -212,    10,    10,  -212,   469,   563,   182,   182,
     182,  -212,  -212,  -212,  -212
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
      10,     0,     0,     0,     0,     0,    54,     7,    44,   114,
     140,   134,   135,   139,   136,   137,   138,     0,     0,     0,
       0,     9,     0,   111,   112,   113,   131,   130,   132,   114,
       0,    42,     0,     0,    40,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     7,     0,     7,     0,     0,     0,
       0,   129,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    60,     7,
       0,     0,     0,     0,     7,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,   143,
     146,     0,   145,     0,    16,     8,   133,   120,   122,   121,
     123,   124,   125,   115,   116,   117,   118,   119,   126,   127,
      59,     0,     7,    39,    41,     7,     0,    27,     7,     0,
       0,     0,     0,     7,     7,     0,     0,    48,     0,     0,
       0,    47,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    87,     0,     0,    79,    80,    81,
      82,    84,    85,    86,    83,   142,     0,   141,    24,     0,
       0,    22,     0,    26,     7,     0,     0,     7,     0,     0,
       7,     7,     7,     0,     0,    89,    71,     0,   100,   102,
       0,     0,     0,     0,     0,     0,    73,     0,     0,    68,
      78,   144,    23,    25,    21,     0,     7,     7,     0,     0,
      37,    35,     7,     0,     0,     0,     7,     0,     0,    70,
      99,   101,     0,     0,     0,    93,     0,     0,     0,    72,
       0,   108,    32,     0,     0,    30,     0,     0,     0,     0,
      36,    34,    51,     0,     0,     0,    97,    95,     0,    90,
     110,     0,    92,   106,     0,    31,    33,   104,    76,     0,
      75,    29,    52,     0,     0,     0,     0,   109,     0,   105,
     107,   103,    74,     7,     7,    98,     0,    94,     0,     0,
       0,    91,    53,    50,    96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,  -212,   315,    -5,  -212,    85,  -212,  -212,  -212,  -212,
    -212,   -53,  -212,  -212,   112,  -212,  -212,  -212,  -212,   -26,
     -99,   232,  -212,   -59,  -212,  -212,  -204,  -182,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,    47,  -212,    57,  -212,   -51,
    -212,  -212,    56,  -212,  -212,  -212,  -211,  -212
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    10,    11,    19,    20,    21,    44,    22,
      47,    93,    94,    95,    49,    50,    51,    52,    67,    38,
      39,    40,    41,   148,   203,   204,   260,   205,   206,   207,
     208,   209,   210,   211,   212,   288,   213,   280,   214,   150,
      83,    84,    85,    86,    87,    88,   151,   152
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    13,    58,   141,    27,   251,    23,    82,    90,    98,
     100,   103,   237,     5,     8,    14,    91,    16,    42,   247,
     243,    17,    18,    45,   250,   261,   110,    65,   192,   113,
     122,   123,   124,   277,   189,   244,     7,   245,   180,    92,
       9,   183,     2,   186,    15,   193,   194,    43,   195,   196,
     197,   282,    46,   198,   285,   199,    66,   200,   153,   290,
     291,    28,   107,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   177,   287,   173,   305,
     306,    26,   225,   226,   187,   311,   230,   191,   201,   192,
     202,   190,   135,   144,     1,    48,    91,    24,    25,   143,
       8,   146,     8,    56,     8,    53,   174,   194,   236,   195,
     196,   197,   218,   108,   198,   109,   199,   221,   200,    99,
     223,     2,   145,   192,   171,   286,     9,   308,     9,   176,
       9,   179,    59,   235,   111,   112,    54,    55,   -77,   234,
     -77,   194,   -77,   195,   196,   197,   240,   241,   198,   201,
     199,   202,   200,   134,   105,   178,    60,   106,    61,    62,
     252,   253,    68,   254,   131,    63,    64,   219,   104,   130,
     220,   133,   129,   222,   136,   132,   138,     8,   228,   229,
     192,    96,   137,   201,   -77,   202,    30,    31,    32,    33,
      34,    35,   275,   139,   278,     8,   142,   281,   194,   147,
     195,   196,   197,     9,   172,   198,   292,   199,    91,   200,
      91,   175,   184,   296,   297,   181,   294,   295,   182,   255,
     101,     9,   258,   298,   188,   263,   264,   265,   215,   224,
     227,   231,   216,    97,   312,   307,   238,   239,   233,   140,
     201,   246,   202,    30,    31,    32,    33,    34,   262,    91,
     232,   283,   284,   281,   267,   242,   325,   289,   249,   256,
     192,   293,   248,   259,   269,   326,   257,   327,   266,   332,
     333,   334,   102,   270,   271,   286,   274,   279,   194,   300,
     195,   196,   197,   301,   303,   198,   154,   199,   310,   200,
     315,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   317,   125,   126,   318,    30,    31,    32,    33,
      34,    35,   268,   319,    69,   322,     6,   323,   328,   329,
     201,   324,   202,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   309,   125,   126,   120,   121,   122,
     123,   124,   155,    70,    71,    72,    73,    74,    75,    76,
      77,    89,    30,    31,    32,    33,    34,    35,    78,   185,
     170,   320,    79,     0,     0,    80,     0,    29,     0,     0,
      81,    30,    31,    32,    33,    34,    35,    36,    37,   -14,
      70,    71,    72,    73,    74,    75,    76,    89,   -14,   -14,
     -14,     0,   -14,     0,     0,    78,     0,     0,     0,    79,
       0,     0,    80,   149,     0,   -14,     0,     0,     0,     0,
       0,    89,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    57,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,    79,     0,     0,    80,   276,
      70,    71,    72,    73,    74,    75,    76,     0,     0,   272,
       0,     0,     0,     0,     0,    78,     0,     0,     0,    79,
       0,     0,    80,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   273,   125,   126,     0,    70,    71,
      72,    73,    74,    75,    76,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   330,   125,   126,     0,
      80,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   316,   125,
     126,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
     126,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,     0,     0,     0,     0,     0,
     127,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,     0,     0,     0,     0,     0,
     299,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,     0,     0,     0,     0,     0,
     321,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,     0,     0,     0,     0,     0,
     331,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,     0,     0,     0,     0,   304,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,   126,     0,     0,     0,   128,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,     0,     0,     0,   217,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   126,
       0,     0,     0,   302,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,   126,     0,     0,
       0,   313,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,   126,     0,     0,     0,   314,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,   126,     0,   156,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   126,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    29,   125,     0,     0,    30,    31,    32,    33,    34,
      35,    36,    37,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   114,   115,   116,   117,     0,     0,
     120,   121,   122,   123,   124
};

static const yytype_int16 yycheck[] =
{
       5,     6,    28,   102,     1,   216,    11,    58,    59,    62,
      63,    64,   194,     1,     4,     1,    30,    58,     1,   201,
      37,    14,    15,     1,   206,   229,    77,     1,     1,    80,
      46,    47,    48,   244,     1,    52,     0,    54,   137,    53,
      30,   140,    30,   142,    30,    18,    19,    30,    21,    22,
      23,   255,    30,    26,   258,    28,    30,    30,   109,   263,
     264,    58,    67,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   135,   259,   131,   283,
     284,    57,   181,   182,   143,   289,   185,   146,    61,     1,
      63,    58,    97,     1,     3,    13,    30,    12,    13,   104,
       4,   106,     4,    57,     4,    20,   132,    19,    20,    21,
      22,    23,   171,    52,    26,    54,    28,   176,    30,    53,
     179,    30,    30,     1,   129,    16,    30,    18,    30,   134,
      30,   136,    54,   192,    78,    79,    24,    25,    16,   190,
      18,    19,    20,    21,    22,    23,   197,   198,    26,    61,
      28,    63,    30,    57,    54,    57,    57,    57,    52,    52,
     219,   220,    50,   222,    56,    52,    52,   172,    57,    53,
     175,    53,    57,   178,    53,    58,    53,     4,   183,   184,
       1,     1,    58,    61,    62,    63,     5,     6,     7,     8,
       9,    10,   243,    53,   245,     4,    53,   248,    19,    17,
      21,    22,    23,    30,    57,    26,   265,    28,    30,    30,
      30,    57,    57,   272,   273,    58,   267,   268,    58,   224,
       1,    30,   227,   274,    55,   230,   231,   232,    53,    57,
      57,    57,    56,    53,   293,   286,    30,    30,    55,    58,
      61,    62,    63,     5,     6,     7,     8,     9,    57,    30,
      57,   256,   257,   304,     1,    30,   315,   262,    18,    57,
       1,   266,    52,    17,    20,   316,    57,   318,    57,   328,
     329,   330,    53,    57,    57,    16,    37,    62,    19,    57,
      21,    22,    23,    53,    53,    26,     1,    28,    18,    30,
      25,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    57,    50,    51,    37,     5,     6,     7,     8,
       9,    10,    59,    57,     1,    18,     1,    57,   323,   324,
      61,    57,    63,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,   287,    50,    51,    44,    45,    46,
      47,    48,    57,    30,    31,    32,    33,    34,    35,    36,
      37,     1,     5,     6,     7,     8,     9,    10,    45,    58,
     128,   304,    49,    -1,    -1,    52,    -1,     1,    -1,    -1,
      57,     5,     6,     7,     8,     9,    10,    11,    12,     4,
      30,    31,    32,    33,    34,    35,    36,     1,    13,    14,
      15,    -1,    17,    -1,    -1,    45,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    -1,    30,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    49,
      -1,    -1,    52,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    27,    50,    51,    -1,    30,    31,
      32,    33,    34,    35,    36,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    27,    50,    51,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    29,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      57,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      57,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      57,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      57,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    -1,    -1,    55,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    -1,    -1,    -1,    55,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    -1,    55,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    -1,    -1,
      -1,    55,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    -1,    -1,    -1,    55,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    53,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     1,    50,    -1,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    38,    39,    40,    41,    -1,    -1,
      44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    30,    67,    68,     1,    68,     0,     4,    30,
      69,    70,    69,    69,     1,    30,    58,    14,    15,    71,
      72,    73,    75,    69,    71,    71,    57,     1,    58,     1,
       5,     6,     7,     8,     9,    10,    11,    12,    85,    86,
      87,    88,     1,    30,    74,     1,    30,    76,    13,    80,
      81,    82,    83,    71,    80,    80,    57,    57,    85,    54,
      57,    52,    52,    52,    52,     1,    30,    84,    80,     1,
      30,    31,    32,    33,    34,    35,    36,    37,    45,    49,
      52,    57,   105,   106,   107,   108,   109,   110,   111,     1,
     105,    30,    53,    77,    78,    79,     1,    53,    77,    53,
      77,     1,    53,    77,    57,    54,    57,    69,    52,    54,
     105,   108,   108,   105,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    50,    51,    57,    55,    57,
      53,    56,    58,    53,    57,    69,    53,    58,    53,    53,
      58,    86,    53,    69,     1,    30,    69,    17,    89,    53,
     105,   112,   113,   105,     1,    57,    53,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
      87,    69,    57,    77,    85,    57,    69,    89,    57,    69,
      86,    58,    58,    86,    57,    58,    86,    89,    55,     1,
      58,    89,     1,    18,    19,    21,    22,    23,    26,    28,
      30,    61,    63,    90,    91,    93,    94,    95,    96,    97,
      98,    99,   100,   102,   104,    53,    56,    55,    89,    69,
      69,    89,    69,    89,    57,    86,    86,    57,    69,    69,
      86,    57,    57,    55,   105,    89,    20,    93,    30,    30,
     105,   105,    30,    37,    52,    54,    62,    93,    52,    18,
      93,   112,    89,    89,    89,    69,    57,    57,    69,    17,
      92,    92,    57,    69,    69,    69,    57,     1,    59,    20,
      57,    57,    24,    27,    37,   105,    53,   112,   105,    62,
     103,   105,    92,    69,    69,    92,    16,    93,   101,    69,
      92,    92,    89,    69,   105,   105,    89,    89,   105,    57,
      57,    53,    55,    53,    56,    92,    92,   105,    18,   101,
      18,    92,    89,    55,    55,    25,    29,    57,    37,    57,
     103,    57,    18,    57,    57,    89,   105,   105,    69,    69,
      27,    57,    89,    89,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    67,    67,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    76,    77,
      77,    78,    79,    80,    80,    81,    81,    82,    82,    82,
      83,    83,    83,    83,    84,    85,    85,    85,    86,    86,
      86,    87,    87,    87,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    92,    92,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    95,    95,    95,    96,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   105,   105,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   107,   107,
     108,   108,   108,   108,   109,   109,   109,   109,   109,   109,
     110,   110,   111,   111,   112,   112,   113
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     7,     4,     3,     6,     4,     8,     4,     6,     3,
       2,     3,     2,     3,     2,     5,     4,     3,     1,     5,
       4,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     3,     3,     1,     1
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
#line 237 "src/parser/parser.y"
                                                                          {
        // -- Crear AST (solo si no hay errores sintacticos)
        if(!have_syntax_errors())
            AST_program = create_program((yyvsp[-3].ident),(yyvsp[-2].decl),(yyvsp[-1].subprog),(yyvsp[0].proc));
    }
#line 1540 "src/parser/parser.c"
    break;

  case 3: /* program: program-name list-declarations list-subprograms list-process  */
#line 243 "src/parser/parser.y"
                                                                  {
        mark_error_syntax_program_expected_program((yyvsp[-3].ident));
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }
#line 1550 "src/parser/parser.c"
    break;

  case 4: /* program: S_PROGRAM error list-declarations list-subprograms list-process  */
#line 249 "src/parser/parser.y"
                                                                     {
        mark_error_syntax_program_expected_identifier();
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }
#line 1560 "src/parser/parser.c"
    break;

  case 5: /* program-name: IDENT  */
#line 257 "src/parser/parser.y"
         { 
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1568 "src/parser/parser.c"
    break;

  case 6: /* list-declarations: declaration list-declarations  */
#line 266 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.decl) = (yyvsp[-1].decl);
            (yyvsp[-1].decl)->next = (yyvsp[0].decl);
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1582 "src/parser/parser.c"
    break;

  case 7: /* list-declarations: %empty  */
#line 275 "src/parser/parser.y"
                   {
        (yyval.decl) = 0;
    }
#line 1590 "src/parser/parser.c"
    break;

  case 8: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression DELIM_PC  */
#line 282 "src/parser/parser.y"
                                                           {
        if(!have_syntax_errors()){
            (yyval.decl) = create_declaration_variable((yyvsp[-5].ident), (yyvsp[-3].type), (yyvsp[-1].expr), yylineno);
            add_declaration_to_register((yyval.decl));
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1604 "src/parser/parser.c"
    break;

  case 9: /* declaration: S_VAR IDENT DELIM_2P type DELIM_PC  */
#line 292 "src/parser/parser.y"
                                        {
        if(!have_syntax_errors()){
            (yyval.decl) = create_declaration_variable((yyvsp[-3].ident), (yyvsp[-1].type), 0, yylineno);
            add_declaration_to_register((yyval.decl));
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1618 "src/parser/parser.c"
    break;

  case 10: /* declaration: IDENT DELIM_2P type DELIM_PC  */
#line 302 "src/parser/parser.y"
                                  {
        mark_error_syntax_declaration_expected_var((yyvsp[-3].ident));
        // Recuperar
        //YYABORT;
    }
#line 1628 "src/parser/parser.c"
    break;

  case 11: /* declaration: S_VAR error DELIM_PC  */
#line 308 "src/parser/parser.y"
                          {
        mark_error_syntax_declaration_expected_identifier();
        //YYABORT;
    }
#line 1637 "src/parser/parser.c"
    break;

  case 12: /* declaration: S_VAR IDENT error DELIM_PC  */
#line 313 "src/parser/parser.y"
                                {
        mark_error_syntax_declaration_expected_delim2p((yyvsp[-2].ident));
        //YYABORT;
    }
#line 1646 "src/parser/parser.c"
    break;

  case 13: /* declaration: S_VAR IDENT DELIM_2P DELIM_PC  */
#line 318 "src/parser/parser.y"
                                   {
        mark_error_syntax_type_expected_type((yyvsp[-2].ident));
        //YYABORT;
    }
#line 1655 "src/parser/parser.c"
    break;

  case 14: /* declaration: S_VAR IDENT DELIM_2P type error  */
#line 323 "src/parser/parser.y"
                                     {
        mark_error_syntax_declaration_expected_delimpc((yyvsp[-3].ident));
        free_AST_type_register((yyvsp[-1].type));
        //YYABORT;
    }
#line 1665 "src/parser/parser.c"
    break;

  case 15: /* declaration: S_VAR IDENT DELIM_2P type expression DELIM_PC  */
#line 329 "src/parser/parser.y"
                                                   {
        mark_error_syntax_declaration_expected_opassign((yyvsp[-4].ident));
        //YYABORT;
    }
#line 1674 "src/parser/parser.c"
    break;

  case 16: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression error  */
#line 334 "src/parser/parser.y"
                                                          {
        mark_error_syntax_declaration_expected_delimpc((yyvsp[-5].ident));
        //YYABORT;
    }
#line 1683 "src/parser/parser.c"
    break;

  case 17: /* list-subprograms: subprogram list-subprograms  */
#line 344 "src/parser/parser.y"
                               {
        if(!have_syntax_errors()){
            (yyval.subprog) = (yyvsp[-1].subprog);
            (yyvsp[-1].subprog)->next = (yyvsp[0].subprog);
        }
        else{
            (yyval.subprog) = 0;
        }
    }
#line 1697 "src/parser/parser.c"
    break;

  case 18: /* list-subprograms: %empty  */
#line 353 "src/parser/parser.y"
                   {
        (yyval.subprog) = 0;
    }
#line 1705 "src/parser/parser.c"
    break;

  case 19: /* subprogram: subprogram-procedure  */
#line 359 "src/parser/parser.y"
                        {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1713 "src/parser/parser.c"
    break;

  case 20: /* subprogram: subprogram-function  */
#line 362 "src/parser/parser.y"
                         {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1721 "src/parser/parser.c"
    break;

  case 21: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 369 "src/parser/parser.y"
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
#line 1736 "src/parser/parser.c"
    break;

  case 22: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 380 "src/parser/parser.y"
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
#line 1752 "src/parser/parser.c"
    break;

  case 23: /* subprogram-procedure: S_PROCEDURE error PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 392 "src/parser/parser.y"
                                                                                                               {
        mark_error_syntax_subprogram_procedure_expected_identifier();
        //YYABORT;
    }
#line 1761 "src/parser/parser.c"
    break;

  case 24: /* subprogram-procedure: S_PROCEDURE error PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 397 "src/parser/parser.y"
                                                                                               {
        // -- Mostrar error
        mark_error_syntax_subprogram_procedure_expected_identifier();
        // -- Abortar inmediatmente el analisis
        //YYABORT;
    }
#line 1772 "src/parser/parser.c"
    break;

  case 25: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO error PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 404 "src/parser/parser.y"
                                                                                                                         {
        mark_error_syntax_subprogram_procedure_expected_parameters((yyvsp[-6].ident));
        //YYABORT;
    }
#line 1781 "src/parser/parser.c"
    break;

  case 26: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO list-declarations block-statements-begin-end  */
#line 409 "src/parser/parser.y"
                                                                                                                          {
        mark_error_syntax_subprogram_procedure_expected_delimpc((yyvsp[-5].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1791 "src/parser/parser.c"
    break;

  case 27: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO list-declarations block-statements-begin-end  */
#line 415 "src/parser/parser.y"
                                                                                                          {
        mark_error_syntax_subprogram_procedure_expected_delimpc((yyvsp[-4].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1801 "src/parser/parser.c"
    break;

  case 28: /* subprogram-procedure-name: IDENT  */
#line 423 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1809 "src/parser/parser.c"
    break;

  case 29: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 430 "src/parser/parser.y"
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
#line 1835 "src/parser/parser.c"
    break;

  case 30: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 452 "src/parser/parser.y"
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
#line 1861 "src/parser/parser.c"
    break;

  case 31: /* subprogram-function: S_FUNCTION error PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 474 "src/parser/parser.y"
                                                                                                                                          {
        mark_error_syntax_subprogram_function_expected_identifier();
        //YYABORT;
    }
#line 1870 "src/parser/parser.c"
    break;

  case 32: /* subprogram-function: S_FUNCTION error PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 479 "src/parser/parser.y"
                                                                                                                          {
        mark_error_syntax_subprogram_function_expected_identifier();
        //YYABORT;
    }
#line 1879 "src/parser/parser.c"
    break;

  case 33: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO error PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 484 "src/parser/parser.y"
                                                                                                                                                   {
        mark_error_syntax_subprogram_function_expected_parameters((yyvsp[-8].ident));
        //YYABORT;
    }
#line 1888 "src/parser/parser.c"
    break;

  case 34: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 489 "src/parser/parser.y"
                                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delim2p((yyvsp[-7].ident));
        //YYABORT;
    }
#line 1897 "src/parser/parser.c"
    break;

  case 35: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 494 "src/parser/parser.y"
                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delim2p((yyvsp[-6].ident));
        //YYABORT;
    }
#line 1906 "src/parser/parser.c"
    break;

  case 36: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type list-declarations block-statements-function  */
#line 499 "src/parser/parser.y"
                                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delimpc((yyvsp[-7].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1916 "src/parser/parser.c"
    break;

  case 37: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type list-declarations block-statements-function  */
#line 505 "src/parser/parser.y"
                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delimpc((yyvsp[-6].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1926 "src/parser/parser.c"
    break;

  case 38: /* subprogram-function-name: IDENT  */
#line 513 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1934 "src/parser/parser.c"
    break;

  case 39: /* list-parameters: parameter DELIM_C list-parameters  */
#line 522 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.param) = (yyvsp[-2].param);
            (yyvsp[-2].param)->next = (yyvsp[0].param);
        }
        else{
            (yyval.param) = 0;
        }
    }
#line 1948 "src/parser/parser.c"
    break;

  case 40: /* list-parameters: parameter  */
#line 531 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.param) = (yyvsp[0].param);
        }
        else{
            (yyval.param) = 0;
        }
    }
#line 1961 "src/parser/parser.c"
    break;

  case 41: /* parameter: parameter-name DELIM_2P type  */
#line 543 "src/parser/parser.y"
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
#line 1977 "src/parser/parser.c"
    break;

  case 42: /* parameter-name: IDENT  */
#line 557 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1985 "src/parser/parser.c"
    break;

  case 43: /* list-process: process  */
#line 566 "src/parser/parser.y"
           {
        if(!have_syntax_errors()){
            (yyval.proc) = (yyvsp[0].proc);
        }
        else{
            (yyval.proc) = 0;
        }
    }
#line 1998 "src/parser/parser.c"
    break;

  case 44: /* list-process: process list-process  */
#line 574 "src/parser/parser.y"
                          {
        if(!have_syntax_errors()){
            (yyval.proc) = (yyvsp[-1].proc);
            (yyvsp[-1].proc)->next = (yyvsp[0].proc);
        }
        else{
            (yyval.proc) = 0;
        }
    }
#line 2012 "src/parser/parser.c"
    break;

  case 45: /* process: process-def  */
#line 586 "src/parser/parser.y"
               {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 2020 "src/parser/parser.c"
    break;

  case 46: /* process: process-def-array  */
#line 589 "src/parser/parser.y"
                       {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 2028 "src/parser/parser.c"
    break;

  case 47: /* process-def: S_PROCESS process-name DELIM_PC list-declarations block-statements-begin-end  */
#line 596 "src/parser/parser.y"
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
#line 2044 "src/parser/parser.c"
    break;

  case 48: /* process-def: S_PROCESS error DELIM_PC list-declarations block-statements-begin-end  */
#line 608 "src/parser/parser.y"
                                                                           {
        mark_error_syntax_process_expected_identifier();
        //YYABORT;
    }
#line 2053 "src/parser/parser.c"
    break;

  case 49: /* process-def: S_PROCESS process-name list-declarations block-statements-begin-end  */
#line 613 "src/parser/parser.y"
                                                                         {
        mark_error_syntax_process_expected_delimpc((yyvsp[-2].ident));
        //YYABORT;
    }
#line 2062 "src/parser/parser.c"
    break;

  case 50: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 621 "src/parser/parser.y"
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
#line 2077 "src/parser/parser.c"
    break;

  case 51: /* process-def-array: S_PROCESS process-name CORCH_IZDO error CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 632 "src/parser/parser.y"
                                                                                                              {
        mark_error_syntax_process_expected_index_identifier((yyvsp[-6].ident));
        //YYABORT;
    }
#line 2086 "src/parser/parser.c"
    break;

  case 52: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT error CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 637 "src/parser/parser.y"
                                                                                                                    {
        mark_error_syntax_process_expected_delim2p((yyvsp[-7].ident));
        //YYABORT;
    }
#line 2095 "src/parser/parser.c"
    break;

  case 53: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression error expression CORCH_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 642 "src/parser/parser.y"
                                                                                                                                                   {
        mark_error_syntax_process_expected_delimarr((yyvsp[-10].ident));
        //YYABORT;
    }
#line 2104 "src/parser/parser.c"
    break;

  case 54: /* process-name: IDENT  */
#line 649 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 2112 "src/parser/parser.c"
    break;

  case 55: /* type: basic-or-array-type  */
#line 658 "src/parser/parser.y"
                       {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2120 "src/parser/parser.c"
    break;

  case 56: /* type: special-type  */
#line 661 "src/parser/parser.y"
                  {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2128 "src/parser/parser.c"
    break;

  case 57: /* type: error  */
#line 664 "src/parser/parser.y"
           {
        mark_error_syntax_type_expected_type();
        //YYABORT;
    }
#line 2137 "src/parser/parser.c"
    break;

  case 58: /* basic-or-array-type: basic-type  */
#line 671 "src/parser/parser.y"
              {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2145 "src/parser/parser.c"
    break;

  case 59: /* basic-or-array-type: T_ARRAY CORCH_IZDO expression CORCH_DCHO basic-type  */
#line 674 "src/parser/parser.y"
                                                         {
        if(!have_syntax_errors()){
            (yyval.type) = create_array_type((yyvsp[0].type),(yyvsp[-2].expr));
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2159 "src/parser/parser.c"
    break;

  case 60: /* basic-or-array-type: T_ARRAY CORCH_IZDO expression CORCH_DCHO  */
#line 684 "src/parser/parser.y"
                                              {
        mark_error_syntax_type_expected_type();
        //YYABORT;
    }
#line 2168 "src/parser/parser.c"
    break;

  case 61: /* basic-type: T_INTEGER  */
#line 691 "src/parser/parser.y"
             {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_INTEGER);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2182 "src/parser/parser.c"
    break;

  case 62: /* basic-type: T_BOOLEAN  */
#line 700 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_BOOLEAN);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2196 "src/parser/parser.c"
    break;

  case 63: /* basic-type: T_CHAR  */
#line 709 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_CHAR);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2210 "src/parser/parser.c"
    break;

  case 64: /* basic-type: T_STRING  */
#line 718 "src/parser/parser.y"
              {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_STRING);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2224 "src/parser/parser.c"
    break;

  case 65: /* basic-type: T_REAL  */
#line 727 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_REAL);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2238 "src/parser/parser.c"
    break;

  case 66: /* special-type: T_SEMAPHORE  */
#line 739 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.type) = create_semaphore_type();
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2252 "src/parser/parser.c"
    break;

  case 67: /* special-type: T_DPROCESS  */
#line 748 "src/parser/parser.y"
                {
        if(!have_syntax_errors()){
            (yyval.type) = create_dprocess_type();
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2266 "src/parser/parser.c"
    break;

  case 68: /* block-statements-begin-end: B_BEGIN list-statements B_END  */
#line 764 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2280 "src/parser/parser.c"
    break;

  case 69: /* block-statements-begin-end: B_BEGIN B_END  */
#line 774 "src/parser/parser.y"
                   {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2289 "src/parser/parser.c"
    break;

  case 70: /* block-statements-cobegin-coend: B_COBEGIN list-statements B_COEND  */
#line 782 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_cobegin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2303 "src/parser/parser.c"
    break;

  case 71: /* block-statements-cobegin-coend: B_COBEGIN B_COEND  */
#line 792 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2312 "src/parser/parser.c"
    break;

  case 72: /* block-statements-atomic: ATOM_INI list-statements ATOM_FIN  */
#line 800 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_atomic((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2326 "src/parser/parser.c"
    break;

  case 73: /* block-statements-atomic: ATOM_INI ATOM_FIN  */
#line 810 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2335 "src/parser/parser.c"
    break;

  case 74: /* block-statements-function: B_BEGIN list-statements return-statement B_END  */
#line 818 "src/parser/parser.y"
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
#line 2354 "src/parser/parser.c"
    break;

  case 75: /* block-statements-function: B_BEGIN return-statement B_END  */
#line 833 "src/parser/parser.y"
                                    {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2368 "src/parser/parser.c"
    break;

  case 76: /* block-statements-function: B_BEGIN list-statements B_END  */
#line 843 "src/parser/parser.y"
                                   {
        mark_error_syntax_statement_non_return_in_block();
        //YYABORT;
    }
#line 2377 "src/parser/parser.c"
    break;

  case 77: /* list-statements: statement  */
#line 850 "src/parser/parser.y"
             {
        if(!have_syntax_errors()){
            (yyval.stmt) = (yyvsp[0].stmt);
        }
        else{
            (yyval.stmt) = 0;
        }
        
    }
#line 2391 "src/parser/parser.c"
    break;

  case 78: /* list-statements: statement list-statements  */
#line 859 "src/parser/parser.y"
                               {
        if(!have_syntax_errors()){
            (yyval.stmt) = (yyvsp[-1].stmt);
            (yyvsp[-1].stmt)->next = (yyvsp[0].stmt);
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2405 "src/parser/parser.c"
    break;

  case 79: /* statement: assignment-statement  */
#line 871 "src/parser/parser.y"
                        {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2413 "src/parser/parser.c"
    break;

  case 80: /* statement: while-statement  */
#line 874 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2421 "src/parser/parser.c"
    break;

  case 81: /* statement: for-statement  */
#line 877 "src/parser/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2429 "src/parser/parser.c"
    break;

  case 82: /* statement: if-statement  */
#line 880 "src/parser/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2437 "src/parser/parser.c"
    break;

  case 83: /* statement: procedure-call-statement  */
#line 883 "src/parser/parser.y"
                              {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2445 "src/parser/parser.c"
    break;

  case 84: /* statement: fork-statement  */
#line 886 "src/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2453 "src/parser/parser.c"
    break;

  case 85: /* statement: join-statement  */
#line 889 "src/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2461 "src/parser/parser.c"
    break;

  case 86: /* statement: print-statement  */
#line 892 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2469 "src/parser/parser.c"
    break;

  case 87: /* statement: block-statements-atomic  */
#line 895 "src/parser/parser.y"
                             {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2477 "src/parser/parser.c"
    break;

  case 88: /* statement: block-statements-cobegin-coend  */
#line 898 "src/parser/parser.y"
                                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2485 "src/parser/parser.c"
    break;

  case 89: /* statement: error block-statements-begin-end  */
#line 901 "src/parser/parser.y"
                                      {
        mark_error_syntax_statement_expected_statement();
    }
#line 2493 "src/parser/parser.c"
    break;

  case 90: /* assignment-statement: IDENT OP_ASSIGN expression DELIM_PC  */
#line 908 "src/parser/parser.y"
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
#line 2508 "src/parser/parser.c"
    break;

  case 91: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression DELIM_PC  */
#line 919 "src/parser/parser.y"
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
#line 2523 "src/parser/parser.c"
    break;

  case 92: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO  */
#line 930 "src/parser/parser.y"
                                            {
        mark_error_syntax_statement_expected_statement();
        //YYABORT;
    }
#line 2532 "src/parser/parser.c"
    break;

  case 93: /* assignment-statement: IDENT OP_ASSIGN expression  */
#line 935 "src/parser/parser.y"
                                {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2541 "src/parser/parser.c"
    break;

  case 94: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression  */
#line 940 "src/parser/parser.y"
                                                                 {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2550 "src/parser/parser.c"
    break;

  case 95: /* while-statement: WHILE expression DO block-statements-begin-end  */
#line 948 "src/parser/parser.y"
                                                  {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_while((yyvsp[-2].expr), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2564 "src/parser/parser.c"
    break;

  case 96: /* for-statement: FOR IDENT OP_ASSIGN expression TO expression DO block-statements-begin-end  */
#line 961 "src/parser/parser.y"
                                                                              {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_for((yyvsp[-6].ident), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2578 "src/parser/parser.c"
    break;

  case 97: /* if-statement: IF expression THEN block-statements-begin-end  */
#line 975 "src/parser/parser.y"
                                                 {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_if_else((yyvsp[-2].expr), (yyvsp[0].stmt), 0, yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2592 "src/parser/parser.c"
    break;

  case 98: /* if-statement: IF expression THEN block-statements-begin-end ELSE block-statements-begin-end  */
#line 985 "src/parser/parser.y"
                                                                                   {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_if_else((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2606 "src/parser/parser.c"
    break;

  case 99: /* fork-statement: S_FORK IDENT DELIM_PC  */
#line 998 "src/parser/parser.y"
                         {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_fork((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2620 "src/parser/parser.c"
    break;

  case 100: /* fork-statement: S_FORK IDENT  */
#line 1008 "src/parser/parser.y"
                  {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2629 "src/parser/parser.c"
    break;

  case 101: /* join-statement: JOIN IDENT DELIM_PC  */
#line 1016 "src/parser/parser.y"
                       {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_join((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2643 "src/parser/parser.c"
    break;

  case 102: /* join-statement: JOIN IDENT  */
#line 1026 "src/parser/parser.y"
                {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2652 "src/parser/parser.c"
    break;

  case 103: /* return-statement: RETURN expression DELIM_PC  */
#line 1034 "src/parser/parser.y"
                              {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_return((yyvsp[-1].expr), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2666 "src/parser/parser.c"
    break;

  case 104: /* return-statement: RETURN expression  */
#line 1044 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2675 "src/parser/parser.c"
    break;

  case 105: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO DELIM_PC  */
#line 1052 "src/parser/parser.y"
                                               {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_print((yyvsp[-2].expr));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2689 "src/parser/parser.c"
    break;

  case 106: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO  */
#line 1062 "src/parser/parser.y"
                                        {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2698 "src/parser/parser.c"
    break;

  case 107: /* list-print: expression DELIM_C list-print  */
#line 1069 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[-2].expr);
            (yyvsp[-2].expr)->next = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2712 "src/parser/parser.c"
    break;

  case 108: /* list-print: expression  */
#line 1078 "src/parser/parser.y"
                {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2725 "src/parser/parser.c"
    break;

  case 109: /* procedure-call-statement: IDENT PAR_IZDO list-arguments PAR_DCHO DELIM_PC  */
#line 1090 "src/parser/parser.y"
                                                   {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_procedure_inv((yyvsp[-4].ident), (yyvsp[-2].expr), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2739 "src/parser/parser.c"
    break;

  case 110: /* procedure-call-statement: IDENT PAR_IZDO PAR_DCHO DELIM_PC  */
#line 1100 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_procedure_inv((yyvsp[-3].ident), 0, yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2753 "src/parser/parser.c"
    break;

  case 111: /* expression: binary-expression  */
#line 1115 "src/parser/parser.y"
                     {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2761 "src/parser/parser.c"
    break;

  case 112: /* expression: unary-expression  */
#line 1118 "src/parser/parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2769 "src/parser/parser.c"
    break;

  case 113: /* expression: term  */
#line 1121 "src/parser/parser.y"
          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2777 "src/parser/parser.c"
    break;

  case 114: /* expression: error  */
#line 1124 "src/parser/parser.y"
            {
        mark_error_syntax_expression_expected_expr();
        YYABORT;
    }
#line 2786 "src/parser/parser.c"
    break;

  case 115: /* binary-expression: expression OP_SUM expression  */
#line 1132 "src/parser/parser.y"
                                {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_ADD, "+", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2800 "src/parser/parser.c"
    break;

  case 116: /* binary-expression: expression OP_MINUS expression  */
#line 1142 "src/parser/parser.y"
                                    {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_SUB, "-", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2814 "src/parser/parser.c"
    break;

  case 117: /* binary-expression: expression OP_MULT expression  */
#line 1152 "src/parser/parser.y"
                                   {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_MULT, "*", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2828 "src/parser/parser.c"
    break;

  case 118: /* binary-expression: expression OP_DIV expression  */
#line 1162 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_DIV, "/", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2842 "src/parser/parser.c"
    break;

  case 119: /* binary-expression: expression OP_MOD expression  */
#line 1172 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_MOD, "%", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2856 "src/parser/parser.c"
    break;

  case 120: /* binary-expression: expression OP_REL_LT expression  */
#line 1182 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_LT, "<", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2870 "src/parser/parser.c"
    break;

  case 121: /* binary-expression: expression OP_REL_LTE expression  */
#line 1192 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_LTE, "<=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2884 "src/parser/parser.c"
    break;

  case 122: /* binary-expression: expression OP_REL_GT expression  */
#line 1202 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_GT, ">", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2898 "src/parser/parser.c"
    break;

  case 123: /* binary-expression: expression OP_REL_GTE expression  */
#line 1212 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_GTE, ">=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2912 "src/parser/parser.c"
    break;

  case 124: /* binary-expression: expression OP_REL_EQ expression  */
#line 1222 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_EQ, "==", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2926 "src/parser/parser.c"
    break;

  case 125: /* binary-expression: expression OP_REL_NEQ expression  */
#line 1232 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_NEQ, "!=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
       
    }
#line 2941 "src/parser/parser.c"
    break;

  case 126: /* binary-expression: expression OP_AND expression  */
#line 1243 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_AND, "and", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2955 "src/parser/parser.c"
    break;

  case 127: /* binary-expression: expression OP_OR expression  */
#line 1253 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_OR, "or", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2969 "src/parser/parser.c"
    break;

  case 128: /* unary-expression: OP_NOT term  */
#line 1266 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_unary_operation(EXPR_NOT, "not", (yyvsp[0].expr),yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2983 "src/parser/parser.c"
    break;

  case 129: /* unary-expression: OP_MINUS term  */
#line 1276 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_unary_operation(EXPR_NEGATIVE, "-", (yyvsp[0].expr),yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2997 "src/parser/parser.c"
    break;

  case 130: /* term: expr-identifier  */
#line 1288 "src/parser/parser.y"
                   {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3005 "src/parser/parser.c"
    break;

  case 131: /* term: literal  */
#line 1291 "src/parser/parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3013 "src/parser/parser.c"
    break;

  case 132: /* term: function-call-expression  */
#line 1294 "src/parser/parser.y"
                              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3021 "src/parser/parser.c"
    break;

  case 133: /* term: PAR_IZDO expression PAR_DCHO  */
#line 1297 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_grouped((yyvsp[-1].expr));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3035 "src/parser/parser.c"
    break;

  case 134: /* literal: LITERAL  */
#line 1310 "src/parser/parser.y"
           {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_string((yyvsp[0].literal_string));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3049 "src/parser/parser.c"
    break;

  case 135: /* literal: L_INTEGER  */
#line 1319 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_integer((yyvsp[0].literal_int));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3063 "src/parser/parser.c"
    break;

  case 136: /* literal: L_BOOLEAN_TRUE  */
#line 1328 "src/parser/parser.y"
                    {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_boolean(1);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3077 "src/parser/parser.c"
    break;

  case 137: /* literal: L_BOOLEAN_FALSE  */
#line 1337 "src/parser/parser.y"
                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_boolean(0);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3091 "src/parser/parser.c"
    break;

  case 138: /* literal: L_CHAR  */
#line 1346 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_char((yyvsp[0].literal_char));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3105 "src/parser/parser.c"
    break;

  case 139: /* literal: L_REAL  */
#line 1355 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_real((yyvsp[0].literal_float));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3119 "src/parser/parser.c"
    break;

  case 140: /* expr-identifier: IDENT  */
#line 1367 "src/parser/parser.y"
         {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_identifier((yyvsp[0].ident),0, yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3133 "src/parser/parser.c"
    break;

  case 141: /* expr-identifier: IDENT CORCH_IZDO expression CORCH_DCHO  */
#line 1376 "src/parser/parser.y"
                                            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_identifier((yyvsp[-3].ident), (yyvsp[-1].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3147 "src/parser/parser.c"
    break;

  case 142: /* function-call-expression: IDENT PAR_IZDO list-arguments PAR_DCHO  */
#line 1389 "src/parser/parser.y"
                                          {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_function_invocation((yyvsp[-3].ident), (yyvsp[-1].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3161 "src/parser/parser.c"
    break;

  case 143: /* function-call-expression: IDENT PAR_IZDO PAR_DCHO  */
#line 1399 "src/parser/parser.y"
                             {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_function_invocation((yyvsp[-2].ident), 0, yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }

    }
#line 3176 "src/parser/parser.c"
    break;

  case 144: /* list-arguments: argument DELIM_C list-arguments  */
#line 1415 "src/parser/parser.y"
                                   {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[-2].expr);
            (yyvsp[-2].expr)->next = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3190 "src/parser/parser.c"
    break;

  case 145: /* list-arguments: argument  */
#line 1424 "src/parser/parser.y"
              {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3203 "src/parser/parser.c"
    break;

  case 146: /* argument: expression  */
#line 1435 "src/parser/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3211 "src/parser/parser.c"
    break;


#line 3215 "src/parser/parser.c"

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

#line 1440 "src/parser/parser.y"


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
