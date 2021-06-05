# Pascal-Compiler
A simple pascal compiler using flex and bison as frontend and LLVM as backend. Project for Compiler Principle course in ZJU.

## Functionalities

- Support types
  - Integer, Longint, Char, Boolean, String: Complete support
  - Array: Partial
    - Support: Array of Basic Types/String
    - Array of array (i.e. multi-dim array)
    - Array of record
    - Array as param of function
    - NOT support:
      - Array as return of function
  - Record
    - Support:
      - Record field of Basic Types/String
      - Record as param/return of function
      - Nested record/Array in record field
- Support system functions
  - `writeln`/`write`: Integer, Longint, Real, Char, String
    - *Variable argument number*
    - Implemented by `printf`
  - `abs`: Integer, Real -> Integer, Real
    - Implemented by `abs` for Integer and `fabs` for Real
  - `val`: String -> Integer
    - Description: Converts the String content into its INTEGER value
    - Implemented by `atoi`
  - `str`: Integer, Real, Char -> String
    - Description: Converts value into String
    - Implemented by `sprintf`
  - `length`: String -> Integer
    - Description: computes the length of the String
    - Implemented by `strlen`
  - `sqr`: Integer, Real -> Integer, Real
    - Description: computes the square of the input
    - Implemented by a single instruction that multiplies the argument with itself
  - `sqrt`: Integer, Real -> Real
    - Description: computes the square root of the input
    - Implemented by `sqrt`
  - `chr`: Integer -> Char
    - Description: returns the Char with ASCII of the input
    - Implemented by a type conversion
  - `ord`: Char -> Integer
    - Description: returns the ASCII of the input Char
    - Implemented by a type conversion
  - `pred`/`succ`: Char -> Char
    - Description: returns the previous/next of the input Char according to ASCII
    - Implemented by a single instruction that adds/substracts the argument with 1

## Build and use

1. Install flex and bison

   ```shell
   sudo apt install -y flex bison
   ```

2. Download LLVM 9.0.0

   - **Note: DO NOT use the LLVM installed from apt!**

   - Download from LLVM official website:

     - Website address: https://releases.llvm.org/download.html#9.0.0

     - If you're Ubuntu 14/16/18/19.04, you can download the pre-built binaries:

       - Take Ubuntu 18.04 as example:

         ```sh
         wget https://releases.llvm.org/9.0.0/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz
         ```

       - If the Internet speed in the virtual machine is too slow, you can download it in Windows first and drag it into virtual machine

     - If your system doesn't support pre-built binaries, you should download the source code yourself and compile it

   - Extract the tar.xz:

     ```sh
     tar xvf clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz
     ```

   - Install prerequisites

     ```sh
     sudo apt install -y cmake zlib1g-dev libedit-dev libxml2-dev
     ```

3. Suppose your LLVM 9.0.0 binary is at `path/to/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04`, the directory for this project is at `~/Pascal-Compiler`
   With all the prerequisites installed, you can build this project

   ```sh
   cd ~/Pascal-Compiler
   mkdir build
   export LLVM_DIR=~/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04/lib/cmake/llvm
   cmake ..
   make
   ```

4. Enjoy! (-o is optional)

   ```
   ./compiler [optional options] <-ir/-S> <source pascal file>
   ```

   Args description:

   - -ir: produce LLVM IR code
   - -S: produce assembler code
   - -O: Optional, enable LLVM optimizations


5. Result
   The result will in version1/test/<file name>  for instance, "arr.pas" result will in version1/test/arr/

6. Notes
llvm optimization: codegen_context.hpp, line:420-432
target code generation: llvm::TargetMachine::CodeGenFileType type, llvm::Module &module), main.cpp, line:41

