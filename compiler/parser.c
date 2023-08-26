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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "colors.h"

extern int yylex();
extern char *yytext;
extern int line;

void yyerror(char *s);

struct decl *parser_result;

#line 87 "parser.c"

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
  YYSYMBOL_TOKEN_PRINT_IN = 3,             /* TOKEN_PRINT_IN  */
  YYSYMBOL_TOKEN_STDIN = 4,                /* TOKEN_STDIN  */
  YYSYMBOL_TOKEN_ALLOCATE = 5,             /* TOKEN_ALLOCATE  */
  YYSYMBOL_TOKEN_SUBSCRIPT = 6,            /* TOKEN_SUBSCRIPT  */
  YYSYMBOL_TOKEN_UP = 7,                   /* TOKEN_UP  */
  YYSYMBOL_TOKEN_AND = 8,                  /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 9,                   /* TOKEN_OR  */
  YYSYMBOL_TOKEN_NOT = 10,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_UNKNOWN = 11,             /* TOKEN_UNKNOWN  */
  YYSYMBOL_TOKEN_GIVE = 12,                /* TOKEN_GIVE  */
  YYSYMBOL_TOKEN_IF = 13,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 14,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_WHILE = 15,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_FOR = 16,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_DO = 17,                  /* TOKEN_DO  */
  YYSYMBOL_TOKEN_CHAR = 18,                /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_INT = 19,                 /* TOKEN_INT  */
  YYSYMBOL_TOKEN_FLOAT = 20,               /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_BOOL = 21,                /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_VOID = 22,                /* TOKEN_VOID  */
  YYSYMBOL_TOKEN_TRUE = 23,                /* TOKEN_TRUE  */
  YYSYMBOL_TOKEN_FALSE = 24,               /* TOKEN_FALSE  */
  YYSYMBOL_TOKEN_CHAR_LITERAL = 25,        /* TOKEN_CHAR_LITERAL  */
  YYSYMBOL_TOKEN_INTEGER_LITERAL = 26,     /* TOKEN_INTEGER_LITERAL  */
  YYSYMBOL_TOKEN_FLOATING_POINT_LITERAL = 27, /* TOKEN_FLOATING_POINT_LITERAL  */
  YYSYMBOL_TOKEN_IDENT = 28,               /* TOKEN_IDENT  */
  YYSYMBOL_TOKEN_STRING_LITERAL = 29,      /* TOKEN_STRING_LITERAL  */
  YYSYMBOL_TOKEN_PLUS = 30,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 31,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MUL = 32,                 /* TOKEN_MUL  */
  YYSYMBOL_TOKEN_DIV = 33,                 /* TOKEN_DIV  */
  YYSYMBOL_TOKEN_MODULUS = 34,             /* TOKEN_MODULUS  */
  YYSYMBOL_TOKEN_ASSIGN = 35,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_EQUAL = 36,               /* TOKEN_EQUAL  */
  YYSYMBOL_TOKEN_NOT_EQUAL = 37,           /* TOKEN_NOT_EQUAL  */
  YYSYMBOL_TOKEN_GREATER = 38,             /* TOKEN_GREATER  */
  YYSYMBOL_TOKEN_GREATER_EQUAL = 39,       /* TOKEN_GREATER_EQUAL  */
  YYSYMBOL_TOKEN_LESS = 40,                /* TOKEN_LESS  */
  YYSYMBOL_TOKEN_LESS_EQUAL = 41,          /* TOKEN_LESS_EQUAL  */
  YYSYMBOL_TOKEN_INCREMENT = 42,           /* TOKEN_INCREMENT  */
  YYSYMBOL_TOKEN_DECREMENT = 43,           /* TOKEN_DECREMENT  */
  YYSYMBOL_TOKEN_ADD_WITH = 44,            /* TOKEN_ADD_WITH  */
  YYSYMBOL_TOKEN_SUB_WITH = 45,            /* TOKEN_SUB_WITH  */
  YYSYMBOL_TOKEN_MUL_WITH = 46,            /* TOKEN_MUL_WITH  */
  YYSYMBOL_TOKEN_DIV_WITH = 47,            /* TOKEN_DIV_WITH  */
  YYSYMBOL_TOKEN_LPAREN = 48,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 49,              /* TOKEN_RPAREN  */
  YYSYMBOL_TOKEN_LCRBR = 50,               /* TOKEN_LCRBR  */
  YYSYMBOL_TOKEN_RCRBR = 51,               /* TOKEN_RCRBR  */
  YYSYMBOL_TOKEN_LSQBR = 52,               /* TOKEN_LSQBR  */
  YYSYMBOL_TOKEN_RSQBR = 53,               /* TOKEN_RSQBR  */
  YYSYMBOL_TOKEN_COMMA = 54,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_COLON = 55,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_SEMI = 56,                /* TOKEN_SEMI  */
  YYSYMBOL_TOKEN_ERROR = 57,               /* TOKEN_ERROR  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_decl = 60,                      /* decl  */
  YYSYMBOL_decl_list = 61,                 /* decl_list  */
  YYSYMBOL_stmt = 62,                      /* stmt  */
  YYSYMBOL_stmt_list = 63,                 /* stmt_list  */
  YYSYMBOL_term = 64,                      /* term  */
  YYSYMBOL_assignment_algebra = 65,        /* assignment_algebra  */
  YYSYMBOL_algebra = 66,                   /* algebra  */
  YYSYMBOL_starting_expr = 67,             /* starting_expr  */
  YYSYMBOL_factor = 68,                    /* factor  */
  YYSYMBOL_comparison_algebra = 69,        /* comparison_algebra  */
  YYSYMBOL_logical_algebra = 70,           /* logical_algebra  */
  YYSYMBOL_expr = 71,                      /* expr  */
  YYSYMBOL_expr_list = 72,                 /* expr_list  */
  YYSYMBOL_next_expr = 73,                 /* next_expr  */
  YYSYMBOL_name = 74,                      /* name  */
  YYSYMBOL_string_literal = 75,            /* string_literal  */
  YYSYMBOL_boolean_literal = 76,           /* boolean_literal  */
  YYSYMBOL_char_literal = 77,              /* char_literal  */
  YYSYMBOL_allocation_size = 78,           /* allocation_size  */
  YYSYMBOL_parameter = 79,                 /* parameter  */
  YYSYMBOL_parameters = 80,                /* parameters  */
  YYSYMBOL_list_of_parameters = 81,        /* list_of_parameters  */
  YYSYMBOL_type = 82                       /* type  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   284

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   109,   111,   113,   118,   125,   131,   140,
     141,   144,   146,   148,   151,   153,   154,   156,   158,   160,
     168,   169,   172,   173,   174,   176,   180,   182,   184,   186,
     188,   190,   191,   192,   193,   196,   197,   198,   199,   203,
     204,   205,   209,   210,   211,   213,   214,   215,   216,   218,
     219,   221,   223,   228,   229,   230,   231,   232,   233,   237,
     238,   241,   242,   246,   247,   251,   252,   255,   263,   271,
     272,   276,   284,   285,   289,   294,   296,   300,   301,   304,
     305,   306,   307,   308
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_PRINT_IN",
  "TOKEN_STDIN", "TOKEN_ALLOCATE", "TOKEN_SUBSCRIPT", "TOKEN_UP",
  "TOKEN_AND", "TOKEN_OR", "TOKEN_NOT", "TOKEN_UNKNOWN", "TOKEN_GIVE",
  "TOKEN_IF", "TOKEN_ELSE", "TOKEN_WHILE", "TOKEN_FOR", "TOKEN_DO",
  "TOKEN_CHAR", "TOKEN_INT", "TOKEN_FLOAT", "TOKEN_BOOL", "TOKEN_VOID",
  "TOKEN_TRUE", "TOKEN_FALSE", "TOKEN_CHAR_LITERAL",
  "TOKEN_INTEGER_LITERAL", "TOKEN_FLOATING_POINT_LITERAL", "TOKEN_IDENT",
  "TOKEN_STRING_LITERAL", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MUL",
  "TOKEN_DIV", "TOKEN_MODULUS", "TOKEN_ASSIGN", "TOKEN_EQUAL",
  "TOKEN_NOT_EQUAL", "TOKEN_GREATER", "TOKEN_GREATER_EQUAL", "TOKEN_LESS",
  "TOKEN_LESS_EQUAL", "TOKEN_INCREMENT", "TOKEN_DECREMENT",
  "TOKEN_ADD_WITH", "TOKEN_SUB_WITH", "TOKEN_MUL_WITH", "TOKEN_DIV_WITH",
  "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LCRBR", "TOKEN_RCRBR",
  "TOKEN_LSQBR", "TOKEN_RSQBR", "TOKEN_COMMA", "TOKEN_COLON", "TOKEN_SEMI",
  "TOKEN_ERROR", "$accept", "program", "decl", "decl_list", "stmt",
  "stmt_list", "term", "assignment_algebra", "algebra", "starting_expr",
  "factor", "comparison_algebra", "logical_algebra", "expr", "expr_list",
  "next_expr", "name", "string_literal", "boolean_literal", "char_literal",
  "allocation_size", "parameter", "parameters", "list_of_parameters",
  "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,  -111,    28,     1,  -111,   -17,  -111,  -111,    55,  -111,
    -111,  -111,  -111,  -111,   -12,     3,    29,   202,     1,  -111,
    -111,  -111,   -20,   228,  -111,  -111,  -111,  -111,  -111,  -111,
     228,     1,     1,   202,    36,  -111,   230,  -111,  -111,  -111,
    -111,     2,   122,  -111,  -111,  -111,    14,    -6,    31,    -3,
    -111,  -111,     8,  -111,  -111,  -111,    13,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
    -111,   228,   202,  -111,  -111,   228,   228,   228,   228,   202,
      55,     1,  -111,    -1,   202,    22,  -111,  -111,  -111,  -111,
      36,    36,    36,    36,    36,    36,    36,    36,   230,   230,
    -111,  -111,   230,   136,   230,   230,   230,   230,    -4,    33,
      30,  -111,   193,    35,  -111,   228,   202,  -111,  -111,  -111,
     165,     5,    39,   193,  -111,   193,    40,     4,    58,    38,
    -111,    43,    -2,   202,   202,    56,  -111,  -111,  -111,  -111,
    -111,   104,  -111,    16,    53,  -111,    57,   193,   202,  -111,
      97,    11,   193,   202,  -111,    65,   193,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      10,    67,     0,    10,     2,     0,     1,     9,     0,    80,
      79,    82,    81,    83,     0,     0,     0,     0,    76,     3,
      73,    72,     0,     0,    69,    70,    71,    43,    44,    68,
       0,     0,     0,     0,    38,    39,    62,    61,    25,    37,
      40,     0,    42,    45,    46,    47,     0,    78,     0,     0,
       5,    49,    42,    48,    33,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     0,    31,    32,     0,     0,     0,     0,    64,
       0,    76,    75,     0,    64,     0,    52,    22,    23,    24,
      35,    36,    53,    54,    56,    58,    55,    57,    59,    60,
      51,    41,    26,    42,    27,    28,    29,    30,    66,     0,
       0,    77,    21,     0,     6,     0,    64,    63,    50,    74,
       0,     0,     0,    21,    15,    21,     0,     0,    42,     0,
      65,     0,     0,     0,    64,     0,    20,     8,    16,     7,
      18,     0,    17,     0,     0,    14,     0,     0,     0,    19,
      11,     0,     0,    64,    12,     0,     0,    13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,    27,   112,  -110,   -62,   217,    45,    20,  -111,
     -14,  -111,  -111,     6,   -82,  -111,     0,    69,  -111,  -111,
    -111,  -111,    46,  -111,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,   124,     4,   125,   126,    34,    35,    36,    37,
      38,    39,    40,   127,   109,   117,    52,    43,    44,    45,
      22,    47,    48,    82,    14
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       5,   141,   113,     5,    68,    69,    68,    69,    16,    51,
      68,    69,    68,    69,    71,    49,    53,    42,    46,    68,
      69,    68,    69,    41,    68,    69,    29,     3,     6,     1,
       3,    54,    55,    42,   130,     8,    50,   150,    17,    56,
      20,    15,   154,    87,    88,    89,   157,    84,    81,   112,
     116,    18,   144,   133,   142,    21,    79,   100,    70,    19,
     138,   135,    86,   136,    71,   147,    80,   153,    57,    58,
      59,   155,   103,     9,    10,    11,    12,    13,   114,    42,
      83,    46,   118,   119,    42,   108,   129,   134,    98,    99,
     108,   137,   102,    72,   139,   104,   105,   106,   107,   140,
      73,    74,    75,    76,    77,    78,    79,   145,   146,   148,
       8,   152,   128,   149,   156,     7,    42,   101,    85,     0,
      42,   110,   108,   128,     0,   128,   132,   111,    71,     0,
       0,     0,     0,    42,    42,   102,     0,     0,     0,   143,
     108,     0,    71,     0,     0,     0,     0,   128,    42,     0,
       0,     0,   128,    42,   151,     0,   128,    72,     0,   108,
       0,     0,     0,     0,    73,    74,    75,    76,    77,    78,
      79,   115,   131,     0,     0,    23,     0,     0,    73,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    24,    25,
      26,    27,    28,     1,    29,     0,    30,     0,     0,     0,
       0,     0,     0,    23,     0,   120,   121,    31,    32,   122,
       0,     0,    23,    33,     0,     0,    24,    25,    26,    27,
      28,     1,    29,     0,    30,    24,    25,    26,    27,    28,
       1,    29,     0,    30,     0,    31,    32,     0,    23,     0,
       0,    33,     0,   123,    31,    32,     0,     0,     0,     0,
      33,    24,    25,    26,    27,    28,     1,    29,     0,    30,
      60,    61,     0,     0,     0,     0,    62,    63,    64,    65,
      66,    67,     0,     0,     0,     0,    33,    90,    91,    92,
      93,    94,    95,    96,    97
};

static const yytype_int16 yycheck[] =
{
       0,     3,    84,     3,     8,     9,     8,     9,     5,    23,
       8,     9,     8,     9,     6,    35,    30,    17,    18,     8,
       9,     8,     9,    17,     8,     9,    29,     0,     0,    28,
       3,    31,    32,    33,   116,    52,    56,   147,    35,    33,
      11,    53,   152,    57,    58,    59,   156,    50,    54,    50,
      54,    48,   134,    48,    56,    26,    48,    71,    56,    56,
      56,   123,    49,   125,     6,    49,    52,    56,    32,    33,
      34,   153,    72,    18,    19,    20,    21,    22,    56,    79,
      49,    81,    49,    53,    84,    79,    51,    48,    68,    69,
      84,    51,    72,    35,    56,    75,    76,    77,    78,    56,
      42,    43,    44,    45,    46,    47,    48,    51,     4,    56,
      52,    14,   112,    56,    49,     3,   116,    72,    49,    -1,
     120,    80,   116,   123,    -1,   125,   120,    81,     6,    -1,
      -1,    -1,    -1,   133,   134,   115,    -1,    -1,    -1,   133,
     134,    -1,     6,    -1,    -1,    -1,    -1,   147,   148,    -1,
      -1,    -1,   152,   153,   148,    -1,   156,    35,    -1,   153,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    35,     7,    -1,    -1,    10,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,    12,    13,    42,    43,    16,
      -1,    -1,    10,    48,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    -1,    42,    43,    -1,    10,    -1,
      -1,    48,    -1,    50,    42,    43,    -1,    -1,    -1,    -1,
      48,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      30,    31,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    48,    60,    61,    62,
      63,    64,    65,    66,    67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    59,    60,    61,    74,     0,    61,    52,    18,
      19,    20,    21,    22,    82,    53,     5,    35,    48,    56,
      11,    26,    78,    10,    23,    24,    25,    26,    27,    29,
      31,    42,    43,    48,    64,    65,    66,    67,    68,    69,
      70,    71,    74,    75,    76,    77,    74,    79,    80,    35,
      56,    68,    74,    68,    74,    74,    71,    32,    33,    34,
      30,    31,    36,    37,    38,    39,    40,    41,     8,     9,
      56,     6,    35,    42,    43,    44,    45,    46,    47,    48,
      52,    54,    81,    49,    50,    75,    49,    68,    68,    68,
      64,    64,    64,    64,    64,    64,    64,    64,    66,    66,
      68,    65,    66,    74,    66,    66,    66,    66,    71,    72,
      82,    80,    50,    72,    56,    35,    54,    73,    49,    53,
      12,    13,    16,    50,    60,    62,    63,    71,    74,    51,
      72,     7,    71,    48,    48,    63,    63,    51,    56,    56,
      56,     3,    56,    71,    72,    51,     4,    49,    56,    56,
      62,    71,    14,    56,    62,    72,    49,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    66,    66,    67,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    69,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    75,    76,
      76,    77,    78,    78,    79,    80,    80,    81,    81,    82,
      82,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     7,     7,     9,    11,    10,     2,
       0,     5,     7,     9,     3,     1,     2,     3,     3,     5,
       2,     0,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     3,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     2,     2,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     2,     0,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     4,     2,     0,     2,     0,     1,
       1,     1,     1,     1
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
  case 2: /* program: decl_list  */
