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

    //Definir directiva para testeo
    #define VERBOSE

    //Definir prototipos de funciones
    extern int yylex();  
    extern FILE *yyin;

    void yyerror(const char* s);  

#line 85 "parser.tab.c"

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
  YYSYMBOL_66_opt_declarations = 66,       /* opt-declarations  */
  YYSYMBOL_declarations = 67,              /* declarations  */
  YYSYMBOL_68_list_variable_declarations = 68, /* list-variable-declarations  */
  YYSYMBOL_69_variable_declaration = 69,   /* variable-declaration  */
  YYSYMBOL_70_variable_assignation = 70,   /* variable-assignation  */
  YYSYMBOL_71_opt_subprograms = 71,        /* opt-subprograms  */
  YYSYMBOL_72_list_subprograms = 72,       /* list-subprograms  */
  YYSYMBOL_subprogram = 73,                /* subprogram  */
  YYSYMBOL_74_program_process = 74,        /* program-process  */
  YYSYMBOL_process = 75,                   /* process  */
  YYSYMBOL_76_array_of_process = 76,       /* array-of-process  */
  YYSYMBOL_type = 77,                      /* type  */
  YYSYMBOL_78_procedure_definition = 78,   /* procedure-definition  */
  YYSYMBOL_79_function_definition = 79,    /* function-definition  */
  YYSYMBOL_80_opt_parameters = 80,         /* opt-parameters  */
  YYSYMBOL_81_list_parameters = 81,        /* list-parameters  */
  YYSYMBOL_parameter = 82,                 /* parameter  */
  YYSYMBOL_83_list_statements = 83,        /* list-statements  */
  YYSYMBOL_statement = 84,                 /* statement  */
  YYSYMBOL_85_block_statement = 85,        /* block-statement  */
  YYSYMBOL_86_cobegin_statement = 86,      /* cobegin-statement  */
  YYSYMBOL_87_assignment_statement = 87,   /* assignment-statement  */
  YYSYMBOL_88_array_assignment_statement = 88, /* array-assignment-statement  */
  YYSYMBOL_89_while_statement = 89,        /* while-statement  */
  YYSYMBOL_90_for_statement = 90,          /* for-statement  */
  YYSYMBOL_91_if_statement = 91,           /* if-statement  */
  YYSYMBOL_92_fork_statement = 92,         /* fork-statement  */
  YYSYMBOL_93_atomic_statement = 93,       /* atomic-statement  */
  YYSYMBOL_94_return_statement = 94,       /* return-statement  */
  YYSYMBOL_95_procedure_invocation = 95,   /* procedure-invocation  */
  YYSYMBOL_96_function_invocation = 96,    /* function-invocation  */
  YYSYMBOL_expression = 97,                /* expression  */
  YYSYMBOL_term = 98,                      /* term  */
  YYSYMBOL_literal = 99,                   /* literal  */
  YYSYMBOL_identifier = 100,               /* identifier  */
  YYSYMBOL_101_binary_operator = 101,      /* binary-operator  */
  YYSYMBOL_102_unary_operator = 102        /* unary-operator  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

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
       0,   102,   102,   107,   108,   112,   116,   117,   121,   125,
     126,   131,   132,   136,   137,   141,   142,   147,   148,   152,
     156,   157,   162,   163,   164,   165,   166,   167,   168,   169,
     174,   178,   182,   183,   187,   188,   192,   197,   198,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   215,
     219,   223,   227,   228,   232,   236,   240,   241,   245,   249,
     253,   258,   262,   267,   268,   272,   273,   274,   275,   280,
     281,   282,   283,   284,   285,   289,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   310,
     311
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
  "$accept", "program", "opt-declarations", "declarations",
  "list-variable-declarations", "variable-declaration",
  "variable-assignation", "opt-subprograms", "list-subprograms",
  "subprogram", "program-process", "process", "array-of-process", "type",
  "procedure-definition", "function-definition", "opt-parameters",
  "list-parameters", "parameter", "list-statements", "statement",
  "block-statement", "cobegin-statement", "assignment-statement",
  "array-assignment-statement", "while-statement", "for-statement",
  "if-statement", "fork-statement", "atomic-statement", "return-statement",
  "procedure-invocation", "function-invocation", "expression", "term",
  "literal", "identifier", "binary-operator", "unary-operator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -16,    16,  -105,    13,  -105,   -16,    37,  -105,   -16,
    -105,   -24,   -16,   -16,    24,    37,  -105,  -105,  -105,  -105,
     110,    -6,    -4,   -16,    24,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,     1,  -105,  -105,    19,   -16,   -16,     4,  -105,
     129,   129,     0,    12,    10,  -105,    17,    15,   -16,    14,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   129,  -105,
      21,   151,  -105,    18,     9,  -105,  -105,    13,   -16,   110,
      20,    23,    13,    26,   110,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   129,   -16,
    -105,    60,  -105,  -105,   110,    54,    60,  -105,  -105,  -105,
      38,   127,  -105,    33,    34,  -105,  -105,   129,   127,   -16,
     129,   129,   -16,   127,    66,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,   -39,    13,    63,    40,
     119,   127,    74,    72,    67,     2,  -105,  -105,   -16,   129,
      68,    60,    48,  -105,  -105,  -105,    60,    60,   129,  -105,
      53,    70,   129,  -105,  -105,    84,  -105,    94,    69,  -105,
      71,    60,   129,  -105,  -105,  -105,   104,    60,  -105
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    75,     4,     1,     0,    12,     3,     5,
       6,     0,     0,     0,     0,    11,    13,    15,    16,     7,
       0,     0,     0,     0,     2,    17,    14,    22,    23,    24,
      25,    26,     0,    28,    29,    10,    33,    33,    21,    18,
       0,     0,     0,     0,    32,    34,     0,     0,     0,     0,
      69,    70,    74,    71,    72,    73,    89,    90,     0,    67,
       0,     0,    66,    65,     0,     9,     8,     4,     0,     0,
       0,     0,     4,     0,     0,    82,    81,    84,    83,    85,
      86,    78,    79,    76,    77,    80,    87,    88,     0,    33,
      64,     0,    35,    36,     0,     0,     0,    68,    27,    63,
       0,     0,    30,     0,     0,    19,    62,     0,     0,     0,
       0,     0,     0,     0,     0,    37,    39,    40,    41,    42,
      43,    44,    46,    47,    48,    45,    53,     4,     0,     0,
       0,     0,     0,     0,     0,     0,    49,    38,    33,     0,
       0,     0,     0,    60,    50,    58,     0,     0,     0,    59,
       0,     0,     0,    31,    20,    56,    54,     0,     0,    52,
       0,     0,     0,    61,    51,    57,     0,     0,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -105,  -105,   -65,  -105,  -105,   123,  -105,  -105,  -105,   118,
    -105,   117,  -105,   -45,  -105,  -105,   -36,  -105,    83,   -75,
    -104,   -87,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,   -38,    88,  -105,    -1,  -105,  -105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     7,     8,     9,    10,    42,    14,    15,    16,
      24,    25,    49,    35,    17,    18,    43,    44,    45,   114,
     115,   116,   117,   118,   140,   119,   120,   121,   122,   123,
     124,   125,    59,    60,    61,    62,    63,    88,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       4,    47,    91,    65,   102,    11,     1,    96,    11,   105,
     137,    21,    22,   138,     3,   139,     5,     6,   107,   101,
      73,   108,    38,   109,    93,   110,   137,   145,   111,    98,
     112,   137,     3,   130,    20,    46,    46,    23,   135,     3,
      50,    51,    52,    53,    54,    55,    36,    71,    37,   103,
      99,    12,    13,   100,   153,    40,    41,    66,    48,   155,
     156,    58,   141,   113,   149,    67,    68,    46,    70,   129,
      89,    72,   132,   133,   165,    69,    74,   101,    94,    97,
     168,    95,   107,   101,   136,   108,   104,   109,    46,   110,
     127,   106,   111,   128,   112,   142,     3,   143,   146,   147,
     126,   151,   150,   154,   148,   152,   158,   126,   131,   161,
     157,   134,   126,   126,   160,    27,    28,    29,    30,    31,
      32,    33,    34,   162,   166,   159,   163,   113,   164,   126,
     126,   167,    19,    26,   126,   107,   101,    46,   108,   144,
     109,    39,   110,   107,   101,   111,   108,   112,   109,     3,
     110,    92,    90,   111,     0,   112,     0,     3,     0,     3,
      50,    51,    52,    53,    54,    55,     0,     0,     0,     0,
       0,     0,     0,     0,    56,     0,     0,     0,    57,     0,
     113,    58,     0,     0,     0,     0,     0,     0,   113,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,    86,    87
};

static const yytype_int16 yycheck[] =
{
       1,    37,    67,    41,    91,     6,     3,    72,     9,    96,
     114,    12,    13,    52,    30,    54,     0,     4,    16,    17,
      58,    19,    23,    21,    69,    23,   130,   131,    26,    74,
      28,   135,    30,   108,    58,    36,    37,    13,   113,    30,
      31,    32,    33,    34,    35,    36,    52,    48,    52,    94,
      88,    14,    15,    89,   141,    54,    37,    57,    54,   146,
     147,    52,   127,    61,    62,    53,    56,    68,    53,   107,
      52,    57,   110,   111,   161,    58,    55,    17,    58,    53,
     167,    58,    16,    17,    18,    19,    32,    21,    89,    23,
      57,    53,    26,    59,    28,    32,    30,    57,    24,    27,
     101,   139,   138,    55,    37,    37,    53,   108,   109,    25,
     148,   112,   113,   114,   152,     5,     6,     7,     8,     9,
      10,    11,    12,    29,   162,    55,    57,    61,    57,   130,
     131,    27,     9,    15,   135,    16,    17,   138,    19,    20,
      21,    24,    23,    16,    17,    26,    19,    28,    21,    30,
      23,    68,    64,    26,    -1,    28,    -1,    30,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    -1,
      61,    52,    -1,    -1,    -1,    -1,    -1,    -1,    61,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    65,    30,   100,     0,     4,    66,    67,    68,
      69,   100,    14,    15,    71,    72,    73,    78,    79,    69,
      58,   100,   100,    13,    74,    75,    73,     5,     6,     7,
       8,     9,    10,    11,    12,    77,    52,    52,   100,    75,
      54,    37,    70,    80,    81,    82,   100,    80,    54,    76,
      31,    32,    33,    34,    35,    36,    45,    49,    52,    96,
      97,    98,    99,   100,   102,    97,    57,    53,    56,    58,
      53,   100,    57,    97,    55,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    50,    51,   101,    52,
      98,    66,    82,    77,    58,    58,    66,    53,    77,    97,
      80,    17,    85,    77,    32,    85,    53,    16,    19,    21,
      23,    26,    28,    61,    83,    84,    85,    86,    87,    89,
      90,    91,    92,    93,    94,    95,   100,    57,    59,    97,
      83,   100,    97,    97,   100,    83,    18,    84,    52,    54,
      88,    66,    32,    57,    20,    84,    24,    27,    37,    62,
      80,    97,    37,    85,    55,    85,    85,    97,    53,    55,
      97,    25,    29,    57,    57,    85,    97,    27,    85
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    68,    68,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      78,    79,    80,    80,    81,    81,    82,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    85,
      86,    87,    88,    88,    89,    90,    91,    91,    92,    93,
      94,    95,    96,    97,    97,    98,    98,    98,    98,    99,
      99,    99,    99,    99,    99,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     1,     0,     2,     1,     2,     5,     2,
       0,     1,     0,     1,     2,     1,     1,     1,     2,     6,
       7,     0,     1,     1,     1,     1,     1,     5,     1,     1,
       7,    10,     1,     0,     1,     3,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     5,     3,     0,     4,     8,     4,     6,     3,     3,
       3,     5,     4,     3,     2,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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

#line 1305 "parser.tab.c"

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

#line 314 "src/parser.y"


// Soporte de las rutinas en C


void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}
