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
    #include "AST/AST.h"

    //Inclusion de mensajes de errores de parser
    #include "parser_errors.h"

    //Definir directiva para testeo
    #define VERBOSE

    //Definir prototipos de funciones
    extern int yylex();
    extern FILE *yyin;
    extern int yylineno;

    void yyerror(const char* s);  

#line 92 "src/parser.c"

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

#include "token.h"
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
  YYSYMBOL_66_program_name = 66,           /* program-name  */
  YYSYMBOL_67_list_declarations = 67,      /* list-declarations  */
  YYSYMBOL_declaration = 68,               /* declaration  */
  YYSYMBOL_69_declaration_var_with_assignment = 69, /* declaration-var-with-assignment  */
  YYSYMBOL_70_declaration_var = 70,        /* declaration-var  */
  YYSYMBOL_71_declaration_name = 71,       /* declaration-name  */
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
  YYSYMBOL_97_procedure_invocation = 97,   /* procedure-invocation  */
  YYSYMBOL_98_function_invocation = 98,    /* function-invocation  */
  YYSYMBOL_99_list_arguments = 99,         /* list-arguments  */
  YYSYMBOL_argument = 100,                 /* argument  */
  YYSYMBOL_expression = 101,               /* expression  */
  YYSYMBOL_102_binary_expression = 102,    /* binary-expression  */
  YYSYMBOL_103_unary_expression = 103,     /* unary-expression  */
  YYSYMBOL_term = 104,                     /* term  */
  YYSYMBOL_literal = 105,                  /* literal  */
  YYSYMBOL_identifier = 106                /* identifier  */
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
#define YYLAST   242

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

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
       0,   174,   174,   177,   187,   191,   202,   206,   212,   215,
     219,   229,   233,   241,   251,   255,   263,   273,   277,   288,
     292,   298,   301,   308,   312,   316,   326,   330,   341,   345,
     349,   359,   363,   373,   377,   383,   387,   397,   401,   412,
     415,   422,   432,   436,   451,   455,   467,   470,   473,   476,
     479,   482,   485,   488,   492,   503,   506,   513,   516,   519,
     522,   525,   528,   531,   534,   537,   540,   543,   553,   559,
     566,   574,   580,   586,   589,   595,   601,   607,   614,   617,
     623,   626,   632,   636,   642,   649,   652,   655,   662,   666,
     670,   674,   678,   682,   686,   690,   694,   698,   702,   706,
     710,   713,   724,   728,   734,   737,   740,   743,   750,   753,
     756,   759,   762,   765,   771
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
  "$accept", "program", "program-name", "list-declarations", "declaration",
  "declaration-var-with-assignment", "declaration-var", "declaration-name",
  "list-subprograms", "subprogram", "subprogram-procedure",
  "subprogram-procedure-name", "subprogram-function",
  "subprogram-function-name", "list-parameters", "parameter",
  "parameter-name", "list-process", "process", "process-def",
  "process-name", "type", "list-statements", "statement",
  "block-statement", "cobegin-statement", "assignment-statement",
  "while-statement", "for-statement", "if-statement", "fork-statement",
  "atomic-statement", "return-statement", "procedure-invocation",
  "function-invocation", "list-arguments", "argument", "expression",
  "binary-expression", "unary-expression", "term", "literal", "identifier", YY_NULLPTR
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

