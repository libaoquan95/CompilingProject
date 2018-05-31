%{
#include <stdio.h>
void yyerror(const char* msg) {printf("error: %s\n", msg);}
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

%left '+' '-'
%left '*' '/'

%%
Program     :   DeclList                { printf("Program -> DeclList\n"); @1 } ;

DeclList    :   DeclList Decl           { printf("DeclList -> DeclList Decl\n"); } 
            |   /* empty */             { printf("DeclList ->\n"); }
            ;

Decl        :   VariableDecl            { printf("Decl -> VaruableDecl\n"); } 
            |   ClassDefn               { printf("Decl -> ClassDefn\n");} 
            |   FunctionDefn            { printf("Decl -> FunctionDefn\n"); } 
            |   FunctionDecl            { printf("Decl -> FunctionDecl\n"); } 
            ;
            
VariableDecl:   Variable ';'            { printf("VariableDecl -> Variable\n"); } ;

/* 变量定义 */
Variable    :   Type T_Identifier       { printf("Variable -> Identifier\n"); } ;

/* 变量类型 */
Type        :   T_Int                   { printf("Type -> Int\n"); } 
            |   T_Double                { printf("Type -> Double\n");} 
            |   T_Boolean               { printf("Type -> Bool\n");} 
            |   T_String                { printf("Type -> String\n");} 
            |   T_Void                  { printf("Type ->Void\n");} 
            |   T_Class T_Identifier    { printf("Type ->Identifier\n");} 
            |   Type '[' ']'            { printf("Type -> Type[]\n");} 
            ;

/* 函数定义 */            
FunctionDecl:   Type T_Identifier '(' Formals ')' ';'           { printf("FunctionDecl ->Identifier\n");} ;

/* 函数参数列表 */
Formals     :   Variable '+' ','        { printf("Formals -> Variable+,\n"); } 
            |   /* empty */             { printf("Formals -> \n");} 
            ;

/* 函数体 */             
FunctionDefn:   Type T_Identifier '(' Formals ')' StmtBlock     { printf("FunctionDefn -> Identifier\n");} ;

/* 类定义 */  
ClassDefn   :   T_Class T_Identifier '<' T_Extends T_Identifier '>' '{' Fieldlist '}' { printf("Class Identifier < Extends Identifier > { Fieldlist } \n");} ;

Fieldlist   :   Fieldlist Field         { printf(" Fieldlist -> Fieldlist Field\n");} 
            |   /* empty */             { printf(" Fieldlist -> \n");}
            ;

Field       :   VariableDecl            { printf("Field -> VariableDecl\n");} 
            |   FunctionDecl            { printf("Field -> FunctionDecl\n ");} 
            |   FunctionDefn            { printf("Field -> FunctionDefn\n ");} 
            ;

/* 语句块 */            
StmtBlock   :   '{' Stmtlist '}'        { printf("StmtBlock ->:{ Stmtlist } \n");} ;

Stmtlist    :   Stmtlist Stmt           { printf("Stmtlist -> Stmtlist Stmt\n ");} ;

Stmt        :   VariableDecl            { printf(" Stmt -> VariableDecl\n ");} 
            |   SimpleStmt ';'          { printf(" Stmt ->SimpleStmt；\n ");} 
            |   IfStmt                  { printf(" Stmt ->IfStmt\n ");} 
            |   WhileStmt               { printf(" Stmt -> WhileStmt \n ");} 
            |   ForStmt                 { printf(" Stmt -> ForStmt \n ");} 
            |   ReturnStmt ';'          { printf(" Stmt ->ReturnStmt；\n ");} 
            |   PrintStmt ';'           { printf(" Stmt -> PrintStmt ；\n ");} 
            |   StmtBlock               { printf(" Stmt -> StmtBlock \n ");}
            ;

SimpleStmt  :   LValue '=' Expr { printf(" SimpleStmt ->LValue = Expr \n");} 
            |   Expr { printf(" SimpleStmt -> Expr \n");} 
            |   { printf(" SimpleStmt -> \n");} 
            ;
            
LValue      :   '<' Expr '.' '>' T_Identifier   { printf(" LValue -> :< Expr . > \n");} 
            |    Expr '[' Expr ']'              { printf(" LValue -> [ Expr ] \n");} 
            ;
            
Call        :   '<'Expr '.' '>' T_Identifier '(' Actuals ')' { printf(" Call -><Expr .> T_Identifier ( Actuals ) \n");} ;

Actuals     :   Expr '+' ','    { printf(" Actuals -> Expr +, \n");} 
            |   /* empty */     { printf(" Actuals -> \n");} 
            ;
            
ForStmt     :   T_For '(' SimpleStmt ';' BoolExpr ';' SimpleStmt ')' Stmt { printf(" ForStmt ->For (SimpleStmt BoolExpr SimpleStmt ) Stmt \n");} ;

WhileStmt   :   T_While '(' BoolExpr ')' Stmt       { printf("WhileStmt->While ( BoolExpr ) Stmt \n");} ;

IfStmt      :   T_If '(' BoolExpr ')' Stmt '<' T_Else Stmt '>' { printf("IfStmt->If (BoolExpr ) Stmt <Else Stmt > \n");} ;

ReturnStmt  :   T_Return        { printf(" ReturnStmt ->Return\n");} 
            |   T_Return Expr   { printf(" ReturnStmt ->Return Expr \n");} 
            ;
            
PrintStmt   :   T_Print '(' Expr '+' ',' ')'    { printf("PrintStmt->Print (Expr+ ,) \n");} ;

BoolExpr    :   Expr             { printf("BoolExpr ->Expr\n");} ;

Expr        :   Constant        { printf("Expr ->Constant\n");} 
            |   LValue          { printf("Expr ->LValue\n");} 
            |   T_This          { printf("Expr ->This\n");} 
            |   Call            { printf("Expr ->Call\n");} 
            |   '(' Expr')'     { printf("Expr ->( Expr) \n");} 
            |   Expr '+' Expr   { printf("Expr ->Expr + Expr \n");} 
            |   Expr '-' Expr   { printf("Expr ->Expr - Expr \n");} 
            |   Expr '*' Expr   { printf("Expr ->Expr * Expr \n");} 
            |   Expr '/' Expr   { printf("Expr ->Expr /Expr \n");} 
            |   Expr '%' Expr   { printf("Expr ->Expr % Expr \n");} 
            |   '-' Expr        { printf("Expr -> - Expr \n");} 
            |   Expr '<' Expr   { printf("Expr ->Expr < Expr \n");} 
            |   Expr T_Le Expr       { printf("Expr ->LessEqual Expr \n");} 
            |   Expr '>' Expr               { printf("Expr ->Expr >Expr \n");} 
            |   Expr T_Ge Expr    { printf("Expr ->GreaterEqual\n");} 
            |   Expr T_Eq Expr           { printf("Expr ->Equal Expr \n");} 
            |   Expr T_Ne Expr        { printf("Expr ->NotEqual Expr \n");} 
            |   Expr T_And Expr             { printf("Expr ->And Expr \n");} 
            |   Expr T_Or Expr              { printf("Expr ->Or Expr \n");} 
            |   '!' Expr                    { printf("Expr ->! Expr \n");} 
            |   T_ReadInteger '(' ')'       { printf("Expr ->Expr ReadInteger ( ) \n");} 
            |   T_ReadLine '(' ')'          { printf("Expr ->Expr ReadLine ( ) \n");} 
            |   T_New '(' T_Identifier ')'  { printf("Expr ->New ( Identifier ) \n");}
            |   T_NewArray '(' Expr ',' Type ')' { printf("Expr ->NewArray ( Expr , Type )\n");} 
            ;
            
Constant    :   T_IntConstant       { printf("Constant ->IntConstant\n");} 
            |   T_DoubleConstant    { printf("Constant ->DoubleConstant\n");} 
            |   T_BooleanConstant      { printf("Constant ->BoolConstant\n");} 
            |   T_StringConstant    { printf("Constant ->StringConstant\n");} 
            |   T_Null              { printf("Constant -> Null\n");}
            ;

%%

int main() {
    return yyparse();
}
