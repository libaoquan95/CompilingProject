### 编译工程课程实验

#### lab1 Lexical Analysis
利用 felx 对 Decaf 词法分析

```
$ flex lab1/lexical_analysis/parse.l
$ gcc lab1/lexical_analysis/lex.yy.c  -o lab1/lexical_analysis/scanner
$ ./lab1/lexical_analysis/scanner < lab1/lexical_analysis/test.c
```