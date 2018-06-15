#include <iostream>
#include "ast.h"

extern int yylineno;


IntType::IntType() {
	kind = INT_TYPE;
	dimension = 0;
}
IntType::~IntType() {}


DoubleType::DoubleType() {
	kind = DOUBLE_TYPE;
	dimension = 0;
}
DoubleType::~DoubleType() {}


BooleanType::BooleanType() {
	kind = BOOL_TYPE;
	dimension = 0;
}
BooleanType::~BooleanType() {}


StringType::StringType() {
	kind = STRING_TYPE;
	dimension = 0;
}
StringType::~StringType() {}


VoidType::VoidType() {
	kind = VOID_TYPE;
	dimension = 0;
}
VoidType::~VoidType() {}


ClassType::ClassType(ClassEntity* _classtype)
	:	classtype(_classtype)
{
	kind = CLASS_TYPE;
	dimension = 0;
}
ClassType::~ClassType() {}


InstanceType::InstanceType(ClassEntity* _classtype)
	:	classtype(_classtype)
{
  kind = INSTANCE_TYPE;
  dimension = 0;
}
InstanceType::~InstanceType() {}


ErrorType::ErrorType() {
	kind = ERROR_TYPE;
	dimension = 0;
}
ErrorType::~ErrorType() {}


ArrayType::ArrayType(Type* _elementtype)
	:	elementtype(_elementtype)
{
	kind = ARRAY_TYPE;
	dimension = _elementtype->dimension + 1;
}
ArrayType::~ArrayType() {}


UniverseType::UniverseType() {
	kind = UNIVERSE_TYPE;
	dimension = 0;
}
UniverseType::~UniverseType() {}


NullType::NullType() {
	kind = NULL_TYPE;
	dimension = 0;
}
NullType::~NullType() {}


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


NullExpression::NullExpression()
{
    lineno = yylineno;
}
NullExpression::~NullExpression() {}


FunctionInvocation::FunctionInvocation(Expression* _base, char* _name, list<Expression*>* _args)
	:	base(_base),
		name(_name),
		args(_args)
{
    lineno = yylineno;
}
FunctionInvocation::~FunctionInvocation() {}


MemberAccess::MemberAccess(Expression* _base, char* _name)
	:	base(_base),
		name(_name)
{
    lineno = yylineno;
}
MemberAccess::~MemberAccess() {}


ArrayAccess::ArrayAccess(Expression* _base, Expression* _idx)
	:	base(_base),
		idx(_idx)
{
    lineno = yylineno;
}
ArrayAccess::~ArrayAccess() {}


IdExpression::IdExpression(Entity* _id)
	:	id(_id)
{
    lineno = yylineno;
}
IdExpression::~IdExpression() {}


AssignStatement::AssignStatement(Expression* _lhs, Expression* _rhs)
	:	lhs(_lhs),
		rhs(_rhs)
{
    lineno = yylineno;
}
AssignStatement::~AssignStatement() {}


CallStatement::CallStatement(Expression* _exprs)
	:	exprs(_exprs)
{
    lineno = yylineno;
}
CallStatement::~CallStatement() {}


DeclStatement::DeclStatement(Entity* _var_list)
	:	var_list(_var_list)
{
    lineno = yylineno;
}
DeclStatement::~DeclStatement() {}


ExprStatement::ExprStatement(Expression* _expr)
	:	expr(_expr)
{
    lineno = yylineno;
}
ExprStatement::~ExprStatement() {}


BlockStatement::BlockStatement(list<Statement*>* _stmt_list)
	:	stmt_list(_stmt_list)
{
    lineno = yylineno;
}
BlockStatement::~BlockStatement() {}


ForStatement::ForStatement(Statement* _init, Expression* _guard, Statement* _update, Statement* _body)
	:	init(_init),
		guard(_guard),
		update(_update),
		body(_body)
{
    lineno = yylineno;
}
ForStatement::~ForStatement() {}


WhileStatement::WhileStatement(Expression* _expr, Statement* _body)
	:	expr(_expr),
		body(_body)
{
    lineno = yylineno;
}
WhileStatement::~WhileStatement() {}


IfStatement::IfStatement(Expression* _expr, Statement* _thenpart, Statement* _elsepart)
	:	expr(_expr),
		thenpart(_thenpart),
		elsepart(_elsepart)
{
    lineno = yylineno;
}
IfStatement::~IfStatement() {}


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


NullStatement::NullStatement()
{
    lineno = yylineno;
}
NullStatement::~NullStatement() {}


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