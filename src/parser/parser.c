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
  YYSYMBOL_93_block_statements_process = 93, /* block-statements-process  */
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
  YYSYMBOL_105_procedure_call_statement = 105, /* procedure-call-statement  */
  YYSYMBOL_expression = 106,               /* expression  */
  YYSYMBOL_107_binary_expression = 107,    /* binary-expression  */
  YYSYMBOL_108_unary_expression = 108,     /* unary-expression  */
  YYSYMBOL_term = 109,                     /* term  */
  YYSYMBOL_literal = 110,                  /* literal  */
  YYSYMBOL_111_expr_identifier = 111,      /* expr-identifier  */
  YYSYMBOL_112_function_call_expression = 112, /* function-call-expression  */
  YYSYMBOL_113_list_arguments = 113,       /* list-arguments  */
  YYSYMBOL_argument = 114                  /* argument  */
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
#define YYLAST   784

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  336

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
       0,   238,   238,   244,   250,   258,   267,   276,   283,   293,
     303,   309,   314,   319,   324,   330,   335,   345,   354,   360,
     363,   370,   381,   393,   398,   405,   410,   416,   424,   431,
     444,   457,   462,   467,   472,   477,   482,   488,   496,   505,
     514,   526,   540,   549,   557,   569,   572,   579,   591,   596,
     604,   615,   620,   625,   632,   641,   644,   647,   654,   657,
     667,   674,   683,   692,   701,   710,   722,   731,   747,   757,
     765,   775,   783,   793,   801,   812,   822,   829,   832,   838,
     847,   859,   862,   865,   868,   871,   874,   877,   880,   883,
     886,   893,   904,   915,   920,   925,   933,   946,   960,   970,
     983,   993,  1001,  1011,  1019,  1029,  1037,  1047,  1054,  1063,
    1075,  1085,  1100,  1103,  1106,  1109,  1117,  1127,  1137,  1147,
    1157,  1167,  1177,  1187,  1197,  1207,  1217,  1228,  1238,  1251,
    1261,  1273,  1276,  1279,  1282,  1295,  1304,  1313,  1322,  1331,
    1340,  1352,  1361,  1374,  1384,  1400,  1409,  1420
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
  "block-statements-function", "block-statements-process",
  "list-statements", "statement", "assignment-statement",
  "while-statement", "for-statement", "if-statement", "fork-statement",
  "join-statement", "return-statement", "print-statement", "list-print",
  "procedure-call-statement", "expression", "binary-expression",
  "unary-expression", "term", "literal", "expr-identifier",
  "function-call-expression", "list-arguments", "argument", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-142)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,    15,  -142,    32,    98,    98,    98,  -142,    21,   -37,
      74,    98,    74,    74,   -32,     6,   750,    23,    26,    16,
      74,  -142,  -142,  -142,    16,    16,  -142,    28,   346,  -142,
    -142,  -142,  -142,  -142,  -142,    41,  -142,  -142,    46,  -142,
    -142,  -142,    60,  -142,    68,    73,  -142,    83,    97,  -142,
      16,  -142,  -142,  -142,  -142,  -142,  -142,  -142,   293,   390,
    -142,   -15,    54,    57,   116,    92,  -142,     4,  -142,   355,
     108,  -142,  -142,  -142,  -142,  -142,  -142,   390,   183,   183,
     390,  -142,   483,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
     582,  -142,    95,   115,   121,   129,   153,    29,   154,   151,
     158,   170,   241,   171,    98,   104,    98,   179,   330,   390,
     265,  -142,  -142,   672,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,  -142,   381,    98,
     174,   144,   750,   175,    98,   210,   100,   327,   178,   181,
     327,   176,   281,   179,   186,    25,   179,    18,   117,  -142,
    -142,  -142,  -142,   688,   184,   196,   600,  -142,  -142,  -142,
     360,   360,   360,   360,   736,   736,   146,   146,  -142,  -142,
    -142,   725,   702,  -142,   210,    98,  -142,  -142,    98,   210,
    -142,    98,   210,   185,   327,   327,   102,    98,   327,   200,
    -142,   201,   209,   390,  -142,   210,  -142,   252,   255,   390,
     390,   263,   -17,   182,   243,  -142,   278,    93,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,   277,  -142,   390,
    -142,  -142,   210,   210,  -142,   210,  -142,    98,   244,   257,
      98,   300,   300,   118,    98,    98,   261,   233,  -142,   264,
     283,   405,   427,   304,   390,   366,   390,  -142,   236,   390,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,   300,    98,    98,
     300,   239,  -142,  -142,    98,   300,   300,   179,    98,   390,
     390,  -142,  -142,   210,   210,   390,   503,   286,   291,   618,
    -142,   295,   563,  -142,   300,   300,  -142,   390,   147,   328,
     300,  -142,  -142,  -142,   179,   636,   654,   324,  -142,   469,
    -142,  -142,   314,   336,   319,   390,  -142,  -142,   523,  -142,
     359,  -142,  -142,  -142,   321,   323,   210,   390,  -142,   390,
    -142,  -142,  -142,  -142,    98,    98,  -142,   449,   543,   179,
     179,   210,  -142,  -142,  -142,  -142
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
      10,     0,     0,     0,     0,     0,    54,     7,    44,   115,
     141,   135,   136,   140,   137,   138,   139,     0,     0,     0,
       0,     9,     0,   112,   113,   114,   132,   131,   133,   115,
       0,    42,     0,     0,    40,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     7,     0,     7,     0,     0,     0,
       0,   130,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    60,     7,
       0,     0,     0,     0,     7,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    49,   144,   147,     0,   146,     0,    16,     8,   134,
     121,   123,   122,   124,   125,   126,   116,   117,   118,   119,
     120,   127,   128,    59,     0,     7,    39,    41,     7,     0,
      27,     7,     0,     0,     0,     0,     7,     7,     0,     0,
      48,     0,     0,     0,    47,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,    81,    82,
      83,    84,    86,    87,    88,    85,    71,     0,   143,     0,
     142,    24,     0,     0,    22,     0,    26,     7,     0,     0,
       7,     0,     0,     7,     7,     7,     0,     0,    90,   101,
     103,     0,     0,     0,     0,     0,     0,    73,     0,     0,
      68,    80,    70,   145,    23,    25,    21,     0,     7,     7,
       0,     0,    37,    35,     7,     0,     0,     0,     7,     0,
       0,   100,   102,     0,     0,     0,    94,     0,     0,     0,
      72,     0,   109,    32,     0,     0,    30,     0,     0,     0,
       0,    36,    34,    51,     0,     0,     0,    98,    96,     0,
      91,   111,     0,    93,   107,     0,    31,    33,   105,    76,
       0,    75,    29,    52,     0,     0,     0,     0,   110,     0,
     106,   108,   104,    74,     7,     7,    99,     0,    95,     0,
       0,     0,    92,    53,    50,    97
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,   380,    -5,  -142,   159,  -142,  -142,  -142,  -142,
    -142,   -51,  -142,  -142,    -7,  -142,  -142,  -142,  -142,   -24,
     -88,   256,  -142,  -132,  -142,  -142,   -99,  -141,  -125,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,   105,  -142,    87,  -142,
     -49,  -142,  -142,   123,  -142,  -142,  -142,   -55,  -142
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    10,    11,    19,    20,    21,    44,    22,
      47,    93,    94,    95,    49,    50,    51,    52,    67,    38,
      39,    40,    41,   149,   150,   205,   262,   151,   206,   207,
     208,   209,   210,   211,   212,   213,   289,   214,   281,   215,
     153,    83,    84,    85,    86,    87,    88,   154,   155
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    13,   190,   180,    58,   194,    23,    27,     8,    82,
      90,    98,   100,   103,   141,    91,     5,    54,    55,   195,
     244,    16,    14,   217,    42,    26,   192,    45,   110,    48,
       1,   113,     7,     8,     9,   245,   196,   246,    92,   197,
     198,   199,   221,    68,   200,     2,   201,   224,   202,   183,
     226,    15,   186,    43,   189,    96,    46,     2,   105,     9,
     156,   106,   107,   238,    28,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   248,   203,
     176,   204,   251,   193,    91,    56,   134,    91,    17,    18,
     254,   255,   135,   256,   195,    59,   228,   229,    65,   143,
     233,   146,     8,    60,     8,   144,     8,    97,   177,   -79,
      99,   -79,    61,   -79,   197,   198,   199,   101,   195,   200,
      62,   201,     8,   202,   174,    63,   293,    66,     9,   179,
       9,   182,     9,   263,   145,    64,   288,   216,   197,   198,
     199,   297,   298,   200,   237,   201,    91,   202,     9,   104,
     241,   242,   129,   313,   203,   -79,   204,   181,   283,   230,
     108,   286,   109,   287,   253,   309,   291,   292,   130,   102,
     222,    24,    25,   223,    91,   264,   225,   131,   203,    53,
     204,   231,   232,   195,   326,   306,   307,   132,   333,   334,
     278,   312,   122,   123,   124,   276,   147,   279,   148,   335,
     282,   111,   112,   197,   198,   199,   133,   136,   200,   137,
     201,   138,   202,    70,    71,    72,    73,    74,    75,    76,
     295,   296,   257,   139,   142,   260,   299,   147,   265,   266,
     267,   175,   178,   187,   269,    80,   184,   218,   308,   185,
     195,   191,   227,   203,   247,   204,    30,    31,    32,    33,
      34,    35,   219,   284,   285,   287,   282,   234,   235,   290,
     197,   198,   199,   294,   236,   200,   157,   201,   327,   202,
     328,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   239,   125,   126,   240,    30,    31,    32,    33,
      34,    35,   270,   243,    69,   249,   250,   252,   280,   140,
     203,   258,   204,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   259,   125,   126,   261,   268,   329,
     330,   271,   158,    70,    71,    72,    73,    74,    75,    76,
      77,    89,    30,    31,    32,    33,    34,    35,    78,   188,
     272,   275,    79,   301,   302,    80,   311,    29,   304,   316,
      81,    30,    31,    32,    33,    34,    35,    36,    37,   -14,
      70,    71,    72,    73,    74,    75,    76,    89,   -14,   -14,
     -14,   318,   -14,   319,   -14,    78,   320,   323,   324,    79,
     325,     6,    80,   152,   173,   -14,    30,    31,    32,    33,
      34,    89,   321,   310,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    57,   120,   121,   122,   123,   124,     0,
       0,    78,     0,     0,     0,    79,     0,     0,    80,   277,
      70,    71,    72,    73,    74,    75,    76,     0,     0,   273,
       0,     0,     0,     0,     0,    78,     0,     0,     0,    79,
       0,     0,    80,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   274,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   331,   125,   126,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   317,   125,
     126,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
     126,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,     0,     0,     0,     0,     0,
     127,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,     0,     0,     0,     0,     0,
     300,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,     0,     0,     0,     0,     0,
     322,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,     0,     0,     0,     0,     0,
     332,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,     0,     0,     0,     0,   305,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,   126,     0,     0,     0,   128,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,     0,     0,     0,   220,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   126,
       0,     0,     0,   303,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,   126,     0,     0,
       0,   314,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,   126,     0,     0,     0,   315,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,   126,     0,   159,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   126,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    29,   125,     0,     0,    30,    31,    32,    33,    34,
      35,    36,    37,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   114,   115,   116,   117,     0,     0,
     120,   121,   122,   123,   124
};

