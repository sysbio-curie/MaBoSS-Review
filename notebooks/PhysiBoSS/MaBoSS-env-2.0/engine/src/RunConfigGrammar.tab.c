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
#line 2 "RunConfigGrammar.y"

/* 
   MaBoSS (Markov Boolean Stochastic Simulator)
   Copyright (C) 2011 Institut Curie, 26 rue d'Ulm, Paris, France
   
   MaBoSS is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   
   MaBoSS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA 
*/

/*
   Module:
     RunConfigGrammar.l

   Authors:
     Eric Viara <viara@sysra.com>
     Gautier Stoll <gautier.stoll@curie.fr>
 
   Date:
     January-March 2011
     updated to add extended initial conditions: October 2014
*/

#include "BooleanNetwork.h"
#include "RunConfig.h"

extern int yylex();

static void yyerror(const char *s);
static Network* network;

extern std::string yy_error_head();

#line 115 "RunConfigGrammar.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VARIABLE = 258,                /* VARIABLE  */
    SYMBOL = 259,                  /* SYMBOL  */
    DOUBLE = 260,                  /* DOUBLE  */
    INTEGER = 261,                 /* INTEGER  */
    LOGAND = 262,                  /* LOGAND  */
    LOGOR = 263,                   /* LOGOR  */
    LOGXOR = 264,                  /* LOGXOR  */
    LOGNOT = 265,                  /* LOGNOT  */
    EQUAL = 266,                   /* EQUAL  */
    NOT_EQUAL = 267,               /* NOT_EQUAL  */
    NODE = 268,                    /* NODE  */
    GTEQ = 269,                    /* GTEQ  */
    LTEQ = 270                     /* LTEQ  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "RunConfigGrammar.y"

  Expression* expr;
  char* str;
  double d;
  long long l;
  std::vector<const Node*>* node_list;
  std::vector<Expression*>* expr_list;
  IStateGroup::ProbaIState* istate_expr;
  std::vector<IStateGroup::ProbaIState*>* istate_expr_list;

#line 188 "RunConfigGrammar.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VARIABLE = 3,                   /* VARIABLE  */
  YYSYMBOL_SYMBOL = 4,                     /* SYMBOL  */
  YYSYMBOL_DOUBLE = 5,                     /* DOUBLE  */
  YYSYMBOL_INTEGER = 6,                    /* INTEGER  */
  YYSYMBOL_LOGAND = 7,                     /* LOGAND  */
  YYSYMBOL_LOGOR = 8,                      /* LOGOR  */
  YYSYMBOL_LOGXOR = 9,                     /* LOGXOR  */
  YYSYMBOL_LOGNOT = 10,                    /* LOGNOT  */
  YYSYMBOL_EQUAL = 11,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 12,                 /* NOT_EQUAL  */
  YYSYMBOL_NODE = 13,                      /* NODE  */
  YYSYMBOL_GTEQ = 14,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 15,                      /* LTEQ  */
  YYSYMBOL_16_ = 16,                       /* ';'  */
  YYSYMBOL_17_ = 17,                       /* '='  */
  YYSYMBOL_18_ = 18,                       /* '.'  */
  YYSYMBOL_19_ = 19,                       /* '['  */
  YYSYMBOL_20_ = 20,                       /* ']'  */
  YYSYMBOL_21_ = 21,                       /* ','  */
  YYSYMBOL_22_ = 22,                       /* '('  */
  YYSYMBOL_23_ = 23,                       /* ')'  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '!'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_31_ = 31,                       /* '^'  */
  YYSYMBOL_32_ = 32,                       /* '?'  */
  YYSYMBOL_33_ = 33,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_translation_unit = 35,          /* translation_unit  */
  YYSYMBOL_decl = 36,                      /* decl  */
  YYSYMBOL_runconfig_decl = 37,            /* runconfig_decl  */
  YYSYMBOL_node_attr_decl = 38,            /* node_attr_decl  */
  YYSYMBOL_symbol_istate_list = 39,        /* symbol_istate_list  */
  YYSYMBOL_symbol_list = 40,               /* symbol_list  */
  YYSYMBOL_istate_expression_list = 41,    /* istate_expression_list  */
  YYSYMBOL_istate_expression = 42,         /* istate_expression  */
  YYSYMBOL_expression_list = 43,           /* expression_list  */
  YYSYMBOL_var_decl = 44,                  /* var_decl  */
  YYSYMBOL_primary_expression = 45,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 46,        /* postfix_expression  */
  YYSYMBOL_unary_expression = 47,          /* unary_expression  */
  YYSYMBOL_multiplicative_expression = 48, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 49,       /* additive_expression  */
  YYSYMBOL_relational_expression = 50,     /* relational_expression  */
  YYSYMBOL_equality_expression = 51,       /* equality_expression  */
  YYSYMBOL_logical_and_expression = 52,    /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 53,     /* logical_or_expression  */
  YYSYMBOL_logical_xor_expression = 54,    /* logical_xor_expression  */
  YYSYMBOL_conditional_expression = 55,    /* conditional_expression  */
  YYSYMBOL_expression = 56                 /* expression  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   86

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  101

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   270


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
       2,     2,     2,    26,     2,     2,     2,     2,     2,     2,
      22,    23,    27,    24,    21,    25,    18,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    16,
      29,    17,    30,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    19,     2,    20,    31,     2,     2,     2,     2,     2,
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
      15
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    87,    92,    93,    94,    95,    98,   106,
     133,   146,   152,   157,   164,   169,   176,   182,   187,   194,
     203,   207,   211,   215,   221,   227,   231,   235,   239,   243,
     249,   253,   257,   263,   267,   271,   277,   281,   285,   289,
     293,   299,   303,   307,   313,   317,   323,   327,   333,   337,
     341,   347,   351,   357
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
  "\"end of file\"", "error", "\"invalid token\"", "VARIABLE", "SYMBOL",
  "DOUBLE", "INTEGER", "LOGAND", "LOGOR", "LOGXOR", "LOGNOT", "EQUAL",
  "NOT_EQUAL", "NODE", "GTEQ", "LTEQ", "';'", "'='", "'.'", "'['", "']'",
  "','", "'('", "')'", "'+'", "'-'", "'!'", "'*'", "'/'", "'<'", "'>'",
  "'^'", "'?'", "':'", "$accept", "translation_unit", "decl",
  "runconfig_decl", "node_attr_decl", "symbol_istate_list", "symbol_list",
  "istate_expression_list", "istate_expression", "expression_list",
  "var_decl", "primary_expression", "postfix_expression",
  "unary_expression", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "logical_xor_expression",
  "conditional_expression", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      41,   -14,    -8,   -68,    13,    24,   -68,   -68,   -68,    -5,
     -68,     9,     9,    38,   -68,    32,   -68,   -68,    42,   -68,
     -68,   -68,     9,     9,     9,     9,     9,   -68,   -68,   -68,
      28,    34,    -7,    50,    64,    65,     7,   -68,    56,    58,
      59,   -68,    71,    60,   -68,    55,   -68,   -68,   -68,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,   -68,   -68,     9,   -68,    15,   -68,
     -68,   -68,    28,    28,    34,    34,    34,    34,    -7,    -7,
      50,    64,    65,    65,    46,    66,    20,   -68,    61,     9,
     -68,   -68,    15,    15,   -68,   -68,    43,   -68,   -68,    15,
     -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     7,     0,     0,     2,     5,     6,     0,
       4,     0,     0,     0,    12,     0,     1,     3,     0,    22,
      21,    20,     0,     0,     0,     0,     0,    24,    25,    30,
      33,    36,    41,    44,    46,    48,    51,    53,     0,     0,
       0,    11,     0,     0,    29,     0,    26,    27,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     8,     0,    13,     0,    23,
      31,    32,    34,    35,    40,    39,    37,    38,    42,    43,
      45,    47,    49,    50,     0,     0,     0,    14,     0,     0,
       9,    10,     0,     0,    52,    15,     0,    17,    16,     0,
      18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,    76,   -68,   -68,   -68,   -68,   -68,    -9,   -68,
     -68,   -67,   -68,   -20,    14,    -6,    10,    25,    26,     8,
     -68,    -4,   -12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    15,    86,    87,    96,
      10,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      39,    88,    44,    11,    46,    47,    48,    53,    54,    12,
      13,    45,    19,    18,    20,    21,    61,    14,    19,    22,
      20,    21,    55,    56,    16,    88,    97,     1,     2,    70,
      71,    23,   100,    24,    25,    26,    91,    23,    62,    63,
       3,    92,    40,     4,     1,     2,    43,    74,    75,    76,
      77,    84,    41,    42,    85,    49,    50,     3,    51,    52,
       4,    57,    58,    98,    99,    72,    73,    78,    79,    82,
      83,    59,    64,    60,    65,    67,    66,    68,    69,    89,
      93,    17,    90,    95,    80,    94,    81
};

static const yytype_int8 yycheck[] =
{
      12,    68,    22,    17,    24,    25,    26,    14,    15,    17,
      18,    23,     3,    18,     5,     6,     9,     4,     3,    10,
       5,     6,    29,    30,     0,    92,    93,     3,     4,    49,
      50,    22,    99,    24,    25,    26,    16,    22,    31,    32,
      16,    21,     4,    19,     3,     4,     4,    53,    54,    55,
      56,    63,    20,    21,    66,    27,    28,    16,    24,    25,
      19,    11,    12,    20,    21,    51,    52,    57,    58,    61,
      62,     7,    16,     8,    16,     4,    17,    17,    23,    33,
      19,     5,    16,    92,    59,    89,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    16,    19,    35,    36,    37,    38,    39,
      44,    17,    17,    18,     4,    40,     0,    36,    18,     3,
       5,     6,    10,    22,    24,    25,    26,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    56,
       4,    20,    21,     4,    47,    56,    47,    47,    47,    27,
      28,    24,    25,    14,    15,    29,    30,    11,    12,     7,
       8,     9,    31,    32,    16,    16,    17,     4,    17,    23,
      47,    47,    48,    48,    49,    49,    49,    49,    50,    50,
      51,    52,    53,    53,    56,    56,    41,    42,    45,    33,
      16,    16,    21,    19,    55,    42,    43,    45,    20,    21,
      45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    35,    36,    36,    36,    36,    37,    38,
      38,    39,    40,    40,    41,    41,    42,    43,    43,    44,
      45,    45,    45,    45,    46,    47,    47,    47,    47,    47,
      48,    48,    48,    49,    49,    49,    50,    50,    50,    50,
      50,    51,    51,    51,    52,    52,    53,    53,    54,    54,
      54,    55,    55,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     6,
       6,     3,     1,     3,     1,     3,     4,     1,     3,     4,
       1,     1,     1,     3,     1,     1,     2,     2,     2,     2,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     5,     1
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
  case 2: /* translation_unit: decl  */
