#include <iostream>
#include "ast.h"

extern int yylineno;


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