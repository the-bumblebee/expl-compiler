/* A Bison parser, made by GNU Bison 3.5.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "exprtree.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include "exprtree.h"
	#include "reglib.h"
	#include "y.tab.h"
	#include "auxlib.h"

	FILE *yyin;
	FILE *out_file;

	int compile_flag = 1;
	int n_params = 0;
	int decl_flag;
	int yylex(void);
	void yyerror(char const *s);

	struct Gsymbol *funcGentry;
	struct type_node *thead = NULL;
	struct arglist *arghead = NULL;


#line 93 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    RETURN = 258,
    MAIN = 259,
    NUM = 260,
    COL = 261,
    PLUS = 262,
    MINUS = 263,
    MUL = 264,
    DIV = 265,
    MOD = 266,
    END = 267,
    BEGINI = 268,
    READI = 269,
    WRITEI = 270,
    ID = 271,
    EQUAL = 272,
    IF = 273,
    then = 274,
    Else = 275,
    ENDIF = 276,
    WHILE = 277,
    DO = 278,
    ENDWHILE = 279,
    BREAK = 280,
    CONTINUE = 281,
    STRLIT = 282,
    DECL = 283,
    ENDDECL = 284,
    INT = 285,
    STR = 286,
    ERROR = 287,
    LT = 288,
    GT = 289,
    LE = 290,
    GE = 291,
    NE = 292,
    EQ = 293
  };
#endif
/* Tokens.  */
#define RETURN 258
#define MAIN 259
#define NUM 260
#define COL 261
#define PLUS 262
#define MINUS 263
#define MUL 264
#define DIV 265
#define MOD 266
#define END 267
#define BEGINI 268
#define READI 269
#define WRITEI 270
#define ID 271
#define EQUAL 272
#define IF 273
#define then 274
#define Else 275
#define ENDIF 276
#define WHILE 277
#define DO 278
#define ENDWHILE 279
#define BREAK 280
#define CONTINUE 281
#define STRLIT 282
#define DECL 283
#define ENDDECL 284
#define INT 285
#define STR 286
#define ERROR 287
#define LT 288
#define GT 289
#define LE 290
#define GE 291
#define NE 292
#define EQ 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "exprtree.y"

	struct tnode *no;
	char *varname;
	int number;
	char* literal;

#line 228 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   358

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

