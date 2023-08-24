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
#line 10 "src/parser.y"

    //Inclusion de cabeceras
    #include <stdio.h>

    //Inclusion de AST
    #include "AST.h"

    //Definir directiva para testeo
    #define VERBOSE

    //Definir prototipos de funciones
    extern int yylex();  
    extern FILE *yyin;

    void yyerror(const char* s);  

#line 88 "parser.tab.c"

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

#include "parser.tab.h"
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
  YYSYMBOL_UNRECOGNIZED_TOKEN = 63,        /* UNRECOGNIZED_TOKEN  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_program = 65,                   /* program  */
  YYSYMBOL_66_list_declarations = 66,      /* list-declarations  */
  YYSYMBOL_declaration = 67,               /* declaration  */
  YYSYMBOL_68_list_subprograms = 68,       /* list-subprograms  */
  YYSYMBOL_subprogram = 69,                /* subprogram  */
  YYSYMBOL_70_list_parameters = 70,        /* list-parameters  */
  YYSYMBOL_parameter = 71,                 /* parameter  */
  YYSYMBOL_72_list_process = 72,           /* list-process  */
  YYSYMBOL_process = 73,                   /* process  */
  YYSYMBOL_type = 74,                      /* type  */
  YYSYMBOL_75_list_statements = 75,        /* list-statements  */
  YYSYMBOL_statement = 76,                 /* statement  */
  YYSYMBOL_77_block_statement = 77,        /* block-statement  */
  YYSYMBOL_78_cobegin_statement = 78,      /* cobegin-statement  */
  YYSYMBOL_79_assignment_statement = 79,   /* assignment-statement  */
  YYSYMBOL_80_while_statement = 80,        /* while-statement  */
  YYSYMBOL_81_for_statement = 81,          /* for-statement  */
  YYSYMBOL_82_if_statement = 82,           /* if-statement  */
  YYSYMBOL_83_fork_statement = 83,         /* fork-statement  */
  YYSYMBOL_84_atomic_statement = 84,       /* atomic-statement  */
  YYSYMBOL_85_return_statement = 85,       /* return-statement  */
  YYSYMBOL_86_procedure_invocation = 86,   /* procedure-invocation  */
  YYSYMBOL_87_function_invocation = 87,    /* function-invocation  */
  YYSYMBOL_expression = 88,                /* expression  */
  YYSYMBOL_89_binary_expression = 89,      /* binary-expression  */
  YYSYMBOL_90_unary_expression = 90,       /* unary-expression  */
  YYSYMBOL_term = 91,                      /* term  */
  YYSYMBOL_literal = 92,                   /* literal  */
  YYSYMBOL_identifier = 93                 /* identifier  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,     2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   143,   143,   150,   154,   160,   163,   170,   174,   181,
     185,   191,   195,   198,   204,   211,   214,   222,   231,   234,
     237,   240,   243,   246,   249,   252,   259,   262,   269,   272,
     275,   278,   281,   284,   287,   290,   293,   296,   302,   308,
     315,   323,   329,   335,   338,   344,   350,   356,   363,   369,
     376,   379,   382,   389,   393,   397,   401,   405,   409,   413,
     417,   421,   425,   429,   433,   437,   444,   448,   454,   457,
     460,   463,   470,   473,   476,   479,   482,   485,   491
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
  "DELIM_ARR", "DELIM_P", "ATOM_INI", "ATOM_FIN", "UNRECOGNIZED_TOKEN",
  "$accept", "program", "list-declarations", "declaration",
  "list-subprograms", "subprogram", "list-parameters", "parameter",
  "list-process", "process", "type", "list-statements", "statement",
  "block-statement", "cobegin-statement", "assignment-statement",
  "while-statement", "for-statement", "if-statement", "fork-statement",
  "atomic-statement", "return-statement", "procedure-invocation",
  "function-invocation", "expression", "binary-expression",
  "unary-expression", "term", "literal", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-107)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      17,    -2,    29,    26,  -107,     2,    10,    26,   -25,     4,
      21,    56,    10,  -107,    55,    18,    19,    42,  -107,    56,
    -107,  -107,  -107,  -107,  -107,  -107,    20,  -107,  -107,   -36,
      50,    50,    24,  -107,    57,    57,  -107,    27,    33,    38,
      43,    26,    30,  -107,  -107,  -107,  -107,  -107,  -107,    23,
      23,    57,  -107,    44,  -107,  -107,    87,  -107,  -107,    40,
      55,    26,    50,    45,    81,    50,  -107,  -107,    51,    55,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,  -107,  -107,    81,  -107,    55,   -11,  -107,
      52,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,    53,    57,   -11,
      77,    57,    57,    57,   -30,   -11,    90,   -11,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,    26,
      54,    93,   -11,    91,    89,    80,    57,    50,    58,  -107,
    -107,    81,  -107,  -107,  -107,    81,    81,    57,    61,    66,
    -107,  -107,    96,  -107,    85,  -107,    65,    81,    57,  -107,
    -107,   112,    81,  -107
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     1,     0,     8,     4,     0,     0,
       0,     0,     8,     3,     0,     0,     0,     0,     2,    15,
       7,    18,    19,    20,    21,    22,     0,    24,    25,     0,
      13,    13,     0,    16,     0,     0,     6,     0,     0,    12,
       0,     4,    78,    72,    73,    77,    74,    75,    76,     0,
       0,     0,    70,     0,    50,    51,    52,    69,    68,     0,
       0,     4,    13,     0,     0,    13,    67,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,    14,     0,    11,     0,     0,    17,
       0,    71,    23,    58,    60,    59,    61,    62,    63,    53,
      54,    55,    56,    57,    64,    65,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,    28,    29,
      30,    31,    32,    33,    35,    36,    37,    34,    49,     4,
       0,     0,     0,     0,     0,     0,     0,    13,     0,    38,
      27,     0,    47,    39,    45,     0,     0,     0,     0,     0,
      46,    10,    43,    41,     0,    40,     0,     0,     0,    48,
      44,     0,     0,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,     7,  -107,   128,  -107,   -13,  -107,   122,  -107,
     -56,  -106,    11,   -62,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,   -35,  -107,  -107,   -23,  -107,  -107
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,     7,    11,    12,    38,    39,    18,    19,
      29,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    52,    53,    54,    55,    56,    57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    35,    89,   131,    84,   108,    88,   136,   109,   138,
     110,   140,   111,    92,    13,   112,    68,   113,    40,   114,
       1,    36,   137,   106,     9,    10,    66,    67,     3,     4,
       5,   107,     8,    14,    15,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    64,    86,
     115,    16,    90,    42,    43,    44,    45,    46,    47,    48,
      21,    22,    23,    24,    25,    26,    27,    28,    85,    17,
      30,    31,    32,   130,    34,    51,   133,   134,   135,   151,
      37,    41,    65,   152,   153,    60,    61,    42,    43,    44,
      45,    46,    47,    48,    62,   160,    63,    83,    88,    69,
     163,   148,    49,    87,    91,   128,    50,   132,   139,    51,
     129,   142,   154,   143,   158,   145,   146,   147,   155,   156,
     150,   157,   159,   161,   149,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   141,    81,    82,   162,
      20,    33,     0,   144
};

static const yytype_int16 yycheck[] =
{
      35,    37,    64,   109,    60,    16,    17,    37,    19,   115,
      21,   117,    23,    69,     7,    26,    51,    28,    31,    30,
       3,    57,    52,    85,    14,    15,    49,    50,    30,     0,
       4,    87,    30,    58,    30,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    41,    62,
      61,    30,    65,    30,    31,    32,    33,    34,    35,    36,
       5,     6,     7,     8,     9,    10,    11,    12,    61,    13,
      52,    52,    30,   108,    54,    52,   111,   112,   113,   141,
      30,    57,    52,   145,   146,    58,    53,    30,    31,    32,
      33,    34,    35,    36,    56,   157,    53,    57,    17,    55,
     162,   136,    45,    58,    53,    53,    49,    30,    18,    52,
      57,    57,   147,    20,    29,    24,    27,    37,    57,    53,
      62,    25,    57,   158,   137,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   129,    50,    51,    27,
      12,    19,    -1,   132
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    65,    30,     0,     4,    66,    67,    30,    14,
      15,    68,    69,    66,    58,    30,    30,    13,    72,    73,
      68,     5,     6,     7,     8,     9,    10,    11,    12,    74,
      52,    52,    30,    72,    54,    37,    57,    30,    70,    71,
      70,    57,    30,    31,    32,    33,    34,    35,    36,    45,
      49,    52,    87,    88,    89,    90,    91,    92,    93,    88,
      58,    53,    56,    53,    66,    52,    91,    91,    88,    55,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    50,    51,    57,    74,    66,    70,    58,    17,    77,
      70,    53,    74,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    77,    74,    16,    19,
      21,    23,    26,    28,    30,    61,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    53,    57,
      88,    75,    30,    88,    88,    88,    37,    52,    75,    18,
      75,    66,    57,    20,    76,    24,    27,    37,    88,    70,
      62,    77,    77,    77,    88,    57,    53,    25,    29,    57,
      77,    88,    27,    77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    70,    71,    72,    72,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    78,
      79,    80,    81,    82,    82,    83,    84,    85,    86,    87,
      88,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    90,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    92,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     0,     7,     5,     2,     0,     7,
      10,     3,     1,     0,     3,     1,     2,     5,     1,     1,
       1,     1,     1,     5,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     4,     8,     4,     6,     3,     3,     3,     5,     4,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1
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
  case 2: /* program: S_PROGRAM IDENT list-declarations list-subprograms list-process  */
