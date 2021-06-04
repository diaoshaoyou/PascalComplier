//To get AST graph in .tex pattern
#include "ASTvis.hpp"

#include <fstream>
#include <iostream>
#include <string>

using namespace spc;
using namespace std;
void ASTvis::travAST(const std::shared_ptr<ProgramNode>& prog)
{

    of << texHeader;
    of << "\\node {Program: " << prog->getName() << "}\n";
    travRoutineBody(dynamic_pointer_cast<BaseRoutineNode>(prog));
    of << texTail;

    //std::cout << "debug info:\n" << prog->getName() << std::endl;

    return;
}

int ASTvis::travRoutineBody(const std::shared_ptr<BaseRoutineNode>& prog)
{
    int tmp = 0, lines = 6;
    of << "child { node {CONST}\n";
    tmp = travCONST(prog->header->constList);
    of << "}\n";
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    // std::cout << "debug info: CONST part over" << std::endl;

    of << "child { node {TYPE}\n";
    tmp = travTYPE(prog->header->typeList);
    of << "}\n";
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    // std::cout << "debug info: TYPE part over" << std::endl;

    of << "child { node {VAR}\n";
    tmp = travVAR(prog->header->varList);
    of << "}\n";
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    // std::cout << "debug info: VAR part over" << std::endl;

    of << "child { node {PROC or FUNC}\n";
    tmp = travSubprocList(prog->header->subroutineList);
    of << "}\n";
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    // std::cout << "debug info: PROC part over" << std::endl;

    of << "child { node {STMT}\n";
    tmp = travCompound(prog->body);
    of << "}\n";
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    // std::cout << "debug info: BODY part over" << std::endl;

    return lines;
}

int ASTvis::travCONST(const std::shared_ptr<ConstDeclList>& const_declListAST)
{
    std::list<std::shared_ptr<ConstDeclNode>>& constList(const_declListAST->getChildren());
    int lines = constList.size();

    for (auto &p : constList) {
        of << "   child { node {";
        of << p->name->name << " : ";
        switch (p->val->type) {
            case Type::Void    : of << "VOID"   ; break;
            case Type::Array   : of << "ARRAY"  ; break;
            case Type::Record  : of << "RECORD" ; break;
            case Type::Bool : of << "BOOLEAN"; break;
            case Type::Int : of << "INTEGER"; break;
            case Type::Long : of << "LONG"; break;
            case Type::Real    : of << "REAL"   ; break;
            case Type::String  : of << "STRING" ; break;
            default : of << "ERROR"; break;
        }
        of << "}}\n";
    }
    return lines;
}

int ASTvis::travTYPE(const std::shared_ptr<TypeDeclList>& type_declListAST)
{
    std::list<std::shared_ptr<TypeDeclNode>>& typeList(type_declListAST->getChildren());
    int lines = typeList.size();

    for (auto &p : typeList) {
        of << "   child { node {";
        of << p->name->name << " : ";
        switch (p->type->type) {
            case Type::Void    : of << "VOID"   ; break;
            case Type::Array   : of << "ARRAY"  ; break;
            case Type::Record  : of << "RECORD" ; break;
            case Type::Bool : of << "BOOLEAN"; break;
            case Type::Int : of << "INTEGER"; break;
            case Type::Long : of << "LONG"; break;
            case Type::Real    : of << "REAL"   ; break;
            case Type::String  : of << "STRING" ; break;
            default : of << "ERROR"; break;
        }
        of << "}}\n";
    }
    return lines;
}
int ASTvis::travVAR(const std::shared_ptr<VarDeclList>& var_declListAST)
{
    std::list<std::shared_ptr<VarDeclNode>>& varList(var_declListAST->getChildren());
    int lines = varList.size();

    for (auto &p : varList) {
        of << "   child { node {";
        of << p->name->name << " : ";
        switch (p->type->type) {
            case Type::Void    : of << "VOID"   ; break;
            case Type::Array   : of << "ARRAY"  ; break;
            case Type::Record  : of << "RECORD" ; break;
            case Type::Bool : of << "BOOLEAN"; break;
            case Type::Int : of << "INTEGER"; break;
            case Type::Long : of << "LONG"; break;
            case Type::Real    : of << "REAL"   ; break;
            case Type::String  : of << "STRING" ; break;
            case Type::Alias  : of << "ALIAS" ; break;
            default : of << "ERROR"; break;
        }
        of << "}}\n";
    }
    return lines;
}

