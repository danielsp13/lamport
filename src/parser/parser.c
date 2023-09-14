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
  YYSYMBOL_86_list_statements = 86,        /* list-statements  */
  YYSYMBOL_statement = 87,                 /* statement  */
  YYSYMBOL_88_block_statement = 88,        /* block-statement  */
  YYSYMBOL_89_cobegin_statement = 89,      /* cobegin-statement  */
  YYSYMBOL_90_assignment_statement = 90,   /* assignment-statement  */
  YYSYMBOL_91_while_statement = 91,        /* while-statement  */
  YYSYMBOL_92_for_statement = 92,          /* for-statement  */
  YYSYMBOL_93_if_statement = 93,           /* if-statement  */
  YYSYMBOL_94_fork_statement = 94,         /* fork-statement  */
  YYSYMBOL_95_atomic_statement = 95,       /* atomic-statement  */
  YYSYMBOL_96_return_statement = 96,       /* return-statement  */
  YYSYMBOL_97_print_statement = 97,        /* print-statement  */
  YYSYMBOL_98_list_print = 98,             /* list-print  */
  YYSYMBOL_99_procedure_invocation = 99,   /* procedure-invocation  */
  YYSYMBOL_100_function_invocation = 100,  /* function-invocation  */
  YYSYMBOL_101_list_arguments = 101,       /* list-arguments  */
  YYSYMBOL_argument = 102,                 /* argument  */
  YYSYMBOL_expression = 103,               /* expression  */
  YYSYMBOL_104_binary_expression = 104,    /* binary-expression  */
  YYSYMBOL_105_unary_expression = 105,     /* unary-expression  */
  YYSYMBOL_term = 106,                     /* term  */
  YYSYMBOL_literal = 107,                  /* literal  */
  YYSYMBOL_108_expr_identifier = 108       /* expr-identifier  */
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
#define YYLAST   767

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  272

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
       0,   216,   216,   221,   229,   233,   244,   248,   255,   267,
     278,   284,   289,   294,   299,   305,   310,   320,   324,   330,
     333,   340,   346,   352,   357,   363,   369,   375,   383,   387,
     397,   403,   409,   414,   419,   424,   432,   436,   448,   452,
     459,   465,   472,   476,   488,   491,   498,   501,   508,   514,
     523,   529,   534,   539,   544,   549,   556,   560,   571,   578,
     582,   586,   590,   594,   598,   602,   606,   616,   619,   626,
     629,   632,   635,   638,   641,   644,   647,   650,   653,   656,
     659,   667,   672,   680,   685,   693,   699,   705,   710,   718,
     726,   735,   740,   748,   754,   762,   767,   775,   780,   788,
     793,   800,   804,   811,   817,   826,   833,   841,   845,   851,
     860,   863,   866,   869,   877,   882,   887,   892,   897,   902,
     907,   912,   917,   922,   927,   932,   937,   945,   950,   957,
     960,   963,   966,   974,   979,   983,   987,   991,   995,  1002,
    1007
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
  "process-def-array", "process-name", "type", "list-statements",
  "statement", "block-statement", "cobegin-statement",
  "assignment-statement", "while-statement", "for-statement",
  "if-statement", "fork-statement", "atomic-statement", "return-statement",
  "print-statement", "list-print", "procedure-invocation",
  "function-invocation", "list-arguments", "argument", "expression",
  "binary-expression", "unary-expression", "term", "literal",
  "expr-identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-68)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      94,  -131,    21,    24,  -131,  -131,   277,  -131,   -48,    80,
     193,   283,  -131,    22,    11,    81,   118,    74,   193,  -131,
    -131,  -131,  -131,    41,   115,  -131,  -131,    16,  -131,  -131,
      32,   127,  -131,    74,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,    54,  -131,  -131,  -131,   237,    75,
      82,    87,   112,  -131,  -131,   113,  -131,   323,   675,   114,
    -131,  -131,  -131,  -131,  -131,  -131,   323,   361,   361,   323,
    -131,  -131,   438,  -131,  -131,  -131,  -131,  -131,  -131,    15,
    -131,    20,    33,    96,    17,  -131,  -131,    72,    47,    97,
     139,   101,  -131,   537,   274,   323,   209,  -131,  -131,   655,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,  -131,  -131,   101,  -131,    49,   153,   733,
     733,   733,   107,    35,   323,   125,    18,   165,   733,  -131,
     137,   140,   671,   555,  -131,  -131,  -131,   -41,   -41,   -41,
     -41,   719,   719,   -33,   -33,  -131,  -131,  -131,   708,   685,
     165,  -131,   101,  -131,  -131,  -131,   148,  -131,   733,   157,
     416,  -131,   161,   323,    73,  -131,  -131,  -131,   323,  -131,
    -131,   165,   101,    52,  -131,   323,  -131,   184,  -131,   323,
    -131,   158,   187,   323,   323,   188,   150,   130,   168,   215,
       9,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,   165,  -131,   101,   573,   323,   323,
     458,  -131,   217,   182,   338,   360,   203,   323,   298,   323,
    -131,   179,   323,  -131,  -131,  -131,   165,   185,   591,   609,
    -131,  -131,  -131,   165,   165,   323,   478,   201,   191,   627,
    -131,   192,   518,  -131,  -131,   204,   205,   238,  -131,   402,
    -131,  -131,   207,   228,   219,   323,  -131,   101,   165,   323,
    -131,   323,  -131,  -131,   165,  -131,   382,   498,  -131,   165,
    -131,  -131
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     5,     4,     0,     1,     0,     0,
      18,     0,    10,     0,     0,     0,     0,     0,    18,    19,
      20,     6,    11,     0,     0,    29,    28,     0,    37,    36,
       0,     0,     2,    44,    46,    47,    17,    12,    66,    58,
      59,    60,    61,    62,     0,    64,    65,    13,     0,     0,
       0,     0,     0,    57,    56,    49,    45,     0,   113,   139,
     133,   134,   138,   135,   136,   137,     0,     0,     0,     0,
       9,   131,     0,   110,   111,   112,   130,   129,    23,    25,
      42,     0,     0,    39,     0,    32,    43,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,   128,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    27,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
       0,   108,   109,     0,    16,     8,   132,   119,   121,   120,
     122,   123,   124,   114,   115,   116,   117,   118,   125,   126,
       0,    26,     0,    38,    41,    40,     0,    33,     0,     0,
       0,    52,     0,     0,     0,    48,    63,   105,     0,   140,
      22,     0,     0,     0,    34,     0,    53,     0,    80,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    76,    77,    78,
      79,    75,   107,    21,     0,    35,     0,     0,     0,     0,
      98,    84,     0,    94,     0,     0,     0,     0,     0,     0,
      96,     0,     0,    81,    68,    31,     0,     0,     0,    55,
      97,    83,    93,     0,     0,     0,    87,     0,     0,     0,
      95,     0,   102,    30,    51,     0,     0,    91,    89,     0,
      85,   104,     0,     0,   100,     0,    54,     0,     0,     0,
     103,     0,    99,   101,     0,    92,     0,    88,    50,     0,
      86,    90
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,   -11,  -131,   259,  -131,  -131,  -131,  -131,
    -131,   -51,  -131,  -131,   246,  -131,  -131,  -131,  -131,    78,
      13,  -131,  -119,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,    25,  -131,  -131,  -130,  -131,   -46,  -131,  -131,
     144,  -131,  -131
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     6,    10,    11,    17,    18,    19,    27,    20,
      30,    82,    83,    84,    32,    33,    34,    35,    55,    48,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   241,   201,    71,   130,   131,   132,    73,    74,
      75,    76,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    88,    72,   106,   107,   108,   109,   110,   165,    12,
     178,    93,    23,   108,   109,   110,   -43,    49,   119,   162,
      96,   114,     4,    99,     7,   179,   164,   -67,   181,   -67,
     182,   170,   183,    51,   116,   184,    38,   185,   202,   186,
      39,    40,    41,    42,    43,    44,    45,    46,   122,   133,
     151,     5,   203,   205,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   153,    50,    24,
     187,   -67,   188,   -43,   178,   120,   163,   115,   160,    22,
     127,    13,    25,    79,    52,   225,   117,    31,   238,   179,
     164,   180,   181,   158,   182,     1,   183,     2,    37,   184,
     123,   185,     8,   186,   150,     9,   152,   243,    57,   206,
      14,    26,    80,    86,   247,   248,    38,   177,    -7,    28,
      39,    40,    41,    42,    43,    44,    45,    46,    53,   207,
     121,   178,    78,   210,   187,    81,   188,   214,   215,   265,
     125,   171,    80,    89,    85,   268,   179,   164,    29,   181,
     271,   182,   118,   183,    86,   124,   184,    54,   185,   178,
     186,   204,   228,   229,   157,    87,    94,    90,    95,   126,
      91,   236,    47,   239,   179,   164,   242,   181,   211,   182,
     161,   183,   164,    80,   184,   208,   185,   217,   186,   249,
     167,   187,   220,   188,   212,   226,   168,   154,   155,   156,
     221,   159,   218,   224,   219,   172,   166,    15,    16,   242,
     134,    97,    98,   266,   174,   267,   176,   213,   216,   187,
     222,   188,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   223,   111,   112,   173,   231,    58,   232,
     235,   240,   244,   209,   252,   254,   264,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   251,   111,
     112,   256,   257,   258,   260,   261,   135,    59,    60,    61,
      62,    63,    64,    65,    66,    92,   262,    36,     8,    56,
     263,     9,    67,     0,     8,     0,    68,     9,     0,    69,
      -7,    -7,    -7,     0,    70,     0,    -7,    -7,    -7,    92,
      -7,     0,     0,     0,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,     0,    68,    92,     0,    69,   129,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,     0,     0,    68,     0,     0,
      69,   237,     0,    59,    60,    61,    62,    63,    64,    65,
       0,     0,   233,     0,     0,     0,     0,     0,    67,     0,
       0,     0,    68,     0,     0,    69,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   234,   111,   112,
       0,    59,    60,    61,    62,    63,    64,    65,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   269,
     111,   112,     0,    69,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   259,   111,   112,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,     0,   111,   112,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,     0,   111,   112,     0,     0,
       0,     0,     0,     0,     0,   175,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,     0,   111,   112,
       0,     0,     0,     0,     0,   113,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,     0,   111,   112,
       0,     0,     0,     0,     0,   230,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,     0,   111,   112,
       0,     0,     0,     0,     0,   250,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,     0,   111,   112,
       0,     0,     0,     0,     0,   270,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,     0,   111,   112,
       0,     0,     0,     0,   255,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,     0,   111,   112,     0,
       0,     0,   128,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,     0,   111,   112,     0,     0,     0,
     169,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,     0,   111,   112,     0,     0,     0,   227,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
       0,   111,   112,     0,     0,     0,   245,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,     0,   111,
     112,     0,     0,     0,   246,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   -14,   111,   112,   -14,
       0,     0,   253,     0,     0,     0,     0,     0,   -14,   -14,
     -14,     0,   -14,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,     0,   111,   112,     0,   136,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
       0,   111,   112,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    38,   111,     0,     0,    39,    40,
      41,    42,    43,    44,    45,    46,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   100,   101,   102,
     103,     0,     0,   106,   107,   108,   109,   110
};