#define YYTABLE_NINF (-56)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     118,  -169,     4,    32,  -169,  -169,   116,  -169,  -169,    14,
     119,   111,  -169,  -169,  -169,  -169,    15,    17,    19,    66,
     119,  -169,  -169,  -169,   230,   230,   -19,  -169,    33,    39,
    -169,    43,    26,  -169,    66,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,    44,  -169,  -169,    56,    18,     0,     1,
    -169,  -169,    24,  -169,   160,   160,  -169,  -169,   160,  -169,
    -169,  -169,    20,    50,    60,    16,    65,    82,    20,    20,
    -169,    86,  -169,  -169,  -169,  -169,  -169,  -169,   167,   167,
     160,  -169,    84,  -169,  -169,   182,  -169,  -169,    90,    25,
     131,    20,    88,   230,   230,   230,    92,   131,   131,   110,
    -169,  -169,    98,   230,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,  -169,  -169,  -169,
      71,  -169,   131,  -169,  -169,  -169,    95,   230,  -169,  -169,
    -169,   100,   101,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
     160,    71,   124,   160,   160,   126,   -30,    71,   140,    22,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,    20,   108,  -169,   160,   117,   153,    71,   151,   150,
     141,   160,   136,   120,  -169,  -169,   131,    20,  -169,  -169,
    -169,  -169,   131,   131,   160,   122,   123,   130,  -169,  -169,
     131,   159,  -169,   157,  -169,  -169,   147,  -169,   131,   160,
    -169,  -169,   179,   131,  -169
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     5,     4,     0,     1,    10,     0,
      20,     0,    18,    17,     8,     9,     0,     0,     0,     0,
      20,    21,    22,     6,     0,     0,    25,    26,     0,    30,
      31,     0,     0,     2,    39,    41,    19,    54,    46,    47,
      48,    49,    50,     0,    52,    53,     0,     0,     0,     0,
      45,    44,     0,    40,     0,     0,    15,    16,     0,    14,
      38,    37,     0,     0,    34,     0,     0,     0,     0,     0,
     101,   114,   108,   109,   113,   110,   111,   112,     0,     0,
       0,   106,     0,    85,    86,    87,   105,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    13,    11,
       0,    24,     0,    33,    36,    35,     0,     0,    43,    42,
      81,     0,    83,    84,   107,    51,    93,    95,    94,    96,
      97,    98,    88,    89,    90,    91,    92,    99,   100,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    62,    64,    65,    66,    63,
      23,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,    56,     0,     0,    82,    77,
      69,    75,     0,     0,     0,     0,     0,     0,    76,    29,
       0,    73,    71,     0,    70,    79,     0,    28,     0,     0,
      78,    74,     0,     0,    72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,  -169,   -11,  -169,  -169,  -169,  -169,   187,  -169,
    -169,  -169,  -169,  -169,   -46,  -169,  -169,   174,  -169,  -169,
    -169,   -17,   -55,    10,   -86,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -168,  -169,   -45,  -169,  -169,
     -50,  -169,  -169
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     6,    10,    11,    14,    15,    16,    19,    20,
      21,    28,    22,    31,    63,    64,    65,    33,    34,    35,
      52,    46,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    81,   131,   132,   133,    83,    84,
      85,    86,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    60,    60,    67,   121,     4,   188,   181,    47,    82,
      88,   128,   129,    89,   197,    12,    24,    93,    26,    57,
      29,     8,   182,   149,     9,    68,   118,    50,   100,   101,
      61,    61,     7,   -27,     5,   102,   170,    -7,   150,   120,
     -55,   151,   -55,   152,    13,   153,   123,    27,   154,    30,
     155,    90,   156,    62,    66,    58,    51,    97,    98,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    25,    94,    59,   124,   125,   126,    32,
     122,    69,   119,   157,   -55,    48,   135,   150,   120,    60,
     151,   -32,   152,    55,   153,    49,   176,   154,    54,   155,
     199,   156,   183,    91,   185,   175,   201,   202,   178,   179,
     172,    70,     8,    56,   207,     9,    92,     8,    61,     1,
       9,     2,   211,    95,    -7,    -7,    -7,   214,    -7,    -7,
      -7,    -7,   157,    17,    18,    96,   195,    70,    99,   103,
      71,    72,    73,    74,    75,    76,    77,   117,   120,   203,
     127,   134,   171,   173,   177,    78,   180,   174,   184,    79,
     186,    70,    80,   130,   212,   187,    71,    72,    73,    74,
      75,    76,    77,   190,   189,   192,   200,   193,   194,   204,
     205,    78,   198,   206,   208,    79,   209,   191,    80,   196,
      71,    72,    73,    74,    75,    76,    77,    71,    72,    73,
      74,    75,    76,    77,   210,    78,   213,    36,    53,    79,
       0,     0,    80,     0,     0,     0,     0,     0,     0,    80,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    37,   115,   116,     0,    38,    39,    40,    41,    42,
      43,    44,    45
};

