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

    // -- Inclusion de mensajes de errores de parser
    #include "parser/parser_errors.h"

    // -----------------------------------------------------------------
    // DEFINICION DE FUNCIONES Y ESTRUCTURAS PROPIAS DE BISON

    // -- Variables y funciones a utilizar por el analizador sintactico
    extern int yylex();
    extern FILE *yyin;
    extern int yylineno;

    void yyerror(const char* s);  

#line 92 "src/parser/parser.c"

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
  YYSYMBOL_UNRECOGNIZED_TOKEN = 64,        /* UNRECOGNIZED_TOKEN  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_67_program_name = 67,           /* program-name  */
  YYSYMBOL_68_list_declarations = 68,      /* list-declarations  */
  YYSYMBOL_declaration = 69,               /* declaration  */
  YYSYMBOL_70_declaration_var_with_assignment = 70, /* declaration-var-with-assignment  */
  YYSYMBOL_71_declaration_var = 71,        /* declaration-var  */
  YYSYMBOL_72_declaration_name = 72,       /* declaration-name  */
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
  YYSYMBOL_88_list_statements = 88,        /* list-statements  */
  YYSYMBOL_statement = 89,                 /* statement  */
  YYSYMBOL_90_block_statement = 90,        /* block-statement  */
  YYSYMBOL_91_cobegin_statement = 91,      /* cobegin-statement  */
  YYSYMBOL_92_assignment_statement = 92,   /* assignment-statement  */
  YYSYMBOL_93_while_statement = 93,        /* while-statement  */
  YYSYMBOL_94_for_statement = 94,          /* for-statement  */
  YYSYMBOL_95_if_statement = 95,           /* if-statement  */
  YYSYMBOL_96_fork_statement = 96,         /* fork-statement  */
  YYSYMBOL_97_atomic_statement = 97,       /* atomic-statement  */
  YYSYMBOL_98_return_statement = 98,       /* return-statement  */
  YYSYMBOL_99_print_statement = 99,        /* print-statement  */
  YYSYMBOL_100_list_print = 100,           /* list-print  */
  YYSYMBOL_101_procedure_invocation = 101, /* procedure-invocation  */
  YYSYMBOL_102_function_invocation = 102,  /* function-invocation  */
  YYSYMBOL_103_list_arguments = 103,       /* list-arguments  */
  YYSYMBOL_argument = 104,                 /* argument  */
  YYSYMBOL_expression = 105,               /* expression  */
  YYSYMBOL_106_binary_expression = 106,    /* binary-expression  */
  YYSYMBOL_107_unary_expression = 107,     /* unary-expression  */
  YYSYMBOL_term = 108,                     /* term  */
  YYSYMBOL_literal = 109,                  /* literal  */
  YYSYMBOL_110_expr_identifier = 110       /* expr-identifier  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   320


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
       2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   195,   195,   205,   215,   219,   230,   234,   240,   243,
     247,   257,   268,   276,   286,   297,   305,   315,   319,   330,
     334,   340,   343,   350,   361,   372,   382,   386,   397,   408,
     419,   429,   433,   443,   447,   453,   464,   474,   478,   489,
     492,   499,   502,   509,   520,   531,   544,   548,   560,   563,
     566,   569,   572,   575,   578,   581,   585,   596,   599,   606,
     609,   612,   615,   618,   621,   624,   627,   630,   633,   636,
     639,   649,   655,   662,   673,   686,   692,   705,   708,   714,
     727,   733,   739,   745,   749,   756,   766,   779,   789,   802,
     806,   812,   819,   822,   825,   828,   839,   843,   847,   851,
     855,   859,   863,   867,   871,   875,   879,   883,   887,   894,
     898,   904,   907,   910,   913,   920,   928,   931,   934,   937,
     940,   946,   954
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
  "DELIM_ARR", "DELIM_P", "ATOM_INI", "ATOM_FIN", "PRINT",
  "UNRECOGNIZED_TOKEN", "$accept", "program", "program-name",
  "list-declarations", "declaration", "declaration-var-with-assignment",
  "declaration-var", "declaration-name", "list-subprograms", "subprogram",
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

#define YYPACT_NINF (-172)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-58)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,  -172,     0,    23,  -172,  -172,   153,  -172,  -172,     2,
      22,   189,  -172,  -172,  -172,  -172,     1,     3,     9,    21,
      22,  -172,  -172,  -172,   251,   251,   -14,  -172,    32,    41,
    -172,    44,    10,  -172,    21,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,   -13,  -172,  -172,   -31,    81,    90,
      91,  -172,  -172,    26,  -172,   188,   188,  -172,  -172,   188,
    -172,  -172,  -172,    -5,    47,    -2,    20,    40,    49,    14,
      85,    14,  -172,   -30,  -172,  -172,  -172,  -172,  -172,  -172,
      99,    99,   188,  -172,    56,  -172,  -172,   203,  -172,  -172,
      62,    28,    14,    79,    19,   251,   251,   251,    84,   120,
      87,   120,   139,   188,  -172,  -172,    94,   251,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,  -172,  -172,  -172,   120,    14,  -172,  -172,  -172,    96,
     251,    78,  -172,   188,  -172,  -172,   103,   102,  -172,   106,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,   120,    14,   105,  -172,
     188,    78,   133,   188,   188,   146,    70,    78,   126,   161,
      27,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,   121,  -172,   188,  -172,  -172,   120,    14,   124,
     163,   129,   177,   178,   170,   188,   164,   188,   148,   188,
    -172,  -172,   188,  -172,  -172,   120,  -172,  -172,  -172,   120,
     120,   188,   151,   154,   159,   160,  -172,   172,   158,   173,
    -172,   202,  -172,   200,  -172,  -172,   174,   193,   175,   188,
     179,   120,   188,  -172,   188,  -172,  -172,    14,  -172,   207,
     181,   120,   120,  -172,  -172,  -172
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     5,     4,     0,     1,    10,     0,
      20,     0,    18,    17,     8,     9,     0,     0,     0,     0,
      20,    21,    22,     6,     0,     0,    25,    26,     0,    30,
      31,     0,     0,     2,    39,    41,    42,    19,    56,    48,
      49,    50,    51,    52,     0,    54,    55,     0,     0,     0,
       0,    47,    46,     0,    40,     0,     0,    15,    16,     0,
      14,    38,    37,     0,     0,    34,     0,     0,     0,     0,
       0,     0,    95,   121,   115,   116,   120,   117,   118,   119,
       0,     0,     0,   113,     0,    92,    93,    94,   112,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    11,     0,     0,    33,    36,    35,     0,
       0,     0,    44,     0,    43,    88,     0,    90,    91,     0,
     114,    53,   101,   103,   102,   104,   105,   106,    96,    97,
      98,    99,   100,   107,   108,    24,     0,     0,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,    64,    66,    67,    68,
      69,    65,     0,    87,     0,   122,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    58,     0,    89,    29,     0,    81,    72,    79,     0,
       0,     0,     0,     0,     0,     0,    80,     0,    84,     0,
      28,    77,    75,     0,    73,    86,     0,     0,     0,     0,
       0,     0,     0,    85,     0,    82,    83,     0,    78,     0,
       0,     0,     0,    74,    45,    76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,  -172,   -11,  -172,  -172,  -172,  -172,   215,  -172,
    -172,  -172,  -172,  -172,   -43,  -172,  -172,   205,  -172,  -172,
    -172,  -172,   -20,   -58,  -172,   -82,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,    35,  -172,  -172,  -171,  -172,
     -47,  -172,  -172,    45,  -172,  -172
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     6,    10,    11,    14,    15,    16,    19,    20,
      21,    28,    22,    31,    64,    65,    66,    33,    34,    35,
      36,    53,    47,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   217,   181,    83,   136,   137,
     138,    85,    86,    87,    88,    89
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,     4,    24,    12,    26,    48,    56,    68,    84,    90,
      29,    51,    91,   203,     1,     8,     2,   132,     9,   134,
      61,    95,   102,     7,   103,   214,    57,    69,   159,   122,
       5,    -7,    13,    27,    32,   106,    17,    18,   -27,    30,
      52,    55,   155,   160,   131,   -57,   161,   -57,   162,    62,
     163,   126,    92,   164,    94,   165,   139,   166,    99,    25,
     101,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   186,   127,   128,   129,    96,   159,
      70,   124,    58,    71,    49,   123,   182,   141,   167,   -57,
     168,    61,    61,   -32,   160,   131,    50,   161,    97,   162,
      93,   163,    98,   190,   164,   204,   165,   195,   166,   198,
     158,   107,   201,   189,   156,   100,   192,   193,    59,   121,
      62,    62,   196,   220,   197,   104,   105,   221,   222,    73,
      74,    75,    76,    77,    78,    79,   125,   131,    60,   167,
      72,   168,   130,    63,    67,   133,   187,   140,   212,   238,
     215,    82,   218,   157,     8,   219,   183,     9,   184,   244,
     245,   185,   188,   191,   223,    72,    -7,    -7,    -7,    73,
      74,    75,    76,    77,    78,    79,   194,   205,   199,   200,
     202,   206,   218,   207,    80,   239,   208,   240,    81,    72,
       8,    82,   135,     9,    73,    74,    75,    76,    77,    78,
      79,   209,    -7,    -7,    -7,   210,    -7,   211,   224,    80,
     216,   225,   226,    81,   229,   227,    82,   213,    73,    74,
      75,    76,    77,    78,    79,   228,   241,   231,   230,   232,
     234,   233,   235,    80,   242,    37,   237,    81,   243,    54,
      82,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    38,   119,   120,     0,    39,    40,    41,    42,
      43,    44,    45,    46,   236
};

static const yytype_int16 yycheck[] =
{
      11,     1,     1,     1,     1,    25,    37,    50,    55,    56,
       1,     1,    59,   184,     1,     1,     3,    99,     4,   101,
       1,     1,    52,     0,    54,   196,    57,     1,     1,     1,
      30,    17,    30,    30,    13,    82,    14,    15,    52,    30,
      30,    54,   124,    16,    17,    18,    19,    20,    21,    30,
      23,    94,    57,    26,    56,    28,   103,    30,    69,    58,
      71,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   156,    95,    96,    97,    58,     1,
      54,    92,     1,    57,    52,    57,   133,   107,    61,    62,
      63,     1,     1,    52,    16,    17,    52,    19,    58,    21,
      53,    23,    53,   161,    26,   187,    28,    37,    30,   167,
     130,    55,   170,   160,   125,    30,   163,   164,    37,    57,
      30,    30,    52,   205,    54,    80,    81,   209,   210,    30,
      31,    32,    33,    34,    35,    36,    57,    17,    57,    61,
       1,    63,    58,    53,    53,    58,   157,    53,   195,   231,
     197,    52,   199,    57,     1,   202,    53,     4,    56,   241,
     242,    55,    57,    30,   211,     1,    13,    14,    15,    30,
      31,    32,    33,    34,    35,    36,    30,   188,    52,    18,
      59,    57,   229,    20,    45,   232,    57,   234,    49,     1,
       1,    52,    53,     4,    30,    31,    32,    33,    34,    35,
      36,    24,    13,    14,    15,    27,    17,    37,    57,    45,
      62,    57,    53,    49,    56,    55,    52,    53,    30,    31,
      32,    33,    34,    35,    36,    53,   237,    25,    55,    29,
      37,    57,    57,    45,    27,    20,    57,    49,    57,    34,
      52,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     1,    50,    51,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,   229
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    66,     1,    30,    67,     0,     1,     4,
      68,    69,     1,    30,    70,    71,    72,    14,    15,    73,
      74,    75,    77,    68,     1,    58,     1,    30,    76,     1,
      30,    78,    13,    82,    83,    84,    85,    73,     1,     5,
       6,     7,     8,     9,    10,    11,    12,    87,    87,    52,
      52,     1,    30,    86,    82,    54,    37,    57,     1,    37,
      57,     1,    30,    53,    79,    80,    81,    53,    79,     1,
      54,    57,     1,    30,    31,    32,    33,    34,    35,    36,
      45,    49,    52,   102,   105,   106,   107,   108,   109,   110,
     105,   105,    57,    53,    56,     1,    58,    58,    53,    68,
      30,    68,    52,    54,   108,   108,   105,    55,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    50,
      51,    57,     1,    57,    68,    57,    79,    87,    87,    87,
      58,    17,    90,    58,    90,    53,   103,   104,   105,   105,
      53,    87,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,    90,    68,    57,    87,     1,
      16,    19,    21,    23,    26,    28,    30,    61,    63,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   101,   105,    53,    56,    55,    90,    68,    57,   105,
      88,    30,   105,   105,    30,    37,    52,    54,    88,    52,
      18,    88,    59,   103,    90,    68,    57,    20,    57,    24,
      27,    37,   105,    53,   103,   105,    62,   100,   105,   105,
      90,    90,    90,   105,    57,    57,    53,    55,    53,    56,
      55,    25,    29,    57,    37,    57,   100,    57,    90,   105,
     105,    68,    27,    57,    90,    90
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      69,    70,    70,    70,    71,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    75,    76,    76,    77,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    86,    86,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    91,    92,    92,    93,    94,    95,    95,    96,
      97,    98,    99,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   105,   105,   105,   105,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   107,
     107,   108,   108,   108,   108,   109,   109,   109,   109,   109,
     109,   110,   110
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     1,     1,     1,     2,     0,     2,     2,
       1,     6,     6,     6,     4,     4,     4,     1,     1,     2,
       0,     1,     1,     8,     7,     2,     1,     1,    10,     9,
       2,     1,     1,     3,     1,     3,     3,     1,     1,     1,
       2,     1,     1,     5,     5,    12,     1,     1,     1,     1,
       1,     1,     1,     5,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     7,     4,     8,     4,     6,     3,
       3,     3,     5,     3,     1,     5,     4,     4,     3,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     4
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
#line 195 "src/parser/parser.y"
                                                                          {
        // -- Obtener identificador de programa
        char * identifier = (yyvsp[-3].ident);

        // -- Crear AST
        AST_program = create_program(identifier,(yyvsp[-2].decl),(yyvsp[-1].subprog),(yyvsp[0].proc));

        // -- Liberar memoria asociada para el identificador
        free(identifier);
    }
#line 1382 "src/parser/parser.c"
    break;

  case 3: /* program: error  */