#line 106 "parser.y"
                    {parser_result = (yyvsp[0].decl);}
#line 1295 "parser.c"
    break;

  case 3: /* decl: name TOKEN_LSQBR type TOKEN_RSQBR TOKEN_SEMI  */
#line 110 "parser.y"
            { (yyval.decl) = decl_create((yyvsp[-4].name), (yyvsp[-2].type), 0, 0, 0); }
#line 1301 "parser.c"
    break;

  case 4: /* decl: name TOKEN_LSQBR type TOKEN_RSQBR TOKEN_ASSIGN expr TOKEN_SEMI  */
#line 112 "parser.y"
            { (yyval.decl) = decl_create((yyvsp[-6].name), (yyvsp[-4].type), (yyvsp[-1].expr), 0, 0); }
#line 1307 "parser.c"
    break;

  case 5: /* decl: name TOKEN_LSQBR type TOKEN_RSQBR TOKEN_ALLOCATE allocation_size TOKEN_SEMI  */
#line 114 "parser.y"
            {
                struct type *temp = type_create(TYPE_ARRAY, (yyvsp[-4].type), 0, (yyvsp[-1].integer));
                (yyval.decl) = decl_create((yyvsp[-6].name), temp, 0, 0, 0); 
            }
#line 1316 "parser.c"
    break;

  case 6: /* decl: name TOKEN_LSQBR type TOKEN_RSQBR TOKEN_ALLOCATE allocation_size TOKEN_ASSIGN string_literal TOKEN_SEMI  */