static const yytype_int16 yycheck[] =
{
      11,     1,     1,    49,    90,     1,   174,    37,    25,    54,
      55,    97,    98,    58,   182,     1,     1,     1,     1,     1,
       1,     1,    52,     1,     4,     1,     1,     1,    78,    79,
      30,    30,     0,    52,    30,    80,   122,    17,    16,    17,
      18,    19,    20,    21,    30,    23,    92,    30,    26,    30,
      28,    62,    30,    53,    53,    37,    30,    68,    69,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     1,    58,    58,    57,    93,    94,    95,    13,
      91,    57,    57,    61,    62,    52,   103,    16,    17,     1,
      19,    52,    21,    37,    23,    52,   151,    26,    54,    28,
     186,    30,   157,    53,   159,   150,   192,   193,   153,   154,
     127,     1,     1,    57,   200,     4,    56,     1,    30,     1,
       4,     3,   208,    58,    13,    14,    15,   213,    17,    13,
      14,    15,    61,    14,    15,    53,   181,     1,    52,    55,
      30,    31,    32,    33,    34,    35,    36,    57,    17,   194,
      58,    53,    57,    53,    30,    45,    30,    56,    18,    49,
     171,     1,    52,    53,   209,    57,    30,    31,    32,    33,
      34,    35,    36,    20,    57,    24,   187,    27,    37,    57,
      57,    45,    62,    53,    25,    49,    29,   177,    52,    53,
      30,    31,    32,    33,    34,    35,    36,    30,    31,    32,
      33,    34,    35,    36,    57,    45,    27,    20,    34,    49,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     1,    50,    51,    -1,     5,     6,     7,     8,     9,
      10,    11,    12
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    65,     1,    30,    66,     0,     1,     4,
      67,    68,     1,    30,    69,    70,    71,    14,    15,    72,
      73,    74,    76,    67,     1,    58,     1,    30,    75,     1,
      30,    77,    13,    81,    82,    83,    72,     1,     5,     6,
       7,     8,     9,    10,    11,    12,    85,    85,    52,    52,
       1,    30,    84,    81,    54,    37,    57,     1,    37,    57,
       1,    30,    53,    78,    79,    80,    53,    78,     1,    57,
       1,    30,    31,    32,    33,    34,    35,    36,    45,    49,
      52,    98,   101,   102,   103,   104,   105,   106,   101,   101,
      67,    53,    56,     1,    58,    58,    53,    67,    67,    52,
     104,   104,   101,    55,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    50,    51,    57,     1,    57,
      17,    88,    67,    78,    85,    85,    85,    58,    88,    88,
      53,    99,   100,   101,    53,    85,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,     1,
      16,    19,    21,    23,    26,    28,    30,    61,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      88,    57,    85,    53,    56,   101,    86,    30,   101,   101,
      30,    37,    52,    86,    18,    86,    67,    57,    99,    57,
      20,    87,    24,    27,    37,   101,    53,    99,    62,    88,
      67,    88,    88,   101,    57,    57,    53,    88,    25,    29,
      57,    88,   101,    27,    88
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    69,    69,    69,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    82,    83,    83,    84,    84,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    88,    89,
      90,    91,    92,    93,    93,    94,    95,    96,    97,    97,
      98,    98,    99,    99,   100,   101,   101,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   103,   104,   104,   104,   104,   105,   105,
     105,   105,   105,   105,   106
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     1,     1,     1,     2,     0,     2,     2,
       1,     6,     6,     6,     4,     4,     4,     1,     1,     2,
       0,     1,     1,     7,     6,     2,     1,     1,    10,     9,
       2,     1,     1,     3,     1,     3,     3,     1,     1,     1,
       2,     1,     5,     5,     1,     1,     1,     1,     1,     1,
       1,     5,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     4,     8,     4,     6,     3,     3,     3,     5,     4,
       4,     3,     3,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     2,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1
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
#line 174 "src/parser.y"
                                                                          {
        AST_program = create_program((yyvsp[-3].ident),(yyvsp[-2].decl),(yyvsp[-1].subprog),(yyvsp[0].proc));
    }
#line 1352 "src/parser.c"
    break;

  case 3: /* program: error  */
#line 177 "src/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROGRAM_PROGRAM);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1364 "src/parser.c"
    break;

  case 4: /* program-name: IDENT  */
#line 187 "src/parser.y"
         { 
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1372 "src/parser.c"
    break;

  case 5: /* program-name: error  */
#line 191 "src/parser.y"
            { 
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROGRAM_IDENT);

        // -- Abortar inmediatamente el analisis
        YYABORT; 
    }
#line 1384 "src/parser.c"
    break;

  case 6: /* list-declarations: declaration list-declarations  */
#line 202 "src/parser.y"
                                 {
        (yyval.decl) = (yyvsp[-1].decl);
        (yyvsp[-1].decl)->next = (yyvsp[0].decl);
    }
#line 1393 "src/parser.c"
    break;

  case 7: /* list-declarations: %empty  */
#line 206 "src/parser.y"
                   {
        (yyval.decl) = 0;
    }
#line 1401 "src/parser.c"
    break;

  case 8: /* declaration: S_VAR declaration-var-with-assignment  */
#line 212 "src/parser.y"
                                         {
        (yyval.decl) = (yyvsp[0].decl);
    }
#line 1409 "src/parser.c"
    break;

  case 9: /* declaration: S_VAR declaration-var  */
#line 215 "src/parser.y"
                           {
        (yyval.decl) = (yyvsp[0].decl);
    }
#line 1417 "src/parser.c"
    break;

  case 10: /* declaration: error  */
#line 219 "src/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARARTION_VAR);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1429 "src/parser.c"
    break;

  case 11: /* declaration-var-with-assignment: declaration-name DELIM_2P type OP_ASSIGN expression DELIM_PC  */
#line 229 "src/parser.y"
                                                                {
        (yyval.decl) = create_declaration_variable((yyvsp[-5].ident), (yyvsp[-3].type), (yyvsp[-1].expr));
    }
#line 1437 "src/parser.c"
    break;

  case 12: /* declaration-var-with-assignment: declaration-name error type OP_ASSIGN expression DELIM_PC  */
#line 233 "src/parser.y"
                                                               {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_DELIM2P);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1449 "src/parser.c"
    break;

  case 13: /* declaration-var-with-assignment: declaration-name DELIM_2P type OP_ASSIGN expression error  */
#line 241 "src/parser.y"
                                                               {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_DELIMPC);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1461 "src/parser.c"
    break;

  case 14: /* declaration-var: declaration-name DELIM_2P type DELIM_PC  */
#line 251 "src/parser.y"
                                           {
        (yyval.decl) = create_declaration_variable((yyvsp[-3].ident), (yyvsp[-1].type), 0);
    }
#line 1469 "src/parser.c"
    break;

  case 15: /* declaration-var: declaration-name error type DELIM_PC  */
#line 255 "src/parser.y"
                                          {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_DELIM2P);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1481 "src/parser.c"
    break;

  case 16: /* declaration-var: declaration-name DELIM_2P type error  */
#line 263 "src/parser.y"
                                          {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_DELIMPC);

        // -- Abortar inmediatamente el analisis
        YYABORT;
    }
