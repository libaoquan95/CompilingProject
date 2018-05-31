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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    /*T_IntConstant = 258*/
    T_Le = 258,
    T_Ge,
    T_Eq,
    T_Ne,
    T_And,
    T_Or,
    T_Void,
    T_Int,
    T_Double,
    T_Boolean,
    T_String,
    T_Class,
    T_Interface,
    T_Null,
    T_This,
    T_Extends,
    T_Implements,
    T_For,
    T_While,
    T_If,
    T_Else,
    T_Return,
    T_Break,
    T_New,
    T_NewArray,
    T_Print,
    T_ReadInteger,
    T_ReadLine,
    T_IntConstant,
    T_DoubleConstant,
    T_StringConstant,
    T_Identifier,
    T_BooleanConstant
  };
#endif
/* Tokens.  */
/*#define T_IntConstant 258*/
#define	T_Le	258
#define	T_Ge	259
#define	T_Eq	260
#define	T_Ne	261
#define	T_And	262
#define	T_Or	263
#define	T_Void	264
#define	T_Int	265
#define	T_Double	266
#define	T_Boolean	267
#define	T_String	268
#define	T_Class		269
#define	T_Interface	270
#define	T_Null		271
#define	T_This		272
#define	T_Extends	273
#define	T_Implements	274
#define	T_For		275
#define	T_While		276
#define	T_If		277
#define	T_Else		278
#define	T_Return	279
#define	T_Break		280
#define	T_New		281
#define	T_NewArray	282
#define	T_Print		283
#define	T_ReadInteger	284
#define	T_ReadLine	285
#define	T_IntConstant	286
#define	T_DoubleConstant	287
#define	T_StringConstant	288
#define	T_Identifier		289
#define	T_BooleanConstant	290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