int ASTvis::travSubprocList(const std::shared_ptr<RoutineList>& subProc_declListAST)
{
    std::list<std::shared_ptr<RoutineNode>>& progList(subProc_declListAST->getChildren());
    int tmp = 0, lines = progList.size();

    for (auto &p : progList) {
        tmp = travSubproc(p);
        for (int i=0; i<tmp; ++i) of << "   " << texNone;
        lines += tmp;
    }
    return lines;
}

int ASTvis::travSubproc(const std::shared_ptr<RoutineNode>& subProc_AST)
{
    int lines = 0;
    of << "   child { node {";
    if (subProc_AST->retType->type == Type::Void )
        of << "PROCEDURE: " << subProc_AST->getName();
    else
    {
        of << "FUNCTION: " << subProc_AST->getName();
        of << "$ -- $RET$-$TYPE: ";
        switch (subProc_AST->retType->type) {
            case Type::Void    : of << "VOID"   ; break;
            case Type::Array   : of << "ARRAY"  ; break;
            case Type::Record  : of << "RECORD" ; break;
            case Type::Bool : of << "BOOLEAN"; break;
            case Type::Int : of << "INTEGER"; break;
            case Type::Long : of << "LONG"; break;
            case Type::Real    : of << "REAL"   ; break;
            case Type::String  : of << "STRING" ; break;
            default : of << "ERROR"; break;
        }
    }

    std::list<std::shared_ptr<ParamNode>>& paramAsts
            = subProc_AST->params->getChildren();
    {
        of << "$ -- $PARAMS: ";
        for (auto &p : paramAsts) {
            of << p->name->name << " $-$ ";
            switch (p->type->type) {
                case Type::Void    : of << "VOID"   ; break;
                case Type::Array   : of << "ARRAY"  ; break;
                case Type::Record  : of << "RECORD" ; break;
                case Type::Bool : of << "BOOLEAN"; break;
                case Type::Int : of << "INTEGER"; break;
                case Type::Long : of << "LONG"; break;
                case Type::Real    : of << "REAL"   ; break;
                case Type::String  : of << "STRING" ; break;
                default : of << "ERROR"; break;
            }
        }
    }
    of << "}\n";
    lines = travRoutineBody(dynamic_pointer_cast<BaseRoutineNode>(subProc_AST));
    of << "}\n";
    return lines;
}

int ASTvis::travCompound(const std::shared_ptr<CompoundStmtNode>& compound_declListAST)
{
    if (compound_declListAST == nullptr) return 0;
    std::list<std::shared_ptr<StmtNode>>& stmtList(compound_declListAST->getChildren());
    int tmp = 0, lines = stmtList.size();
    for (auto &p : stmtList) {
        tmp = 0;
        //if (is_ptr_of<IfStmtNode>(p))
	if(dynamic_cast<IfStmtNode *>(p.get()) != nullptr)
        {
	    tmp += travStmt(dynamic_pointer_cast<IfStmtNode>(p));
            //tmp += travStmt(cast_node<IfStmtNode>(p));
            // std::cout << "debug info: IF over" << std::endl;
        }
        else if (dynamic_cast<WhileStmtNode *>(p.get()) != nullptr)
        {
            tmp += travStmt(dynamic_pointer_cast<WhileStmtNode>(p));
            // std::cout << "debug info: WHILE over" << std::endl;
        }
        else if (dynamic_cast<ForStmtNode *>(p.get()) != nullptr)
        {
            tmp += travStmt(dynamic_pointer_cast<ForStmtNode>(p));
            // std::cout << "debug info: FOR over" << std::endl;
        }
        else if (dynamic_cast<RepeatStmtNode *>(p.get()) != nullptr)
        {
            tmp += travStmt(dynamic_pointer_cast<RepeatStmtNode>(p));
            // std::cout << "debug info: REPEAT over" << std::endl;
        }
        else if (dynamic_cast<ProcStmtNode *>(p.get()) != nullptr)
        {
            tmp += travStmt(dynamic_pointer_cast<ProcStmtNode>(p));
            // std::cout << "debug info: PROC over" << std::endl;
        }
        else if (dynamic_cast<AssignStmtNode *>(p.get()) != nullptr)
        {
            tmp += travStmt(dynamic_pointer_cast<AssignStmtNode>(p));
            // std::cout << "debug info: ASSIGN over" << std::endl;
        }
        else if (dynamic_cast<CaseStmtNode *>(p.get()) != nullptr)
        {
            tmp += travStmt(dynamic_pointer_cast<CaseStmtNode>(p));
            // std::cout << "debug info: CASE over" << std::endl;
        }
        lines += tmp;
    }
    return lines;
}