#line 1493 "src/parser.c"
    break;

  case 17: /* declaration-name: IDENT  */
#line 273 "src/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1501 "src/parser.c"
    break;

  case 18: /* declaration-name: error  */
#line 277 "src/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_DECLARATION_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1513 "src/parser.c"
    break;

  case 19: /* list-subprograms: subprogram list-subprograms  */
#line 288 "src/parser.y"
                               {
        (yyval.subprog) = (yyvsp[-1].subprog);
        (yyvsp[-1].subprog)->next = (yyvsp[0].subprog);
    }
#line 1522 "src/parser.c"
    break;

  case 20: /* list-subprograms: %empty  */
#line 292 "src/parser.y"
                   {
        (yyval.subprog) = 0;
    }
#line 1530 "src/parser.c"
    break;

  case 21: /* subprogram: subprogram-procedure  */
#line 298 "src/parser.y"
                        {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1538 "src/parser.c"
    break;

  case 22: /* subprogram: subprogram-function  */
#line 301 "src/parser.y"
                         {
        (yyval.subprog) = (yyvsp[0].subprog);
    }
#line 1546 "src/parser.c"
    break;

  case 23: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO list-parameters PAR_DCHO list-declarations block-statement  */
#line 308 "src/parser.y"
                                                                                                             {
        (yyval.subprog) = create_subprogram_procedure((yyvsp[-5].ident), (yyvsp[-3].param), (yyvsp[-1].decl), (yyvsp[0].stmt));
    }
#line 1554 "src/parser.c"
    break;

  case 24: /* subprogram-procedure: S_PROCEDURE subprogram-procedure-name PAR_IZDO PAR_DCHO list-declarations block-statement  */
#line 312 "src/parser.y"
                                                                                               {
        (yyval.subprog) = create_subprogram_procedure((yyvsp[-4].ident), 0, (yyvsp[-1].decl), (yyvsp[0].stmt));
    }
#line 1562 "src/parser.c"
    break;

  case 25: /* subprogram-procedure: S_PROCEDURE error  */
#line 316 "src/parser.y"
                       {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_PROCEDURE_MALFORMED);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1574 "src/parser.c"
    break;

  case 26: /* subprogram-procedure-name: IDENT  */
#line 326 "src/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1582 "src/parser.c"
    break;

  case 27: /* subprogram-procedure-name: error  */
#line 330 "src/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_PROCEDURE_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1594 "src/parser.c"
    break;

  case 28: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO list-parameters PAR_DCHO DELIM_2P type DELIM_PC list-declarations block-statement  */
#line 341 "src/parser.y"
                                                                                                                                  {
        (yyval.subprog) = create_subprogram_function((yyvsp[-8].ident), (yyvsp[-6].param), (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-3].type));
    }
#line 1602 "src/parser.c"
    break;

  case 29: /* subprogram-function: S_FUNCTION subprogram-function-name PAR_IZDO PAR_DCHO DELIM_2P type DELIM_PC list-declarations block-statement  */
