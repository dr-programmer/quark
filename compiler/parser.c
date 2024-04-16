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
  YYSYMBOL_TOKEN_INSTANCE = 8,             /* TOKEN_INSTANCE  */
  YYSYMBOL_TOKEN_AND = 9,                  /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 10,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_NOT = 11,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_UNKNOWN = 12,             /* TOKEN_UNKNOWN  */
  YYSYMBOL_TOKEN_GIVE = 13,                /* TOKEN_GIVE  */
  YYSYMBOL_TOKEN_IF = 14,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 15,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_WHILE = 16,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_FOR = 17,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_DO = 18,                  /* TOKEN_DO  */
  YYSYMBOL_TOKEN_CHAR = 19,                /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_INT = 20,                 /* TOKEN_INT  */
  YYSYMBOL_TOKEN_FLOAT = 21,               /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_BOOL = 22,                /* TOKEN_BOOL  */
  YYSYMBOL_TOKEN_VOID = 23,                /* TOKEN_VOID  */
  YYSYMBOL_TOKEN_TRUE = 24,                /* TOKEN_TRUE  */
  YYSYMBOL_TOKEN_FALSE = 25,               /* TOKEN_FALSE  */
  YYSYMBOL_TOKEN_CHAR_LITERAL = 26,        /* TOKEN_CHAR_LITERAL  */
  YYSYMBOL_TOKEN_INTEGER_LITERAL = 27,     /* TOKEN_INTEGER_LITERAL  */
  YYSYMBOL_TOKEN_FLOATING_POINT_LITERAL = 28, /* TOKEN_FLOATING_POINT_LITERAL  */
  YYSYMBOL_TOKEN_IDENT = 29,               /* TOKEN_IDENT  */
  YYSYMBOL_TOKEN_STRING_LITERAL = 30,      /* TOKEN_STRING_LITERAL  */
  YYSYMBOL_TOKEN_PLUS = 31,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 32,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MUL = 33,                 /* TOKEN_MUL  */
  YYSYMBOL_TOKEN_DIV = 34,                 /* TOKEN_DIV  */
  YYSYMBOL_TOKEN_MODULUS = 35,             /* TOKEN_MODULUS  */
  YYSYMBOL_TOKEN_ASSIGN = 36,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_EQUAL = 37,               /* TOKEN_EQUAL  */
  YYSYMBOL_TOKEN_NOT_EQUAL = 38,           /* TOKEN_NOT_EQUAL  */
  YYSYMBOL_TOKEN_GREATER = 39,             /* TOKEN_GREATER  */
  YYSYMBOL_TOKEN_GREATER_EQUAL = 40,       /* TOKEN_GREATER_EQUAL  */
  YYSYMBOL_TOKEN_LESS = 41,                /* TOKEN_LESS  */
  YYSYMBOL_TOKEN_LESS_EQUAL = 42,          /* TOKEN_LESS_EQUAL  */
  YYSYMBOL_TOKEN_INCREMENT = 43,           /* TOKEN_INCREMENT  */
  YYSYMBOL_TOKEN_DECREMENT = 44,           /* TOKEN_DECREMENT  */
  YYSYMBOL_TOKEN_ADD_WITH = 45,            /* TOKEN_ADD_WITH  */
  YYSYMBOL_TOKEN_SUB_WITH = 46,            /* TOKEN_SUB_WITH  */
  YYSYMBOL_TOKEN_MUL_WITH = 47,            /* TOKEN_MUL_WITH  */
  YYSYMBOL_TOKEN_DIV_WITH = 48,            /* TOKEN_DIV_WITH  */
  YYSYMBOL_TOKEN_LPAREN = 49,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 50,              /* TOKEN_RPAREN  */
  YYSYMBOL_TOKEN_LCRBR = 51,               /* TOKEN_LCRBR  */
  YYSYMBOL_TOKEN_RCRBR = 52,               /* TOKEN_RCRBR  */
  YYSYMBOL_TOKEN_LSQBR = 53,               /* TOKEN_LSQBR  */
  YYSYMBOL_TOKEN_RSQBR = 54,               /* TOKEN_RSQBR  */
  YYSYMBOL_TOKEN_COMMA = 55,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_COLON = 56,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_SEMI = 57,                /* TOKEN_SEMI  */
  YYSYMBOL_TOKEN_ERROR = 58,               /* TOKEN_ERROR  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_decl = 61,                      /* decl  */
  YYSYMBOL_decl_list = 62,                 /* decl_list  */
  YYSYMBOL_stmt = 63,                      /* stmt  */
  YYSYMBOL_stmt_list = 64,                 /* stmt_list  */
  YYSYMBOL_term = 65,                      /* term  */
  YYSYMBOL_assignable = 66,                /* assignable  */
  YYSYMBOL_assignment_algebra = 67,        /* assignment_algebra  */
  YYSYMBOL_algebra = 68,                   /* algebra  */
  YYSYMBOL_starting_expr = 69,             /* starting_expr  */
  YYSYMBOL_factor = 70,                    /* factor  */
  YYSYMBOL_comparison_algebra = 71,        /* comparison_algebra  */
  YYSYMBOL_logical_algebra = 72,           /* logical_algebra  */
  YYSYMBOL_expr = 73,                      /* expr  */
  YYSYMBOL_expr_list = 74,                 /* expr_list  */
  YYSYMBOL_next_expr = 75,                 /* next_expr  */
  YYSYMBOL_name = 76,                      /* name  */
  YYSYMBOL_string_literal = 77,            /* string_literal  */
  YYSYMBOL_boolean_literal = 78,           /* boolean_literal  */
  YYSYMBOL_char_literal = 79,              /* char_literal  */
  YYSYMBOL_allocation_size = 80,           /* allocation_size  */
  YYSYMBOL_parameter = 81,                 /* parameter  */
  YYSYMBOL_parameters = 82,                /* parameters  */
  YYSYMBOL_list_of_parameters = 83,        /* list_of_parameters  */
  YYSYMBOL_type = 84                       /* type  */
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
#define YYLAST   386

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


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
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   110,   112,   114,   119,   126,   132,   138,
     143,   152,   153,   156,   158,   160,   163,   166,   168,   169,
     171,   173,   175,   183,   184,   187,   188,   189,   191,   195,
     196,   198,   203,   205,   207,   209,   211,   213,   214,   215,
     216,   219,   220,   221,   222,   226,   227,   228,   232,   233,
     234,   236,   237,   238,   239,   241,   242,   244,   246,   252,
     254,   256,   261,   262,   263,   264,   265,   266,   270,   271,
     274,   275,   279,   280,   284,   285,   288,   296,   304,   305,
     309,   317,   318,   322,   327,   329,   333,   334,   337,   339,
     341,   343,   345
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
  "TOKEN_INSTANCE", "TOKEN_AND", "TOKEN_OR", "TOKEN_NOT", "TOKEN_UNKNOWN",
  "TOKEN_GIVE", "TOKEN_IF", "TOKEN_ELSE", "TOKEN_WHILE", "TOKEN_FOR",
  "TOKEN_DO", "TOKEN_CHAR", "TOKEN_INT", "TOKEN_FLOAT", "TOKEN_BOOL",
  "TOKEN_VOID", "TOKEN_TRUE", "TOKEN_FALSE", "TOKEN_CHAR_LITERAL",
  "TOKEN_INTEGER_LITERAL", "TOKEN_FLOATING_POINT_LITERAL", "TOKEN_IDENT",
  "TOKEN_STRING_LITERAL", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MUL",
  "TOKEN_DIV", "TOKEN_MODULUS", "TOKEN_ASSIGN", "TOKEN_EQUAL",
  "TOKEN_NOT_EQUAL", "TOKEN_GREATER", "TOKEN_GREATER_EQUAL", "TOKEN_LESS",
  "TOKEN_LESS_EQUAL", "TOKEN_INCREMENT", "TOKEN_DECREMENT",
  "TOKEN_ADD_WITH", "TOKEN_SUB_WITH", "TOKEN_MUL_WITH", "TOKEN_DIV_WITH",
  "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LCRBR", "TOKEN_RCRBR",
  "TOKEN_LSQBR", "TOKEN_RSQBR", "TOKEN_COMMA", "TOKEN_COLON", "TOKEN_SEMI",
  "TOKEN_ERROR", "$accept", "program", "decl", "decl_list", "stmt",
  "stmt_list", "term", "assignable", "assignment_algebra", "algebra",
  "starting_expr", "factor", "comparison_algebra", "logical_algebra",
  "expr", "expr_list", "next_expr", "name", "string_literal",
  "boolean_literal", "char_literal", "allocation_size", "parameter",
  "parameters", "list_of_parameters", "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,   -99,    27,   -15,   -99,    -6,   -99,   -99,   202,    17,
      -2,    15,    18,    28,    35,    73,   240,   -15,   -99,   -99,
     -99,   -99,   -99,   -99,   -28,   -99,   -99,   -11,   -15,   277,
     -99,   -99,   -99,   -99,   -99,   -99,   277,    21,    21,   240,
      83,   275,   -99,   325,   -99,   -99,   -99,   -99,    -3,   144,
     -99,   -99,   -99,    -6,    42,    51,   240,   -99,    40,   -99,
     288,   -15,   -99,     6,   -99,   -15,   -99,    96,   -99,    26,
     277,   277,   277,   240,   -99,   -99,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     -99,   268,   240,   -15,   -99,   -15,   -99,    61,    14,   240,
      56,   -99,   268,   -99,   277,   -99,   -99,   -99,   -99,   294,
     -99,   325,   325,   325,   325,   325,    83,    83,    83,    83,
      83,    83,    83,    83,   325,   325,   -99,   307,    23,    69,
     115,   -99,   203,   -99,    74,   -99,   -99,   -99,   277,   240,
     -99,   -99,   117,   231,    80,    81,   203,   -99,   203,    85,
      53,   158,    76,   -99,    77,    78,    39,   240,   240,    88,
     -99,   -99,   -99,   349,   -99,   -99,   -99,   137,   -99,    48,
      87,   -99,    90,   203,    79,   -99,   127,   240,    58,   203,
      95,   240,   -99,   203,    99,   -99,   203,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      12,    76,     0,    12,     2,     0,     1,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,     3,    89,
      88,    91,    90,    92,     0,    82,    81,     0,     0,     0,
      78,    79,    80,    49,    50,    77,     0,     0,     0,     0,
      44,     0,    45,    71,    70,    28,    43,    46,     0,    48,
      51,    52,    53,     0,    87,     0,     0,     9,     0,     5,
      60,     0,    55,    48,    54,     0,    39,    29,    40,     0,
       0,     0,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,    73,     0,    83,    85,    84,     0,     0,    73,
       0,    60,     0,    31,     0,    61,    25,    26,    27,     0,
      47,    32,    33,    34,    35,    36,    41,    42,    62,    63,
      65,    67,    64,    66,    68,    69,    59,    57,    75,     0,
       0,    86,    24,    10,     0,     6,    57,    30,     0,    73,
      72,    56,     0,     0,     0,     0,    24,    18,    24,     0,
       0,    48,     0,    74,     0,     0,     0,     0,    73,     0,
      23,     8,    19,     0,     7,    58,    21,     0,    20,     0,
       0,    17,     0,     0,     0,    22,    13,    73,     0,     0,
       0,    73,    14,     0,     0,    16,     0,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,    10,   148,   -59,   -60,   299,   -33,    82,   -58,
     -99,   -27,   -99,   -99,    -5,   -98,   -99,     0,    98,   -99,
     -99,   -99,   -99,    59,   -99,   106
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,   147,     4,   148,   149,    40,    41,    42,    43,
      44,    45,    46,    47,   150,   129,   140,    63,    50,    51,
      52,    27,    54,    55,    96,     9
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,   134,    62,     5,    66,    68,    88,    89,    56,    64,
       3,    48,   102,     3,     1,   111,    49,    53,   112,   113,
     114,   115,    15,    88,    89,    58,    65,     6,    60,    57,
     124,   125,    88,    89,    69,    88,    89,    67,    67,    49,
     109,   153,   167,   106,   107,   108,    59,     8,    88,    89,
       1,    98,    19,    16,    90,    92,    49,    88,    89,    93,
     170,   101,    88,    89,   127,   103,    17,    88,    89,    20,
      35,   133,    21,    49,    18,   136,   105,   137,   139,   180,
     111,    24,    22,   184,    28,    25,   159,   128,   160,    23,
      29,    99,    49,   130,   128,    53,   168,    95,   173,    49,
      26,    97,   104,    30,    31,    32,    33,    34,     1,    35,
     162,    36,   132,   135,   176,   181,    70,    71,    72,   141,
     182,   142,    37,    38,   185,   154,   152,   187,    39,   157,
     158,   165,   151,   164,   128,   166,   177,   161,   156,    49,
     171,   172,   179,    49,   174,   183,   151,   175,   151,   186,
      91,     7,   169,   128,   131,   110,   100,    49,    49,    94,
       0,     0,     0,   130,    91,     0,     0,     0,     0,   178,
       0,     0,   128,   151,    49,     0,   128,    49,     0,   151,
     -29,    49,     0,   151,     0,     0,   151,   -29,   -29,   -29,
     -29,   -29,   -29,    92,   -29,     0,     0,    93,     0,     0,
       0,   -29,   -29,   -29,   -29,   -29,   -29,    92,    28,     0,
       0,   163,     0,     0,    29,     0,   143,   144,     0,     0,
     145,    10,    11,    12,    13,    14,     0,    30,    31,    32,
      33,    34,     1,    35,     0,    36,    28,     0,   155,     0,
       0,     0,    29,     0,     0,    28,    37,    38,     0,     0,
       0,    29,    39,     0,   146,    30,    31,    32,    33,    34,
       1,    35,     0,    36,    30,    31,    32,    33,    34,     1,
      35,     0,    36,    61,    37,    38,   126,     0,     0,    29,
      39,     0,    61,    37,    38,     0,     0,     0,    29,    39,
       0,     0,    30,    31,    32,    33,    34,     1,    35,     0,
      36,    30,    31,    32,    33,    34,     1,    35,     0,    36,
       0,    73,     0,     0,     0,     0,     0,    39,    74,    75,
      76,    77,    78,    79,   -31,     0,    39,     0,     0,     0,
     138,   -31,   -31,   -31,   -31,   -31,   -31,    74,    75,    76,
      77,    78,    79,   -30,     0,     0,     0,     0,     0,     0,
     -30,   -30,   -30,   -30,   -30,   -30,    80,    81,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    10,    11,
      12,    13,    14,     0,     0,     0,     0,     0,     1,   116,
     117,   118,   119,   120,   121,   122,   123
};

