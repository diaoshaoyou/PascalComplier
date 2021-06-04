// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hpp"

// User implementation prologue.

#line 51 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:412
// Unqualified %code blocks.
#line 37 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:413

    int yylex(spc::parser::semantic_type* lval, spc::parser::location_type* loc);

#line 57 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:479
namespace spc {
#line 143 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 31: // TO
      case 32: // DOWNTO
      case 99: // direction
        value.copy< spc::ForDirection > (other.value);
        break;

      case 19: // SYS_FUNCT
      case 20: // SYS_PROC
        value.copy< spc::SysFunc > (other.value);
        break;

      case 75: // array_range
        value.copy< std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<ExprNode>> > (other.value);
        break;

      case 78: // field_decl
        value.copy< std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> > (other.value);
        break;

      case 110: // args_list
        value.copy< std::shared_ptr<ArgList> > (other.value);
        break;

      case 73: // array_type_decl
        value.copy< std::shared_ptr<ArrayTypeNode> > (other.value);
        break;

      case 94: // assign_stmt
        value.copy< std::shared_ptr<AssignStmtNode> > (other.value);
        break;

      case 103: // case_expr_list
        value.copy< std::shared_ptr<CaseBranchList> > (other.value);
        break;

      case 104: // case_expr
        value.copy< std::shared_ptr<CaseBranchNode> > (other.value);
        break;

      case 102: // case_stmt
        value.copy< std::shared_ptr<CaseStmtNode> > (other.value);
        break;

      case 16: // CHAR
        value.copy< std::shared_ptr<CharNode> > (other.value);
        break;

      case 90: // routine_body
      case 91: // compound_stmt
      case 92: // stmt_list
      case 93: // stmt
      case 101: // else_clause
        value.copy< std::shared_ptr<CompoundStmtNode> > (other.value);
        break;

      case 65: // const_part
      case 66: // const_expr_list
        value.copy< std::shared_ptr<ConstDeclList> > (other.value);
        break;

      case 18: // SYS_CON
      case 67: // const_value
        value.copy< std::shared_ptr<ConstValueNode> > (other.value);
        break;

      case 105: // expression
      case 106: // expr
      case 107: // term
      case 108: // factor
        value.copy< std::shared_ptr<ExprNode> > (other.value);
        break;

      case 98: // for_stmt
        value.copy< std::shared_ptr<ForStmtNode> > (other.value);
        break;

      case 79: // name_list
      case 89: // var_para_list
        value.copy< std::shared_ptr<IdentifierList> > (other.value);
        break;

      case 4: // ID
        value.copy< std::shared_ptr<IdentifierNode> > (other.value);
        break;

      case 100: // if_stmt
        value.copy< std::shared_ptr<IfStmtNode> > (other.value);
        break;

      case 14: // INTEGER
        value.copy< std::shared_ptr<IntegerNode> > (other.value);
        break;

      case 109: // left_expr
        value.copy< std::shared_ptr<LeftExprNode> > (other.value);
        break;

      case 86: // parameters
      case 87: // para_decl_list
      case 88: // para_type_list
        value.copy< std::shared_ptr<ParamList> > (other.value);
        break;

      case 95: // proc_stmt
        value.copy< std::shared_ptr<ProcStmtNode> > (other.value);
        break;

      case 63: // program
        value.copy< std::shared_ptr<ProgramNode> > (other.value);
        break;

      case 15: // REAL
        value.copy< std::shared_ptr<RealNode> > (other.value);
        break;

      case 76: // record_type_decl
      case 77: // field_decl_list
        value.copy< std::shared_ptr<RecordTypeNode> > (other.value);
        break;

      case 96: // repeat_stmt
        value.copy< std::shared_ptr<RepeatStmtNode> > (other.value);
        break;

      case 64: // routine_head
        value.copy< std::shared_ptr<RoutineHeadNode> > (other.value);
        break;

      case 83: // routine_part
        value.copy< std::shared_ptr<RoutineList> > (other.value);
        break;

      case 84: // function_decl
      case 85: // procedure_decl
        value.copy< std::shared_ptr<RoutineNode> > (other.value);
        break;

      case 21: // SYS_TYPE
        value.copy< std::shared_ptr<SimpleTypeNode> > (other.value);
        break;

      case 17: // STRING
        value.copy< std::shared_ptr<StringNode> > (other.value);
        break;

      case 74: // string_type_decl
        value.copy< std::shared_ptr<StringTypeNode> > (other.value);
        break;

      case 68: // type_part
      case 69: // type_decl_list
        value.copy< std::shared_ptr<TypeDeclList> > (other.value);
        break;

      case 70: // type_definition
        value.copy< std::shared_ptr<TypeDeclNode> > (other.value);
        break;

      case 71: // type_decl
      case 72: // simple_type_decl
        value.copy< std::shared_ptr<TypeNode> > (other.value);
        break;

      case 80: // var_part
      case 81: // var_decl_list
      case 82: // var_decl
        value.copy< std::shared_ptr<VarDeclList> > (other.value);
        break;

      case 97: // while_stmt
        value.copy< std::shared_ptr<WhileStmtNode> > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 31: // TO
      case 32: // DOWNTO
      case 99: // direction
        value.copy< spc::ForDirection > (v);
        break;

      case 19: // SYS_FUNCT
      case 20: // SYS_PROC
        value.copy< spc::SysFunc > (v);
        break;

      case 75: // array_range
        value.copy< std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<ExprNode>> > (v);
        break;

      case 78: // field_decl
        value.copy< std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> > (v);
        break;

      case 110: // args_list
        value.copy< std::shared_ptr<ArgList> > (v);
        break;

      case 73: // array_type_decl
        value.copy< std::shared_ptr<ArrayTypeNode> > (v);
        break;

      case 94: // assign_stmt
        value.copy< std::shared_ptr<AssignStmtNode> > (v);
        break;

      case 103: // case_expr_list
        value.copy< std::shared_ptr<CaseBranchList> > (v);
        break;

      case 104: // case_expr
        value.copy< std::shared_ptr<CaseBranchNode> > (v);
        break;

      case 102: // case_stmt
        value.copy< std::shared_ptr<CaseStmtNode> > (v);
        break;

      case 16: // CHAR
        value.copy< std::shared_ptr<CharNode> > (v);
        break;

      case 90: // routine_body
      case 91: // compound_stmt
      case 92: // stmt_list
      case 93: // stmt
      case 101: // else_clause
        value.copy< std::shared_ptr<CompoundStmtNode> > (v);
        break;

      case 65: // const_part
      case 66: // const_expr_list
        value.copy< std::shared_ptr<ConstDeclList> > (v);
        break;

      case 18: // SYS_CON
      case 67: // const_value
        value.copy< std::shared_ptr<ConstValueNode> > (v);
        break;

      case 105: // expression
      case 106: // expr
      case 107: // term
      case 108: // factor
        value.copy< std::shared_ptr<ExprNode> > (v);
        break;

      case 98: // for_stmt
        value.copy< std::shared_ptr<ForStmtNode> > (v);
        break;

      case 79: // name_list
      case 89: // var_para_list
        value.copy< std::shared_ptr<IdentifierList> > (v);
        break;

      case 4: // ID
        value.copy< std::shared_ptr<IdentifierNode> > (v);
        break;

      case 100: // if_stmt
        value.copy< std::shared_ptr<IfStmtNode> > (v);
        break;

      case 14: // INTEGER
        value.copy< std::shared_ptr<IntegerNode> > (v);
        break;

      case 109: // left_expr
        value.copy< std::shared_ptr<LeftExprNode> > (v);
        break;

      case 86: // parameters
      case 87: // para_decl_list
      case 88: // para_type_list
        value.copy< std::shared_ptr<ParamList> > (v);
        break;

      case 95: // proc_stmt
        value.copy< std::shared_ptr<ProcStmtNode> > (v);
        break;

      case 63: // program
        value.copy< std::shared_ptr<ProgramNode> > (v);
        break;

      case 15: // REAL
        value.copy< std::shared_ptr<RealNode> > (v);
        break;

      case 76: // record_type_decl
      case 77: // field_decl_list
        value.copy< std::shared_ptr<RecordTypeNode> > (v);
        break;

      case 96: // repeat_stmt
        value.copy< std::shared_ptr<RepeatStmtNode> > (v);
        break;

      case 64: // routine_head
        value.copy< std::shared_ptr<RoutineHeadNode> > (v);
        break;

      case 83: // routine_part
        value.copy< std::shared_ptr<RoutineList> > (v);
        break;

      case 84: // function_decl
      case 85: // procedure_decl
        value.copy< std::shared_ptr<RoutineNode> > (v);
        break;

      case 21: // SYS_TYPE
        value.copy< std::shared_ptr<SimpleTypeNode> > (v);
        break;

      case 17: // STRING
        value.copy< std::shared_ptr<StringNode> > (v);
        break;

      case 74: // string_type_decl
        value.copy< std::shared_ptr<StringTypeNode> > (v);
        break;

      case 68: // type_part
      case 69: // type_decl_list
        value.copy< std::shared_ptr<TypeDeclList> > (v);
        break;

      case 70: // type_definition
        value.copy< std::shared_ptr<TypeDeclNode> > (v);
        break;

      case 71: // type_decl
      case 72: // simple_type_decl
        value.copy< std::shared_ptr<TypeNode> > (v);
        break;

      case 80: // var_part
      case 81: // var_decl_list
      case 82: // var_decl
        value.copy< std::shared_ptr<VarDeclList> > (v);
        break;

