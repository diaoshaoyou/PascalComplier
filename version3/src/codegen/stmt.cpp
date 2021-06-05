#include "ast/base.hpp"
#include "ast/decl.hpp"
#include "ast/expr.hpp"
#include "ast/identifier.hpp"
#include "ast/stmt.hpp"
#include "ast/type.hpp"
#include "codegen_context.hpp"

namespace spc
{
    
    llvm::Value *IfStmtNode::codegen(CodegenContext &context)
    {
        auto *cond = expr->codegen(context);
        if (!cond->getType()->isIntegerTy(1))       
            throw CodegenException("Incompatible type in if condition: expected boolean");

        auto *func = context.getBuilder().GetInsertBlock()->getParent();
        auto *then_block = llvm::BasicBlock::Create(context.getModule()->getContext(), "then", func);
        auto *else_block = llvm::BasicBlock::Create(context.getModule()->getContext(), "else");
        auto *cont_block = llvm::BasicBlock::Create(context.getModule()->getContext(), "cont");
        context.getBuilder().CreateCondBr(cond, then_block, else_block);

        context.getBuilder().SetInsertPoint(then_block);
        if_stmt->codegen(context);
        context.getBuilder().CreateBr(cont_block);

        func->getBasicBlockList().push_back(else_block);
        context.getBuilder().SetInsertPoint(else_block);
        if (else_stmt != nullptr)
            else_stmt->codegen(context);
        context.getBuilder().CreateBr(cont_block);

        func->getBasicBlockList().push_back(cont_block);
        context.getBuilder().SetInsertPoint(cont_block);
        return nullptr;
    }

    llvm::Value *WhileStmtNode::codegen(CodegenContext &context)
    {
        auto *func = context.getBuilder().GetInsertBlock()->getParent();
        auto *while_block = llvm::BasicBlock::Create(context.getModule()->getContext(), "while", func);
        auto *loop_block = llvm::BasicBlock::Create(context.getModule()->getContext(), "loop", func);
        auto *cont_block = llvm::BasicBlock::Create(context.getModule()->getContext(), "cont");
        context.getBuilder().CreateBr(while_block);

        context.getBuilder().SetInsertPoint(while_block);
        auto *cond = expr->codegen(context);
        if (!cond->getType()->isIntegerTy(1))
        { throw CodegenException("Incompatible type in while condition: expected boolean"); }
        context.getBuilder().CreateCondBr(cond, loop_block, cont_block);

        context.getBuilder().SetInsertPoint(loop_block);
        stmt->codegen(context);
        context.getBuilder().CreateBr(while_block);

        func->getBasicBlockList().push_back(cont_block);
        context.getBuilder().SetInsertPoint(cont_block);
        return nullptr;
    }

    llvm::Value *ForStmtNode::codegen(CodegenContext &context)
    {
        if (!id->codegen(context)->getType()->isIntegerTy(32))
            throw CodegenException("Incompatible type in for iterator: expected int");

        auto init = make_node<AssignStmtNode>(id, init_val);
        auto upto = direction == ForDirection::To;
        auto cond = make_node<BinaryExprNode>(upto ? BinaryOp::Leq : BinaryOp::Geq, id, end_val);
        auto iter = make_node<AssignStmtNode>(id,
                make_node<BinaryExprNode>(upto ? BinaryOp::Plus :BinaryOp::Minus, id, make_node<IntegerNode>(1)));
        auto compound = make_node<CompoundStmtNode>();
        compound->merge(stmt); 
        compound->append(iter);
        auto while_stmt = make_node<WhileStmtNode>(cond, compound);

        init->codegen(context);
        while_stmt->codegen(context);
        return nullptr;
    }

    llvm::Value *RepeatStmtNode::codegen(CodegenContext &context)
    {
        auto *func = context.getBuilder().GetInsertBlock()->getParent();
        auto *block = llvm::BasicBlock::Create(context.getModule()->getContext(), "repeat", func);
        context.getBuilder().CreateBr(block);
        context.getBuilder().SetInsertPoint(block);
        
        stmt->codegen(context);
        auto *cond = expr->codegen(context);
        if (!cond->getType()->isIntegerTy(1))
            throw CodegenException("Incompatible type in repeat condition: expected boolean");
        auto *cont = llvm::BasicBlock::Create(context.getModule()->getContext(), "cont", func);
        context.getBuilder().CreateCondBr(cond, cont, block);

        context.getBuilder().SetInsertPoint(cont);
        return nullptr;
    }

    llvm::Value *ProcStmtNode::codegen(CodegenContext &context)
    {
        return call->codegen(context);
    }