#line 85 "RunConfigGrammar.y"
{
}
#line 1287 "RunConfigGrammar.tab.c"
    break;

  case 3: /* translation_unit: translation_unit decl  */
#line 88 "RunConfigGrammar.y"
{
}
#line 1294 "RunConfigGrammar.tab.c"
    break;

  case 8: /* runconfig_decl: SYMBOL '=' expression ';'  */
#line 99 "RunConfigGrammar.y"
{
  NetworkState network_state;
  double value = (yyvsp[-1].expr)->eval(NULL, network_state);
  RunConfig::getInstance()->setParameter((yyvsp[-3].str), value);
}
#line 1304 "RunConfigGrammar.tab.c"
    break;

  case 9: /* node_attr_decl: SYMBOL '.' SYMBOL '=' expression ';'  */
#line 107 "RunConfigGrammar.y"
{
  Node* node = network->getNode((yyvsp[-5].str));
  NetworkState network_state;
  double value = (yyvsp[-1].expr)->eval(NULL, network_state);
  if (!strcasecmp((yyvsp[-3].str), "istate")) {
    if (backward_istate) {
      node->setIState((bool)value);
    } else {
      if (value < 0) {
	new IStateGroup(node);
      } else {
	new IStateGroup(node, (yyvsp[-1].expr));
      }
    }
  } else if (!strcasecmp((yyvsp[-3].str), "is_internal")) {
    node->isInternal((bool)value);
  } else if (!strcasecmp((yyvsp[-3].str), "refstate")) {
    if (value < 0) {
      node->setReference(false);
    } else {
      node->setReferenceState((NodeState)value);
    }
  } else {
    throw BNException(std::string(yy_error_head() + "invalid node attribute: ") + (yyvsp[-3].str) + ", valid attributes are: istate or is_internal");
  }
}
#line 1335 "RunConfigGrammar.tab.c"
    break;

  case 10: /* node_attr_decl: symbol_istate_list '.' SYMBOL '=' istate_expression_list ';'  */
