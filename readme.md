### 编译工程课程实验

#### 1.lab1 词法分析
利用 felx 对 Decaf 词法分析

```
$ cd lab1
$ flex lexical_analysis/scanner.l
$ gcc lexical_analysis/lex.yy.c  -o lexical_analysis/scanner
$ ./lexical_analysis/scanner < lexical_analysis/test.c
```

#### 2.lab2 语法分析
利用 bison 对 Decaf 词法分析

```
$ cd lab2
$ flex scanner.l
$ bison parser.y
$ gcc y.tab.h lex.yy.c parser.tab.c -o parser
$ ./parser < test/test
```

#### 3.lab3 语义分析
利用 bison 对 Decaf 语义分析

```
$ cd lab3
$ flex scanner.l
$ bison parser.y
$ g++ symbols.cc ast_symbols.cc ast.cc ast_print.cc lex.yy.c parser.tab.c -o parser -std=c++11
$ ./parser < test/test
```