    llvm::Value *AssignStmtNode::codegen(CodegenContext &context)
    {
        llvm::Value *lhs;
        lhs = this->lhs->getAssignPtr(context);
        auto *rhs = this->rhs->codegen(context);
        auto *lhs_type = lhs->getType()->getPointerElementType();
        auto *rhs_type = rhs->getType();
        if (lhs_type->isDoubleTy() && rhs_type->isIntegerTy(32))
        {
            rhs = context.getBuilder().CreateSIToFP(rhs, context.getBuilder().getDoubleTy());
        }
        else if (lhs_type->isArrayTy())
        {
            if (!lhs_type->getArrayElementType()->isIntegerTy(8))
                throw CodegenException("Cannot assign to a non-char array");
            llvm::Value *zero = llvm::ConstantInt::getSigned(context.getBuilder().getInt32Ty(), 0);
            llvm::Value *lhsPtr = context.getBuilder().CreateInBoundsGEP(lhs, {zero, zero});;
            llvm::Value *rhsPtr;
            if (rhs_type->isPointerTy())
            {
                context.log() << "\tString assign: call Sysfunc STRCPY" << std::endl;
                if (rhs_type->getPointerElementType()->isArrayTy())
                    rhsPtr = context.getBuilder().CreateInBoundsGEP(rhs, {zero, zero});
                else
                    rhsPtr = rhs;
                context.getBuilder().CreateCall(context.strcpyFunc, {lhsPtr, rhsPtr});
                return nullptr;
            }
            else if (rhs_type->isArrayTy())
            {
                context.log() << "\tString assign: Sysfunc SPRINTF" << std::endl;
                context.log() << "\tString assign: call Sysfunc SPRINTF" << std::endl;
                if (is_ptr_of<IdentifierNode>(this->rhs))
                    rhsPtr = context.getBuilder().CreateInBoundsGEP(cast_node<IdentifierNode>(this->rhs)->getPtr(context), {zero, zero});
                else if (is_ptr_of<RecordRefNode>(this->rhs))
                    rhsPtr = cast_node<RecordRefNode>(this->rhs)->getPtr(context);
                else if (is_ptr_of<CustomProcNode>(this->rhs))
                    rhsPtr = context.getBuilder().CreateInBoundsGEP(rhs, {zero, zero});
                if (!rhs_type->getArrayElementType()->isIntegerTy(8))
                    throw CodegenException("Cannot assign to a non-char array");
                context.getBuilder().CreateCall(context.sprintfFunc, {lhsPtr, context.getBuilder().CreateGlobalStringPtr("%s"), rhsPtr});
                return nullptr;
            }
        }
        else if (lhs_type->isDoubleTy() && rhs_type->isIntegerTy())
        {
            auto *rhsFP = context.getBuilder().CreateSIToFP(rhs, lhs_type);
            context.getBuilder().CreateStore(rhsFP, lhs);
            return nullptr;
        }
        else if (lhs_type->isIntegerTy(32) && rhs_type->isDoubleTy())
        {
            auto *rhsSI = context.getBuilder().CreateFPToSI(rhs, lhs_type);
            std::cerr << "Warning: Assigning REAL type to INTEGER type, this may lose information" << std::endl;
            context.getBuilder().CreateStore(rhsSI, lhs);
            return nullptr;
        }
        if (!((lhs_type->isIntegerTy(1) && rhs_type->isIntegerTy(1))  // bool
                   || (lhs_type->isIntegerTy(32) && rhs_type->isIntegerTy(32))  // int
                   || (lhs_type->isIntegerTy(8) && rhs_type->isIntegerTy(8))  // char
                   || (lhs_type->isDoubleTy() && rhs_type->isDoubleTy()) // float
                   || (lhs_type->isArrayTy() && rhs_type->isIntegerTy(32)))) // string
            throw CodegenException("Incompatible type in assignment");
        context.getBuilder().CreateStore(rhs, lhs);
        return nullptr;
    }

    llvm::Value *CaseStmtNode::codegen(CodegenContext &context)
    {
        auto *value = expr->codegen(context);
        if (!value->getType()->isIntegerTy())
            throw CodegenException("Incompatible type in case statement: expected char, integer");
        auto *func = context.getBuilder().GetInsertBlock()->getParent();
        auto *cont = llvm::BasicBlock::Create(context.getModule()->getContext(), "cont");
        auto *switch_inst = context.getBuilder().CreateSwitch(value, cont, static_cast<unsigned int>(branches.size()));
        for (auto &branch : branches)
        {
            llvm::ConstantInt *constant;
            if (is_ptr_of<ConstValueNode>(branch->branch))
                constant = llvm::cast<llvm::ConstantInt>(branch->branch->codegen(context));
            else // ID node
                constant = context.getConstInt(cast_node<IdentifierNode>(branch->branch)->name);
            auto *block = llvm::BasicBlock::Create(context.getModule()->getContext(), "case", func);
            context.getBuilder().SetInsertPoint(block);
            branch->stmt->codegen(context);
            context.getBuilder().CreateBr(cont);
            switch_inst->addCase(constant, block);
        }
        func->getBasicBlockList().push_back(cont);
        context.getBuilder().SetInsertPoint(cont);
        return nullptr;
    }
    