#line 345 "src/parser.y"
                                                                                                                    {
        (yyval.subprog) = create_subprogram_function((yyvsp[-7].ident), 0, (yyvsp[-1].decl), (yyvsp[0].stmt), (yyvsp[-3].type));
    }
#line 1610 "src/parser.c"
    break;

  case 30: /* subprogram-function: S_FUNCTION error  */
#line 349 "src/parser.y"
                      {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_FUNCTION_MALFORMED);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1622 "src/parser.c"
    break;

  case 31: /* subprogram-function-name: IDENT  */
#line 359 "src/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1630 "src/parser.c"
    break;

  case 32: /* subprogram-function-name: error  */
#line 363 "src/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_FUNCTION_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1642 "src/parser.c"
    break;

  case 33: /* list-parameters: parameter DELIM_C list-parameters  */
#line 373 "src/parser.y"
                                     {
        (yyval.param) = (yyvsp[-2].param);
        (yyvsp[-2].param)->next = (yyvsp[0].param);
    }
#line 1651 "src/parser.c"
    break;

  case 34: /* list-parameters: parameter  */
#line 377 "src/parser.y"
               {
        (yyval.param) = (yyvsp[0].param);
    }
#line 1659 "src/parser.c"
    break;

  case 35: /* parameter: parameter-name DELIM_2P type  */
#line 383 "src/parser.y"
                                {
        (yyval.param) = create_parameter_list((yyvsp[-2].ident), (yyvsp[0].type));
    }
#line 1667 "src/parser.c"
    break;

  case 36: /* parameter: parameter-name error type  */
#line 387 "src/parser.y"
                               {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_PARAMETER_DELIM2P);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1679 "src/parser.c"
    break;

  case 37: /* parameter-name: IDENT  */
#line 397 "src/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1687 "src/parser.c"
    break;

  case 38: /* parameter-name: error  */
#line 401 "src/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROC_PARAMETER_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1699 "src/parser.c"
    break;

  case 39: /* list-process: process  */