      case 97: // while_stmt
        value.copy< std::shared_ptr<WhileStmtNode> > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const spc::ForDirection v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const spc::SysFunc v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<ExprNode>> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ArgList> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ArrayTypeNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<AssignStmtNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<CaseBranchList> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<CaseBranchNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<CaseStmtNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<CharNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<CompoundStmtNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ConstDeclList> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ConstValueNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ExprNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ForStmtNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<IdentifierList> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<IdentifierNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<IfStmtNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<IntegerNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<LeftExprNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ParamList> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ProcStmtNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ProgramNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<RealNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<RecordTypeNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<RepeatStmtNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<RoutineHeadNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<RoutineList> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<RoutineNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<SimpleTypeNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<StringNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<StringTypeNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<TypeDeclList> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<TypeDeclNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<TypeNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<VarDeclList> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<WhileStmtNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 31: // TO
      case 32: // DOWNTO
      case 99: // direction
        value.template destroy< spc::ForDirection > ();
        break;

      case 19: // SYS_FUNCT
      case 20: // SYS_PROC
        value.template destroy< spc::SysFunc > ();
        break;

      case 75: // array_range
        value.template destroy< std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<ExprNode>> > ();
        break;

      case 78: // field_decl
        value.template destroy< std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> > ();
        break;

      case 110: // args_list
        value.template destroy< std::shared_ptr<ArgList> > ();
        break;

      case 73: // array_type_decl
        value.template destroy< std::shared_ptr<ArrayTypeNode> > ();
        break;

      case 94: // assign_stmt
        value.template destroy< std::shared_ptr<AssignStmtNode> > ();
        break;

      case 103: // case_expr_list
        value.template destroy< std::shared_ptr<CaseBranchList> > ();
        break;

      case 104: // case_expr
        value.template destroy< std::shared_ptr<CaseBranchNode> > ();
        break;

      case 102: // case_stmt
        value.template destroy< std::shared_ptr<CaseStmtNode> > ();
        break;

      case 16: // CHAR
        value.template destroy< std::shared_ptr<CharNode> > ();
        break;

      case 90: // routine_body
      case 91: // compound_stmt
      case 92: // stmt_list
      case 93: // stmt
      case 101: // else_clause
        value.template destroy< std::shared_ptr<CompoundStmtNode> > ();
        break;

      case 65: // const_part
      case 66: // const_expr_list
        value.template destroy< std::shared_ptr<ConstDeclList> > ();
        break;

      case 18: // SYS_CON
      case 67: // const_value
        value.template destroy< std::shared_ptr<ConstValueNode> > ();
        break;

      case 105: // expression
      case 106: // expr
      case 107: // term
      case 108: // factor
        value.template destroy< std::shared_ptr<ExprNode> > ();
        break;

      case 98: // for_stmt
        value.template destroy< std::shared_ptr<ForStmtNode> > ();
        break;

      case 79: // name_list
      case 89: // var_para_list
        value.template destroy< std::shared_ptr<IdentifierList> > ();
        break;

      case 4: // ID
        value.template destroy< std::shared_ptr<IdentifierNode> > ();
        break;

      case 100: // if_stmt
        value.template destroy< std::shared_ptr<IfStmtNode> > ();
        break;

      case 14: // INTEGER
        value.template destroy< std::shared_ptr<IntegerNode> > ();
        break;

      case 109: // left_expr
        value.template destroy< std::shared_ptr<LeftExprNode> > ();
        break;

      case 86: // parameters
      case 87: // para_decl_list
      case 88: // para_type_list
        value.template destroy< std::shared_ptr<ParamList> > ();
        break;

      case 95: // proc_stmt
        value.template destroy< std::shared_ptr<ProcStmtNode> > ();
        break;

      case 63: // program
        value.template destroy< std::shared_ptr<ProgramNode> > ();
        break;

      case 15: // REAL
        value.template destroy< std::shared_ptr<RealNode> > ();
        break;

      case 76: // record_type_decl
      case 77: // field_decl_list
        value.template destroy< std::shared_ptr<RecordTypeNode> > ();
        break;

      case 96: // repeat_stmt
        value.template destroy< std::shared_ptr<RepeatStmtNode> > ();
        break;

      case 64: // routine_head
        value.template destroy< std::shared_ptr<RoutineHeadNode> > ();
        break;

      case 83: // routine_part
        value.template destroy< std::shared_ptr<RoutineList> > ();
        break;

      case 84: // function_decl
      case 85: // procedure_decl
        value.template destroy< std::shared_ptr<RoutineNode> > ();
        break;

      case 21: // SYS_TYPE
        value.template destroy< std::shared_ptr<SimpleTypeNode> > ();
        break;

      case 17: // STRING
        value.template destroy< std::shared_ptr<StringNode> > ();
        break;

      case 74: // string_type_decl
        value.template destroy< std::shared_ptr<StringTypeNode> > ();
        break;

      case 68: // type_part
      case 69: // type_decl_list
        value.template destroy< std::shared_ptr<TypeDeclList> > ();
        break;

      case 70: // type_definition
        value.template destroy< std::shared_ptr<TypeDeclNode> > ();
        break;

      case 71: // type_decl
      case 72: // simple_type_decl
        value.template destroy< std::shared_ptr<TypeNode> > ();
        break;

      case 80: // var_part
      case 81: // var_decl_list
      case 82: // var_decl
        value.template destroy< std::shared_ptr<VarDeclList> > ();
        break;

      case 97: // while_stmt
        value.template destroy< std::shared_ptr<WhileStmtNode> > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 31: // TO
      case 32: // DOWNTO
      case 99: // direction
        value.move< spc::ForDirection > (s.value);
        break;

      case 19: // SYS_FUNCT
      case 20: // SYS_PROC
        value.move< spc::SysFunc > (s.value);
        break;

      case 75: // array_range
        value.move< std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<ExprNode>> > (s.value);
        break;

      case 78: // field_decl
        value.move< std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> > (s.value);
        break;

      case 110: // args_list
        value.move< std::shared_ptr<ArgList> > (s.value);
        break;

      case 73: // array_type_decl
        value.move< std::shared_ptr<ArrayTypeNode> > (s.value);
        break;

      case 94: // assign_stmt
        value.move< std::shared_ptr<AssignStmtNode> > (s.value);
        break;

      case 103: // case_expr_list
        value.move< std::shared_ptr<CaseBranchList> > (s.value);
        break;

      case 104: // case_expr
        value.move< std::shared_ptr<CaseBranchNode> > (s.value);
        break;

      case 102: // case_stmt
        value.move< std::shared_ptr<CaseStmtNode> > (s.value);
        break;

      case 16: // CHAR
        value.move< std::shared_ptr<CharNode> > (s.value);
        break;

      case 90: // routine_body
      case 91: // compound_stmt
      case 92: // stmt_list
      case 93: // stmt
      case 101: // else_clause
        value.move< std::shared_ptr<CompoundStmtNode> > (s.value);
        break;

      case 65: // const_part
      case 66: // const_expr_list
        value.move< std::shared_ptr<ConstDeclList> > (s.value);
        break;

      case 18: // SYS_CON
      case 67: // const_value
        value.move< std::shared_ptr<ConstValueNode> > (s.value);
        break;

      case 105: // expression
      case 106: // expr
      case 107: // term
      case 108: // factor
        value.move< std::shared_ptr<ExprNode> > (s.value);
        break;

      case 98: // for_stmt
        value.move< std::shared_ptr<ForStmtNode> > (s.value);
        break;

      case 79: // name_list
      case 89: // var_para_list
        value.move< std::shared_ptr<IdentifierList> > (s.value);
        break;

      case 4: // ID
        value.move< std::shared_ptr<IdentifierNode> > (s.value);
        break;

      case 100: // if_stmt
        value.move< std::shared_ptr<IfStmtNode> > (s.value);
        break;

      case 14: // INTEGER
        value.move< std::shared_ptr<IntegerNode> > (s.value);
        break;

      case 109: // left_expr
        value.move< std::shared_ptr<LeftExprNode> > (s.value);
        break;

      case 86: // parameters
      case 87: // para_decl_list
      case 88: // para_type_list
        value.move< std::shared_ptr<ParamList> > (s.value);
        break;

      case 95: // proc_stmt
        value.move< std::shared_ptr<ProcStmtNode> > (s.value);
        break;

      case 63: // program
        value.move< std::shared_ptr<ProgramNode> > (s.value);
        break;

      case 15: // REAL
        value.move< std::shared_ptr<RealNode> > (s.value);
        break;

      case 76: // record_type_decl
      case 77: // field_decl_list
        value.move< std::shared_ptr<RecordTypeNode> > (s.value);
        break;

      case 96: // repeat_stmt
        value.move< std::shared_ptr<RepeatStmtNode> > (s.value);
        break;

      case 64: // routine_head
        value.move< std::shared_ptr<RoutineHeadNode> > (s.value);
        break;

      case 83: // routine_part
        value.move< std::shared_ptr<RoutineList> > (s.value);
        break;

      case 84: // function_decl
      case 85: // procedure_decl
        value.move< std::shared_ptr<RoutineNode> > (s.value);
        break;

      case 21: // SYS_TYPE
        value.move< std::shared_ptr<SimpleTypeNode> > (s.value);
        break;

      case 17: // STRING
        value.move< std::shared_ptr<StringNode> > (s.value);
        break;

      case 74: // string_type_decl
        value.move< std::shared_ptr<StringTypeNode> > (s.value);
        break;

      case 68: // type_part
      case 69: // type_decl_list
        value.move< std::shared_ptr<TypeDeclList> > (s.value);
        break;

      case 70: // type_definition
        value.move< std::shared_ptr<TypeDeclNode> > (s.value);
        break;

      case 71: // type_decl
      case 72: // simple_type_decl
        value.move< std::shared_ptr<TypeNode> > (s.value);
        break;

      case 80: // var_part
      case 81: // var_decl_list
      case 82: // var_decl
        value.move< std::shared_ptr<VarDeclList> > (s.value);
        break;

      case 97: // while_stmt
        value.move< std::shared_ptr<WhileStmtNode> > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  parser::symbol_type
  parser::make_PROGRAM (const location_type& l)
  {
    return symbol_type (token::PROGRAM, l);
  }

