%{
#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 
#include <iostream>
#include <list>
#include "ast.h"

extern char *yytext;
extern int yylineno;

int yylex();
void yyerror(const char* msg) {
	printf("\nError: (line: %d) %s encountered at %s\n", yylineno, msg, yytext);
}

EntityTable *global_symtab = new EntityTable();
list<Entity*>* toplevel = new list<Entity*>();
ClassEntity* objectclass = new ClassEntity("Object", (ClassEntity*)NULL, new list<Entity*>());
%}

%start Program

/*bison可以从这个定义中产生yylval的定义*/ 
%union {
    int      ival;
    char     *sval;
    double   dval;
    bool     bval;

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
}

%token    T_Le                
%token    T_Ge                
%token    T_Eq                
%token    T_Ne                
%token    T_And               
%token    T_Or                
%token    T_Void              
%token    T_Int               
%token    T_Double            
%token    T_Boolean           
%token    T_String            
%token    T_Class             
%token    T_Interface         
%token    T_Null              
%token    T_This              
%token    T_Extends           
%token    T_Implements        
%token    T_For               
%token    T_While             
%token    T_If                
%token    T_Else              
%token    T_Return            
%token    T_Break             
%token    T_New               
%token    T_NewArray          
%token    T_Print             
%token    T_ReadInteger       
%token    T_ReadLine          
%token    <ival>   T_IntConstant       
%token    <dval>   T_DoubleConstant    
%token    <sval>   T_StringConstant    
%token    <sval>   T_Identifier        
%token    <bval>   T_BooleanConstant

%left ')' ']'
%left ','
%left '='
%left T_OR
%left T_AND
%nonassoc T_Eq T_Ne
%nonassoc '<' '>' T_LET T_HET
%left '+' '-'
%left '*' '/' '%'
%right '!'
%left '.' '(' '['
%nonassoc T_ELSE
%nonassoc T_IFX


%type <entityList>     Program 
%type <variableEntity> VariableDecl
%type <variableEntity> Variable
%type <typeVal>        Type
%type <entityList>     Formals
%type <entityList>     VariableMore
%type <functionEntity> FunctionDefn
%type <classEntity>    ClassDefn
%type <classEntity>    ExtendsQ
%type <entityList>     Fieldlist
%type <entity>         Field
%type <statement>      StmtBlock
%type <stmtList>       Stmtlist
%type <statement>      Stmt
%type <statement>      SimpleStmt
%type <expression>     LValue
%type <expression>     Call
%type <exprList>       Actuals
%type <exprList>       ExprMore
%type <statement>      ForStmt
%type <statement>      WhileStmt
%type <statement>      IfStmt
%type <statement>      ReturnStmt
%type <statement>      BreakStmt
%type <statement>      PrintStmt
%type <expression>     BoolExpr
%type <expression>     Expr
%type <expression>     Constant

%%
Program     :   ClassDefn               {
                                            $$ = toplevel;
				                            $$->push_back($1);
                                            printf("%15s -> %s \n", "Program", "ClassDefn");
                                        } 
            |   Program ClassDefn       {
                                            $$ = $1;
				                            $$->push_back($2);
                                            printf("%15s -> %s \n", "Program", "Program ClassDefn");
                                        }
            |   error                   {
                                            yyerror("Program");
                                        }
            ; 

VariableDecl:   Variable ';'            {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "VariableDecl", "Variable ;");
                                        } 
            |   error                   {
                                            yyerror("VariableDecl");
                                        }
            ;

/* 变量定义 */
Variable    :   Type T_Identifier       {
                                            bool current;
                                            //printf("before into find_entity\n");
                                            Entity* entity = global_symtab->find_entity($2, VARIABLE_ENTITY, &current);
                                            //printf("after  into find_entity\n");
                                            VariableEntity* variable = dynamic_cast<VariableEntity*>(entity);
                                            if (variable && current) {
                                                yyerror("Redefinition of variable name");
                                                printf("Redefined variable name: %s\n", $2);
                                            }
                                            $$ = new VariableEntity($2, $1);
                                            printf("%15s -> %-15s |",  "Variable", "Type Identifier");  
                                            printf("%15s -> %s %s \n",  "Variable", "Type", $2);  
                                        } 
            |   error                   {
                                            yyerror("Variable");
                                        }
            ;

