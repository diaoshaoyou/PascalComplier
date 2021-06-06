<img  src="img/title.png"  style="zoom:80%;"  />

  
  
  

<center><strong><font  size="50">本科实验报告</font></strong></center>

  
  
  
  
  
  
  
  
  

| 课程名称 | 编译原理 |

| -------- | ---------------- |

| 姓名 | |

| 学院 | 计算机学院 |

| 系 | 计算机系 |

| 专业 | 计算机科学与技术 |

| 学号 | |

| 指导老师 | 冯雁 |

  

<div  style="page-break-after:always"></div>

  

# 序言

  

## 概述

  

​ 本项目为类PASCAL语言的简易编译器，用lex完成词法分析，yacc完成语法分析，并生成语法分析树、中间代码和目标代码（汇编代码）。以下为编译器所支持的类PASCAL语言的功能：

  

数据类型：integer, longint, char, boolean, string, array, record

  

系统函数：writeln, write, abs, str, length, sqr, sqrt, chr, ord, pred, succ

  
  
  

## 文件说明

  

**src**

  

​ main.cpp：主函数，用于整合各功能

  

​ scanner.l：lex源码，用于词法分析

  

​ parser.y：yacc源码，用于语法分析

  

**CMakeLists**：用于cmake

  

**report**

  

​ report.pdf：项目报告

  

**test**

  

​ < name >.pas：测试代码

  
  
  

## 运行环境与工具

  

运行环境：linux，Ubuntu16.04

  

工具：cmake, flex, bison, llvm9.0.0

  

编译操作：

  

此处默认当前位置是工程目录内，默认llvm装在~处

  

```sh

mkdir build

cd build

export LLVM_DIR=~/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-16.04/lib/cmake/llvm

cmake ..

make

```

  

运行操作：

  

```sh

./compiler [-optional] <-IR/-S> <source pascal file>

比如：./compiler -O -IR ../test/AST.pas

```

  
  
  

## 分工

  

| 组员 | 分工 |

| ------ | ----------------------------------------- |

| 周寒靖 | 词法分析，语法分析，AST可视化，主函数main |

| 顾哲涵 | 生成目标代码，测试集，cmake |

| 邢怡婷 | 中间代码，代码优化 |

  
  
  

# 第一章 词法分析

  

词法分析负责处理编译器读入的程序字符串，将其转化成一个个独立token，留待后续语法分析使用。

  

## 1.1 lex原理

  

​ lex接收到字符串，将其与常规表达式进行匹配。 每次读入一个输入字符，直到找到一个匹配的模式。 如果能够找到一个匹配模式，Lex 就返回一个标记。如果没有可以匹配的常规表达式，将会报错。一个 .l文件通过 lex 公用程序来传递，并生成 C 的输出文件。

  

​ 一个lex程序分成3段，分别是定义区、规则区和辅助函数区。定义区是 C++和 Lex 的全局声明，规则区是词法规则，辅助函数区是补充的 C++函数。 这些段以%%来分界。

  

```sh

{定义区}

%%

{规则区}

%%

{辅助函数区}

```

  

## 1.2 具体实现

  

### 1.2.1 定义区

  

​ 定义区主要是所需的C++头文件、全局变量和一些参数设置。

  

```c++

#include<iostream>

#include<stdio.h>

#include<string>

#include<stdexcept>

#include  "parser.hpp"

#include  "ast/base.hpp"

#include  "ast/decl.hpp"

#include  "ast/expr.hpp"

#include  "ast/identifier.hpp"

#include  "ast/stmt.hpp"

#include  "ast/type.hpp"

#undef YY_DECL

#define YY_DECL int yylex(yy::parser::semantic_type* lval, yy::parser::location_type* loc)

#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

using  token = yy::parser::token::yytokentype;

```

  

### 1.2.2 规则区

  

​ 规则区是整个lex程序的核心，根据类pascal语言的词法规则，将对应字符串转化成标记。标记的对应关系如下：

  

<table  border="2"  bordercolor="black"  width="300"  cellspacing="0"  cellpadding="5">

<tr>  <td>类别</td>  <td>字符</td>  <td>标记</td>  </tr>

<tr>  <td  rowspan="20">运算符、界符</td>  <td>(</td>  <td>LP</td>  </tr>

<tr>  <td>)</td>  <td>RP</td>  </tr>

<tr>  <td>[</td>  <td>LB</td>  </tr>

<tr>  <td>}</td>  <td>RB</td>  </tr>