#line 134 "RunConfigGrammar.y"
{
  if (strcasecmp((yyvsp[-3].str), "istate")) {
    throw BNException(std::string(yy_error_head() + "invalid node group attribute: ") + (yyvsp[-3].str) + ", valid attribute is istate");
  }
  std::string error_msg;
  new IStateGroup((yyvsp[-5].node_list), (yyvsp[-1].istate_expr_list), error_msg);
  if (error_msg.length() > 0) {
    throw BNException(std::string(yy_error_head() + error_msg));
  }
}
#line 1350 "RunConfigGrammar.tab.c"
    break;

  case 11: /* symbol_istate_list: '[' symbol_list ']'  */
#line 147 "RunConfigGrammar.y"
{
  (yyval.node_list) = (yyvsp[-1].node_list);
}
#line 1358 "RunConfigGrammar.tab.c"
    break;

  case 12: /* symbol_list: SYMBOL  */
#line 153 "RunConfigGrammar.y"
{
  (yyval.node_list) = new std::vector<const Node*>();
  (yyval.node_list)->push_back(network->getNode((yyvsp[0].str)));
}
#line 1367 "RunConfigGrammar.tab.c"
    break;

  case 13: /* symbol_list: symbol_list ',' SYMBOL  */
#line 158 "RunConfigGrammar.y"
{
  (yyval.node_list) = (yyvsp[-2].node_list);
  (yyval.node_list)->push_back(network->getNode((yyvsp[0].str)));
}
#line 1376 "RunConfigGrammar.tab.c"
    break;

  case 14: /* istate_expression_list: istate_expression  */