#line 205 "src/parser/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROGRAM_PROGRAM);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1394 "src/parser/parser.c"
    break;

  case 4: /* program-name: IDENT  */
#line 215 "src/parser/parser.y"
         { 
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1402 "src/parser/parser.c"
    break;

  case 5: /* program-name: error  */
#line 219 "src/parser/parser.y"
            { 
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROGRAM_IDENT);

        // -- Abortar inmediatamente el analisis
        YYABORT; 
    }
#line 1414 "src/parser/parser.c"
    break;

  case 6: /* list-declarations: declaration list-declarations  */
#line 230 "src/parser/parser.y"
                                 {
        (yyval.decl) = (yyvsp[-1].decl);
        (yyvsp[-1].decl)->next = (yyvsp[0].decl);
    }
#line 1423 "src/parser/parser.c"
    break;

  case 7: /* list-declarations: %empty  */
#line 234 "src/parser/parser.y"
                   {
        (yyval.decl) = 0;
    }
#line 1431 "src/parser/parser.c"
    break;

  case 8: /* declaration: S_VAR declaration-var-with-assignment  */
#line 240 "src/parser/parser.y"
                                         {
        (yyval.decl) = (yyvsp[0].decl);
    }
#line 1439 "src/parser/parser.c"
    break;

  case 9: /* declaration: S_VAR declaration-var  */
