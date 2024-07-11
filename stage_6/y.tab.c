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
	#include <string.h>
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
	struct Typetable *Tentry;
	struct Fieldlist *Fhead = NULL;
	struct type_node *thead = NULL;
	struct arglist *arghead = NULL;


#line 96 "y.tab.c"

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
    TYPE = 288,
    ENDTYPE = 289,
    ALLOC = 290,
    FREE = 291,
    NULLV = 292,
    INITIALIZE = 293,
    LT = 294,
    GT = 295,
    LE = 296,
    GE = 297,
    NE = 298,
    EQ = 299
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
#define TYPE 288
#define ENDTYPE 289
#define ALLOC 290
#define FREE 291
#define NULLV 292
#define INITIALIZE 293
#define LT 294
#define GT 295
#define LE 296
#define GE 297
#define NE 298
#define EQ 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "exprtree.y"

	struct tnode *no;
	char *varname;
	int number;
	char* literal;

#line 243 "y.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   416

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  221

#define YYUNDEFTOK  2
#define YYMAXUTOK   299


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
      45,    46,     2,     2,    49,     2,    52,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    45,    46,    47,    50,    51,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    65,    68,
      74,    81,    91,   105,   115,   129,   135,   137,   143,   149,
     155,   161,   168,   174,   184,   191,   192,   195,   198,   199,
     202,   203,   204,   211,   212,   215,   245,   267,   275,   284,
     287,   290,   291,   292,   295,   296,   298,   300,   301,   304,
     305,   308,   309,   312,   323,   328,   329,   332,   334,   335,
     336,   348,   364,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   411,   412,   413,   414,
     415,   416,   417,   418,   421,   422
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
  "TYPE", "ENDTYPE", "ALLOC", "FREE", "NULLV", "INITIALIZE", "LT", "GT",
  "LE", "GE", "NE", "EQ", "'('", "')'", "'['", "']'", "','", "'{'", "'}'",
  "'.'", "$accept", "program", "Slist", "Stmt", "RtnStmt", "InputStmt",
  "AllocStmt", "FreeStmt", "InitFunc", "OutputStmt", "AsgStmt", "Ifstmt",
  "Whilestmt", "GDeclBlock", "GDeclList", "GDecl", "GidList", "Gid",
  "FDefBlock", "Fdef", "MainBlock", "ParamList", "Param", "LDeclBlock",
  "LDeclList", "LDecl", "IdList", "TypeDefBlock", "TypeDefList", "TypeDef",
  "TypeDecl", "FieldDeclList", "FieldDecl", "TypeName", "Field", "expr",
  "ArgList", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    40,    41,    91,    93,    44,
     123,   125,    46
};
# endif

