#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    T_Le = 256, T_Ge, T_Eq, T_Ne, T_And, T_Or, T_Void, T_Int, T_Double, 
    T_Boolean, T_String, T_Class, T_Interface, T_Null, T_This, T_Extends, 
    T_Implements, T_For, T_While, T_If, T_Else, T_Return, T_Break, T_New, 
    T_NewArray, T_Print, T_ReadInteger, T_ReadLine, T_IntConstant, T_DoubleConstant, 
    T_StringConstant, T_Identifier, T_BooleanConstant
} TokenType;

static void print_token(int token) {
    static char* token_strs[] = {
    	"T_Le", "T_Ge", "T_Eq", "T_Ne", "T_And", "T_Or", "T_Void", "T_Int", "T_Double", 
	"T_Boolean", "T_String", "T_Class", "T_Interface", "T_Null", "T_This", "T_Extends", 
	"T_Implements", "T_For", "T_While", "T_If", "T_Else", "T_Return", "T_Break", "T_New", 
	"T_NewArray", "T_Print", "T_ReadInteger", "T_ReadLine", "T_IntConstant", "T_DoubleConstant", 
	"T_StringConstant", "T_Identifier", "T_BooleanConstant"
    };

    if (token < 256) {
        printf("%-20c", token);
    } else {
        printf("%-20s", token_strs[token-256]);
    }
}

#endif