/* 变量类型 */
Type        :   T_Int                   {
                                            $$ = new IntType();
                                            printf("%15s -> %s \n",  "Type", "Int");
                                        } 
            |   T_Double                {
                                            $$ = new DoubleType();
                                            printf("%15s -> %s \n",  "Type", "Double");
                                        } 
            |   T_Boolean               {
                                            $$ = new BooleanType();
                                            printf("%15s -> %s \n",  "Type", "Bool");
                                        } 
            |   T_String                {
                                            $$ = new StringType();
                                            printf("%15s -> %s \n",  "Type", "String");
                                        } 
            |   T_Void                  {
                                            $$ = new VoidType();
                                            printf("%15s -> %s \n",  "Type", "Void");
                                        } 
            |   T_Class T_Identifier    {
                                            bool current;
                                            Entity* entity = global_symtab->find_entity($2, CLASS_ENTITY, &current);
                                            ClassEntity* classEntity = dynamic_cast<ClassEntity*>(entity);
                                            if (!classEntity) {
                                                yyerror("Undefined class");
                                                printf("Undefined class name: %s\n", $2);
                                                $$ = new ErrorType();
                                            } else {
                                                $$ = new InstanceType(classEntity);
                                            }
                                            /*$$ = new ClassType($2);*/
                                            printf("%15s -> %-15s |","Type", "Identifier");  
                                            printf("%15s -> %s %s\n", "Type", "calss", $2);
                                        } 
            |   Type '[' ']'            {
                                            $$ = new ArrayType($1);
                                            printf("%15s -> %s \n",  "Type", "Type[]");
                                        } 
            |   error                   {
                                            yyerror("Type");
                                        }
            ;

/* 函数参数列表 */
Formals     :   VariableMore            {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Formals", "VariableMore,");
                                        } 
            |   /* empty */             {
                                            $$ = new list<Entity*>();
                                            printf("%15s -> %s \n",  "Formals", " ");
                                        } 
            ;

VariableMore:   Variable                { 
                                            $$ = new list<Entity*>();
				                            $$->push_back($1);
                                            printf("%15s -> %s \n",  "VariableMore", "Variable");
                                        } 
            |   VariableMore ',' Variable
                                        { 
                                            $$ = $1;
                                            $$->push_back($3);
                                            printf("%15s -> %s \n",  "Formals", "VariableMore , Variable");
                                        } 
            ;

/* 函数定义 */            
FunctionDecl:   Type T_Identifier '(' Formals ')' ';'    
                                        { 
                                            printf("%15s -> %-15s |",  "FunctionDecl", "Identifier(Formals)"); 
                                            printf("%15s -> %s \n",    "FunctionDecl", $2);           
                                        } 
            ;

/* 函数体 */
/*             
FunctionDefn:   Type T_Identifier       {
                                            $<functionEntity>$ = new FunctionEntity($2, $1, nullptr, nullptr);
					                        global_symtab->enter_block();
                                        }
                '(' Formals ')' StmtBlock 
                                        {
                                            $$ = $<functionEntity>3;
                                            $$->formal_params = $5;
                                            $$->function_body = $7;
                                            global_symtab->leave_block();
                                            //$$ = new FunctionEntity($2, $1, $4, $6);
                                            printf("%15s -> %-15s \n",  "FunctionDefn", "Identifier(Formals) StmtBlock");
                                        } 
            ; 
*/
FunctionDefn:   Type T_Identifier '(' Formals ')' StmtBlock 
                                        {
                                            printf("%15s -> %-15s \n",  "FunctionDefn", "Identifier(Formals) StmtBlock");
                                        }
            ; 
            