    //--------------------------------------------------------program.cpp
	llvm::Value *ProgramNode::codegen(CodegenContext &context)
    {
        context.is_subroutine = false;
        context.log() << "Entering main program" << std::endl;
        auto *funcT = llvm::FunctionType::get(context.getBuilder().getInt32Ty(), false);
        auto *mainFunc = llvm::Function::Create(funcT, llvm::Function::ExternalLinkage, "main", *context.getModule());
        auto *block = llvm::BasicBlock::Create(context.getModule()->getContext(), "entry", mainFunc);
        context.getBuilder().SetInsertPoint(block);

        context.log() << "Entering global const part" << std::endl;
        header->constList->codegen(context);
        context.log() << "Entering global type part" << std::endl;
        header->typeList->codegen(context);
        context.log() << "Entering global var part" << std::endl;
        header->varList->codegen(context);
        context.is_subroutine = true;
        context.log() << "Entering global routine part" << std::endl;
        header->subroutineList->codegen(context);
        context.is_subroutine = false;

        context.getBuilder().SetInsertPoint(block);
        context.log() << "Entering global body part" << std::endl;
        body->codegen(context);
        context.getBuilder().CreateRet(context.getBuilder().getInt32(0));

        llvm::verifyFunction(*mainFunc, &llvm::errs());

        // Optimizations
        if (context.fpm)
            context.fpm->run(*mainFunc);
        if (context.mpm)
            context.mpm->run(*context.getModule());
        return nullptr;
    }

