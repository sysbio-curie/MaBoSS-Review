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
   especially those whose name start with YY_ or CTBNDL_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with CTBNDL or YY, to avoid
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
#line 2 "BooleanGrammar.y"

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
     BooleanGrammar.y

   Authors:
     Eric Viara <viara@sysra.com>
     Gautier Stoll <gautier.stoll@curie.fr>
 
   Date:
     January-March 2011
*/

#include "BooleanGrammar.h"

extern int CTBNDLlex();
static void CTBNDLerror(const char *s);
// MAP<std::string, bool> NodeDecl::node_def_map;
static Network* current_network;

#line 111 "BooleanGrammar.tab.c"

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
extern int CTBNDLdebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum CTBNDLtokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    VARIABLE = 259,                /* VARIABLE  */
    STRING = 260,                  /* STRING  */
    DOUBLE = 261,                  /* DOUBLE  */
    INTEGER = 262,                 /* INTEGER  */
    LOGAND = 263,                  /* LOGAND  */
    LOGOR = 264,                   /* LOGOR  */
    LOGXOR = 265,                  /* LOGXOR  */
    LOGNOT = 266,                  /* LOGNOT  */
    EQUAL = 267,                   /* EQUAL  */
    NOT_EQUAL = 268,               /* NOT_EQUAL  */
    NODE = 269,                    /* NODE  */
    GTEQ = 270,                    /* GTEQ  */
    LTEQ = 271                     /* LTEQ  */
  };
  typedef enum CTBNDLtokentype CTBNDLtoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "BooleanGrammar.y"

  std::vector<NodeDecl*>* node_decl_list;
  NodeDecl* node_decl;
  std::vector<NodeDeclItem*>* node_decl_item_list;
  NodeDeclItem* node_decl_item;
  Expression* expr;
  ArgumentList* arg_list;
  char* str;
  double d;
  long long l;

#line 186 "BooleanGrammar.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE CTBNDLlval;


int CTBNDLparse (void);



/* Symbol kind.  */
enum CTBNDLsymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_VARIABLE = 4,                   /* VARIABLE  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_DOUBLE = 6,                     /* DOUBLE  */
  YYSYMBOL_INTEGER = 7,                    /* INTEGER  */
  YYSYMBOL_LOGAND = 8,                     /* LOGAND  */
  YYSYMBOL_LOGOR = 9,                      /* LOGOR  */
  YYSYMBOL_LOGXOR = 10,                    /* LOGXOR  */
  YYSYMBOL_LOGNOT = 11,                    /* LOGNOT  */
  YYSYMBOL_EQUAL = 12,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 13,                 /* NOT_EQUAL  */
  YYSYMBOL_NODE = 14,                      /* NODE  */
  YYSYMBOL_GTEQ = 15,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 16,                      /* LTEQ  */
  YYSYMBOL_17_ = 17,                       /* '{'  */
  YYSYMBOL_18_ = 18,                       /* '}'  */
  YYSYMBOL_19_ = 19,                       /* ':'  */
  YYSYMBOL_20_ = 20,                       /* ','  */
  YYSYMBOL_21_ = 21,                       /* '='  */
  YYSYMBOL_22_ = 22,                       /* ';'  */
  YYSYMBOL_23_ = 23,                       /* '@'  */
  YYSYMBOL_24_ = 24,                       /* '('  */
  YYSYMBOL_25_ = 25,                       /* ')'  */
  YYSYMBOL_26_ = 26,                       /* '+'  */
  YYSYMBOL_27_ = 27,                       /* '-'  */
  YYSYMBOL_28_ = 28,                       /* '!'  */
  YYSYMBOL_29_ = 29,                       /* '*'  */
  YYSYMBOL_30_ = 30,                       /* '/'  */
  YYSYMBOL_31_ = 31,                       /* '<'  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_33_ = 33,                       /* '^'  */
  YYSYMBOL_34_ = 34,                       /* '?'  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_translation_unit = 36,          /* translation_unit  */
  YYSYMBOL_node_decl = 37,                 /* node_decl  */
  YYSYMBOL_colon_comma = 38,               /* colon_comma  */
  YYSYMBOL_node_decl_item_list = 39,       /* node_decl_item_list  */
  YYSYMBOL_node_decl_item = 40,            /* node_decl_item  */
  YYSYMBOL_primary_expression = 41,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 42,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 43,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 44,          /* unary_expression  */
  YYSYMBOL_multiplicative_expression = 45, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 46,       /* additive_expression  */
  YYSYMBOL_relational_expression = 47,     /* relational_expression  */
  YYSYMBOL_equality_expression = 48,       /* equality_expression  */
  YYSYMBOL_logical_and_expression = 49,    /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 50,     /* logical_or_expression  */
  YYSYMBOL_logical_xor_expression = 51,    /* logical_xor_expression  */
  YYSYMBOL_conditional_expression = 52,    /* conditional_expression  */
  YYSYMBOL_expression = 53,                /* expression  */
  YYSYMBOL_term_opt = 54                   /* term_opt  */
};
typedef enum CTBNDLsymbol_kind_t CTBNDLsymbol_kind_t;




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
typedef __INT_LEAST8_TYPE__ CTBNDLtype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t CTBNDLtype_int8;
#else
typedef signed char CTBNDLtype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ CTBNDLtype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t CTBNDLtype_int16;
#else
typedef short CTBNDLtype_int16;
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
typedef __UINT_LEAST8_TYPE__ CTBNDLtype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t CTBNDLtype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char CTBNDLtype_uint8;
#else
typedef short CTBNDLtype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ CTBNDLtype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t CTBNDLtype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short CTBNDLtype_uint16;
#else
typedef int CTBNDLtype_uint16;
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
typedef CTBNDLtype_int8 CTBNDL_state_t;