#line 412 "src/parser.y"
           {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 1707 "src/parser.c"
    break;

  case 40: /* list-process: process list-process  */
#line 415 "src/parser.y"
                          {
        (yyval.proc) = (yyvsp[-1].proc);
        (yyvsp[-1].proc)->next = (yyvsp[0].proc);
    }
#line 1716 "src/parser.c"
    break;

  case 41: /* process: process-def  */
#line 422 "src/parser.y"
               {
        (yyval.proc) = (yyvsp[0].proc);
    }
#line 1724 "src/parser.c"
    break;

  case 42: /* process-def: S_PROCESS process-name DELIM_PC list-declarations block-statement  */
#line 432 "src/parser.y"
                                                                     {
        (yyval.proc) = create_process((yyvsp[-3].ident), (yyvsp[-1].decl), (yyvsp[0].stmt));
    }
#line 1732 "src/parser.c"
    break;

  case 43: /* process-def: S_PROCESS process-name error list-declarations block-statement  */
#line 436 "src/parser.y"
                                                                    {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROCESS_DELIMPC);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1744 "src/parser.c"
    break;

  case 44: /* process-name: IDENT  */
#line 451 "src/parser.y"
         {
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1752 "src/parser.c"
    break;

  case 45: /* process-name: error  */
#line 455 "src/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_PROCESS_IDENT);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1764 "src/parser.c"
    break;

  case 46: /* type: T_INTEGER  */
#line 467 "src/parser.y"
             {
        (yyval.type) = create_basic_type(TYPE_INTEGER);
    }
#line 1772 "src/parser.c"
    break;

  case 47: /* type: T_BOOLEAN  */
#line 470 "src/parser.y"
               {
        (yyval.type) = create_basic_type(TYPE_BOOLEAN);
    }
#line 1780 "src/parser.c"
    break;

  case 48: /* type: T_CHAR  */
#line 473 "src/parser.y"
            {
        (yyval.type) = create_basic_type(TYPE_CHAR);
    }
#line 1788 "src/parser.c"
    break;

  case 49: /* type: T_STRING  */
#line 476 "src/parser.y"
              {
        (yyval.type) = create_basic_type(TYPE_STRING);
    }
#line 1796 "src/parser.c"
    break;

  case 50: /* type: T_REAL  */
#line 479 "src/parser.y"
            {
        (yyval.type) = create_basic_type(TYPE_REAL);
    }
#line 1804 "src/parser.c"
    break;

  case 51: /* type: T_ARRAY CORCH_IZDO expression CORCH_DCHO type  */
#line 482 "src/parser.y"
                                                   {
        (yyval.type) = create_array_type((yyvsp[0].type));
    }
#line 1812 "src/parser.c"
    break;

  case 52: /* type: T_SEMAPHORE  */
#line 485 "src/parser.y"
                 {
        (yyval.type) = create_semaphore_type();
    }
#line 1820 "src/parser.c"
    break;

  case 53: /* type: T_DPROCESS  */
#line 488 "src/parser.y"
                {
        (yyval.type) = create_dprocess_type();
    }
#line 1828 "src/parser.c"
    break;

  case 54: /* type: error  */
#line 492 "src/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_TYPE);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1840 "src/parser.c"
    break;

  case 55: /* list-statements: statement  */
#line 503 "src/parser.y"
             {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1848 "src/parser.c"
    break;

  case 56: /* list-statements: statement list-statements  */
#line 506 "src/parser.y"
                               {
        (yyval.stmt) = (yyvsp[-1].stmt);
        (yyvsp[-1].stmt)->next = (yyvsp[0].stmt);
    }
#line 1857 "src/parser.c"
    break;

  case 57: /* statement: block-statement  */
#line 513 "src/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1865 "src/parser.c"
    break;

  case 58: /* statement: cobegin-statement  */
#line 516 "src/parser.y"
                       {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1873 "src/parser.c"
    break;

  case 59: /* statement: assignment-statement  */
#line 519 "src/parser.y"
                          {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1881 "src/parser.c"
    break;

  case 60: /* statement: while-statement  */
#line 522 "src/parser.y"
                     {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1889 "src/parser.c"
    break;

  case 61: /* statement: for-statement  */
#line 525 "src/parser.y"
                   {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1897 "src/parser.c"
    break;

  case 62: /* statement: if-statement  */
#line 528 "src/parser.y"
                  {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1905 "src/parser.c"
    break;

  case 63: /* statement: procedure-invocation  */
#line 531 "src/parser.y"
                          {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1913 "src/parser.c"
    break;

  case 64: /* statement: fork-statement  */
#line 534 "src/parser.y"
                    {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1921 "src/parser.c"
    break;

  case 65: /* statement: atomic-statement  */
#line 537 "src/parser.y"
                      {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1929 "src/parser.c"
    break;

  case 66: /* statement: return-statement  */
#line 540 "src/parser.y"
                      {
        (yyval.stmt) = (yyvsp[0].stmt);
    }
#line 1937 "src/parser.c"
    break;

  case 67: /* statement: error  */
#line 543 "src/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_STMT_MALFORMED);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 1949 "src/parser.c"
    break;

  case 68: /* block-statement: B_BEGIN list-statements B_END  */
#line 553 "src/parser.y"
                                 {
        (yyval.stmt) = create_statement_block_begin((yyvsp[-1].stmt));
    }
#line 1957 "src/parser.c"
    break;

  case 69: /* cobegin-statement: B_COBEGIN list-statements B_COEND  */
#line 559 "src/parser.y"
                                     {
        (yyval.stmt) = create_statement_block_cobegin((yyvsp[-1].stmt));
    }
#line 1965 "src/parser.c"
    break;

  case 70: /* assignment-statement: IDENT OP_ASSIGN expression DELIM_PC  */
#line 566 "src/parser.y"
                                       {
        (yyval.stmt) = create_statement_assignment((yyvsp[-3].ident), (yyvsp[-1].expr));
    }
#line 1973 "src/parser.c"
    break;

  case 71: /* while-statement: WHILE expression DO block-statement  */
#line 574 "src/parser.y"
                                       {
        (yyval.stmt) = create_statement_while((yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 1981 "src/parser.c"
    break;

  case 72: /* for-statement: FOR IDENT OP_ASSIGN expression TO expression DO block-statement  */
#line 580 "src/parser.y"
                                                                   {
        (yyval.stmt) = create_statement_for((yyvsp[-6].ident), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt));
    }
#line 1989 "src/parser.c"
    break;

  case 73: /* if-statement: IF expression THEN block-statement  */
#line 586 "src/parser.y"
                                      {
        (yyval.stmt) = create_statement_if_else((yyvsp[-2].expr), (yyvsp[0].stmt), 0);
    }
#line 1997 "src/parser.c"
    break;

  case 74: /* if-statement: IF expression THEN block-statement ELSE block-statement  */
#line 589 "src/parser.y"
                                                             {
        (yyval.stmt) = create_statement_if_else((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt));
    }
#line 2005 "src/parser.c"
    break;

  case 75: /* fork-statement: S_FORK IDENT statement  */
#line 595 "src/parser.y"
                          {
        (yyval.stmt) = create_statement_fork((yyvsp[-1].ident), (yyvsp[0].stmt));
    }
#line 2013 "src/parser.c"
    break;

  case 76: /* atomic-statement: ATOM_INI list-statements ATOM_FIN  */
#line 601 "src/parser.y"
                                     {
        (yyval.stmt) = create_statement_atomic((yyvsp[-1].stmt));
    }
#line 2021 "src/parser.c"
    break;

  case 77: /* return-statement: RETURN expression DELIM_PC  */
#line 607 "src/parser.y"
                              {
        (yyval.stmt) = create_statement_return((yyvsp[-1].expr));
    }
#line 2029 "src/parser.c"
    break;

  case 78: /* procedure-invocation: IDENT PAR_IZDO list-arguments PAR_DCHO DELIM_PC  */
#line 614 "src/parser.y"
                                                   {
        (yyval.stmt) = create_statement_procedure_inv((yyvsp[-4].ident), (yyvsp[-2].expr));
    }
#line 2037 "src/parser.c"
    break;

  case 79: /* procedure-invocation: IDENT PAR_IZDO PAR_DCHO DELIM_PC  */
#line 617 "src/parser.y"
                                      {
        (yyval.stmt) = create_statement_procedure_inv((yyvsp[-3].ident), 0);
    }
#line 2045 "src/parser.c"
    break;

  case 80: /* function-invocation: IDENT PAR_IZDO list-arguments PAR_DCHO  */
#line 623 "src/parser.y"
                                          {
        (yyval.expr) = create_expression_function_invocation((yyvsp[-3].ident), (yyvsp[-1].expr));
    }
#line 2053 "src/parser.c"
    break;

  case 81: /* function-invocation: IDENT PAR_IZDO PAR_DCHO  */
#line 626 "src/parser.y"
                             {
        (yyval.expr) = create_expression_function_invocation((yyvsp[-2].ident), 0);
    }
#line 2061 "src/parser.c"
    break;

  case 82: /* list-arguments: argument DELIM_C list-arguments  */
#line 632 "src/parser.y"
                                   {
        (yyval.expr) = (yyvsp[-2].expr);
        (yyvsp[-2].expr)->next = (yyvsp[0].expr);
    }
#line 2070 "src/parser.c"
    break;

  case 83: /* list-arguments: argument  */
#line 636 "src/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2078 "src/parser.c"
    break;

  case 84: /* argument: expression  */
#line 642 "src/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2086 "src/parser.c"
    break;

  case 85: /* expression: binary-expression  */
#line 649 "src/parser.y"
                     {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2094 "src/parser.c"
    break;

  case 86: /* expression: unary-expression  */
#line 652 "src/parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2102 "src/parser.c"
    break;

  case 87: /* expression: term  */
#line 655 "src/parser.y"
          {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2110 "src/parser.c"
    break;

  case 88: /* binary-expression: term OP_SUM expression  */
#line 662 "src/parser.y"
                          {
        (yyval.expr) = create_expression_binary_operation(EXPR_ADD, "+", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2118 "src/parser.c"
    break;

  case 89: /* binary-expression: term OP_MINUS expression  */
#line 666 "src/parser.y"
                              {
        (yyval.expr) = create_expression_binary_operation(EXPR_SUB, "-", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2126 "src/parser.c"
    break;

  case 90: /* binary-expression: term OP_MULT expression  */
#line 670 "src/parser.y"
                             {
        (yyval.expr) = create_expression_binary_operation(EXPR_MULT, "*", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2134 "src/parser.c"
    break;

  case 91: /* binary-expression: term OP_DIV expression  */
#line 674 "src/parser.y"
                            {
        (yyval.expr) = create_expression_binary_operation(EXPR_DIV, "/", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2142 "src/parser.c"
    break;

  case 92: /* binary-expression: term OP_MOD expression  */
#line 678 "src/parser.y"
                            {
        (yyval.expr) = create_expression_binary_operation(EXPR_MOD, "%", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2150 "src/parser.c"
    break;

  case 93: /* binary-expression: term OP_REL_LT expression  */
#line 682 "src/parser.y"
                               {
        (yyval.expr) = create_expression_binary_operation(EXPR_LT, "<", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2158 "src/parser.c"
    break;

  case 94: /* binary-expression: term OP_REL_LTE expression  */
#line 686 "src/parser.y"
                                {
        (yyval.expr) = create_expression_binary_operation(EXPR_LTE, "<=", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2166 "src/parser.c"
    break;

  case 95: /* binary-expression: term OP_REL_GT expression  */
#line 690 "src/parser.y"
                               {
        (yyval.expr) = create_expression_binary_operation(EXPR_GT, ">", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2174 "src/parser.c"
    break;

  case 96: /* binary-expression: term OP_REL_GTE expression  */
#line 694 "src/parser.y"
                                {
        (yyval.expr) = create_expression_binary_operation(EXPR_GTE, ">=", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2182 "src/parser.c"
    break;

  case 97: /* binary-expression: term OP_REL_EQ expression  */
#line 698 "src/parser.y"
                               {
        (yyval.expr) = create_expression_binary_operation(EXPR_EQ, "==", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2190 "src/parser.c"
    break;

  case 98: /* binary-expression: term OP_REL_NEQ expression  */
#line 702 "src/parser.y"
                                {
        (yyval.expr) = create_expression_binary_operation(EXPR_NEQ, "!=", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2198 "src/parser.c"
    break;

  case 99: /* binary-expression: term OP_AND expression  */
#line 706 "src/parser.y"
                            {
        (yyval.expr) = create_expression_binary_operation(EXPR_AND, "and", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2206 "src/parser.c"
    break;

  case 100: /* binary-expression: term OP_OR expression  */
#line 710 "src/parser.y"
                           {
        (yyval.expr) = create_expression_binary_operation(EXPR_OR, "or", (yyvsp[-2].expr), (yyvsp[0].expr));
    }
#line 2214 "src/parser.c"
    break;

  case 101: /* binary-expression: error  */
#line 713 "src/parser.y"
           {
        // -- Mostrar error
        yyerror(PARSER_ERROR_MSG_EXPR_MALFORMED);

        // -- Abortar inmediatmente el analisis
        YYABORT;
    }
#line 2226 "src/parser.c"
    break;

  case 102: /* unary-expression: OP_NOT term  */
#line 724 "src/parser.y"
               {
        (yyval.expr) = create_expression_unary_operation(EXPR_NOT, "not", (yyvsp[0].expr));
    }
#line 2234 "src/parser.c"
    break;

  case 103: /* unary-expression: OP_MINUS term  */
#line 728 "src/parser.y"
                   {
        (yyval.expr) = create_expression_unary_operation(EXPR_NEGATIVE, "-", (yyvsp[0].expr));
    }
#line 2242 "src/parser.c"
    break;

  case 104: /* term: identifier  */
#line 734 "src/parser.y"
              {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2250 "src/parser.c"
    break;

  case 105: /* term: literal  */
#line 737 "src/parser.y"
             {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2258 "src/parser.c"
    break;

  case 106: /* term: function-invocation  */
#line 740 "src/parser.y"
                         {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2266 "src/parser.c"
    break;

  case 107: /* term: PAR_IZDO expression PAR_DCHO  */
#line 743 "src/parser.y"
                                  {
        (yyval.expr) = create_expression_grouped((yyvsp[-1].expr));
    }
#line 2274 "src/parser.c"
    break;

  case 108: /* literal: LITERAL  */
#line 750 "src/parser.y"
           {
        (yyval.expr) = create_expression_literal_string((yyvsp[0].literal_string));
    }
#line 2282 "src/parser.c"
    break;

  case 109: /* literal: L_INTEGER  */
#line 753 "src/parser.y"
               {
        (yyval.expr) = create_expression_literal_integer((yyvsp[0].literal_int));
    }
#line 2290 "src/parser.c"
    break;

  case 110: /* literal: L_BOOLEAN_TRUE  */
#line 756 "src/parser.y"
                    {
        (yyval.expr) = create_expression_literal_boolean(1);
    }
#line 2298 "src/parser.c"
    break;

  case 111: /* literal: L_BOOLEAN_FALSE  */
#line 759 "src/parser.y"
                     {
        (yyval.expr) = create_expression_literal_boolean(0);
    }
#line 2306 "src/parser.c"
    break;

  case 112: /* literal: L_CHAR  */
#line 762 "src/parser.y"
            {
        (yyval.expr) = create_expression_literal_char((yyvsp[0].literal_char));
    }
#line 2314 "src/parser.c"
    break;

  case 113: /* literal: L_REAL  */
#line 765 "src/parser.y"
            {
        (yyval.expr) = create_expression_literal_real((yyvsp[0].literal_float));
    }
#line 2322 "src/parser.c"
    break;

  case 114: /* identifier: IDENT  */
#line 771 "src/parser.y"
         {
        (yyval.expr) = create_expression_identifier((yyvsp[0].ident));
    }
#line 2330 "src/parser.c"
    break;


#line 2334 "src/parser.c"

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

#line 776 "src/parser.y"


// Soporte de las rutinas en C


void yyerror(const char *s) {
    if(strcmp(s, "syntax error") != 0)
        fprintf(stderr, "--- Error de sintaxis en la línea %d -> %s\n", yylineno, s);
}