#line 143 "src/parser.y"
                                                                   {
        (yyval.prog) = create_program((yyvsp[-3].ident),(yyvsp[-2].decl),(yyvsp[-1].subprog),(yyvsp[0].proc));
    }
#line 1280 "parser.tab.c"
    break;

  case 3: /* list-declarations: declaration list-declarations  */
#line 150 "src/parser.y"
                                 {
        (yyval.decl) = (yyvsp[-1].decl);
        (yyvsp[-1].decl)->next = (yyvsp[0].decl);
    }
#line 1289 "parser.tab.c"
    break;

  case 4: /* list-declarations: %empty  */
#line 154 "src/parser.y"
                   {
        (yyval.decl) = 0;
    }
#line 1297 "parser.tab.c"
    break;

  case 5: /* declaration: S_VAR IDENT DELIM_2P type OP_ASSIGN expression DELIM_PC  */
#line 160 "src/parser.y"
                                                           {
        (yyval.decl) = create_declaration_variable((yyvsp[-5].ident), (yyvsp[-3].type), (yyvsp[-1].expr));
    }
#line 1305 "parser.tab.c"
    break;

  case 6: /* declaration: S_VAR IDENT DELIM_2P type DELIM_PC  */
#line 163 "src/parser.y"
                                        {
        (yyval.decl) = create_declaration_variable((yyvsp[-3].ident), (yyvsp[-1].type), 0);
    }