#line 120 "parser.y"
            {
                struct type *temp = type_create(TYPE_ARRAY, (yyvsp[-6].type), 0, (yyvsp[-3].integer));
                struct expr *e = expr_create_string_literal((yyvsp[-1].name));
                (yyval.decl) = decl_create((yyvsp[-8].name), temp, e, 0, 0); 
            }
#line 1326 "parser.c"
    break;

  case 7: /* decl: name TOKEN_LSQBR type TOKEN_RSQBR TOKEN_ALLOCATE allocation_size TOKEN_ASSIGN TOKEN_LCRBR expr_list TOKEN_RCRBR TOKEN_SEMI  */
#line 127 "parser.y"
            {
                struct type *temp = type_create(TYPE_ARRAY, (yyvsp[-8].type), 0, (yyvsp[-5].integer));
                (yyval.decl) = decl_create((yyvsp[-10].name), temp, (yyvsp[-2].expr), 0, 0); 
            }
#line 1335 "parser.c"
    break;

  case 8: /* decl: name TOKEN_LSQBR type TOKEN_RSQBR TOKEN_LPAREN parameters TOKEN_RPAREN TOKEN_LCRBR stmt_list TOKEN_RCRBR  */
#line 133 "parser.y"
            {
                struct type *temp = type_create(TYPE_FUNCTION, (yyvsp[-7].type), (yyvsp[-4].params), 0);
                (yyval.decl) = decl_create((yyvsp[-9].name), temp, 0, (yyvsp[-1].stmt), 0); 
            }