/* State numbers in computations.  */
typedef int CTBNDL_state_fast_t;

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

/* Suppress an incorrect diagnostic about CTBNDLlval being uninitialized.  */
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

#if !defined CTBNDLoverflow

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
#endif /* !defined CTBNDLoverflow */

#if (! defined CTBNDLoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union CTBNDLalloc
{
  CTBNDL_state_t CTBNDLss_alloc;
  YYSTYPE CTBNDLvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union CTBNDLalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (CTBNDL_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T CTBNDLnewbytes;                                         \
        YYCOPY (&CTBNDLptr->Stack_alloc, Stack, CTBNDLsize);                    \
        Stack = &CTBNDLptr->Stack_alloc;                                    \
        CTBNDLnewbytes = CTBNDLstacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        CTBNDLptr += CTBNDLnewbytes / YYSIZEOF (*CTBNDLptr);                        \
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
          YYPTRDIFF_T CTBNDLi;                      \
          for (CTBNDLi = 0; CTBNDLi < (Count); CTBNDLi++)   \
            (Dst)[CTBNDLi] = (Src)[CTBNDLi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   99

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  93

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   271


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by CTBNDLlex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (CTBNDLsymbol_kind_t, CTBNDLtranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by CTBNDLlex.  */
static const CTBNDLtype_int8 CTBNDLtranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,     2,     2,     2,     2,     2,
      24,    25,    29,    26,    20,    27,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    19,    22,
      31,    21,    32,    34,    23,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,    18,     2,     2,     2,     2,
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
      15,    16
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const CTBNDLtype_int16 CTBNDLrline[] =
{
       0,    82,    82,    87,    94,    98,   102,   111,   113,   117,
     122,   129,   133,   139,   144,   148,   152,   156,   160,   166,
     170,   174,   180,   185,   192,   196,   200,   204,   208,   214,
     218,   222,   228,   232,   236,   242,   246,   250,   254,   258,
     264,   268,   272,   278,   282,   288,   292,   298,   302,   306,
     312,   316,   322,   328,   329
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (CTBNDLsymbol_kind_t, CTBNDLstos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *CTBNDLsymbol_name (CTBNDLsymbol_kind_t CTBNDLsymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const CTBNDLtname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "VARIABLE", "STRING", "DOUBLE", "INTEGER", "LOGAND", "LOGOR", "LOGXOR",
  "LOGNOT", "EQUAL", "NOT_EQUAL", "NODE", "GTEQ", "LTEQ", "'{'", "'}'",
  "':'", "','", "'='", "';'", "'@'", "'('", "')'", "'+'", "'-'", "'!'",
  "'*'", "'/'", "'<'", "'>'", "'^'", "'?'", "$accept", "translation_unit",
  "node_decl", "colon_comma", "node_decl_item_list", "node_decl_item",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "logical_xor_expression",
  "conditional_expression", "expression", "term_opt", YY_NULLPTR
};

static const char *
CTBNDLsymbol_name (CTBNDLsymbol_kind_t CTBNDLsymbol)
{
  return CTBNDLtname[CTBNDLsymbol];
}
#endif

#define YYPACT_NINF (-34)

#define CTBNDLpact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define CTBNDLtable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const CTBNDLtype_int8 CTBNDLpact[] =
{
       1,    36,     0,    58,   -34,   -34,   -34,    43,    -1,   -34,
     -34,    21,   -34,   -34,   -34,    43,    45,    43,    43,    43,
      43,   -34,   -34,   -34,    33,    51,    -7,    67,    49,    56,
      26,   -34,    46,    23,     7,   -34,   -34,    61,   -34,   -34,
     -34,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,   -34,   -34,    62,   -34,
      34,   -34,   -34,    -8,   -34,   -34,   -34,   -34,    33,    33,
      51,    51,    51,    51,    -7,    -7,    67,    49,    56,    56,
      68,    16,   -34,   -34,    43,   -34,    43,    66,    70,   -34,
     -34,   -34,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const CTBNDLtype_int8 CTBNDLdefact[] =
{
       0,     0,     0,     0,     2,     7,     8,     0,     0,     1,
       3,    13,    15,    17,    16,     0,     0,     0,     0,     0,
       0,    19,    24,    29,    32,    35,    40,    43,    45,    47,
      50,    52,    53,     0,     0,    28,    14,     0,    25,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     6,     0,     5,
       0,     9,    21,     0,    22,    18,    30,    31,    33,    34,
      39,    38,    36,    37,    41,    42,    44,    46,    48,    49,
       0,     0,     4,    10,     0,    20,     0,     0,     0,    23,
      51,    12,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const CTBNDLtype_int8 CTBNDLpgoto[] =
{
     -34,   -34,    86,   -34,   -34,    39,   -34,   -34,   -34,   -13,
      38,    28,    35,    42,    44,    37,   -34,   -33,   -17,   -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const CTBNDLtype_int8 CTBNDLdefgoto[] =
{
       0,     3,     4,     7,    60,    61,    21,    22,    63,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const CTBNDLtype_int8 CTBNDLtable[] =
{
      37,    64,    35,     8,     1,    38,    39,    40,    45,    46,
      11,    12,    84,    13,    14,     2,    33,    85,    15,    11,
      12,    87,    13,    14,    47,    48,    58,    15,    66,    67,
      16,    17,    62,    18,    19,    20,    53,    58,    80,    16,
      17,    59,    18,    19,    20,    34,    11,    12,    36,    13,
      14,    89,    82,    90,    15,     5,     6,    51,     9,    54,
      55,     1,    41,    42,    88,    52,    16,    17,    56,    18,
      19,    20,     2,    70,    71,    72,    73,    43,    44,    49,
      50,    68,    69,    81,    74,    75,    65,    86,    91,    10,
      78,    79,    92,    76,     0,     0,    77,     0,     0,    83
};

static const CTBNDLtype_int8 CTBNDLcheck[] =
{
      17,    34,    15,     3,     3,    18,    19,    20,    15,    16,
       3,     4,    20,     6,     7,    14,    17,    25,    11,     3,
       4,     5,     6,     7,    31,    32,     3,    11,    41,    42,
      23,    24,    25,    26,    27,    28,    10,     3,    55,    23,
      24,    18,    26,    27,    28,    24,     3,     4,     3,     6,
       7,    84,    18,    86,    11,    19,    20,     8,     0,    33,
      34,     3,    29,    30,    81,     9,    23,    24,    22,    26,
      27,    28,    14,    45,    46,    47,    48,    26,    27,    12,
      13,    43,    44,    21,    49,    50,    25,    19,    22,     3,
      53,    54,    22,    51,    -1,    -1,    52,    -1,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const CTBNDLtype_int8 CTBNDLstos[] =
{
       0,     3,    14,    36,    37,    19,    20,    38,     3,     0,
      37,     3,     4,     6,     7,    11,    23,    24,    26,    27,
      28,    41,    42,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    17,    24,    44,     3,    53,    44,    44,
      44,    29,    30,    26,    27,    15,    16,    31,    32,    12,
      13,     8,     9,    10,    33,    34,    22,    54,     3,    18,
      39,    40,    25,    43,    52,    25,    44,    44,    45,    45,
      46,    46,    46,    46,    47,    47,    48,    49,    50,    50,
      53,    21,    18,    40,    20,    25,    19,     5,    53,    52,
      52,    22,    22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const CTBNDLtype_int8 CTBNDLr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    38,    38,    39,
      39,    40,    40,    41,    41,    41,    41,    41,    41,    42,
      42,    42,    43,    43,    44,    44,    44,    44,    44,    45,
      45,    45,    46,    46,    46,    47,    47,    47,    47,    47,
      48,    48,    48,    49,    49,    50,    50,    51,    51,    51,
      52,    52,    53,    54,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const CTBNDLtype_int8 CTBNDLr2[] =
{
       0,     2,     1,     2,     5,     4,     4,     1,     1,     1,
       2,     4,     4,     1,     2,     1,     1,     1,     3,     1,
       4,     3,     1,     3,     1,     2,     2,     2,     2,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     5,     1,     0,     1
};


enum { YYENOMEM = -2 };

#define CTBNDLerrok         (CTBNDLerrstatus = 0)
#define CTBNDLclearin       (CTBNDLchar = YYEMPTY)

#define YYACCEPT        goto CTBNDLacceptlab
#define YYABORT         goto CTBNDLabortlab
#define YYERROR         goto CTBNDLerrorlab
#define YYNOMEM         goto CTBNDLexhaustedlab


#define YYRECOVERING()  (!!CTBNDLerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (CTBNDLchar == YYEMPTY)                                        \
      {                                                           \
        CTBNDLchar = (Token);                                         \
        CTBNDLlval = (Value);                                         \
        YYPOPSTACK (CTBNDLlen);                                       \
        CTBNDLstate = *CTBNDLssp;                                         \
        goto CTBNDLbackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        CTBNDLerror (YY_("syntax error: cannot back up")); \
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
  if (CTBNDLdebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (CTBNDLdebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      CTBNDL_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
CTBNDL_symbol_value_print (FILE *CTBNDLo,
                       CTBNDLsymbol_kind_t CTBNDLkind, YYSTYPE const * const CTBNDLvaluep)
{
  FILE *CTBNDLoutput = CTBNDLo;
  YY_USE (CTBNDLoutput);
  if (!CTBNDLvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (CTBNDLkind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
CTBNDL_symbol_print (FILE *CTBNDLo,
                 CTBNDLsymbol_kind_t CTBNDLkind, YYSTYPE const * const CTBNDLvaluep)
{
  YYFPRINTF (CTBNDLo, "%s %s (",
             CTBNDLkind < YYNTOKENS ? "token" : "nterm", CTBNDLsymbol_name (CTBNDLkind));

  CTBNDL_symbol_value_print (CTBNDLo, CTBNDLkind, CTBNDLvaluep);
  YYFPRINTF (CTBNDLo, ")");
}

/*------------------------------------------------------------------.
| CTBNDL_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
CTBNDL_stack_print (CTBNDL_state_t *CTBNDLbottom, CTBNDL_state_t *CTBNDLtop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; CTBNDLbottom <= CTBNDLtop; CTBNDLbottom++)
    {
      int CTBNDLbot = *CTBNDLbottom;
      YYFPRINTF (stderr, " %d", CTBNDLbot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (CTBNDLdebug)                                                  \
    CTBNDL_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
CTBNDL_reduce_print (CTBNDL_state_t *CTBNDLssp, YYSTYPE *CTBNDLvsp,
                 int CTBNDLrule)
{
  int CTBNDLlno = CTBNDLrline[CTBNDLrule];
  int CTBNDLnrhs = CTBNDLr2[CTBNDLrule];
  int CTBNDLi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             CTBNDLrule - 1, CTBNDLlno);
  /* The symbols being reduced.  */
  for (CTBNDLi = 0; CTBNDLi < CTBNDLnrhs; CTBNDLi++)
    {
      YYFPRINTF (stderr, "   $%d = ", CTBNDLi + 1);
      CTBNDL_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+CTBNDLssp[CTBNDLi + 1 - CTBNDLnrhs]),
                       &CTBNDLvsp[(CTBNDLi + 1) - (CTBNDLnrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (CTBNDLdebug)                          \
    CTBNDL_reduce_print (CTBNDLssp, CTBNDLvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int CTBNDLdebug;
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
CTBNDLdestruct (const char *CTBNDLmsg,
            CTBNDLsymbol_kind_t CTBNDLkind, YYSTYPE *CTBNDLvaluep)
{
  YY_USE (CTBNDLvaluep);
  if (!CTBNDLmsg)
    CTBNDLmsg = "Deleting";
  YY_SYMBOL_PRINT (CTBNDLmsg, CTBNDLkind, CTBNDLvaluep, CTBNDLlocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (CTBNDLkind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int CTBNDLchar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE CTBNDLlval;
/* Number of syntax errors so far.  */
int CTBNDLnerrs;




/*----------.
| CTBNDLparse.  |
`----------*/

int
CTBNDLparse (void)
{
    CTBNDL_state_fast_t CTBNDLstate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int CTBNDLerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow CTBNDLoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T CTBNDLstacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    CTBNDL_state_t CTBNDLssa[YYINITDEPTH];
    CTBNDL_state_t *CTBNDLss = CTBNDLssa;
    CTBNDL_state_t *CTBNDLssp = CTBNDLss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE CTBNDLvsa[YYINITDEPTH];
    YYSTYPE *CTBNDLvs = CTBNDLvsa;
    YYSTYPE *CTBNDLvsp = CTBNDLvs;

  int CTBNDLn;
  /* The return value of CTBNDLparse.  */
  int CTBNDLresult;
  /* Lookahead symbol kind.  */
  CTBNDLsymbol_kind_t CTBNDLtoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE CTBNDLval;



#define YYPOPSTACK(N)   (CTBNDLvsp -= (N), CTBNDLssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int CTBNDLlen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  CTBNDLchar = YYEMPTY; /* Cause a token to be read.  */

  goto CTBNDLsetstate;


/*------------------------------------------------------------.
| CTBNDLnewstate -- push a new state, which is found in CTBNDLstate.  |
`------------------------------------------------------------*/
CTBNDLnewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  CTBNDLssp++;


/*--------------------------------------------------------------------.
| CTBNDLsetstate -- set current state (the top of the stack) to CTBNDLstate.  |
`--------------------------------------------------------------------*/
CTBNDLsetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", CTBNDLstate));
  YY_ASSERT (0 <= CTBNDLstate && CTBNDLstate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *CTBNDLssp = YY_CAST (CTBNDL_state_t, CTBNDLstate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (CTBNDLss, CTBNDLssp);

  if (CTBNDLss + CTBNDLstacksize - 1 <= CTBNDLssp)
#if !defined CTBNDLoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T CTBNDLsize = CTBNDLssp - CTBNDLss + 1;

# if defined CTBNDLoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        CTBNDL_state_t *CTBNDLss1 = CTBNDLss;
        YYSTYPE *CTBNDLvs1 = CTBNDLvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if CTBNDLoverflow is a macro.  */
        CTBNDLoverflow (YY_("memory exhausted"),
                    &CTBNDLss1, CTBNDLsize * YYSIZEOF (*CTBNDLssp),
                    &CTBNDLvs1, CTBNDLsize * YYSIZEOF (*CTBNDLvsp),
                    &CTBNDLstacksize);
        CTBNDLss = CTBNDLss1;
        CTBNDLvs = CTBNDLvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= CTBNDLstacksize)
        YYNOMEM;
      CTBNDLstacksize *= 2;
      if (YYMAXDEPTH < CTBNDLstacksize)
        CTBNDLstacksize = YYMAXDEPTH;

      {
        CTBNDL_state_t *CTBNDLss1 = CTBNDLss;
        union CTBNDLalloc *CTBNDLptr =
          YY_CAST (union CTBNDLalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (CTBNDLstacksize))));
        if (! CTBNDLptr)
          YYNOMEM;
        YYSTACK_RELOCATE (CTBNDLss_alloc, CTBNDLss);
        YYSTACK_RELOCATE (CTBNDLvs_alloc, CTBNDLvs);
#  undef YYSTACK_RELOCATE
        if (CTBNDLss1 != CTBNDLssa)
          YYSTACK_FREE (CTBNDLss1);
      }
# endif

      CTBNDLssp = CTBNDLss + CTBNDLsize - 1;
      CTBNDLvsp = CTBNDLvs + CTBNDLsize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, CTBNDLstacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (CTBNDLss + CTBNDLstacksize - 1 <= CTBNDLssp)
        YYABORT;
    }
#endif /* !defined CTBNDLoverflow && !defined YYSTACK_RELOCATE */


  if (CTBNDLstate == YYFINAL)
    YYACCEPT;

  goto CTBNDLbackup;


/*-----------.
| CTBNDLbackup.  |
`-----------*/
CTBNDLbackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  CTBNDLn = CTBNDLpact[CTBNDLstate];
  if (CTBNDLpact_value_is_default (CTBNDLn))
    goto CTBNDLdefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (CTBNDLchar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      CTBNDLchar = CTBNDLlex ();
    }

  if (CTBNDLchar <= YYEOF)
    {
      CTBNDLchar = YYEOF;
      CTBNDLtoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (CTBNDLchar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      CTBNDLchar = YYUNDEF;
      CTBNDLtoken = YYSYMBOL_YYerror;
      goto CTBNDLerrlab1;
    }
  else
    {
      CTBNDLtoken = YYTRANSLATE (CTBNDLchar);
      YY_SYMBOL_PRINT ("Next token is", CTBNDLtoken, &CTBNDLlval, &CTBNDLlloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  CTBNDLn += CTBNDLtoken;
  if (CTBNDLn < 0 || YYLAST < CTBNDLn || CTBNDLcheck[CTBNDLn] != CTBNDLtoken)
    goto CTBNDLdefault;
  CTBNDLn = CTBNDLtable[CTBNDLn];
  if (CTBNDLn <= 0)
    {
      if (CTBNDLtable_value_is_error (CTBNDLn))
        goto CTBNDLerrlab;
      CTBNDLn = -CTBNDLn;
      goto CTBNDLreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (CTBNDLerrstatus)
    CTBNDLerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", CTBNDLtoken, &CTBNDLlval, &CTBNDLlloc);
  CTBNDLstate = CTBNDLn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++CTBNDLvsp = CTBNDLlval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  CTBNDLchar = YYEMPTY;
  goto CTBNDLnewstate;


/*-----------------------------------------------------------.
| CTBNDLdefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
CTBNDLdefault:
  CTBNDLn = CTBNDLdefact[CTBNDLstate];
  if (CTBNDLn == 0)
    goto CTBNDLerrlab;
  goto CTBNDLreduce;


/*-----------------------------.
| CTBNDLreduce -- do a reduction.  |
`-----------------------------*/
CTBNDLreduce:
  /* CTBNDLn is the number of a rule to reduce with.  */
  CTBNDLlen = CTBNDLr2[CTBNDLn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  CTBNDLval = CTBNDLvsp[1-CTBNDLlen];


  YY_REDUCE_PRINT (CTBNDLn);
  switch (CTBNDLn)
    {
  case 2: /* translation_unit: node_decl  */
#line 83 "BooleanGrammar.y"
{
  (CTBNDLval.node_decl_list) = new std::vector<NodeDecl*>();
  (CTBNDLval.node_decl_list)->push_back((CTBNDLvsp[0].node_decl));
}
#line 1281 "BooleanGrammar.tab.c"
    break;

  case 3: /* translation_unit: translation_unit node_decl  */
#line 88 "BooleanGrammar.y"
{
  (CTBNDLvsp[-1].node_decl_list)->push_back((CTBNDLvsp[0].node_decl));
  (CTBNDLval.node_decl_list) = (CTBNDLvsp[-1].node_decl_list);
}
#line 1290 "BooleanGrammar.tab.c"
    break;

  case 4: /* node_decl: NODE IDENTIFIER '{' node_decl_item_list '}'  */
#line 95 "BooleanGrammar.y"
{
  (CTBNDLval.node_decl) = new NodeDecl((CTBNDLvsp[-3].str), (CTBNDLvsp[-1].node_decl_item_list));
}
#line 1298 "BooleanGrammar.tab.c"
    break;

  case 5: /* node_decl: NODE IDENTIFIER '{' '}'  */
#line 99 "BooleanGrammar.y"
{
  (CTBNDLval.node_decl) = new NodeDecl((CTBNDLvsp[-2].str), NULL);
}
#line 1306 "BooleanGrammar.tab.c"
    break;

  case 6: /* node_decl: IDENTIFIER colon_comma expression term_opt  */
#line 103 "BooleanGrammar.y"
{
  NodeDeclItem* decl_item = new NodeDeclItem("logic", (CTBNDLvsp[-1].expr));
  std::vector<NodeDeclItem*>* decl_item_v = new std::vector<NodeDeclItem*>();
  decl_item_v->push_back(decl_item);
  (CTBNDLval.node_decl) = new NodeDecl((CTBNDLvsp[-3].str), decl_item_v);
}
#line 1317 "BooleanGrammar.tab.c"
    break;

  case 7: /* colon_comma: ':'  */
#line 112 "BooleanGrammar.y"
{}
#line 1323 "BooleanGrammar.tab.c"
    break;

  case 8: /* colon_comma: ','  */
#line 114 "BooleanGrammar.y"
{}
#line 1329 "BooleanGrammar.tab.c"
    break;

  case 9: /* node_decl_item_list: node_decl_item  */
#line 118 "BooleanGrammar.y"
{
  (CTBNDLval.node_decl_item_list) = new std::vector<NodeDeclItem*>();
  (CTBNDLval.node_decl_item_list)->push_back((CTBNDLvsp[0].node_decl_item));
}
#line 1338 "BooleanGrammar.tab.c"
    break;

  case 10: /* node_decl_item_list: node_decl_item_list node_decl_item  */
#line 123 "BooleanGrammar.y"
{
  (CTBNDLvsp[-1].node_decl_item_list)->push_back((CTBNDLvsp[0].node_decl_item));
  (CTBNDLval.node_decl_item_list) = (CTBNDLvsp[-1].node_decl_item_list);
}
#line 1347 "BooleanGrammar.tab.c"
    break;

  case 11: /* node_decl_item: IDENTIFIER '=' expression ';'  */
#line 130 "BooleanGrammar.y"
{
  (CTBNDLval.node_decl_item) = new NodeDeclItem((CTBNDLvsp[-3].str), (CTBNDLvsp[-1].expr));
}
#line 1355 "BooleanGrammar.tab.c"
    break;

  case 12: /* node_decl_item: IDENTIFIER '=' STRING ';'  */
#line 134 "BooleanGrammar.y"
{
  (CTBNDLval.node_decl_item) = new NodeDeclItem((CTBNDLvsp[-3].str), (CTBNDLvsp[-1].str));
}
#line 1363 "BooleanGrammar.tab.c"
    break;

  case 13: /* primary_expression: IDENTIFIER  */
#line 140 "BooleanGrammar.y"
{
  Node* node = current_network->getOrMakeNode((CTBNDLvsp[0].str));
  (CTBNDLval.expr) = new NodeExpression(node);
}
#line 1372 "BooleanGrammar.tab.c"
    break;

  case 14: /* primary_expression: '@' IDENTIFIER  */
#line 145 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new AliasExpression((CTBNDLvsp[0].str));
}
#line 1380 "BooleanGrammar.tab.c"
    break;

  case 15: /* primary_expression: VARIABLE  */
#line 149 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new SymbolExpression(SymbolTable::getInstance()->getOrMakeSymbol((CTBNDLvsp[0].str)));
}
#line 1388 "BooleanGrammar.tab.c"
    break;

  case 16: /* primary_expression: INTEGER  */
#line 153 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new ConstantExpression((CTBNDLvsp[0].l));
}
#line 1396 "BooleanGrammar.tab.c"
    break;

  case 17: /* primary_expression: DOUBLE  */
#line 157 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new ConstantExpression((CTBNDLvsp[0].d));
}
#line 1404 "BooleanGrammar.tab.c"
    break;

  case 18: /* primary_expression: '(' expression ')'  */
#line 161 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new ParenthesisExpression((CTBNDLvsp[-1].expr));
}
#line 1412 "BooleanGrammar.tab.c"
    break;

  case 19: /* postfix_expression: primary_expression  */
#line 167 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = (CTBNDLvsp[0].expr);
}
#line 1420 "BooleanGrammar.tab.c"
    break;

  case 20: /* postfix_expression: IDENTIFIER '(' argument_expression_list ')'  */
#line 171 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new FuncCallExpression((CTBNDLvsp[-3].str), (CTBNDLvsp[-1].arg_list));
}
#line 1428 "BooleanGrammar.tab.c"
    break;

  case 21: /* postfix_expression: IDENTIFIER '(' ')'  */
#line 175 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new FuncCallExpression((CTBNDLvsp[-2].str), NULL);
}
#line 1436 "BooleanGrammar.tab.c"
    break;

  case 22: /* argument_expression_list: conditional_expression  */
#line 181 "BooleanGrammar.y"
{
  (CTBNDLval.arg_list) = new ArgumentList();
  (CTBNDLval.arg_list)->push_back((CTBNDLvsp[0].expr));
}
#line 1445 "BooleanGrammar.tab.c"
    break;

  case 23: /* argument_expression_list: argument_expression_list ',' conditional_expression  */
#line 186 "BooleanGrammar.y"
{
  (CTBNDLval.arg_list) = (CTBNDLvsp[-2].arg_list);
  (CTBNDLval.arg_list)->push_back((CTBNDLvsp[0].expr));
}
#line 1454 "BooleanGrammar.tab.c"
    break;

  case 24: /* unary_expression: postfix_expression  */
#line 193 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = (CTBNDLvsp[0].expr);
}
#line 1462 "BooleanGrammar.tab.c"
    break;

  case 25: /* unary_expression: '+' unary_expression  */
#line 197 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = (CTBNDLvsp[0].expr);
}
#line 1470 "BooleanGrammar.tab.c"
    break;

  case 26: /* unary_expression: '-' unary_expression  */
#line 201 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new SubExpression(new ConstantExpression(0.0), (CTBNDLvsp[0].expr));
}
#line 1478 "BooleanGrammar.tab.c"
    break;

  case 27: /* unary_expression: '!' unary_expression  */
#line 205 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new NotLogicalExpression((CTBNDLvsp[0].expr));
}
#line 1486 "BooleanGrammar.tab.c"
    break;

  case 28: /* unary_expression: LOGNOT unary_expression  */
#line 209 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new NotLogicalExpression((CTBNDLvsp[0].expr));
}
#line 1494 "BooleanGrammar.tab.c"
    break;

  case 29: /* multiplicative_expression: unary_expression  */
#line 215 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = (CTBNDLvsp[0].expr);
}
#line 1502 "BooleanGrammar.tab.c"
    break;

  case 30: /* multiplicative_expression: multiplicative_expression '*' unary_expression  */
#line 219 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new MulExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1510 "BooleanGrammar.tab.c"
    break;

  case 31: /* multiplicative_expression: multiplicative_expression '/' unary_expression  */
#line 223 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new DivExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1518 "BooleanGrammar.tab.c"
    break;

  case 32: /* additive_expression: multiplicative_expression  */
#line 229 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = (CTBNDLvsp[0].expr);
}
#line 1526 "BooleanGrammar.tab.c"
    break;

  case 33: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 233 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new AddExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1534 "BooleanGrammar.tab.c"
    break;

  case 34: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 237 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new SubExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1542 "BooleanGrammar.tab.c"
    break;

  case 35: /* relational_expression: additive_expression  */
#line 243 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = (CTBNDLvsp[0].expr);
}
#line 1550 "BooleanGrammar.tab.c"
    break;

  case 36: /* relational_expression: relational_expression '<' additive_expression  */
#line 247 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new LetterExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1558 "BooleanGrammar.tab.c"
    break;

  case 37: /* relational_expression: relational_expression '>' additive_expression  */
#line 251 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new GreaterExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1566 "BooleanGrammar.tab.c"
    break;

  case 38: /* relational_expression: relational_expression LTEQ additive_expression  */
#line 255 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new LetterOrEqualExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1574 "BooleanGrammar.tab.c"
    break;

  case 39: /* relational_expression: relational_expression GTEQ additive_expression  */
#line 259 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new GreaterOrEqualExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1582 "BooleanGrammar.tab.c"
    break;

  case 40: /* equality_expression: relational_expression  */
#line 265 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = (CTBNDLvsp[0].expr);
}
#line 1590 "BooleanGrammar.tab.c"
    break;

  case 41: /* equality_expression: equality_expression EQUAL relational_expression  */
#line 269 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new EqualExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1598 "BooleanGrammar.tab.c"
    break;

  case 42: /* equality_expression: equality_expression NOT_EQUAL relational_expression  */
#line 273 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new NotEqualExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1606 "BooleanGrammar.tab.c"
    break;

  case 43: /* logical_and_expression: equality_expression  */
#line 279 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = (CTBNDLvsp[0].expr);
}
#line 1614 "BooleanGrammar.tab.c"
    break;

  case 44: /* logical_and_expression: logical_and_expression LOGAND equality_expression  */
#line 283 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new AndLogicalExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1622 "BooleanGrammar.tab.c"
    break;

  case 45: /* logical_or_expression: logical_and_expression  */
#line 289 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = (CTBNDLvsp[0].expr);
}
#line 1630 "BooleanGrammar.tab.c"
    break;

  case 46: /* logical_or_expression: logical_or_expression LOGOR logical_and_expression  */
#line 293 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new OrLogicalExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1638 "BooleanGrammar.tab.c"
    break;

  case 47: /* logical_xor_expression: logical_or_expression  */
#line 299 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = (CTBNDLvsp[0].expr);
}
#line 1646 "BooleanGrammar.tab.c"
    break;

  case 48: /* logical_xor_expression: logical_xor_expression LOGXOR logical_or_expression  */
#line 303 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new XorLogicalExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1654 "BooleanGrammar.tab.c"
    break;

  case 49: /* logical_xor_expression: logical_xor_expression '^' logical_or_expression  */
#line 307 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new XorLogicalExpression((CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1662 "BooleanGrammar.tab.c"
    break;

  case 50: /* conditional_expression: logical_xor_expression  */
#line 313 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = (CTBNDLvsp[0].expr);
}
#line 1670 "BooleanGrammar.tab.c"
    break;

  case 51: /* conditional_expression: logical_xor_expression '?' expression ':' conditional_expression  */
#line 317 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = new CondExpression((CTBNDLvsp[-4].expr), (CTBNDLvsp[-2].expr), (CTBNDLvsp[0].expr));
}
#line 1678 "BooleanGrammar.tab.c"
    break;

  case 52: /* expression: conditional_expression  */
#line 323 "BooleanGrammar.y"
{
  (CTBNDLval.expr) = (CTBNDLvsp[0].expr);
}
#line 1686 "BooleanGrammar.tab.c"
    break;


#line 1690 "BooleanGrammar.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter CTBNDLchar, and that requires
     that CTBNDLtoken be updated with the new translation.  We take the
     approach of translating immediately before every use of CTBNDLtoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering CTBNDLchar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (CTBNDLsymbol_kind_t, CTBNDLr1[CTBNDLn]), &CTBNDLval, &CTBNDLloc);

  YYPOPSTACK (CTBNDLlen);
  CTBNDLlen = 0;

  *++CTBNDLvsp = CTBNDLval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int CTBNDLlhs = CTBNDLr1[CTBNDLn] - YYNTOKENS;
    const int CTBNDLi = CTBNDLpgoto[CTBNDLlhs] + *CTBNDLssp;
    CTBNDLstate = (0 <= CTBNDLi && CTBNDLi <= YYLAST && CTBNDLcheck[CTBNDLi] == *CTBNDLssp
               ? CTBNDLtable[CTBNDLi]
               : CTBNDLdefgoto[CTBNDLlhs]);
  }

  goto CTBNDLnewstate;


/*--------------------------------------.
| CTBNDLerrlab -- here on detecting error.  |
`--------------------------------------*/
CTBNDLerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  CTBNDLtoken = CTBNDLchar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (CTBNDLchar);
  /* If not already recovering from an error, report this error.  */
  if (!CTBNDLerrstatus)
    {
      ++CTBNDLnerrs;
      CTBNDLerror (YY_("syntax error"));
    }

  if (CTBNDLerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (CTBNDLchar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (CTBNDLchar == YYEOF)
            YYABORT;
        }
      else
        {
          CTBNDLdestruct ("Error: discarding",
                      CTBNDLtoken, &CTBNDLlval);
          CTBNDLchar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto CTBNDLerrlab1;


/*---------------------------------------------------.
| CTBNDLerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
CTBNDLerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label CTBNDLerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++CTBNDLnerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (CTBNDLlen);
  CTBNDLlen = 0;
  YY_STACK_PRINT (CTBNDLss, CTBNDLssp);
  CTBNDLstate = *CTBNDLssp;
  goto CTBNDLerrlab1;


/*-------------------------------------------------------------.
| CTBNDLerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
CTBNDLerrlab1:
  CTBNDLerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      CTBNDLn = CTBNDLpact[CTBNDLstate];
      if (!CTBNDLpact_value_is_default (CTBNDLn))
        {
          CTBNDLn += YYSYMBOL_YYerror;
          if (0 <= CTBNDLn && CTBNDLn <= YYLAST && CTBNDLcheck[CTBNDLn] == YYSYMBOL_YYerror)
            {
              CTBNDLn = CTBNDLtable[CTBNDLn];
              if (0 < CTBNDLn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (CTBNDLssp == CTBNDLss)
        YYABORT;


      CTBNDLdestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (CTBNDLstate), CTBNDLvsp);
      YYPOPSTACK (1);
      CTBNDLstate = *CTBNDLssp;
      YY_STACK_PRINT (CTBNDLss, CTBNDLssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++CTBNDLvsp = CTBNDLlval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (CTBNDLn), CTBNDLvsp, CTBNDLlsp);

  CTBNDLstate = CTBNDLn;
  goto CTBNDLnewstate;


/*-------------------------------------.
| CTBNDLacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
CTBNDLacceptlab:
  CTBNDLresult = 0;
  goto CTBNDLreturnlab;


/*-----------------------------------.
| CTBNDLabortlab -- YYABORT comes here.  |
`-----------------------------------*/
CTBNDLabortlab:
  CTBNDLresult = 1;
  goto CTBNDLreturnlab;


/*-----------------------------------------------------------.
| CTBNDLexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
CTBNDLexhaustedlab:
  CTBNDLerror (YY_("memory exhausted"));
  CTBNDLresult = 2;
  goto CTBNDLreturnlab;


/*----------------------------------------------------------.
| CTBNDLreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
CTBNDLreturnlab:
  if (CTBNDLchar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      CTBNDLtoken = YYTRANSLATE (CTBNDLchar);
      CTBNDLdestruct ("Cleanup: discarding lookahead",
                  CTBNDLtoken, &CTBNDLlval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (CTBNDLlen);
  YY_STACK_PRINT (CTBNDLss, CTBNDLssp);
  while (CTBNDLssp != CTBNDLss)
    {
      CTBNDLdestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*CTBNDLssp), CTBNDLvsp);
      YYPOPSTACK (1);
    }
#ifndef CTBNDLoverflow
  if (CTBNDLss != CTBNDLssa)
    YYSTACK_FREE (CTBNDLss);
#endif

  return CTBNDLresult;
}

#line 332 "BooleanGrammar.y"


#include "lex.CTBNDL.cc"

void set_current_network(Network* network)
{
  current_network = network;
}

Network* get_current_network()
{
  return current_network;
}