#line 243 "src/parser/parser.y"
                           {
        (yyval.decl) = (yyvsp[0].decl);
    }
#line 1447 "src/parser/parser.c"
    break;

  case 10: /* declaration: error  */
#line 247 "src/parser/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARARTION_VAR);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1459 "src/parser/parser.c"
    break;

  case 11: /* declaration-var-with-assignment: declaration-name DELIM_2P type OP_ASSIGN expression DELIM_PC  */
#line 257 "src/parser/parser.y"
                                                                {
        // -- Obtener identificador de variable
        char * identifier = (yyvsp[-5].ident);

        // -- Crear nodo DECLARACION
        (yyval.decl) = create_declaration_variable(identifier, (yyvsp[-3].type), (yyvsp[-1].expr), yylineno);

        // -- Liberar la memoria para el identificador
        free(identifier);
    }
#line 1474 "src/parser/parser.c"
    break;

  case 12: /* declaration-var-with-assignment: declaration-name error type OP_ASSIGN expression DELIM_PC  */
#line 268 "src/parser/parser.y"
                                                               {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_DELIM2P);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1486 "src/parser/parser.c"
    break;

  case 13: /* declaration-var-with-assignment: declaration-name DELIM_2P type OP_ASSIGN expression error  */
#line 276 "src/parser/parser.y"
                                                               {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_DELIMPC);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1498 "src/parser/parser.c"
    break;

  case 14: /* declaration-var: declaration-name DELIM_2P type DELIM_PC  */