int ASTvis::travStmt(const std::shared_ptr<CaseStmtNode>&p_stmp)
{
    if (p_stmp == nullptr) return 0;
    std::list<std::shared_ptr<CaseBranchNode>>& stmtList(p_stmp->branches);
    int tmp = 0, lines = stmtList.size();
    of << "child { node {CASE Statment case expr}\n";
    tmp = travExpr(p_stmp->expr);
    of << "}\n";
    for (int i=0; i<tmp+1; ++i) of << texNone;
    lines += tmp; tmp = 0;
    of << "child { node {CASE Statement case branches}\n";
    int sublines = stmtList.size();
    for (auto &p : stmtList)
    {
        std::string br;
        if (dynamic_cast<IntegerNode *>((p->branch).get()) != nullptr)
            br = std::to_string(cast_node<IntegerNode>(p->branch)->val);
	    //br = to_string((dynamic_pointer_cast<IntegerNode>((p->branch))->val);
        else if (dynamic_cast<IdentifierNode *>((p->branch).get()) != nullptr)
            br = cast_node<IdentifierNode>(p->branch)->name;
	    //IdentifierNode* tmp = dynamic_pointer_cast<IdentifierNode>(p->branch);
	    //br = tmp->name;
        of << "child { node {Case " + br + "}\n";
        tmp = travCompound(p->stmt);
        of << "}\n";
        for (int i=0; i<tmp; ++i) of << texNone;
        lines += tmp; sublines += tmp; tmp = 0;
    }
    of << "}\n";
    for (int i=0; i<sublines; ++i) of << texNone;
    return lines;
}