<tr>  <td>.</td>  <td>DOT</td>  </tr>

<tr>  <td>..</td>  <td>DOTDOT</td>  </tr>

<tr>  <td>;</td>  <td>SEMI</td>  </tr>

<tr>  <td>,</td>  <td>COMMA</td>  </tr>

<tr>  <td>:</td>  <td>COLON</td>  </tr>

<tr>  <td>*</td>  <td>MUL</td>  </tr>

<tr>  <td>/</td>  <td>TRUEDIV</td>  </tr>

<tr>  <td>+</td>  <td>PLUS</td>  </tr>

<tr>  <td>-</td>  <td>MINUS</td>  </tr>

<tr>  <td>>=</td>  <td>GE</td>  </tr>

<tr>  <td>></td>  <td>GT</td>  </tr>

<tr>  <td><=</td>  <td>LE</td>  </tr>

<tr>  <td><</td>  <td>LT</td>  </tr>

<tr>  <td><></td>  <td>UNEQUAL</td>  </tr>

<tr>  <td>=</td>  <td>EQUAL</td>  </tr>

<tr>  <td>:=</td>  <td>ASSIGN</td>  </tr>

<tr>  <td  rowspan="28">关键字</td>  <td>and</td>  <td>AND</td>  </tr>

<tr>  <td>array</td>  <td>ARRAY</td>  </tr>

<tr>  <td>case</td>  <td>CASE</td>  </tr>

<tr>  <td>const</td>  <td>CONST</td>  </tr>

<tr>  <td>div</td>  <td>DIV</td>  </tr>

<tr>  <td>mod</td>  <td>MOD</td>  </tr>

<tr>  <td>do</td>  <td>DO</td>  </tr>

<tr>  <td>downto</td>  <td>DOWNTO</td>  </tr>

<tr>  <td>else</td>  <td>ELSE</td>  </tr>

<tr>  <td>end</td>  <td>END</td>  </tr>

<tr>  <td>for</td>  <td>FOR</td>  </tr>

<tr>  <td>function</td>  <td>FUNTION</td>  </tr>

<tr>  <td>goto</td>  <td>GOTO</td>  </tr>

<tr>  <td>if</td>  <td>IF</td>  </tr>

<tr>  <td>not</td>  <td>NOT</td>  </tr>

<tr>  <td>of</td>  <td>OF</td>  </tr>

<tr>  <td>or</td>  <td>OR</td>  </tr>

<tr>  <td>xor</td>  <td>XOR</td>  </tr>

<tr>  <td>begin</td>  <td>BEGIN</td>  </tr>

<tr>  <td>procedure</td>  <td>PROCEDURE</td>  </tr>

<tr>  <td>program</td>  <td>PROGRAM</td>  </tr>

<tr>  <td>repeat</td>  <td>REPEAT</td>  </tr>

<tr>  <td>then</td>  <td>THEN</td>  </tr>

<tr>  <td>type</td>  <td>TYPE</td>  </tr>

<tr>  <td>until</td>  <td>UNTIL</td>  </tr>

<tr>  <td>var</td>  <td>VAR</td>  </tr>

<tr>  <td>while</td>  <td>WHILE</td>  </tr>

<tr>  <td>record</td>  <td>RECORD</td>  </tr>

<tr>  <td  rowspan="3">系统常数</td>  <td>true</td>  <td>SYS_CON</td>  </tr>

<tr>  <td>false</td>  <td>SYS_CON</td>  </tr>

<tr>  <td>maxint</td>  <td>SYS_CON</td>  </tr>

<tr>  <td  rowspan="10">系统函数</td>  <td>abs</td>  <td>SYS_FUNCT</td>  </tr>

<tr>  <td>chr</td>  <td>SYS_FUNCT</td>  </tr>

<tr>  <td>length</td>  <td>SYS_FUNCT</td>  </tr>

<tr>  <td>odd</td>  <td>SYS_FUNCT</td>  </tr>

<tr>  <td>ord</td>  <td>SYS_FUNCT</td>  </tr>

<tr>  <td>pred</td>  <td>SYS_FUNCT</td>  </tr>

<tr>  <td>sqr</td>  <td>SYS_FUNCT</td>  </tr>

<tr>  <td>sqrt</td>  <td>SYS_FUNCT</td>  </tr>

<tr>  <td>str</td>  <td>SYS_FUNCT</td>  </tr>

<tr>  <td>succ</td>  <td>SYS_FUNCT</td>  </tr>