#define YYPACT_NINF (-153)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      38,     4,    41,    12,    69,  -153,    52,  -153,    39,  -153,
      54,  -153,    35,  -153,   117,    24,    55,  -153,  -153,   112,
    -153,  -153,  -153,  -153,   166,  -153,    89,    41,    24,  -153,
    -153,    97,    88,    11,  -153,   128,  -153,  -153,    47,    -1,
    -153,  -153,  -153,   104,   123,  -153,  -153,   147,   112,   162,
    -153,    89,   112,   378,   155,  -153,   -31,  -153,   153,   122,
    -153,    68,  -153,   385,  -153,   156,   377,  -153,   112,  -153,
    -153,   129,  -153,  -153,  -153,     0,   161,   130,   133,     6,
     135,   138,   179,   199,   168,   377,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,     5,  -153,   123,  -153,   191,
    -153,    34,  -153,  -153,   169,   161,  -153,   163,   250,   211,
     161,   136,   161,   213,   161,   161,  -153,  -153,   214,  -153,
     219,   149,   222,   233,  -153,    45,   161,   208,   182,  -153,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   115,   193,   235,   256,    56,  -153,   201,   209,    66,
      85,   236,   241,   262,  -153,   377,  -153,   274,    70,    67,
    -153,  -153,   125,   125,  -153,  -153,  -153,   312,   312,   312,
     312,   312,   312,   282,   161,   319,   280,  -153,   310,   309,
     306,   324,   325,  -153,   286,  -153,   377,  -153,   161,  -153,
    -153,   116,  -153,   327,   161,   377,   377,  -153,  -153,   328,
     326,   274,   294,  -153,   268,   321,   345,  -153,   293,   339,
    -153,   377,   343,   344,  -153,  -153,   361,  -153,  -153,   352,
    -153
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      60,     0,     0,     0,     0,     3,     0,     2,     0,    64,
       0,    62,     0,     1,     0,     0,     0,    59,    61,     0,
      70,    34,    68,    69,     0,    36,     0,    68,     0,    44,
       5,     0,     0,     0,    66,     0,    33,    35,    40,     0,
      39,    43,     4,     0,    53,    63,    65,     0,    49,     0,
      37,     0,    49,     0,     0,    67,     0,    48,     0,     0,
      38,     0,    52,     0,    55,     0,     0,    42,     0,    50,
      41,     0,    51,    54,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,    15,     8,    13,
      14,     9,    10,    11,    12,     0,    47,    53,    56,     0,
      90,    92,    93,    89,     0,     0,    88,    87,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    16,     0,     6,
      15,     0,     0,     0,    57,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,     0,     0,     0,
       0,     0,     0,     0,    71,     0,    84,    95,     0,     0,
      25,    86,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,    46,     0,    29,     0,    85,     0,    91,
      19,     0,    26,     0,     0,     0,     0,    23,    24,     0,
      15,    94,     0,    21,     0,     0,     0,    22,     0,     0,
      28,     0,     0,     0,    45,    20,     0,    31,    32,     0,
      30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -152,   -84,   -83,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,   338,  -153,   314,  -153,   340,
      32,   320,   298,   276,  -153,   311,  -153,  -153,  -153,   368,
    -153,  -153,   351,    -7,   -66,  -101,  -153
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    85,    86,    87,    88,    89,    90,   106,    91,
      92,    93,    94,    15,    24,    25,    39,    40,    28,    29,
       5,    56,    57,    54,    63,    64,    75,     6,    10,    11,
      12,    33,    34,    58,   107,   108,   158
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,   119,   120,   186,   128,    50,    98,    26,    31,   142,
     144,   145,    35,   147,   148,    67,     7,    26,    68,    95,
     153,    31,   121,   111,   157,   159,    35,    20,     9,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      20,    22,    23,   205,   206,     8,    65,    30,    51,    99,
     100,     1,   150,   112,    27,    23,    65,   122,   113,   216,
      42,   101,    45,   130,   131,   132,   133,   134,     2,    13,
       9,     3,   102,   191,   130,   131,   132,   133,   134,   125,
      14,   126,   103,   104,    16,    19,   113,   201,    17,    95,
     105,   156,    48,   204,    49,   135,   136,   137,   138,   139,
     140,    32,   119,   200,   178,    38,   135,   136,   137,   138,
     139,   140,   181,    43,    71,   189,   187,    68,   113,   188,
      95,   119,   119,   130,   131,   132,   133,   134,    20,    95,
      95,   182,   119,    20,   132,   133,   134,   122,    44,    95,
      95,   100,    22,    23,    47,    95,    21,    22,    23,    52,
      95,    53,   101,    55,   100,   135,   136,   137,   138,   139,
     140,   173,   174,   102,   202,   101,   100,    59,    66,    69,
      70,   143,    74,   103,   104,   109,   102,   101,   110,    97,
     114,   105,    20,   115,   152,   116,   103,   104,   102,   130,
     131,   132,   133,   134,   105,    36,    22,    23,   103,   104,
     130,   131,   132,   133,   134,   117,   105,   124,   130,   131,
     132,   133,   134,   118,   127,   122,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   161,   146,
     149,   151,   135,   136,   137,   138,   139,   140,   154,   175,
     135,   136,   137,   138,   139,   140,   155,   179,   135,   136,
     137,   138,   139,   140,   160,   180,   129,   130,   131,   132,
     133,   134,   177,   130,   131,   132,   133,   134,   185,   130,
     131,   132,   133,   134,   210,   130,   131,   132,   133,   134,
     176,   130,   131,   132,   133,   134,   184,   183,   190,   135,
     136,   137,   138,   139,   140,   135,   136,   137,   138,   139,
     140,   135,   136,   137,   138,   139,   140,   135,   136,   137,
     138,   139,   140,   135,   136,   137,   138,   139,   140,   130,
     131,   132,   133,   134,    76,   192,   193,   194,   195,   196,
     197,   198,   199,   203,   207,    77,    78,    79,   208,    80,
     209,   211,   212,    81,   214,   215,    82,    83,    76,   217,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    84,   220,    77,
      78,    79,    37,    80,    76,    60,    96,    81,    41,   213,
      82,    83,    61,   123,    73,    77,    78,    79,    18,    80,
      76,    84,   219,    81,    46,     0,    82,    83,     0,     0,
       0,    77,    78,    79,    20,    80,     0,    84,     0,    81,
       0,    20,    82,    83,     0,     0,     0,    62,    22,    23,
       0,     0,     0,    84,    72,    22,    23
};

