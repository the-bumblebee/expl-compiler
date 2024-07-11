/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    NUM = 258,
    COL = 259,
    PLUS = 260,
    MINUS = 261,
    MUL = 262,
    DIV = 263,
    MOD = 264,
    END = 265,
    BEGINI = 266,
    READI = 267,
    WRITEI = 268,
    ID = 269,
    IDdecl = 270,
    EQUAL = 271,
    IF = 272,
    then = 273,
    Else = 274,
    ENDIF = 275,
    WHILE = 276,
    DO = 277,
    ENDWHILE = 278,
    BREAK = 279,
    CONTINUE = 280,
    STRLIT = 281,
    DECL = 282,
    ENDDECL = 283,
    INT = 284,
    STR = 285,
    LT = 286,
    GT = 287,
    LE = 288,
    GE = 289,
    NE = 290,
    EQ = 291
  };
#endif
/* Tokens.  */
#define NUM 258
#define COL 259
#define PLUS 260
#define MINUS 261
#define MUL 262
#define DIV 263
#define MOD 264
#define END 265
#define BEGINI 266
#define READI 267
#define WRITEI 268
#define ID 269
#define IDdecl 270
#define EQUAL 271
#define IF 272
#define then 273
#define Else 274
#define ENDIF 275
#define WHILE 276
#define DO 277
#define ENDWHILE 278
#define BREAK 279
#define CONTINUE 280
#define STRLIT 281
#define DECL 282
#define ENDDECL 283
#define INT 284
#define STR 285
#define LT 286
#define GT 287
#define LE 288
#define GE 289
#define NE 290
#define EQ 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "exprtree.y" /* yacc.c:1909  */

	struct tnode *no;


#line 131 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