<tr>  <td  rowspan="2">系统过程</td>  <td>write</td>  <td>SYS_PROC</td>  </tr>

<tr>  <td>writeln</td>  <td>SYS_PROC</td>  </tr>

<tr>  <td  rowspan="6">数据类型</td>  <td>boolean</td>  <td>SYS_TYPE</td>  </tr>

<tr>  <td>char</td>  <td>SYS_TYPE</td>  </tr>

<tr>  <td>integer</td>  <td>SYS_TYPE</td>  </tr>

<tr>  <td>longint</td>  <td>SYS_TYPE</td>  </tr>

<tr>  <td>real</td>  <td>SYS_TYPE</td>  </tr>

<tr>  <td>string</td>  <td>SYS_TYPE</td>  </tr>

<tr>  <td  >整数</td>  <td>[+-]?[0-9]+</td>  <td>INTEGER</td>  </tr>

<tr>  <td  >实数</td>  <td>[+-]?[0-9]+"."[0-9]+("e"[+-]?[0-9]+)?</td>  <td>REAL</td>  </tr>

<tr>  <td  >变量名</td>  <td>[a-zA-Z_]([a-zA-Z0-9_])*</td>  <td>ID</td>  </tr>

<tr>  <td  >字符</td>  <td>'[^']'</td>  <td>CHAR</td>  </tr>

<tr>  <td  >字符串</td>  <td>'('[^']'|'')+'</td>  <td>STRING</td>  </tr>

<tr>  <td  rowspan="3">注释</td>  <td>{...}</td>  <td>  </td>  </tr>

<tr>  <td>(*...*)</td>  <td>  </td>  </tr>

<tr>  <td>//...</td>  <td>  </td>  </tr>

</table>

  
  
  

# 第二章 语法分析

  

语法分析负责接收词法分析传来的token序列，根据既定的语法规则，输出抽象语法树结构。

  

## 2.1 yacc原理

  

​ yacc是语法分析器的生成工具，能生成LALR分析器。yacc编译器能将.y文件转化成.cpp/.c文件，方便与后续其他源码文件一起运行。

  

​ 一个yacc程序与lex程序类似，分为3段：定义区、规则区和辅助函数区。定义区是C++头文件、全局变量声明、终结符和非终结符的声明、参数设置等等。规则区是语法规则，即文法的非终结符及产生式集合，以及归约整个产生式时应执行的操作。辅助函数区包括在规则段中用到或者在语法分析器的其他部分用到的函数，这一部分一般会被直接拷贝到yacc编译器产生的cpp源文件中。三者由%%分隔。

  

```sh

{定义区}

%%

{规则区}

%%

{辅助函数区}

```

  

## 2.2 抽象语法树构建

  

抽象语法树整体结构如下图所示。

  

```mermaid

graph LR

0[BaseNode]---2[ExprNode]

2---2.1[LeftExprNode]

2.1---2.1.1[RecordRefNode]

2.1---2.1.2[ArrayRefNode]

2.1---2.1.3[IdentifierNode]

2---2.2[ConstValueNode]

2.2---2.2.1[BooleanNode]

2.2---2.2.2[IntegerNode]

2.2---2.2.3[StringNode]

2.2---2.2.4[RealNode]

2.2---2.2.5[CharNode]

2---2.3[BinaryExprNode]

2---2.4[ProcNode]

2.4---2.4.1[CustomProcNode]

2.4---2.4.2[SysProcNode]

0---ListNode

0---3[StmtNode]

3---3.1[IfStmtNode]

3---3.2[WhileStmtNode]

3---3.3[ForStmtNode]

3---3.4[RepeatStmtNode]

3---3.5[ProcStmtNode]

3---3.6[AssignStmtNode]

3---3.7[CaseBranchNode]

3---3.8[CaseStmtNode]

0---4[TypeNode]

4---4.1[VoidTypeNode]

4---4.2[SimpleTypeNode]

4---4.3[StringTypeNode]

4---4.4[AliasTypeNode]

4---4.5[RecordTypeNode]

4---4.6[ArrayTypeNode]

0---5[DeclNode]

5---5.1[ConstDeclNode]

5---5.2[TypeDeclNode]

5---5.3[ParamNode]

0---6[RoutineHeadNode]

0---7[BaseRoutineNode]

7---7.1[RoutineNode]

7---7.2[ProgramNode]

```

  

### 2.2.1 BaseNode类

  