/* 类定义 */  
ClassDefn   :   T_Class T_Identifier    {
                                            bool current;
                                            Entity* entity = global_symtab->find_entity($2, CLASS_ENTITY, &current);
                                            ClassEntity* classEntity = dynamic_cast<ClassEntity*>(entity);
                                            if (classEntity){
                                                yyerror("Redefinition of class"); 
                                                printf("Redefined class name: %s\n", $2);
                                            }
                                            $<classEntity>$ = new ClassEntity($2, nullptr, nullptr);
                                            global_symtab->enter_block();
                                        }
                ExtendsQ '{' Fieldlist '}'   
                                        {
                                            $$ = $<classEntity>3;
                                            $$->superclass = $4;
                                            $$->class_members = $6;
                                            global_symtab->leave_block();
                                            /*$$ = new ClassEntity($2, $3, $5);*/
                                           printf("Class Identifier ExtendsQ { Fieldlist } \n");
                                        } 
            ;

ExtendsQ    :   T_Extends T_Identifier  {
                                            bool current;
                                            Entity* entity = global_symtab->find_entity($2, CLASS_ENTITY, &current);
                                            ClassEntity* superclass = dynamic_cast<ClassEntity*>(entity);
                                            if (!superclass){
                                                yyerror("Undeclared superclass");
                                                printf("Undeclared superclass name: %s\n", $2);
                                            }
                                            $$ = superclass;
                                            printf("%15s -> %s \n",  "ExtendsQ", "T_Extends T_Identifier");
                                        } 
            |   /* empty */             {
                                            $$ = objectclass;
                                            printf("%15s -> %s \n",  "ExtendsQ", " ");
                                        } 
            ;

Fieldlist   :   Fieldlist Field         {
                                            $$ = $1;
				                            $$->push_back($2);
                                            printf("%15s -> %s \n",  "Fieldlist", "Fieldlist Field");
                                        } 
            |   /* empty */             {
                                            $$ = new list<Entity*>();
                                            printf("%15s -> %s \n",  "Fieldlist", " ");
                                        }
            |   error                   {
                                            yyerror("Fieldlist");
                                        }
            ;

Field       :   VariableDecl            {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Field", "VariableDecl");
                                        } 
            |   FunctionDecl            {
                                            printf("%15s -> %s \n",  "Field", "FunctionDecl");
                                        } 
            |   FunctionDefn            {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Field", "FunctionDefn");
                                        } 
            ;

/* 语句块 */            
StmtBlock   :   /* entry block */       {
                                            global_symtab->enter_block();
                                        }
                '{' Stmtlist '}'        {
                                            $$ = new BlockStatement($3);
                                            $$->level_number = global_symtab->level;
                                            global_symtab->leave_block();
                                            printf("%15s -> %s \n",  "StmtBlock", ":{ Stmtlist } ");
                                        } 
            |   error                   {
                                            yyerror("StmtBlock");
                                        }
            ;

Stmtlist    :   Stmtlist Stmt           {
                                            $$ = $1;
                                            $$->push_back($2);
                                            printf("%15s -> %s \n",  "Stmtlist", "Stmtlist Stmt");
                                        } 
            |   /* empty */             {
                                            $$ = new list<Statement*>();
                                            printf("%15s -> %s \n",  "Stmtlist", " ");
                                        }
            ; 

Stmt        :   VariableDecl            {
                                            $$ = new DeclStatement($1);
				                            $$->level_number = global_symtab->level;
                                            printf("%15s -> %s \n",  "Stmt", "VariableDecl");
                                        } 
            |   SimpleStmt ';'          {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Stmt", "SimpleStmt ;");
                                        } 
            |   IfStmt                  {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Stmt", "IfStmt");
                                        } 
            |   WhileStmt               {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Stmt", "WhileStmt ");
                                        } 
            |   ForStmt                 {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Stmt", "ForStmt ");
                                        } 
            |   BreakStmt ';'           {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Stmt", "BreakStmt ;");
                                        } 
            |   ReturnStmt ';'          {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Stmt", "ReturnStmt ;");
                                        } 
            |   PrintStmt ';'           {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Stmt", "PrintStmt ;");
                                        } 
            |   StmtBlock               {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Stmt", "StmtBlock ");
                                        }
            ;