  parser::symbol_type
  parser::make_ID (const std::shared_ptr<IdentifierNode>& v, const location_type& l)
  {
    return symbol_type (token::ID, v, l);
  }

  parser::symbol_type
  parser::make_CONST (const location_type& l)
  {
    return symbol_type (token::CONST, l);
  }

  parser::symbol_type
  parser::make_ARRAY (const location_type& l)
  {
    return symbol_type (token::ARRAY, l);
  }

  parser::symbol_type
  parser::make_VAR (const location_type& l)
  {
    return symbol_type (token::VAR, l);
  }

  parser::symbol_type
  parser::make_FUNCTION (const location_type& l)
  {
    return symbol_type (token::FUNCTION, l);
  }

  parser::symbol_type
  parser::make_PROCEDURE (const location_type& l)
  {
    return symbol_type (token::PROCEDURE, l);
  }

  parser::symbol_type
  parser::make_PBEGIN (const location_type& l)
  {
    return symbol_type (token::PBEGIN, l);
  }

  parser::symbol_type
  parser::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

  parser::symbol_type
  parser::make_TYPE (const location_type& l)
  {
    return symbol_type (token::TYPE, l);
  }

  parser::symbol_type
  parser::make_RECORD (const location_type& l)
  {
    return symbol_type (token::RECORD, l);
  }

  parser::symbol_type
  parser::make_INTEGER (const std::shared_ptr<IntegerNode>& v, const location_type& l)
  {
    return symbol_type (token::INTEGER, v, l);
  }

  parser::symbol_type
  parser::make_REAL (const std::shared_ptr<RealNode>& v, const location_type& l)
  {
    return symbol_type (token::REAL, v, l);
  }

  parser::symbol_type
  parser::make_CHAR (const std::shared_ptr<CharNode>& v, const location_type& l)
  {
    return symbol_type (token::CHAR, v, l);
  }

  parser::symbol_type
  parser::make_STRING (const std::shared_ptr<StringNode>& v, const location_type& l)
  {
    return symbol_type (token::STRING, v, l);
  }

  parser::symbol_type
  parser::make_SYS_CON (const std::shared_ptr<ConstValueNode>& v, const location_type& l)
  {
    return symbol_type (token::SYS_CON, v, l);
  }

  parser::symbol_type
  parser::make_SYS_FUNCT (const spc::SysFunc& v, const location_type& l)
  {
    return symbol_type (token::SYS_FUNCT, v, l);
  }

  parser::symbol_type
  parser::make_SYS_PROC (const spc::SysFunc& v, const location_type& l)
  {
    return symbol_type (token::SYS_PROC, v, l);
  }

  parser::symbol_type
  parser::make_SYS_TYPE (const std::shared_ptr<SimpleTypeNode>& v, const location_type& l)
  {
    return symbol_type (token::SYS_TYPE, v, l);
  }

  parser::symbol_type
  parser::make_STR_TYPE (const location_type& l)
  {
    return symbol_type (token::STR_TYPE, l);
  }

  parser::symbol_type
  parser::make_IF (const location_type& l)
  {
    return symbol_type (token::IF, l);
  }

  parser::symbol_type
  parser::make_THEN (const location_type& l)
  {
    return symbol_type (token::THEN, l);
  }

  parser::symbol_type
  parser::make_ELSE (const location_type& l)
  {
    return symbol_type (token::ELSE, l);
  }

  parser::symbol_type
  parser::make_REPEAT (const location_type& l)
  {
    return symbol_type (token::REPEAT, l);
  }

  parser::symbol_type
  parser::make_UNTIL (const location_type& l)
  {
    return symbol_type (token::UNTIL, l);
  }

  parser::symbol_type
  parser::make_WHILE (const location_type& l)
  {
    return symbol_type (token::WHILE, l);
  }

  parser::symbol_type
  parser::make_DO (const location_type& l)
  {
    return symbol_type (token::DO, l);
  }

  parser::symbol_type
  parser::make_FOR (const location_type& l)
  {
    return symbol_type (token::FOR, l);
  }

  parser::symbol_type
  parser::make_TO (const spc::ForDirection& v, const location_type& l)
  {
    return symbol_type (token::TO, v, l);
  }

  parser::symbol_type
  parser::make_DOWNTO (const spc::ForDirection& v, const location_type& l)
  {
    return symbol_type (token::DOWNTO, v, l);
  }

  parser::symbol_type
  parser::make_CASE (const location_type& l)
  {
    return symbol_type (token::CASE, l);
  }

  parser::symbol_type
  parser::make_OF (const location_type& l)
  {
    return symbol_type (token::OF, l);
  }

  parser::symbol_type
  parser::make_GOTO (const location_type& l)
  {
    return symbol_type (token::GOTO, l);
  }

  parser::symbol_type
  parser::make_ASSIGN (const location_type& l)
  {
    return symbol_type (token::ASSIGN, l);
  }

  parser::symbol_type
  parser::make_EQUAL (const location_type& l)
  {
    return symbol_type (token::EQUAL, l);
  }

  parser::symbol_type
  parser::make_UNEQUAL (const location_type& l)
  {
    return symbol_type (token::UNEQUAL, l);
  }

  parser::symbol_type
  parser::make_LE (const location_type& l)
  {
    return symbol_type (token::LE, l);
  }

  parser::symbol_type
  parser::make_LT (const location_type& l)
  {
    return symbol_type (token::LT, l);
  }

  parser::symbol_type
  parser::make_GE (const location_type& l)
  {
    return symbol_type (token::GE, l);
  }

  parser::symbol_type
  parser::make_GT (const location_type& l)
  {
    return symbol_type (token::GT, l);
  }

  parser::symbol_type
  parser::make_PLUS (const location_type& l)
  {
    return symbol_type (token::PLUS, l);
  }

  parser::symbol_type
  parser::make_MINUS (const location_type& l)
  {
    return symbol_type (token::MINUS, l);
  }

  parser::symbol_type
  parser::make_MUL (const location_type& l)
  {
    return symbol_type (token::MUL, l);
  }

  parser::symbol_type
  parser::make_DIV (const location_type& l)
  {
    return symbol_type (token::DIV, l);
  }

  parser::symbol_type
  parser::make_MOD (const location_type& l)
  {
    return symbol_type (token::MOD, l);
  }

  parser::symbol_type
  parser::make_TRUEDIV (const location_type& l)
  {
    return symbol_type (token::TRUEDIV, l);
  }

  parser::symbol_type
  parser::make_AND (const location_type& l)
  {
    return symbol_type (token::AND, l);
  }

  parser::symbol_type
  parser::make_OR (const location_type& l)
  {
    return symbol_type (token::OR, l);
  }

  parser::symbol_type
  parser::make_XOR (const location_type& l)
  {
    return symbol_type (token::XOR, l);
  }

  parser::symbol_type
  parser::make_NOT (const location_type& l)
  {
    return symbol_type (token::NOT, l);
  }

  parser::symbol_type
  parser::make_DOT (const location_type& l)
  {
    return symbol_type (token::DOT, l);
  }

  parser::symbol_type
  parser::make_DOTDOT (const location_type& l)
  {
    return symbol_type (token::DOTDOT, l);
  }

  parser::symbol_type
  parser::make_SEMI (const location_type& l)
  {
    return symbol_type (token::SEMI, l);
  }

  parser::symbol_type
  parser::make_LP (const location_type& l)
  {
    return symbol_type (token::LP, l);
  }

  parser::symbol_type
  parser::make_RP (const location_type& l)
  {
    return symbol_type (token::RP, l);
  }

  parser::symbol_type
  parser::make_LB (const location_type& l)
  {
    return symbol_type (token::LB, l);
  }

  parser::symbol_type
  parser::make_RB (const location_type& l)
  {
    return symbol_type (token::RB, l);
  }

  parser::symbol_type
  parser::make_COMMA (const location_type& l)
  {
    return symbol_type (token::COMMA, l);
  }

  parser::symbol_type
  parser::make_COLON (const location_type& l)
  {
    return symbol_type (token::COLON, l);
  }



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 31: // TO
      case 32: // DOWNTO
      case 99: // direction
        value.move< spc::ForDirection > (that.value);
        break;

      case 19: // SYS_FUNCT
      case 20: // SYS_PROC
        value.move< spc::SysFunc > (that.value);
        break;

      case 75: // array_range
        value.move< std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<ExprNode>> > (that.value);
        break;

      case 78: // field_decl
        value.move< std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> > (that.value);
        break;

      case 110: // args_list
        value.move< std::shared_ptr<ArgList> > (that.value);
        break;

      case 73: // array_type_decl
        value.move< std::shared_ptr<ArrayTypeNode> > (that.value);
        break;

      case 94: // assign_stmt
        value.move< std::shared_ptr<AssignStmtNode> > (that.value);
        break;

      case 103: // case_expr_list
        value.move< std::shared_ptr<CaseBranchList> > (that.value);
        break;

      case 104: // case_expr
        value.move< std::shared_ptr<CaseBranchNode> > (that.value);
        break;

      case 102: // case_stmt
        value.move< std::shared_ptr<CaseStmtNode> > (that.value);
        break;

      case 16: // CHAR
        value.move< std::shared_ptr<CharNode> > (that.value);
        break;

      case 90: // routine_body
      case 91: // compound_stmt
      case 92: // stmt_list
      case 93: // stmt
      case 101: // else_clause
        value.move< std::shared_ptr<CompoundStmtNode> > (that.value);
        break;

      case 65: // const_part
      case 66: // const_expr_list
        value.move< std::shared_ptr<ConstDeclList> > (that.value);
        break;

      case 18: // SYS_CON
      case 67: // const_value
        value.move< std::shared_ptr<ConstValueNode> > (that.value);
        break;

      case 105: // expression
      case 106: // expr
      case 107: // term
      case 108: // factor
        value.move< std::shared_ptr<ExprNode> > (that.value);
        break;

