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
	#include "classlib.h"

	#include "tablelib.h"

	#define TYPE_SIZE 8

	FILE *yyin;
	FILE *out_file;

	int line_no;
	int decl_flag, class_flag;
	int yylex(void);
	void yyerror(char const *s);

	struct Methodlist *funcTempEntry;
	struct Typetable *Tentry;
	struct Fieldlist *Fhead = NULL;
	struct type_node *thead = NULL;
	struct arglist *arghead = NULL;


#line 100 "y.tab.c"

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
    CLASS = 294,
    ENDCLASS = 295,
    SELF = 296,
    NEW = 297,
    DELETE = 298,
    LT = 299,
    GT = 300,
    LE = 301,
    GE = 302,
    NE = 303,
    EQ = 304
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
#define CLASS 294
#define ENDCLASS 295
#define SELF 296
#define NEW 297
#define DELETE 298
#define LT 299
#define GT 300
#define LE 301
#define GE 302
#define NE 303
#define EQ 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "exprtree.y"

	struct tnode *no;
	char *name;
	int number;
	char* literal;

#line 257 "y.tab.c"

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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   460

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

#define YYUNDEFTOK  2
#define YYMAXUTOK   304


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
      50,    51,     2,     2,    54,     2,    57,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    48,    48,    49,    52,    53,    55,    56,    57,    58,
      59,    60,    61,    62,    65,    67,    73,    79,    85,    87,
      89,    95,   101,   107,   113,   120,   126,   127,   128,   131,
     132,   135,   138,   139,   142,   143,   144,   151,   152,   155,
     220,   253,   254,   256,   263,   271,   279,   282,   283,   284,
     287,   288,   290,   292,   293,   296,   297,   300,   301,   304,
     306,   308,   309,   312,   314,   315,   316,   326,   348,   387,
     401,   402,   405,   406,   409,   412,   415,   416,   419,   422,
     423,   426,   429,   430,   433,   460,   495,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   534,   543,
     544,   545,   546,   547,   548,   549,   551,   560,   569,   570,
     571,   572,   575,   576,   577
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
  "TYPE", "ENDTYPE", "ALLOC", "FREE", "NULLV", "INITIALIZE", "CLASS",
  "ENDCLASS", "SELF", "NEW", "DELETE", "LT", "GT", "LE", "GE", "NE", "EQ",
  "'('", "')'", "'['", "']'", "','", "'{'", "'}'", "'.'", "$accept",
  "program", "Slist", "Stmt", "RtnStmt", "InputStmt", "InitFunc",
  "OutputStmt", "AsgStmt", "Ifstmt", "Whilestmt", "GDeclBlock",
  "GDeclList", "GDecl", "GidList", "Gid", "FDefBlock", "Fdef", "MainBlock",
  "Body", "ParamList", "Param", "LDeclBlock", "LDeclList", "LDecl",
  "IdList", "TypeDefBlock", "TypeDefList", "TypeDef", "TypeDecl",
  "FieldDeclList", "FieldDecl", "TypeName", "Field", "ClassDefBlock",
  "ClassDefList", "ClassDef", "Cname", "Fieldlists", "Fld", "MethodDecl",
  "MDecl", "MethodDefns", "FieldFunction", "expr", "ArgList", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      40,    41,    91,    93,    44,   123,   125,    46
};
# endif

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,    79,   103,    73,  -150,    -9,  -150,    53,  -150,    97,
      98,  -150,  -150,   119,  -150,    -7,  -150,    91,    85,   131,
    -150,  -150,  -150,    -4,  -150,   135,  -150,  -150,   125,  -150,
     112,  -150,   147,   161,   131,  -150,  -150,   150,  -150,  -150,
     168,  -150,  -150,  -150,    18,    -1,  -150,   132,  -150,  -150,
     133,  -150,   119,   119,   179,  -150,   147,   124,   119,   169,
    -150,   157,  -150,    32,  -150,   174,   138,  -150,   144,    42,
       0,   119,   184,  -150,  -150,   119,  -150,  -150,   178,   158,
    -150,   119,  -150,     5,   162,  -150,   173,   208,   178,    69,
    -150,  -150,  -150,   195,  -150,   206,   419,   171,   208,   226,
    -150,  -150,  -150,     2,   193,   183,   192,    12,   194,   200,
     245,   252,   202,   419,  -150,   240,  -150,  -150,  -150,  -150,
    -150,     1,  -150,   204,  -150,  -150,   250,  -150,   -37,  -150,
     217,   218,  -150,   269,   223,   270,   295,   193,  -150,   231,
    -150,   315,   -13,   193,   193,   193,   280,   193,   193,  -150,
    -150,   288,  -150,   300,  -150,   193,   341,  -150,  -150,   193,
     193,   380,   346,   193,   348,   384,   385,   193,   230,   386,
    -150,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   -41,    33,   238,   321,   123,  -150,   246,   254,
    -150,  -150,   327,  -150,   339,    86,   148,   353,  -150,   262,
    -150,   354,   357,   307,  -150,   360,    13,    13,  -150,  -150,
    -150,   382,   382,   382,   382,   382,   382,   405,   193,   408,
     409,  -150,   401,   400,   397,  -150,  -150,   193,  -150,   193,
    -150,   193,  -150,  -150,   193,  -150,   170,  -150,  -150,   193,
     419,   419,   339,   154,   156,   344,   370,   333,    84,  -150,
      16,  -150,  -150,  -150,   417,  -150,   419,   418,   430,  -150,
     391,  -150,  -150,   432,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      56,     0,     0,    71,    60,     0,    58,     0,     1,     0,
      28,    55,    57,     0,    75,     0,    73,     0,     0,     0,
      66,    64,    65,     0,    62,     0,    70,    72,     0,    27,
       0,    30,     0,    64,     0,    38,     3,     0,    59,    61,
       0,    77,    26,    29,    34,     0,    33,     0,    37,     2,
       0,    63,     0,    46,     0,    31,     0,     0,    46,     0,
      76,     0,    80,     0,    44,     0,     0,    32,     0,     0,
       0,     0,     0,    79,    36,    46,    45,    35,    49,     0,
      78,    46,    83,     0,     0,    43,     0,     0,    49,     0,
      74,    82,    48,     0,    51,     0,     0,     0,     0,     0,
      47,    50,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,    11,     6,     7,     8,     9,
      10,     0,    40,     0,    81,    52,     0,   108,   110,   111,
       0,     0,   105,     0,     0,     0,     0,     0,   102,   101,
     100,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      12,     0,     4,    11,    42,     0,     0,    39,    53,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,     0,     0,
      69,    41,     0,    67,   113,     0,     0,    68,   103,     0,
      18,    69,     0,     0,    99,    67,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,     0,     0,     0,
       0,    20,     0,     0,     0,    22,    98,     0,   109,   114,
     104,   114,   106,   107,   114,    15,     0,    17,    19,     0,
       0,     0,   112,     0,     0,     0,     0,     0,     0,    11,
       0,    85,    84,    86,     0,    21,     0,     0,     0,    16,
       0,    24,    25,     0,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -149,  -112,   -31,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,   395,  -150,   383,  -150,   -32,   406,   345,
       4,   367,   358,  -150,   355,  -150,  -150,  -150,   442,  -150,
    -150,   426,    36,   -96,  -150,  -150,   435,  -150,  -150,  -150,
    -150,   390,  -150,  -150,  -100,  -110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   113,   114,   249,   116,   138,   117,   118,   119,
     120,    19,    30,    31,    45,    46,    34,    35,    36,    97,
      63,    64,    87,    93,    94,   103,     3,     5,     6,     7,
      23,    24,    37,   139,    10,    15,    16,    17,    52,    60,
      61,    62,    83,   140,   194,   195
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     121,   152,    48,   182,   141,    55,    80,     4,   125,    14,
     217,   218,    20,   159,     1,   160,   146,   121,   155,   104,
     161,    20,   173,   174,   175,    11,    21,    22,   112,   144,
     105,   106,   107,    26,   108,    21,    22,   168,   109,    82,
     258,   110,   111,   184,   185,   186,   183,   188,   189,    25,
      81,    91,    38,    56,    32,   192,   126,   112,   156,    25,
     196,    90,    69,   199,   145,   115,    32,   203,    53,   146,
      54,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   153,    74,   219,    89,    75,   104,    59,    65,
     156,   248,   250,    79,    65,     4,    75,    72,   105,   106,
     107,    20,   108,     8,   256,   257,   109,   260,    13,   110,
     111,    65,     9,    14,    29,    21,    22,    65,   236,   243,
      99,   244,    95,    75,   245,   112,    18,   242,    20,    95,
     171,   172,   173,   174,   175,    20,   152,   226,   152,   247,
     227,    42,    21,    22,   121,   121,    28,    20,   152,    21,
      22,    40,   121,    41,   121,   171,   172,   173,   174,   175,
     121,    33,    22,    44,   121,    47,    50,   176,   177,   178,
     179,   180,   181,    20,    51,    68,   222,   171,   172,   173,
     174,   175,    57,    58,    66,    70,    71,    21,    22,    20,
      76,    77,   176,   177,   178,   179,   180,   181,   127,    78,
      84,   228,    92,    21,    22,   251,    86,   252,   227,   128,
     227,    20,    81,    88,   176,   177,   178,   179,   180,   181,
     129,    96,   102,   246,   100,    21,    22,   122,   130,   131,
     132,   133,   124,   142,   134,   135,   136,   171,   172,   173,
     174,   175,   143,   137,   147,   171,   172,   173,   174,   175,
     148,   149,   154,   171,   172,   173,   174,   175,   150,   151,
     157,   171,   172,   173,   174,   175,   158,   162,   163,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     165,   204,   176,   177,   178,   179,   180,   181,   169,   220,
     176,   177,   178,   179,   180,   181,   187,   223,   176,   177,
     178,   179,   180,   181,   190,   224,   176,   177,   178,   179,
     180,   181,   191,   230,   171,   172,   173,   174,   175,   164,
     166,   170,   171,   172,   173,   174,   175,   221,   171,   172,
     173,   174,   175,   225,   171,   172,   173,   174,   175,   255,
     171,   172,   173,   174,   175,   167,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   193,   233,   176,
     177,   178,   179,   180,   181,   176,   177,   178,   179,   180,
     181,   176,   177,   178,   179,   180,   181,   176,   177,   178,
     179,   180,   181,   176,   177,   178,   179,   180,   181,   171,
     172,   173,   174,   175,   104,   253,   197,   198,   227,   200,
     201,   202,   205,   229,   231,   105,   106,   107,   232,   108,
     234,   235,   263,   109,   237,   238,   110,   111,   239,   240,
     241,   254,   104,   259,   261,    43,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   105,   106,   107,   262,   108,   264,    67,
      49,   109,    85,   123,   110,   111,    98,    12,   101,    39,
      27,    73,     0,     0,     0,     0,     0,     0,     0,     0,
     112
};