static const yytype_int16 yycheck[] =
{
      11,    52,    48,    44,    45,    46,    47,    48,   127,    57,
       1,    57,     1,    46,    47,    48,     1,     1,     1,     1,
      66,     1,     1,    69,     0,    16,    17,    18,    19,    20,
      21,   150,    23,     1,     1,    26,     1,    28,   168,    30,
       5,     6,     7,     8,     9,    10,    11,    12,     1,    95,
       1,    30,   171,     1,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   118,    52,    58,
      61,    62,    63,    58,     1,    58,    58,    57,   124,    57,
      91,     1,     1,     1,    52,   204,    53,    13,   218,    16,
      17,    18,    19,    58,    21,     1,    23,     3,    57,    26,
      53,    28,     1,    30,   115,     4,    57,   226,    54,    57,
      30,    30,    30,     1,   233,   234,     1,   163,    17,     1,
       5,     6,     7,     8,     9,    10,    11,    12,     1,   175,
      58,     1,    57,   179,    61,    53,    63,   183,   184,   258,
       1,   152,    30,    30,    57,   264,    16,    17,    30,    19,
     269,    21,    56,    23,     1,    58,    26,    30,    28,     1,
      30,   172,   208,   209,    57,    53,    52,    54,    54,    30,
      57,   217,    57,   219,    16,    17,   222,    19,    20,    21,
      55,    23,    17,    30,    26,     1,    28,    37,    30,   235,
      53,    61,    62,    63,   181,   206,    56,   119,   120,   121,
     187,   123,    52,   190,    54,    57,   128,    14,    15,   255,
       1,    67,    68,   259,    57,   261,    55,    30,    30,    61,
      52,    63,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    18,    50,    51,   158,    20,     1,    57,
      37,    62,    57,    59,    53,    53,   257,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    57,    50,
      51,    57,    57,    25,    57,    37,    57,    30,    31,    32,
      33,    34,    35,    36,    37,     1,    57,    18,     1,    33,
     255,     4,    45,    -1,     1,    -1,    49,     4,    -1,    52,
      13,    14,    15,    -1,    57,    -1,    13,    14,    15,     1,
      17,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    49,     1,    -1,    52,    53,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    49,    -1,    -1,    52,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    27,    50,    51,
      -1,    30,    31,    32,    33,    34,    35,    36,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    27,
      50,    51,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    29,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    -1,    -1,    -1,    57,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    -1,    -1,    -1,    57,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    -1,    -1,    -1,    57,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    -1,    -1,    -1,    57,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    -1,    -1,    56,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    -1,
      -1,    -1,    55,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    -1,    -1,    -1,
      55,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    -1,    -1,    -1,    55,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    -1,    -1,    -1,    55,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    -1,    -1,    -1,    55,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     1,    50,    51,     4,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    -1,    17,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    -1,    53,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     1,    50,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    38,    39,    40,
      41,    -1,    -1,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    67,     1,    30,    68,     0,     1,     4,
      69,    70,    57,     1,    30,    14,    15,    71,    72,    73,
      75,    69,    57,     1,    58,     1,    30,    74,     1,    30,
      76,    13,    80,    81,    82,    83,    71,    57,     1,     5,
       6,     7,     8,     9,    10,    11,    12,    57,    85,     1,
      52,     1,    52,     1,    30,    84,    80,    54,     1,    30,
      31,    32,    33,    34,    35,    36,    37,    45,    49,    52,
      57,   100,   103,   104,   105,   106,   107,   108,    57,     1,
      30,    53,    77,    78,    79,    57,     1,    53,    77,    30,
      54,    57,     1,   103,    52,    54,   103,   106,   106,   103,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    50,    51,    57,     1,    57,     1,    53,    56,     1,
      58,    58,     1,    53,    58,     1,    30,    69,    55,    53,
     101,   102,   103,   103,     1,    57,    53,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
      69,     1,    57,    77,    85,    85,    85,    57,    58,    85,
     103,    55,     1,    58,    17,    88,    85,    53,    56,    55,
      88,    69,    57,    85,    57,    59,    55,   103,     1,    16,
      18,    19,    21,    23,    26,    28,    30,    61,    63,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    99,   101,    88,    69,     1,    57,   103,     1,    59,
     103,    20,    86,    30,   103,   103,    30,    37,    52,    54,
      62,    86,    52,    18,    86,    88,    69,    55,   103,   103,
      57,    20,    57,    24,    27,    37,   103,    53,   101,   103,
      62,    98,   103,    88,    57,    55,    55,    88,    88,   103,
      57,    57,    53,    55,    53,    56,    57,    57,    25,    29,
      57,    37,    57,    98,    69,    88,   103,   103,    88,    27,
      57,    88
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    88,    88,    89,    89,    90,    90,    90,    90,    91,
      92,    93,    93,    94,    94,    95,    95,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   102,
     103,   103,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   105,   105,   106,
     106,   106,   106,   107,   107,   107,   107,   107,   107,   108,
     108
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     1,     1,     1,     2,     0,     7,     5,
       2,     3,     4,     4,     5,     6,     7,     2,     0,     1,
       1,     8,     7,     4,     5,     4,     6,     5,     1,     1,
      10,     9,     4,     6,     7,     8,     1,     1,     3,     1,
       3,     3,     1,     1,     1,     2,     1,     1,     5,     2,
      12,     9,     5,     6,    10,     8,     1,     1,     1,     1,
       1,     1,     1,     5,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     2,     4,     7,     3,     6,     4,
       8,     4,     6,     3,     2,     3,     2,     3,     2,     5,
       4,     3,     1,     5,     4,     4,     3,     3,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       4
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
#line 216 "src/parser/parser.y"
                                                                          {
        // -- Crear AST (solo si no hay errores sintacticos)
        AST_program = create_program((yyvsp[-3].ident),(yyvsp[-2].decl),(yyvsp[-1].subprog),(yyvsp[0].proc));
    }
#line 1506 "src/parser/parser.c"
    break;

  case 3: /* program: error  */
#line 221 "src/parser/parser.y"
           {
        mark_error_syntax_program_expected_program();
        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1516 "src/parser/parser.c"
    break;

  case 4: /* program-name: IDENT  */
#line 229 "src/parser/parser.y"
         { 
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1524 "src/parser/parser.c"
    break;

  case 5: /* program-name: error  */
#line 233 "src/parser/parser.y"
            { 
        mark_error_syntax_program_expected_identifier();
        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1534 "src/parser/parser.c"
    break;

  case 6: /* list-declarations: declaration list-declarations  */
#line 244 "src/parser/parser.y"
                                 {
        (yyval.decl) = (yyvsp[-1].decl);
        (yyvsp[-1].decl)->next = (yyvsp[0].decl);
    }
#line 1543 "src/parser/parser.c"
    break;

  case 7: /* list-declarations: %empty  */
#line 248 "src/parser/parser.y"
                   {
        (yyval.decl) = 0;
    }
#line 1551 "src/parser/parser.c"
    break;

  case 8: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression DELIM_PC  */
#line 255 "src/parser/parser.y"
                                                           {
        char * decl_identifier = (yyvsp[-5].ident);
        struct type * decl_type = (yyvsp[-3].type);
        struct expression *decl_expr = (yyvsp[-1].expr);

        // -- Crear nodo
        (yyval.decl) = create_declaration_variable(decl_identifier, decl_type, decl_expr, yylineno);

        // -- Incluir en cache
        add_declaration_to_register((yyval.decl));
    }
#line 1567 "src/parser/parser.c"
    break;

  case 9: /* declaration: S_VAR IDENT DELIM_2P type DELIM_PC  */
#line 267 "src/parser/parser.y"
                                        {
        char * decl_identifier = (yyvsp[-3].ident);
        struct type * decl_type = (yyvsp[-1].type);

        // -- Crear nodo
        (yyval.decl) = create_declaration_variable(decl_identifier, decl_type, 0, yylineno);

        // -- Incluir en cache
        add_declaration_to_register((yyval.decl));
    }
#line 1582 "src/parser/parser.c"
    break;

  case 10: /* declaration: error DELIM_PC  */
#line 278 "src/parser/parser.y"
                    {
        mark_error_syntax_declaration_expected_var();
        // Recuperar
        YYABORT;
    }
#line 1592 "src/parser/parser.c"
    break;

  case 11: /* declaration: S_VAR error DELIM_PC  */
#line 284 "src/parser/parser.y"
                          {
        mark_error_syntax_declaration_expected_identifier();
        YYABORT;
    }
#line 1601 "src/parser/parser.c"
    break;

  case 12: /* declaration: S_VAR IDENT error DELIM_PC  */
#line 289 "src/parser/parser.y"
                                {
        mark_error_syntax_declaration_expected_delim2p();
        YYABORT;
    }
#line 1610 "src/parser/parser.c"
    break;

  case 13: /* declaration: S_VAR IDENT DELIM_2P DELIM_PC  */
#line 294 "src/parser/parser.y"
                                   {
        mark_error_syntax_type_expected_type();
        YYABORT;
    }
#line 1619 "src/parser/parser.c"
    break;

  case 14: /* declaration: S_VAR IDENT DELIM_2P type error  */
#line 299 "src/parser/parser.y"
                                     {
        mark_error_syntax_declaration_expected_delimpc();
        free_AST_type_register();
        YYABORT;
    }
#line 1629 "src/parser/parser.c"
    break;

  case 15: /* declaration: S_VAR IDENT DELIM_2P type expression DELIM_PC  */
#line 305 "src/parser/parser.y"
                                                   {
        mark_error_syntax_declaration_expected_opassign();
        YYABORT;
    }
#line 1638 "src/parser/parser.c"
    break;

  case 16: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression error  */
#line 310 "src/parser/parser.y"
                                                          {
        mark_error_syntax_declaration_expected_delimpc();
        YYABORT;
    }
#line 1647 "src/parser/parser.c"
    break;

  case 17: /* list-subprograms: subprogram list-subprograms  */
#line 320 "src/parser/parser.y"
                               {
        (yyval.subprog) = (yyvsp[-1].subprog);
        (yyvsp[-1].subprog)->next = (yyvsp[0].subprog);
    }
#line 1656 "src/parser/parser.c"
    break;

  case 18: /* list-subprograms: %empty  */
#line 324 "src/parser/parser.y"
                   {
        (yyval.subprog) = 0;
    }
#line 1664 "src/parser/parser.c"
    break;

  case 19: /* subprogram: subprogram-procedure  */
#line 330 "src/parser/parser.y"
                        {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1672 "src/parser/parser.c"
    break;

  case 20: /* subprogram: subprogram-function  */
#line 333 "src/parser/parser.y"
                         {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1680 "src/parser/parser.c"
    break;

  case 21: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statement  */
#line 340 "src/parser/parser.y"
                                                                                                                      {
        // -- Creacion nodo SUBPROGRAMA (PROCEDURE)
        (yyval.subprog) = create_subprogram_procedure((yyvsp[-6].ident), (yyvsp[-4].param), (yyvsp[-1].decl), (yyvsp[0].stmt), yylineno);
        add_subprogram_to_register((yyval.subprog));
    }
#line 1690 "src/parser/parser.c"
    break;

  case 22: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statement  */
#line 346 "src/parser/parser.y"
                                                                                                        {
        // -- Creacion nodo SUBPROGRAMA (PROCEDURE)
        (yyval.subprog) = create_subprogram_procedure((yyvsp[-5].ident), 0, (yyvsp[-1].decl), (yyvsp[0].stmt), yylineno);
        add_subprogram_to_register((yyval.subprog));
    }
#line 1700 "src/parser/parser.c"
    break;

  case 23: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name error DELIM_PC  */
#line 352 "src/parser/parser.y"
                                                          {
        mark_error_syntax_subprogram_expected_parizdo();
        YYABORT;
    }
#line 1709 "src/parser/parser.c"
    break;

  case 24: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters error  */
#line 357 "src/parser/parser.y"
                                                                           {
        mark_error_syntax_subprogram_expected_pardcho();
        free_AST_parameter_register();
        YYABORT;
    }
#line 1719 "src/parser/parser.c"
    break;

  case 25: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO error  */
#line 363 "src/parser/parser.y"
                                                           {
        mark_error_syntax_subprogram_expected_pardcho();
        free_AST_parameter_register();
        YYABORT;
    }
#line 1729 "src/parser/parser.c"
    break;

  case 26: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO error  */
#line 369 "src/parser/parser.y"
                                                                                   {
        mark_error_syntax_subprogram_expected_delimpc();
        free_AST_parameter_register();
        YYABORT;
    }
#line 1739 "src/parser/parser.c"
    break;

  case 27: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO error  */
#line 375 "src/parser/parser.y"
                                                                   {
        mark_error_syntax_subprogram_expected_delimpc();
        free_AST_parameter_register();
        YYABORT;
    }
#line 1749 "src/parser/parser.c"
    break;

  case 28: /* subprogram-procedure-name: IDENT  */
#line 383 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1757 "src/parser/parser.c"
    break;

  case 29: /* subprogram-procedure-name: error  */
#line 387 "src/parser/parser.y"
           {
        // -- Mostrar error
        mark_error_syntax_subprogram_procedure_expected_identifier();
        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1768 "src/parser/parser.c"
    break;

  case 30: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P type DELIM_PC list-declarations block-statement  */
#line 397 "src/parser/parser.y"
                                                                                                                                  {
        // -- Creacion de nodo SUBPROGRAMA (FUNCTION)
        (yyval.subprog) = create_subprogram_function((yyvsp[-8].ident), (yyvsp[-6].param), (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-3].type), yylineno);
        add_subprogram_to_register((yyval.subprog));
    }
#line 1778 "src/parser/parser.c"
    break;

  case 31: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P type DELIM_PC list-declarations block-statement  */
#line 403 "src/parser/parser.y"
                                                                                                                    {
        // -- Creacion de nodo SUBPROGRAMA (FUNCTION)
        (yyval.subprog) = create_subprogram_function((yyvsp[-7].ident), 0, (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-3].type), yylineno);
        add_subprogram_to_register((yyval.subprog));
    }
#line 1788 "src/parser/parser.c"
    break;

  case 32: /* subprogram-function: S_FUNCTION subprogram-function-name error DELIM_PC  */
#line 409 "src/parser/parser.y"
                                                        {
        mark_error_syntax_subprogram_expected_parizdo();
        YYABORT;
    }
#line 1797 "src/parser/parser.c"
    break;

  case 33: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters error DELIM_PC  */
#line 414 "src/parser/parser.y"
                                                                                 {
        mark_error_syntax_subprogram_expected_pardcho();
        YYABORT;
    }
#line 1806 "src/parser/parser.c"
    break;

  case 34: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO type DELIM_PC  */
#line 419 "src/parser/parser.y"
                                                                                         {
        mark_error_syntax_subprogram_function_expected_delim2p();
        YYABORT;
    }
#line 1815 "src/parser/parser.c"
    break;

  case 35: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P type error  */
#line 424 "src/parser/parser.y"
                                                                                               {
        mark_error_syntax_subprogram_expected_delimpc();
        free_AST_parameter_register();
        YYABORT;
    }
#line 1825 "src/parser/parser.c"
    break;

  case 36: /* subprogram-function-name: IDENT  */
#line 432 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1833 "src/parser/parser.c"
    break;

  case 37: /* subprogram-function-name: error  */
#line 436 "src/parser/parser.y"
           {
        // -- Mostrar error
        mark_error_syntax_subprogram_function_expected_identifier();
        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1844 "src/parser/parser.c"
    break;

  case 38: /* list-parameters: parameter DELIM_C list-parameters  */
#line 448 "src/parser/parser.y"
                                     {
        (yyval.param) = (yyvsp[-2].param);
        (yyvsp[-2].param)->next = (yyvsp[0].param);
    }
#line 1853 "src/parser/parser.c"
    break;

  case 39: /* list-parameters: parameter  */
#line 452 "src/parser/parser.y"
               {
        (yyval.param) = (yyvsp[0].param);
    }
#line 1861 "src/parser/parser.c"
    break;

  case 40: /* parameter: parameter-name DELIM_2P type  */
#line 459 "src/parser/parser.y"
                                {
        // -- Creacion de nodo PARAMETRO
        (yyval.param) = create_parameter((yyvsp[-2].ident), (yyvsp[0].type), yylineno);
        add_parameter_to_register((yyval.param));
    }
#line 1871 "src/parser/parser.c"
    break;

  case 41: /* parameter: parameter-name error type  */
#line 465 "src/parser/parser.y"
                               {
        mark_error_syntax_parameter_expected_delim2p();
        YYABORT;
    }
#line 1880 "src/parser/parser.c"
    break;

  case 42: /* parameter-name: IDENT  */
#line 472 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1888 "src/parser/parser.c"
    break;

  case 43: /* parameter-name: error  */
#line 476 "src/parser/parser.y"
           {
        // -- Mostrar error
        mark_error_syntax_parameter_expected_identifier();
        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1899 "src/parser/parser.c"
    break;

  case 44: /* list-process: process  */
#line 488 "src/parser/parser.y"
           {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 1907 "src/parser/parser.c"
    break;

  case 45: /* list-process: process list-process  */
#line 491 "src/parser/parser.y"
                          {
        (yyval.proc) = (yyvsp[-1].proc);
        (yyvsp[-1].proc)->next = (yyvsp[0].proc);
    }
#line 1916 "src/parser/parser.c"
    break;

  case 46: /* process: process-def  */
#line 498 "src/parser/parser.y"
               {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 1924 "src/parser/parser.c"
    break;

  case 47: /* process: process-def-array  */
#line 501 "src/parser/parser.y"
                       {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 1932 "src/parser/parser.c"
    break;

  case 48: /* process-def: S_PROCESS process-name DELIM_PC list-declarations block-statement  */
#line 508 "src/parser/parser.y"
                                                                     {
        // -- Creacion de nodo PROCESO
        (yyval.proc) = create_process_single((yyvsp[-3].ident), (yyvsp[-1].decl), (yyvsp[0].stmt), yylineno);
        add_process_to_register((yyval.proc));
    }
#line 1942 "src/parser/parser.c"
    break;

  case 49: /* process-def: S_PROCESS process-name  */
#line 514 "src/parser/parser.y"
                            {
        mark_error_syntax_process_expected_delimpc();
        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1952 "src/parser/parser.c"
    break;

  case 50: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC list-declarations block-statement  */
#line 523 "src/parser/parser.y"
                                                                                                                                          {
        // -- Creacion de nodo PROCESO
        (yyval.proc) = create_process_vector((yyvsp[-10].ident), (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-8].ident), (yyvsp[-6].expr), (yyvsp[-4].expr), yylineno);
        add_process_to_register((yyval.proc));
    }
#line 1962 "src/parser/parser.c"
    break;

  case 51: /* process-def-array: S_PROCESS process-name IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC  */
#line 529 "src/parser/parser.y"
                                                                                               {
        mark_error_syntax_process_expected_corchizdo();
        YYABORT;
    }
#line 1971 "src/parser/parser.c"
    break;

  case 52: /* process-def-array: S_PROCESS process-name CORCH_IZDO error CORCH_DCHO  */
#line 534 "src/parser/parser.y"
                                                        {
        mark_error_syntax_process_expected_index_identifier();
        YYABORT;
    }
#line 1980 "src/parser/parser.c"
    break;

  case 53: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT error CORCH_DCHO  */
#line 539 "src/parser/parser.y"
                                                              {
        mark_error_syntax_process_expected_delim2p();
        YYABORT;
    }
#line 1989 "src/parser/parser.c"
    break;

  case 54: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression error expression CORCH_DCHO DELIM_PC  */
#line 544 "src/parser/parser.y"
                                                                                                      {
        mark_error_syntax_process_expected_delimarr();
        YYABORT;
    }
#line 1998 "src/parser/parser.c"
    break;

  case 55: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression  */
#line 549 "src/parser/parser.y"
                                                                                      {
        mark_error_syntax_process_expected_corchdcho();
        YYABORT;
    }
#line 2007 "src/parser/parser.c"
    break;

  case 56: /* process-name: IDENT  */
#line 556 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 2015 "src/parser/parser.c"
    break;

  case 57: /* process-name: error  */
#line 560 "src/parser/parser.y"
           {
        mark_error_syntax_process_expected_identifier();
        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 2025 "src/parser/parser.c"
    break;

  case 58: /* type: T_INTEGER  */
#line 571 "src/parser/parser.y"
             {
        // -- Crear nodo de tipo
        (yyval.type) = create_basic_type(TYPE_INTEGER);

        // -- Incluir en el registro
        add_type_to_register((yyval.type));
    }
#line 2037 "src/parser/parser.c"
    break;

  case 59: /* type: T_BOOLEAN  */
#line 578 "src/parser/parser.y"
               {
        (yyval.type) = create_basic_type(TYPE_BOOLEAN);
        add_type_to_register((yyval.type));
    }
#line 2046 "src/parser/parser.c"
    break;

  case 60: /* type: T_CHAR  */
#line 582 "src/parser/parser.y"
            {
        (yyval.type) = create_basic_type(TYPE_CHAR);
        add_type_to_register((yyval.type));
    }
#line 2055 "src/parser/parser.c"
    break;

  case 61: /* type: T_STRING  */
#line 586 "src/parser/parser.y"
              {
        (yyval.type) = create_basic_type(TYPE_STRING);
        add_type_to_register((yyval.type));
    }
#line 2064 "src/parser/parser.c"
    break;

  case 62: /* type: T_REAL  */
#line 590 "src/parser/parser.y"
            {
        (yyval.type) = create_basic_type(TYPE_REAL);
        add_type_to_register((yyval.type));
    }
#line 2073 "src/parser/parser.c"
    break;

  case 63: /* type: T_ARRAY CORCH_IZDO expression CORCH_DCHO type  */
#line 594 "src/parser/parser.y"
                                                   {
        (yyval.type) = create_array_type((yyvsp[0].type),(yyvsp[-2].expr));
        add_type_to_register((yyval.type));
    }
#line 2082 "src/parser/parser.c"
    break;

  case 64: /* type: T_SEMAPHORE  */
#line 598 "src/parser/parser.y"
                 {
        (yyval.type) = create_semaphore_type();
        add_type_to_register((yyval.type));
    }
#line 2091 "src/parser/parser.c"
    break;

  case 65: /* type: T_DPROCESS  */
#line 602 "src/parser/parser.y"
                {
        (yyval.type) = create_dprocess_type();
        add_type_to_register((yyval.type));
    }
#line 2100 "src/parser/parser.c"
    break;

  case 66: /* type: error  */
#line 606 "src/parser/parser.y"
           {
        mark_error_syntax_type_expected_type();
        YYABORT;
    }
#line 2109 "src/parser/parser.c"
    break;

  case 67: /* list-statements: statement  */
#line 616 "src/parser/parser.y"
             {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2117 "src/parser/parser.c"
    break;

  case 68: /* list-statements: statement list-statements  */
#line 619 "src/parser/parser.y"
                               {
        (yyval.stmt) = (yyvsp[-1].stmt);
        (yyvsp[-1].stmt)->next = (yyvsp[0].stmt);
    }
#line 2126 "src/parser/parser.c"
    break;

  case 69: /* statement: block-statement  */
#line 626 "src/parser/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2134 "src/parser/parser.c"
    break;

  case 70: /* statement: cobegin-statement  */
#line 629 "src/parser/parser.y"
                       {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2142 "src/parser/parser.c"
    break;

  case 71: /* statement: assignment-statement  */
#line 632 "src/parser/parser.y"
                          {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2150 "src/parser/parser.c"
    break;

  case 72: /* statement: while-statement  */
#line 635 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2158 "src/parser/parser.c"
    break;

  case 73: /* statement: for-statement  */
#line 638 "src/parser/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2166 "src/parser/parser.c"
    break;

  case 74: /* statement: if-statement  */
#line 641 "src/parser/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2174 "src/parser/parser.c"
    break;

  case 75: /* statement: procedure-invocation  */
#line 644 "src/parser/parser.y"
                          {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2182 "src/parser/parser.c"
    break;

  case 76: /* statement: fork-statement  */
#line 647 "src/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2190 "src/parser/parser.c"
    break;

  case 77: /* statement: atomic-statement  */
#line 650 "src/parser/parser.y"
                      {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2198 "src/parser/parser.c"
    break;

  case 78: /* statement: return-statement  */
#line 653 "src/parser/parser.y"
                      {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2206 "src/parser/parser.c"
    break;

  case 79: /* statement: print-statement  */
#line 656 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2214 "src/parser/parser.c"
    break;

  case 80: /* statement: error  */
#line 659 "src/parser/parser.y"
           {
        mark_error_syntax_statement_expected_statement();
        YYABORT;
    }
#line 2223 "src/parser/parser.c"
    break;

  case 81: /* block-statement: B_BEGIN list-statements B_END  */
#line 667 "src/parser/parser.y"
                                 {
        (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
        add_statement_to_register((yyval.stmt));
    }
#line 2232 "src/parser/parser.c"
    break;

  case 82: /* block-statement: B_BEGIN B_END  */
#line 672 "src/parser/parser.y"
                   {
        mark_error_syntax_statement_empty_block();
        YYABORT;
    }
#line 2241 "src/parser/parser.c"
    break;

  case 83: /* cobegin-statement: B_COBEGIN list-statements B_COEND  */
#line 680 "src/parser/parser.y"
                                     {
        (yyval.stmt) = create_statement_block_cobegin((yyvsp[-1].stmt));
        add_statement_to_register((yyval.stmt));
    }
#line 2250 "src/parser/parser.c"
    break;

  case 84: /* cobegin-statement: B_COBEGIN B_COEND  */
#line 685 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_empty_block();
        YYABORT;
    }
#line 2259 "src/parser/parser.c"
    break;

  case 85: /* assignment-statement: IDENT OP_ASSIGN expression DELIM_PC  */
#line 693 "src/parser/parser.y"
                                       {
        // -- Creacion de nodo STATEMENT (ASSIGNMENT)
        (yyval.stmt) = create_statement_assignment((yyvsp[-3].ident), 0, (yyvsp[-1].expr), yylineno);
        add_statement_to_register((yyval.stmt));
    }
#line 2269 "src/parser/parser.c"
    break;

  case 86: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression DELIM_PC  */
#line 699 "src/parser/parser.y"
                                                                          {
        // -- Creacion de nodo STATEMENT (ASSIGNMENT)
        (yyval.stmt) = create_statement_assignment((yyvsp[-6].ident), (yyvsp[-4].expr), (yyvsp[-1].expr), yylineno);
        add_statement_to_register((yyval.stmt));
    }
#line 2279 "src/parser/parser.c"
    break;

  case 87: /* assignment-statement: IDENT OP_ASSIGN expression  */
#line 705 "src/parser/parser.y"
                                {
        mark_error_syntax_statement_expected_delimpc();
        YYABORT;
    }
#line 2288 "src/parser/parser.c"
    break;

  case 88: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression  */
#line 710 "src/parser/parser.y"
                                                                 {
        mark_error_syntax_statement_expected_delimpc();
        YYABORT;
    }
#line 2297 "src/parser/parser.c"
    break;

  case 89: /* while-statement: WHILE expression DO block-statement  */
#line 718 "src/parser/parser.y"
                                       {
        (yyval.stmt) = create_statement_while((yyvsp[-2].expr), (yyvsp[0].stmt));
        add_statement_to_register((yyval.stmt));
    }
#line 2306 "src/parser/parser.c"
    break;

  case 90: /* for-statement: FOR IDENT OP_ASSIGN expression TO expression DO block-statement  */
#line 726 "src/parser/parser.y"
                                                                   {
        // -- Creacion de nodo STATEMENT (FOR)
        (yyval.stmt) = create_statement_for((yyvsp[-6].ident), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), yylineno);
        add_statement_to_register((yyval.stmt));
    }
#line 2316 "src/parser/parser.c"
    break;

  case 91: /* if-statement: IF expression THEN block-statement  */
#line 735 "src/parser/parser.y"
                                      {
        (yyval.stmt) = create_statement_if_else((yyvsp[-2].expr), (yyvsp[0].stmt), 0);
        add_statement_to_register((yyval.stmt));
    }
#line 2325 "src/parser/parser.c"
    break;

  case 92: /* if-statement: IF expression THEN block-statement ELSE block-statement  */
#line 740 "src/parser/parser.y"
                                                             {
        (yyval.stmt) = create_statement_if_else((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt));
        add_statement_to_register((yyval.stmt));
    }
#line 2334 "src/parser/parser.c"
    break;

  case 93: /* fork-statement: S_FORK IDENT DELIM_PC  */
#line 748 "src/parser/parser.y"
                         {
        // -- Creacion de nodo STATEMENT (FORK)
        (yyval.stmt) = create_statement_fork((yyvsp[-1].ident), yylineno);
        add_statement_to_register((yyval.stmt));
    }
#line 2344 "src/parser/parser.c"
    break;

  case 94: /* fork-statement: S_FORK IDENT  */
#line 754 "src/parser/parser.y"
                  {
        mark_error_syntax_statement_expected_delimpc();
        YYABORT;
    }
#line 2353 "src/parser/parser.c"
    break;

  case 95: /* atomic-statement: ATOM_INI list-statements ATOM_FIN  */
#line 762 "src/parser/parser.y"
                                     {
        (yyval.stmt) = create_statement_atomic((yyvsp[-1].stmt));
        add_statement_to_register((yyval.stmt));
    }
#line 2362 "src/parser/parser.c"
    break;

  case 96: /* atomic-statement: ATOM_INI ATOM_FIN  */
#line 767 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_empty_block();
        YYABORT;
    }
#line 2371 "src/parser/parser.c"
    break;

  case 97: /* return-statement: RETURN expression DELIM_PC  */
#line 775 "src/parser/parser.y"
                              {
        (yyval.stmt) = create_statement_return((yyvsp[-1].expr));
        add_statement_to_register((yyval.stmt));
    }
#line 2380 "src/parser/parser.c"
    break;

  case 98: /* return-statement: RETURN expression  */
#line 780 "src/parser/parser.y"
                       {
        mark_error_syntax_statement_expected_delimpc();
        YYABORT;
    }
#line 2389 "src/parser/parser.c"
    break;

  case 99: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO DELIM_PC  */
#line 788 "src/parser/parser.y"
                                               {
        (yyval.stmt) = create_statement_print((yyvsp[-2].expr));
        add_statement_to_register((yyval.stmt));
    }
#line 2398 "src/parser/parser.c"
    break;

  case 100: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO  */
#line 793 "src/parser/parser.y"
                                        {
        mark_error_syntax_statement_expected_delimpc();
        YYABORT;
    }
#line 2407 "src/parser/parser.c"
    break;

  case 101: /* list-print: expression DELIM_C list-print  */
#line 800 "src/parser/parser.y"
                                 {
        (yyval.expr) = (yyvsp[-2].expr);
        (yyvsp[-2].expr)->next = (yyvsp[0].expr);
    }
#line 2416 "src/parser/parser.c"
    break;

  case 102: /* list-print: expression  */
#line 804 "src/parser/parser.y"
                {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2424 "src/parser/parser.c"
    break;

  case 103: /* procedure-invocation: IDENT PAR_IZDO list-arguments PAR_DCHO DELIM_PC  */
#line 811 "src/parser/parser.y"
                                                   {
        // -- Creacion de nodo STATEMENT (PROCEDURE INVOCATION)
        (yyval.stmt) = create_statement_procedure_inv((yyvsp[-4].ident), (yyvsp[-2].expr), yylineno);
        add_statement_to_register((yyval.stmt));
    }
#line 2434 "src/parser/parser.c"
    break;

  case 104: /* procedure-invocation: IDENT PAR_IZDO PAR_DCHO DELIM_PC  */
#line 817 "src/parser/parser.y"
                                      {
        // -- Creacion de nodo STATEMENT (PROCEDURE INVOCATION)
        (yyval.stmt) = create_statement_procedure_inv((yyvsp[-3].ident), 0, yylineno);
        add_statement_to_register((yyval.stmt));
    }
#line 2444 "src/parser/parser.c"
    break;

  case 105: /* function-invocation: IDENT PAR_IZDO list-arguments PAR_DCHO  */
#line 826 "src/parser/parser.y"
                                          {
        // -- Creacion de nodo EXPRESSION
        (yyval.expr) = create_expression_function_invocation((yyvsp[-3].ident), (yyvsp[-1].expr), yylineno);
        add_expression_to_register((yyval.expr));

    }
#line 2455 "src/parser/parser.c"
    break;

  case 106: /* function-invocation: IDENT PAR_IZDO PAR_DCHO  */
#line 833 "src/parser/parser.y"
                             {
        // -- Creacion de nodo EXPRESSION
        (yyval.expr) = create_expression_function_invocation((yyvsp[-2].ident), 0, yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2465 "src/parser/parser.c"
    break;

  case 107: /* list-arguments: argument DELIM_C list-arguments  */
#line 841 "src/parser/parser.y"
                                   {
        (yyval.expr) = (yyvsp[-2].expr);
        (yyvsp[-2].expr)->next = (yyvsp[0].expr);
    }
#line 2474 "src/parser/parser.c"
    break;

  case 108: /* list-arguments: argument  */
#line 845 "src/parser/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2482 "src/parser/parser.c"
    break;

  case 109: /* argument: expression  */
#line 851 "src/parser/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2490 "src/parser/parser.c"
    break;

  case 110: /* expression: binary-expression  */
#line 860 "src/parser/parser.y"
                     {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2498 "src/parser/parser.c"
    break;

  case 111: /* expression: unary-expression  */
#line 863 "src/parser/parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2506 "src/parser/parser.c"
    break;

  case 112: /* expression: term  */
#line 866 "src/parser/parser.y"
          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2514 "src/parser/parser.c"
    break;

  case 113: /* expression: error  */
#line 869 "src/parser/parser.y"
           {
        mark_error_syntax_expression_expected_expr();
        YYABORT;
    }
#line 2523 "src/parser/parser.c"
    break;

  case 114: /* binary-expression: expression OP_SUM expression  */
#line 877 "src/parser/parser.y"
                                {
        (yyval.expr) = create_expression_binary_operation(EXPR_ADD, "+", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2532 "src/parser/parser.c"
    break;

  case 115: /* binary-expression: expression OP_MINUS expression  */
#line 882 "src/parser/parser.y"
                                    {
        (yyval.expr) = create_expression_binary_operation(EXPR_SUB, "-", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2541 "src/parser/parser.c"
    break;

  case 116: /* binary-expression: expression OP_MULT expression  */
#line 887 "src/parser/parser.y"
                                   {
        (yyval.expr) = create_expression_binary_operation(EXPR_MULT, "*", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2550 "src/parser/parser.c"
    break;

  case 117: /* binary-expression: expression OP_DIV expression  */
#line 892 "src/parser/parser.y"
                                  {
        (yyval.expr) = create_expression_binary_operation(EXPR_DIV, "/", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2559 "src/parser/parser.c"
    break;

  case 118: /* binary-expression: expression OP_MOD expression  */
#line 897 "src/parser/parser.y"
                                  {
        (yyval.expr) = create_expression_binary_operation(EXPR_MOD, "%", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2568 "src/parser/parser.c"
    break;

  case 119: /* binary-expression: expression OP_REL_LT expression  */
#line 902 "src/parser/parser.y"
                                     {
        (yyval.expr) = create_expression_binary_operation(EXPR_LT, "<", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2577 "src/parser/parser.c"
    break;

  case 120: /* binary-expression: expression OP_REL_LTE expression  */
#line 907 "src/parser/parser.y"
                                      {
        (yyval.expr) = create_expression_binary_operation(EXPR_LTE, "<=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2586 "src/parser/parser.c"
    break;

  case 121: /* binary-expression: expression OP_REL_GT expression  */
#line 912 "src/parser/parser.y"
                                     {
        (yyval.expr) = create_expression_binary_operation(EXPR_GT, ">", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2595 "src/parser/parser.c"
    break;

  case 122: /* binary-expression: expression OP_REL_GTE expression  */
#line 917 "src/parser/parser.y"
                                      {
        (yyval.expr) = create_expression_binary_operation(EXPR_GTE, ">=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2604 "src/parser/parser.c"
    break;

  case 123: /* binary-expression: expression OP_REL_EQ expression  */
#line 922 "src/parser/parser.y"
                                     {
        (yyval.expr) = create_expression_binary_operation(EXPR_EQ, "==", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2613 "src/parser/parser.c"
    break;

  case 124: /* binary-expression: expression OP_REL_NEQ expression  */
#line 927 "src/parser/parser.y"
                                      {
        (yyval.expr) = create_expression_binary_operation(EXPR_NEQ, "!=", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2622 "src/parser/parser.c"
    break;

  case 125: /* binary-expression: expression OP_AND expression  */
#line 932 "src/parser/parser.y"
                                  {
        (yyval.expr) = create_expression_binary_operation(EXPR_AND, "and", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2631 "src/parser/parser.c"
    break;

  case 126: /* binary-expression: expression OP_OR expression  */
#line 937 "src/parser/parser.y"
                                 {
        (yyval.expr) = create_expression_binary_operation(EXPR_OR, "or", (yyvsp[-2].expr), (yyvsp[0].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2640 "src/parser/parser.c"
    break;

  case 127: /* unary-expression: OP_NOT term  */
#line 945 "src/parser/parser.y"
               {
        (yyval.expr) = create_expression_unary_operation(EXPR_NOT, "not", (yyvsp[0].expr),yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2649 "src/parser/parser.c"
    break;

  case 128: /* unary-expression: OP_MINUS term  */
#line 950 "src/parser/parser.y"
                                  {
        (yyval.expr) = create_expression_unary_operation(EXPR_NEGATIVE, "-", (yyvsp[0].expr),yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2658 "src/parser/parser.c"
    break;

  case 129: /* term: expr-identifier  */
#line 957 "src/parser/parser.y"
                   {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2666 "src/parser/parser.c"
    break;

  case 130: /* term: literal  */
#line 960 "src/parser/parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2674 "src/parser/parser.c"
    break;

  case 131: /* term: function-invocation  */
#line 963 "src/parser/parser.y"
                         {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2682 "src/parser/parser.c"
    break;

  case 132: /* term: PAR_IZDO expression PAR_DCHO  */
#line 966 "src/parser/parser.y"
                                  {
        (yyval.expr) = create_expression_grouped((yyvsp[-1].expr));
        add_expression_to_register((yyval.expr));
    }
#line 2691 "src/parser/parser.c"
    break;

  case 133: /* literal: LITERAL  */
#line 974 "src/parser/parser.y"
           {
        // -- Crear expresion literal
        (yyval.expr) = create_expression_literal_string((yyvsp[0].literal_string));
        add_expression_to_register((yyval.expr));
    }
#line 2701 "src/parser/parser.c"
    break;

  case 134: /* literal: L_INTEGER  */
#line 979 "src/parser/parser.y"
               {
        (yyval.expr) = create_expression_literal_integer((yyvsp[0].literal_int));
        add_expression_to_register((yyval.expr));
    }
#line 2710 "src/parser/parser.c"
    break;

  case 135: /* literal: L_BOOLEAN_TRUE  */
#line 983 "src/parser/parser.y"
                    {
        (yyval.expr) = create_expression_literal_boolean(1);
        add_expression_to_register((yyval.expr));
    }
#line 2719 "src/parser/parser.c"
    break;

  case 136: /* literal: L_BOOLEAN_FALSE  */
#line 987 "src/parser/parser.y"
                     {
        (yyval.expr) = create_expression_literal_boolean(0);
        add_expression_to_register((yyval.expr));
    }
#line 2728 "src/parser/parser.c"
    break;

  case 137: /* literal: L_CHAR  */
#line 991 "src/parser/parser.y"
            {
        (yyval.expr) = create_expression_literal_char((yyvsp[0].literal_char));
        add_expression_to_register((yyval.expr));
    }
#line 2737 "src/parser/parser.c"
    break;

  case 138: /* literal: L_REAL  */
#line 995 "src/parser/parser.y"
            {
        (yyval.expr) = create_expression_literal_real((yyvsp[0].literal_float));
        add_expression_to_register((yyval.expr));
    }
#line 2746 "src/parser/parser.c"
    break;

  case 139: /* expr-identifier: IDENT  */
#line 1002 "src/parser/parser.y"
         {
        // -- Crear expresion
        (yyval.expr) = create_expression_identifier((yyvsp[0].ident),0, yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2756 "src/parser/parser.c"
    break;

  case 140: /* expr-identifier: IDENT CORCH_IZDO expression CORCH_DCHO  */
#line 1007 "src/parser/parser.y"
                                            {
        // -- Crear expresion
        (yyval.expr) = create_expression_identifier((yyvsp[-3].ident), (yyvsp[-1].expr), yylineno);
        add_expression_to_register((yyval.expr));
    }
#line 2766 "src/parser/parser.c"
    break;


#line 2770 "src/parser/parser.c"

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

#line 1014 "src/parser/parser.y"


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

void mark_error_syntax_declaration_expected_var(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_VAR_TOKEN_MSG);
}  

void mark_error_syntax_declaration_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_IDENTIFIER_AFTER_VAR_MSG);
}

void mark_error_syntax_declaration_expected_delim2p(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_DELIM2P_TOKEN_MSG);
}

void mark_error_syntax_declaration_expected_opassign(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_EXPR, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_OPASSIGN_TOKEN_MSG);
}

void mark_error_syntax_declaration_expected_delimpc(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_DECLARATION_EXPECTED_DELIMPC_DECL_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (SUBPROGRAMAS)

void mark_error_syntax_subprogram_expected_procedure(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROCEDURE_EXPECTED_PROCEDURE_TOKEN_MSG);
}

void mark_error_syntax_subprogram_procedure_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_PROCEDURE_EXPECTED_IDENTIFIER_AFTER_PROCEDURE_MSG);
}

void mark_error_syntax_subprogram_function_expected_function(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_FUNCTION_TOKEN_MSG);
}

void mark_error_syntax_subprogram_function_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_IDENTIFIER_AFTER_FUNCTION_MSG);
}

void mark_error_syntax_subprogram_function_expected_delim2p(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_FUNCTION_EXPECTED_DELIM2P_TOKEN_MSG);
}

void mark_error_syntax_subprogram_expected_parizdo(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_SUBPROGRAM_EXPECTED_PARIZDO_TOKEN_MSG);
}

void mark_error_syntax_subprogram_expected_pardcho(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_SUBPROGRAM_EXPECTED_PARDCHO_TOKEN_MSG);
}

void mark_error_syntax_subprogram_expected_delimpc(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_SUBPROGRAM_EXPECTED_DELIMPC_TOKEN_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (TIPOS)

void mark_error_syntax_type_expected_type(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_TYPE_EXPECTED_TYPE_TOKEN_MSG);
}


// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (PARAMETROS)

void mark_error_syntax_parameter_expected_parameter(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PARAMETER_EXPECTED_PARAMETER_MSG);
}

void mark_error_syntax_parameter_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_PARAMETER_EXPECTED_IDENTIFIER_MSG);
}

void mark_error_syntax_parameter_expected_delim2p(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PARAMETER_EXPECTED_DELIM2P_MSG);
}

void mark_error_syntax_parameter_expected_delimc(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PARAMETER_EXPECTED_DELIMC_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (SENTENCIAS)

void mark_error_syntax_statement_expected_statement(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_STMT, yylineno, ERR_SYNTAX_STATEMENT_EXPECTED_STATEMENT_MSG);
}

void mark_error_syntax_statement_empty_block(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_STMT, yylineno, ERR_SYNTAX_STATEMENT_EXPECTED_NON_EMPTY_BLOCK_MSG);
}

void mark_error_syntax_statement_expected_delimpc(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_EXPR, yylineno, ERR_SYNTAX_STATEMENT_EXPECTED_DELIMPC_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (EXPRESIONES)

void mark_error_syntax_expression_expected_expr(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_EXPR, yylineno, ERR_SYNTAX_EXPRESSION_EXPECTED_EXPRESSION_MSG);
}

// ----/////----------------------------------------------------------
// IMPLEMENTACION DE FUNCIONES DE MANEJO DE ERRORES (PROCESOS)

void mark_error_syntax_process_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_IDENTIFIER_AFTER_PROCESS_MSG);
}

void mark_error_syntax_process_expected_delimpc(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_DELIMPC_MSG);
}

void mark_error_syntax_process_expected_corchizdo(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_CORCHIZDO_MSG);
}

void mark_error_syntax_process_expected_corchdcho(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_CORCHDCHO_MSG);
}

void mark_error_syntax_process_expected_index_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_IDENTIFIER_INDEXER_MSG);
}

void mark_error_syntax_process_expected_delim2p(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_DELIM2P_MSG);
}

void mark_error_syntax_process_expected_delimarr(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROCESS_EXPECTED_DELIMARR_MSG);
}

// ----/////----------------------------------------------------------
// FUNCIONES DE MANEJO DE ERRORES (PROGRAMAS)

void mark_error_syntax_program_expected_program(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_TOKEN, yylineno, ERR_SYNTAX_PROGRAM_EXPECTED_PROGRAM_TOKEN_MSG);
}

void mark_error_syntax_program_expected_identifier(){
    // -- Crear error sintactico e incluir en la lista de errores sintacticos
    create_and_add_error_syntax_to_list(EXPECTED_IDENTIFIER, yylineno, ERR_SYNTAX_PROGRAM_EXPECTED_IDENTIFIER_AFTER_PROGRAM_MSG);
}
