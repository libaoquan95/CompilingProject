#ifndef AST_H
#define AST_H

#include <list>
#include "ast_symbols.h"

using namespace std;
using namespace __gnu_cxx;

typedef enum {
	ADD, SUB, MUL, DIV, MOD, EQ, NEQ, LT, LE, GT, GE, AND, OR
} BinaryOperator;

typedef enum {
	NOT, UMINUS
} UnaryOperator;

typedef enum {
	INT_TYPE, DOUBLE_TYPE, BOOL_TYPE, STRING_TYPE, VOID_TYPE,
	INSTANCE_TYPE, CLASS_TYPE, ARRAY_TYPE, ERROR_TYPE,
	UNIVERSE_TYPE, NULL_TYPE
} TypeKind;

class Statement {
public:
	Statement() {}
	virtual ~Statement() {}
	virtual void print() = 0;
	//virtual void typecheck()() = 0;
	int level_number;
	int lineno;
};

class Expression {
public:
	Expression() {};
	virtual ~Expression() {};
	virtual void print() = 0;
	//virtual Type* typeinfer() = 0;

	int lineno;
};

class Type {
public:
	Type() {};
	virtual ~Type() {};

	virtual void print() = 0;
	//virtual bool isSubtypeOf(Type *t);

	int dimension;
	TypeKind kind;
};

/*
* Type classes
*/
class IntType : public Type {
public:
	IntType();
	virtual ~IntType();
	void print();
};
class DoubleType : public Type {
	public:
		DoubleType();
		virtual ~DoubleType();
		void print();
};
class BooleanType : public Type {
	public:
		BooleanType();
		virtual ~BooleanType();
		void print();
};
class StringType : public Type {
	public:
		StringType();
		virtual ~StringType();
		void print();
};
class VoidType : public Type {
	public:
		VoidType();
		virtual ~VoidType();
		void print();
};
class ClassType : public Type {
	public:
		ClassType(ClassEntity* _classtype);
		virtual ~ClassType();
		void print();
		ClassEntity *classtype;
};
class InstanceType : public Type {
	public:
		InstanceType(ClassEntity* _classtype);
		virtual ~InstanceType();
		void print();
		ClassEntity* classtype;
};
class ErrorType : public Type {
	public:
		ErrorType();
		virtual ~ErrorType();
		void print();
};
class ArrayType : public Type {
	public:
		ArrayType(Type* _elementtype);
		virtual ~ArrayType();
		void print();
		Type* elementtype;
};

// UniverseType is the top-most in type hierarchy;
// every type is in UniverseType
class UniverseType : public Type {
public:
	UniverseType();
	virtual ~UniverseType();
	void print();
};

// NullType is a bottom in type hierarchy;
// it is in every class type
class NullType : public Type {
public:
	NullType();
	virtual ~NullType();
	void print();
};

/*
* Expression classes
*/
class BinaryExpression : public Expression {
public:
	BinaryExpression(BinaryOperator _binary_operator, Expression* _lhs, Expression* _rhs);
	virtual ~BinaryExpression();
	void print();
	//virtual Type* typeinfer();
	BinaryOperator binary_operator;
	Expression* lhs;
	Expression* rhs;
};

class UnaryExpression : public Expression {
public:
	UnaryExpression(UnaryOperator _unary_operator, Expression* _arg);
	virtual ~UnaryExpression();
	void print();
	//virtual Type* typeinfer();
	UnaryOperator unary_operator;
	Expression* arg;
};

class ThisExpression : public Expression {
public:
	ThisExpression();
	virtual ~ThisExpression();
	void print();
	//virtual Type* typeinfer();
};

class ReadIntegerExpression : public Expression {
public:
	ReadIntegerExpression();
	virtual ~ReadIntegerExpression();
	void print();
	//virtual Type* typeinfer();
};

class ReadLineExpression : public Expression {
public:
	ReadLineExpression();
	virtual ~ReadLineExpression();
	void print();
	//virtual Type* typeinfer();
};

class NewInstance : public Expression {
public:
	NewInstance(char* _class_name, ClassEntity* _classEntity);
	virtual ~NewInstance();
	void print();
	//virtual Type* typeinfer();
	char* class_name;
	ClassEntity* classEntity;
};

class NullExpression : public Expression {
public:
	NullExpression();
	virtual ~NullExpression();
	void print();
	//virtual Type* typeinfer();
};