      case 98: // for_stmt
        value.move< std::shared_ptr<ForStmtNode> > (that.value);
        break;

      case 79: // name_list
      case 89: // var_para_list
        value.move< std::shared_ptr<IdentifierList> > (that.value);
        break;

      case 4: // ID
        value.move< std::shared_ptr<IdentifierNode> > (that.value);
        break;

      case 100: // if_stmt
        value.move< std::shared_ptr<IfStmtNode> > (that.value);
        break;

      case 14: // INTEGER
        value.move< std::shared_ptr<IntegerNode> > (that.value);
        break;

      case 109: // left_expr
        value.move< std::shared_ptr<LeftExprNode> > (that.value);
        break;

      case 86: // parameters
      case 87: // para_decl_list
      case 88: // para_type_list
        value.move< std::shared_ptr<ParamList> > (that.value);
        break;

      case 95: // proc_stmt
        value.move< std::shared_ptr<ProcStmtNode> > (that.value);
        break;

      case 63: // program
        value.move< std::shared_ptr<ProgramNode> > (that.value);
        break;

      case 15: // REAL
        value.move< std::shared_ptr<RealNode> > (that.value);
        break;

      case 76: // record_type_decl
      case 77: // field_decl_list
        value.move< std::shared_ptr<RecordTypeNode> > (that.value);
        break;

      case 96: // repeat_stmt
        value.move< std::shared_ptr<RepeatStmtNode> > (that.value);
        break;

      case 64: // routine_head
        value.move< std::shared_ptr<RoutineHeadNode> > (that.value);
        break;

      case 83: // routine_part
        value.move< std::shared_ptr<RoutineList> > (that.value);
        break;

      case 84: // function_decl
      case 85: // procedure_decl
        value.move< std::shared_ptr<RoutineNode> > (that.value);
        break;

      case 21: // SYS_TYPE
        value.move< std::shared_ptr<SimpleTypeNode> > (that.value);
        break;

      case 17: // STRING
        value.move< std::shared_ptr<StringNode> > (that.value);
        break;

      case 74: // string_type_decl
        value.move< std::shared_ptr<StringTypeNode> > (that.value);
        break;

      case 68: // type_part
      case 69: // type_decl_list
        value.move< std::shared_ptr<TypeDeclList> > (that.value);
        break;

      case 70: // type_definition
        value.move< std::shared_ptr<TypeDeclNode> > (that.value);
        break;

      case 71: // type_decl
      case 72: // simple_type_decl
        value.move< std::shared_ptr<TypeNode> > (that.value);
        break;

      case 80: // var_part
      case 81: // var_decl_list
      case 82: // var_decl
        value.move< std::shared_ptr<VarDeclList> > (that.value);
        break;

      case 97: // while_stmt
        value.move< std::shared_ptr<WhileStmtNode> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 31: // TO
      case 32: // DOWNTO
      case 99: // direction
        value.copy< spc::ForDirection > (that.value);
        break;

      case 19: // SYS_FUNCT
      case 20: // SYS_PROC
        value.copy< spc::SysFunc > (that.value);
        break;

      case 75: // array_range
        value.copy< std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<ExprNode>> > (that.value);
        break;

      case 78: // field_decl
        value.copy< std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> > (that.value);
        break;

      case 110: // args_list
        value.copy< std::shared_ptr<ArgList> > (that.value);
        break;

      case 73: // array_type_decl
        value.copy< std::shared_ptr<ArrayTypeNode> > (that.value);
        break;

      case 94: // assign_stmt
        value.copy< std::shared_ptr<AssignStmtNode> > (that.value);
        break;

      case 103: // case_expr_list
        value.copy< std::shared_ptr<CaseBranchList> > (that.value);
        break;

      case 104: // case_expr
        value.copy< std::shared_ptr<CaseBranchNode> > (that.value);
        break;

      case 102: // case_stmt
        value.copy< std::shared_ptr<CaseStmtNode> > (that.value);
        break;

      case 16: // CHAR
        value.copy< std::shared_ptr<CharNode> > (that.value);
        break;

      case 90: // routine_body
      case 91: // compound_stmt
      case 92: // stmt_list
      case 93: // stmt
      case 101: // else_clause
        value.copy< std::shared_ptr<CompoundStmtNode> > (that.value);
        break;

      case 65: // const_part
      case 66: // const_expr_list
        value.copy< std::shared_ptr<ConstDeclList> > (that.value);
        break;

      case 18: // SYS_CON
      case 67: // const_value
        value.copy< std::shared_ptr<ConstValueNode> > (that.value);
        break;

      case 105: // expression
      case 106: // expr
      case 107: // term
      case 108: // factor
        value.copy< std::shared_ptr<ExprNode> > (that.value);
        break;

      case 98: // for_stmt
        value.copy< std::shared_ptr<ForStmtNode> > (that.value);
        break;

      case 79: // name_list
      case 89: // var_para_list
        value.copy< std::shared_ptr<IdentifierList> > (that.value);
        break;

      case 4: // ID
        value.copy< std::shared_ptr<IdentifierNode> > (that.value);
        break;

      case 100: // if_stmt
        value.copy< std::shared_ptr<IfStmtNode> > (that.value);
        break;

      case 14: // INTEGER
        value.copy< std::shared_ptr<IntegerNode> > (that.value);
        break;

      case 109: // left_expr
        value.copy< std::shared_ptr<LeftExprNode> > (that.value);
        break;

      case 86: // parameters
      case 87: // para_decl_list
      case 88: // para_type_list
        value.copy< std::shared_ptr<ParamList> > (that.value);
        break;

      case 95: // proc_stmt
        value.copy< std::shared_ptr<ProcStmtNode> > (that.value);
        break;

      case 63: // program
        value.copy< std::shared_ptr<ProgramNode> > (that.value);
        break;

      case 15: // REAL
        value.copy< std::shared_ptr<RealNode> > (that.value);
        break;

      case 76: // record_type_decl
      case 77: // field_decl_list
        value.copy< std::shared_ptr<RecordTypeNode> > (that.value);
        break;

      case 96: // repeat_stmt
        value.copy< std::shared_ptr<RepeatStmtNode> > (that.value);
        break;

      case 64: // routine_head
        value.copy< std::shared_ptr<RoutineHeadNode> > (that.value);
        break;

      case 83: // routine_part
        value.copy< std::shared_ptr<RoutineList> > (that.value);
        break;

      case 84: // function_decl
      case 85: // procedure_decl
        value.copy< std::shared_ptr<RoutineNode> > (that.value);
        break;

      case 21: // SYS_TYPE
        value.copy< std::shared_ptr<SimpleTypeNode> > (that.value);
        break;

      case 17: // STRING
        value.copy< std::shared_ptr<StringNode> > (that.value);
        break;

      case 74: // string_type_decl
        value.copy< std::shared_ptr<StringTypeNode> > (that.value);
        break;

      case 68: // type_part
      case 69: // type_decl_list
        value.copy< std::shared_ptr<TypeDeclList> > (that.value);
        break;

      case 70: // type_definition
        value.copy< std::shared_ptr<TypeDeclNode> > (that.value);
        break;

      case 71: // type_decl
      case 72: // simple_type_decl
        value.copy< std::shared_ptr<TypeNode> > (that.value);
        break;

      case 80: // var_part
      case 81: // var_decl_list
      case 82: // var_decl
        value.copy< std::shared_ptr<VarDeclList> > (that.value);
        break;

      case 97: // while_stmt
        value.copy< std::shared_ptr<WhileStmtNode> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 31: // TO
      case 32: // DOWNTO
      case 99: // direction
        yylhs.value.build< spc::ForDirection > ();
        break;

      case 19: // SYS_FUNCT
      case 20: // SYS_PROC
        yylhs.value.build< spc::SysFunc > ();
        break;

      case 75: // array_range
        yylhs.value.build< std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<ExprNode>> > ();
        break;

      case 78: // field_decl
        yylhs.value.build< std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> > ();
        break;

      case 110: // args_list
        yylhs.value.build< std::shared_ptr<ArgList> > ();
        break;

      case 73: // array_type_decl
        yylhs.value.build< std::shared_ptr<ArrayTypeNode> > ();
        break;

      case 94: // assign_stmt
        yylhs.value.build< std::shared_ptr<AssignStmtNode> > ();
        break;

      case 103: // case_expr_list
        yylhs.value.build< std::shared_ptr<CaseBranchList> > ();
        break;

      case 104: // case_expr
        yylhs.value.build< std::shared_ptr<CaseBranchNode> > ();
        break;

      case 102: // case_stmt
        yylhs.value.build< std::shared_ptr<CaseStmtNode> > ();
        break;

      case 16: // CHAR
        yylhs.value.build< std::shared_ptr<CharNode> > ();
        break;

      case 90: // routine_body
      case 91: // compound_stmt
      case 92: // stmt_list
      case 93: // stmt
      case 101: // else_clause
        yylhs.value.build< std::shared_ptr<CompoundStmtNode> > ();
        break;

      case 65: // const_part
      case 66: // const_expr_list
        yylhs.value.build< std::shared_ptr<ConstDeclList> > ();
        break;

      case 18: // SYS_CON
      case 67: // const_value
        yylhs.value.build< std::shared_ptr<ConstValueNode> > ();
        break;

      case 105: // expression
      case 106: // expr
      case 107: // term
      case 108: // factor
        yylhs.value.build< std::shared_ptr<ExprNode> > ();
        break;

      case 98: // for_stmt
        yylhs.value.build< std::shared_ptr<ForStmtNode> > ();
        break;

      case 79: // name_list
      case 89: // var_para_list
        yylhs.value.build< std::shared_ptr<IdentifierList> > ();
        break;

      case 4: // ID
        yylhs.value.build< std::shared_ptr<IdentifierNode> > ();
        break;