#define YYUNDEFTOK  2
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    42,    48,    51,    52,    54,    55,    56,
      57,    58,    59,    60,    61,    64,    67,    73,    80,    82,
      88,    95,   101,   108,   114,   124,   131,   132,   135,   138,
     139,   142,   143,   144,   150,   151,   154,   188,   212,   220,
     229,   232,   235,   239,   240,   243,   243,   245,   247,   248,
     251,   252,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   274,   275,   276,   277,   278,
     281,   282
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RETURN", "MAIN", "NUM", "COL", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "END", "BEGINI", "READI", "WRITEI", "ID",
  "EQUAL", "IF", "then", "Else", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "BREAK", "CONTINUE", "STRLIT", "DECL", "ENDDECL", "INT", "STR", "ERROR",
  "LT", "GT", "LE", "GE", "NE", "EQ", "'('", "')'", "'['", "']'", "','",
  "'{'", "'}'", "$accept", "program", "Slist", "Stmt", "RtnStmt",
  "InputStmt", "OutputStmt", "AsgStmt", "Ifstmt", "Whilestmt",
  "GDeclBlock", "GDeclList", "GDecl", "GidList", "Gid", "FDefBlock",
  "Fdef", "MainBlock", "ParamList", "Param", "LDeclBlock", "LDeclList",
  "LDecl", "IdList", "Type", "expr", "ArgList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    40,
      41,    91,    93,    44,   123,   125
};
# endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,   -10,    18,    27,    44,   -76,   -76,   -76,   -76,    23,
     -76,     7,   -76,    41,    44,   -76,   -76,    34,   -76,   -76,
     -19,    -3,   -76,    32,   -76,   -76,    46,    68,    82,   -76,
       7,    64,    68,   -36,   -76,    95,    71,   -76,    76,   -32,
     -76,    68,   -76,   -76,    93,    78,   -76,    26,   111,    93,
     -76,    29,   -76,   109,   332,   114,   -76,   -76,   -76,    -1,
     121,    89,    90,     2,    91,    92,   126,   127,   332,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   332,   -76,   118,   -76,
      31,   -76,   121,   204,   122,   121,   121,   121,   121,   121,
     -76,   -76,   -76,   128,   332,   -76,    96,   121,   144,   -76,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,    62,   154,   210,    58,   162,   196,    94,   135,   -76,
     248,   -31,    72,   -76,    52,    52,   -76,   -76,   -76,   254,
     254,   254,   254,   254,   254,   143,   121,   150,   -76,   140,
     139,   136,   -76,   123,   -76,   121,   -76,   -76,   108,   -76,
     121,   332,   332,   -76,   248,   134,   216,   290,   304,   160,
     -76,   332,   161,   169,   -76,   318,   -76,   -76,   170,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,    25,    50,    51,     0,
      27,     0,     1,    50,     0,    35,     4,     0,    24,    26,
      31,     0,    30,     0,    34,     3,     0,    40,     0,    28,
       0,     0,    40,     0,    39,     0,     0,    29,     0,     0,
      33,     0,    41,    32,    44,     0,    38,     0,     0,    44,
      43,     0,    46,     0,     0,     0,    42,    45,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
      12,     7,     8,     9,    10,    11,     0,    47,     0,    66,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    13,     5,    12,     0,    48,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    63,
      71,     0,     0,    65,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,     0,    19,     0,
       0,     0,    37,     0,    64,     0,    67,    16,     0,    18,
       0,     0,     0,    36,    70,     0,     0,     0,     0,     0,
      20,     0,     0,     0,    17,     0,    22,    23,     0,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -75,   -68,   -50,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   174,   -76,   155,   -76,   172,   179,   176,   168,
     152,   -76,   177,   -76,    37,   -72,   -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    68,    69,    70,    71,    72,    73,    74,    75,
       4,     9,    10,    21,    22,    14,    15,    16,    33,    34,
      48,    51,    52,    59,    35,    83,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,    94,     5,    29,    40,    77,     1,    41,    45,   144,
      98,    41,   145,   112,   113,   114,   115,   116,    93,    86,
      27,     2,    28,    20,   120,   122,    92,    12,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    11,
      30,    17,    78,    87,   118,    23,    11,     6,     7,     8,
      26,    17,    18,     7,     8,    50,     7,     8,    56,     7,
       8,   102,   103,   104,   148,   100,   101,   102,   103,   104,
      96,    31,    97,   154,    13,     8,   157,   158,   156,   100,
     101,   102,   103,   104,    53,    32,   165,    36,    53,    92,
      92,   105,   106,   107,   108,   109,   110,    92,     7,     8,
     139,    79,   135,   136,    38,   105,   106,   107,   108,   109,
     110,    42,    80,    43,   146,   100,   101,   102,   103,   104,
      44,    47,    49,    81,    54,    58,    79,    76,    84,    85,
      88,    89,    90,    91,    95,    82,   119,    80,   111,   142,
     117,   105,   106,   107,   108,   109,   110,   143,    81,   147,
     155,   100,   101,   102,   103,   104,   149,   150,   151,   152,
      82,   100,   101,   102,   103,   104,   164,   166,   153,   100,
     101,   102,   103,   104,   159,   167,   169,   105,   106,   107,
     108,   109,   110,    19,   123,    37,    24,   105,   106,   107,
     108,   109,   110,    25,   137,   105,   106,   107,   108,   109,
     110,    55,   140,   100,   101,   102,   103,   104,    39,    46,
      99,   100,   101,   102,   103,   104,   138,   100,   101,   102,
     103,   104,   160,   100,   101,   102,   103,   104,    57,   105,
     106,   107,   108,   109,   110,     0,   141,   105,   106,   107,
     108,   109,   110,   105,   106,   107,   108,   109,   110,   105,
     106,   107,   108,   109,   110,   100,   101,   102,   103,   104,
       0,   100,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    60,    64,     0,
     161,   162,    65,     0,     0,    66,    67,     0,    61,    62,
      63,    60,    64,     0,     0,     0,    65,     0,   163,    66,
      67,     0,    61,    62,    63,    60,    64,     0,     0,   168,
      65,     0,     0,    66,    67,     0,    61,    62,    63,     0,
      64,     0,     0,     0,    65,     0,     0,    66,    67
};

