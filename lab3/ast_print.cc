#include <iostream>
#include "ast.h"

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