      case 100: // if_stmt
        yylhs.value.build< std::shared_ptr<IfStmtNode> > ();
        break;

      case 14: // INTEGER
        yylhs.value.build< std::shared_ptr<IntegerNode> > ();
        break;

      case 109: // left_expr
        yylhs.value.build< std::shared_ptr<LeftExprNode> > ();
        break;

      case 86: // parameters
      case 87: // para_decl_list
      case 88: // para_type_list
        yylhs.value.build< std::shared_ptr<ParamList> > ();
        break;

      case 95: // proc_stmt
        yylhs.value.build< std::shared_ptr<ProcStmtNode> > ();
        break;

      case 63: // program
        yylhs.value.build< std::shared_ptr<ProgramNode> > ();
        break;

      case 15: // REAL
        yylhs.value.build< std::shared_ptr<RealNode> > ();
        break;

      case 76: // record_type_decl
      case 77: // field_decl_list
        yylhs.value.build< std::shared_ptr<RecordTypeNode> > ();
        break;

      case 96: // repeat_stmt
        yylhs.value.build< std::shared_ptr<RepeatStmtNode> > ();
        break;

      case 64: // routine_head
        yylhs.value.build< std::shared_ptr<RoutineHeadNode> > ();
        break;

      case 83: // routine_part
        yylhs.value.build< std::shared_ptr<RoutineList> > ();
        break;

      case 84: // function_decl
      case 85: // procedure_decl
        yylhs.value.build< std::shared_ptr<RoutineNode> > ();
        break;

      case 21: // SYS_TYPE
        yylhs.value.build< std::shared_ptr<SimpleTypeNode> > ();
        break;

      case 17: // STRING
        yylhs.value.build< std::shared_ptr<StringNode> > ();
        break;

      case 74: // string_type_decl
        yylhs.value.build< std::shared_ptr<StringTypeNode> > ();
        break;

      case 68: // type_part
      case 69: // type_decl_list
        yylhs.value.build< std::shared_ptr<TypeDeclList> > ();
        break;

      case 70: // type_definition
        yylhs.value.build< std::shared_ptr<TypeDeclNode> > ();
        break;

      case 71: // type_decl
      case 72: // simple_type_decl
        yylhs.value.build< std::shared_ptr<TypeNode> > ();
        break;

      case 80: // var_part
      case 81: // var_decl_list
      case 82: // var_decl
        yylhs.value.build< std::shared_ptr<VarDeclList> > ();
        break;

      case 97: // while_stmt
        yylhs.value.build< std::shared_ptr<WhileStmtNode> > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 100 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        program = make_node<ProgramNode>(yystack_[4].value.as< std::shared_ptr<IdentifierNode> > (), yystack_[2].value.as< std::shared_ptr<RoutineHeadNode> > (), yystack_[1].value.as< std::shared_ptr<CompoundStmtNode> > ());
    }
#line 2496 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 3:
#line 105 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<RoutineHeadNode> > () = make_node<RoutineHeadNode>(yystack_[3].value.as< std::shared_ptr<ConstDeclList> > (), yystack_[1].value.as< std::shared_ptr<VarDeclList> > (), yystack_[2].value.as< std::shared_ptr<TypeDeclList> > (), yystack_[0].value.as< std::shared_ptr<RoutineList> > ());
    }
#line 2504 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 110 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ConstDeclList> > ()=yystack_[0].value.as< std::shared_ptr<ConstDeclList> > (); }
#line 2510 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 5:
#line 111 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ConstDeclList> > () = make_node<ConstDeclList>(); }
#line 2516 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 114 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<ConstDeclList> > () = yystack_[4].value.as< std::shared_ptr<ConstDeclList> > (); yylhs.value.as< std::shared_ptr<ConstDeclList> > ()->append(make_node<ConstDeclNode>(yystack_[3].value.as< std::shared_ptr<IdentifierNode> > (), yystack_[1].value.as< std::shared_ptr<ConstValueNode> > ()));
    }
#line 2524 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 117 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<ConstDeclList> > () = make_node<ConstDeclList>(make_node<ConstDeclNode>(yystack_[3].value.as< std::shared_ptr<IdentifierNode> > (), yystack_[1].value.as< std::shared_ptr<ConstValueNode> > ()));
    }
#line 2532 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 122 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<ConstValueNode> > () = yystack_[0].value.as< std::shared_ptr<IntegerNode> > ();}
#line 2538 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 123 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<ConstValueNode> > () = yystack_[0].value.as< std::shared_ptr<RealNode> > ();}
#line 2544 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 124 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<ConstValueNode> > () = yystack_[0].value.as< std::shared_ptr<CharNode> > ();}
#line 2550 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 125 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<ConstValueNode> > () = yystack_[0].value.as< std::shared_ptr<StringNode> > ();}
#line 2556 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 126 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<ConstValueNode> > () = yystack_[0].value.as< std::shared_ptr<ConstValueNode> > ();}
#line 2562 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 129 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<TypeDeclList> > () = yystack_[0].value.as< std::shared_ptr<TypeDeclList> > ();}
#line 2568 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 130 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<TypeDeclList> > () = make_node<TypeDeclList>();}
#line 2574 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 133 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<TypeDeclList> > () = yystack_[1].value.as< std::shared_ptr<TypeDeclList> > (); yylhs.value.as< std::shared_ptr<TypeDeclList> > ()->append(yystack_[0].value.as< std::shared_ptr<TypeDeclNode> > ());
    }
#line 2582 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 136 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<TypeDeclList> > () = make_node<TypeDeclList>(yystack_[0].value.as< std::shared_ptr<TypeDeclNode> > ());
    }
#line 2590 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 141 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<TypeDeclNode> > () = make_node<TypeDeclNode>(yystack_[3].value.as< std::shared_ptr<IdentifierNode> > (), yystack_[1].value.as< std::shared_ptr<TypeNode> > ());
    }
#line 2598 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 146 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<TypeNode> > () = yystack_[0].value.as< std::shared_ptr<TypeNode> > ();
    }
#line 2606 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 149 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<TypeNode> > () = yystack_[0].value.as< std::shared_ptr<ArrayTypeNode> > ();}
#line 2612 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 152 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<TypeNode> > () = yystack_[0].value.as< std::shared_ptr<SimpleTypeNode> > ();}
#line 2618 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 153 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<TypeNode> > () = make_node<AliasTypeNode>(yystack_[0].value.as< std::shared_ptr<IdentifierNode> > ());}
#line 2624 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 154 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<TypeNode> > () = yystack_[0].value.as< std::shared_ptr<StringTypeNode> > ();}
#line 2630 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 155 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<TypeNode> > () = yystack_[0].value.as< std::shared_ptr<RecordTypeNode> > ();}
#line 2636 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 158 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<ArrayTypeNode> > () = make_node<ArrayTypeNode>(yystack_[3].value.as< std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<ExprNode>> > ().first, yystack_[3].value.as< std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<ExprNode>> > ().second, yystack_[0].value.as< std::shared_ptr<TypeNode> > ());
    }
#line 2644 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 163 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<StringTypeNode> > () = make_node<StringTypeNode>();
    }
#line 2652 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 168 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { 
        if (!is_ptr_of<IntegerNode>(yystack_[2].value.as< std::shared_ptr<ConstValueNode> > ()) || !is_ptr_of<IntegerNode>(yystack_[0].value.as< std::shared_ptr<ConstValueNode> > ())) throw std::logic_error("\nArray index must be integer!");
        yylhs.value.as< std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<ExprNode>> > () = std::make_pair(yystack_[2].value.as< std::shared_ptr<ConstValueNode> > (), yystack_[0].value.as< std::shared_ptr<ConstValueNode> > ());
    }
#line 2661 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 172 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { 
        yylhs.value.as< std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<ExprNode>> > () = std::make_pair(yystack_[2].value.as< std::shared_ptr<IdentifierNode> > (), yystack_[0].value.as< std::shared_ptr<IdentifierNode> > ());
    }
#line 2669 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 177 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<RecordTypeNode> > () = yystack_[1].value.as< std::shared_ptr<RecordTypeNode> > ();
    }
#line 2677 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 182 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<RecordTypeNode> > () = yystack_[1].value.as< std::shared_ptr<RecordTypeNode> > (); yylhs.value.as< std::shared_ptr<RecordTypeNode> > ()->merge(make_node<RecordTypeNode>(yystack_[0].value.as< std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> > ().first, yystack_[0].value.as< std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> > ().second));
    }
#line 2685 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 185 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<RecordTypeNode> > () = make_node<RecordTypeNode>(yystack_[0].value.as< std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> > ().first, yystack_[0].value.as< std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> > ().second);}
#line 2691 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 188 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::pair<std::shared_ptr<IdentifierList>, std::shared_ptr<TypeNode>> > () = std::make_pair(yystack_[3].value.as< std::shared_ptr<IdentifierList> > (), yystack_[1].value.as< std::shared_ptr<TypeNode> > ());
    }
#line 2699 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 193 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<IdentifierList> > () = yystack_[2].value.as< std::shared_ptr<IdentifierList> > (); yylhs.value.as< std::shared_ptr<IdentifierList> > ()->append(yystack_[0].value.as< std::shared_ptr<IdentifierNode> > ());
    }
#line 2707 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 196 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<IdentifierList> > () = make_node<IdentifierList>(yystack_[0].value.as< std::shared_ptr<IdentifierNode> > ());}
#line 2713 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 199 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<VarDeclList> > () = yystack_[0].value.as< std::shared_ptr<VarDeclList> > ();}
#line 2719 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 200 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<VarDeclList> > () = make_node<VarDeclList>();}
#line 2725 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 203 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<VarDeclList> > () = yystack_[1].value.as< std::shared_ptr<VarDeclList> > (); yylhs.value.as< std::shared_ptr<VarDeclList> > ()->merge(std::move(yystack_[0].value.as< std::shared_ptr<VarDeclList> > ()));
    }
