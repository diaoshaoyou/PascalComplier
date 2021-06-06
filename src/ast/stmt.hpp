#ifndef STMT_AST
#define STMT_AST

#include "expr.hpp"


    using CompoundStmtNode = ListNode<StmtNode>;

    class IfStmtNode: public StmtNode
    {
    private:
        std::shared_ptr<ExprNode> expr;
        std::shared_ptr<CompoundStmtNode> if_stmt;
        std::shared_ptr<CompoundStmtNode> else_stmt;
    public:
        IfStmtNode(
            const std::shared_ptr<ExprNode> &expr, 
            const std::shared_ptr<CompoundStmtNode> &if_stmt, 
            const std::shared_ptr<CompoundStmtNode> &else_stmt = nullptr
            ) 
            : expr(expr), if_stmt(if_stmt), else_stmt(else_stmt) {}
        ~IfStmtNode() = default;

        llvm::Value *codegen(CodegenContext &context) override;
        // void print() override;
        friend class ASTvis;
        friend class ASTopt;
    };
    
    class WhileStmtNode: public StmtNode
    {
    private:
        std::shared_ptr<ExprNode> expr;
        std::shared_ptr<CompoundStmtNode> stmt;
    public:
        WhileStmtNode(
            const std::shared_ptr<ExprNode> &expr, 
            const std::shared_ptr<CompoundStmtNode> &stmt
            )
            : expr(expr), stmt(stmt) {}
        ~WhileStmtNode() = default;

        llvm::Value *codegen(CodegenContext &context) override;
        // void print() override;
        friend class ASTvis;
        friend class ASTopt;
    };

    
    enum ForDirection { To, Downto };
    
    class ForStmtNode: public StmtNode
    {
    private:
        ForDirection direction;
        std::shared_ptr<IdentifierNode> id;
        std::shared_ptr<ExprNode> init_val;
        std::shared_ptr<ExprNode> end_val;
        std::shared_ptr<CompoundStmtNode> stmt;
    public:
        ForStmtNode(
            const ForDirection dir,
            const std::shared_ptr<IdentifierNode> &id, 
            const std::shared_ptr<ExprNode> &init_val, 
            const std::shared_ptr<ExprNode> &end_val, 
            const std::shared_ptr<CompoundStmtNode> &stmt
            )
            : direction(dir), id(id), init_val(init_val), end_val(end_val), stmt(stmt) {}
        ~ForStmtNode() = default;

        llvm::Value *codegen(CodegenContext &context) override;
        // void print() override;
        friend class ASTvis;
    };
    
    class RepeatStmtNode: public StmtNode
    {
    private:
        std::shared_ptr<ExprNode> expr;
        std::shared_ptr<CompoundStmtNode> stmt;
    public:
        RepeatStmtNode(
            const std::shared_ptr<ExprNode> &expr, 
            const std::shared_ptr<CompoundStmtNode> &stmt
            )
            : expr(expr), stmt(stmt) {}
        ~RepeatStmtNode() = default;

        llvm::Value *codegen(CodegenContext &context) override;
        // void print() override;
        friend class ASTvis;
        friend class ASTopt;
    };

    class ProcStmtNode: public StmtNode
    {
    private:
        std::shared_ptr<ProcNode> call;
    public:
        ProcStmtNode(const std::shared_ptr<ProcNode> &call) : call(call) {}
        ~ProcStmtNode() = default;
        llvm::Value *codegen(CodegenContext &context) override;
        // void print() override;
        friend class ASTvis;
    };

    class AssignStmtNode: public StmtNode
    {
    private:
        std::shared_ptr<LeftExprNode> lhs;
        std::shared_ptr<ExprNode> rhs;
    public:
        AssignStmtNode(const std::shared_ptr<LeftExprNode> &lhs, const std::shared_ptr<ExprNode> &rhs)
            : lhs(lhs), rhs(rhs)
        {}
        ~AssignStmtNode() = default;

        llvm::Value *codegen(CodegenContext &context) override;
        // void print() override;
        friend class ASTvis;
        friend class ASTopt;
    };
    

    // TODO: Case
    class CaseBranchNode: public StmtNode
    {
    private:
        std::shared_ptr<ExprNode> branch;
        std::shared_ptr<CompoundStmtNode> stmt;
    public:
        CaseBranchNode(const std::shared_ptr<ExprNode> &branch, const std::shared_ptr<CompoundStmtNode> &stmt)
            : branch(branch), stmt(stmt) {}
        ~CaseBranchNode() = default;

        llvm::Value *codegen(CodegenContext &context) override { return nullptr; }
        // void print() override;
        friend class ASTvis;
        friend class CaseStmtNode;
    };

    using CaseBranchList = ListNode<CaseBranchNode>;

    class CaseStmtNode: public StmtNode
    {
    private:
        std::shared_ptr<ExprNode> expr;
        std::list<std::shared_ptr<CaseBranchNode>> branches;
    public:
        CaseStmtNode(const std::shared_ptr<ExprNode> &expr, const std::shared_ptr<CaseBranchList> &list)
            : expr(expr), branches(list->getChildren()) {}
        CaseStmtNode(const std::shared_ptr<ExprNode> &expr, std::shared_ptr<CaseBranchList> &&list)
            : expr(expr), branches(std::move(list->getChildren())) {}
        ~CaseStmtNode() = default;

        llvm::Value *codegen(CodegenContext &context) override;
        // void print() override;
        friend class ASTvis;
    };
    
    //---------------------------------------------program.hpp
    class RoutineNode;
    using RoutineList = ListNode<RoutineNode>;

    class RoutineHeadNode: public BaseNode
    {
    private:
        std::shared_ptr<ConstDeclList> constList;
        std::shared_ptr<VarDeclList> varList;
        std::shared_ptr<TypeDeclList> typeList;
        std::shared_ptr<RoutineList> subroutineList;
    public:
        RoutineHeadNode(
            const std::shared_ptr<ConstDeclList> &constList,
            const std::shared_ptr<VarDeclList> &varList,
            const std::shared_ptr<TypeDeclList> &typeList,
            const std::shared_ptr<RoutineList> &subroutineList
            )
            : constList(constList), varList(varList), typeList(typeList), subroutineList(subroutineList) {}
        ~RoutineHeadNode() = default;

        llvm::Value *codegen(CodegenContext &) override { return nullptr; }
        // void print() override;
        friend class ASTvis;
        friend class ProgramNode;
        friend class RoutineNode;
        friend class ASTopt;
    };

    class BaseRoutineNode: public BaseNode
    {
    protected:
        std::shared_ptr<IdentifierNode> name;
        std::shared_ptr<RoutineHeadNode> header;
        std::shared_ptr<CompoundStmtNode> body;
    public:
        BaseRoutineNode(const std::shared_ptr<IdentifierNode> &name, const std::shared_ptr<RoutineHeadNode> &header, const std::shared_ptr<CompoundStmtNode> &body)
            : name(name), header(header), body(body) {}
        ~BaseRoutineNode() = default;

        std::string getName() const { return name->name; }
        llvm::Value *codegen(CodegenContext &) = 0;
        // void print() = 0;
        friend class ASTvis;
        friend class ASTopt;
    };

    class RoutineNode: public BaseRoutineNode
    {
    private:
        std::shared_ptr<ParamList> params;
        std::shared_ptr<TypeNode> retType;
    public:
        RoutineNode(
            const std::shared_ptr<IdentifierNode> &name, 
            const std::shared_ptr<RoutineHeadNode> &header, 
            const std::shared_ptr<CompoundStmtNode> &body, 
            const std::shared_ptr<ParamList> &params, 
            const std::shared_ptr<TypeNode> &retType
            )
            : BaseRoutineNode(name, header, body), params(params), retType(retType) {}
        ~RoutineNode() = default;

        llvm::Value *codegen(CodegenContext &) override;
        // void print() override;
        friend class ASTvis;
    };

    class ProgramNode: public BaseRoutineNode
    {
    public:
        using BaseRoutineNode::BaseRoutineNode;
        ~ProgramNode() = default;

        llvm::Value *codegen(CodegenContext &) override;
        // void print() override;
        friend class ASTvis;
    };  

#endif