/* 语句 */
SimpleStmt  :   LValue '=' Expr         {
                                            $$ = new AssignStatement($1, $3);
                                            printf("%15s -> %s \n",  "SimpleStmt", "LValue = Expr ");
                                        } 
            |   Call                    {
                                            $$ = new CallStatement($1);
                                            printf("%15s -> %s \n",  "SimpleStmt", "Call ");
                                        } 
            |   /* empty */             {
                                            $$ = new NullStatement();
                                            printf("%15s -> %s \n",  "SimpleStmt", " ");
                                        } 
            |   error                   {
                                            yyerror("SimpleStmt");
                                        }
            ;

/* 左值 */            
LValue      :   Expr '.' T_Identifier   {
                                            $$ = new MemberAccess($1, $3);
                                            printf("%15s -> %s \n",  "LValue", "Expr . T_Identifier");
                                        } 
            |   T_Identifier            {
                                            bool current;
                                            Entity* entity = global_symtab->find_entity($1, VARIABLE_ENTITY, &current);
                                            if (entity && current){
                                                // local variable
                                                VariableEntity* local = dynamic_cast<VariableEntity*>(entity);
                                                $$ = new IdExpression(local);
                                            } 
                                            else if (entity = global_symtab->find_entity($1, CLASS_ENTITY, &current)){
                                                // class variable
                                                ClassEntity* classEntity = dynamic_cast<ClassEntity*>(entity);
                                                $$ = new IdExpression(classEntity);
                                            } 
                                            else if (entity = global_symtab->find_entity($1, VARIABLE_ENTITY, &current)){
                                                // outter variable
                                                VariableEntity* variable = dynamic_cast<VariableEntity*>(entity);
                                                $$ = new IdExpression(variable);
                                            } 
                                            else {
                                                yyerror("Undefined variable");
                                                printf("Undefined variable name: %s\n", $1);
                                                $$ = new MemberAccess(new ThisExpression(), $1);
                                            }
                                            printf("%15s -> %s \n",  "LValue", "T_Identifier");
                                        }
            |   Expr '[' Expr ']'       {
                                            $$ = new ArrayAccess($1, $3);
                                            printf("%15s -> %s \n",  "LValue", "Expr [ Expr ] ");
                                        } 
            |   error                   { 
                                            yyerror("LValue");
                                        }
            ;

/* 调用 */            
Call        :   Expr '.' T_Identifier '(' Actuals ')'                
                                        {
                                            $$ = new FunctionInvocation($1, $3, $5);
                                            printf("%15s -> %s \n", "Call", "Expr . T_Identifier ( Actuals ) ");
                                        } 
            |   T_Identifier '(' Actuals ')'
                                        {
                                            $$ = new FunctionInvocation(new NullExpression(), $1, $3);
                                            printf("%15s -> %s \n", "Call", "T_Identifier ( Actuals ) ");
                                        } 
            ;

Actuals     :   ExprMore                {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Actuals", "ExprMore");
                                        } 
            |   /* empty */             {
                                            $$ = new list<Expression*>();
                                            printf("%15s -> %s \n",  "Actuals", "");
                                        } 
            ;

ExprMore    :   Expr                    { 
                                            $$ = new list<Expression*>();
                                            printf("%15s -> %s \n",  "ExprMore", "Expr");
                                        } 
            |   ExprMore ',' Expr       {
                                            $$ = $1;
                                            $$->push_back($3);
                                            printf("%15s -> %s \n",  "ExprMore", "ExprMore , Expr");
                                        } 
            ;