#line 2733 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 206 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<VarDeclList> > () = yystack_[0].value.as< std::shared_ptr<VarDeclList> > ();}
#line 2739 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 209 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<VarDeclList> > () = make_node<VarDeclList>();
        for (auto &name : yystack_[3].value.as< std::shared_ptr<IdentifierList> > ()->getChildren()) yylhs.value.as< std::shared_ptr<VarDeclList> > ()->append(make_node<VarDeclNode>(name, yystack_[1].value.as< std::shared_ptr<TypeNode> > ()));
    }
#line 2748 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 215 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<RoutineList> > () = yystack_[1].value.as< std::shared_ptr<RoutineList> > (); yylhs.value.as< std::shared_ptr<RoutineList> > ()->append(yystack_[0].value.as< std::shared_ptr<RoutineNode> > ());
    }
#line 2756 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 218 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<RoutineList> > () = yystack_[1].value.as< std::shared_ptr<RoutineList> > (); yylhs.value.as< std::shared_ptr<RoutineList> > ()->append(yystack_[0].value.as< std::shared_ptr<RoutineNode> > ());}
#line 2762 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 219 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<RoutineList> > () = make_node<RoutineList>();}
#line 2768 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 222 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
    yylhs.value.as< std::shared_ptr<RoutineNode> > () = make_node<RoutineNode>(yystack_[7].value.as< std::shared_ptr<IdentifierNode> > (), yystack_[2].value.as< std::shared_ptr<RoutineHeadNode> > (), yystack_[1].value.as< std::shared_ptr<CompoundStmtNode> > (), yystack_[6].value.as< std::shared_ptr<ParamList> > (), yystack_[4].value.as< std::shared_ptr<TypeNode> > ()); 
    }
#line 2776 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 227 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<RoutineNode> > () = make_node<RoutineNode>(yystack_[5].value.as< std::shared_ptr<IdentifierNode> > (), yystack_[2].value.as< std::shared_ptr<RoutineHeadNode> > (), yystack_[1].value.as< std::shared_ptr<CompoundStmtNode> > (), yystack_[4].value.as< std::shared_ptr<ParamList> > (), make_node<VoidTypeNode>());
    }
#line 2784 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 232 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ParamList> > () = yystack_[1].value.as< std::shared_ptr<ParamList> > (); }
#line 2790 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 233 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ParamList> > () = make_node<ParamList>(); }
#line 2796 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 234 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ParamList> > () = make_node<ParamList>(); }
#line 2802 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 237 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<ParamList> > () = yystack_[2].value.as< std::shared_ptr<ParamList> > (); yylhs.value.as< std::shared_ptr<ParamList> > ()->merge(std::move(yystack_[0].value.as< std::shared_ptr<ParamList> > ()));
    }
#line 2810 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 240 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<ParamList> > () = yystack_[0].value.as< std::shared_ptr<ParamList> > ();}
#line 2816 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 243 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<ParamList> > () = make_node<ParamList>();
        for (auto &name : yystack_[2].value.as< std::shared_ptr<IdentifierList> > ()->getChildren()) yylhs.value.as< std::shared_ptr<ParamList> > ()->append(make_node<ParamNode>(name, yystack_[0].value.as< std::shared_ptr<TypeNode> > ()));
    }
#line 2825 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 249 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<IdentifierList> > () = yystack_[0].value.as< std::shared_ptr<IdentifierList> > ();
    }
#line 2833 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 252 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<IdentifierList> > () = yystack_[0].value.as< std::shared_ptr<IdentifierList> > ();}
#line 2839 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 255 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = yystack_[0].value.as< std::shared_ptr<CompoundStmtNode> > ();
    }
#line 2847 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 260 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = yystack_[1].value.as< std::shared_ptr<CompoundStmtNode> > ();
    }
#line 2855 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 265 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = yystack_[2].value.as< std::shared_ptr<CompoundStmtNode> > (); yylhs.value.as< std::shared_ptr<CompoundStmtNode> > ()->merge(std::move(yystack_[1].value.as< std::shared_ptr<CompoundStmtNode> > ()));
    }
#line 2863 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 268 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = make_node<CompoundStmtNode>(); }
#line 2869 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 271 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = make_node<CompoundStmtNode>(yystack_[0].value.as< std::shared_ptr<AssignStmtNode> > ());}
#line 2875 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 272 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = make_node<CompoundStmtNode>(yystack_[0].value.as< std::shared_ptr<ProcStmtNode> > ());}
#line 2881 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 273 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = yystack_[0].value.as< std::shared_ptr<CompoundStmtNode> > ();}
#line 2887 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 274 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = make_node<CompoundStmtNode>(yystack_[0].value.as< std::shared_ptr<IfStmtNode> > ());}
#line 2893 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 275 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = make_node<CompoundStmtNode>(yystack_[0].value.as< std::shared_ptr<RepeatStmtNode> > ());}
#line 2899 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 276 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = make_node<CompoundStmtNode>(yystack_[0].value.as< std::shared_ptr<WhileStmtNode> > ());}
#line 2905 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 277 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = make_node<CompoundStmtNode>(yystack_[0].value.as< std::shared_ptr<ForStmtNode> > ());}
#line 2911 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 278 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = make_node<CompoundStmtNode>(yystack_[0].value.as< std::shared_ptr<CaseStmtNode> > ());}
#line 2917 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 281 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<AssignStmtNode> > () = make_node<AssignStmtNode>(yystack_[2].value.as< std::shared_ptr<LeftExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ());
    }
#line 2925 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 287 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {  yylhs.value.as< std::shared_ptr<ProcStmtNode> > () = make_node<ProcStmtNode>(make_node<CustomProcNode>(yystack_[0].value.as< std::shared_ptr<IdentifierNode> > ())); }
#line 2931 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 288 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {  yylhs.value.as< std::shared_ptr<ProcStmtNode> > () = make_node<ProcStmtNode>(make_node<CustomProcNode>(yystack_[2].value.as< std::shared_ptr<IdentifierNode> > ())); }
#line 2937 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 290 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ProcStmtNode> > () = make_node<ProcStmtNode>(make_node<CustomProcNode>(yystack_[3].value.as< std::shared_ptr<IdentifierNode> > (), yystack_[1].value.as< std::shared_ptr<ArgList> > ())); }
#line 2943 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 292 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ProcStmtNode> > () = make_node<ProcStmtNode>(make_node<SysProcNode>(yystack_[2].value.as< spc::SysFunc > ())); }
#line 2949 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 294 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ProcStmtNode> > () = make_node<ProcStmtNode>(make_node<SysProcNode>(yystack_[0].value.as< spc::SysFunc > ())); }
#line 2955 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 296 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ProcStmtNode> > () = make_node<ProcStmtNode>(make_node<SysProcNode>(yystack_[3].value.as< spc::SysFunc > (), yystack_[1].value.as< std::shared_ptr<ArgList> > ())); }
#line 2961 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 299 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<RepeatStmtNode> > () = make_node<RepeatStmtNode>(yystack_[0].value.as< std::shared_ptr<ExprNode> > (), yystack_[2].value.as< std::shared_ptr<CompoundStmtNode> > ()); // $$->append($2);
    }
#line 2969 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 304 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<WhileStmtNode> > () = make_node<WhileStmtNode>(yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<CompoundStmtNode> > ());
    }
#line 2977 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 309 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<ForStmtNode> > () = make_node<ForStmtNode>(yystack_[3].value.as< spc::ForDirection > (), yystack_[6].value.as< std::shared_ptr<IdentifierNode> > (), yystack_[4].value.as< std::shared_ptr<ExprNode> > (), yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<CompoundStmtNode> > ());
    }
#line 2985 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 314 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< spc::ForDirection > () = ForDirection::To; }
#line 2991 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 315 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {yylhs.value.as< spc::ForDirection > () = ForDirection::Downto;}
#line 2997 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 318 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<IfStmtNode> > () = make_node<IfStmtNode>(yystack_[3].value.as< std::shared_ptr<ExprNode> > (), yystack_[1].value.as< std::shared_ptr<CompoundStmtNode> > (), yystack_[0].value.as< std::shared_ptr<CompoundStmtNode> > ());
    }
#line 3005 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 323 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = yystack_[0].value.as< std::shared_ptr<CompoundStmtNode> > (); }
#line 3011 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 324 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<CompoundStmtNode> > () = nullptr; }
#line 3017 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 327 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<CaseStmtNode> > () = make_node<CaseStmtNode>(yystack_[3].value.as< std::shared_ptr<ExprNode> > (), std::move(yystack_[1].value.as< std::shared_ptr<CaseBranchList> > ()));
    }
#line 3025 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 332 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<CaseBranchList> > () = yystack_[1].value.as< std::shared_ptr<CaseBranchList> > (); yylhs.value.as< std::shared_ptr<CaseBranchList> > ()->append(yystack_[0].value.as< std::shared_ptr<CaseBranchNode> > ()); 
    }
#line 3033 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 335 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<CaseBranchList> > () = make_node<CaseBranchList>(yystack_[0].value.as< std::shared_ptr<CaseBranchNode> > ()); }
#line 3039 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 338 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        if (!is_ptr_of<IntegerNode>(yystack_[3].value.as< std::shared_ptr<ConstValueNode> > ()) && !is_ptr_of<CharNode>(yystack_[3].value.as< std::shared_ptr<ConstValueNode> > ()))
            throw std::logic_error("\nCase branch must be integer type!");
        yylhs.value.as< std::shared_ptr<CaseBranchNode> > () = make_node<CaseBranchNode>(yystack_[3].value.as< std::shared_ptr<ConstValueNode> > (), yystack_[1].value.as< std::shared_ptr<CompoundStmtNode> > ()); 
    }