class FunctionInvocation : public Expression {
public:
	FunctionInvocation(Expression* _base, char* _name, list<Expression*>* _args);
	virtual ~FunctionInvocation();
	void print();
	//virtual Type* typeinfer();
	Expression* base;
	char* name;
	list<Expression*>* args;
};

class MemberAccess : public Expression {
public:
	MemberAccess(Expression* _base, char* _name);
	virtual ~MemberAccess();
	void print();
	//virtual Type* typeinfer();
	Expression* base;
	char* name;
};

class ArrayAccess : public Expression {
public:
	ArrayAccess(Expression* _base, Expression* _idx);
	virtual ~ArrayAccess();
	void print();
	//virtual Type* typeinfer();
	Expression* base;
	Expression* idx;
};

class IdExpression : public Expression {
public:
	IdExpression(Entity* _id);
	virtual ~IdExpression();
	void print();
	//virtual Type* typeinfer();
	Entity* id;
};

class AssignStatement : public Statement {
public:
	AssignStatement(Expression* _lhs, Expression* _rhs);
	virtual ~AssignStatement();
	void print();
	//virtual void typecheck()();
	Expression* lhs;
	Expression* rhs;
};

class CallStatement : public Statement {
public:
	CallStatement(Expression* _exprs);
	virtual ~CallStatement();
	void print();
	//virtual void typecheck()();
	Expression* exprs;
};

class DeclStatement : public Statement {
public:
	DeclStatement(Entity* _var_list);
	virtual ~DeclStatement();
	void print();
	//virtual void typecheck()();
	Entity* var_list;
};

class ExprStatement : public Statement {
public:
	ExprStatement(Expression* _expr);
	virtual ~ExprStatement();
	void print();
	//virtual void typecheck()();
	Expression* expr;
};

class BlockStatement : public Statement {
public:
	BlockStatement(list<Statement*>* _stmt_list);
	virtual ~BlockStatement();
	void print();
	//virtual void typecheck()();
	list<Statement*>* stmt_list;
};

/*
* Statement classes
*/
class ForStatement : public Statement {
public:
	ForStatement(Statement* _init, Expression* _guard, Statement* _update, Statement* _body);
	virtual ~ForStatement();
	void print();
	//virtual void typecheck()();
	Statement* init;
	Expression* guard;
	Statement* update;
	Statement* body;
};

class WhileStatement : public Statement {
public:
	WhileStatement(Expression* _expr, Statement* _body);
	virtual ~WhileStatement();
	void print();
	//virtual void typecheck()();
	Expression* expr;
	Statement* body;
};

class IfStatement : public Statement {
public:
	IfStatement(Expression* _expr, Statement* _thenpart, Statement* _elsepart);
	virtual ~IfStatement();
	void print();
	//virtual void typecheck()();
	Expression* expr;
	Statement* thenpart;
	Statement* elsepart;
};

class ReturnStatement : public Statement {
public:
	ReturnStatement(Expression* _expr);
	virtual ~ReturnStatement();
	void print();
	//virtual void typecheck()();
	Expression* expr;
};

class BreakStatement : public Statement {
	public:
		BreakStatement();
		virtual ~BreakStatement();
		void print();
		//virtual void typecheck()();
};

class PrintStatement : public Statement {
public:
	PrintStatement(list<Expression*>* _exprs);
	virtual ~PrintStatement();
	void print();
	//virtual void typecheck()();
	list<Expression*>* exprs;
};

class NullStatement : public Statement {
public:
	NullStatement();
	virtual ~NullStatement();
	void print();
	//virtual void typecheck()();
};

/*
* Constant classes
*/
class IntegerConstant : public Expression {
public:
	IntegerConstant(int _value);
	virtual ~IntegerConstant();

	void print();
	//virtual Type* typeinfer();

	int value;
};

class DoubleConstant : public Expression {
public:
	DoubleConstant(double _value);
	virtual ~DoubleConstant();

	void print();
	//virtual Type* typeinfer();

	double value;
};

class BooleanConstant : public Expression {
public:
	BooleanConstant(bool _value);
	virtual ~BooleanConstant();

	void print();
	//virtual Type* typeinfer();

	bool value;
};

class StringConstant : public Expression {
public:
	StringConstant(char* _value);
	virtual ~StringConstant();

	void print();
	//virtual Type* typeinfer();

	char* value;
};

class NullConstant : public Expression {
public:
	NullConstant();
	virtual ~NullConstant();

	void print();
	//virtual Type* typeinfer();
};
#endif