ForStmt     :   T_For '(' SimpleStmt ';' BoolExpr ';' SimpleStmt ')' Stmt   
                                        {
                                            $$ = new ForStatement($3, $5, $7, $9);
				                            $$->level_number = global_symtab->level;
                                            printf("%15s -> %s \n",  "ForStmt", "For (SimpleStmt BoolExpr SimpleStmt ) Stmt ");
                                        } 
            ;

WhileStmt   :   T_While '(' BoolExpr ')' Stmt
                                        {
                                            $$ = new WhileStatement($3, $5);
				                            $$->level_number = global_symtab->level;
                                            printf("%15s -> %s \n",  "WhileStmt", "While ( BoolExpr ) Stmt ");
                                        } 
            ;

IfStmt      :   T_If '(' BoolExpr ')' Stmt %prec T_IFX
                                        {
                                            $$ = new IfStatement($3, $5, new NullStatement());
                                            $$->level_number = global_symtab->level;
                                            printf("%15s -> %s \n",  "IfStmt", "If (BoolExpr ) Stmt %prec T_IFX ");
                                        }
            |   T_If '(' BoolExpr ')' Stmt T_Else Stmt
                                        {
                                            $$ = new IfStatement($3, $5, $7);
                                            $$->level_number = global_symtab->level;
                                            printf("%15s -> %s \n",  "IfStmt", "If (BoolExpr ) Stmt T_Else Stmt ");
                                        }
            ;

ReturnStmt  :   T_Return                {
                                            $$ = new ReturnStatement(new NullExpression());
				                            $$->level_number = global_symtab->level;
                                            printf("%15s -> %s \n",  "ReturnStmt", "Return");
                                        } 
            |   T_Return Expr           {
                                            $$ = new ReturnStatement($2);
				                            $$->level_number = global_symtab->level;
                                            printf("%15s -> %s \n",  "ReturnStmt", "Return Expr ");
                                        } 
            ;
            
BreakStmt   :   T_Break                 {
                                            $$ = new BreakStatement();
				                            $$->level_number = global_symtab->level;
                                            printf("%15s -> %s \n",  "BreakStmt", "Break");
                                        }  
            ;

PrintStmt   :   T_Print '(' ExprMore ')'{
                                            $$ = new PrintStatement($3);
                                            $$->level_number = global_symtab->level;
                                            printf("%15s -> %s \n",  "PrintStmt", "Print (ExprMore) ");
                                        } 
            ;

BoolExpr    :   Expr                    { 
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "BoolExpr", "Expr");
                                        } 
            ;