static const yytype_int16 yycheck[] =
{
       0,    99,    29,     3,    37,    38,     9,    10,    36,    36,
       0,    16,     6,     3,    29,    73,    16,    17,    76,    77,
      78,    79,     5,     9,    10,    36,     5,     0,    28,    57,
      88,    89,     9,    10,    39,     9,    10,    37,    38,    39,
      73,   139,     3,    70,    71,    72,    57,    53,     9,    10,
      29,    56,    54,    36,    57,    49,    56,     9,    10,    53,
     158,    61,     9,    10,    91,    65,    49,     9,    10,    54,
      30,    57,    54,    73,    57,   102,    50,   104,    55,   177,
     138,     8,    54,   181,     5,    12,   146,    92,   148,    54,
      11,    51,    92,    93,    99,    95,    57,    55,    50,    99,
      27,    50,     6,    24,    25,    26,    27,    28,    29,    30,
      57,    32,    51,    57,   173,    57,    33,    34,    35,    50,
     179,     6,    43,    44,   183,     8,    52,   186,    49,    49,
      49,    54,   132,    57,   139,    57,    57,    52,   143,   139,
      52,     4,    15,   143,    57,    50,   146,    57,   148,    50,
       6,     3,   157,   158,    95,    73,    58,   157,   158,    53,
      -1,    -1,    -1,   163,     6,    -1,    -1,    -1,    -1,   174,
      -1,    -1,   177,   173,   174,    -1,   181,   177,    -1,   179,
      36,   181,    -1,   183,    -1,    -1,   186,    43,    44,    45,
      46,    47,    48,    49,    36,    -1,    -1,    53,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,     5,    -1,
      -1,    53,    -1,    -1,    11,    -1,    13,    14,    -1,    -1,
      17,    19,    20,    21,    22,    23,    -1,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,     5,    -1,     7,    -1,
      -1,    -1,    11,    -1,    -1,     5,    43,    44,    -1,    -1,
      -1,    11,    49,    -1,    51,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,     5,    43,    44,     8,    -1,    -1,    11,
      49,    -1,     5,    43,    44,    -1,    -1,    -1,    11,    49,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    49,    43,    44,
      45,    46,    47,    48,    36,    -1,    49,    -1,    -1,    -1,
      36,    43,    44,    45,    46,    47,    48,    43,    44,    45,
      46,    47,    48,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    31,    32,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    29,    80,
      81,    82,    83,    84,    85,    86,    87
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    60,    61,    62,    76,     0,    62,    53,    84,
      19,    20,    21,    22,    23,     5,    36,    49,    57,    54,
      54,    54,    54,    54,     8,    12,    27,    80,     5,    11,
      24,    25,    26,    27,    28,    30,    32,    43,    44,    49,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    76,
      77,    78,    79,    76,    81,    82,    36,    57,    36,    57,
      76,     5,    70,    76,    70,     5,    66,    76,    66,    73,
      33,    34,    35,    36,    43,    44,    45,    46,    47,    48,
      31,    32,    37,    38,    39,    40,    41,    42,     9,    10,
      57,     6,    49,    53,    84,    55,    83,    50,    73,    51,
      77,    76,     6,    76,     6,    50,    70,    70,    70,    66,
      67,    68,    68,    68,    68,    68,    65,    65,    65,    65,
      65,    65,    65,    65,    68,    68,     8,    70,    73,    74,
      76,    82,    51,    57,    74,    57,    70,    70,    36,    55,
      75,    50,     6,    13,    14,    17,    51,    61,    63,    64,
      73,    76,    52,    74,     8,     7,    73,    49,    49,    64,
      64,    52,    57,    53,    57,    54,    57,     3,    57,    73,
      74,    52,     4,    50,    57,    57,    63,    57,    73,    15,
      74,    57,    63,    50,    74,    63,    50,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    64,    64,    65,    65,    65,    65,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    68,    68,    69,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    77,    78,    78,
      79,    80,    80,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     5,     5,     7,     9,     8,     5,
       7,     2,     0,     5,     7,     9,     8,     3,     1,     2,
       3,     3,     5,     2,     0,     3,     3,     3,     1,     1,
       3,     2,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     4,     3,     6,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     0,     2,     0,     3,     3,
       3,     3,     3
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
#line 107 "parser.y"
                    {parser_result = (yyvsp[0].decl);}
#line 1329 "parser.c"
    break;

  case 3: /* decl: name type TOKEN_SEMI  */
#line 111 "parser.y"
            { (yyval.decl) = decl_create((yyvsp[-2].name), (yyvsp[-1].type), 0, 0, 0); }
#line 1335 "parser.c"
    break;

  case 4: /* decl: name type TOKEN_ASSIGN expr TOKEN_SEMI  */
#line 113 "parser.y"
            { (yyval.decl) = decl_create((yyvsp[-4].name), (yyvsp[-3].type), (yyvsp[-1].expr), 0, 0); }
#line 1341 "parser.c"
    break;

  case 5: /* decl: name type TOKEN_ALLOCATE allocation_size TOKEN_SEMI  */
#line 115 "parser.y"
            {
                struct type *temp = type_create(TYPE_ARRAY, (yyvsp[-3].type), 0, (yyvsp[-1].integer));
                (yyval.decl) = decl_create((yyvsp[-4].name), temp, 0, 0, 0); 
            }
#line 1350 "parser.c"
    break;

  case 6: /* decl: name type TOKEN_ALLOCATE allocation_size TOKEN_ASSIGN string_literal TOKEN_SEMI  */
#line 121 "parser.y"
            {
                struct type *temp = type_create(TYPE_ARRAY, (yyvsp[-5].type), 0, (yyvsp[-3].integer));
                struct expr *e = expr_create_string_literal((yyvsp[-1].name));
                (yyval.decl) = decl_create((yyvsp[-6].name), temp, e, 0, 0); 
            }
#line 1360 "parser.c"
    break;

  case 7: /* decl: name type TOKEN_ALLOCATE allocation_size TOKEN_ASSIGN TOKEN_LCRBR expr_list TOKEN_RCRBR TOKEN_SEMI  */
#line 128 "parser.y"
            {
                struct type *temp = type_create(TYPE_ARRAY, (yyvsp[-7].type), 0, (yyvsp[-5].integer));
                (yyval.decl) = decl_create((yyvsp[-8].name), temp, (yyvsp[-2].expr), 0, 0); 
            }
#line 1369 "parser.c"
    break;

  case 8: /* decl: name type TOKEN_LPAREN parameters TOKEN_RPAREN TOKEN_LCRBR stmt_list TOKEN_RCRBR  */
#line 134 "parser.y"
            {
                struct type *temp = type_create(TYPE_FUNCTION, (yyvsp[-6].type), (yyvsp[-4].params), 0);
                (yyval.decl) = decl_create((yyvsp[-7].name), temp, 0, (yyvsp[-1].stmt), 0); 
            }
#line 1378 "parser.c"
    break;

  case 9: /* decl: name type TOKEN_ALLOCATE TOKEN_INSTANCE TOKEN_SEMI  */
#line 139 "parser.y"
            {
                struct type *temp = type_create(TYPE_POINTER, (yyvsp[-3].type), 0, 0);
                (yyval.decl) = decl_create((yyvsp[-4].name), temp, 0, 0, 0);
            }
#line 1387 "parser.c"
    break;

  case 10: /* decl: name type TOKEN_ALLOCATE TOKEN_INSTANCE TOKEN_ASSIGN expr TOKEN_SEMI  */
#line 145 "parser.y"
            {
                struct type *temp = type_create(TYPE_POINTER, (yyvsp[-5].type), 0, 0);
                (yyval.decl) = decl_create((yyvsp[-6].name), temp, (yyvsp[-1].expr), 0, 0);
            }
#line 1396 "parser.c"
    break;

  case 11: /* decl_list: decl decl_list  */
#line 152 "parser.y"
                            { (yyval.decl) = (yyvsp[-1].decl); (yyvsp[-1].decl)->next = (yyvsp[0].decl); }
#line 1402 "parser.c"
    break;

  case 12: /* decl_list: %empty  */
#line 153 "parser.y"
                            { (yyval.decl) = 0; }
#line 1408 "parser.c"
    break;

  case 13: /* stmt: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt  */
#line 157 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-2].expr), 0, (yyvsp[0].stmt), 0, 0); }
#line 1414 "parser.c"
    break;

  case 14: /* stmt: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt TOKEN_ELSE stmt  */
#line 159 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[-4].expr), 0, (yyvsp[-2].stmt), (yyvsp[0].stmt), 0); }
#line 1420 "parser.c"
    break;

  case 15: /* stmt: TOKEN_FOR TOKEN_LPAREN expr_list TOKEN_SEMI expr TOKEN_SEMI expr_list TOKEN_RPAREN stmt  */
#line 162 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), 0, 0); }
#line 1426 "parser.c"
    break;

  case 16: /* stmt: TOKEN_FOR TOKEN_LPAREN expr_list TOKEN_SEMI TOKEN_SEMI expr_list TOKEN_RPAREN stmt  */
#line 165 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[-5].expr), 0, (yyvsp[-2].expr), (yyvsp[0].stmt), 0, 0); }
#line 1432 "parser.c"
    break;

  case 17: /* stmt: TOKEN_LCRBR stmt_list TOKEN_RCRBR  */
#line 167 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_BLOCK, 0, 0, 0, 0, (yyvsp[-1].stmt), 0, 0); }
#line 1438 "parser.c"
    break;

  case 18: /* stmt: decl  */
#line 168 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), 0, 0, 0, 0, 0, 0); }
#line 1444 "parser.c"
    break;

  case 19: /* stmt: expr TOKEN_SEMI  */
#line 170 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1450 "parser.c"
    break;

  case 20: /* stmt: TOKEN_GIVE expr TOKEN_SEMI  */
#line 172 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_GIVE, 0, 0, (yyvsp[-1].expr), 0, 0, 0, 0); }
#line 1456 "parser.c"
    break;

  case 21: /* stmt: TOKEN_GIVE TOKEN_UP TOKEN_SEMI  */
#line 174 "parser.y"
                { (yyval.stmt) = stmt_create(STMT_GIVE, 0, 0, 0, 0, 0, 0, 0); }
#line 1462 "parser.c"
    break;

  case 22: /* stmt: TOKEN_GIVE expr TOKEN_PRINT_IN TOKEN_STDIN TOKEN_SEMI  */
#line 176 "parser.y"
                { 
                        (yyval.stmt) = stmt_create(STMT_GIVE, 0, 0, (yyvsp[-3].expr), 0, 0, 0, 0); 
                        (yyval.stmt)->print = 1; 
                }
#line 1471 "parser.c"
    break;

  case 23: /* stmt_list: stmt stmt_list  */
#line 183 "parser.y"
                                { (yyval.stmt) = (yyvsp[-1].stmt); (yyvsp[-1].stmt)->next = (yyvsp[0].stmt); }
#line 1477 "parser.c"
    break;

  case 24: /* stmt_list: %empty  */
#line 184 "parser.y"
                                { (yyval.stmt) = 0; }
#line 1483 "parser.c"
    break;

  case 25: /* term: term TOKEN_MUL factor  */
#line 187 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1489 "parser.c"
    break;

  case 26: /* term: term TOKEN_DIV factor  */
#line 188 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1495 "parser.c"
    break;

  case 27: /* term: term TOKEN_MODULUS factor  */
#line 190 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_MODULUS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1501 "parser.c"
    break;

  case 28: /* term: factor  */
#line 191 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1507 "parser.c"
    break;

  case 29: /* assignable: name  */
#line 195 "parser.y"
                        { (yyval.expr) = expr_create_name((yyvsp[0].name)); }
#line 1513 "parser.c"
    break;

  case 30: /* assignable: name TOKEN_SUBSCRIPT factor  */
#line 197 "parser.y"
                        { (yyval.expr) = expr_create(EXPR_SUBSCRIPT, expr_create_name((yyvsp[-2].name)), (yyvsp[0].expr)); }
#line 1519 "parser.c"
    break;

  case 31: /* assignable: TOKEN_ALLOCATE name  */
#line 199 "parser.y"
                        { (yyval.expr) = expr_create(EXPR_DEREFERENCE, expr_create_name((yyvsp[0].name)), 0); }
#line 1525 "parser.c"
    break;

  case 32: /* assignment_algebra: assignable TOKEN_ASSIGN algebra  */
#line 204 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1531 "parser.c"
    break;

  case 33: /* assignment_algebra: assignable TOKEN_ADD_WITH algebra  */
#line 206 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_ADD_WITH, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1537 "parser.c"
    break;

  case 34: /* assignment_algebra: assignable TOKEN_SUB_WITH algebra  */
#line 208 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_SUB_WITH, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1543 "parser.c"
    break;

  case 35: /* assignment_algebra: assignable TOKEN_MUL_WITH algebra  */
#line 210 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_MUL_WITH, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1549 "parser.c"
    break;

  case 36: /* assignment_algebra: assignable TOKEN_DIV_WITH algebra  */
#line 212 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_DIV_WITH, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1555 "parser.c"
    break;

  case 37: /* assignment_algebra: assignable TOKEN_INCREMENT  */
#line 213 "parser.y"
                                      { (yyval.expr) = expr_create(EXPR_INCREMENT, (yyvsp[-1].expr), 0); }
#line 1561 "parser.c"
    break;

  case 38: /* assignment_algebra: assignable TOKEN_DECREMENT  */
#line 214 "parser.y"
                                      { (yyval.expr) = expr_create(EXPR_DECREMENT, (yyvsp[-1].expr), 0); }
#line 1567 "parser.c"
    break;

  case 39: /* assignment_algebra: TOKEN_INCREMENT assignable  */
#line 215 "parser.y"
                                      { (yyval.expr) = expr_create(EXPR_INCREMENT, 0, (yyvsp[0].expr)); }
#line 1573 "parser.c"
    break;

  case 40: /* assignment_algebra: TOKEN_DECREMENT assignable  */
#line 216 "parser.y"
                                      { (yyval.expr) = expr_create(EXPR_DECREMENT, 0, (yyvsp[0].expr)); }
#line 1579 "parser.c"
    break;

  case 41: /* algebra: algebra TOKEN_PLUS term  */
#line 219 "parser.y"
                                        { (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1585 "parser.c"
    break;

  case 42: /* algebra: algebra TOKEN_MINUS term  */
#line 220 "parser.y"
                                        { (yyval.expr) = expr_create(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1591 "parser.c"
    break;

  case 43: /* algebra: comparison_algebra  */
#line 221 "parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1597 "parser.c"
    break;

  case 44: /* algebra: term  */
#line 222 "parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1603 "parser.c"
    break;

  case 45: /* starting_expr: assignment_algebra  */
#line 226 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1609 "parser.c"
    break;

  case 46: /* starting_expr: logical_algebra  */
#line 227 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1615 "parser.c"
    break;

  case 47: /* starting_expr: assignable TOKEN_ASSIGN assignment_algebra  */
#line 229 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1621 "parser.c"
    break;

  case 48: /* factor: name  */
#line 232 "parser.y"
                                { (yyval.expr) = expr_create_name((yyvsp[0].name)); }
#line 1627 "parser.c"
    break;

  case 49: /* factor: TOKEN_INTEGER_LITERAL  */
#line 233 "parser.y"
                                { (yyval.expr) = expr_create_integer_literal(atoi(yytext)); }
#line 1633 "parser.c"
    break;

  case 50: /* factor: TOKEN_FLOATING_POINT_LITERAL  */
#line 235 "parser.y"
                                { (yyval.expr) = expr_create_floating_point_literal(atof(yytext)); }
#line 1639 "parser.c"
    break;

  case 51: /* factor: string_literal  */
#line 236 "parser.y"
                                { (yyval.expr) = expr_create_string_literal((yyvsp[0].name)); }
#line 1645 "parser.c"
    break;

  case 52: /* factor: boolean_literal  */
#line 237 "parser.y"
                                { (yyval.expr) = expr_create_boolean_literal((yyvsp[0].integer)); }
#line 1651 "parser.c"
    break;

  case 53: /* factor: char_literal  */
#line 238 "parser.y"
                                { (yyval.expr) = expr_create_char_literal((yyvsp[0].integer)); }
#line 1657 "parser.c"
    break;

  case 54: /* factor: TOKEN_MINUS factor  */
#line 240 "parser.y"
                { (yyval.expr) = expr_create(EXPR_MUL, expr_create_integer_literal(-1), (yyvsp[0].expr)); }
#line 1663 "parser.c"
    break;

  case 55: /* factor: TOKEN_NOT factor  */
#line 241 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_NOT, (yyvsp[0].expr), 0); }
#line 1669 "parser.c"
    break;

  case 56: /* factor: name TOKEN_LPAREN expr_list TOKEN_RPAREN  */
#line 243 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_CALL, expr_create_name((yyvsp[-3].name)), (yyvsp[-1].expr)); }
#line 1675 "parser.c"
    break;

  case 57: /* factor: name TOKEN_SUBSCRIPT factor  */
#line 245 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_SUBSCRIPT, expr_create_name((yyvsp[-2].name)), (yyvsp[0].expr)); }
#line 1681 "parser.c"
    break;

  case 58: /* factor: name TOKEN_LSQBR name TOKEN_SUBSCRIPT TOKEN_INSTANCE TOKEN_RSQBR  */
#line 247 "parser.y"
                                { 
                                        (yyval.expr) = expr_create(EXPR_RENAME, NULL, NULL); 
                                        (yyval.expr)->name = (yyvsp[-5].name); 
                                        (yyval.expr)->string_literal = (yyvsp[-3].name); 
                                }
#line 1691 "parser.c"
    break;

  case 59: /* factor: name TOKEN_SUBSCRIPT TOKEN_INSTANCE  */
#line 253 "parser.y"
                { (yyval.expr) = expr_create(EXPR_ADDRESS, expr_create_name((yyvsp[-2].name)), 0); }
#line 1697 "parser.c"
    break;

  case 60: /* factor: TOKEN_ALLOCATE name  */
#line 255 "parser.y"
                        { (yyval.expr) = expr_create(EXPR_DEREFERENCE, expr_create_name((yyvsp[0].name)), 0); }
#line 1703 "parser.c"
    break;

  case 61: /* factor: TOKEN_LPAREN expr TOKEN_RPAREN  */
#line 257 "parser.y"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1709 "parser.c"
    break;

  case 62: /* comparison_algebra: algebra TOKEN_EQUAL term  */
#line 261 "parser.y"
                                           { (yyval.expr) = expr_create(EXPR_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1715 "parser.c"
    break;

  case 63: /* comparison_algebra: algebra TOKEN_NOT_EQUAL term  */
#line 262 "parser.y"
                                           { (yyval.expr) = expr_create(EXPR_NOT_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1721 "parser.c"
    break;

  case 64: /* comparison_algebra: algebra TOKEN_LESS term  */
#line 263 "parser.y"
                                           { (yyval.expr) = expr_create(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1727 "parser.c"
    break;

  case 65: /* comparison_algebra: algebra TOKEN_GREATER term  */
#line 264 "parser.y"
                                           { (yyval.expr) = expr_create(EXPR_GREATER, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1733 "parser.c"
    break;

  case 66: /* comparison_algebra: algebra TOKEN_LESS_EQUAL term  */
#line 265 "parser.y"
                                           { (yyval.expr) = expr_create(EXPR_LESS_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1739 "parser.c"
    break;

  case 67: /* comparison_algebra: algebra TOKEN_GREATER_EQUAL term  */
#line 266 "parser.y"
                                           { (yyval.expr) = expr_create(EXPR_GREATER_EQUAL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1745 "parser.c"
    break;

  case 68: /* logical_algebra: expr TOKEN_AND algebra  */
#line 270 "parser.y"
                                   { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1751 "parser.c"
    break;

  case 69: /* logical_algebra: expr TOKEN_OR algebra  */
#line 271 "parser.y"
                                   { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1757 "parser.c"
    break;

  case 70: /* expr: starting_expr  */
#line 274 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1763 "parser.c"
    break;

  case 71: /* expr: algebra  */
#line 275 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1769 "parser.c"
    break;

  case 72: /* expr_list: expr next_expr  */
#line 279 "parser.y"
                                { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 1775 "parser.c"
    break;

  case 73: /* expr_list: %empty  */
#line 280 "parser.y"
                                { (yyval.expr) = 0; }
#line 1781 "parser.c"
    break;

  case 74: /* next_expr: TOKEN_COMMA expr_list  */
#line 284 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1787 "parser.c"
    break;

  case 75: /* next_expr: %empty  */
#line 285 "parser.y"
                                { (yyval.expr) = 0; }
#line 1793 "parser.c"
    break;

  case 76: /* name: TOKEN_IDENT  */
#line 288 "parser.y"
                        {
                                char *temp = (char *)malloc(strlen(yytext)*sizeof(char));
                                strcpy(temp, yytext);
                                (yyval.name) = temp; 
                        }
#line 1803 "parser.c"
    break;

  case 77: /* string_literal: TOKEN_STRING_LITERAL  */
#line 296 "parser.y"
                                { 
                                char *temp = (char *)malloc(strlen(yytext)*sizeof(char));
                                strcpy(temp, yytext);
                                (yyval.name) = temp; 
                                }
#line 1813 "parser.c"
    break;

  case 78: /* boolean_literal: TOKEN_TRUE  */
#line 304 "parser.y"
                                { (yyval.integer) = 1; }
#line 1819 "parser.c"
    break;

  case 79: /* boolean_literal: TOKEN_FALSE  */
#line 305 "parser.y"
                                { (yyval.integer) = 0; }
#line 1825 "parser.c"
    break;

  case 80: /* char_literal: TOKEN_CHAR_LITERAL  */
#line 309 "parser.y"
                                {
                                char *temp = (char *)malloc(sizeof(char));
                                *temp = yytext[1];
                                (yyval.integer) = *temp;
                                }
#line 1835 "parser.c"
    break;

  case 81: /* allocation_size: TOKEN_INTEGER_LITERAL  */
#line 317 "parser.y"
                                { (yyval.integer) = atoi(yytext); }
#line 1841 "parser.c"
    break;

  case 82: /* allocation_size: TOKEN_UNKNOWN  */
#line 318 "parser.y"
                                { (yyval.integer) = 0; }
#line 1847 "parser.c"
    break;

  case 83: /* parameter: name type  */
#line 323 "parser.y"
            { (yyval.params) = param_list_create((yyvsp[-1].name), (yyvsp[0].type), 0); }
#line 1853 "parser.c"
    break;

  case 84: /* parameters: parameter list_of_parameters  */
#line 328 "parser.y"
            { (yyval.params) = (yyvsp[-1].params); (yyvsp[-1].params)->next = (yyvsp[0].params); }
#line 1859 "parser.c"
    break;

  case 85: /* parameters: %empty  */
#line 329 "parser.y"
            { (yyval.params) = 0; }
#line 1865 "parser.c"
    break;

  case 86: /* list_of_parameters: TOKEN_COMMA parameters  */
#line 333 "parser.y"
                                    { (yyval.params) = (yyvsp[0].params); }
#line 1871 "parser.c"
    break;

  case 87: /* list_of_parameters: %empty  */
#line 334 "parser.y"
                                    { (yyval.params) = 0; }
#line 1877 "parser.c"
    break;

  case 88: /* type: TOKEN_LSQBR TOKEN_INT TOKEN_RSQBR  */
#line 338 "parser.y"
                { (yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0); }
#line 1883 "parser.c"
    break;

  case 89: /* type: TOKEN_LSQBR TOKEN_CHAR TOKEN_RSQBR  */
#line 340 "parser.y"
                { (yyval.type) = type_create(TYPE_CHARACTER, 0, 0, 0); }
#line 1889 "parser.c"
    break;

  case 90: /* type: TOKEN_LSQBR TOKEN_BOOL TOKEN_RSQBR  */
#line 342 "parser.y"
                { (yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0); }
#line 1895 "parser.c"
    break;

  case 91: /* type: TOKEN_LSQBR TOKEN_FLOAT TOKEN_RSQBR  */
#line 344 "parser.y"
                { (yyval.type) = type_create(TYPE_FLOATING_POINT, 0, 0, 0); }
#line 1901 "parser.c"
    break;

  case 92: /* type: TOKEN_LSQBR TOKEN_VOID TOKEN_RSQBR  */
#line 346 "parser.y"
                { (yyval.type) = type_create(TYPE_VOID, 0, 0, 0); }
#line 1907 "parser.c"
    break;


#line 1911 "parser.c"

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

#line 349 "parser.y"


void yyerror(char *s) {
    error_count++;
    fprintf(stderr, RED "Error" RESET \
        MAG" |%s|"RESET"->"YEL"|%s|"RESET" on line %d \n", s, yytext, line);
}