``BaseNode``类是一个抽象类，不实现具体功能，被``ExprNode, StmtNode, TypeNode, DelNode, RoutineHeadNode, BaseRouitneNode, ListNode``继承，重载其成员函数，实现后续功能。

  

```c++

class  BaseNode{

public:

BaseNode() {}

~BaseNode() {}

virtual  llvm::Value  *codegen(CodegenContext  &) = 0;

};

```

  

### 2.2.2 ExprNode类

  

``ExprNode``被大部分实体类继承，是一个表达式类。其子类如下：

  

``LeftExprNode``：表示可获得值，也就是左值。包括记录``RecordRefNode``、数组``ArrayRefNode``和自定义变量``IdentifierNode``。

  

``ConstValueNode``：表示常量，因为常量类型很多，所以ConstValue是一个抽象类，具体由``IntegerNode、RealNode、BooleanNode、CharNode、StringNode``四个子类完成。

  

``BinaryExprNode``：表示二元表达式，节点存储有左表达式``lval``、右表达式``rval``和操作符``op``。

  

```c++

class  BinaryExprNode: public  ExprNode{

private:

BinaryOp op;

std::shared_ptr<ExprNode> lhs, rhs;

public:

BinaryExprNode(

const  BinaryOp  op, //操作符

const  std::shared_ptr<ExprNode>&  lval, //左表达式

const  std::shared_ptr<ExprNode>&  rval//右表达式

) : op(op), lhs(lval), rhs(rval) {}

~BinaryExprNode() = default;

llvm::Value  *codegen(CodegenContext  &) override;

friend  class  ASTvis;

friend  class  ASTopt;

};

```

  

``ProcNode``：表示过程/函数节点，包括用户自定义的过程``CustomProcNode``和系统过程``SysProcNode``。

  

### 2.2.3 StmtNode类

  

``StmtNode``是一个语句类，其本身是抽象类，但它的子类特征是该类会进行操作，比如赋值、比较、条件控制等。其子类与类pascal语言的基本操作一一对应：``IfStmtNode, WhileStmtNode, ForStmtNode, RepeatStmtNode, ProcStmtNode, AssignStmtNode, CaseBranchNode, CaseStmtNode``。

  

### 2.2.4 TypeNode类

  

``TypeNode``是一个类型类，其子类与类pascal支持的数据类型一一对应：``VoidTypeNode, SimpleTypeNode, StringTypeNode, AliasNode, RecordTypeNode, ArrayTypeNode``。

  

### 2.2.5 DeclNode类

  

​ ``DeclNode``是一个声明类，包括常量声明``ConstDeclNode``、变量声明``ParamNode``和类型声明``TypeDeclNode`` 。三者大同小异，都存储声明时对应对象的名字、类型和值(若声明时被赋值)。如下源码中，``name``存储常量名，``val``存储常量值。

  

```c++

class  ConstDeclNode: public  DeclNode{

private:

std::shared_ptr<IdentifierNode> name;

std::shared_ptr<ConstValueNode> val;

public:

ConstDeclNode(const  std::shared_ptr<IdentifierNode>&  name, const  std::shared_ptr<ConstValueNode>&  val) : name(name), val(val) {}

~ConstDeclNode() = default;

llvm::Value  *codegen(CodegenContext  &) override;

friend  class  ASTvis;

};

```

  

### 2.2.6 Routine类

  

​ ``Routine``是一个过程类，包括常量声明、类型声明、变量声明、函数声明和语句部分。下面是``Routine``的一个构造函数，对一个过程的过程名、变量名、返回值等等做初始化。

  

```c++

RoutineNode(

const  std::shared_ptr<IdentifierNode> &name,

const  std::shared_ptr<RoutineHeadNode> &header,

const  std::shared_ptr<CompoundStmtNode> &body,

const  std::shared_ptr<ParamList> &params,

const  std::shared_ptr<TypeNode> &retType

): BaseRoutineNode(name, header, body), params(params), retType(retType) {}

```

  

###

  

## 2.3 抽象语法树可视化

  

​ 抽象语法树通过latex实现可视化。在生成每个节点的同时，往< name >.tex文件中写入对应的latex代码。若要查看抽象语法树，用texmaker等软件将.tex文件转化成.pdf文件即可。

  

### 2.3.1 latex相关语法

  

​ ``node``可以新建一个节点，一个pascal程序只需要一个``program:<name>``根。其他子节点要被包含在``child``中，如此不断嵌套，可以增加树的深度。

  

