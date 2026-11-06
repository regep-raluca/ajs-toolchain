
// Generated from C:/TAC/atomjs1/expr/Expr.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  ExprParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, ID = 5, INT = 6, ADD = 7, SUB = 8, 
    MUL = 9, DIV = 10, NEWLINE = 11, WS = 12
  };

  enum {
    RuleProg = 0, RuleStat = 1, RuleExprAdd = 2, RuleExprMul = 3, RuleExprFactor = 4
  };

  explicit ExprParser(antlr4::TokenStream *input);

  ExprParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ExprParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgContext;
  class StatContext;
  class ExprAddContext;
  class ExprMulContext;
  class ExprFactorContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatContext *> stat();
    StatContext* stat(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  StatContext : public antlr4::ParserRuleContext {
  public:
    StatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatContext() = default;
    void copyFrom(StatContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PrintExprContext : public StatContext {
  public:
    PrintExprContext(StatContext *ctx);

    ExprAddContext *exprAdd();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignContext : public StatContext {
  public:
    AssignContext(StatContext *ctx);

    antlr4::tree::TerminalNode *ID();
    ExprAddContext *exprAdd();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatContext* stat();

  class  ExprAddContext : public antlr4::ParserRuleContext {
  public:
    ExprAddContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprAddContext() = default;
    void copyFrom(ExprAddContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AddSubContext : public ExprAddContext {
  public:
    AddSubContext(ExprAddContext *ctx);

    ExprAddContext *exprAdd();
    ExprMulContext *exprMul();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ToMulContext : public ExprAddContext {
  public:
    ToMulContext(ExprAddContext *ctx);

    ExprMulContext *exprMul();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprAddContext* exprAdd();
  ExprAddContext* exprAdd(int precedence);
  class  ExprMulContext : public antlr4::ParserRuleContext {
  public:
    ExprMulContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprMulContext() = default;
    void copyFrom(ExprMulContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ToFactorContext : public ExprMulContext {
  public:
    ToFactorContext(ExprMulContext *ctx);

    ExprFactorContext *exprFactor();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulDivContext : public ExprMulContext {
  public:
    MulDivContext(ExprMulContext *ctx);

    ExprMulContext *exprMul();
    ExprFactorContext *exprFactor();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprMulContext* exprMul();
  ExprMulContext* exprMul(int precedence);
  class  ExprFactorContext : public antlr4::ParserRuleContext {
  public:
    ExprFactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprFactorContext() = default;
    void copyFrom(ExprFactorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParensContext : public ExprFactorContext {
  public:
    ParensContext(ExprFactorContext *ctx);

    ExprAddContext *exprAdd();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdContext : public ExprFactorContext {
  public:
    IdContext(ExprFactorContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntContext : public ExprFactorContext {
  public:
    IntContext(ExprFactorContext *ctx);

    antlr4::tree::TerminalNode *INT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprFactorContext* exprFactor();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprAddSempred(ExprAddContext *_localctx, size_t predicateIndex);
  bool exprMulSempred(ExprMulContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