int ASTvis::travStmt(const std::shared_ptr<StmtNode>&p_stmp)
{
    if (p_stmp == nullptr) return 0;
    of << "child { node {Base Statment}}\n";
    return 0;
}
// * done
int ASTvis::travStmt(const std::shared_ptr<IfStmtNode>&p_stmp)
{
    if (p_stmp == nullptr) return 0;
    int tmp = 0, lines = 3;
    of << "child { node {IF Statment if expr}\n";
    tmp += travExpr(p_stmp->expr);
    of << "}\n";
    for (int i=0; i<tmp+1; ++i) of << texNone;
    lines += tmp; tmp = 0;
    // std::cout << "debug info: IF expr over" << std::endl;
    of << "child { node {IF Statment if stmt}\n";
    tmp = travCompound(p_stmp->if_stmt);
    of << "}\n";
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp; tmp = 0;
    // std::cout << "debug info: IF part over" << std::endl;
    of << "child { node {IF Statment else stmt}\n";
    tmp = travCompound(p_stmp->else_stmt);
    of << "}\n";
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp; tmp = 0;
    // std::cout << "debug info: ELSE part over" << std::endl;

    return lines;
}
int ASTvis::travStmt(const std::shared_ptr<WhileStmtNode>&p_stmp)
{
    if (p_stmp == nullptr) return 0;
    int tmp = 0, lines = 2;
    of << "child { node {WHILE Expr}";
    tmp = travExpr(p_stmp->expr);
    of << "}\n";
    for (int i=0; i<tmp+1; ++i) of << texNone;
    lines += tmp; tmp = 0;
    of << "child { node {WHILE Statment}\n";
    tmp = travCompound(p_stmp->stmt);
    of << "}\n";
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp; tmp = 0;
    return lines;
}
int ASTvis::travStmt(const std::shared_ptr<ForStmtNode>&p_stmp)
{
    if (p_stmp == nullptr) return 0;
    int tmp = 0, lines = 0;
    of << "child { node {FOR Expr: ";
    of << p_stmp->id->name << " }\n ";

    tmp += travExpr(p_stmp->init_val);
    // of << texNone;
    tmp += travExpr(p_stmp->end_val);
    of << "}\n";
    for (int i=0; i<tmp+1; ++i) of << texNone;
    lines += tmp; tmp = 0;

    of << "child { node {FOR Statment}\n";
    tmp = travCompound(p_stmp->stmt);
    of << "}\n";
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;

    return lines;
}
int ASTvis::travStmt(const std::shared_ptr<RepeatStmtNode>&p_stmp)
{
    if (p_stmp == nullptr) return 0;
    int tmp = 0, lines = 2;
    of << "child { node {REPEAT Expr}";
    tmp += travExpr(p_stmp->expr);
    of << "}\n";
    for (int i=0; i<tmp+1; ++i) of << texNone;
    lines += tmp; tmp = 0;
    of << "child { node {REPEAT Statment}\n";
    tmp = travCompound(p_stmp->stmt);
    of << "}\n";
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    // of << "}\n";
    return lines;
}
int ASTvis::travStmt(const std::shared_ptr<ProcStmtNode>&p_stmp)
{
    if (p_stmp == nullptr) return 0;
    int tmp = 0, lines = 0;
    of << "child { node {CALL Statment";
    // tmp = travExpr(p_stmp->expr);
    // for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    of << "}\n}\n";
    return lines;
}
int ASTvis::travStmt(const std::shared_ptr<AssignStmtNode>&p_stmp)
{
    if (p_stmp == nullptr) return 0;
    int tmp = 2, lines = 0;
    of << "child { node {ASSIGN Statment}";
    tmp += travExpr(p_stmp->lhs);
    tmp += travExpr(p_stmp->rhs);
    of << "}\n";
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    // of << "}\n}\n";
    return lines;
}

int ASTvis::travExpr(const std::shared_ptr<ExprNode>& expr)
{
    int tmp = 0, lines = 0;
    if (dynamic_cast<BinaryExprNode *>(expr.get()) != nullptr)
        //tmp += travExpr(cast_node<BinaryExprNode>(expr));
	tmp += travExpr(dynamic_pointer_cast<BinaryExprNode>(expr));
    else if (dynamic_cast<IdentifierNode *>(expr.get()) != nullptr)
        //tmp += travExpr(cast_node<IdentifierNode>(expr));
	tmp += travExpr(dynamic_pointer_cast<IdentifierNode>(expr));
    else if (dynamic_cast<ConstValueNode *>(expr.get()) != nullptr)
        //tmp += travExpr(cast_node<ConstValueNode>(expr));
	tmp += travExpr(dynamic_pointer_cast<ConstValueNode>(expr));
    else if (dynamic_cast<ArrayRefNode *>(expr.get()) != nullptr)
        //tmp += travExpr(cast_node<ArrayRefNode>(expr));
	tmp += travExpr(dynamic_pointer_cast<ArrayRefNode>(expr));
    else if (dynamic_cast<RecordRefNode *>(expr.get()) != nullptr)
        //tmp += travExpr(cast_node<RecordRefNode>(expr));
	tmp += travExpr(dynamic_pointer_cast<RecordRefNode>(expr));
    else if (dynamic_cast<CustomProcNode *>(expr.get()) != nullptr)
        //tmp += travExpr(cast_node<CustomProcNode>(expr));
	tmp += travExpr(dynamic_pointer_cast<CustomProcNode>(expr));
    else if (dynamic_cast<SysProcNode *>(expr.get()) != nullptr)
        //tmp += travExpr(cast_node<SysProcNode>(expr));
	tmp += travExpr(dynamic_pointer_cast<SysProcNode>(expr));
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    return lines;
}