#line 1313 "parser.tab.c"
    break;

  case 7: /* list-subprograms: subprogram list-subprograms  */
#line 170 "src/parser.y"
                               {
        (yyval.subprog) = (yyvsp[-1].subprog);
        (yyvsp[-1].subprog)->next = (yyvsp[0].subprog);
    }
#line 1322 "parser.tab.c"
    break;

  case 8: /* list-subprograms: %empty  */
#line 174 "src/parser.y"
                   {
        (yyval.subprog) = 0;
    }
#line 1330 "parser.tab.c"
    break;

  case 9: /* subprogram: S_PROCEDURE IDENT PAR_IZDO list-parameters PAR_DCHO list-declarations block-statement  */
#line 181 "src/parser.y"
                                                                                         {
        (yyval.subprog) = create_subprogram_procedure((yyvsp[-5].ident), (yyvsp[-3].param), (yyvsp[-1].decl), (yyvsp[0].stmt));
    }
#line 1338 "parser.tab.c"
    break;

  case 10: /* subprogram: S_FUNCTION IDENT PAR_IZDO list-parameters PAR_DCHO DELIM_2P type DELIM_PC list-declarations block-statement  */
#line 185 "src/parser.y"
                                                                                                                 {
        (yyval.subprog) = create_subprogram_function((yyvsp[-8].ident), (yyvsp[-6].param), (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-3].type));
    }