#line 3049 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 343 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<CaseBranchNode> > () = make_node<CaseBranchNode>(yystack_[3].value.as< std::shared_ptr<IdentifierNode> > (), yystack_[1].value.as< std::shared_ptr<CompoundStmtNode> > ()); }
#line 3055 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 346 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Geq, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3061 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 347 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Gt, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3067 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 348 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Leq, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3073 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 349 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Lt, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3079 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 350 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Eq, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3085 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 351 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Neq, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3091 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 90:
#line 352 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = yystack_[0].value.as< std::shared_ptr<ExprNode> > (); }
#line 3097 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 91:
#line 355 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Plus, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3103 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 92:
#line 356 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Minus, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3109 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 93:
#line 357 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Or, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3115 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 94:
#line 358 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Xor, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3121 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 95:
#line 359 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = yystack_[0].value.as< std::shared_ptr<ExprNode> > (); }
#line 3127 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 96:
#line 362 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Mul, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3133 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 97:
#line 363 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Div, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3139 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 98:
#line 364 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Mod, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3145 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 99:
#line 365 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::And, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3151 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 100:
#line 366 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Truediv, yystack_[2].value.as< std::shared_ptr<ExprNode> > (), yystack_[0].value.as< std::shared_ptr<ExprNode> > ());  }
#line 3157 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 101:
#line 367 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = yystack_[0].value.as< std::shared_ptr<ExprNode> > (); }
#line 3163 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 102:
#line 370 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = yystack_[0].value.as< std::shared_ptr<LeftExprNode> > (); }
#line 3169 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 103:
#line 372 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<CustomProcNode>(yystack_[3].value.as< std::shared_ptr<IdentifierNode> > (), yystack_[1].value.as< std::shared_ptr<ArgList> > ()); }
#line 3175 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 104:
#line 374 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<CustomProcNode>(yystack_[2].value.as< std::shared_ptr<IdentifierNode> > ()); }
#line 3181 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 105:
#line 376 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<SysProcNode>(yystack_[3].value.as< spc::SysFunc > (), yystack_[1].value.as< std::shared_ptr<ArgList> > ()); }
#line 3187 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 106:
#line 377 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = yystack_[0].value.as< std::shared_ptr<ConstValueNode> > (); }
#line 3193 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 107:
#line 378 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = yystack_[1].value.as< std::shared_ptr<ExprNode> > (); }
#line 3199 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 108:
#line 380 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Xor, make_node<BooleanNode>(true), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3205 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 109:
#line 382 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = make_node<BinaryExprNode>(BinaryOp::Minus, make_node<IntegerNode>(0), yystack_[0].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3211 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 110:
#line 383 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ExprNode> > () = yystack_[0].value.as< std::shared_ptr<ExprNode> > (); }
#line 3217 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 111:
#line 386 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<LeftExprNode> > () = yystack_[0].value.as< std::shared_ptr<IdentifierNode> > (); }
#line 3223 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 112:
#line 387 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<LeftExprNode> > () = make_node<ArrayRefNode>(yystack_[3].value.as< std::shared_ptr<LeftExprNode> > (), yystack_[1].value.as< std::shared_ptr<ExprNode> > ()); }
#line 3229 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 113:
#line 388 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<LeftExprNode> > () = make_node<RecordRefNode>(yystack_[2].value.as< std::shared_ptr<LeftExprNode> > (), yystack_[0].value.as< std::shared_ptr<IdentifierNode> > ()); }
#line 3235 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 114:
#line 391 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<ArgList> > () = yystack_[2].value.as< std::shared_ptr<ArgList> > (); yylhs.value.as< std::shared_ptr<ArgList> > ()->append(yystack_[0].value.as< std::shared_ptr<ExprNode> > ());
    }
#line 3243 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;

  case 115:
#line 394 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<ArgList> > () = make_node<ArgList>(yystack_[0].value.as< std::shared_ptr<ExprNode> > ());// $$->add_child($1);
    }
#line 3251 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
    break;