static const yytype_int16 yycheck[] =
{
      66,    85,    85,   155,   105,     6,     6,    14,    15,   110,
     111,   112,    19,   114,   115,    46,    12,    24,    49,    85,
     121,    28,    17,    17,   125,   126,    33,    16,    16,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
      16,    30,    31,   195,   196,     4,    53,    15,    49,    49,
       5,    13,   118,    47,    30,    31,    63,    52,    52,   211,
      28,    16,    51,     7,     8,     9,    10,    11,    30,     0,
      16,    33,    27,   174,     7,     8,     9,    10,    11,    45,
      28,    47,    37,    38,    45,    50,    52,   188,    34,   155,
      45,    46,    45,   194,    47,    39,    40,    41,    42,    43,
      44,    46,   186,   186,    48,    16,    39,    40,    41,    42,
      43,    44,    46,    16,    46,    48,    46,    49,    52,    49,
     186,   205,   206,     7,     8,     9,    10,    11,    16,   195,
     196,    46,   216,    16,     9,    10,    11,    52,    50,   205,
     206,     5,    30,    31,    16,   211,    29,    30,    31,    45,
     216,    28,    16,     6,     5,    39,    40,    41,    42,    43,
      44,    46,    47,    27,    48,    16,     5,     5,    13,    16,
      48,    35,    16,    37,    38,    45,    27,    16,    45,    50,
      45,    45,    16,    45,    35,     6,    37,    38,    27,     7,
       8,     9,    10,    11,    45,    29,    30,    31,    37,    38,
       7,     8,     9,    10,    11,     6,    45,    16,     7,     8,
       9,    10,    11,    45,    45,    52,     7,     8,     9,    10,
      11,    39,    40,    41,    42,    43,    44,    16,    46,    16,
      16,    12,    39,    40,    41,    42,    43,    44,    16,    46,
      39,    40,    41,    42,    43,    44,    13,    46,    39,    40,
      41,    42,    43,    44,    46,    46,     6,     7,     8,     9,
      10,    11,     6,     7,     8,     9,    10,    11,     6,     7,
       8,     9,    10,    11,     6,     7,     8,     9,    10,    11,
      45,     7,     8,     9,    10,    11,    45,    51,     6,    39,
      40,    41,    42,    43,    44,    39,    40,    41,    42,    43,
      44,    39,    40,    41,    42,    43,    44,    39,    40,    41,
      42,    43,    44,    39,    40,    41,    42,    43,    44,     7,
       8,     9,    10,    11,     3,     6,    46,    17,    19,    23,
       6,     6,    46,     6,     6,    14,    15,    16,    12,    18,
      46,    20,    21,    22,    51,     6,    25,    26,     3,     6,
       6,    39,    40,    41,    42,    43,    44,    36,     6,    14,
      15,    16,    24,    18,     3,    51,    68,    22,    28,    24,
      25,    26,    52,    97,    63,    14,    15,    16,    10,    18,
       3,    36,    21,    22,    33,    -1,    25,    26,    -1,    -1,
      -1,    14,    15,    16,    16,    18,    -1,    36,    -1,    22,
      -1,    16,    25,    26,    -1,    -1,    -1,    29,    30,    31,
      -1,    -1,    -1,    36,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    30,    33,    54,    73,    80,    12,     4,    16,
      81,    82,    83,     0,    28,    66,    45,    34,    82,    50,
      16,    29,    30,    31,    67,    68,    86,    30,    71,    72,
      73,    86,    46,    84,    85,    86,    29,    68,    16,    69,
      70,    72,    73,    16,    50,    51,    85,    16,    45,    47,
       6,    49,    45,    28,    76,     6,    74,    75,    86,     5,
      70,    74,    29,    77,    78,    86,    13,    46,    49,    16,
      48,    46,    29,    78,    16,    79,     3,    14,    15,    16,
      18,    22,    25,    26,    36,    55,    56,    57,    58,    59,
      60,    62,    63,    64,    65,    87,    75,    50,     6,    49,
       5,    16,    27,    37,    38,    45,    61,    87,    88,    45,
      45,    17,    47,    52,    45,    45,     6,     6,    45,    56,
      57,    17,    52,    76,    16,    45,    47,    45,    88,     6,
       7,     8,     9,    10,    11,    39,    40,    41,    42,    43,
      44,    16,    88,    35,    88,    88,    16,    88,    88,    16,
      87,    12,    35,    88,    16,    13,    46,    88,    89,    88,
      46,    46,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    46,    47,    46,    45,     6,    48,    46,
      46,    46,    46,    51,    45,     6,    55,    46,    49,    48,
       6,    88,     6,    46,    17,    19,    23,     6,     6,    46,
      57,    88,    48,     6,    88,    55,    55,     6,    12,    46,
       6,    20,    21,    24,    51,     6,    55,     6,     6,    21,
       6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    58,
      58,    59,    59,    60,    60,    61,    62,    63,    63,    63,
      64,    64,    65,    66,    66,    67,    67,    68,    69,    69,
      70,    70,    70,    71,    71,    72,    73,    74,    74,    74,
      75,    76,    76,    76,    77,    77,    78,    79,    79,    80,
      80,    81,    81,    82,    83,    84,    84,    85,    86,    86,
      86,    87,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     4,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     5,
       8,     6,     6,     5,     5,     3,     5,     4,     7,     4,
      10,     8,     8,     3,     2,     2,     1,     3,     3,     1,
       1,     4,     4,     2,     1,    12,    11,     3,     1,     0,
       2,     3,     2,     0,     2,     1,     3,     3,     1,     3,
       0,     2,     1,     4,     1,     2,     1,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     1,     1,     1,
       1,     4,     1,     1,     3,     1
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
#line 44 "exprtree.y"
                                                                                                {exit(1);}
#line 1606 "y.tab.c"
    break;

  case 3:
#line 45 "exprtree.y"
                                                                                                                {exit(1);}
#line 1612 "y.tab.c"
    break;

  case 4:
#line 46 "exprtree.y"
                                                                        {exit(1);}
#line 1618 "y.tab.c"
    break;

  case 5:
#line 47 "exprtree.y"
                                                                                        {exit(1);}
#line 1624 "y.tab.c"
    break;

  case 6:
#line 50 "exprtree.y"
                                                {(yyval.no) = createTree(0, Tlookup("void"), NULL, 8, (yyvsp[-1].no), (yyvsp[0].no));}
#line 1630 "y.tab.c"
    break;

  case 16:
#line 61 "exprtree.y"
                                {(yyval.no) = createTree(0, Tlookup("void"), NULL, 17, NULL, NULL);}
#line 1636 "y.tab.c"
    break;

  case 17:
#line 62 "exprtree.y"
                                {(yyval.no) = createTree(0, Tlookup("void"), NULL, 18, NULL, NULL);}
#line 1642 "y.tab.c"
    break;

  case 18:
#line 65 "exprtree.y"
                                {(yyval.no) = createTree(0, Tlookup("void"), NULL, 21, (yyvsp[-1].no), NULL);}
#line 1648 "y.tab.c"
    break;

  case 19:
#line 69 "exprtree.y"
                        {
				struct tnode* t; t = createTree(0, NULL, (yyvsp[-2].varname), none, NULL, NULL);
				(yyval.no) = createTree(0, Tlookup("void"), NULL, 6, t, NULL);
			}
#line 1657 "y.tab.c"
    break;

  case 20:
#line 75 "exprtree.y"
                        {
				struct tnode* t = createTree(0, NULL, (yyvsp[-5].varname), 19, (yyvsp[-3].no), NULL);
				(yyval.no) = createTree(0, Tlookup("void"), NULL, 6, t, NULL);
			 }
#line 1666 "y.tab.c"
    break;

  case 21:
#line 82 "exprtree.y"
                        {
				struct tnode *IDNode = createTree(0, NULL, (yyvsp[-5].varname), none, NULL, NULL);
				if (IDNode->type->fields == NULL) {
					fprintf(stderr, "Error: Allocation failed. '%s' is a primtive type.\n", IDNode->varname);
					exit(1);
				}
				(yyval.no) = createTree(0, Tlookup("void"), NULL, 25, IDNode, NULL);
			}
#line 1679 "y.tab.c"
    break;

  case 22:
#line 92 "exprtree.y"
                        {
				struct tnode *IDNode = (yyvsp[-5].no);
				while (IDNode->left != NULL) {
					IDNode = IDNode->left;
				}
				if ((yyvsp[-5].no)->type->fields == NULL) {
					fprintf(stderr, "Error: Allocation failed. '%s' is a primtive type.\n", IDNode->varname);
					exit(1);
				}
				(yyval.no) = createTree(0, Tlookup("void"), NULL, 25, (yyvsp[-5].no), NULL);
			}
#line 1695 "y.tab.c"
    break;

  case 23:
#line 106 "exprtree.y"
                        {
				struct tnode *IDNode = createTree(0, NULL, (yyvsp[-2].varname), none, NULL, NULL);
				if (IDNode->type->fields == NULL) {
					fprintf(stderr, "Error: Cannot free '%s'. It is a primtive type.\n", IDNode->varname);
					exit(1);
				}
				(yyval.no) = createTree(0, Tlookup("int"), NULL, 26, IDNode, NULL);
			}
#line 1708 "y.tab.c"
    break;

  case 24:
#line 116 "exprtree.y"
                        {
				struct tnode *IDNode = (yyvsp[-2].no);
				while (IDNode->left != NULL) {
					IDNode = IDNode->left;
				}
				if ((yyvsp[-2].no)->type->fields == NULL) {
					fprintf(stderr, "Error: Cannot free '%s'. It is a primtive type.\n", IDNode->varname);
					exit(1);
				}
				(yyval.no) = createTree(0, Tlookup("int"), NULL, 26, (yyvsp[-2].no), NULL);
			}
#line 1724 "y.tab.c"
    break;

  case 25:
#line 130 "exprtree.y"
                        {
				(yyval.no) = createTree(0, Tlookup("int"), NULL, 28, NULL, NULL);
			}
#line 1732 "y.tab.c"
    break;

  case 26:
#line 135 "exprtree.y"
                                                {(yyval.no) = createTree(0, Tlookup("void"), NULL, 7, (yyvsp[-2].no), NULL);}
#line 1738 "y.tab.c"
    break;

  case 27:
#line 138 "exprtree.y"
                {
			struct tnode* t; t = createTree(0, NULL, (yyvsp[-3].varname), none, NULL, NULL);
			(yyval.no) = createTree(0, Tlookup("void"), NULL, 5, t, (yyvsp[-1].no));
		}
#line 1747 "y.tab.c"
    break;

  case 28:
#line 144 "exprtree.y"
                {
			struct tnode* t = createTree(0, NULL, (yyvsp[-6].varname), 19, (yyvsp[-4].no), NULL);
			(yyval.no) = createTree(0, Tlookup("void"), NULL, 5, t, (yyvsp[-1].no));
		}
#line 1756 "y.tab.c"
    break;

  case 29:
#line 150 "exprtree.y"
                {
			(yyval.no) = createTree(0, Tlookup("void"), NULL, 5, (yyvsp[-3].no), (yyvsp[-1].no));
		}
#line 1764 "y.tab.c"
    break;

  case 30:
#line 156 "exprtree.y"
                {
			struct tnode* t; t = createTree(0, Tlookup("void"), NULL, 8, (yyvsp[-4].no), (yyvsp[-2].no));
			(yyval.no) = createTree(0, Tlookup("void"), NULL, 15, (yyvsp[-7].no), t);
		}
#line 1773 "y.tab.c"
    break;

  case 31:
#line 162 "exprtree.y"
                {
			struct tnode* t; t = createTree(0, Tlookup("void"), NULL, 8, (yyvsp[-2].no), NULL);
			(yyval.no) = createTree(0, Tlookup("void"), NULL, 15, (yyvsp[-5].no), t);
		}
#line 1782 "y.tab.c"
    break;

  case 32:
#line 169 "exprtree.y"
                        {
				(yyval.no) = createTree(0, Tlookup("void"), NULL, 16, (yyvsp[-5].no), (yyvsp[-2].no));
			}
#line 1790 "y.tab.c"
    break;

  case 33:
#line 175 "exprtree.y"
                        {
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
				int SP;
				SP = Ghead->binding + Ghead->size;
				if (SP != Ghead->binding)
					SP = SP - 1;
				fprintf(target_file, "MOV SP, %d\n", SP);
				fprintf(target_file, "JMP <main>\n");
			}
#line 1804 "y.tab.c"
    break;

  case 34:
#line 185 "exprtree.y"
                        {
				fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
				fprintf(target_file, "MOV SP, 4096\n");
			}
#line 1813 "y.tab.c"
    break;

  case 37:
#line 195 "exprtree.y"
                                {tpop(&thead);}
#line 1819 "y.tab.c"
    break;

  case 40:
#line 202 "exprtree.y"
                                                {Ginstall(&Ghead, (yyvsp[0].varname), thead->type, 1, NULL);}
#line 1825 "y.tab.c"
    break;

  case 41:
#line 203 "exprtree.y"
                                        {Ginstall(&Ghead, (yyvsp[-3].varname), thead->type, (yyvsp[-1].number), NULL);}
#line 1831 "y.tab.c"
    break;

  case 42:
#line 205 "exprtree.y"
        {
		Ginstall(&Ghead, (yyvsp[-3].varname), thead->type, 0, &Phead);
		Phead = NULL;
	}
#line 1840 "y.tab.c"
    break;

  case 45:
#line 216 "exprtree.y"
                {
			n_params = 0;
			//Build AST for function.
			struct tnode* temp_node;
			temp_node = createTree(0, Tlookup("void"), NULL, 8, (yyvsp[-3].no), (yyvsp[-2].no));
			(yyval.no) = createTree(0, NULL, (yyvsp[-10].varname), 22, temp_node, NULL);
			//Compare Phead and fun->paramlist for name equivalence and deallocate Phead.
			cmpPara(&Phead, &((yyval.no)->Gentry->paramlist));
			//Compare function types in both function declaration and function definition.
			if (thead->type != (yyval.no)->Gentry->type) {
				fprintf(stderr, "Error: Function return type shows conflicts in function declaration and function definiton.(%s, %s)\n", thead->type->name, (yyvsp[-10].varname));
				exit(1);
			}
			//Function entry saved to be used in codeGen. (For checking return type for return node.)
			funcGentry = (yyval.no)->Gentry;
			tpop(&thead);
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
#line 1872 "y.tab.c"
    break;

  case 46:
#line 246 "exprtree.y"
                        {
				//Adding global entry.
				Ginstall(&Ghead, "main", Tlookup("int"), 0, NULL);
				//Build AST for function.
				struct tnode* temp_node;
				temp_node = createTree(0, Tlookup("void"), NULL, 8, (yyvsp[-3].no), (yyvsp[-2].no));
				(yyval.no) = createTree(0, Tlookup("int"), "main", 22, temp_node, NULL);
				(yyval.no)->Gentry = Ghead;
				(yyval.no)->Gentry->flabel = strdup("main");
				funcGentry = (yyval.no)->Gentry;
				codeGen((yyval.no));
				struct Lsymbol *Ltemp;
				while(Lhead != NULL) {
					Ltemp = Lhead;
					Lhead = Lhead->next;
					free(Ltemp);
				}
				deallocateAST((yyval.no));
			}
#line 1896 "y.tab.c"
    break;

  case 47:
#line 268 "exprtree.y"
                        {
				if (decl_flag == 0) {
					n_params += 1;
					Linstall(&Lhead, Phead->name, Phead->type);
				}
			}
#line 1907 "y.tab.c"
    break;

  case 48:
#line 276 "exprtree.y"
                        {
				if (decl_flag == 0) {
					n_params = 1;
					Linstall(&Lhead, Phead->name, Phead->type);
				}
			}
#line 1918 "y.tab.c"
    break;

  case 49:
#line 284 "exprtree.y"
                        {n_params = 0;}
#line 1924 "y.tab.c"
    break;

  case 50:
#line 287 "exprtree.y"
                                        {Pinstall(&Phead, (yyvsp[0].varname), thead->type); tpop(&thead);}
#line 1930 "y.tab.c"
    break;

  case 56:
#line 298 "exprtree.y"
                                {tpop(&thead);}
#line 1936 "y.tab.c"
    break;

  case 57:
#line 300 "exprtree.y"
                                {Linstall(&Lhead, (yyvsp[0].varname), thead->type);}
#line 1942 "y.tab.c"
    break;

  case 58:
#line 301 "exprtree.y"
                                                {Linstall(&Lhead, (yyvsp[0].varname), thead->type);}
#line 1948 "y.tab.c"
    break;

  case 63:
#line 313 "exprtree.y"
                {
			if (Fhead->fieldIndex >= Thead->size) {
				fprintf(stderr, "Error: Total size of the field numbers exceeds %d (Maximum allowed size).\n", Thead->size);
				exit(1);
			}
			Thead->fields = Fhead;
			Fhead = NULL;
		}
#line 1961 "y.tab.c"
    break;

  case 64:
#line 324 "exprtree.y"
                        {
				TInstall((yyvsp[0].varname), 8, NULL);
			}
#line 1969 "y.tab.c"
    break;

  case 65:
#line 328 "exprtree.y"
                                          {Fhead->fieldIndex = Fhead->next->fieldIndex + 1;}
#line 1975 "y.tab.c"
    break;

  case 66:
#line 329 "exprtree.y"
                                                                        {Fhead->fieldIndex = 0;}
#line 1981 "y.tab.c"
    break;

  case 67:
#line 332 "exprtree.y"
                                        {FInstall(&Fhead, (yyvsp[-1].varname), thead->type); tpop(&thead);}
#line 1987 "y.tab.c"
    break;

  case 68:
#line 334 "exprtree.y"
                                                        {tpush(&thead, Tlookup("int"));}
#line 1993 "y.tab.c"
    break;

  case 69:
#line 335 "exprtree.y"
                                                                {tpush(&thead, Tlookup("str"));}
#line 1999 "y.tab.c"
    break;

  case 70:
#line 337 "exprtree.y"
                        {
				struct Typetable *Ttemp;
				Ttemp = Tlookup((yyvsp[0].varname));
				if (Ttemp == NULL) {
					fprintf(stderr, "Error: The user-defined type '%s' is not defined.\n", (yyvsp[0].varname));
					exit(1);
				}
				tpush(&thead, Ttemp);
			}
#line 2013 "y.tab.c"
    break;

  case 71:
#line 349 "exprtree.y"
                {
			struct tnode *tn = (yyvsp[-2].no);
			while(tn->left != NULL) {
				tn = tn->left;
			}
			struct Fieldlist *Ftemp = FLookup(tn->type->fields, (yyvsp[0].varname));
			if (Ftemp == NULL) {
				fprintf(stderr, "Error: %s' type has no member field named '%s'.\n", tn->type->name, (yyvsp[0].varname));
				exit(1);
			}
			struct tnode *temp = createTree(0, Ftemp->type, (yyvsp[0].varname), none, NULL, NULL);
			tn->left = temp;
			(yyvsp[-2].no)->type = Ftemp->type;
		}
#line 2032 "y.tab.c"
    break;

  case 72:
#line 365 "exprtree.y"
                {
			struct Typetable *type;
			struct Fieldlist *Ftemp;
			struct Lsymbol *Ltemp = Llookup(Lhead, (yyvsp[-2].varname));
			if (Ltemp == NULL) {
				struct Gsymbol *Gentry = Glookup(Ghead, (yyvsp[-2].varname));
				if (Gentry == NULL) {
					fprintf(stderr, "Error: The variable '%s' is not declared.\n", (yyvsp[-2].varname));
					exit(1);
				}
				Ftemp = FLookup(Gentry->type->fields, (yyvsp[0].varname));
				type = Gentry->type;
			}
			else {
				Ftemp = FLookup(Ltemp->type->fields, (yyvsp[0].varname));
				type = Ltemp->type;
			}
			if (Ftemp == NULL) {
				fprintf(stderr, "Error: '%s' ('%s' type) has no member named '%s'.\n", (yyvsp[-2].varname), type->name, (yyvsp[0].varname));
				exit(1);
			}
			struct tnode *temp = createTree(0, Ftemp->type, (yyvsp[0].varname), none, NULL, NULL);
			struct tnode *temp2 = createTree(0, type, (yyvsp[-2].varname), none, temp, NULL);
			(yyval.no) = createTree(0, Ftemp->type, NULL, 24, temp2, NULL);
		}
#line 2062 "y.tab.c"
    break;

  case 73:
#line 392 "exprtree.y"
                                {(yyval.no) = createTree(0, Tlookup("int"), NULL, 1, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2068 "y.tab.c"
    break;

  case 74:
#line 393 "exprtree.y"
                                {(yyval.no) = createTree(0, Tlookup("int"), NULL, 2, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2074 "y.tab.c"
    break;

  case 75:
#line 394 "exprtree.y"
                                        {(yyval.no) = createTree(0, Tlookup("int"), NULL, 3, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2080 "y.tab.c"
    break;

  case 76:
#line 395 "exprtree.y"
                                        {(yyval.no) = createTree(0, Tlookup("int"), NULL, 4, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2086 "y.tab.c"
    break;

  case 77:
#line 396 "exprtree.y"
                                        {(yyval.no) = createTree(0, Tlookup("int"), NULL, 20, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2092 "y.tab.c"
    break;

  case 78:
#line 397 "exprtree.y"
                                        {(yyval.no) = createTree(0, Tlookup("bool"), NULL, 9, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2098 "y.tab.c"
    break;

  case 79:
#line 398 "exprtree.y"
                                        {(yyval.no) = createTree(0, Tlookup("bool"), NULL, 10, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2104 "y.tab.c"
    break;

  case 80:
#line 399 "exprtree.y"
                                        {(yyval.no) = createTree(0, Tlookup("bool"), NULL, 11, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2110 "y.tab.c"
    break;

  case 81:
#line 400 "exprtree.y"
                                        {(yyval.no) = createTree(0, Tlookup("bool"), NULL, 12, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2116 "y.tab.c"
    break;

  case 82:
#line 401 "exprtree.y"
                                        {(yyval.no) = createTree(0, Tlookup("bool"), NULL, 13, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2122 "y.tab.c"
    break;

  case 83:
#line 402 "exprtree.y"
                                        {(yyval.no) = createTree(0, Tlookup("bool"), NULL, 14, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2128 "y.tab.c"
    break;

  case 84:
#line 403 "exprtree.y"
                                        {(yyval.no) = createTree(0, NULL, (yyvsp[-2].varname), 23, NULL, NULL);}
#line 2134 "y.tab.c"
    break;

  case 85:
#line 405 "exprtree.y"
         {
		 struct tnode *tn;
		 (yyval.no) = createTree(0, NULL, (yyvsp[-3].varname), 23, NULL, NULL);
		 tn = cmpArg(&arghead, &((yyval.no)->Gentry->paramlist));
		 (yyval.no)->left = tn;
	 }
#line 2145 "y.tab.c"
    break;

  case 86:
#line 411 "exprtree.y"
                                        {(yyval.no) = (yyvsp[-1].no);}
#line 2151 "y.tab.c"
    break;

  case 87:
#line 412 "exprtree.y"
                                                {(yyval.no) = (yyvsp[0].no);}
#line 2157 "y.tab.c"
    break;

  case 88:
#line 413 "exprtree.y"
                                                {(yyval.no) = (yyvsp[0].no);}
#line 2163 "y.tab.c"
    break;

  case 89:
#line 414 "exprtree.y"
                                                {(yyval.no) = createTree(0, Tlookup("void"), NULL, 27, NULL, NULL);}
#line 2169 "y.tab.c"
    break;

  case 90:
#line 415 "exprtree.y"
                                                {(yyval.no) = createTree((yyvsp[0].number), Tlookup("int"), NULL, none, NULL, NULL);}
#line 2175 "y.tab.c"
    break;

  case 91:
#line 416 "exprtree.y"
                                        {(yyval.no) = createTree(0, NULL, (yyvsp[-3].varname), 19, (yyvsp[-1].no), NULL);}
#line 2181 "y.tab.c"
    break;

  case 92:
#line 417 "exprtree.y"
                                                {(yyval.no) = createTree(0, NULL, (yyvsp[0].varname), none, NULL, NULL);}
#line 2187 "y.tab.c"
    break;

  case 93:
#line 418 "exprtree.y"
                                                {(yyval.no) = makeStringNode((yyvsp[0].literal));}
#line 2193 "y.tab.c"
    break;

  case 94:
#line 421 "exprtree.y"
                                {argpush(&arghead, (yyvsp[0].no));}
#line 2199 "y.tab.c"
    break;

  case 95:
#line 422 "exprtree.y"
                                                {argpush(&arghead, (yyvsp[0].no));}
#line 2205 "y.tab.c"
    break;


#line 2209 "y.tab.c"

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
#line 425 "exprtree.y"


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
	TypeTableCreate();
	yyparse();
	fclose(yyin);
	fclose(target_file);
	return 0;
}