static const yytype_int16 yycheck[] =
{
      96,   113,    34,    16,   104,     6,     6,    16,     6,    16,
      51,    52,    16,    50,    33,    52,    57,   113,    17,     3,
      57,    16,     9,    10,    11,    34,    30,    31,    41,    17,
      14,    15,    16,    40,    18,    30,    31,   137,    22,    71,
      24,    25,    26,   143,   144,   145,   142,   147,   148,    13,
      50,    83,    56,    54,    18,   155,    54,    41,    57,    23,
     160,    56,    58,   163,    52,    96,    30,   167,    50,    57,
      52,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   113,    51,    51,    81,    54,     3,    52,    53,
      57,   240,   241,    51,    58,    16,    54,    61,    14,    15,
      16,    16,    18,     0,    20,    21,    22,   256,    55,    25,
      26,    75,    39,    16,    29,    30,    31,    81,   218,   229,
      51,   231,    86,    54,   234,    41,    28,   227,    16,    93,
       7,     8,     9,    10,    11,    16,   248,    51,   250,   239,
      54,    29,    30,    31,   240,   241,    55,    16,   260,    30,
      31,    16,   248,    28,   250,     7,     8,     9,    10,    11,
     256,    30,    31,    16,   260,     4,    16,    44,    45,    46,
      47,    48,    49,    16,     6,    51,    53,     7,     8,     9,
      10,    11,    50,    50,     5,    16,    29,    30,    31,    16,
      16,    53,    44,    45,    46,    47,    48,    49,     5,    55,
      16,    53,    29,    30,    31,    51,    28,    51,    54,    16,
      54,    16,    50,    55,    44,    45,    46,    47,    48,    49,
      27,    13,    16,    53,    29,    30,    31,    56,    35,    36,
      37,    38,     6,    50,    41,    42,    43,     7,     8,     9,
      10,    11,    50,    50,    50,     7,     8,     9,    10,    11,
      50,     6,    12,     7,     8,     9,    10,    11,     6,    57,
      56,     7,     8,     9,    10,    11,    16,    50,    50,     7,
       8,     9,    10,    11,    44,    45,    46,    47,    48,    49,
      57,    51,    44,    45,    46,    47,    48,    49,    57,    51,
      44,    45,    46,    47,    48,    49,    16,    51,    44,    45,
      46,    47,    48,    49,    16,    51,    44,    45,    46,    47,
      48,    49,    12,    51,     7,     8,     9,    10,    11,    50,
      50,     6,     7,     8,     9,    10,    11,     6,     7,     8,
       9,    10,    11,     6,     7,     8,     9,    10,    11,     6,
       7,     8,     9,    10,    11,    50,     7,     8,     9,    10,
      11,    44,    45,    46,    47,    48,    49,    16,    51,    44,
      45,    46,    47,    48,    49,    44,    45,    46,    47,    48,
      49,    44,    45,    46,    47,    48,    49,    44,    45,    46,
      47,    48,    49,    44,    45,    46,    47,    48,    49,     7,
       8,     9,    10,    11,     3,    51,    16,    51,    54,    51,
      16,    16,    16,    50,    50,    14,    15,    16,    51,    18,
      50,     6,    21,    22,     6,     6,    25,    26,    17,    19,
      23,    51,     3,     6,     6,    30,    44,    45,    46,    47,
      48,    49,    41,    14,    15,    16,     6,    18,     6,    56,
      34,    22,    75,    98,    25,    26,    88,     5,    93,    23,
      15,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    59,    84,    16,    85,    86,    87,     0,    39,
      92,    34,    86,    55,    16,    93,    94,    95,    28,    69,
      16,    30,    31,    88,    89,    90,    40,    94,    55,    29,
      70,    71,    90,    30,    74,    75,    76,    90,    56,    89,
      16,    28,    29,    71,    16,    72,    73,     4,    75,    76,
      16,     6,    96,    50,    52,     6,    54,    50,    50,    90,
      97,    98,    99,    78,    79,    90,     5,    73,    51,    78,
      16,    29,    90,    99,    51,    54,    16,    53,    55,    51,
       6,    50,    75,   100,    16,    79,    28,    80,    55,    78,
      56,    75,    29,    81,    82,    90,    13,    77,    80,    51,
      29,    82,    16,    83,     3,    14,    15,    16,    18,    22,
      25,    26,    41,    60,    61,    62,    63,    65,    66,    67,
      68,    91,    56,    77,     6,     6,    54,     5,    16,    27,
      35,    36,    37,    38,    41,    42,    43,    50,    64,    91,
     101,   102,    50,    50,    17,    52,    57,    50,    50,     6,
       6,    57,    61,    62,    12,    17,    57,    56,    16,    50,
      52,    57,    50,    50,    50,    57,    50,    50,   102,    57,
       6,     7,     8,     9,    10,    11,    44,    45,    46,    47,
      48,    49,    16,    91,   102,   102,   102,    16,   102,   102,
      16,    12,   102,    16,   102,   103,   102,    16,    51,   102,
      51,    16,    16,   102,    51,    16,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,    51,    52,    51,
      51,     6,    53,    51,    51,     6,    51,    54,    53,    50,
      51,    50,    51,    51,    50,     6,   102,     6,     6,    17,
      19,    23,   102,   103,   103,   103,    53,   102,    60,    62,
      60,    51,    51,    51,    51,     6,    20,    21,    24,     6,
      60,     6,     6,    21,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    63,    63,    63,    64,    65,
      66,    66,    66,    67,    67,    68,    69,    69,    69,    70,
      70,    71,    72,    72,    73,    73,    73,    74,    74,    75,
      76,    77,    77,    78,    78,    79,    79,    80,    80,    80,
      81,    81,    82,    83,    83,    84,    84,    85,    85,    86,
      87,    88,    88,    89,    90,    90,    90,    91,    91,    91,
      92,    92,    93,    93,    94,    95,    96,    96,    97,    98,
      98,    99,   100,   100,   101,   101,   101,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     5,     8,     5,     3,     5,
       4,     7,     4,    10,     8,     8,     3,     2,     0,     2,
       1,     3,     3,     1,     1,     4,     4,     2,     1,     9,
       8,     4,     3,     3,     1,     2,     0,     3,     2,     0,
       2,     1,     3,     3,     1,     3,     0,     2,     1,     4,
       1,     2,     1,     3,     1,     1,     1,     3,     3,     3,
       3,     0,     2,     1,     8,     1,     2,     0,     3,     2,
       1,     6,     2,     1,     6,     6,     6,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       1,     1,     1,     3,     4,     1,     4,     4,     1,     4,
       1,     1,     3,     1,     0
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
#line 48 "exprtree.y"
                                                                                        {exit(1);}
#line 1653 "y.tab.c"
    break;

  case 3:
#line 49 "exprtree.y"
                                                                                                        {exit(1);}
#line 1659 "y.tab.c"
    break;

  case 4:
#line 52 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "void", NULL, 8, (yyvsp[-1].no), (yyvsp[0].no));}
#line 1665 "y.tab.c"
    break;

  case 12:
#line 61 "exprtree.y"
                                                                        {(yyval.no) = createTree(0, "void", NULL, 17, NULL, NULL);}
#line 1671 "y.tab.c"
    break;

  case 13:
#line 62 "exprtree.y"
                                                                                {(yyval.no) = createTree(0, "void", NULL, 18, NULL, NULL);}
#line 1677 "y.tab.c"
    break;

  case 14:
#line 65 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "void", NULL, 21, (yyvsp[-1].no), NULL);}
#line 1683 "y.tab.c"
    break;

  case 15:
#line 68 "exprtree.y"
                                {
					struct tnode* t; t = createTree(0, NULL, (yyvsp[-2].name), none, NULL, NULL);
					(yyval.no) = createTree(0, "void", NULL, 6, t, NULL);
				}
#line 1692 "y.tab.c"
    break;

  case 16:
#line 74 "exprtree.y"
                                {
					struct tnode* t = createTree(0, NULL, (yyvsp[-5].name), 19, (yyvsp[-3].no), NULL);
					(yyval.no) = createTree(0, "void", NULL, 6, t, NULL);
				}
#line 1701 "y.tab.c"
    break;

  case 17:
#line 80 "exprtree.y"
                                {
					(yyval.no) = createTree(0, "void", NULL, 6, (yyvsp[-2].no), NULL);
				}
#line 1709 "y.tab.c"
    break;

  case 18:
#line 85 "exprtree.y"
                                                        {(yyval.no) = createTree(0, "int", NULL, 28, NULL, NULL);}
#line 1715 "y.tab.c"
    break;

  case 19:
#line 87 "exprtree.y"
                                                        {(yyval.no) = createTree(0, "void", NULL, 7, (yyvsp[-2].no), NULL);}
#line 1721 "y.tab.c"
    break;

  case 20:
#line 90 "exprtree.y"
                                {
					struct tnode* t; t = createTree(0, NULL, (yyvsp[-3].name), none, NULL, NULL);
					(yyval.no) = createTree(0, "void", NULL, 5, t, (yyvsp[-1].no));
				}
#line 1730 "y.tab.c"
    break;

  case 21:
#line 96 "exprtree.y"
                                {
					struct tnode* t = createTree(0, NULL, (yyvsp[-6].name), 19, (yyvsp[-4].no), NULL);
					(yyval.no) = createTree(0, "void", NULL, 5, t, (yyvsp[-1].no));
				}
#line 1739 "y.tab.c"
    break;

  case 22:
#line 102 "exprtree.y"
                                {
					(yyval.no) = createTree(0, "void", NULL, 5, (yyvsp[-3].no), (yyvsp[-1].no));
				}
#line 1747 "y.tab.c"
    break;

  case 23:
#line 108 "exprtree.y"
                                {
					struct tnode* t; t = createTree(0, "void", NULL, 8, (yyvsp[-4].no), (yyvsp[-2].no));
					(yyval.no) = createTree(0, "void", NULL, 15, (yyvsp[-7].no), t);
				}
#line 1756 "y.tab.c"
    break;

  case 24:
#line 114 "exprtree.y"
                                {
					struct tnode* t; t = createTree(0, "void", NULL, 8, (yyvsp[-2].no), NULL);
					(yyval.no) = createTree(0, "void", NULL, 15, (yyvsp[-5].no), t);
				}
#line 1765 "y.tab.c"
    break;

  case 25:
#line 121 "exprtree.y"
                                {
					(yyval.no) = createTree(0, "void", NULL, 16, (yyvsp[-5].no), (yyvsp[-2].no));
				}
#line 1773 "y.tab.c"
    break;

  case 31:
#line 135 "exprtree.y"
                                                {tpop(&thead);}
#line 1779 "y.tab.c"
    break;

  case 34:
#line 142 "exprtree.y"
                                                                        {Ginstall(&Ghead, (yyvsp[0].name), thead->name, 1, NULL);}
#line 1785 "y.tab.c"
    break;

  case 35:
#line 143 "exprtree.y"
                                                                {Ginstall(&Ghead, (yyvsp[-3].name), thead->name, (yyvsp[-1].number), NULL);}
#line 1791 "y.tab.c"
    break;

  case 36:
#line 145 "exprtree.y"
                                {
					Ginstall(&Ghead, (yyvsp[-3].name), thead->name, 0, &Phead);
					Phead = NULL;
				}
#line 1800 "y.tab.c"
    break;

  case 39:
#line 156 "exprtree.y"
                                {
					struct Methodlist *Mtemp;
					//Build AST for function.
					if (class_flag == 1) {
						Mtemp = Class_MLookup((yyvsp[-7].name), Chead);
						(yyval.no) = createTree(0, "void", (yyvsp[-7].name), 22, (yyvsp[-1].no), NULL);
						(yyval.no)->type = Mtemp->type;
						cmpPara(&Phead, &(Mtemp->paramList));											//Compare Phead and fun->paramlist for name equivalence and deallocate Phead.
						funcTempEntry = Mtemp;
					}
					else {
						(yyval.no) = createTree(0, NULL, (yyvsp[-7].name), 22, (yyvsp[-1].no), NULL);
						cmpPara(&Phead, &((yyval.no)->Gentry->paramlist));										//Compare Phead and fun->paramlist for name equivalence and deallocate Phead.

						//Function entry saved to be used in codeGen. (For checking return type for return node.)
						funcTempEntry = (struct Methodlist *)malloc(sizeof(struct Methodlist));
						funcTempEntry->name = (yyval.no)->name;
						funcTempEntry->type = (yyval.no)->type;
						funcTempEntry->flabel = (yyval.no)->Gentry->flabel;
						funcTempEntry->paramList = (yyval.no)->Gentry->paramlist;
						funcTempEntry->next = NULL;
						funcTempEntry->funcIndex = -1;
					}
					//Compare function types in both function declaration and function definition.
					if ((yyval.no)->type != Tlookup(thead->name)) {
						fprintf(stderr, "Error: Function return type shows conflicts in function declaration and function definiton.(%s, %s)\n", thead->name, (yyvsp[-7].name));
						exit(1);
					}

					if (funcTempEntry->flabel != NULL) {
						if (class_flag == 1){
							fprintf(stderr, "Error: Method '%s' already defined within '%s' class.\n", funcTempEntry->name, Chead->name);
							exit(1);
						}
						else {
							fprintf(stderr, "Error: Function '%s' already defined.\n", funcTempEntry->name);
							exit(1);
						}
					}

					if (class_flag == 1){
						funcTempEntry->flabel = (char *)malloc(sizeof(char) * (strlen(Chead->name) + strlen(funcTempEntry->name) + 1));
						strcpy(funcTempEntry->flabel, Chead->name);
						strcat(funcTempEntry->flabel, ".");
						strcat(funcTempEntry->flabel, funcTempEntry->name);
					}
					else {
						funcTempEntry->flabel = strdup(funcTempEntry->name);
					}

					tpop(&thead);
					//codeGen for function.
					codeGen((yyval.no));
					//print_Ltable($2, Lhead);
					//Deallocate Lhead and AST.
					deallocateLTable();
					deallocateAST((yyval.no));
					if (class_flag == 0) {
						free(funcTempEntry);
						funcTempEntry = NULL;
					}
			 	}
#line 1867 "y.tab.c"
    break;

  case 40:
#line 221 "exprtree.y"
                                {
					//Adding global entry.
					Ginstall(&Ghead, "main", "int", 0, NULL);
					//Build AST for function.
					(yyval.no) = createTree(0, "int", "main", 22, (yyvsp[-1].no), NULL);
					(yyval.no)->Gentry = Ghead;

					funcTempEntry = (struct Methodlist *)malloc(sizeof(struct Methodlist));
					funcTempEntry->name = (yyval.no)->name;
					funcTempEntry->type = (yyval.no)->type;
					funcTempEntry->flabel = (yyval.no)->Gentry->flabel;
					funcTempEntry->paramList = (yyval.no)->Gentry->paramlist;
					funcTempEntry->next = NULL;
					funcTempEntry->funcIndex = -1;

					if (funcTempEntry->flabel != NULL) {
						fprintf(stderr, "Error: Function '%s' already defined.\n", funcTempEntry->name);
						exit(1);
					}

					funcTempEntry->flabel = strdup("main");

					codeGen((yyval.no));
					//print_Ltable("main", Lhead);
					deallocateLTable();
					deallocateAST((yyval.no));
					tpop(&thead);
					free(funcTempEntry);
					funcTempEntry = NULL;
				}
#line 1902 "y.tab.c"
    break;

  case 41:
#line 253 "exprtree.y"
                                                                                {(yyval.no) = createTree(0, "void", NULL, 8, (yyvsp[-2].no), (yyvsp[-1].no));}
#line 1908 "y.tab.c"
    break;

  case 42:
#line 254 "exprtree.y"
                                                                                        {(yyval.no) = (yyvsp[-1].no);}
#line 1914 "y.tab.c"
    break;

  case 43:
#line 257 "exprtree.y"
                                {
					if (decl_flag == 0) {
						Linstall(&Lhead, Phead->name, Phead->type);
					}
				}
#line 1924 "y.tab.c"
    break;

  case 44:
#line 264 "exprtree.y"
                                {
					if (decl_flag == 0 && Phead != NULL) {
						Linstall(&Lhead, Phead->name, Phead->type);
					}
				}
#line 1934 "y.tab.c"
    break;

  case 45:
#line 272 "exprtree.y"
                                {
					/*if (class_flag == 1 && Phead == NULL)
						Pinstall(&Phead, "self", Tlookup("void"));*/
					Pinstall(&Phead, (yyvsp[0].name), Tlookup(thead->name)); tpop(&thead);
				}
#line 1944 "y.tab.c"
    break;

  case 46:
#line 279 "exprtree.y"
                                {/*if (class_flag == 1) Pinstall(&Phead, "self", Tlookup("void"));*/}
#line 1950 "y.tab.c"
    break;

  case 52:
#line 290 "exprtree.y"
                                                {tpop(&thead);}
#line 1956 "y.tab.c"
    break;

  case 53:
#line 292 "exprtree.y"
                                                {Linstall(&Lhead, (yyvsp[0].name), Tlookup(thead->name));}
#line 1962 "y.tab.c"
    break;

  case 54:
#line 293 "exprtree.y"
                                                                {Linstall(&Lhead, (yyvsp[0].name), Tlookup(thead->name));}
#line 1968 "y.tab.c"
    break;

  case 59:
#line 304 "exprtree.y"
                                                                        {TFieldUpdate(&Fhead);}
#line 1974 "y.tab.c"
    break;

  case 60:
#line 306 "exprtree.y"
                                                {TInstall((yyvsp[0].name), TYPE_SIZE, NULL);}
#line 1980 "y.tab.c"
    break;

  case 63:
#line 312 "exprtree.y"
                                                        {FInstall(&Fhead, (yyvsp[-1].name), Tlookup(thead->name)); tpop(&thead);}
#line 1986 "y.tab.c"
    break;

  case 64:
#line 314 "exprtree.y"
                                                                {tpush(&thead, "int");}
#line 1992 "y.tab.c"
    break;

  case 65:
#line 315 "exprtree.y"
                                                                        {tpush(&thead, "str");}
#line 1998 "y.tab.c"
    break;

  case 66:
#line 317 "exprtree.y"
                                {
					if (Tlookup((yyvsp[0].name)) == NULL && CLookup((yyvsp[0].name), Chead) == NULL) {
						fprintf(stderr, "Error: '%s' is neither a class nor a user-defined type.\n", (yyvsp[0].name));
						exit(1);
					}
					tpush(&thead, (yyvsp[0].name));
				}
#line 2010 "y.tab.c"
    break;

  case 67:
#line 327 "exprtree.y"
                                {
					struct tnode *temp;
					if ((yyvsp[-2].no)->ctype != NULL) {
						fprintf(stderr, "Error: Fields of a class cannot be accessed in other classes.\n");
						exit(1);
					}

					struct tnode *tn = (yyvsp[-2].no);
					while(tn->left != NULL) {
						tn = tn->left;
					}

					if (tn->type != NULL)
						temp = createFieldVar(tn->type->name, (yyvsp[0].name), NULL, NULL);
					else if (tn->ctype != NULL)
						temp = createFieldVar(tn->ctype->name, (yyvsp[0].name), NULL, NULL);
					tn->left = temp;
					(yyvsp[-2].no)->type = temp->type;
					(yyvsp[-2].no)->ctype = temp->ctype;
				}
#line 2035 "y.tab.c"
    break;

  case 68:
#line 349 "exprtree.y"
                                {
					struct Typetable *type;
					struct Fieldlist *Ftemp;
					struct Gsymbol *Gentry = Glookup(Ghead, (yyvsp[-2].name));
					struct Lsymbol *Ltemp = Llookup(Lhead, (yyvsp[-2].name));

					if (Ltemp == NULL) {
						if (Gentry == NULL) {
							fprintf(stderr, "Error: The class or user-defined type variable '%s' is not declared.\n", (yyvsp[-2].name));
							exit(1);
						}

						if (Gentry->ctype != NULL) {
							fprintf(stderr, "Error: Fields of classes cannot be accessed outside class methods.\n");
							exit(1);
						}

						if (Gentry->type->fields == NULL) {
							fprintf(stderr, "Error: '%s' is neither a user-defined type nor a class object.\n", (yyvsp[-2].name));
							exit(1);
						}
						Ftemp = FLookup(Gentry->type->fields, (yyvsp[0].name));
						type = Gentry->type;
					}
					else {
						Ftemp = FLookup(Ltemp->type->fields, (yyvsp[0].name));
						type = Ltemp->type;
					}

					if (Ftemp == NULL) {
						fprintf(stderr, "Error: '%s' ('%s' type) has no member named '%s'.\n", (yyvsp[-2].name), type->name, (yyvsp[0].name));
						exit(1);
					}
					struct tnode *temp = createTree(0, Ftemp->type->name, (yyvsp[0].name), none, NULL, NULL);
					struct tnode *temp2 = createTree(0, type->name, (yyvsp[-2].name), none, temp, NULL);
					(yyval.no) = createTree(0, Ftemp->type->name, NULL, 24, temp2, NULL);
				}
#line 2077 "y.tab.c"
    break;

  case 69:
#line 388 "exprtree.y"
                                {
					if (class_flag == 0) {
						fprintf(stderr, "Error: 'self' is a reserved keyword and cannot occur outside class methods.\n");
						exit(1);
					}
					struct tnode *temp = createFieldVar(Chead->name, (yyvsp[0].name), NULL, NULL);
					struct tnode *temp2 = createTree(0, Chead->name, NULL, 29, temp, NULL);
					(yyval.no) = createTree(0, "void", NULL, 24, temp2, NULL);
					(yyval.no)->type = temp->type;
					(yyval.no)->ctype = temp->ctype;
				}
#line 2093 "y.tab.c"
    break;

  case 75:
#line 412 "exprtree.y"
                                                {Chead = CInstall((yyvsp[0].name) ,NULL, Chead);}
#line 2099 "y.tab.c"
    break;

  case 78:
#line 419 "exprtree.y"
                                                                {Class_FInstall((yyvsp[-1].name), thead->name, Chead); tpop(&thead);}
#line 2105 "y.tab.c"
    break;

  case 81:
#line 426 "exprtree.y"
                                                            {Class_MInstall((yyvsp[-4].name), Tlookup(thead->name), Phead, Chead); tpop(&thead); Phead = NULL;}
#line 2111 "y.tab.c"
    break;

  case 84:
#line 434 "exprtree.y"
                                {
					//if class flag
					//push bp -3
					struct Methodlist *Mtemp = Class_MLookup((yyvsp[-3].name), Chead);

					if (class_flag == 0) {
						fprintf(stderr, "Error: 'self' is a reserved keyword and cannot occur outside class methods.\n");
						exit(1);
					}

					if (Mtemp == NULL) {
						fprintf(stderr, "Error: The class '%s' has no method named '%s'.\n", Chead->name, (yyvsp[-3].name));
						exit(1);
					}

					struct tnode *self_node = createTree(0, Chead->name, NULL, 29, NULL, NULL);
					struct tnode *field_node = createTree(0, self_node->ctype->name, NULL, 24, self_node, NULL);
					struct tnode *func_node = createTree(0, Mtemp->type->name, Mtemp->name, none, NULL, NULL);
					if (arghead != NULL) {
						struct tnode *arg = cmpArg(&arghead, &(Mtemp->paramList));
						func_node->left = arg;
					}
					(yyval.no) = createTree(0, Mtemp->type->name, NULL, 30, field_node, func_node);

				}
#line 2141 "y.tab.c"
    break;

  case 85:
#line 461 "exprtree.y"
                                {
					//id1-.gebtry n id1->gentry->ctype
					//push id1->binding

					struct Gsymbol *Gentry = Glookup(Ghead, (yyvsp[-5].name));

					if (Gentry == NULL) {
						fprintf(stderr, "Error: There is no class object named '%s'.\n", (yyvsp[-5].name));
						exit(1);
					}

					if (Gentry->ctype == NULL) {
						fprintf(stderr, "Error: '%s' is not a class object and thus, doesn't have any methods.\n", (yyvsp[-5].name));
						exit(1);
					}

					struct Methodlist *Mtemp = Class_MLookup((yyvsp[-3].name), Gentry->ctype);

					if (Mtemp == NULL) {
						fprintf(stderr, "Error: '%s' ('%s' class) has no method named '%s'.\n", (yyvsp[-5].name), Chead->name, (yyvsp[-3].name));
						exit(1);
					}

					struct tnode *id_node = createTree(0, Gentry->ctype->name, (yyvsp[-5].name), none, NULL, NULL);
					struct tnode *field_node = createTree(0, Gentry->ctype->name, NULL, 24, id_node, NULL);
					struct tnode *func_node = createTree(0, Mtemp->type->name, Mtemp->name, none, NULL, NULL);
					if (arghead != NULL) {
						struct tnode *arg = cmpArg(&arghead, &(Mtemp->paramList));
						func_node->left = arg;
					}
					(yyval.no) = createTree(0, Mtemp->type->name, NULL, 30, field_node, func_node);

				}
#line 2179 "y.tab.c"
    break;

  case 86:
#line 496 "exprtree.y"
                                {
					//if(field->ctype)
					//push getIDAddress(field)

					if ((yyvsp[-5].no)->ctype == NULL) {
						fprintf(stderr, "Error at line %d: The object doesn't have methods as it is not a class object.\n", line_no);
						exit(1);
					}

					struct Methodlist *Mtemp = Class_MLookup((yyvsp[-3].name), (yyvsp[-5].no)->ctype);

					if (Mtemp == NULL) {
						fprintf(stderr, "Error at line %d: The class '%s' has no method named '%s'.\n", line_no, (yyvsp[-5].no)->ctype->name);
					}

					//struct tnode *id_node = createTree(0, Gentry->ctype->name, NULL, none, NULL, NULL);
					//struct tnode *field_node = createTree(0, "void", NULL, 24, id_node, NULL);
					struct tnode *func_node = createTree(0, Mtemp->type->name, Mtemp->name, none, NULL, NULL);
					if (arghead != NULL) {
						struct tnode *arg = cmpArg(&arghead, &(Mtemp->paramList));
						func_node->left = arg;
					}
					(yyval.no) = createTree(0, Mtemp->type->name, NULL, 30, (yyvsp[-5].no), func_node);
				}
#line 2208 "y.tab.c"
    break;

  case 87:
#line 522 "exprtree.y"
                                                        {(yyval.no) = createTree(0, "int", NULL, 1, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2214 "y.tab.c"
    break;

  case 88:
#line 523 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "int", NULL, 2, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2220 "y.tab.c"
    break;

  case 89:
#line 524 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "int", NULL, 3, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2226 "y.tab.c"
    break;

  case 90:
#line 525 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "int", NULL, 4, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2232 "y.tab.c"
    break;

  case 91:
#line 526 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "int", NULL, 20, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2238 "y.tab.c"
    break;

  case 92:
#line 527 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "bool", NULL, 9, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2244 "y.tab.c"
    break;

  case 93:
#line 528 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "bool", NULL, 10, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2250 "y.tab.c"
    break;

  case 94:
#line 529 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "bool", NULL, 11, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2256 "y.tab.c"
    break;

  case 95:
#line 530 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "bool", NULL, 12, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2262 "y.tab.c"
    break;

  case 96:
#line 531 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "bool", NULL, 13, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2268 "y.tab.c"
    break;

  case 97:
#line 532 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "bool", NULL, 14, (yyvsp[-2].no), (yyvsp[0].no));}
#line 2274 "y.tab.c"
    break;

  case 98:
#line 535 "exprtree.y"
                                {
					struct tnode *tn;
					(yyval.no) = createTree(0, NULL, (yyvsp[-3].name), 23, NULL, NULL);
					if (arghead != NULL) {
						tn = cmpArg(&arghead, &((yyval.no)->Gentry->paramlist));
						(yyval.no)->left = tn;
					}
				}
#line 2287 "y.tab.c"
    break;

  case 99:
#line 543 "exprtree.y"
                                                                {(yyval.no) = (yyvsp[-1].no);}
#line 2293 "y.tab.c"
    break;

  case 100:
#line 544 "exprtree.y"
                                                                {(yyval.no) = (yyvsp[0].no);}
#line 2299 "y.tab.c"
    break;

  case 101:
#line 545 "exprtree.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2305 "y.tab.c"
    break;

  case 102:
#line 546 "exprtree.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2311 "y.tab.c"
    break;

  case 103:
#line 547 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "void", NULL, 25, NULL, NULL);}
#line 2317 "y.tab.c"
    break;

  case 104:
#line 548 "exprtree.y"
                                                                {(yyval.no) = createTree(0, "int", NULL, 26, (yyvsp[-1].no), NULL);}
#line 2323 "y.tab.c"
    break;

  case 105:
#line 549 "exprtree.y"
                                                                        {(yyval.no) = createTree(0, "void", NULL, 27, NULL, NULL);}
#line 2329 "y.tab.c"
    break;

  case 106:
#line 552 "exprtree.y"
                                {
					if (CLookup((yyvsp[-1].name), Chead) == NULL) {
						fprintf(stderr, "Error at line %d: '%s' is not a class.\n", line_no, (yyvsp[-1].name));
						exit(1);
					}
					(yyval.no) = createTree(0, (yyvsp[-1].name), NULL, 25, NULL, NULL);
				}
#line 2341 "y.tab.c"
    break;

  case 107:
#line 561 "exprtree.y"
                                {
					if ((yyvsp[-1].no)->ctype == NULL) {
						fprintf(stderr, "Error at line %d: Expected a class object.\n", line_no);
						exit(1);
					}
					(yyval.no) = createTree(0, "int", NULL, 26, (yyvsp[-1].no), NULL);
				}
#line 2353 "y.tab.c"
    break;

  case 108:
#line 569 "exprtree.y"
                                                                        {(yyval.no) = createTree((yyvsp[0].number), "int", NULL, none, NULL, NULL);}
#line 2359 "y.tab.c"
    break;

  case 109:
#line 570 "exprtree.y"
                                                                {(yyval.no) = createTree(0, NULL, (yyvsp[-3].name), 19, (yyvsp[-1].no), NULL);}
#line 2365 "y.tab.c"
    break;

  case 110:
#line 571 "exprtree.y"
                                                                        {(yyval.no) = createTree(0, NULL, (yyvsp[0].name), none, NULL, NULL);}
#line 2371 "y.tab.c"
    break;

  case 111:
#line 572 "exprtree.y"
                                                                        {(yyval.no) = makeStringNode((yyvsp[0].literal));}
#line 2377 "y.tab.c"
    break;

  case 112:
#line 575 "exprtree.y"
                                                {argpush(&arghead, (yyvsp[0].no));}
#line 2383 "y.tab.c"
    break;

  case 113:
#line 576 "exprtree.y"
                                                                {argpush(&arghead, (yyvsp[0].no));}
#line 2389 "y.tab.c"
    break;


#line 2393 "y.tab.c"

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
#line 580 "exprtree.y"


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