static const yytype_int16 yycheck[] =
{
      68,    76,    12,     6,    40,     6,    13,    43,    40,    40,
      82,    43,    43,    85,    86,    87,    88,    89,    68,    17,
      39,    28,    41,    16,    96,    97,    94,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,     2,
      43,     4,    43,    41,    94,     4,     9,    29,    30,    31,
      16,    14,    29,    30,    31,    29,    30,    31,    29,    30,
      31,     9,    10,    11,   136,     7,     8,     9,    10,    11,
      39,    39,    41,   145,    30,    31,   151,   152,   150,     7,
       8,     9,    10,    11,    47,    39,   161,     5,    51,   157,
     158,    33,    34,    35,    36,    37,    38,   165,    30,    31,
      42,     5,    40,    41,    40,    33,    34,    35,    36,    37,
      38,    16,    16,    42,    42,     7,     8,     9,    10,    11,
      44,    28,    44,    27,    13,    16,     5,    13,    39,    39,
      39,    39,     6,     6,    16,    39,    40,    16,    16,    45,
      12,    33,    34,    35,    36,    37,    38,    12,    27,     6,
      42,     7,     8,     9,    10,    11,     6,    17,    19,    23,
      39,     7,     8,     9,    10,    11,     6,     6,    45,     7,
       8,     9,    10,    11,    40,     6,     6,    33,    34,    35,
      36,    37,    38,     9,    40,    30,    14,    33,    34,    35,
      36,    37,    38,    14,    40,    33,    34,    35,    36,    37,
      38,    49,    40,     7,     8,     9,    10,    11,    32,    41,
       6,     7,     8,     9,    10,    11,     6,     7,     8,     9,
      10,    11,     6,     7,     8,     9,    10,    11,    51,    33,
      34,    35,    36,    37,    38,    -1,    40,    33,    34,    35,
      36,    37,    38,    33,    34,    35,    36,    37,    38,    33,
      34,    35,    36,    37,    38,     7,     8,     9,    10,    11,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    33,    34,    35,
      36,    37,    38,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,     3,    18,    -1,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    14,    15,
      16,     3,    18,    -1,    -1,    -1,    22,    -1,    24,    25,
      26,    -1,    14,    15,    16,     3,    18,    -1,    -1,    21,
      22,    -1,    -1,    25,    26,    -1,    14,    15,    16,    -1,
      18,    -1,    -1,    -1,    22,    -1,    -1,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    28,    47,    56,    12,    29,    30,    31,    57,
      58,    70,     0,    30,    61,    62,    63,    70,    29,    58,
      16,    59,    60,     4,    62,    63,    16,    39,    41,     6,
      43,    39,    39,    64,    65,    70,     5,    60,    40,    64,
      40,    43,    16,    42,    44,    40,    65,    28,    66,    44,
      29,    67,    68,    70,    13,    66,    29,    68,    16,    69,
       3,    14,    15,    16,    18,    22,    25,    26,    48,    49,
      50,    51,    52,    53,    54,    55,    13,     6,    43,     5,
      16,    27,    39,    71,    39,    39,    17,    41,    39,    39,
       6,     6,    49,    50,    48,    16,    39,    41,    71,     6,
       7,     8,     9,    10,    11,    33,    34,    35,    36,    37,
      38,    16,    71,    71,    71,    71,    71,    12,    50,    40,
      71,    72,    71,    40,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    40,    41,    40,     6,    42,
      40,    40,    45,    12,    40,    43,    42,     6,    71,     6,
      17,    19,    23,    45,    71,    42,    71,    48,    48,    40,
       6,    20,    21,    24,     6,    48,     6,     6,    21,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    47,    48,    48,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    51,    51,    52,    53,
      53,    54,    54,    55,    56,    56,    57,    57,    58,    59,
      59,    60,    60,    60,    61,    61,    62,    63,    64,    64,
      64,    65,    66,    66,    66,    67,    67,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     5,     8,     5,     4,
       7,    10,     8,     8,     3,     2,     2,     1,     3,     3,
       1,     1,     4,     4,     2,     1,    12,    11,     3,     1,
       0,     2,     3,     2,     0,     2,     1,     3,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     1,     4,     1,     1,
       3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 41 "exprtree.y"
                                                        {exit(1);}
#line 1549 "y.tab.c"
    break;

  case 3:
#line 43 "exprtree.y"
                        {
				/*print_Gtable();*/
				exit(1);
			}
#line 1558 "y.tab.c"
    break;

  case 4:
#line 48 "exprtree.y"
                                                                                {/*print_Gtable(); fprintf(stderr, "Success\n");*/ exit(1);}
#line 1564 "y.tab.c"
    break;

  case 5:
#line 51 "exprtree.y"
                                                {(yyval.no) = createTree(0, none, NULL, 8, (yyvsp[-1].no), (yyvsp[0].no));}
#line 1570 "y.tab.c"
    break;

  case 13:
#line 60 "exprtree.y"
                                {(yyval.no) = createTree(0, none, NULL, 17, NULL, NULL);}
#line 1576 "y.tab.c"
    break;

  case 14:
#line 61 "exprtree.y"
                                {(yyval.no) = createTree(0, none, NULL, 18, NULL, NULL);}
#line 1582 "y.tab.c"
    break;

  case 15:
#line 64 "exprtree.y"
                                {(yyval.no) = createTree(0, none, NULL, 21, (yyvsp[-1].no), NULL);}
#line 1588 "y.tab.c"
    break;

  case 16:
#line 68 "exprtree.y"
                        {
				struct tnode* t; t = createTree(0, none, (yyvsp[-2].varname), none, NULL, NULL);
				(yyval.no) = createTree(0, none, NULL, 6, t, NULL);
			}
#line 1597 "y.tab.c"
    break;

  case 17:
#line 74 "exprtree.y"
                {
			struct tnode* t = createTree(0, none, (yyvsp[-5].varname), 19, (yyvsp[-3].no), NULL);
			 (yyval.no) = createTree(0, none, NULL, 6, t, NULL);
		 }
#line 1606 "y.tab.c"
    break;

  case 18:
#line 80 "exprtree.y"
                                                {(yyval.no) = createTree(0, none, NULL, 7, (yyvsp[-2].no), NULL);}
#line 1612 "y.tab.c"
    break;

  case 19:
#line 83 "exprtree.y"
                {
			struct tnode* t; t = createTree(0, none, (yyvsp[-3].varname), none, NULL, NULL);
			(yyval.no) = createTree(0, none, NULL, 5, t, (yyvsp[-1].no));
		}
#line 1621 "y.tab.c"
    break;

  case 20:
#line 89 "exprtree.y"
                {
			struct tnode* t = createTree(0, none, (yyvsp[-6].varname), 19, (yyvsp[-4].no), NULL);
			(yyval.no) = createTree(0, none, NULL, 5, t, (yyvsp[-1].no));
		}
#line 1630 "y.tab.c"
    break;

  case 21:
#line 96 "exprtree.y"
                {
			struct tnode* t; t = createTree(0, none, NULL, 8, (yyvsp[-4].no), (yyvsp[-2].no));
			(yyval.no) = createTree(0, none, NULL, 15, (yyvsp[-7].no), t);
		}
#line 1639 "y.tab.c"
    break;

  case 22:
#line 102 "exprtree.y"
                {
			struct tnode* t; t = createTree(0, none, NULL, 8, (yyvsp[-2].no), NULL);
			(yyval.no) = createTree(0, none, NULL, 15, (yyvsp[-5].no), t);
		}
#line 1648 "y.tab.c"
    break;

  case 23:
#line 109 "exprtree.y"
                        {
				(yyval.no) = createTree(0, none, NULL, 16, (yyvsp[-5].no), (yyvsp[-2].no));
			}
#line 1656 "y.tab.c"
    break;

  case 24:
#line 115 "exprtree.y"
                        {
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
				int SP;
				SP = Ghead->binding + Ghead->size;
				if (SP != Ghead->binding)
					SP = SP - 1;
				fprintf(target_file, "MOV SP, %d\n", SP);
				fprintf(target_file, "JMP L0\n");
			}
#line 1670 "y.tab.c"
    break;

  case 25:
#line 125 "exprtree.y"
                        {
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
				fprintf(target_file, "MOV SP, 4096\n");
			}
#line 1679 "y.tab.c"
    break;

  case 28:
#line 135 "exprtree.y"
                                {tpop(&thead);}
#line 1685 "y.tab.c"
    break;

  case 31:
#line 142 "exprtree.y"
                                                {Ginstall(&Ghead, (yyvsp[0].varname), thead->type, 1, NULL);}
#line 1691 "y.tab.c"
    break;

  case 32:
#line 143 "exprtree.y"
                                        {Ginstall(&Ghead, (yyvsp[-3].varname), thead->type, (yyvsp[-1].number), NULL);}
#line 1697 "y.tab.c"
    break;

  case 33:
#line 145 "exprtree.y"
        {
		Ginstall(&Ghead, (yyvsp[-3].varname), thead->type, 0, &Phead);
		Phead = NULL;}
#line 1705 "y.tab.c"
    break;

  case 36:
#line 155 "exprtree.y"
                {
			n_params = 0;
			//Build AST for function.
			struct tnode* temp_node;
			temp_node = createTree(0, none, NULL, 8, (yyvsp[-3].no), (yyvsp[-2].no));
			(yyval.no) = createTree(0, none, (yyvsp[-10].varname), 22, temp_node, NULL);
			(yyval.no)->Gentry->flabel = getLabel();
			//Compare Phead and fun->paramlist for name equivalence and deallocate Phead.
			cmpPara(&Phead, &((yyval.no)->Gentry->paramlist));
			//Compare function types in both function declaration and function definition.
			if (thead->type != (yyval.no)->Gentry->type) {
				fprintf(stderr, "Error: Function return type shows conflicts in function declaration and function definiton.\n");
				exit(1);
			}
			//Function entry saved to be used in codeGen. (For checking return type for return node.)
			funcGentry = (yyval.no)->Gentry;
			tpop(&thead);
			//print_Ltable($2);
			//codeGen for function.
			codeGen((yyval.no));
			//Deallocate Lhead and AST.
			struct Lsymbol *Ltemp;
			while(Lhead != NULL) {
				Ltemp = Lhead;
				Lhead = Lhead->next;
				free(Ltemp);
			}
			deallocateAST((yyval.no));
	 	}
#line 1739 "y.tab.c"
    break;

  case 37:
#line 189 "exprtree.y"
        {
		//Adding global entry.
		Ginstall(&Ghead, "main", inttype, 0, NULL);
		//Build AST for function.
		struct tnode* temp_node;
		temp_node = createTree(0, none, NULL, 8, (yyvsp[-3].no), (yyvsp[-2].no));
		(yyval.no) = createTree(0, none, "main", 22, temp_node, NULL);
		(yyval.no)->Gentry = Ghead;
		(yyval.no)->Gentry->flabel = 0;
		funcGentry = (yyval.no)->Gentry;

		codeGen((yyval.no));
		//print_Ltable("main");
		struct Lsymbol *Ltemp;
		while(Lhead != NULL) {
			Ltemp = Lhead;
			Lhead = Lhead->next;
			free(Ltemp);
		}
		deallocateAST((yyval.no));
	}
#line 1765 "y.tab.c"
    break;

  case 38:
#line 213 "exprtree.y"
                {
			if (decl_flag == 0) {
				n_params += 1;
				Linstall(&Lhead, Phead->name, Phead->type, Lhead->binding - 1);
			}
		}
#line 1776 "y.tab.c"
    break;

  case 39:
#line 221 "exprtree.y"
                {
			if (decl_flag == 0) {
				n_params = 1;
				Linstall(&Lhead, Phead->name, Phead->type, -3);
			}
		}
#line 1787 "y.tab.c"
    break;

  case 40:
#line 229 "exprtree.y"
                {n_params = 0;}
#line 1793 "y.tab.c"
    break;

  case 41:
#line 232 "exprtree.y"
                                {Pinstall(&Phead, (yyvsp[0].varname), thead->type); tpop(&thead);}
#line 1799 "y.tab.c"
    break;

  case 42:
#line 236 "exprtree.y"
                        {
				tpop(&thead);
			}
#line 1807 "y.tab.c"
    break;

  case 48:
#line 247 "exprtree.y"
                                {Linstall(&Lhead, (yyvsp[0].varname), thead->type, Lhead->binding + 1);}
#line 1813 "y.tab.c"
    break;

  case 49:
#line 248 "exprtree.y"
                                                {Linstall(&Lhead, (yyvsp[0].varname), thead->type, 1);}
#line 1819 "y.tab.c"
    break;

  case 50:
#line 251 "exprtree.y"
                                                {tpush(&thead, inttype);}
#line 1825 "y.tab.c"
    break;

  case 51:
#line 252 "exprtree.y"
                                                {tpush(&thead, strtype);}
#line 1831 "y.tab.c"
    break;

  case 52:
#line 255 "exprtree.y"
                                {(yyval.no) = createTree(0, inttype, NULL, 1, (yyvsp[-2].no), (yyvsp[0].no));}
#line 1837 "y.tab.c"
    break;

  case 53:
#line 256 "exprtree.y"
                                {(yyval.no) = createTree(0, inttype, NULL, 2, (yyvsp[-2].no), (yyvsp[0].no));}
#line 1843 "y.tab.c"
    break;

  case 54:
#line 257 "exprtree.y"
                                        {(yyval.no) = createTree(0, inttype, NULL, 3, (yyvsp[-2].no), (yyvsp[0].no));}
#line 1849 "y.tab.c"
    break;

  case 55:
#line 258 "exprtree.y"
                                        {(yyval.no) = createTree(0, inttype, NULL, 4, (yyvsp[-2].no), (yyvsp[0].no));}
#line 1855 "y.tab.c"
    break;

  case 56:
#line 259 "exprtree.y"
                                        {(yyval.no) = createTree(0, inttype, NULL, 20, (yyvsp[-2].no), (yyvsp[0].no));}
#line 1861 "y.tab.c"
    break;

  case 57:
#line 260 "exprtree.y"
                                        {(yyval.no) = createTree(0, booltype, NULL, 9, (yyvsp[-2].no), (yyvsp[0].no));}
#line 1867 "y.tab.c"
    break;

  case 58:
#line 261 "exprtree.y"
                                        {(yyval.no) = createTree(0, booltype, NULL, 10, (yyvsp[-2].no), (yyvsp[0].no));}
#line 1873 "y.tab.c"
    break;

  case 59:
#line 262 "exprtree.y"
                                        {(yyval.no) = createTree(0, booltype, NULL, 11, (yyvsp[-2].no), (yyvsp[0].no));}
#line 1879 "y.tab.c"
    break;

  case 60:
#line 263 "exprtree.y"
                                        {(yyval.no) = createTree(0, booltype, NULL, 12, (yyvsp[-2].no), (yyvsp[0].no));}
#line 1885 "y.tab.c"
    break;

  case 61:
#line 264 "exprtree.y"
                                        {(yyval.no) = createTree(0, booltype, NULL, 13, (yyvsp[-2].no), (yyvsp[0].no));}
#line 1891 "y.tab.c"
    break;

  case 62:
#line 265 "exprtree.y"
                                        {(yyval.no) = createTree(0, booltype, NULL, 14, (yyvsp[-2].no), (yyvsp[0].no));}
#line 1897 "y.tab.c"
    break;

  case 63:
#line 266 "exprtree.y"
                                        {(yyval.no) = createTree(0, none, (yyvsp[-2].varname), 23, NULL, NULL);}
#line 1903 "y.tab.c"
    break;

  case 64:
#line 268 "exprtree.y"
         {
		 struct tnode *tn;
		 (yyval.no) = createTree(0, none, (yyvsp[-3].varname), 23, NULL, NULL);
		 tn = cmpArg(&arghead, &((yyval.no)->Gentry->paramlist));
		 (yyval.no)->left = tn;
	 }
#line 1914 "y.tab.c"
    break;

  case 65:
#line 274 "exprtree.y"
                                        {(yyval.no) = (yyvsp[-1].no);}
#line 1920 "y.tab.c"
    break;

  case 66:
#line 275 "exprtree.y"
                                                {(yyval.no) = createTree((yyvsp[0].number), inttype, NULL, none, NULL, NULL);}
#line 1926 "y.tab.c"
    break;

  case 67:
#line 276 "exprtree.y"
                                        {(yyval.no) = createTree(0, none, (yyvsp[-3].varname), 19, (yyvsp[-1].no), NULL);}
#line 1932 "y.tab.c"
    break;

  case 68:
#line 277 "exprtree.y"
                                                {(yyval.no) = createTree(0, none, (yyvsp[0].varname), none, NULL, NULL);}
#line 1938 "y.tab.c"
    break;

  case 69:
#line 278 "exprtree.y"
                                                {(yyval.no) = makeStringNode((yyvsp[0].literal));}
#line 1944 "y.tab.c"
    break;

  case 70:
#line 281 "exprtree.y"
                                {argpush(&arghead, (yyvsp[0].no));}
#line 1950 "y.tab.c"
    break;

  case 71:
#line 282 "exprtree.y"
                                                {argpush(&arghead, (yyvsp[0].no));}
#line 1956 "y.tab.c"
    break;


#line 1960 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 285 "exprtree.y"


void yyerror(char const *s) {
    printf("yyerror %s\n", s);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage:\n ./a.out <input_file>\n\n");
		printf("Output:\n out_label.xsm\n");
		exit(0);
	}
	target_file = fopen("out_label.xsm", "w");
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
	fclose(target_file);
	return 0;
}