    llvm::Value *RoutineNode::codegen(CodegenContext &context)
    {
        context.log() << "Entering function " + name->name << std::endl;

        if (context.getModule()->getFunction(name->name) != nullptr)
            throw CodegenException("Duplicate function definition: " + name->name);

        context.traces.push_back(name->name);

        std::vector<llvm::Type *> types;
        std::vector<std::string> names;
        for (auto &p : params->getChildren()) 
        {
            auto *ty = p->type->getLLVMType(context);
            if (ty == nullptr)
                throw CodegenException("Unsupported function param type");
            types.push_back(ty);
            names.push_back(p->name->name);
            if (ty->isArrayTy())
            {
                if (p->type->type == Type::String)
                    context.setArrayEntry(name->name + "." + p->name->name, 0, 255);
                else if (p->type->type == Type::Array)
                {
                    auto arrTy = cast_node<ArrayTypeNode>(p->type);
                    assert(arrTy != nullptr);
                    context.setArrayEntry(name->name + "." + p->name->name, arrTy);
                    arrTy->insertNestedArray(name->name + "." + p->name->name, context);
                }
                else if (p->type->type == Type::Alias)
                {
                    std::string aliasName = cast_node<AliasTypeNode>(p->type)->name->name;
                    std::shared_ptr<ArrayTypeNode> a;
                    for (auto rit = context.traces.rbegin(); rit != context.traces.rend(); rit++)
                        if ((a = context.getArrayAlias(*rit + "." + aliasName)) != nullptr)
                            break;
                    if (a == nullptr) a = context.getArrayAlias(aliasName);
                    assert(a != nullptr && "Fatal error: array type not found!");
                    context.setArrayEntry(name->name + "." + p->name->name, a);
                    a->insertNestedArray(name->name + "." + p->name->name, context);
                }
            }
            else if (ty->isStructTy())
            {
                assert(is_ptr_of<RecordTypeNode>(p->type) || is_ptr_of<AliasTypeNode>(p->type));
                if (is_ptr_of<RecordTypeNode>(p->type))
                {
                    auto recTy = cast_node<RecordTypeNode>(p->type);
                    context.setRecordAlias(name->name + "." + p->name->name, recTy);
                    recTy->insertNestedRecord(name->name + "." + p->name->name, context);
                }
                else
                {
                    std::string aliasName = cast_node<AliasTypeNode>(p->type)->name->name;
                    std::shared_ptr<RecordTypeNode> recTy = nullptr;
                    for (auto rit = context.traces.rbegin(); rit != context.traces.rend(); rit++)
                    {
                        if ((recTy = context.getRecordAlias(*rit + "." + aliasName)) != nullptr)
                            break;
                    }
                    if (recTy == nullptr) recTy = context.getRecordAlias(aliasName);
                    if (recTy == nullptr) assert(0);
                    context.setRecordAlias(name->name + "." + p->name->name, recTy);
                    recTy->insertNestedRecord(name->name + "." + p->name->name, context);
                }
            }
        }
        llvm::Type *retTy = this->retType->getLLVMType(context);
        if (retTy == nullptr) throw CodegenException("Unsupported function return type");
        if (retTy->isArrayTy())
        {
            if (!retTy->getArrayElementType()->isIntegerTy(8) || retTy->getArrayNumElements() != 256)
                throw CodegenException("Not support array as function return type");
            retTy = context.getBuilder().getInt8PtrTy();
            context.setArrayEntry(name->name + "." + name->name, 0, 255);
        }
        else if (retTy->isStructTy())
        {
            assert(is_ptr_of<RecordTypeNode>(this->retType) || is_ptr_of<AliasTypeNode>(this->retType));
            if (is_ptr_of<RecordTypeNode>(this->retType))
            {
                auto recTy = cast_node<RecordTypeNode>(this->retType);
                context.setRecordAlias(name->name + "." + name->name, recTy);
                recTy->insertNestedRecord(name->name + "." + name->name, context);
            }
            else
            {
                std::string aliasName = cast_node<AliasTypeNode>(this->retType)->name->name;
                std::shared_ptr<RecordTypeNode> recTy = nullptr;
                for (auto rit = context.traces.rbegin(); rit != context.traces.rend(); rit++)
                {
                    if ((recTy = context.getRecordAlias(*rit + "." + aliasName)) != nullptr)
                        break;
                }
                if (recTy == nullptr) recTy = context.getRecordAlias(aliasName);
                if (recTy == nullptr) assert(0);
                context.setRecordAlias(name->name + "." + name->name, recTy);
                recTy->insertNestedRecord(name->name + "." + name->name, context);
            }
        }
        auto *funcTy = llvm::FunctionType::get(retTy, types, false);
        auto *func = llvm::Function::Create(funcTy, llvm::Function::ExternalLinkage, name->name, *context.getModule());
        auto *block = llvm::BasicBlock::Create(context.getModule()->getContext(), "entry", func);
        context.getBuilder().SetInsertPoint(block);

        auto index = 0;
        for (auto &arg : func->args())
        {
            auto *type = arg.getType();
            auto *local = context.getBuilder().CreateAlloca(type);
            context.setLocal(name->name + "." + names[index++], local);
            context.getBuilder().CreateStore(&arg, local);
        }

        context.log() << "Entering const part of function " << name->name << std::endl;
        header->constList->codegen(context);
        context.log() << "Entering type part of function " << name->name << std::endl;
        header->typeList->codegen(context);
        context.log() << "Entering var part of function " << name->name << std::endl;
        header->varList->codegen(context);

        context.log() << "Entering routine part of function " << name->name << std::endl;
        header->subroutineList->codegen(context);

        context.getBuilder().SetInsertPoint(block);
        if (retType->type != Type::Void)  // set the return variable
        {  
            auto *type = retType->getLLVMType(context);

            llvm::Value *local;
            if (type == nullptr) throw CodegenException("Unknown function return type");
            else if (type->isArrayTy())
            {
                if (type->getArrayElementType()->isIntegerTy(8) && type->getArrayNumElements() == 256) // String
                {
                    local = context.getBuilder().CreateAlloca(type);
                }
                else
                    throw CodegenException("Unknown function return type");
            }
            else
                local = context.getBuilder().CreateAlloca(type);
            assert(local != nullptr && "Fatal error: Local variable alloc failed!");
            context.setLocal(name->name + "." + name->name, local);
        }

        context.log() << "Entering body part of function " << name->name << std::endl;
        body->codegen(context);

        if (retType->type != Type::Void) 
        {
            auto *local = context.getLocal(name->name + "." + name->name);
            llvm::Value *ret = context.getBuilder().CreateLoad(local);
            if (ret->getType()->isArrayTy())
            {
                llvm::Value *tmpStr = context.getTempStrPtr();
                llvm::Value *zero = llvm::ConstantInt::get(context.getBuilder().getInt32Ty(), 0, false);
                llvm::Value *retPtr = context.getBuilder().CreateInBoundsGEP(local, {zero, zero});
                context.log() << "\tSysfunc STRCPY" << std::endl;
                context.getBuilder().CreateCall(context.strcpyFunc, {tmpStr, retPtr});
                context.log() << "\tSTRING return" << std::endl;
                context.getBuilder().CreateRet(tmpStr);
            }
            else
                context.getBuilder().CreateRet(ret);
        } 
        else 
        {
            context.getBuilder().CreateRetVoid();
        }

        llvm::verifyFunction(*func, &llvm::errs());

        if (context.fpm)
            context.fpm->run(*func);

        context.traces.pop_back();  

        context.log() << "Leaving function " << name->name << std::endl;

        return nullptr;
    } 

} // namespace spc