#line 1344 "parser.c"
    break;

  case 9: /* decl_list: decl decl_list  */
#line 140 "parser.y"
                            { (yyval.decl) = (yyvsp[-1].decl); (yyvsp[-1].decl)->next = (yyvsp[0].decl); }
#line 1350 "parser.c"
    break;

  case 10: /* decl_list: %empty  */
#line 141 "parser.y"
                            { (yyval.decl) = 0; }
#line 1356 "parser.c"
    break;

  case 11: /* stmt: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt  */
#line 145 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-2].expr), 0, (yyvsp[0].stmt), 0, 0); }
#line 1362 "parser.c"
    break;

  case 12: /* stmt: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt TOKEN_ELSE stmt  */
#line 147 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt), 0); }
#line 1368 "parser.c"
    break;

  case 13: /* stmt: TOKEN_FOR TOKEN_LPAREN expr_list TOKEN_SEMI expr TOKEN_SEMI expr_list TOKEN_RPAREN stmt  */
#line 150 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), 0, 0); }
#line 1374 "parser.c"
    break;

  case 14: /* stmt: TOKEN_LCRBR stmt_list TOKEN_RCRBR  */
#line 152 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_BLOCK, 0, 0, 0, 0, (yyvsp[-1].stmt), 0, 0); }
#line 1380 "parser.c"
    break;

  case 15: /* stmt: decl  */
