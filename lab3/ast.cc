#include <iostream>
#include "ast.h"

extern int yylineno;

BinaryExpression::BinaryExpression(BinaryOperator _binary_operator, Expression* _lhs, Expression* _rhs)
	:	binary_operator(_binary_operator),
		lhs(_lhs),
		rhs(_rhs)
{
    lineno = yylineno;
}
BinaryExpression::~BinaryExpression() {}


UnaryExpression::UnaryExpression(UnaryOperator _unary_operator, Expression* _arg)
	:	unary_operator(_unary_operator),
		arg(_arg)
{
    lineno = yylineno;
}
UnaryExpression::~UnaryExpression() {}


ThisExpression::ThisExpression() {
    lineno = yylineno;
}
ThisExpression::~ThisExpression() {}


ReadIntegerExpression::ReadIntegerExpression() {
    lineno = yylineno;
}
ReadIntegerExpression::~ReadIntegerExpression() {}


ReadLineExpression::ReadLineExpression() {
    lineno = yylineno;
}
ReadLineExpression::~ReadLineExpression() {}


NewInstance::NewInstance(char* _class_name, ClassEntity* _classEntity)
	:	class_name(_class_name),
		classEntity(_classEntity)
{
    lineno = yylineno;
}
NewInstance::~NewInstance() {}


ReturnStatement::ReturnStatement(Expression* _expr)
	:	expr(_expr)
{
    lineno = yylineno;
}
ReturnStatement::~ReturnStatement() {}


BreakStatement::BreakStatement() {
    lineno = yylineno;
}
BreakStatement::~BreakStatement() {}


PrintStatement::PrintStatement(list<Expression*>* _exprs)
	:	exprs(_exprs)
{
    lineno = yylineno;
}
PrintStatement::~PrintStatement() {}


NullExpression::NullExpression()
{
    lineno = yylineno;
}
NullExpression::~NullExpression() {}


IntegerConstant::IntegerConstant(int _value)
	:	value(_value)
{
    lineno = yylineno;
}
IntegerConstant::~IntegerConstant() {}


DoubleConstant::DoubleConstant(double _value)
	:	value(_value)
{
    lineno = yylineno;
}
DoubleConstant::~DoubleConstant() {}


BooleanConstant::BooleanConstant(bool _value)
	:	value(_value)
{
    lineno = yylineno;
}
BooleanConstant::~BooleanConstant() {}


StringConstant::StringConstant(char* _value)
	:	value(_value)
{
    lineno = yylineno;
}
StringConstant::~StringConstant() {}


NullConstant::NullConstant()
{
    lineno = yylineno;
}
NullConstant::~NullConstant() {}