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
    T_Le = 258,
    T_Ge = 259,
    T_Eq = 260,
    T_Ne = 261,
    T_And = 262,
    T_Or = 263,
    T_Void = 264,
    T_Int = 265,
    T_Double = 266,
    T_Boolean = 267,
    T_String = 268,
    T_Class = 269,
    T_Interface = 270,
    T_Null = 271,
    T_This = 272,
    T_Extends = 273,
    T_Implements = 274,
    T_For = 275,
    T_While = 276,
    T_If = 277,
    T_Else = 278,
    T_Return = 279,
    T_Break = 280,
    T_New = 281,
    T_NewArray = 282,
    T_Print = 283,
    T_ReadInteger = 284,
    T_ReadLine = 285,
    T_IntConstant = 286,
    T_DoubleConstant = 287,
    T_StringConstant = 288,
    T_Identifier = 289,
    T_BooleanConstant = 290,
    T_OR = 291,
    T_AND = 292,
    T_LET = 293,
    T_HET = 294,
    T_ELSE = 295,
    T_IFX = 296
  };
#endif
/* Tokens.  */
#define T_Le 258
#define T_Ge 259
#define T_Eq 260
#define T_Ne 261
#define T_And 262
#define T_Or 263
#define T_Void 264
#define T_Int 265
#define T_Double 266
#define T_Boolean 267
#define T_String 268
#define T_Class 269
#define T_Interface 270
#define T_Null 271
#define T_This 272
#define T_Extends 273
#define T_Implements 274
#define T_For 275
#define T_While 276
#define T_If 277
#define T_Else 278
#define T_Return 279
#define T_Break 280
#define T_New 281
#define T_NewArray 282
#define T_Print 283
#define T_ReadInteger 284
#define T_ReadLine 285
#define T_IntConstant 286
#define T_DoubleConstant 287
#define T_StringConstant 288
#define T_Identifier 289
#define T_BooleanConstant 290
#define T_OR 291
#define T_AND 292
#define T_LET 293
#define T_HET 294
#define T_ELSE 295
#define T_IFX 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "parser.y" /* yacc.c:1909  */

    int      ival;
    char     *sval;
    double   dval;
    bool     bval;

    // List
    list<Entity*>     *entityList;
    list<Expression*> *exprList;
    list<Statement*>  *stmtList;

    // Entity
    Entity            *entity;
    ClassEntity       *classEntity;
    FunctionEntity    *functionEntity;
    VariableEntity    *variableEntity;

    // Statement
    Statement         *statement;

    // Type
    Type              *typeVal;

    // Expression 
    Expression        *expression;

#line 163 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */