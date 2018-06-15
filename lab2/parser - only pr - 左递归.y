%{
#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 
int yylex();
void yyerror(const char* msg) {
    printf("error: %s\n", msg);
}
%}

%start Program

/*bison可以从这个定义中产生yylval的定义*/ 
%union { 
    int     integerConstant; 
    int     boolConstant; 
    const   char *stringConstant; 
    double  doubleConstant; 
    char    identifier[128]; 
}

%token    T_Le                258
%token    T_Ge                259
%token    T_Eq                260
%token    T_Ne                261
%token    T_And               262
%token    T_Or                263
%token    T_Void              264
%token    T_Int               265
%token    T_Double            266
%token    T_Boolean           267
%token    T_String            268
%token    T_Class             269
%token    T_Interface         270
%token    T_Null              271
%token    T_This              272
%token    T_Extends           273
%token    T_Implements        274
%token    T_For               275
%token    T_While             276
%token    T_If                277
%token    T_Else              278
%token    T_Return            279
%token    T_Break             280
%token    T_New               281
%token    T_NewArray          282
%token    T_Print             283
%token    T_ReadInteger       284
%token    T_ReadLine          285
%token    T_IntConstant       286
%token    T_DoubleConstant    287
%token    T_StringConstant    288
%token    T_Identifier        289
%token    T_BooleanConstant   290
%token    T_Lineend           291

%left '+' '-'
%left '*' '/'

%%
Program     :   DeclList                { printf("%15s -> %s \n", "Program", "DeclList"); } 
            |   error;
            ;

DeclList    :   DeclList Decl           { printf("%15s -> %s \n",  "DeclList", "DeclList Decl"); } 
            |   /* empty */             { printf("%15s -> %s \n",  "DeclList", " ");             }
            |   error;
            ;

Decl        :   VariableDecl            { printf("%15s -> %s \n",  "Decl", "VaruableDecl"); } 
            |   ClassDefn               { printf("%15s -> %s \n",  "Decl", "ClassDefn");    } 
            |   FunctionDefn            { printf("%15s -> %s \n",  "Decl", "FunctionDefn"); } 
            |   FunctionDecl            { printf("%15s -> %s \n",  "Decl", "FunctionDecl"); } 
            |   error;
            ;
            
VariableDecl:   Variable ';'            { printf("%15s -> %s \n",  "VariableDecl", "Variable ;"); } 
            |   error;
            ;

/* 变量定义 */
Variable    :   Type T_Identifier       { printf("%15s -> %s \n",  "Variable", "Type Identifier");   } 
            |   error;
            ;

/* 变量类型 */
Type        :   T_Int                   { printf("%15s -> %s \n",  "Type", "Int");       } 
            |   T_Double                { printf("%15s -> %s \n",  "Type", "Double");    } 
            |   T_Boolean               { printf("%15s -> %s \n",  "Type", "Bool");      } 
            |   T_String                { printf("%15s -> %s \n",  "Type", "String");    } 
            |   T_Void                  { printf("%15s -> %s \n",  "Type", "Void");      } 
            |   T_Class T_Identifier    { printf("%15s -> %s \n",  "Type", "Identifier");} 
            |   Type '[' ']'            { printf("%15s -> %s \n",  "Type", "Type[]");    } 
            |   error;
            ;

/* 函数定义 */            
FunctionDecl:   Type T_Identifier '(' Formals ')' ';'                
                                        { printf("%15s -> %s \n",  "FunctionDecl", "Identifier");} 
            ;

/* 函数参数列表 */
Formals     :   Variable  ','           { printf("%15s -> %s \n",  "Formals", "Variable+,"); } 
            |   /* empty */             { printf("%15s -> %s \n",  "Formals", " ");          } 
            |   error;
            ;

/* 函数体 */             
FunctionDefn:   Type T_Identifier '(' Formals ')' StmtBlock        
                                        { printf("%15s -> %s \n",  "FunctionDefn", "Identifier");} 
            ;

/* 类定义 */  
ClassDefn   :   T_Class T_Identifier '<' T_Extends T_Identifier '>' '{' Fieldlist '}'   
                                        { printf("Class Identifier < Extends Identifier > { Fieldlist } \n");} 
            ;

Fieldlist   :   Fieldlist Field         { printf("%15s -> %s \n",  "Fieldlist", "Fieldlist Field"); } 
            |   /* empty */             { printf("%15s -> %s \n",  "Fieldlist", " ");               }
            |   error;
            ;

Field       :   VariableDecl            { printf("%15s -> %s \n",  "Field", "VariableDecl");     } 
            |   FunctionDecl            { printf("%15s -> %s \n",  "Field", "FunctionDecl");     } 
            |   FunctionDefn            { printf("%15s -> %s \n",  "Field", "FunctionDefn");     } 
            ;

/* 语句块 */            
StmtBlock   :   '{' Stmtlist '}'        { printf("%15s -> %s \n",  "StmtBlock", ":{ Stmtlist } ");} 
            |   error;
            ;

Stmtlist    :   Stmtlist Stmt           { printf("%15s -> %s \n",  "Stmtlist", "Stmtlist Stmt"); } 
            |   /* empty */             { printf("%15s -> %s \n",  "Stmtlist", " ");             }
            ;

Stmt        :   VariableDecl            { printf("%15s -> %s \n",  "Stmt", "VariableDecl");     } 
            |   SimpleStmt ';'          { printf("%15s -> %s \n",  "Stmt", "SimpleStmt；");     } 
            |   IfStmt                  { printf("%15s -> %s \n",  "Stmt", "IfStmt");           } 
            |   WhileStmt               { printf("%15s -> %s \n",  "Stmt", "WhileStmt ");       } 
            |   ForStmt                 { printf("%15s -> %s \n",  "Stmt", "ForStmt ");         } 
            |   ReturnStmt ';'          { printf("%15s -> %s \n",  "Stmt", "ReturnStmt；");     } 
            |   PrintStmt ';'           { printf("%15s -> %s \n",  "Stmt", "PrintStmt ；");     } 
            |   StmtBlock               { printf("%15s -> %s \n",  "Stmt", "StmtBlock ");       }
            ;

/* 赋值语句 */
SimpleStmt  :   LValue '=' Expr         { printf("%15s -> %s \n",  "SimpleStmt", "LValue = Expr ");} 
            |   Expr                    { printf("%15s -> %s \n",  "SimpleStmt", "Expr ");         } 
            |   /* empty */             { printf("%15s -> %s \n",  "SimpleStmt", " ");             } 
            |   error;
            ;

/* 数组[] 和 <.> */            
LValue      :   '<' Expr '.' '>' T_Identifier   { printf("%15s -> %s \n",  "LValue", ":< Expr . > "); } 
            |   Expr '[' Expr ']'               { printf("%15s -> %s \n",  "LValue", "[ Expr ] ");    } 
            |   error;
            ;

/* 调用 */            
Call        :   '<'Expr '.' '>' T_Identifier '(' Actuals ')'                
                                        { printf("%15s -> %s \n", "Call", "<Expr .> T_Identifier ( Actuals ) ");} 
            ;

Actuals     :   Expr '+' ','            { printf("%15s -> %s \n",  "Actuals", "Expr +, "); } 
            |   /* empty */             { printf("%15s -> %s \n",  "Actuals", "");         } 
            |   error;
            ;
            
ForStmt     :   T_For '(' SimpleStmt ';' BoolExpr ';' SimpleStmt ')' Stmt   
                                        { printf("%15s -> %s \n",  "ForStmt", "For (SimpleStmt BoolExpr SimpleStmt ) Stmt ");} 
            ;

WhileStmt   :   T_While '(' BoolExpr ')' Stmt
                                        { printf("%15s -> %s \n",  "WhileStmt", "While ( BoolExpr ) Stmt ");} 
            ;

IfStmt      :   T_If '(' BoolExpr ')' Stmt '<' T_Else Stmt '>'
                                        { printf("%15s -> %s \n",  "IfStmt", "If (BoolExpr ) Stmt <Else Stmt > ");}
            ;

ReturnStmt  :   T_Return                { printf("%15s -> %s \n",  "ReturnStmt", "Return");       } 
            |   T_Return Expr           { printf("%15s -> %s \n",  "ReturnStmt", "Return Expr "); } 
            ;
            
PrintStmt   :   T_Print '(' Expr '+' ',' ')'    { printf("%15s -> %s \n",  "PrintStmt", "Print (Expr+ ,) ");} 
            ;

BoolExpr    :   Expr                        { printf("%15s -> %s \n",  "BoolExpr", "Expr");          } 
            ;

Expr        :   Constant                    { printf("%15s -> %s \n",  "Expr", "Constant");          } 
            |   LValue                      { printf("%15s -> %s \n",  "Expr", "LValue");            } 
            |   T_This                      { printf("%15s -> %s \n",  "Expr", "This");              } 
            |   Call                        { printf("%15s -> %s \n",  "Expr", "Call");              } 
            |   '(' Expr')'                 { printf("%15s -> %s \n",  "Expr", "( Expr) ");          } 
            |   Expr '+' Expr               { printf("%15s -> %s \n",  "Expr", "Expr + Expr ");      } 
            |   Expr '-' Expr               { printf("%15s -> %s \n",  "Expr", "Expr - Expr ");      } 
            |   Expr '*' Expr               { printf("%15s -> %s \n",  "Expr", "Expr * Expr ");      } 
            |   Expr '/' Expr               { printf("%15s -> %s \n",  "Expr", "Expr /Expr ");       } 
            |   Expr '%' Expr               { printf("%15s -> %s \n",  "Expr", "Expr % Expr ");      } 
            |   '-' Expr                    { printf("%15s -> %s \n",  "Expr", "- Expr ");           } 
            |   Expr '<' Expr               { printf("%15s -> %s \n",  "Expr", "Expr < Expr ");      } 
            |   Expr T_Le Expr              { printf("%15s -> %s \n",  "Expr", "LessEqual Expr ");   } 
            |   Expr '>' Expr               { printf("%15s -> %s \n",  "Expr", "Expr >Expr ");       } 
            |   Expr T_Ge Expr              { printf("%15s -> %s \n",  "Expr", "GreaterEqual");      } 
            |   Expr T_Eq Expr              { printf("%15s -> %s \n",  "Expr", "Equal Expr ");       } 
            |   Expr T_Ne Expr              { printf("%15s -> %s \n",  "Expr", "NotEqual Expr ");    } 
            |   Expr T_And Expr             { printf("%15s -> %s \n",  "Expr", "And Expr ");         } 
            |   Expr T_Or Expr              { printf("%15s -> %s \n",  "Expr", "Or Expr ");          } 
            |   '!' Expr                    { printf("%15s -> %s \n",  "Expr", "! Expr ");           } 
            |   T_ReadInteger '(' ')'       { printf("%15s -> %s \n",  "Expr", "Expr ReadInteger ( ) "); } 
            |   T_ReadLine '(' ')'          { printf("%15s -> %s \n",  "Expr", "Expr ReadLine ( ) ");    } 
            |   T_New '(' T_Identifier ')'  { printf("%15s -> %s \n",  "Expr", "New ( Identifier ) ");   }
            |   T_NewArray '(' Expr ',' Type ')' { printf("%15s -> %s \n",  "Expr", "NewArray ( Expr , Type )");} 
            ;

/* 常量 */            
Constant    :   T_IntConstant               { printf("%15s -> %s \n",  "Constant", "IntConstant");       } 
            |   T_DoubleConstant            { printf("%15s -> %s \n",  "Constant", "DoubleConstant");    } 
            |   T_BooleanConstant           { printf("%15s -> %s \n",  "Constant", "BoolConstant");      }  
            |   T_StringConstant            { printf("%15s -> %s \n",  "Constant", "StringConstant");    } 
            |   T_Null                      { printf("%15s -> %s \n",  "Constant", "Null");             }
            ;

%%

int main() {
    return yyparse();
}