```latex

%开头

\documentclass{minimal}

\usepackage{tikz}

%%%<

\usepackage{verbatim}

\usepackage[active,tightpage]{preview}

\PreviewEnvironment{tikzpicture}

\setlength\PreviewBorder{5pt}%

%%%>

\usetikzlibrary{trees}

\begin{document}

\tikzstyle{every node}=[draw=black,thick,anchor=west]

\tikzstyle{selected}=[draw=red,fill=red!30]

\tikzstyle{optional}=[dashed,fill=gray!50]

\begin{tikzpicture}[

grow via three points={one child at (0.5,-0.7) and

two children at (0.5,-0.7) and (0.5,-1.4)},

edge from parent path={(\tikzparentnode.south) |- (\tikzchildnode.west)}

]

%构造树结构，例：

\node {root}

child { node {name1}

child { node {name2}}

child { node {name3}}

}

child [missing] {}

child [missing] {}

%结尾

\end{tikzpicture}

\end{document}

```

  

### 2.3.2 可视化结果

  

​ 将< name >.tex文件转换成pdf，如下图是某测试程序的抽象语法树。

  

<img  src="img/a_AST.png"  style="zoom:80%;"  />

  
  
  

# 第三章 语义分析

  

# 第四章 代码生成

  

# 第五章 优化考虑

我们使用LLVM提供的功能来进行代码生成的优化。

## 5.1 中间代码优化

### 常量折叠
LLVM在生成中间代码IR的时候支持通过``IRBuilder``进行常量折叠，不需要另外进行对AST的操作。``IRBuilder``调用时会自动检查，如果有机会，则返回常量结果而不是创建计算指令。对此可以举一个简单的例子：

**优化前**
```c++
define double @calculate(double %a) {
entry:
	%tmp = fadd double 2.0000 , 1.0000
	%tmp2 = fadd double %tmp , %a
	ret double %tmp2
}
```
**优化后**
```c++
define double @calculate(double %a) {
entry:
	%tmp = fadd double 3.0000 , %a
	ret double %tmp
}
```
## 5.2 目标代码优化

### 5.2.1 简化CFG
通过``llvm::createCFGSimplificationPass()``实现。
对控制流图进行优化，实现死代码消除与基本块合并，例如：
* 删除没有前驱的基本块
* 若仅有一个前驱且该前驱仅有一个后继，基本块与前驱合并
* 消除只有一个前驱的基本块的PHI节点
* 消除仅包含无条件分支的基本块
* 把invoke指令改为调用nounwind函数
* 把 if(x) if(y)的情形改为 if ( x&&y )

### 5.2.2 Mem2Reg
通过``llvm::createPromoteMemoryToRegisterPass()``实现
尝试将内存分配提升到寄存器，消除大量alloca指令，使得代码变得简洁很多

### 5.2.3 公共子表达式消除
通过``llvm::createGVNPass()``实现
该pass尝试消除代码中出现的冗余子计算，消除相同计算的冗余指令。

### 5.2.4 指令合并
通过``llvm::createInstructionCombiningPass()``实现
它是一组多种多样的“窥孔优化”，将一组由数据流连接的指令重写为更高效的形式。


# 第六章 测试结果

### 6.1 顺序选择循环测试
编写如下的测试代码，命名为`1.pas`
```pascal
program main;
VAR
    i: integer;
begin
    i := 1 * 3 + sqr(10) - 4 div 2;
    writeln(i);
    
    if i < 100 then writeln('i < 100')
    else writeln('i >= 100');

    i:=1;
    while i<10 do begin
        write(i);
        i := i + 1;
    end;
    writeln;
end.
```
上述代码分别涉及了顺序，选择，循环三种结构，编译成功后得到的`IR code` 如下：
```c++
...
define i32 @main() {
entry:
  store i32 101, i32* @i
  %0 = load i32, i32* @i
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i32 %0)
  %2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @1, i32 0, i32 0))
  %3 = load i32, i32* @i
  %4 = icmp slt i32 %3, 100
  br i1 %4, label %then, label %else

then:                                             ; preds = %entry
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @3, i32 0, i32 0), [8 x i8]* @2)
  %6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @4, i32 0, i32 0))
  br label %cont

else:                                             ; preds = %entry
  %7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @6, i32 0, i32 0), [9 x i8]* @5)
  %8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @7, i32 0, i32 0))
  br label %cont

cont:                                             ; preds = %else, %then
  store i32 1, i32* @i
  br label %while

while:                                            ; preds = %loop, %cont
  %9 = load i32, i32* @i
  %10 = icmp slt i32 %9, 10
  br i1 %10, label %loop, label %cont1

loop:                                             ; preds = %while
  %11 = load i32, i32* @i
  %12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @8, i32 0, i32 0), i32 %11)
  %13 = load i32, i32* @i
  %14 = add i32 %13, 1
  store i32 %14, i32* @i
  br label %while

cont1:                                            ; preds = %while
  %15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @9, i32 0, i32 0))
  ret i32 0
}
```
执行后的结果正确：
<img  src="img/test1.jpg" />

