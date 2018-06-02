### 编译工程课程实验

#### 1.lab1 词法分析
利用 felx 对 Decaf 词法分析

```
$ flex lab1/lexical_analysis/scanner.l
$ gcc lab1/lexical_analysis/lex.yy.c  -o lab1/lexical_analysis/scanner
$ ./lab1/lexical_analysis/scanner < lab1/lexical_analysis/test.c
```

#### 2.lab2 语法分析
利用 bison 对 Decaf 词法分析

```
$ flex lab2/scanner.l
$ bison lab2/parser.y
$ gcc lab2/y.tab.h lab2/lex.yy.c  lab2/parser.tab.c -o lab2/parser
$ ./lab2/parser < lab2/test/test
```