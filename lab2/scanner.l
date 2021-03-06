%{
//#include "token.h"
#include "y.tab.h"
void lex_error(char* msg, int line);
%}

delim        [ \t]
whitespace   {delim}+
letter       [A-Za-z]
digit        [0-9]
digitH       [0-9a-fA-F]
operator     [+*-/%=,;!<>(){}\[\]]

string       (\"[^\"\n]*\")
identifier   {letter}({letter}|{digit}|_)*
integer      ([+|-]?{digit}+)|((0x|0X){digitH}+)
double       [+|-]?{digit}+(\.{digit}+)?(E[+|-]?{digit}+)?
comment      ("//"[^\n]*)|("/*"[^\*/]*"\*/")


%%
[\n]           { cur_line_num++;           }
{operator}     { return yytext[0];         }   
"<="           { return T_Le;              }
">="           { return T_Ge;              }
"=="           { return T_Eq;              }
"!="           { return T_Ne;              }
"&&"           { return T_And;             }
"||"           { return T_Or;              }

"void"         { return T_Void;            }
"int"          { return T_Int;             }
"double"       { return T_Double;          }
"bool"         { return T_Boolean;         }
"string"       { return T_String;          }
"class"        { return T_Class;           }
"interface"    { return T_Interface;       }
"null"         { return T_Null;            }
"this"         { return T_This;            }
"extends"      { return T_Extends;         }
"implements"   { return T_Implements;      }
"for"          { return T_For;             }
"while"        { return T_While;           }
"if"           { return T_If;              }
"else"         { return T_Else;            }
"return"       { return T_Return;          }
"break"        { return T_Break;           }
"New"          { return T_New;             }
"NewArray"     { return T_NewArray;        }
"Print"        { return T_Print;           }
"ReadInteger"  { return T_ReadInteger;     }
"ReadLine"     { return T_ReadLine;        }

"true"         { yylval = 1;            return T_BooleanConstant; }
"false"        { yylval = 0;            return T_BooleanConstant; }

{integer}      { yylval = atoi(yytext); return T_IntConstant;     }
{double}       { yylval = atof(yytext); return T_DoubleConstant;  }
{string}       { yylval = yytext;       return T_StringConstant;  }
{identifier}   { yylval = yytext;       return T_Identifier;      }
{whitespace}   { /* skip */                }
{comment}      { /* skip */                }

.              { lex_error("Unrecognized character", cur_line_num);        }
<<EOF>>        { return 0;                 }


%%

void lex_error(char* msg, int line) {
    printf("\nError at line %-3d: %s\n\n", line, msg);
}

int yywrap(void) {
    return 1;
}