int ASTvis::travExpr(const std::shared_ptr<BinaryExprNode>& expr)
{
    if (expr == nullptr) return 0;
    int tmp = 0, lines = 2;

    of << "child { node {BINARY: ";
    switch (expr->op)
    {
        case BinaryOp::Eq: of << "==";break;
        case BinaryOp::Neq: of << "!=";break;
        case BinaryOp::Leq: of << "<=";break;
        case BinaryOp::Geq: of << ">=";break;
        case BinaryOp::Lt: of << "<";break;
        case BinaryOp::Gt: of << ">";break;
        case BinaryOp::Plus: of << "+";break;
        case BinaryOp::Minus: of << "-";break;
        case BinaryOp::Truediv: of << "/";break;
        case BinaryOp::Div: of << "//";break;
        case BinaryOp::Mod: of << "\\%";break;
        case BinaryOp::Mul: of << "*";break;
        case BinaryOp::Or:  of << "|";break;
        case BinaryOp::And: of << "&";break;
        case BinaryOp::Xor: of << "\\^";break;
        default: of << "ERROR"; break;
    }
    of << "}\n";
    tmp += travExpr(expr->lhs);
    // for (int i=0; i<tmp; ++i) of << texNone;
    // lines += tmp; tmp = 0;
    tmp += travExpr(expr->rhs);
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    of << "}\n";

    return lines;
}
int ASTvis::travExpr(const std::shared_ptr<ConstValueNode>& expr)
{
    if (expr == nullptr) return 0;
    int tmp = 0, lines = 0;
    of << "child { node {Value";
    // tmp = travExpr(p_stmp->expr);
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    of << "}\n}\n";
    return lines;
}
int ASTvis::travExpr(const std::shared_ptr<IdentifierNode>& expr)
{
    if (expr == nullptr) return 0;
    int tmp = 0, lines = 0;
    of << "child { node {ID: " << expr->name;
    // tmp = travExpr(p_stmp->expr);
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    of << "}\n}\n";
    return lines;
}
int ASTvis::travExpr(const std::shared_ptr<ArrayRefNode>& expr)
{
    if (expr == nullptr) return 0;
    int tmp = 0, lines = 0;
    of << "child { node {ARRAY REFERENCE";
    // tmp = travExpr(p_stmp->expr);
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    of << "}\n}\n";
    return lines;
}
int ASTvis::travExpr(const std::shared_ptr<RecordRefNode>& expr)
{
    if (expr == nullptr) return 0;
    int tmp = 0, lines = 0;
    of << "child { node {RECORD REFERENCE";
    // tmp = travExpr(p_stmp->expr);
    for (int i=0; i<tmp; ++i) of << texNone;
    lines += tmp;
    of << "}\n}\n";
    return lines;
}
int ASTvis::travExpr(const std::shared_ptr<ProcNode>& expr)
{
    if (expr == nullptr) return 0;
    int tmp = 0, lines = 0;
    return lines;
}
int ASTvis::travExpr(const std::shared_ptr<CustomProcNode>& expr)
{
    if (expr == nullptr) return 0;
    int tmp = 0, lines = 0;

    of << "child { node {CustomFunc: ";
    of << expr->name->name;
    of << "}\n";
    of << "}\n";
    return lines;
}
int ASTvis::travExpr(const std::shared_ptr<SysProcNode>& expr)
{
    if (expr == nullptr) return 0;
    int tmp = 0, lines = 0;

    of << "child { node {SysFunc: ";
    switch (expr->name)
    {
        case SysFunc::Read:   of << "read()"; break;
        case SysFunc::Write:  of << "write()"; break;
        case SysFunc::Writeln:of << "writeln()";  break;
        case SysFunc::Abs: of << "abs()"; break;
        case SysFunc::Chr: of << "chr()"; break;
        case SysFunc::Odd: of << "odd()"; break;
        case SysFunc::Ord: of << "ord()"; break;
        case SysFunc::Pred: of << "pred()"; break;
        case SysFunc::Sqr: of << "sqr()"; break;
        case SysFunc::Sqrt: of << "sqrt()"; break;
        case SysFunc::Succ: of << "succ()"; break;
    }
    of << "}\n";
    of << "}\n";
    return lines;
}