#line 153 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), 0, 0, 0, 0, 0, 0); }
#line 1386 "parser.c"
    break;

  case 16: /* stmt: expr TOKEN_SEMI  */
#line 155 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1392 "parser.c"
    break;

  case 17: /* stmt: TOKEN_GIVE expr TOKEN_SEMI  */
#line 157 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_GIVE, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1398 "parser.c"
    break;

  case 18: /* stmt: TOKEN_GIVE TOKEN_UP TOKEN_SEMI  */
#line 159 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_GIVE, 0, 0, 0, 0, 0, 0, 0); }
#line 1404 "parser.c"
    break;

  case 19: /* stmt: TOKEN_GIVE expr TOKEN_PRINT_IN TOKEN_STDIN TOKEN_SEMI  */
#line 161 "parser.y"
                { 
                        (yyval.stmt) = stmt_create(STMT_GIVE, 0, 0, (yyvsp[-3].expr), 0, 0, 0, 0); 
                        (yyval.stmt)->print = 1; 
                }
#line 1413 "parser.c"
    break;

  case 20: /* stmt_list: stmt stmt_list  */
#line 168 "parser.y"
                                { (yyval.stmt) = (yyvsp[-1].stmt); (yyvsp[-1].stmt)->next = (yyvsp[0].stmt); }
