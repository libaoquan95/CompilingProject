#ifndef AST_H
#define AST_H

#include <list>
//#include "ast_symbols.h"

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
