# PascalComplier
final project of ZJU Compiler Principle

## 0、Environment

flex

bison

llvm9.0.0

linux Ubuntu16.04

## 1、COMPILE the project

suppose the project and llvm are in ~

```sh
cd ~/compiler-project
mkdir build
export LLVM_DIR=~/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-16.04/lib/cmake/llvm
cmake ..
make
```

## 2、RUN the project

```sh
./compiler [optional options] <-IR/-S> <source pascal file>
```

-IR: produce LLVM IR code
-S: produce assembler code
-O: Optional, enable LLVM optimizations
For instance,   

```sh
  ./compiler -S ../test/test-code/1.pas
```

## 3、reference

https://wenku.baidu.com/view/9c54eac6fbb069dc5022aaea998fcc22bcd14327.html

类PASCAL语法词法规则.docx