#line 1419 "parser.c"
    break;

  case 21: /* stmt_list: %empty  */
#line 169 "parser.y"
                                { (yyval.stmt) = 0; }
#line 1425 "parser.c"
    break;

  case 22: /* term: term TOKEN_MUL factor  */
#line 172 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1431 "parser.c"
    break;

  case 23: /* term: term TOKEN_DIV factor  */
#line 173 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1437 "parser.c"
    break;

  case 24: /* term: term TOKEN_MODULUS factor  */
#line 175 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_MODULUS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1443 "parser.c"
    break;

  case 25: /* term: factor  */
#line 176 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1449 "parser.c"
    break;

  case 26: /* assignment_algebra: name TOKEN_ASSIGN algebra  */
#line 181 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_ASSIGN, expr_create_name((yyvsp[-2].name)), (yyvsp[0].expr)); }
#line 1455 "parser.c"
    break;

  case 27: /* assignment_algebra: name TOKEN_ADD_WITH algebra  */
#line 183 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_ADD_WITH, expr_create_name((yyvsp[-2].name)), (yyvsp[0].expr)); }
#line 1461 "parser.c"
    break;

  case 28: /* assignment_algebra: name TOKEN_SUB_WITH algebra  */
#line 185 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_SUB_WITH, expr_create_name((yyvsp[-2].name)), (yyvsp[0].expr)); }
#line 1467 "parser.c"
    break;

  case 29: /* assignment_algebra: name TOKEN_MUL_WITH algebra  */
#line 187 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_MUL_WITH, expr_create_name((yyvsp[-2].name)), (yyvsp[0].expr)); }
#line 1473 "parser.c"
    break;

  case 30: /* assignment_algebra: name TOKEN_DIV_WITH algebra  */
#line 189 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_DIV_WITH, expr_create_name((yyvsp[-2].name)), (yyvsp[0].expr)); }
#line 1479 "parser.c"
    break;

  case 31: /* assignment_algebra: name TOKEN_INCREMENT  */
#line 190 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_INCREMENT, expr_create_name((yyvsp[-1].name)), 0); }
#line 1485 "parser.c"
    break;

  case 32: /* assignment_algebra: name TOKEN_DECREMENT  */
#line 191 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_DECREMENT, expr_create_name((yyvsp[-1].name)), 0); }
#line 1491 "parser.c"
    break;

  case 33: /* assignment_algebra: TOKEN_INCREMENT name  */
#line 192 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_INCREMENT, 0, expr_create_name((yyvsp[0].name))); }
#line 1497 "parser.c"
    break;

  case 34: /* assignment_algebra: TOKEN_DECREMENT name  */
#line 193 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_DECREMENT, 0, expr_create_name((yyvsp[0].name))); }
#line 1503 "parser.c"
    break;

  case 35: /* algebra: algebra TOKEN_PLUS term  */