### 6.2 函数功能测试
编写如下代码，测试函数功能，命名为`2.pas`
```pascal
program main;
var
  a, b, c : integer;
  d, e : Real;
  f: boolean;

function gcd(a:integer ; b:integer): integer;
  begin
    if b=0 then
      gcd:=a
    else 
      gcd:=gcd(b,a mod b);
  end;

begin
  a:=27;
  b:=12;
  c:=gcd(a,b);
  writeln('gcd=',c);
end.
```
实现基本的求最大公因数gcd的函数，可以预见输出应该为3。 编译生成的IR code如下：
```c++
...
define i32 @gcd(i32, i32) {
entry:
  %2 = alloca i32
  store i32 %0, i32* %2
  %3 = alloca i32
  store i32 %1, i32* %3
  %4 = alloca i32
  %5 = load i32, i32* %3
  %6 = icmp eq i32 %5, 0
  br i1 %6, label %then, label %else

then:                                             ; preds = %entry
  %7 = load i32, i32* %2
  store i32 %7, i32* %4
  br label %cont

else:                                             ; preds = %entry
  %8 = load i32, i32* %3
  %9 = load i32, i32* %2
  %10 = load i32, i32* %3
  %11 = srem i32 %9, %10
  %12 = call i32 @gcd(i32 %8, i32 %11)
  store i32 %12, i32* %4
  br label %cont

cont:                                             ; preds = %else, %then
  %13 = load i32, i32* %4
  ret i32 %13
}
```
执行后的结果正确：
<img  src="img/test2.jpg" />

### 6.3 其他系统函数测试
测试上述没有使用过但是支持的系统函数，命名为`3.pas`
```pascal
program main;
const
  A = -1;
  B = -1.0;
  ZERO = 0;
  ss = 'wow';
var
  a,b: integer;
  c: char;
  s: string;
begin
  writeln('abs(-1): ', abs(A));
  writeln('abs(-1.0): ', abs(B));
  writeln('sqrt(2): ', sqrt(2));
  writeln('chr(65): ', chr(65));
  writeln('ord(A): ', ord('A'));
  writeln('succ(A): ', succ('A'));
  writeln('pred(Z): ', pred('Z'));
end.
```
编译得到的`IR code`如下：
```c++
...
define i32 @main() {
entry:
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0), [10 x i8]* @0)
  %1 = call i32 @abs(i32 -1)
  %2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @2, i32 0, i32 0), i32 %1)
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @3, i32 0, i32 0))
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @5, i32 0, i32 0), [12 x i8]* @4)
  %5 = call double @fabs(double -1.000000e+00)
  %6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @6, i32 0, i32 0), double %5)
  %7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @7, i32 0, i32 0))
  %8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @9, i32 0, i32 0), [10 x i8]* @8)
  %9 = call double @sqrt(double 2.000000e+00)
  %10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @10, i32 0, i32 0), double %9)
  %11 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @11, i32 0, i32 0))
  %12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @13, i32 0, i32 0), [10 x i8]* @12)
  %13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @14, i32 0, i32 0), i8 65)
  %14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @15, i32 0, i32 0))
  %15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @17, i32 0, i32 0), [9 x i8]* @16)
  %16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @18, i32 0, i32 0), i32 65)
  %17 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @19, i32 0, i32 0))
  %18 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @21, i32 0, i32 0), [10 x i8]* @20)
  %19 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @22, i32 0, i32 0), i8 66)
  %20 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @23, i32 0, i32 0))
  %21 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @25, i32 0, i32 0), [10 x i8]* @24)
  %22 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @26, i32 0, i32 0), i8 89)
  %23 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @27, i32 0, i32 0))
  ret i32 0
}
```
运行结果如下，显然可以验证正确性。
<img  src="img/test3.jpg" />