#line 286 "src/parser/parser.y"
                                           {
        // -- Obtener identificador de variable
        char * identifier = (yyvsp[-3].ident);

        // -- Crear nodo DECLARACION
        (yyval.decl) = create_declaration_variable(identifier, (yyvsp[-1].type), 0, yylineno);

        // -- Liberar la memoria para el identificador
        free(identifier);
    }
#line 1513 "src/parser/parser.c"
    break;

  case 15: /* declaration-var: declaration-name error type DELIM_PC  */
#line 297 "src/parser/parser.y"
                                          {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_DELIM2P);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1525 "src/parser/parser.c"
    break;

  case 16: /* declaration-var: declaration-name DELIM_2P type error  */
#line 305 "src/parser/parser.y"
                                          {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_DELIMPC);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1537 "src/parser/parser.c"
    break;

  case 17: /* declaration-name: IDENT  */
#line 315 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1545 "src/parser/parser.c"
    break;

  case 18: /* declaration-name: error  */
#line 319 "src/parser/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1557 "src/parser/parser.c"
    break;

  case 19: /* list-subprograms: subprogram list-subprograms  */
#line 330 "src/parser/parser.y"
                               {
        (yyval.subprog) = (yyvsp[-1].subprog);
        (yyvsp[-1].subprog)->next = (yyvsp[0].subprog);
    }
#line 1566 "src/parser/parser.c"
    break;

  case 20: /* list-subprograms: %empty  */
#line 334 "src/parser/parser.y"
                   {
        (yyval.subprog) = 0;
    }
#line 1574 "src/parser/parser.c"
    break;

  case 21: /* subprogram: subprogram-procedure  */
#line 340 "src/parser/parser.y"
                        {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1582 "src/parser/parser.c"
    break;

  case 22: /* subprogram: subprogram-function  */
#line 343 "src/parser/parser.y"
                         {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1590 "src/parser/parser.c"
    break;

  case 23: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO DELIM_PC list-declarations block-statement  */
#line 350 "src/parser/parser.y"
                                                                                                                      {
        // -- Obtener identificador de subprograma
        char * identifier = (yyvsp[-6].ident);

        // -- Creacion nodo SUBPROGRAMA (PROCEDURE)
        (yyval.subprog) = create_subprogram_procedure(identifier, (yyvsp[-4].param), (yyvsp[-1].decl), (yyvsp[0].stmt), yylineno);

        // -- Liberacion de memoria para identificador
        free(identifier);
    }
#line 1605 "src/parser/parser.c"
    break;

  case 24: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO DELIM_PC list-declarations block-statement  */
#line 361 "src/parser/parser.y"
                                                                                                        {
        // -- Obtener identificador de subprograma
        char * identifier = (yyvsp[-5].ident);

        // -- Creacion nodo SUBPROGRAMA (PROCEDURE)
        (yyval.subprog) = create_subprogram_procedure(identifier, 0, (yyvsp[-1].decl), (yyvsp[0].stmt), yylineno);

        // -- Liberacion de memoria para identificador
        free(identifier);
    }
#line 1620 "src/parser/parser.c"
    break;

  case 25: /* subprogram-procedure: S_PROCEDURE error  */
#line 372 "src/parser/parser.y"
                       {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_PROCEDURE_MALFORMED);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1632 "src/parser/parser.c"
    break;

  case 26: /* subprogram-procedure-name: IDENT  */
#line 382 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1640 "src/parser/parser.c"
    break;

  case 27: /* subprogram-procedure-name: error  */
#line 386 "src/parser/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_PROCEDURE_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1652 "src/parser/parser.c"
    break;

  case 28: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P type DELIM_PC list-declarations block-statement  */
#line 397 "src/parser/parser.y"
                                                                                                                                  {
        // -- Obtener identificador de subprograma
        char * identifier = (yyvsp[-8].ident);
        
        // -- Creacion de nodo SUBPROGRAMA (FUNCTION)
        (yyval.subprog) = create_subprogram_function(identifier, (yyvsp[-6].param), (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-3].type), yylineno);

        // -- Liberacion de memoria para identificador
        free(identifier);
    }
#line 1667 "src/parser/parser.c"
    break;

  case 29: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P type DELIM_PC list-declarations block-statement  */
#line 408 "src/parser/parser.y"
                                                                                                                    {
        // -- Obtener identificador de subprograma
        char * identifier = (yyvsp[-7].ident);
        
        // -- Creacion de nodo SUBPROGRAMA (FUNCTION)
        (yyval.subprog) = create_subprogram_function(identifier, 0, (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-3].type), yylineno);

        // -- Liberacion de memoria para identificador
        free(identifier);
    }
#line 1682 "src/parser/parser.c"
    break;

  case 30: /* subprogram-function: S_FUNCTION error  */
#line 419 "src/parser/parser.y"
                      {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_FUNCTION_MALFORMED);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1694 "src/parser/parser.c"
    break;

  case 31: /* subprogram-function-name: IDENT  */
#line 429 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1702 "src/parser/parser.c"
    break;

  case 32: /* subprogram-function-name: error  */
#line 433 "src/parser/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_FUNCTION_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1714 "src/parser/parser.c"
    break;

  case 33: /* list-parameters: parameter DELIM_C list-parameters  */
#line 443 "src/parser/parser.y"
                                     {
        (yyval.param) = (yyvsp[-2].param);
        (yyvsp[-2].param)->next = (yyvsp[0].param);
    }
#line 1723 "src/parser/parser.c"
    break;

  case 34: /* list-parameters: parameter  */
#line 447 "src/parser/parser.y"
               {
        (yyval.param) = (yyvsp[0].param);
    }
