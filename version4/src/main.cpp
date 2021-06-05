#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <stdlib.h>

#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Target/TargetMachine.h>
#include "utils/ASTvis.hpp"
#include "codegen/codegen_context.hpp"
#include "parser.hpp"
#include "ast/base.hpp"
#include "ast/decl.hpp"
#include "ast/expr.hpp"
#include "ast/identifier.hpp"
#include "ast/stmt.hpp"
#include "ast/type.hpp"
using namespace std;
extern FILE *yyin;
shared_ptr<ProgramNode> program;

string tmpName;
char *input = nullptr;

void Parse(){ // Scan and Parse
    yy::parser pars;
    try {
        pars.parse();
    }
    catch(const invalid_argument& e) {
        cerr << e.what() << endl;
        cerr << "Terminated due to error during flexing" << endl;
        exit(1);
    }
    catch(const logic_error& e) {
        cerr << e.what() << endl;
        cerr << "Terminated due to error during parsing" << endl;
        exit(1);
    }
    cout << "Scanning and Parsing completed!" << endl;
}

void ASTgen(){ // generate AST
	tmpName=input;
    tmpName=tmpName.substr(tmpName.rfind('/')+1, tmpName.rfind('.')-tmpName.rfind('/')-1); // get filename
    string astVisName = input;
    astVisName=astVisName.substr(0, astVisName.rfind('.'));
    system(("mkdir -p "+astVisName).c_str()); 
    astVisName=astVisName.append("/").append(tmpName).append(".tex"); // name.tex
    ASTvis astVis(astVisName);
    astVis.travAST(program);

   	cout << "AST generated in " << astVisName << endl;
}

int main(int argc, char* argv[]) {
    int kase = 0;  // 0:invalid input   1:to IR   2: to target
    bool optimize = false;
    // read 
    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "-IR")) kase = 1;
        else if (!strcmp(argv[i], "-S")) kase = 2;
        else if (!strcmp(argv[i], "-O")) optimize = true;
        else if (argv[i][0] == '-') { 
            fprintf(stderr, "Error: invalid input"); 
            exit(1); 
        }
        else input = argv[i];
    }
    if (kase == 0 || input == nullptr) {
        cerr << "Error: invalid input" << endl;
        exit(1);
    }
    if ((yyin = fopen(input, "r")) == nullptr) {
        cerr << "Error: invalid input" << endl;
        exit(1);
    }
    Parse(); 
    ASTgen();

    CodegenContext genContext("main", optimize);
    try {
        program->codegen(genContext);
    } catch (CodegenException &e) {
        cerr << "[CODEGEN ERROR] ";
        cerr << e.what() << endl;
        cerr << "Terminated due to error during code generation" << endl;
        if (genContext.log().is_open()) genContext.log().close();
        abort();
    }
    cout << "Code generation completed!" << endl;

    // define the position where we write
    string output=input;
    output=output.substr(0, output.rfind('.'));
    output=output.append("/").append(tmpName); 
    if (kase == 1) output.append(".ll");
    else if (kase == 2) output.append(".s");

    std::error_code EC;
    llvm::raw_fd_ostream dest(output, EC, llvm::sys::fs::F_None);
    if (EC) { 
        llvm::errs() << "Could not open file: " << EC.message();
        exit(1); 
    }

    // generate process
    if (kase == 1){ // IR code
        genContext.getModule()->print(dest, nullptr); 
    } else if (kase == 2){ // target code
        // first choose the target architecture
        llvm::InitializeAllTargetInfos();
        llvm::InitializeAllTargets();
        llvm::InitializeAllTargetMCs();
        llvm::InitializeAllAsmParsers();
        llvm::InitializeAllAsmPrinters();
        std::string Error;
        auto TargetTriple = llvm::sys::getDefaultTargetTriple();
        auto target=llvm::TargetRegistry::lookupTarget(TargetTriple,Error);
        if (!target){
            llvm::errs() << Error; 
            exit(1);
        }
        // then choose the target machine
        auto CPU = "generic";
        auto Features = "";
        llvm::TargetOptions opt;
        auto RM = llvm::Optional<llvm::Reloc::Model>();
        auto Target_Machine = target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

        // configure the module
        llvm::Module &module = *(genContext.getModule());
        module.setDataLayout(Target_Machine->createDataLayout());
        module.setTargetTriple(TargetTriple);
    
        // pass the target code
        llvm::legacy::PassManager pass;
        auto FileType = llvm::TargetMachine::CGFT_AssemblyFile;
        if (Target_Machine->addPassesToEmitFile(pass, dest, nullptr, FileType)){
            llvm::errs() << "TargetMachine can't emit a file of this type!";
            exit(1);
        }
        pass.run(module);
        dest.flush();
    }
    cout << "Generated by compiler: " << output << endl;
    return 0;
}