#line 1346 "parser.tab.c"
    break;

  case 11: /* list-parameters: parameter DELIM_C list-parameters  */
#line 191 "src/parser.y"
                                     {
        (yyval.param) = (yyvsp[-2].param);
        (yyvsp[-2].param)->next = (yyvsp[0].param);
    }
#line 1355 "parser.tab.c"
    break;

  case 12: /* list-parameters: parameter  */
#line 195 "src/parser.y"
               {
        (yyval.param) = (yyvsp[0].param);
    }
#line 1363 "parser.tab.c"
    break;

  case 13: /* list-parameters: %empty  */
#line 198 "src/parser.y"
                   {
        (yyval.param) = 0;
    }
#line 1371 "parser.tab.c"
    break;

  case 14: /* parameter: IDENT DELIM_2P type  */
#line 204 "src/parser.y"
                       {
        (yyval.param) = create_parameter_list((yyvsp[-2].ident), (yyvsp[0].type));
    }
#line 1379 "parser.tab.c"
    break;

  case 15: /* list-process: process  */
#line 211 "src/parser.y"
           {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 1387 "parser.tab.c"
    break;

  case 16: /* list-process: process list-process  */
#line 214 "src/parser.y"
                          {
        (yyval.proc) = (yyvsp[-1].proc);
        (yyvsp[-1].proc)->next = (yyvsp[0].proc);
    }
#line 1396 "parser.tab.c"
    break;

  case 17: /* process: S_PROCESS IDENT DELIM_PC list-declarations block-statement  */
#line 222 "src/parser.y"
                                                              {
        (yyval.proc) = create_process((yyvsp[-3].ident), (yyvsp[-1].decl), (yyvsp[0].stmt));
    }
#line 1404 "parser.tab.c"
    break;

  case 18: /* type: T_INTEGER  */
#line 231 "src/parser.y"
             {
        (yyval.type) = create_basic_type(TYPE_INTEGER);
    }
#line 1412 "parser.tab.c"
    break;

  case 19: /* type: T_BOOLEAN  */
#line 234 "src/parser.y"
               {
        (yyval.type) = create_basic_type(TYPE_BOOLEAN);
    }
#line 1420 "parser.tab.c"
    break;

  case 20: /* type: T_CHAR  */
#line 237 "src/parser.y"
            {
        (yyval.type) = create_basic_type(TYPE_CHAR);
    }
#line 1428 "parser.tab.c"
    break;

  case 21: /* type: T_STRING  */
#line 240 "src/parser.y"
              {
        (yyval.type) = create_basic_type(TYPE_STRING);
    }
#line 1436 "parser.tab.c"
    break;

  case 22: /* type: T_REAL  */
#line 243 "src/parser.y"
            {
        (yyval.type) = create_basic_type(TYPE_REAL);
    }
#line 1444 "parser.tab.c"
    break;

  case 23: /* type: T_ARRAY CORCH_IZDO expression CORCH_DCHO type  */
#line 246 "src/parser.y"
                                                   {
        (yyval.type) = create_array_type((yyvsp[0].type));
    }
#line 1452 "parser.tab.c"
    break;

  case 24: /* type: T_SEMAPHORE  */
#line 249 "src/parser.y"
                 {
        (yyval.type) = create_semaphore_type();
    }
#line 1460 "parser.tab.c"
    break;

  case 25: /* type: T_DPROCESS  */
#line 252 "src/parser.y"
                {
        (yyval.type) = create_dprocess_type();
    }
#line 1468 "parser.tab.c"
    break;

  case 26: /* list-statements: statement  */
#line 259 "src/parser.y"
             {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1476 "parser.tab.c"
    break;

  case 27: /* list-statements: statement list-statements  */
#line 262 "src/parser.y"
                               {
        (yyval.stmt) = (yyvsp[-1].stmt);
        (yyvsp[-1].stmt)->next = (yyvsp[0].stmt);
    }
#line 1485 "parser.tab.c"
    break;

  case 28: /* statement: block-statement  */
#line 269 "src/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1493 "parser.tab.c"
    break;

  case 29: /* statement: cobegin-statement  */
#line 272 "src/parser.y"
                       {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1501 "parser.tab.c"
    break;

  case 30: /* statement: assignment-statement  */
#line 275 "src/parser.y"
                          {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1509 "parser.tab.c"
    break;

  case 31: /* statement: while-statement  */
#line 278 "src/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1517 "parser.tab.c"
    break;

  case 32: /* statement: for-statement  */
#line 281 "src/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1525 "parser.tab.c"
    break;

  case 33: /* statement: if-statement  */
#line 284 "src/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1533 "parser.tab.c"
    break;

  case 34: /* statement: procedure-invocation  */
#line 287 "src/parser.y"
                          {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1541 "parser.tab.c"
    break;

  case 35: /* statement: fork-statement  */
#line 290 "src/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1549 "parser.tab.c"
    break;

  case 36: /* statement: atomic-statement  */
#line 293 "src/parser.y"
                      {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1557 "parser.tab.c"
    break;

  case 37: /* statement: return-statement  */
#line 296 "src/parser.y"
                      {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1565 "parser.tab.c"
    break;

  case 38: /* block-statement: B_BEGIN list-statements B_END  */
#line 302 "src/parser.y"
                                 {
        (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
    }
#line 1573 "parser.tab.c"
    break;

  case 39: /* cobegin-statement: B_COBEGIN list-statements B_COEND  */
#line 308 "src/parser.y"
                                     {
        (yyval.stmt) = create_statement_block_cobegin((yyvsp[-1].stmt));
    }
#line 1581 "parser.tab.c"
    break;

  case 40: /* assignment-statement: IDENT OP_ASSIGN expression DELIM_PC  */
#line 315 "src/parser.y"
                                       {
        (yyval.stmt) = create_statement_assignment((yyvsp[-3].ident), (yyvsp[-1].expr));
    }
#line 1589 "parser.tab.c"
    break;

  case 41: /* while-statement: WHILE expression DO block-statement  */
#line 323 "src/parser.y"
                                       {
        (yyval.stmt) = create_statement_while((yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 1597 "parser.tab.c"
    break;

  case 42: /* for-statement: FOR expression OP_ASSIGN expression TO expression DO block-statement  */
#line 329 "src/parser.y"
                                                                        {
        (yyval.stmt) = create_statement_for((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 1605 "parser.tab.c"
    break;

  case 43: /* if-statement: IF expression THEN block-statement  */
#line 335 "src/parser.y"
                                      {
        (yyval.stmt) = create_statement_if_else((yyvsp[-2].expr), (yyvsp[0].stmt), 0);
    }
#line 1613 "parser.tab.c"
    break;

  case 44: /* if-statement: IF expression THEN block-statement ELSE block-statement  */
#line 338 "src/parser.y"
                                                             {
        (yyval.stmt) = create_statement_if_else((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt));
    }
#line 1621 "parser.tab.c"
    break;

  case 45: /* fork-statement: S_FORK IDENT statement  */
#line 344 "src/parser.y"
                          {
        (yyval.stmt) = create_statement_fork((yyvsp[-1].ident), (yyvsp[0].stmt));
    }
#line 1629 "parser.tab.c"
    break;

  case 46: /* atomic-statement: ATOM_INI list-statements ATOM_FIN  */
#line 350 "src/parser.y"
                                     {
        (yyval.stmt) = create_statement_atomic((yyvsp[-1].stmt));
    }
#line 1637 "parser.tab.c"
    break;

  case 47: /* return-statement: RETURN expression DELIM_PC  */
#line 356 "src/parser.y"
                              {
        (yyval.stmt) = create_statement_return((yyvsp[-1].expr));
    }
#line 1645 "parser.tab.c"
    break;

  case 48: /* procedure-invocation: IDENT PAR_IZDO list-parameters PAR_DCHO DELIM_PC  */
#line 363 "src/parser.y"
                                                    {
        (yyval.stmt) = create_statement_procedure_inv((yyvsp[-4].ident), (yyvsp[-2].param));
    }
#line 1653 "parser.tab.c"
    break;

  case 49: /* function-invocation: IDENT PAR_IZDO list-parameters PAR_DCHO  */
#line 369 "src/parser.y"
                                           {
        (yyval.expr) = create_expression_function_invocation((yyvsp[-3].ident), (yyvsp[-1].param));
    }
#line 1661 "parser.tab.c"
    break;

  case 50: /* expression: binary-expression  */
#line 376 "src/parser.y"
                     {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1669 "parser.tab.c"
    break;

  case 51: /* expression: unary-expression  */
#line 379 "src/parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1677 "parser.tab.c"
    break;

  case 52: /* expression: term  */
#line 382 "src/parser.y"
          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1685 "parser.tab.c"
    break;

  case 53: /* binary-expression: term OP_SUM expression  */
#line 389 "src/parser.y"
                          {
        (yyval.expr) = create_expression_binary_operation(EXPR_ADD, "+", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1693 "parser.tab.c"
    break;

  case 54: /* binary-expression: term OP_MINUS expression  */
#line 393 "src/parser.y"
                              {
        (yyval.expr) = create_expression_binary_operation(EXPR_SUB, "-", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1701 "parser.tab.c"
    break;

  case 55: /* binary-expression: term OP_MULT expression  */
#line 397 "src/parser.y"
                             {
        (yyval.expr) = create_expression_binary_operation(EXPR_MULT, "*", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1709 "parser.tab.c"
    break;

  case 56: /* binary-expression: term OP_DIV expression  */
#line 401 "src/parser.y"
                            {
        (yyval.expr) = create_expression_binary_operation(EXPR_DIV, "/", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1717 "parser.tab.c"
    break;

  case 57: /* binary-expression: term OP_MOD expression  */
#line 405 "src/parser.y"
                            {
        (yyval.expr) = create_expression_binary_operation(EXPR_MOD, "%", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1725 "parser.tab.c"
    break;

  case 58: /* binary-expression: term OP_REL_LT expression  */
#line 409 "src/parser.y"
                               {
        (yyval.expr) = create_expression_binary_operation(EXPR_LT, "<", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1733 "parser.tab.c"
    break;

  case 59: /* binary-expression: term OP_REL_LTE expression  */
#line 413 "src/parser.y"
                                {
        (yyval.expr) = create_expression_binary_operation(EXPR_LTE, "<=", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1741 "parser.tab.c"
    break;

  case 60: /* binary-expression: term OP_REL_GT expression  */
#line 417 "src/parser.y"
                               {
        (yyval.expr) = create_expression_binary_operation(EXPR_GT, ">", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1749 "parser.tab.c"
    break;

  case 61: /* binary-expression: term OP_REL_GTE expression  */
#line 421 "src/parser.y"
                                {
        (yyval.expr) = create_expression_binary_operation(EXPR_GTE, ">=", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1757 "parser.tab.c"
    break;

  case 62: /* binary-expression: term OP_REL_EQ expression  */
#line 425 "src/parser.y"
                               {
        (yyval.expr) = create_expression_binary_operation(EXPR_EQ, "==", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1765 "parser.tab.c"
    break;

  case 63: /* binary-expression: term OP_REL_NEQ expression  */
#line 429 "src/parser.y"
                                {
        (yyval.expr) = create_expression_binary_operation(EXPR_NEQ, "!=", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1773 "parser.tab.c"
    break;

  case 64: /* binary-expression: term OP_AND expression  */
#line 433 "src/parser.y"
                            {
        (yyval.expr) = create_expression_binary_operation(EXPR_AND, "and", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1781 "parser.tab.c"
    break;

  case 65: /* binary-expression: term OP_OR expression  */
#line 437 "src/parser.y"
                           {
        (yyval.expr) = create_expression_binary_operation(EXPR_OR, "or", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 1789 "parser.tab.c"
    break;

  case 66: /* unary-expression: OP_NOT term  */
#line 444 "src/parser.y"
               {
        (yyval.expr) = create_expression_unary_operation(EXPR_NOT, "not", (yyvsp[0].expr));
    }
#line 1797 "parser.tab.c"
    break;

  case 67: /* unary-expression: OP_MINUS term  */
#line 448 "src/parser.y"
                   {
        (yyval.expr) = create_expression_unary_operation(EXPR_NEGATIVE, "-", (yyvsp[0].expr));
    }
#line 1805 "parser.tab.c"
    break;

  case 68: /* term: identifier  */
#line 454 "src/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1813 "parser.tab.c"
    break;

  case 69: /* term: literal  */
#line 457 "src/parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1821 "parser.tab.c"
    break;

  case 70: /* term: function-invocation  */
#line 460 "src/parser.y"
                         {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1829 "parser.tab.c"
    break;

  case 71: /* term: PAR_IZDO expression PAR_DCHO  */
#line 463 "src/parser.y"
                                  {
        (yyval.expr) = create_expression_grouped((yyvsp[-1].expr));
    }
#line 1837 "parser.tab.c"
    break;

  case 72: /* literal: LITERAL  */
#line 470 "src/parser.y"
           {
        (yyval.expr) = create_expression_literal_string((yyvsp[0].literal_string));
    }
#line 1845 "parser.tab.c"
    break;

  case 73: /* literal: L_INTEGER  */
#line 473 "src/parser.y"
               {
        (yyval.expr) = create_expression_literal_integer((yyvsp[0].literal_int));
    }
#line 1853 "parser.tab.c"
    break;

  case 74: /* literal: L_BOOLEAN_TRUE  */
#line 476 "src/parser.y"
                    {
        (yyval.expr) = create_expression_literal_boolean(1);
    }
#line 1861 "parser.tab.c"
    break;

  case 75: /* literal: L_BOOLEAN_FALSE  */
#line 479 "src/parser.y"
                     {
        (yyval.expr) = create_expression_literal_boolean(0);
    }
#line 1869 "parser.tab.c"
    break;

  case 76: /* literal: L_CHAR  */
#line 482 "src/parser.y"
            {
        (yyval.expr) = create_expression_literal_char((yyvsp[0].literal_char));
    }
#line 1877 "parser.tab.c"
    break;

  case 77: /* literal: L_REAL  */
#line 485 "src/parser.y"
            {
        (yyval.expr) = create_expression_literal_real((yyvsp[0].literal_float));
    }
#line 1885 "parser.tab.c"
    break;

  case 78: /* identifier: IDENT  */
#line 491 "src/parser.y"
         {
        (yyval.expr) = create_expression_identifier((yyvsp[0].ident));
    }
#line 1893 "parser.tab.c"
    break;


#line 1897 "parser.tab.c"

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

#line 496 "src/parser.y"


// Soporte de las rutinas en C


void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis en la linea ?: %s\n",s);
}