#line 3255 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int parser::yypact_ninf_ = -208;

  const signed char parser::yytable_ninf_ = -66;

  const short int
  parser::yypact_[] =
  {
      17,    37,    89,    35,  -208,    44,    87,    97,   100,    77,
     113,  -208,    65,  -208,   125,   123,   176,    94,   216,  -208,
      99,   125,  -208,   130,  -208,  -208,  -208,  -208,  -208,  -208,
      90,   176,   -13,  -208,    91,   191,  -208,   191,   142,   191,
    -208,    96,  -208,  -208,  -208,  -208,  -208,  -208,  -208,   -18,
     144,  -208,  -208,   -36,   130,  -208,    66,  -208,   115,    43,
     124,    98,   116,   191,   191,   191,   191,  -208,    84,    -6,
     281,  -208,   -37,   228,   252,   119,   177,  -208,   191,   167,
     191,  -208,   120,   130,  -208,  -208,   122,  -208,  -208,  -208,
    -208,   175,   144,  -208,   192,   194,  -208,  -208,  -208,  -208,
     277,    16,  -208,    28,   145,   191,  -208,  -208,  -208,    40,
     249,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   249,   191,   169,
     277,  -208,    -9,   248,    15,  -208,    23,  -208,  -208,   148,
     143,   143,  -208,   191,  -208,  -208,    45,    49,  -208,   187,
      -6,    -6,    -6,    -6,    -6,    -6,   281,   281,   281,   281,
    -208,  -208,  -208,  -208,  -208,   277,  -208,   271,   139,   160,
     269,  -208,  -208,   168,   170,   166,  -208,  -208,   144,  -208,
       7,   172,   173,   277,  -208,  -208,   249,  -208,  -208,  -208,
     191,   249,   249,  -208,  -208,   225,   176,   196,   182,   130,
    -208,   171,     8,  -208,   179,   131,    44,  -208,   259,   186,
     190,  -208,  -208,   144,  -208,   171,   109,  -208,   144,   195,
      97,   249,  -208,  -208,  -208,  -208,  -208,    44,   202,  -208,
      97,  -208,   205,  -208
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     5,     0,     0,    14,     0,
       4,    55,     0,    52,     0,    35,     0,     0,     0,     2,
       0,    13,    16,     0,    41,     8,     9,    10,    11,    12,
       0,     0,   111,    53,    69,     0,    55,     0,     0,     0,
      58,     0,    56,    57,    60,    61,    62,    59,    63,     0,
       0,    15,    33,     0,    34,    37,     3,     7,     0,     0,
       0,   111,     0,     0,     0,     0,     0,   106,     0,    90,
      95,   101,   102,     0,     0,     0,     0,    54,     0,     0,
       0,    21,     0,     0,    20,    25,     0,    18,    19,    22,
      23,     0,     0,    36,     0,     0,    39,    40,     6,    66,
     115,     0,    68,     0,     0,     0,   110,   109,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,   113,     0,     0,     0,    30,     0,    17,    32,     0,
      46,    46,    67,     0,    70,   104,     0,     0,   107,    78,
      88,    89,    86,    87,    84,    85,    91,    92,    93,    94,
      96,    97,    98,   100,    99,    71,    72,     0,     0,     0,
       0,    81,   112,     0,     0,     0,    28,    29,     0,    38,
       0,     0,     0,   114,   103,   105,     0,    76,    74,    75,
       0,     0,     0,    79,    80,     0,     0,     0,     0,     0,
      45,    51,     0,    48,     0,     0,     5,    77,     0,     0,
       0,    27,    26,     0,    31,    50,     0,    44,     0,     0,
       0,     0,    83,    82,    24,    47,    49,     5,     0,    73,
       0,    43,     0,    42
  };

  const short int
  parser::yypgoto_[] =
  {
    -208,  -208,  -191,  -208,  -208,   -14,  -208,  -208,   246,   -86,
      63,  -208,  -208,  -208,  -208,  -208,   136,   -79,  -208,  -208,
     217,  -208,  -208,  -208,   133,  -208,    60,  -208,  -207,    -7,
     242,   -88,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,  -208,   134,   -32,   209,   -66,   -55,   -17,   -33
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     2,     7,     8,    10,    67,    15,    21,    22,    86,
      87,    88,    89,   175,    90,   134,   135,    53,    24,    54,
      55,    56,    96,    97,   181,   202,   203,   204,    12,    40,
      18,    41,    42,    43,    44,    45,    46,   190,    47,   187,
      48,   170,   171,   100,    69,    70,    71,    72,   101
  };

  const short int
  parser::yytable_[] =
  {
      13,    49,    30,    68,   136,    74,   139,    76,   106,   107,
     108,    52,   -65,   228,   199,   220,    79,    58,    78,    52,
       1,    80,   149,   232,    91,    92,   176,   103,   111,   112,
     113,   114,   115,   116,   109,    79,   230,   117,   118,   166,
      80,     3,   -65,    59,   119,   120,   130,    61,   132,     6,
     172,   156,   157,   158,   159,   136,    49,    25,    26,    27,
      28,    29,    62,   216,   200,   217,   160,   161,   162,   163,
     164,   146,   147,   142,    94,    95,   143,   111,   112,   113,
     114,   115,   116,    91,   178,   144,    63,    64,   143,     4,
       5,     9,   198,    49,   165,    65,   167,   148,   207,    66,
      99,   201,   184,   209,   210,   143,   185,    11,   110,   143,
      49,   183,    14,    52,    16,   169,   199,    17,    19,   174,
     215,   111,   112,   113,   114,   115,   116,   224,    61,    20,
      23,    31,   226,   229,    52,    81,    50,   201,    25,    26,
      27,    28,    29,    62,    83,    57,    75,    60,    81,    61,
      82,    77,    84,    85,   104,   128,   169,    83,   208,    25,
      26,    27,    28,    29,    62,    84,    85,    63,    64,    49,
      98,   131,   105,   168,    49,    49,    65,   137,   133,   138,
      66,   102,   212,    25,    26,    27,    28,    29,    63,    64,
      25,    26,    27,    28,    29,    61,   140,    65,   141,   180,
     191,    66,   145,   179,    49,    25,    26,    27,    28,    29,
      62,   129,   186,    13,   111,   112,   113,   114,   115,   116,
      32,   192,   195,    13,   196,   197,    11,    33,   206,   211,
     213,    91,    32,   205,    63,    64,    34,   214,    11,    35,
     218,   222,    36,    65,    37,   223,    38,    66,    34,    39,
     227,    35,   173,    32,    36,   126,    37,   231,    38,    11,
     233,    39,    25,    26,    27,    28,    29,    51,   219,    34,
     177,    93,    35,   168,   182,    36,   225,    37,    73,    38,
     193,   127,    39,    25,    26,    27,    28,    29,   221,   111,
     112,   113,   114,   115,   116,     0,   111,   112,   113,   114,
     115,   116,   188,   189,   194,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   111,   112,   113,   114,   115,   116,
     150,   151,   152,   153,   154,   155,   121,   122,   123,   124,
     125
  };

  const short int
  parser::yycheck_[] =
  {
       7,    18,    16,    35,    83,    37,    92,    39,    63,    64,
      65,     4,    25,   220,     7,   206,    53,    31,    36,     4,
       3,    58,   110,   230,    60,    61,    11,    60,    37,    38,
      39,    40,    41,    42,    66,    53,   227,    43,    44,   127,
      58,     4,    55,    56,    50,    51,    78,     4,    80,     5,
      59,   117,   118,   119,   120,   134,    73,    14,    15,    16,
      17,    18,    19,    55,    57,    57,   121,   122,   123,   124,
     125,   104,   105,    57,     8,     9,    60,    37,    38,    39,
      40,    41,    42,    60,    61,    57,    43,    44,    60,     0,
      55,     4,   178,   110,   126,    52,   128,    57,   186,    56,
      57,   180,    57,   191,   192,    60,    57,    10,    24,    60,
     127,   143,    12,     4,    37,   129,     7,     4,    53,   133,
     199,    37,    38,    39,    40,    41,    42,   213,     4,     4,
       7,    37,   218,   221,     4,     4,    37,   216,    14,    15,
      16,    17,    18,    19,    13,    55,     4,    56,     4,     4,
       6,    55,    21,    22,    56,    36,   170,    13,   190,    14,
      15,    16,    17,    18,    19,    21,    22,    43,    44,   186,
      55,     4,    56,     4,   191,   192,    52,    55,    58,     4,
      56,    57,   196,    14,    15,    16,    17,    18,    43,    44,
      14,    15,    16,    17,    18,     4,     4,    52,     4,    56,
      61,    56,    57,    55,   221,    14,    15,    16,    17,    18,
      19,    34,    25,   220,    37,    38,    39,    40,    41,    42,
       4,    61,    54,   230,    54,    59,    10,    11,    55,     4,
      34,    60,     4,    61,    43,    44,    20,    55,    10,    23,
      61,    55,    26,    52,    28,    55,    30,    56,    20,    33,
      55,    23,     4,     4,    26,    27,    28,    55,    30,    10,
      55,    33,    14,    15,    16,    17,    18,    21,   205,    20,
     134,    54,    23,     4,   141,    26,   216,    28,    36,    30,
      11,    29,    33,    14,    15,    16,    17,    18,    29,    37,
      38,    39,    40,    41,    42,    -1,    37,    38,    39,    40,
      41,    42,    31,    32,   170,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    37,    38,    39,    40,    41,    42,
     111,   112,   113,   114,   115,   116,    45,    46,    47,    48,
      49
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    63,     4,     0,    55,     5,    64,    65,     4,
      66,    10,    90,    91,    12,    68,    37,     4,    92,    53,
       4,    69,    70,     7,    80,    14,    15,    16,    17,    18,
      67,    37,     4,    11,    20,    23,    26,    28,    30,    33,
      91,    93,    94,    95,    96,    97,    98,   100,   102,   109,
      37,    70,     4,    79,    81,    82,    83,    55,    67,    56,
      56,     4,    19,    43,    44,    52,    56,    67,   105,   106,
     107,   108,   109,    92,   105,     4,   105,    55,    36,    53,
      58,     4,     6,    13,    21,    22,    71,    72,    73,    74,
      76,    60,    61,    82,     8,     9,    84,    85,    55,    57,
     105,   110,    57,   110,    56,    56,   108,   108,   108,   105,
      24,    37,    38,    39,    40,    41,    42,    43,    44,    50,
      51,    45,    46,    47,    48,    49,    27,    29,    36,    34,
     105,     4,   105,    58,    77,    78,    79,    55,     4,    71,
       4,     4,    57,    60,    57,    57,   110,   110,    57,    93,
     106,   106,   106,   106,   106,   106,   107,   107,   107,   107,
     108,   108,   108,   108,   108,   105,    93,   105,     4,    67,
     103,   104,    59,     4,    67,    75,    11,    78,    61,    55,
      56,    86,    86,   105,    57,    57,    25,   101,    31,    32,
      99,    61,    61,    11,   104,    54,    54,    59,    71,     7,
      57,    79,    87,    88,    89,    61,    55,    93,   105,    93,
      93,     4,    67,    34,    55,    79,    55,    57,    61,    72,
      64,    29,    55,    55,    71,    88,    71,    55,    90,    93,
      64,    55,    90,    55
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    62,    63,    64,    65,    65,    66,    66,    67,    67,
      67,    67,    67,    68,    68,    69,    69,    70,    71,    71,
      72,    72,    72,    72,    73,    74,    75,    75,    76,    77,
      77,    78,    79,    79,    80,    80,    81,    81,    82,    83,
      83,    83,    84,    85,    86,    86,    86,    87,    87,    88,
      89,    89,    90,    91,    92,    92,    93,    93,    93,    93,
      93,    93,    93,    93,    94,    95,    95,    95,    95,    95,
      95,    96,    97,    98,    99,    99,   100,   101,   101,   102,
     103,   103,   104,   104,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   106,   106,   106,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   109,   109,   109,   110,   110
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     6,     4,     2,     0,     5,     4,     1,     1,
       1,     1,     1,     2,     0,     2,     1,     4,     1,     1,
       1,     1,     1,     1,     6,     1,     3,     3,     3,     2,
       1,     4,     3,     1,     2,     0,     2,     1,     4,     2,
       2,     0,     9,     7,     3,     2,     0,     3,     1,     3,
       2,     1,     1,     3,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     4,     3,     1,
       4,     4,     4,     8,     1,     1,     5,     2,     0,     5,
       2,     1,     4,     4,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     1,     4,     3,     4,     1,     3,     2,     2,
       2,     1,     4,     3,     3,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "PROGRAM", "ID", "CONST", "ARRAY", "VAR",
  "FUNCTION", "PROCEDURE", "PBEGIN", "END", "TYPE", "RECORD", "INTEGER",
  "REAL", "CHAR", "STRING", "SYS_CON", "SYS_FUNCT", "SYS_PROC", "SYS_TYPE",
  "STR_TYPE", "IF", "THEN", "ELSE", "REPEAT", "UNTIL", "WHILE", "DO",
  "FOR", "TO", "DOWNTO", "CASE", "OF", "GOTO", "ASSIGN", "EQUAL",
  "UNEQUAL", "LE", "LT", "GE", "GT", "PLUS", "MINUS", "MUL", "DIV", "MOD",
  "TRUEDIV", "AND", "OR", "XOR", "NOT", "DOT", "DOTDOT", "SEMI", "LP",
  "RP", "LB", "RB", "COMMA", "COLON", "$accept", "program", "routine_head",
  "const_part", "const_expr_list", "const_value", "type_part",
  "type_decl_list", "type_definition", "type_decl", "simple_type_decl",
  "array_type_decl", "string_type_decl", "array_range", "record_type_decl",
  "field_decl_list", "field_decl", "name_list", "var_part",
  "var_decl_list", "var_decl", "routine_part", "function_decl",
  "procedure_decl", "parameters", "para_decl_list", "para_type_list",
  "var_para_list", "routine_body", "compound_stmt", "stmt_list", "stmt",
  "assign_stmt", "proc_stmt", "repeat_stmt", "while_stmt", "for_stmt",
  "direction", "if_stmt", "else_clause", "case_stmt", "case_expr_list",
  "case_expr", "expression", "expr", "term", "factor", "left_expr",
  "args_list", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   100,   100,   105,   110,   111,   114,   117,   122,   123,
     124,   125,   126,   129,   130,   133,   136,   141,   146,   149,
     152,   153,   154,   155,   158,   163,   168,   172,   177,   182,
     185,   188,   193,   196,   199,   200,   203,   206,   209,   215,
     218,   219,   222,   227,   232,   233,   234,   237,   240,   243,
     249,   252,   255,   260,   265,   268,   271,   272,   273,   274,
     275,   276,   277,   278,   281,   287,   288,   289,   291,   293,
     295,   299,   304,   309,   314,   315,   318,   323,   324,   327,
     332,   335,   338,   343,   346,   347,   348,   349,   350,   351,
     352,   355,   356,   357,   358,   359,   362,   363,   364,   365,
     366,   367,   370,   371,   373,   375,   377,   378,   379,   381,
     383,   386,   387,   388,   391,   394
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
    };
    const unsigned int user_token_number_max_ = 316;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 6 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:1167
} // spc
#line 3863 "/home/zhj/Desktop/version2/build/parser.cpp" // lalr1.cc:1167
#line 399 "/home/zhj/Desktop/version2/src/parser.y" // lalr1.cc:1168


void spc::parser::error(const spc::parser::location_type &loc, const std::string& msg) {
    std::cerr << std::endl << "Parser: Error at " << loc << ":" << std::endl;
    std::string msg2 = msg;
    msg2[0] = toupper(msg2[0]);
    throw std::logic_error(msg2);
}