#line 1731 "src/parser/parser.c"
    break;

  case 35: /* parameter: parameter-name DELIM_2P type  */
#line 453 "src/parser/parser.y"
                                {
        // -- Obtener identificador de parametro
        char * identifier = (yyvsp[-2].ident);

        // -- Creacion de nodo PARAMETRO
        (yyval.param) = create_parameter(identifier, (yyvsp[0].type), yylineno);

        // -- Liberar memoria para identificador
        free(identifier);
    }
#line 1746 "src/parser/parser.c"
    break;

  case 36: /* parameter: parameter-name error type  */
#line 464 "src/parser/parser.y"
                               {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_PARAMETER_DELIM2P);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1758 "src/parser/parser.c"
    break;

  case 37: /* parameter-name: IDENT  */
#line 474 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1766 "src/parser/parser.c"
    break;

  case 38: /* parameter-name: error  */
#line 478 "src/parser/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_PARAMETER_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1778 "src/parser/parser.c"
    break;

  case 39: /* list-process: process  */
#line 489 "src/parser/parser.y"
           {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 1786 "src/parser/parser.c"
    break;

  case 40: /* list-process: process list-process  */
#line 492 "src/parser/parser.y"
                          {
        (yyval.proc) = (yyvsp[-1].proc);
        (yyvsp[-1].proc)->next = (yyvsp[0].proc);
    }
#line 1795 "src/parser/parser.c"
    break;

  case 41: /* process: process-def  */
#line 499 "src/parser/parser.y"
               {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 1803 "src/parser/parser.c"
    break;

  case 42: /* process: process-def-array  */
#line 502 "src/parser/parser.y"
                       {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 1811 "src/parser/parser.c"
    break;

  case 43: /* process-def: S_PROCESS process-name DELIM_PC list-declarations block-statement  */
#line 509 "src/parser/parser.y"
                                                                     {
        // -- Obtener identificador de proceso
        char * identifier = (yyvsp[-3].ident);

        // -- Creacion de nodo PROCESO
        (yyval.proc) = create_process_single(identifier, (yyvsp[-1].decl), (yyvsp[0].stmt), yylineno);

        // -- Liberar la memoria para identificador
        free(identifier);
    }
#line 1826 "src/parser/parser.c"
    break;

  case 44: /* process-def: S_PROCESS process-name error list-declarations block-statement  */
#line 520 "src/parser/parser.y"
                                                                    {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROCESS_DELIMPC);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1838 "src/parser/parser.c"
    break;

  case 45: /* process-def-array: S_PROCESS process-name CORCH_IZDO IDENT DELIM_2P expression DELIM_ARR expression CORCH_DCHO DELIM_PC list-declarations block-statement  */
#line 531 "src/parser/parser.y"
                                                                                                                                          {
        // -- Obtener identificador de proceso
        char * identifier = (yyvsp[-10].ident);
        
        // -- Creacion de nodo PROCESO
        (yyval.proc) = create_process_vector(identifier, (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-8].ident), (yyvsp[-6].expr), (yyvsp[-4].expr), yylineno);

        // -- Liberar la memoria para identificador
        free(identifier);
    }
#line 1853 "src/parser/parser.c"
    break;

  case 46: /* process-name: IDENT  */
#line 544 "src/parser/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1861 "src/parser/parser.c"
    break;

  case 47: /* process-name: error  */
#line 548 "src/parser/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROCESS_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1873 "src/parser/parser.c"
    break;

  case 48: /* type: T_INTEGER  */
#line 560 "src/parser/parser.y"
             {
        (yyval.type) = create_basic_type(TYPE_INTEGER);
    }
#line 1881 "src/parser/parser.c"
    break;

  case 49: /* type: T_BOOLEAN  */
#line 563 "src/parser/parser.y"
               {
        (yyval.type) = create_basic_type(TYPE_BOOLEAN);
    }
#line 1889 "src/parser/parser.c"
    break;

  case 50: /* type: T_CHAR  */
#line 566 "src/parser/parser.y"
            {
        (yyval.type) = create_basic_type(TYPE_CHAR);
    }
#line 1897 "src/parser/parser.c"
    break;

  case 51: /* type: T_STRING  */
#line 569 "src/parser/parser.y"
              {
        (yyval.type) = create_basic_type(TYPE_STRING);
    }
#line 1905 "src/parser/parser.c"
    break;

  case 52: /* type: T_REAL  */
#line 572 "src/parser/parser.y"
            {
        (yyval.type) = create_basic_type(TYPE_REAL);
    }
#line 1913 "src/parser/parser.c"
    break;

  case 53: /* type: T_ARRAY CORCH_IZDO expression CORCH_DCHO type  */
#line 575 "src/parser/parser.y"
                                                   {
        (yyval.type) = create_array_type((yyvsp[0].type),(yyvsp[-2].expr));
    }
#line 1921 "src/parser/parser.c"
    break;

  case 54: /* type: T_SEMAPHORE  */
#line 578 "src/parser/parser.y"
                 {
        (yyval.type) = create_semaphore_type();
    }
#line 1929 "src/parser/parser.c"
    break;

  case 55: /* type: T_DPROCESS  */
#line 581 "src/parser/parser.y"
                {
        (yyval.type) = create_dprocess_type();
    }
#line 1937 "src/parser/parser.c"
    break;

  case 56: /* type: error  */
#line 585 "src/parser/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_TYPE);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1949 "src/parser/parser.c"
    break;

  case 57: /* list-statements: statement  */
#line 596 "src/parser/parser.y"
             {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1957 "src/parser/parser.c"
    break;

  case 58: /* list-statements: statement list-statements  */
#line 599 "src/parser/parser.y"
                               {
        (yyval.stmt) = (yyvsp[-1].stmt);
        (yyvsp[-1].stmt)->next = (yyvsp[0].stmt);
    }
#line 1966 "src/parser/parser.c"
    break;

  case 59: /* statement: block-statement  */
#line 606 "src/parser/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1974 "src/parser/parser.c"
    break;

  case 60: /* statement: cobegin-statement  */
#line 609 "src/parser/parser.y"
                       {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1982 "src/parser/parser.c"
    break;

  case 61: /* statement: assignment-statement  */
#line 612 "src/parser/parser.y"
                          {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1990 "src/parser/parser.c"
    break;

  case 62: /* statement: while-statement  */
#line 615 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1998 "src/parser/parser.c"
    break;

  case 63: /* statement: for-statement  */
#line 618 "src/parser/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2006 "src/parser/parser.c"
    break;

  case 64: /* statement: if-statement  */
#line 621 "src/parser/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2014 "src/parser/parser.c"
    break;

  case 65: /* statement: procedure-invocation  */
#line 624 "src/parser/parser.y"
                          {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2022 "src/parser/parser.c"
    break;

  case 66: /* statement: fork-statement  */
#line 627 "src/parser/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2030 "src/parser/parser.c"
    break;

  case 67: /* statement: atomic-statement  */
#line 630 "src/parser/parser.y"
                      {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2038 "src/parser/parser.c"
    break;

  case 68: /* statement: return-statement  */
#line 633 "src/parser/parser.y"
                      {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2046 "src/parser/parser.c"
    break;

  case 69: /* statement: print-statement  */
#line 636 "src/parser/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 2054 "src/parser/parser.c"
    break;

  case 70: /* statement: error  */
#line 639 "src/parser/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_STMT_MALFORMED);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 2066 "src/parser/parser.c"
    break;

  case 71: /* block-statement: B_BEGIN list-statements B_END  */
#line 649 "src/parser/parser.y"
                                 {
        (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
    }
#line 2074 "src/parser/parser.c"
    break;

  case 72: /* cobegin-statement: B_COBEGIN list-statements B_COEND  */
#line 655 "src/parser/parser.y"
                                     {
        (yyval.stmt) = create_statement_block_cobegin((yyvsp[-1].stmt));
    }
#line 2082 "src/parser/parser.c"
    break;

  case 73: /* assignment-statement: IDENT OP_ASSIGN expression DELIM_PC  */
#line 662 "src/parser/parser.y"
                                       {
        // -- Obtener identificador de variable
        char * identifier = (yyvsp[-3].ident);

        // -- Creacion de nodo STATEMENT (ASSIGNMENT)
        (yyval.stmt) = create_statement_assignment(identifier, 0, (yyvsp[-1].expr), yylineno);

        // -- Liberar la memoria para identificador
        free(identifier);
    }
#line 2097 "src/parser/parser.c"
    break;

  case 74: /* assignment-statement: IDENT CORCH_IZDO expression CORCH_DCHO OP_ASSIGN expression DELIM_PC  */
#line 673 "src/parser/parser.y"
                                                                          {
        // -- Obtener identificador de variable
        char * identifier = (yyvsp[-6].ident);

        // -- Creacion de nodo STATEMENT (ASSIGNMENT)
        (yyval.stmt) = create_statement_assignment(identifier, (yyvsp[-4].expr), (yyvsp[-1].expr), yylineno);

        // -- Liberar la memoria para identificador
        free(identifier);
    }
#line 2112 "src/parser/parser.c"
    break;

  case 75: /* while-statement: WHILE expression DO block-statement  */
#line 686 "src/parser/parser.y"
                                       {
        (yyval.stmt) = create_statement_while((yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 2120 "src/parser/parser.c"
    break;

  case 76: /* for-statement: FOR IDENT OP_ASSIGN expression TO expression DO block-statement  */
#line 692 "src/parser/parser.y"
                                                                   {
        // -- Obtener identificador de variable
        char * identifier = (yyvsp[-6].ident);

        // -- Creacion de nodo STATEMENT (ASSIGNMENT)
        (yyval.stmt) = create_statement_for(identifier, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), yylineno);

        // -- Liberar la memoria para identificador
        free(identifier);
    }
#line 2135 "src/parser/parser.c"
    break;

  case 77: /* if-statement: IF expression THEN block-statement  */
#line 705 "src/parser/parser.y"
                                      {
        (yyval.stmt) = create_statement_if_else((yyvsp[-2].expr), (yyvsp[0].stmt), 0);
    }
#line 2143 "src/parser/parser.c"
    break;

  case 78: /* if-statement: IF expression THEN block-statement ELSE block-statement  */
#line 708 "src/parser/parser.y"
                                                             {
        (yyval.stmt) = create_statement_if_else((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt));
    }
#line 2151 "src/parser/parser.c"
    break;

  case 79: /* fork-statement: S_FORK IDENT DELIM_PC  */
#line 714 "src/parser/parser.y"
                         {
        // -- Obtener identificador de proceso
        char * identifier = (yyvsp[-1].ident);

        // -- Creacion de nodo STATEMENT (FORK)
        (yyval.stmt) = create_statement_fork(identifier, yylineno);

        // -- Liberar la memoria para identificador
        free(identifier);
    }
#line 2166 "src/parser/parser.c"
    break;

  case 80: /* atomic-statement: ATOM_INI list-statements ATOM_FIN  */
#line 727 "src/parser/parser.y"
                                     {
        (yyval.stmt) = create_statement_atomic((yyvsp[-1].stmt));
    }
#line 2174 "src/parser/parser.c"
    break;

  case 81: /* return-statement: RETURN expression DELIM_PC  */
#line 733 "src/parser/parser.y"
                              {
        (yyval.stmt) = create_statement_return((yyvsp[-1].expr));
    }
#line 2182 "src/parser/parser.c"
    break;

  case 82: /* print-statement: PRINT PAR_IZDO list-print PAR_DCHO DELIM_PC  */
#line 739 "src/parser/parser.y"
                                               {
        (yyval.stmt) = create_statement_print((yyvsp[-2].expr));
    }
#line 2190 "src/parser/parser.c"
    break;

  case 83: /* list-print: expression DELIM_C list-print  */
#line 745 "src/parser/parser.y"
                                 {
        (yyval.expr) = (yyvsp[-2].expr);
        (yyvsp[-2].expr)->next = (yyvsp[0].expr);
    }
#line 2199 "src/parser/parser.c"
    break;

  case 84: /* list-print: expression  */
#line 749 "src/parser/parser.y"
                {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2207 "src/parser/parser.c"
    break;

  case 85: /* procedure-invocation: IDENT PAR_IZDO list-arguments PAR_DCHO DELIM_PC  */
#line 756 "src/parser/parser.y"
                                                   {
        // -- Obtener identificador de procedimiento
        char * identifier = (yyvsp[-4].ident);

        // -- Creacion de nodo STATEMENT (PROCEDURE INVOCATION)
        (yyval.stmt) = create_statement_procedure_inv(identifier, (yyvsp[-2].expr), yylineno);

        // -- Liberar memoria para el identificador
        free(identifier);
    }
#line 2222 "src/parser/parser.c"
    break;

  case 86: /* procedure-invocation: IDENT PAR_IZDO PAR_DCHO DELIM_PC  */
#line 766 "src/parser/parser.y"
                                      {
        // -- Obtener identificador de procedimiento
        char * identifier = (yyvsp[-3].ident);

        // -- Creacion de nodo STATEMENT (PROCEDURE INVOCATION)
        (yyval.stmt) = create_statement_procedure_inv(identifier, 0, yylineno);

        // -- Liberar memoria para el identificador
        free(identifier);
    }
#line 2237 "src/parser/parser.c"
    break;

  case 87: /* function-invocation: IDENT PAR_IZDO list-arguments PAR_DCHO  */
#line 779 "src/parser/parser.y"
                                          {
        // -- Obtener identificador de funcion
        char * identifier = (yyvsp[-3].ident);

        // -- Creacion de nodo EXPRESSION
        (yyval.expr) = create_expression_function_invocation(identifier, (yyvsp[-1].expr), yylineno);

        // -- Liberar memoria para el identificador
        free(identifier);
    }
#line 2252 "src/parser/parser.c"
    break;

  case 88: /* function-invocation: IDENT PAR_IZDO PAR_DCHO  */
#line 789 "src/parser/parser.y"
                             {
        // -- Obtener identificador de funcion
        char * identifier = (yyvsp[-2].ident);

        // -- Creacion de nodo EXPRESSION
        (yyval.expr) = create_expression_function_invocation(identifier, 0, yylineno);

        // -- Liberar memoria para el identificador
        free(identifier);
    }
#line 2267 "src/parser/parser.c"
    break;

  case 89: /* list-arguments: argument DELIM_C list-arguments  */
#line 802 "src/parser/parser.y"
                                   {
        (yyval.expr) = (yyvsp[-2].expr);
        (yyvsp[-2].expr)->next = (yyvsp[0].expr);
    }
#line 2276 "src/parser/parser.c"
    break;

  case 90: /* list-arguments: argument  */
#line 806 "src/parser/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2284 "src/parser/parser.c"
    break;

  case 91: /* argument: expression  */
#line 812 "src/parser/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2292 "src/parser/parser.c"
    break;

  case 92: /* expression: binary-expression  */
#line 819 "src/parser/parser.y"
                     {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2300 "src/parser/parser.c"
    break;

  case 93: /* expression: unary-expression  */
#line 822 "src/parser/parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2308 "src/parser/parser.c"
    break;

  case 94: /* expression: term  */
#line 825 "src/parser/parser.y"
          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2316 "src/parser/parser.c"
    break;

  case 95: /* expression: error  */
#line 828 "src/parser/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_EXPR_MALFORMED);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 2328 "src/parser/parser.c"
    break;

  case 96: /* binary-expression: term OP_SUM expression  */
#line 839 "src/parser/parser.y"
                          {
        (yyval.expr) = create_expression_binary_operation(EXPR_ADD, "+", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2336 "src/parser/parser.c"
    break;

  case 97: /* binary-expression: term OP_MINUS expression  */
#line 843 "src/parser/parser.y"
                              {
        (yyval.expr) = create_expression_binary_operation(EXPR_SUB, "-", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2344 "src/parser/parser.c"
    break;

  case 98: /* binary-expression: term OP_MULT expression  */
#line 847 "src/parser/parser.y"
                             {
        (yyval.expr) = create_expression_binary_operation(EXPR_MULT, "*", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2352 "src/parser/parser.c"
    break;

  case 99: /* binary-expression: term OP_DIV expression  */
#line 851 "src/parser/parser.y"
                            {
        (yyval.expr) = create_expression_binary_operation(EXPR_DIV, "/", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2360 "src/parser/parser.c"
    break;

  case 100: /* binary-expression: term OP_MOD expression  */
#line 855 "src/parser/parser.y"
                            {
        (yyval.expr) = create_expression_binary_operation(EXPR_MOD, "%", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2368 "src/parser/parser.c"
    break;

  case 101: /* binary-expression: term OP_REL_LT expression  */
#line 859 "src/parser/parser.y"
                               {
        (yyval.expr) = create_expression_binary_operation(EXPR_LT, "<", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2376 "src/parser/parser.c"
    break;

  case 102: /* binary-expression: term OP_REL_LTE expression  */
#line 863 "src/parser/parser.y"
                                {
        (yyval.expr) = create_expression_binary_operation(EXPR_LTE, "<=", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2384 "src/parser/parser.c"
    break;

  case 103: /* binary-expression: term OP_REL_GT expression  */
#line 867 "src/parser/parser.y"
                               {
        (yyval.expr) = create_expression_binary_operation(EXPR_GT, ">", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2392 "src/parser/parser.c"
    break;

  case 104: /* binary-expression: term OP_REL_GTE expression  */
#line 871 "src/parser/parser.y"
                                {
        (yyval.expr) = create_expression_binary_operation(EXPR_GTE, ">=", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2400 "src/parser/parser.c"
    break;

  case 105: /* binary-expression: term OP_REL_EQ expression  */
#line 875 "src/parser/parser.y"
                               {
        (yyval.expr) = create_expression_binary_operation(EXPR_EQ, "==", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2408 "src/parser/parser.c"
    break;

  case 106: /* binary-expression: term OP_REL_NEQ expression  */
#line 879 "src/parser/parser.y"
                                {
        (yyval.expr) = create_expression_binary_operation(EXPR_NEQ, "!=", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2416 "src/parser/parser.c"
    break;

  case 107: /* binary-expression: term OP_AND expression  */
#line 883 "src/parser/parser.y"
                            {
        (yyval.expr) = create_expression_binary_operation(EXPR_AND, "and", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2424 "src/parser/parser.c"
    break;

  case 108: /* binary-expression: term OP_OR expression  */
#line 887 "src/parser/parser.y"
                           {
        (yyval.expr) = create_expression_binary_operation(EXPR_OR, "or", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2432 "src/parser/parser.c"
    break;

  case 109: /* unary-expression: OP_NOT term  */
#line 894 "src/parser/parser.y"
               {
        (yyval.expr) = create_expression_unary_operation(EXPR_NOT, "not", (yyvsp[0].expr));
    }
#line 2440 "src/parser/parser.c"
    break;

  case 110: /* unary-expression: OP_MINUS term  */
#line 898 "src/parser/parser.y"
                   {
        (yyval.expr) = create_expression_unary_operation(EXPR_NEGATIVE, "-", (yyvsp[0].expr));
    }
#line 2448 "src/parser/parser.c"
    break;

  case 111: /* term: expr-identifier  */
#line 904 "src/parser/parser.y"
                   {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2456 "src/parser/parser.c"
    break;

  case 112: /* term: literal  */
#line 907 "src/parser/parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2464 "src/parser/parser.c"
    break;

  case 113: /* term: function-invocation  */
#line 910 "src/parser/parser.y"
                         {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2472 "src/parser/parser.c"
    break;

  case 114: /* term: PAR_IZDO expression PAR_DCHO  */
#line 913 "src/parser/parser.y"
                                  {
        (yyval.expr) = create_expression_grouped((yyvsp[-1].expr));
    }
#line 2480 "src/parser/parser.c"
    break;

  case 115: /* literal: LITERAL  */
#line 920 "src/parser/parser.y"
           {
        // -- Obtener literal
        char * literal_string = (yyvsp[0].literal_string);
        // -- Crear expresion literal
        (yyval.expr) = create_expression_literal_string(literal_string);
        // -- Liberar memoria para el literal
        free(literal_string);
    }
#line 2493 "src/parser/parser.c"
    break;

  case 116: /* literal: L_INTEGER  */
#line 928 "src/parser/parser.y"
               {
        (yyval.expr) = create_expression_literal_integer((yyvsp[0].literal_int));
    }
#line 2501 "src/parser/parser.c"
    break;

  case 117: /* literal: L_BOOLEAN_TRUE  */
#line 931 "src/parser/parser.y"
                    {
        (yyval.expr) = create_expression_literal_boolean(1);
    }
#line 2509 "src/parser/parser.c"
    break;

  case 118: /* literal: L_BOOLEAN_FALSE  */
#line 934 "src/parser/parser.y"
                     {
        (yyval.expr) = create_expression_literal_boolean(0);
    }
#line 2517 "src/parser/parser.c"
    break;

  case 119: /* literal: L_CHAR  */
#line 937 "src/parser/parser.y"
            {
        (yyval.expr) = create_expression_literal_char((yyvsp[0].literal_char));
    }
#line 2525 "src/parser/parser.c"
    break;

  case 120: /* literal: L_REAL  */
#line 940 "src/parser/parser.y"
            {
        (yyval.expr) = create_expression_literal_real((yyvsp[0].literal_float));
    }
#line 2533 "src/parser/parser.c"
    break;

  case 121: /* expr-identifier: IDENT  */
#line 946 "src/parser/parser.y"
         {
        // -- Obtener identificador
        char * identifier = (yyvsp[0].ident); 
        // -- Crear expresion
        (yyval.expr) = create_expression_identifier(identifier,0, yylineno);
        // -- Liberar memoria para el identificador
        free(identifier);
    }
#line 2546 "src/parser/parser.c"
    break;

  case 122: /* expr-identifier: IDENT CORCH_IZDO expression CORCH_DCHO  */
#line 954 "src/parser/parser.y"
                                            {
        // -- Obtener identificador
        char * identifier = (yyvsp[-3].ident);
        // -- Crear expresion
        (yyval.expr) = create_expression_identifier(identifier, (yyvsp[-1].expr), yylineno);
        // -- Liberar memoria para el identificador
        free(identifier);
    }
#line 2559 "src/parser/parser.c"
    break;


#line 2563 "src/parser/parser.c"

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

#line 964 "src/parser/parser.y"


// Soporte de las rutinas en C


void yyerror(const char *s) {
    if(strcmp(s, "syntax error") != 0)
        fprintf(stderr, "--- Error de sintaxis en la línea %d -> %s\n", yylineno, s);
}
