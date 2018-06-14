#include <iostream>
#include "ast.h"

// Print method for BinaryExpression
void BinaryExpression::print() {
	cout << "(";
	lhs->print();
	switch(binary_operator) {
		case ADD:    cout << " + "; break;
		case SUB:    cout << " - "; break;
		case MUL:    cout << " * "; break;
		case DIV:    cout << " / "; break;
		case MOD:    cout << " % "; break;
		case EQ:     cout << " == ";  break;
		case NEQ:    cout << " != "; break;
		case LT:     cout << " < ";  break;
		case LE:     cout << " <= "; break;
		case GT:     cout << " > ";  break;
		case GE:     cout << " >= "; break;
		case AND:    cout << " && "; break;
		case OR:     cout << " || ";  break;
	}
	rhs->print();
	cout << ")";
}

// Print method for UnaryExpression
void UnaryExpression::print() {
	cout << "(";
	switch(unary_operator) {
		case NOT:    cout << " !"; break;
		case UMINUS: cout << " -"; break;
	}
	arg->print();
	cout << ")";
}

// Print method for ThisExpression
void ThisExpression::print() {
	cout << "this";
}

// Print method for ReadIntegerExpression
void ReadIntegerExpression::print() {
	cout << "ReadInteger()";
}

// Print method for NewInstance
void NewInstance::print() {
	cout << "new " << class_name;
}

// Print method for ReadLineExpression
void ReadLineExpression::print() {
	cout << "ReadLine()";
}

// Print method for ReturnStatement
void ReturnStatement::print() {
	printf("%*s", level_number*2, "");
	cout << "return ";
	if (expr != NULL)
		expr->print();
	cout << ";" << endl;
}

// Print method for BreakStatement
void BreakStatement::print() {
	printf("%*s", level_number*2, "");
	cout << "break;" << endl;
}

// Print method for PrintStatement
void PrintStatement::print() {
	printf("%*s", level_number*2, "");
	cout << "Print(";
	for (auto it = exprs->begin(); it != exprs->end(); ++it){
		if (it == exprs->begin())
			(*it)->print();
		else {
			cout << ",";
			(*it)->print();
		}
	}
	cout << ");" << endl;
}

// Print method for NullExpression
void NullExpression::print() {
	cout << "null";
}

// Print method for IntegerConstant
void IntegerConstant::print() {
	cout << value;
}

// Print method for DoubleConstant
void DoubleConstant::print() {
	cout << value;
}

// Print method for BooleanConstant
void BooleanConstant::print() {
	cout << value;
}

// Print method for StringConstant
void StringConstant::print() {
	cout << "\"" << value << "\"";
}

// Print method for NullConstant
void NullConstant::print() {
	cout << "null";
}