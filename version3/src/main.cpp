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
shared_ptr<spc::ProgramNode> program;
void Parse();
void ASTgen();
string tmpName;
char *input = nullptr;//input:file to run

int main(int argc, char* argv[])
{
    enum Target { UNDEFINED, LLVM, ASM };

    Target target = Target::UNDEFINED;
    bool opt = false;

    /*read in instruction*/
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "-ir") == 0) target = Target::LLVM;
        else if (strcmp(argv[i], "-S") == 0) target = Target::ASM;
        else if (strcmp(argv[i], "-O") == 0) opt = true;
        else if (argv[i][0] == '-')
        { 
            fprintf(stderr, "Error: unknown argument: %s", argv[i]); 
            exit(1); 
        }
        else input = argv[i];
    }
    if (target == Target::UNDEFINED || input == nullptr)
    {
        puts("USAGE: spc <option> <input file>");
        puts("OPTION:");
        puts("  -ir                  Emit LLVM assembly code (.ll)");
        puts("  -S                   Emit assembly code (.s)");
        puts(" [-O]                  Enable LLVM optimizations");
        exit(1);
    }

    if ((yyin = fopen(input, "r")) == nullptr)
    {
        cerr << "Error: cannot open iutput file" << endl;
        exit(1);
    }
    Parse();/*scan & parse*/   
    ASTgen();/*generate AST*/ 

    /*generate IR code & target code*/
    spc::CodegenContext genContext("main", opt);
    try 
    {
        program->codegen(genContext);
    } 
    catch (spc::CodegenException &e) 
    {
        cerr << "[CODEGEN ERROR] ";
        cerr << e.what() << endl;
        cerr << "Terminated due to error during code generation" << endl;
        if (genContext.log().is_open()) genContext.log().close();
        abort();
    }
    cout << "Code generation completed!" << endl;

    string output=input;
    output=output.substr(0, output.rfind('.'));
    output=output.append("/").append(tmpName);//eg:    ../test/arr+/+arr+.s
    switch (target)
    {
        case Target::LLVM: output.append(".ll"); break;
        case Target::ASM:  output.append(".s");  break;
        default: break;
    }
    error_code ec;
    llvm::raw_fd_ostream fd(output, ec, llvm::sys::fs::F_None);
    if (ec)
    { 
        llvm::errs() << "Could not open file: " << ec.message();
	cout << endl; 
        exit(1); 
    }

    switch (target)
    {
        case Target::LLVM: {
		genContext.getModule()->print(fd, nullptr); 
		break;
	}
        case Target::ASM: {/*generate target code*/
    		llvm::InitializeAllTargetInfos();
    		llvm::InitializeAllTargets();
		llvm::InitializeAllTargetMCs();
    		llvm::InitializeAllAsmParsers();
    		llvm::InitializeAllAsmPrinters();

    		llvm::Module &module = *(genContext.getModule());
    		auto target_triple = llvm::sys::getDefaultTargetTriple();
    		module.setTargetTriple(target_triple);

    		string e;
    		auto target = llvm::TargetRegistry::lookupTarget(target_triple, e);
    		if (!target){
			llvm::errs() << e; 
			exit(1);
		}

    		//auto cpu = "generic";
    		auto features = "";
    		llvm::TargetOptions opt;
    		auto rm = llvm::Optional<llvm::Reloc::Model>();
    		auto target_machine = target->createTargetMachine(target_triple, "generic", features, opt, rm);
    		module.setDataLayout(target_machine->createDataLayout());

    		llvm::legacy::PassManager pass;
    		if (target_machine->addPassesToEmitFile(pass, fd, nullptr, llvm::TargetMachine::CGFT_AssemblyFile)){
        		llvm::errs() << "The target machine cannot emit an object file";
        		exit(1);
    		}

    		llvm::verifyModule(module, &llvm::errs());
    		pass.run(module);

    		fd.flush();
		break;
	}
        default: break;
    }
    cout << "Compile result output: " << output << endl;

    return 0;
}

void Parse(){/*scan & parse*/
    spc::parser pars;
    try
    {
        pars.parse();
    }
    catch(const invalid_argument& e)
    {
        cerr << e.what() << endl;
        cerr << "Terminated due to error during flexing" << endl;
        exit(1);
    }
    catch(const logic_error& e)
    {
        cerr << e.what() << endl;
        cerr << "Terminated due to error during parsing" << endl;
        exit(1);
    }

    cout << "Scanning & Parsing completed!" << endl;
}
void ASTgen(){/*generate AST tex*/
	tmpName=input;
    	tmpName=tmpName.substr(tmpName.rfind('/')+1, tmpName.rfind('.')-tmpName.rfind('/')-1);//file name without postdex
    	string astVisName = input;
    	astVisName=astVisName.substr(0, astVisName.rfind('.'));
    	system(("mkdir -p "+astVisName).c_str());//create a new folder
    	astVisName=astVisName.append("/").append(tmpName).append(".tex");//astVisName=XX.tex
    	//cout<<"for debug: astVisName="<<astVisName<<endl;
    	spc::ASTvis astVis(astVisName);
    	astVis.travAST(program);

   	cout << "AST verification completed in " << astVisName << endl;
}
