/* A Bison parser, made by GNU Bison 3.5.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    EXTENDS = 299,
    LT = 300,
    GT = 301,
    LE = 302,
    GE = 303,
    NE = 304,
    EQ = 305
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
#define EXTENDS 299
#define LT 300
#define GT 301
#define LE 302
#define GE 303
#define NE 304
#define EQ 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "exprtree.y"

	struct tnode *no;
	char *name;
	int number;
	char* literal;

#line 164 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
