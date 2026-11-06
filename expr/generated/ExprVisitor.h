
// Generated from C:/TAC/atomjs1/expr/Expr.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExprParser.
 */
class  ExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExprParser.
   */
    virtual std::any visitProg(ExprParser::ProgContext *context) = 0;

    virtual std::any visitPrintExpr(ExprParser::PrintExprContext *context) = 0;

    virtual std::any visitAssign(ExprParser::AssignContext *context) = 0;

    virtual std::any visitAddSub(ExprParser::AddSubContext *context) = 0;

    virtual std::any visitToMul(ExprParser::ToMulContext *context) = 0;

    virtual std::any visitToFactor(ExprParser::ToFactorContext *context) = 0;

    virtual std::any visitMulDiv(ExprParser::MulDivContext *context) = 0;

    virtual std::any visitId(ExprParser::IdContext *context) = 0;

    virtual std::any visitInt(ExprParser::IntContext *context) = 0;

    virtual std::any visitParens(ExprParser::ParensContext *context) = 0;


};