Expr        :   Constant                { 
                                            $$  =$1;
                                            printf("%15s -> %s \n",  "Expr", "Constant");
                                        } 
            |   LValue                  { 
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Expr", "LValue");
                                        } 
            |   T_This                  {
                                            $$ = new ThisExpression();
                                            printf("%15s -> %s \n",  "Expr", "This");
                                        } 
            |   Call                    {
                                            $$ = $1;
                                            printf("%15s -> %s \n",  "Expr", "Call");
                                        } 
            |   '(' Expr')'             { 
                                            $$ = $2;
                                            printf("%15s -> %s \n",  "Expr", "( Expr) ");
                                        } 
            |   Expr '+' Expr           { 
                                            $$ = new BinaryExpression(ADD, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "Expr + Expr ");
                                        } 
            |   Expr '-' Expr           { 
                                            $$ = new BinaryExpression(SUB, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "Expr - Expr ");
                                        } 
            |   Expr '*' Expr           { 
                                            $$ = new BinaryExpression(MUL, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "Expr * Expr ");
                                        } 
            |   Expr '/' Expr           { 
                                            $$ = new BinaryExpression(DIV, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "Expr /Expr ");
                                        } 
            |   Expr '%' Expr           { 
                                            $$ = new BinaryExpression(MOD, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "Expr % Expr ");
                                        } 
            |   '-' Expr                { 
                                            $$ = new UnaryExpression(UMINUS, $2);
                                            printf("%15s -> %s \n",  "Expr", "- Expr ");
                                        } 
            |   Expr '<' Expr           { 
                                            $$ = new BinaryExpression(LT, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "Expr < Expr ");
                                        } 
            |   Expr T_Le Expr          { 
                                            $$ = new BinaryExpression(LE, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "LessEqual Expr ");
                                        } 
            |   Expr '>' Expr           {
                                            $$ = new BinaryExpression(GT, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "Expr >Expr ");
                                        } 
            |   Expr T_Ge Expr          {
                                            $$ = new BinaryExpression(GE, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "GreaterEqual");
                                        } 
            |   Expr T_Eq Expr          {
                                            $$ = new BinaryExpression(EQ, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "Equal Expr ");
                                        } 
            |   Expr T_Ne Expr          { 
                                            $$ = new BinaryExpression(NEQ, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "NotEqual Expr ");
                                        } 
            |   Expr T_And Expr         {
                                            $$ = new BinaryExpression(AND, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "And Expr ");
                                        } 
            |   Expr T_Or Expr          {
                                            $$ = new BinaryExpression(OR, $1, $3);
                                            printf("%15s -> %s \n",  "Expr", "Or Expr ");
                                        } 
            |   '!' Expr                {
                                            $$ = new UnaryExpression(NOT, $2);
                                            printf("%15s -> %s \n",  "Expr", "! Expr ");
                                        } 
            |   T_ReadInteger '(' ')'   {
                                            $$ = new ReadIntegerExpression();
                                            printf("%15s -> %s \n",  "Expr", "Expr ReadInteger ( ) ");
                                        } 
            |   T_ReadLine '(' ')'      {
                                            $$ = new ReadLineExpression();
                                            printf("%15s -> %s \n",  "Expr", "Expr ReadLine ( ) ");
                                        } 
            |   T_New T_Identifier '(' ')'  
                                        { 
                                            bool current;
                                            Entity* entity = global_symtab->find_entity($2, CLASS_ENTITY, &current);
                                            ClassEntity* classEntity = dynamic_cast<ClassEntity *>(entity);
                                            if (!classEntity){
                                                yyerror("Undeclared class");
                                                printf("  Undeclared class name: %s\n", $2);
                                            }
                                            $$ = new NewInstance($2, classEntity);
                                            printf("%15s -> %s \n",  "Expr", "New Identifier ( ) ");
                                        }
            |   T_NewArray '(' Expr ',' Type ')' 
                                        { printf("%15s -> %s \n",  "Expr", "NewArray ( Expr , Type )");}
            ;

/* 常量 */            
Constant    :   T_IntConstant           { 
                                            $$ = new IntegerConstant($1);
                                            printf("%15s -> %-15s |",  "Constant", "IntConstant");   
                                            printf("%15s -> %d \n",    "Constant", $1);
                                        } 
            |   T_DoubleConstant        {      
                                            $$ = new DoubleConstant($1);    
                                            printf("%15s -> %-15s |",  "Constant", "DoubleConstant");
                                            printf("%15s -> %f \n",    "Constant", $1); 
                                        } 
            |   T_BooleanConstant       { 
                                            $$ = new BooleanConstant($1);   
                                            printf("%15s -> %-15s |",  "Constant", "BoolConstant"); 
                                            printf("%15s -> %d \n",    "Constant", $1);
                                        }  
            |   T_StringConstant        { 
                                            $$ = new StringConstant($1);
                                            printf("%15s -> %-15s |",  "Constant", "StringConstant"); 
                                            printf("%15s -> %s \n",    "Constant", $1);
                                        } 
            |   T_Null                  { 
                                            $$ = new NullConstant();
                                            printf("%15s -> %s\n",   "Constant", "Null");
                                        }
            ;

%%

int main() {
    return yyparse();
}