#line 196 "parser.y"
                                        { (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1509 "parser.c"
    break;

  case 36: /* algebra: algebra TOKEN_MINUS term  */
#line 197 "parser.y"
                                        { (yyval.expr) = expr_create(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1515 "parser.c"
    break;

  case 37: /* algebra: comparison_algebra  */
#line 198 "parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1521 "parser.c"
    break;

  case 38: /* algebra: term  */
#line 199 "parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1527 "parser.c"
    break;

  case 39: /* starting_expr: assignment_algebra  */
#line 203 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1533 "parser.c"
    break;

  case 40: /* starting_expr: logical_algebra  */
#line 204 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1539 "parser.c"
    break;

  case 41: /* starting_expr: name TOKEN_ASSIGN assignment_algebra  */
#line 206 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_ASSIGN, expr_create_name((yyvsp[-2].name)), (yyvsp[0].expr)); }
#line 1545 "parser.c"
    break;

  case 42: /* factor: name  */
#line 209 "parser.y"
                                { (yyval.expr) = expr_create_name((yyvsp[0].name)); }
#line 1551 "parser.c"
    break;

  case 43: /* factor: TOKEN_INTEGER_LITERAL  */
#line 210 "parser.y"
                                { (yyval.expr) = expr_create_integer_literal(atoi(yytext)); }
#line 1557 "parser.c"
    break;

  case 44: /* factor: TOKEN_FLOATING_POINT_LITERAL  */
#line 212 "parser.y"
                                { (yyval.expr) = expr_create_floating_point_literal(atof(yytext)); }
#line 1563 "parser.c"
    break;

  case 45: /* factor: string_literal  */
#line 213 "parser.y"
                                { (yyval.expr) = expr_create_string_literal((yyvsp[0].name)); }
#line 1569 "parser.c"
    break;

  case 46: /* factor: boolean_literal  */
#line 214 "parser.y"
                                { (yyval.expr) = expr_create_boolean_literal((yyvsp[0].integer)); }
#line 1575 "parser.c"
    break;

  case 47: /* factor: char_literal  */
#line 215 "parser.y"
                                { (yyval.expr) = expr_create_char_literal((yyvsp[0].integer)); }
#line 1581 "parser.c"
    break;

  case 48: /* factor: TOKEN_MINUS factor  */
#line 217 "parser.y"
                { (yyval.expr) = expr_create(EXPR_MUL, expr_create_integer_literal(-1), (yyvsp[0].expr)); }
#line 1587 "parser.c"
    break;

  case 49: /* factor: TOKEN_NOT factor  */
#line 218 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_NOT, (yyvsp[0].expr), 0); }
#line 1593 "parser.c"
    break;

  case 50: /* factor: name TOKEN_LPAREN expr_list TOKEN_RPAREN  */
#line 220 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_CALL, expr_create_name((yyvsp[-3].name)), (yyvsp[-1].expr)); }
#line 1599 "parser.c"
    break;

  case 51: /* factor: name TOKEN_SUBSCRIPT factor  */
#line 222 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_SUBSCRIPT, expr_create_name((yyvsp[-2].name)), (yyvsp[0].expr)); }
#line 1605 "parser.c"
    break;

  case 52: /* factor: TOKEN_LPAREN expr TOKEN_RPAREN  */
#line 224 "parser.y"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1611 "parser.c"
    break;

  case 53: /* comparison_algebra: algebra TOKEN_EQUAL term  */
#line 228 "parser.y"
                                           { (yyval.expr) = expr_create(EXPR_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1617 "parser.c"
    break;

  case 54: /* comparison_algebra: algebra TOKEN_NOT_EQUAL term  */
#line 229 "parser.y"
                                           { (yyval.expr) = expr_create(EXPR_NOT_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1623 "parser.c"
    break;

  case 55: /* comparison_algebra: algebra TOKEN_LESS term  */
#line 230 "parser.y"
                                           { (yyval.expr) = expr_create(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1629 "parser.c"
    break;

  case 56: /* comparison_algebra: algebra TOKEN_GREATER term  */
#line 231 "parser.y"
                                           { (yyval.expr) = expr_create(EXPR_GREATER, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1635 "parser.c"
    break;

  case 57: /* comparison_algebra: algebra TOKEN_LESS_EQUAL term  */
#line 232 "parser.y"
                                           { (yyval.expr) = expr_create(EXPR_LESS_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1641 "parser.c"
    break;

  case 58: /* comparison_algebra: algebra TOKEN_GREATER_EQUAL term  */
#line 233 "parser.y"
                                           { (yyval.expr) = expr_create(EXPR_GREATER_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1647 "parser.c"
    break;

  case 59: /* logical_algebra: expr TOKEN_AND algebra  */
#line 237 "parser.y"
                                   { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1653 "parser.c"
    break;

  case 60: /* logical_algebra: expr TOKEN_OR algebra  */
#line 238 "parser.y"
                                   { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1659 "parser.c"
    break;

  case 61: /* expr: starting_expr  */
#line 241 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1665 "parser.c"
    break;

  case 62: /* expr: algebra  */
#line 242 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1671 "parser.c"
    break;

  case 63: /* expr_list: expr next_expr  */
#line 246 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 1677 "parser.c"
    break;

  case 64: /* expr_list: %empty  */
#line 247 "parser.y"
                                { (yyval.expr) = 0; }
#line 1683 "parser.c"
    break;

  case 65: /* next_expr: TOKEN_COMMA expr_list  */
#line 251 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1689 "parser.c"
    break;

  case 66: /* next_expr: %empty  */
#line 252 "parser.y"
                                { (yyval.expr) = 0; }
#line 1695 "parser.c"
    break;

  case 67: /* name: TOKEN_IDENT  */
#line 255 "parser.y"
                        {
                                char *temp = (char *)malloc(strlen(yytext)*sizeof(char));
                                strcpy(temp, yytext);
                                (yyval.name) = temp; 
                        }
#line 1705 "parser.c"
    break;

  case 68: /* string_literal: TOKEN_STRING_LITERAL  */
#line 263 "parser.y"
                                { 
                                char *temp = (char *)malloc(strlen(yytext)*sizeof(char));
                                strcpy(temp, yytext);
                                (yyval.name) = temp; 
                                }
#line 1715 "parser.c"
    break;

  case 69: /* boolean_literal: TOKEN_TRUE  */
#line 271 "parser.y"
                                { (yyval.integer) = 1; }
#line 1721 "parser.c"
    break;

  case 70: /* boolean_literal: TOKEN_FALSE  */
#line 272 "parser.y"
                                { (yyval.integer) = 0; }
#line 1727 "parser.c"
    break;

  case 71: /* char_literal: TOKEN_CHAR_LITERAL  */
#line 276 "parser.y"
                                {
                                char *temp = (char *)malloc(sizeof(char));
                                *temp = yytext[1];
                                (yyval.integer) = *temp;
                                }
#line 1737 "parser.c"
    break;

  case 72: /* allocation_size: TOKEN_INTEGER_LITERAL  */
#line 284 "parser.y"
                                { (yyval.integer) = atoi(yytext); }
#line 1743 "parser.c"
    break;

  case 73: /* allocation_size: TOKEN_UNKNOWN  */
#line 285 "parser.y"
                                { (yyval.integer) = 0; }
#line 1749 "parser.c"
    break;

  case 74: /* parameter: name TOKEN_LSQBR type TOKEN_RSQBR  */
#line 290 "parser.y"
            { (yyval.params) = param_list_create((yyvsp[-3].name), (yyvsp[-1].type), 0); }
#line 1755 "parser.c"
    break;

  case 75: /* parameters: parameter list_of_parameters  */
#line 295 "parser.y"
            { (yyval.params) = (yyvsp[-1].params); (yyvsp[-1].params)->next = (yyvsp[0].params); }
#line 1761 "parser.c"
    break;

  case 76: /* parameters: %empty  */
#line 296 "parser.y"
            { (yyval.params) = 0; }
#line 1767 "parser.c"
    break;

  case 77: /* list_of_parameters: TOKEN_COMMA parameters  */
#line 300 "parser.y"
                                    { (yyval.params) = (yyvsp[0].params); }
#line 1773 "parser.c"
    break;

  case 78: /* list_of_parameters: %empty  */
#line 301 "parser.y"
                                    { (yyval.params) = 0; }
#line 1779 "parser.c"
    break;

  case 79: /* type: TOKEN_INT  */
#line 304 "parser.y"
                        { (yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0); }
#line 1785 "parser.c"
    break;

  case 80: /* type: TOKEN_CHAR  */
#line 305 "parser.y"
                        { (yyval.type) = type_create(TYPE_CHARACTER, 0, 0, 0); }
#line 1791 "parser.c"
    break;

  case 81: /* type: TOKEN_BOOL  */
#line 306 "parser.y"
                        { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0); }
#line 1797 "parser.c"
    break;

  case 82: /* type: TOKEN_FLOAT  */
#line 307 "parser.y"
                        { (yyval.type) = type_create(TYPE_FLOATING_POINT, 0, 0, 0); }
#line 1803 "parser.c"
    break;

  case 83: /* type: TOKEN_VOID  */
#line 308 "parser.y"
                        { (yyval.type) = type_create(TYPE_VOID, 0, 0, 0); }
#line 1809 "parser.c"
    break;


#line 1813 "parser.c"

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

#line 311 "parser.y"


void yyerror(char *s) {
    fprintf(stderr, RED "Error" RESET \
        MAG" |%s|"RESET"->"YEL"|%s|"RESET" on line %d \n", s, yytext, line);
}