#line 165 "RunConfigGrammar.y"
{
  (yyval.istate_expr_list) = new std::vector<IStateGroup::ProbaIState*>();
  (yyval.istate_expr_list)->push_back((yyvsp[0].istate_expr));
}
#line 1385 "RunConfigGrammar.tab.c"
    break;

  case 15: /* istate_expression_list: istate_expression_list ',' istate_expression  */
#line 170 "RunConfigGrammar.y"
{
  (yyval.istate_expr_list) = (yyvsp[-2].istate_expr_list);
  (yyval.istate_expr_list)->push_back((yyvsp[0].istate_expr));
}
#line 1394 "RunConfigGrammar.tab.c"
    break;

  case 16: /* istate_expression: primary_expression '[' expression_list ']'  */
#line 177 "RunConfigGrammar.y"
{
  (yyval.istate_expr) = new IStateGroup::ProbaIState((yyvsp[-3].expr), (yyvsp[-1].expr_list));
}
#line 1402 "RunConfigGrammar.tab.c"
    break;

  case 17: /* expression_list: primary_expression  */
#line 183 "RunConfigGrammar.y"
{
  (yyval.expr_list) = new std::vector<Expression*>();
  (yyval.expr_list)->push_back((yyvsp[0].expr));
}
#line 1411 "RunConfigGrammar.tab.c"
    break;

  case 18: /* expression_list: expression_list ',' primary_expression  */
#line 188 "RunConfigGrammar.y"
{
  (yyval.expr_list) = (yyvsp[-2].expr_list);
  (yyval.expr_list)->push_back((yyvsp[0].expr));
}
#line 1420 "RunConfigGrammar.tab.c"
    break;

  case 19: /* var_decl: VARIABLE '=' expression ';'  */
#line 195 "RunConfigGrammar.y"
{
  SymbolTable* symtab = SymbolTable::getInstance();
  const Symbol* symbol = symtab->getOrMakeSymbol((yyvsp[-3].str));
  NetworkState dummy_state;
  symtab->setSymbolValue(symbol, (yyvsp[-1].expr)->eval(NULL, dummy_state));
}
#line 1431 "RunConfigGrammar.tab.c"
    break;

  case 20: /* primary_expression: INTEGER  */