static const yytype_int16 yycheck[] =
{
       5,     6,   143,   135,    28,   146,    11,     1,     4,    58,
      59,    62,    63,    64,   102,    30,     1,    24,    25,     1,
      37,    58,     1,   148,     1,    57,     1,     1,    77,    13,
       3,    80,     0,     4,    30,    52,    18,    54,    53,    21,
      22,    23,   174,    50,    26,    30,    28,   179,    30,   137,
     182,    30,   140,    30,   142,     1,    30,    30,    54,    30,
     109,    57,    67,   195,    58,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   203,    61,
     131,    63,   207,    58,    30,    57,    57,    30,    14,    15,
     222,   223,    97,   225,     1,    54,   184,   185,     1,   104,
     188,   106,     4,    57,     4,     1,     4,    53,   132,    16,
      53,    18,    52,    20,    21,    22,    23,     1,     1,    26,
      52,    28,     4,    30,   129,    52,   267,    30,    30,   134,
      30,   136,    30,   232,    30,    52,   261,    20,    21,    22,
      23,   273,   274,    26,   193,    28,    30,    30,    30,    57,
     199,   200,    57,   294,    61,    62,    63,    57,   257,    57,
      52,   260,    54,    16,   219,    18,   265,   266,    53,    53,
     175,    12,    13,   178,    30,    57,   181,    56,    61,    20,
      63,   186,   187,     1,   316,   284,   285,    58,   329,   330,
     245,   290,    46,    47,    48,   244,    17,   246,    19,   331,
     249,    78,    79,    21,    22,    23,    53,    53,    26,    58,
      28,    53,    30,    30,    31,    32,    33,    34,    35,    36,
     269,   270,   227,    53,    53,   230,   275,    17,   233,   234,
     235,    57,    57,    57,     1,    52,    58,    53,   287,    58,
       1,    55,    57,    61,    62,    63,     5,     6,     7,     8,
       9,    10,    56,   258,   259,    16,   305,    57,    57,   264,
      21,    22,    23,   268,    55,    26,     1,    28,   317,    30,
     319,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    30,    50,    51,    30,     5,     6,     7,     8,
       9,    10,    59,    30,     1,    52,    18,    20,    62,    58,
      61,    57,    63,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    57,    50,    51,    17,    57,   324,
     325,    57,    57,    30,    31,    32,    33,    34,    35,    36,
      37,     1,     5,     6,     7,     8,     9,    10,    45,    58,
      57,    37,    49,    57,    53,    52,    18,     1,    53,    25,
      57,     5,     6,     7,     8,     9,    10,    11,    12,     4,
      30,    31,    32,    33,    34,    35,    36,     1,    13,    14,
      15,    57,    17,    37,    19,    45,    57,    18,    57,    49,
      57,     1,    52,    53,   128,    30,     5,     6,     7,     8,
       9,     1,   305,   288,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    57,    44,    45,    46,    47,    48,    -1,
      -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    49,
      -1,    -1,    52,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    27,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    27,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
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
      52,    57,   106,   107,   108,   109,   110,   111,   112,     1,
     106,    30,    53,    77,    78,    79,     1,    53,    77,    53,
      77,     1,    53,    77,    57,    54,    57,    69,    52,    54,
     106,   109,   109,   106,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    50,    51,    57,    55,    57,
      53,    56,    58,    53,    57,    69,    53,    58,    53,    53,
      58,    86,    53,    69,     1,    30,    69,    17,    19,    89,
      90,    93,    53,   106,   113,   114,   106,     1,    57,    53,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,    87,    69,    57,    77,    85,    57,    69,
      89,    57,    69,    86,    58,    58,    86,    57,    58,    86,
      93,    55,     1,    58,    93,     1,    18,    21,    22,    23,
      26,    28,    30,    61,    63,    91,    94,    95,    96,    97,
      98,    99,   100,   101,   103,   105,    20,    94,    53,    56,
      55,    89,    69,    69,    89,    69,    89,    57,    86,    86,
      57,    69,    69,    86,    57,    57,    55,   106,    89,    30,
      30,   106,   106,    30,    37,    52,    54,    62,    94,    52,
      18,    94,    20,   113,    89,    89,    89,    69,    57,    57,
      69,    17,    92,    92,    57,    69,    69,    69,    57,     1,
      59,    57,    57,    24,    27,    37,   106,    53,   113,   106,
      62,   104,   106,    92,    69,    69,    92,    16,    94,   102,
      69,    92,    92,    93,    69,   106,   106,    89,    89,   106,
      57,    57,    53,    55,    53,    56,    92,    92,   106,    18,
     102,    18,    92,    93,    55,    55,    25,    29,    57,    37,
      57,   104,    57,    18,    57,    57,    89,   106,   106,    69,
      69,    27,    57,    93,    93,    89
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
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    96,    96,    96,    96,    96,    97,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   106,   106,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   108,
     108,   109,   109,   109,   109,   110,   110,   110,   110,   110,
     110,   111,   111,   112,   112,   113,   113,   114
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
       3,     2,     3,     2,     4,     3,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     7,     4,     3,     6,     4,     8,     4,     6,
       3,     2,     3,     2,     3,     2,     5,     4,     3,     1,
       5,     4,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     3,     3,     1,     1
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
#line 238 "src/parser/parser.y"
                                                                          {
        // -- Crear AST (solo si no hay errores sintacticos)
        if(!have_syntax_errors())
            AST_program = create_program((yyvsp[-3].ident),(yyvsp[-2].decl),(yyvsp[-1].subprog),(yyvsp[0].proc));
    }
#line 1537 "src/parser/parser.c"
    break;

  case 3: /* program: program-name list-declarations list-subprograms list-process  */
#line 244 "src/parser/parser.y"
                                                                  {
        mark_error_syntax_program_expected_program((yyvsp[-3].ident));
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }
#line 1547 "src/parser/parser.c"
    break;

  case 4: /* program: S_PROGRAM error list-declarations list-subprograms list-process  */
#line 250 "src/parser/parser.y"
                                                                     {
        mark_error_syntax_program_expected_identifier();
        // -- Abortar inmediatamente el analisis
        //YYABORT;
    }
#line 1557 "src/parser/parser.c"
    break;

  case 5: /* program-name: IDENT  */
#line 258 "src/parser/parser.y"
         { 
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1565 "src/parser/parser.c"
    break;

  case 6: /* list-declarations: declaration list-declarations  */
#line 267 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.decl) = (yyvsp[-1].decl);
            (yyvsp[-1].decl)->next = (yyvsp[0].decl);
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1579 "src/parser/parser.c"
    break;

  case 7: /* list-declarations: %empty  */
#line 276 "src/parser/parser.y"
                   {
        (yyval.decl) = 0;
    }
#line 1587 "src/parser/parser.c"
    break;

  case 8: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression DELIM_PC  */
#line 283 "src/parser/parser.y"
                                                           {
        if(!have_syntax_errors()){
            (yyval.decl) = create_declaration_variable((yyvsp[-5].ident), (yyvsp[-3].type), (yyvsp[-1].expr), yylineno);
            add_declaration_to_register((yyval.decl));
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1601 "src/parser/parser.c"
    break;

  case 9: /* declaration: S_VAR IDENT DELIM_2P type DELIM_PC  */
#line 293 "src/parser/parser.y"
                                        {
        if(!have_syntax_errors()){
            (yyval.decl) = create_declaration_variable((yyvsp[-3].ident), (yyvsp[-1].type), 0, yylineno);
            add_declaration_to_register((yyval.decl));
        }
        else{
            (yyval.decl) = 0;
        }
    }
#line 1615 "src/parser/parser.c"
    break;

  case 10: /* declaration: IDENT DELIM_2P type DELIM_PC  */
#line 303 "src/parser/parser.y"
                                  {
        mark_error_syntax_declaration_expected_var((yyvsp[-3].ident));
        // Recuperar
        //YYABORT;
    }
#line 1625 "src/parser/parser.c"
    break;

  case 11: /* declaration: S_VAR error DELIM_PC  */
#line 309 "src/parser/parser.y"
                          {
        mark_error_syntax_declaration_expected_identifier();
        //YYABORT;
    }
#line 1634 "src/parser/parser.c"
    break;

  case 12: /* declaration: S_VAR IDENT error DELIM_PC  */
#line 314 "src/parser/parser.y"
                                {
        mark_error_syntax_declaration_expected_delim2p((yyvsp[-2].ident));
        //YYABORT;
    }
#line 1643 "src/parser/parser.c"
    break;

  case 13: /* declaration: S_VAR IDENT DELIM_2P DELIM_PC  */
#line 319 "src/parser/parser.y"
                                   {
        mark_error_syntax_type_expected_type((yyvsp[-2].ident));
        //YYABORT;
    }
#line 1652 "src/parser/parser.c"
    break;

  case 14: /* declaration: S_VAR IDENT DELIM_2P type error  */
#line 324 "src/parser/parser.y"
                                     {
        mark_error_syntax_declaration_expected_delimpc((yyvsp[-3].ident));
        free_AST_type_register((yyvsp[-1].type));
        //YYABORT;
    }
#line 1662 "src/parser/parser.c"
    break;

  case 15: /* declaration: S_VAR IDENT DELIM_2P type expression DELIM_PC  */
#line 330 "src/parser/parser.y"
                                                   {
        mark_error_syntax_declaration_expected_opassign((yyvsp[-4].ident));
        //YYABORT;
    }
#line 1671 "src/parser/parser.c"
    break;

  case 16: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression error  */
#line 335 "src/parser/parser.y"
                                                          {
        mark_error_syntax_declaration_expected_delimpc((yyvsp[-5].ident));
        //YYABORT;
    }
#line 1680 "src/parser/parser.c"
    break;

  case 17: /* list-subprograms: subprogram list-subprograms  */
#line 345 "src/parser/parser.y"
                               {
        if(!have_syntax_errors()){
            (yyval.subprog) = (yyvsp[-1].subprog);
            (yyvsp[-1].subprog)->next = (yyvsp[0].subprog);
        }
        else{
            (yyval.subprog) = 0;
        }
    }
#line 1694 "src/parser/parser.c"
    break;

  case 18: /* list-subprograms: %empty  */
#line 354 "src/parser/parser.y"
                   {
        (yyval.subprog) = 0;
    }
#line 1702 "src/parser/parser.c"
    break;

  case 19: /* subprogram: subprogram-procedure  */
#line 360 "src/parser/parser.y"
                        {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1710 "src/parser/parser.c"
    break;

  case 20: /* subprogram: subprogram-function  */
#line 363 "src/parser/parser.y"
                         {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1718 "src/parser/parser.c"
    break;

  case 21: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 370 "src/parser/parser.y"
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
#line 1733 "src/parser/parser.c"
    break;

  case 22: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 381 "src/parser/parser.y"
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
#line 1749 "src/parser/parser.c"
    break;

  case 23: /* subprogram-procedure: S_PROCEDURE error PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 393 "src/parser/parser.y"
                                                                                                               {
        mark_error_syntax_subprogram_procedure_expected_identifier();
        //YYABORT;
    }
#line 1758 "src/parser/parser.c"
    break;

  case 24: /* subprogram-procedure: S_PROCEDURE error PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 398 "src/parser/parser.y"
                                                                                               {
        // -- Mostrar error
        mark_error_syntax_subprogram_procedure_expected_identifier();
        // -- Abortar inmediatmente el analisis
        //YYABORT;
    }
#line 1769 "src/parser/parser.c"
    break;

  case 25: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO error PAR_DCHO DELIM_PC list-declarations block-statements-begin-end  */
#line 405 "src/parser/parser.y"
                                                                                                                         {
        mark_error_syntax_subprogram_procedure_expected_parameters((yyvsp[-6].ident));
        //YYABORT;
    }
#line 1778 "src/parser/parser.c"
    break;

  case 26: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO list-declarations block-statements-begin-end  */
#line 410 "src/parser/parser.y"
                                                                                                                          {
        mark_error_syntax_subprogram_procedure_expected_delimpc((yyvsp[-5].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1788 "src/parser/parser.c"
    break;

  case 27: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO list-declarations block-statements-begin-end  */
#line 416 "src/parser/parser.y"
                                                                                                          {
        mark_error_syntax_subprogram_procedure_expected_delimpc((yyvsp[-4].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1798 "src/parser/parser.c"
    break;

  case 28: /* subprogram-procedure-name: IDENT  */
#line 424 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1806 "src/parser/parser.c"
    break;

  case 29: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 431 "src/parser/parser.y"
                                                                                                                                                           {
        // -- Creacion de nodo SUBPROGRAMA (FUNCTION)
        if(!have_syntax_errors()){
            (yyval.subprog) = create_subprogram_function((yyvsp[-8].ident), (yyvsp[-6].param), (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-3].type), yylineno);
            add_subprogram_to_register((yyval.subprog));
        }
        else{
            (yyval.subprog) = 0;
        }

        
    }
#line 1823 "src/parser/parser.c"
    break;

  case 30: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 444 "src/parser/parser.y"
                                                                                                                                             {
        // -- Creacion de nodo SUBPROGRAMA (FUNCTION)
        if(!have_syntax_errors()){
            (yyval.subprog) = create_subprogram_function((yyvsp[-7].ident), 0, (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-3].type), yylineno);
            add_subprogram_to_register((yyval.subprog));
        }
        else{
            (yyval.subprog) = 0;
        }

        
    }
#line 1840 "src/parser/parser.c"
    break;

  case 31: /* subprogram-function: S_FUNCTION error PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 457 "src/parser/parser.y"
                                                                                                                                          {
        mark_error_syntax_subprogram_function_expected_identifier();
        //YYABORT;
    }
#line 1849 "src/parser/parser.c"
    break;

  case 32: /* subprogram-function: S_FUNCTION error PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 462 "src/parser/parser.y"
                                                                                                                          {
        mark_error_syntax_subprogram_function_expected_identifier();
        //YYABORT;
    }
#line 1858 "src/parser/parser.c"
    break;

  case 33: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO error PAR_DCHO DELIM_2P basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 467 "src/parser/parser.y"
                                                                                                                                                   {
        mark_error_syntax_subprogram_function_expected_parameters((yyvsp[-8].ident));
        //YYABORT;
    }
#line 1867 "src/parser/parser.c"
    break;

  case 34: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 472 "src/parser/parser.y"
                                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delim2p((yyvsp[-7].ident));
        //YYABORT;
    }
#line 1876 "src/parser/parser.c"
    break;

  case 35: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO basic-or-array-type DELIM_PC list-declarations block-statements-function  */
#line 477 "src/parser/parser.y"
                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delim2p((yyvsp[-6].ident));
        //YYABORT;
    }
#line 1885 "src/parser/parser.c"
    break;

  case 36: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P basic-or-array-type list-declarations block-statements-function  */
#line 482 "src/parser/parser.y"
                                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delimpc((yyvsp[-7].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1895 "src/parser/parser.c"
    break;

  case 37: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P basic-or-array-type list-declarations block-statements-function  */
#line 488 "src/parser/parser.y"
                                                                                                                                    {
        mark_error_syntax_subprogram_function_expected_delimpc((yyvsp[-6].ident));
        free_AST_parameter_register();
        //YYABORT;
    }
#line 1905 "src/parser/parser.c"
    break;

  case 38: /* subprogram-function-name: IDENT  */
#line 496 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1913 "src/parser/parser.c"
    break;

  case 39: /* list-parameters: parameter DELIM_C list-parameters  */
#line 505 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.param) = (yyvsp[-2].param);
            (yyvsp[-2].param)->next = (yyvsp[0].param);
        }
        else{
            (yyval.param) = 0;
        }
    }
#line 1927 "src/parser/parser.c"
    break;

  case 40: /* list-parameters: parameter  */
#line 514 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.param) = (yyvsp[0].param);
        }
        else{
            (yyval.param) = 0;
        }
    }
#line 1940 "src/parser/parser.c"
    break;

  case 41: /* parameter: parameter-name DELIM_2P type  */
#line 526 "src/parser/parser.y"
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
#line 1956 "src/parser/parser.c"
    break;

  case 42: /* parameter-name: IDENT  */
#line 540 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1964 "src/parser/parser.c"
    break;

  case 43: /* list-process: process  */
#line 549 "src/parser/parser.y"
           {
        if(!have_syntax_errors()){
            (yyval.proc) = (yyvsp[0].proc);
        }
        else{
            (yyval.proc) = 0;
        }
    }
#line 1977 "src/parser/parser.c"
    break;

  case 44: /* list-process: process list-process  */
#line 557 "src/parser/parser.y"
                          {
        if(!have_syntax_errors()){
            (yyval.proc) = (yyvsp[-1].proc);
            (yyvsp[-1].proc)->next = (yyvsp[0].proc);
        }
        else{
            (yyval.proc) = 0;
        }
    }
#line 1991 "src/parser/parser.c"
    break;

  case 45: /* process: process-def  */
#line 569 "src/parser/parser.y"
               {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 1999 "src/parser/parser.c"
    break;

  case 46: /* process: process-def-array  */
#line 572 "src/parser/parser.y"
                       {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 2007 "src/parser/parser.c"
    break;

  case 47: /* process-def: S_PROCESS process-name DELIM_PC list-declarations block-statements-process  */
#line 579 "src/parser/parser.y"
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
#line 2023 "src/parser/parser.c"
    break;

  case 48: /* process-def: S_PROCESS error DELIM_PC list-declarations block-statements-process  */
#line 591 "src/parser/parser.y"
                                                                         {
        mark_error_syntax_process_expected_identifier();
        //YYABORT;
    }
#line 2032 "src/parser/parser.c"
    break;

  case 49: /* process-def: S_PROCESS process-name list-declarations block-statements-process  */
#line 596 "src/parser/parser.y"
                                                                       {
        mark_error_syntax_process_expected_delimpc((yyvsp[-2].ident));
        //YYABORT;
    }
#line 2041 "src/parser/parser.c"
    break;

  case 50: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC list-declarations block-statements-process  */
#line 604 "src/parser/parser.y"
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
#line 2056 "src/parser/parser.c"
    break;

  case 51: /* process-def-array: S_PROCESS process-name CORCH_IZDO error CORCH_DCHO DELIM_PC list-declarations block-statements-process  */
#line 615 "src/parser/parser.y"
                                                                                                            {
        mark_error_syntax_process_expected_index_identifier((yyvsp[-6].ident));
        //YYABORT;
    }
#line 2065 "src/parser/parser.c"
    break;

  case 52: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT error CORCH_DCHO DELIM_PC list-declarations block-statements-process  */
#line 620 "src/parser/parser.y"
                                                                                                                  {
        mark_error_syntax_process_expected_delim2p((yyvsp[-7].ident));
        //YYABORT;
    }
#line 2074 "src/parser/parser.c"
    break;

  case 53: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression error expression CORCH_DCHO DELIM_PC list-declarations block-statements-process  */
#line 625 "src/parser/parser.y"
                                                                                                                                                 {
        mark_error_syntax_process_expected_delimarr((yyvsp[-10].ident));
        //YYABORT;
    }
#line 2083 "src/parser/parser.c"
    break;

  case 54: /* process-name: IDENT  */
#line 632 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 2091 "src/parser/parser.c"
    break;

  case 55: /* type: basic-or-array-type  */
#line 641 "src/parser/parser.y"
                       {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2099 "src/parser/parser.c"
    break;

  case 56: /* type: special-type  */
#line 644 "src/parser/parser.y"
                  {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2107 "src/parser/parser.c"
    break;

  case 57: /* type: error  */
#line 647 "src/parser/parser.y"
           {
        mark_error_syntax_type_expected_type();
        //YYABORT;
    }
#line 2116 "src/parser/parser.c"
    break;

  case 58: /* basic-or-array-type: basic-type  */
#line 654 "src/parser/parser.y"
              {
        (yyval.type) = (yyvsp[0].type);
    }
#line 2124 "src/parser/parser.c"
    break;

  case 59: /* basic-or-array-type: T_ARRAY CORCH_IZDO expression CORCH_DCHO basic-type  */
#line 657 "src/parser/parser.y"
                                                         {
        if(!have_syntax_errors()){
            (yyval.type) = create_array_type((yyvsp[0].type),(yyvsp[-2].expr));
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2138 "src/parser/parser.c"
    break;

  case 60: /* basic-or-array-type: T_ARRAY CORCH_IZDO expression CORCH_DCHO  */
#line 667 "src/parser/parser.y"
                                              {
        mark_error_syntax_type_expected_type();
        //YYABORT;
    }
#line 2147 "src/parser/parser.c"
    break;

  case 61: /* basic-type: T_INTEGER  */
#line 674 "src/parser/parser.y"
             {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_INTEGER);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2161 "src/parser/parser.c"
    break;

  case 62: /* basic-type: T_BOOLEAN  */
#line 683 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_BOOLEAN);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2175 "src/parser/parser.c"
    break;

  case 63: /* basic-type: T_CHAR  */
#line 692 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_CHAR);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2189 "src/parser/parser.c"
    break;

  case 64: /* basic-type: T_STRING  */
#line 701 "src/parser/parser.y"
              {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_STRING);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2203 "src/parser/parser.c"
    break;

  case 65: /* basic-type: T_REAL  */
#line 710 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.type) = create_basic_type(TYPE_REAL);
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2217 "src/parser/parser.c"
    break;

  case 66: /* special-type: T_SEMAPHORE  */
#line 722 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.type) = create_semaphore_type();
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2231 "src/parser/parser.c"
    break;

  case 67: /* special-type: T_DPROCESS  */
#line 731 "src/parser/parser.y"
                {
        if(!have_syntax_errors()){
            (yyval.type) = create_dprocess_type();
            add_type_to_register((yyval.type));
        }
        else{
            (yyval.type) = 0;
        }
    }
#line 2245 "src/parser/parser.c"
    break;

  case 68: /* block-statements-begin-end: B_BEGIN list-statements B_END  */
#line 747 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2259 "src/parser/parser.c"
    break;

  case 69: /* block-statements-begin-end: B_BEGIN B_END  */
#line 757 "src/parser/parser.y"
                   {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2268 "src/parser/parser.c"
    break;

  case 70: /* block-statements-cobegin-coend: B_COBEGIN list-statements B_COEND  */
#line 765 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_cobegin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2282 "src/parser/parser.c"
    break;

  case 71: /* block-statements-cobegin-coend: B_COBEGIN B_COEND  */
#line 775 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2291 "src/parser/parser.c"
    break;

  case 72: /* block-statements-atomic: ATOM_INI list-statements ATOM_FIN  */
#line 783 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_atomic((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2305 "src/parser/parser.c"
    break;

  case 73: /* block-statements-atomic: ATOM_INI ATOM_FIN  */
#line 793 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_empty_block();
        //YYABORT;
    }
#line 2314 "src/parser/parser.c"
    break;

  case 74: /* block-statements-function: B_BEGIN list-statements return-statement B_END  */
#line 801 "src/parser/parser.y"
                                                  {
        if(!have_syntax_errors()){
            (yyvsp[-2].stmt)->next = (yyvsp[-1].stmt);
            (yyval.stmt) = create_statement_block_begin((yyvsp[-2].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2329 "src/parser/parser.c"
    break;

  case 75: /* block-statements-function: B_BEGIN return-statement B_END  */
#line 812 "src/parser/parser.y"
                                    {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2343 "src/parser/parser.c"
    break;

  case 76: /* block-statements-function: B_BEGIN list-statements B_END  */
#line 822 "src/parser/parser.y"
                                   {
        mark_error_syntax_statement_non_return_in_block();
        //YYABORT;
    }
#line 2352 "src/parser/parser.c"
    break;

  case 77: /* block-statements-process: block-statements-begin-end  */
#line 829 "src/parser/parser.y"
                              {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2360 "src/parser/parser.c"
    break;

  case 78: /* block-statements-process: block-statements-cobegin-coend  */
#line 832 "src/parser/parser.y"
                                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2368 "src/parser/parser.c"
    break;

  case 79: /* list-statements: statement  */
#line 838 "src/parser/parser.y"
             {
        if(!have_syntax_errors()){
            (yyval.stmt) = (yyvsp[0].stmt);
        }
        else{
            (yyval.stmt) = 0;
        }
        
    }
#line 2382 "src/parser/parser.c"
    break;

  case 80: /* list-statements: statement list-statements  */
#line 847 "src/parser/parser.y"
                               {
        if(!have_syntax_errors()){
            (yyval.stmt) = (yyvsp[-1].stmt);
            (yyvsp[-1].stmt)->next = (yyvsp[0].stmt);
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2396 "src/parser/parser.c"
    break;

  case 81: /* statement: assignment-statement  */
#line 859 "src/parser/parser.y"
                        {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2404 "src/parser/parser.c"
    break;

  case 82: /* statement: while-statement  */
#line 862 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2412 "src/parser/parser.c"
    break;

  case 83: /* statement: for-statement  */
#line 865 "src/parser/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2420 "src/parser/parser.c"
    break;

  case 84: /* statement: if-statement  */
#line 868 "src/parser/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2428 "src/parser/parser.c"
    break;

  case 85: /* statement: procedure-call-statement  */
#line 871 "src/parser/parser.y"
                              {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2436 "src/parser/parser.c"
    break;

  case 86: /* statement: fork-statement  */
#line 874 "src/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2444 "src/parser/parser.c"
    break;

  case 87: /* statement: join-statement  */
#line 877 "src/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2452 "src/parser/parser.c"
    break;

  case 88: /* statement: print-statement  */
#line 880 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2460 "src/parser/parser.c"
    break;

  case 89: /* statement: block-statements-atomic  */
#line 883 "src/parser/parser.y"
                             {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2468 "src/parser/parser.c"
    break;

  case 90: /* statement: error block-statements-begin-end  */
#line 886 "src/parser/parser.y"
                                      {
        mark_error_syntax_statement_expected_statement();
    }
#line 2476 "src/parser/parser.c"
    break;

  case 91: /* assignment-statement: IDENT OP_ASSIGN expression DELIM_PC  */
#line 893 "src/parser/parser.y"
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
#line 2491 "src/parser/parser.c"
    break;

  case 92: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression DELIM_PC  */
#line 904 "src/parser/parser.y"
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
#line 2506 "src/parser/parser.c"
    break;

  case 93: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO  */
#line 915 "src/parser/parser.y"
                                            {
        mark_error_syntax_statement_expected_statement();
        //YYABORT;
    }
#line 2515 "src/parser/parser.c"
    break;

  case 94: /* assignment-statement: IDENT OP_ASSIGN expression  */
#line 920 "src/parser/parser.y"
                                {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2524 "src/parser/parser.c"
    break;

  case 95: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression  */
#line 925 "src/parser/parser.y"
                                                                 {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2533 "src/parser/parser.c"
    break;

  case 96: /* while-statement: WHILE expression DO block-statements-begin-end  */
#line 933 "src/parser/parser.y"
                                                  {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_while((yyvsp[-2].expr), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2547 "src/parser/parser.c"
    break;

  case 97: /* for-statement: FOR IDENT OP_ASSIGN expression TO expression DO block-statements-begin-end  */
#line 946 "src/parser/parser.y"
                                                                              {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_for((yyvsp[-6].ident), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2561 "src/parser/parser.c"
    break;

  case 98: /* if-statement: IF expression THEN block-statements-begin-end  */
#line 960 "src/parser/parser.y"
                                                 {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_if_else((yyvsp[-2].expr), (yyvsp[0].stmt), 0, yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2575 "src/parser/parser.c"
    break;

  case 99: /* if-statement: IF expression THEN block-statements-begin-end ELSE block-statements-begin-end  */
#line 970 "src/parser/parser.y"
                                                                                   {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_if_else((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2589 "src/parser/parser.c"
    break;

  case 100: /* fork-statement: S_FORK IDENT DELIM_PC  */
#line 983 "src/parser/parser.y"
                         {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_fork((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2603 "src/parser/parser.c"
    break;

  case 101: /* fork-statement: S_FORK IDENT  */
#line 993 "src/parser/parser.y"
                  {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2612 "src/parser/parser.c"
    break;

  case 102: /* join-statement: JOIN IDENT DELIM_PC  */
#line 1001 "src/parser/parser.y"
                       {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_join((yyvsp[-1].ident), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2626 "src/parser/parser.c"
    break;

  case 103: /* join-statement: JOIN IDENT  */
#line 1011 "src/parser/parser.y"
                {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2635 "src/parser/parser.c"
    break;

  case 104: /* return-statement: RETURN expression DELIM_PC  */
#line 1019 "src/parser/parser.y"
                              {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_return((yyvsp[-1].expr), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2649 "src/parser/parser.c"
    break;

  case 105: /* return-statement: RETURN expression  */
#line 1029 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2658 "src/parser/parser.c"
    break;

  case 106: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO DELIM_PC  */
#line 1037 "src/parser/parser.y"
                                               {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_print((yyvsp[-2].expr));
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2672 "src/parser/parser.c"
    break;

  case 107: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO  */
#line 1047 "src/parser/parser.y"
                                        {
        mark_error_syntax_statement_expected_delimpc();
        //YYABORT;
    }
#line 2681 "src/parser/parser.c"
    break;

  case 108: /* list-print: expression DELIM_C list-print  */
#line 1054 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[-2].expr);
            (yyvsp[-2].expr)->next = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2695 "src/parser/parser.c"
    break;

  case 109: /* list-print: expression  */
#line 1063 "src/parser/parser.y"
                {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2708 "src/parser/parser.c"
    break;

  case 110: /* procedure-call-statement: IDENT PAR_IZDO list-arguments PAR_DCHO DELIM_PC  */
#line 1075 "src/parser/parser.y"
                                                   {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_procedure_inv((yyvsp[-4].ident), (yyvsp[-2].expr), yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2722 "src/parser/parser.c"
    break;

  case 111: /* procedure-call-statement: IDENT PAR_IZDO PAR_DCHO DELIM_PC  */
#line 1085 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.stmt) = create_statement_procedure_inv((yyvsp[-3].ident), 0, yylineno);
            add_statement_to_register((yyval.stmt));
        }
        else{
            (yyval.stmt) = 0;
        }
    }
#line 2736 "src/parser/parser.c"
    break;

  case 112: /* expression: binary-expression  */
#line 1100 "src/parser/parser.y"
                     {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2744 "src/parser/parser.c"
    break;

  case 113: /* expression: unary-expression  */
#line 1103 "src/parser/parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2752 "src/parser/parser.c"
    break;

  case 114: /* expression: term  */
#line 1106 "src/parser/parser.y"
          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2760 "src/parser/parser.c"
    break;

  case 115: /* expression: error  */
#line 1109 "src/parser/parser.y"
            {
        mark_error_syntax_expression_expected_expr();
        YYABORT;
    }
#line 2769 "src/parser/parser.c"
    break;

  case 116: /* binary-expression: expression OP_SUM expression  */
#line 1117 "src/parser/parser.y"
                                {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_ADD, "+", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2783 "src/parser/parser.c"
    break;

  case 117: /* binary-expression: expression OP_MINUS expression  */
#line 1127 "src/parser/parser.y"
                                    {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_SUB, "-", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2797 "src/parser/parser.c"
    break;

  case 118: /* binary-expression: expression OP_MULT expression  */
#line 1137 "src/parser/parser.y"
                                   {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_MULT, "*", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2811 "src/parser/parser.c"
    break;

  case 119: /* binary-expression: expression OP_DIV expression  */
#line 1147 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_DIV, "/", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2825 "src/parser/parser.c"
    break;

  case 120: /* binary-expression: expression OP_MOD expression  */
#line 1157 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_MOD, "%", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2839 "src/parser/parser.c"
    break;

  case 121: /* binary-expression: expression OP_REL_LT expression  */
#line 1167 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_LT, "<", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2853 "src/parser/parser.c"
    break;

  case 122: /* binary-expression: expression OP_REL_LTE expression  */
#line 1177 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_LTE, "<=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2867 "src/parser/parser.c"
    break;

  case 123: /* binary-expression: expression OP_REL_GT expression  */
#line 1187 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_GT, ">", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2881 "src/parser/parser.c"
    break;

  case 124: /* binary-expression: expression OP_REL_GTE expression  */
#line 1197 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_GTE, ">=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2895 "src/parser/parser.c"
    break;

  case 125: /* binary-expression: expression OP_REL_EQ expression  */
#line 1207 "src/parser/parser.y"
                                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_EQ, "==", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2909 "src/parser/parser.c"
    break;

  case 126: /* binary-expression: expression OP_REL_NEQ expression  */
#line 1217 "src/parser/parser.y"
                                      {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_NEQ, "!=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
       
    }
#line 2924 "src/parser/parser.c"
    break;

  case 127: /* binary-expression: expression OP_AND expression  */
#line 1228 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_AND, "and", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2938 "src/parser/parser.c"
    break;

  case 128: /* binary-expression: expression OP_OR expression  */
#line 1238 "src/parser/parser.y"
                                 {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_binary_operation(EXPR_OR, "or", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2952 "src/parser/parser.c"
    break;

  case 129: /* unary-expression: OP_NOT term  */
#line 1251 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_unary_operation(EXPR_NOT, "not", (yyvsp[0].expr),yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2966 "src/parser/parser.c"
    break;

  case 130: /* unary-expression: OP_MINUS term  */
#line 1261 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_unary_operation(EXPR_NEGATIVE, "-", (yyvsp[0].expr),yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 2980 "src/parser/parser.c"
    break;

  case 131: /* term: expr-identifier  */
#line 1273 "src/parser/parser.y"
                   {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2988 "src/parser/parser.c"
    break;

  case 132: /* term: literal  */
#line 1276 "src/parser/parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2996 "src/parser/parser.c"
    break;

  case 133: /* term: function-call-expression  */
#line 1279 "src/parser/parser.y"
                              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3004 "src/parser/parser.c"
    break;

  case 134: /* term: PAR_IZDO expression PAR_DCHO  */
#line 1282 "src/parser/parser.y"
                                  {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_grouped((yyvsp[-1].expr));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3018 "src/parser/parser.c"
    break;

  case 135: /* literal: LITERAL  */
#line 1295 "src/parser/parser.y"
           {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_string((yyvsp[0].literal_string));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3032 "src/parser/parser.c"
    break;

  case 136: /* literal: L_INTEGER  */
#line 1304 "src/parser/parser.y"
               {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_integer((yyvsp[0].literal_int));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3046 "src/parser/parser.c"
    break;

  case 137: /* literal: L_BOOLEAN_TRUE  */
#line 1313 "src/parser/parser.y"
                    {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_boolean(1);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3060 "src/parser/parser.c"
    break;

  case 138: /* literal: L_BOOLEAN_FALSE  */
#line 1322 "src/parser/parser.y"
                     {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_boolean(0);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3074 "src/parser/parser.c"
    break;

  case 139: /* literal: L_CHAR  */
#line 1331 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_char((yyvsp[0].literal_char));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3088 "src/parser/parser.c"
    break;

  case 140: /* literal: L_REAL  */
#line 1340 "src/parser/parser.y"
            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_literal_real((yyvsp[0].literal_float));
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3102 "src/parser/parser.c"
    break;

  case 141: /* expr-identifier: IDENT  */
#line 1352 "src/parser/parser.y"
         {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_identifier((yyvsp[0].ident),0, yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3116 "src/parser/parser.c"
    break;

  case 142: /* expr-identifier: IDENT CORCH_IZDO expression CORCH_DCHO  */
#line 1361 "src/parser/parser.y"
                                            {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_identifier((yyvsp[-3].ident), (yyvsp[-1].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3130 "src/parser/parser.c"
    break;

  case 143: /* function-call-expression: IDENT PAR_IZDO list-arguments PAR_DCHO  */
#line 1374 "src/parser/parser.y"
                                          {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_function_invocation((yyvsp[-3].ident), (yyvsp[-1].expr), yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3144 "src/parser/parser.c"
    break;

  case 144: /* function-call-expression: IDENT PAR_IZDO PAR_DCHO  */
#line 1384 "src/parser/parser.y"
                             {
        if(!have_syntax_errors()){
            (yyval.expr) = create_expression_function_invocation((yyvsp[-2].ident), 0, yylineno);
            add_expression_to_register((yyval.expr));
        }
        else{
            (yyval.expr) = 0;
        }

    }
#line 3159 "src/parser/parser.c"
    break;

  case 145: /* list-arguments: argument DELIM_C list-arguments  */
#line 1400 "src/parser/parser.y"
                                   {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[-2].expr);
            (yyvsp[-2].expr)->next = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3173 "src/parser/parser.c"
    break;

  case 146: /* list-arguments: argument  */
#line 1409 "src/parser/parser.y"
              {
        if(!have_syntax_errors()){
            (yyval.expr) = (yyvsp[0].expr);
        }
        else{
            (yyval.expr) = 0;
        }
    }
#line 3186 "src/parser/parser.c"
    break;

  case 147: /* argument: expression  */
#line 1420 "src/parser/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 3194 "src/parser/parser.c"
    break;


#line 3198 "src/parser/parser.c"

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

#line 1425 "src/parser/parser.y"


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
