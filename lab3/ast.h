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
	//virtual void typecheck() = 0;
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
	virtual bool isSubtypeOf(Type *t);

	int dimension;
	//TypeKind kind;
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


/*
* Statement classes
*/
class ReturnStatement : public Statement {
public:
	ReturnStatement(Expression* _expr);
	virtual ~ReturnStatement();
	void print();
	//virtual void typecheck();
	Expression* expr;
};

class BreakStatement : public Statement {
	public:
		BreakStatement();
		virtual ~BreakStatement();
		void print();
		//virtual void typecheck();
};

class PrintStatement : public Statement {
public:
	PrintStatement(list<Expression*>* _exprs);
	virtual ~PrintStatement();
	void print();
	//virtual void typecheck();
	list<Expression*>* exprs;
};

class NullExpression : public Expression {
public:
	NullExpression();
	virtual ~NullExpression();
	void print();
	//virtual Type* typeinfer();
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