#line 204 "RunConfigGrammar.y"
{
  (yyval.expr) = new ConstantExpression((yyvsp[0].l));
}
#line 1439 "RunConfigGrammar.tab.c"
    break;

  case 21: /* primary_expression: DOUBLE  */
#line 208 "RunConfigGrammar.y"
{
  (yyval.expr) = new ConstantExpression((yyvsp[0].d));
}
#line 1447 "RunConfigGrammar.tab.c"
    break;

  case 22: /* primary_expression: VARIABLE  */
#line 212 "RunConfigGrammar.y"
{
  (yyval.expr) = new SymbolExpression(SymbolTable::getInstance()->getOrMakeSymbol((yyvsp[0].str)));
}
#line 1455 "RunConfigGrammar.tab.c"
    break;

  case 23: /* primary_expression: '(' expression ')'  */
#line 216 "RunConfigGrammar.y"
{
  (yyval.expr) = new ParenthesisExpression((yyvsp[-1].expr));
}
#line 1463 "RunConfigGrammar.tab.c"
    break;

  case 24: /* postfix_expression: primary_expression  */
#line 222 "RunConfigGrammar.y"
{
  (yyval.expr) = (yyvsp[0].expr);
}
#line 1471 "RunConfigGrammar.tab.c"
    break;

  case 25: /* unary_expression: postfix_expression  */
#line 228 "RunConfigGrammar.y"
{
  (yyval.expr) = (yyvsp[0].expr);
}
#line 1479 "RunConfigGrammar.tab.c"
    break;

  case 26: /* unary_expression: '+' unary_expression  */
#line 232 "RunConfigGrammar.y"
{
  (yyval.expr) = (yyvsp[0].expr);
}
#line 1487 "RunConfigGrammar.tab.c"
    break;

  case 27: /* unary_expression: '-' unary_expression  */
#line 236 "RunConfigGrammar.y"
{
  (yyval.expr) = new SubExpression(new ConstantExpression(0.0), (yyvsp[0].expr));
}
#line 1495 "RunConfigGrammar.tab.c"
    break;

  case 28: /* unary_expression: '!' unary_expression  */
#line 240 "RunConfigGrammar.y"
{
  (yyval.expr) = new NotLogicalExpression((yyvsp[0].expr));
}
#line 1503 "RunConfigGrammar.tab.c"
    break;

  case 29: /* unary_expression: LOGNOT unary_expression  */
#line 244 "RunConfigGrammar.y"
{
  (yyval.expr) = new NotLogicalExpression((yyvsp[0].expr));
}
#line 1511 "RunConfigGrammar.tab.c"
    break;

  case 30: /* multiplicative_expression: unary_expression  */
#line 250 "RunConfigGrammar.y"
{
  (yyval.expr) = (yyvsp[0].expr);
}
#line 1519 "RunConfigGrammar.tab.c"
    break;

  case 31: /* multiplicative_expression: multiplicative_expression '*' unary_expression  */
#line 254 "RunConfigGrammar.y"
{
  (yyval.expr) = new MulExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1527 "RunConfigGrammar.tab.c"
    break;

  case 32: /* multiplicative_expression: multiplicative_expression '/' unary_expression  */
#line 258 "RunConfigGrammar.y"
{
  (yyval.expr) = new DivExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1535 "RunConfigGrammar.tab.c"
    break;

  case 33: /* additive_expression: multiplicative_expression  */
#line 264 "RunConfigGrammar.y"
{
  (yyval.expr) = (yyvsp[0].expr);
}
#line 1543 "RunConfigGrammar.tab.c"
    break;

  case 34: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 268 "RunConfigGrammar.y"
{
  (yyval.expr) = new AddExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1551 "RunConfigGrammar.tab.c"
    break;

  case 35: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 272 "RunConfigGrammar.y"
{
  (yyval.expr) = new SubExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1559 "RunConfigGrammar.tab.c"
    break;

  case 36: /* relational_expression: additive_expression  */
#line 278 "RunConfigGrammar.y"
{
  (yyval.expr) = (yyvsp[0].expr);
}
#line 1567 "RunConfigGrammar.tab.c"
    break;

  case 37: /* relational_expression: relational_expression '<' additive_expression  */
#line 282 "RunConfigGrammar.y"
{
  (yyval.expr) = new LetterExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1575 "RunConfigGrammar.tab.c"
    break;

  case 38: /* relational_expression: relational_expression '>' additive_expression  */
#line 286 "RunConfigGrammar.y"
{
  (yyval.expr) = new GreaterExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1583 "RunConfigGrammar.tab.c"
    break;

  case 39: /* relational_expression: relational_expression LTEQ additive_expression  */
#line 290 "RunConfigGrammar.y"
{
  (yyval.expr) = new LetterOrEqualExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1591 "RunConfigGrammar.tab.c"
    break;

  case 40: /* relational_expression: relational_expression GTEQ additive_expression  */
#line 294 "RunConfigGrammar.y"
{
  (yyval.expr) = new GreaterOrEqualExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1599 "RunConfigGrammar.tab.c"
    break;

  case 41: /* equality_expression: relational_expression  */
#line 300 "RunConfigGrammar.y"
{
  (yyval.expr) = (yyvsp[0].expr);
}
#line 1607 "RunConfigGrammar.tab.c"
    break;

  case 42: /* equality_expression: equality_expression EQUAL relational_expression  */
#line 304 "RunConfigGrammar.y"
{
  (yyval.expr) = new EqualExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1615 "RunConfigGrammar.tab.c"
    break;

  case 43: /* equality_expression: equality_expression NOT_EQUAL relational_expression  */
#line 308 "RunConfigGrammar.y"
{
  (yyval.expr) = new NotEqualExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1623 "RunConfigGrammar.tab.c"
    break;

  case 44: /* logical_and_expression: equality_expression  */
#line 314 "RunConfigGrammar.y"
{
  (yyval.expr) = (yyvsp[0].expr);
}
#line 1631 "RunConfigGrammar.tab.c"
    break;

  case 45: /* logical_and_expression: logical_and_expression LOGAND equality_expression  */
#line 318 "RunConfigGrammar.y"
{
  (yyval.expr) = new AndLogicalExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1639 "RunConfigGrammar.tab.c"
    break;

  case 46: /* logical_or_expression: logical_and_expression  */
#line 324 "RunConfigGrammar.y"
{
  (yyval.expr) = (yyvsp[0].expr);
}
#line 1647 "RunConfigGrammar.tab.c"
    break;

  case 47: /* logical_or_expression: logical_or_expression LOGOR logical_and_expression  */
#line 328 "RunConfigGrammar.y"
{
  (yyval.expr) = new OrLogicalExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1655 "RunConfigGrammar.tab.c"
    break;

  case 48: /* logical_xor_expression: logical_or_expression  */
#line 334 "RunConfigGrammar.y"
{
  (yyval.expr) = (yyvsp[0].expr);
}
#line 1663 "RunConfigGrammar.tab.c"
    break;

  case 49: /* logical_xor_expression: logical_xor_expression LOGXOR logical_or_expression  */
#line 338 "RunConfigGrammar.y"
{
  (yyval.expr) = new XorLogicalExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1671 "RunConfigGrammar.tab.c"
    break;

  case 50: /* logical_xor_expression: logical_xor_expression '^' logical_or_expression  */
#line 342 "RunConfigGrammar.y"
{
  (yyval.expr) = new XorLogicalExpression((yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1679 "RunConfigGrammar.tab.c"
    break;

  case 51: /* conditional_expression: logical_xor_expression  */
#line 348 "RunConfigGrammar.y"
{
  (yyval.expr) = (yyvsp[0].expr);
}
#line 1687 "RunConfigGrammar.tab.c"
    break;

  case 52: /* conditional_expression: logical_xor_expression '?' expression ':' conditional_expression  */
#line 352 "RunConfigGrammar.y"
{
  (yyval.expr) = new CondExpression((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));
}
#line 1695 "RunConfigGrammar.tab.c"
    break;

  case 53: /* expression: conditional_expression  */
#line 358 "RunConfigGrammar.y"
{
  (yyval.expr) = (yyvsp[0].expr);
}
#line 1703 "RunConfigGrammar.tab.c"
    break;


#line 1707 "RunConfigGrammar.tab.c"

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

#line 363 "RunConfigGrammar.y"


void runconfig_setNetwork(Network* _network)
{
  network = _network;
}

#include "lex.RC.cc"
