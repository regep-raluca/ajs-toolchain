
// Generated from C:/TAC/atomjs1/expr/Expr.g4 by ANTLR 4.13.2


#include "ExprVisitor.h"

#include "ExprParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ExprParserStaticData final {
  ExprParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ExprParserStaticData(const ExprParserStaticData&) = delete;
  ExprParserStaticData(ExprParserStaticData&&) = delete;
  ExprParserStaticData& operator=(const ExprParserStaticData&) = delete;
  ExprParserStaticData& operator=(ExprParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag exprParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<ExprParserStaticData> exprParserStaticData = nullptr;

void exprParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (exprParserStaticData != nullptr) {
    return;
  }
#else
  assert(exprParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ExprParserStaticData>(
    std::vector<std::string>{
      "prog", "stat", "exprAdd", "exprMul", "exprFactor"
    },
    std::vector<std::string>{
      "", "';'", "'='", "'('", "')'", "", "", "'+'", "'-'", "'*'", "'/'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "ID", "INT", "ADD", "SUB", "MUL", "DIV", "NEWLINE", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,12,58,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,1,0,5,0,13,8,0,
  	10,0,12,0,16,9,0,4,0,18,8,0,11,0,12,0,19,1,1,1,1,1,1,1,1,3,1,26,8,1,1,
  	2,1,2,1,2,1,2,1,2,1,2,5,2,34,8,2,10,2,12,2,37,9,2,1,3,1,3,1,3,1,3,1,3,
  	1,3,5,3,45,8,3,10,3,12,3,48,9,3,1,4,1,4,1,4,1,4,1,4,1,4,3,4,56,8,4,1,
  	4,0,2,4,6,5,0,2,4,6,8,0,3,2,0,1,1,11,11,1,0,7,8,1,0,9,10,59,0,17,1,0,
  	0,0,2,25,1,0,0,0,4,27,1,0,0,0,6,38,1,0,0,0,8,55,1,0,0,0,10,14,3,2,1,0,
  	11,13,7,0,0,0,12,11,1,0,0,0,13,16,1,0,0,0,14,12,1,0,0,0,14,15,1,0,0,0,
  	15,18,1,0,0,0,16,14,1,0,0,0,17,10,1,0,0,0,18,19,1,0,0,0,19,17,1,0,0,0,
  	19,20,1,0,0,0,20,1,1,0,0,0,21,26,3,4,2,0,22,23,5,5,0,0,23,24,5,2,0,0,
  	24,26,3,4,2,0,25,21,1,0,0,0,25,22,1,0,0,0,26,3,1,0,0,0,27,28,6,2,-1,0,
  	28,29,3,6,3,0,29,35,1,0,0,0,30,31,10,2,0,0,31,32,7,1,0,0,32,34,3,6,3,
  	0,33,30,1,0,0,0,34,37,1,0,0,0,35,33,1,0,0,0,35,36,1,0,0,0,36,5,1,0,0,
  	0,37,35,1,0,0,0,38,39,6,3,-1,0,39,40,3,8,4,0,40,46,1,0,0,0,41,42,10,2,
  	0,0,42,43,7,2,0,0,43,45,3,8,4,0,44,41,1,0,0,0,45,48,1,0,0,0,46,44,1,0,
  	0,0,46,47,1,0,0,0,47,7,1,0,0,0,48,46,1,0,0,0,49,56,5,5,0,0,50,56,5,6,
  	0,0,51,52,5,3,0,0,52,53,3,4,2,0,53,54,5,4,0,0,54,56,1,0,0,0,55,49,1,0,
  	0,0,55,50,1,0,0,0,55,51,1,0,0,0,56,9,1,0,0,0,6,14,19,25,35,46,55
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  exprParserStaticData = std::move(staticData);
}

}

ExprParser::ExprParser(TokenStream *input) : ExprParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ExprParser::ExprParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ExprParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *exprParserStaticData->atn, exprParserStaticData->decisionToDFA, exprParserStaticData->sharedContextCache, options);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

const atn::ATN& ExprParser::getATN() const {
  return *exprParserStaticData->atn;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return exprParserStaticData->ruleNames;
}

const dfa::Vocabulary& ExprParser::getVocabulary() const {
  return exprParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ExprParser::getSerializedATN() const {
  return exprParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

ExprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::StatContext *> ExprParser::ProgContext::stat() {
  return getRuleContexts<ExprParser::StatContext>();
}

ExprParser::StatContext* ExprParser::ProgContext::stat(size_t i) {
  return getRuleContext<ExprParser::StatContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::ProgContext::NEWLINE() {
  return getTokens(ExprParser::NEWLINE);
}

tree::TerminalNode* ExprParser::ProgContext::NEWLINE(size_t i) {
  return getToken(ExprParser::NEWLINE, i);
}


size_t ExprParser::ProgContext::getRuleIndex() const {
  return ExprParser::RuleProg;
}


std::any ExprParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProgContext* ExprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(10);
      stat();
      setState(14);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ExprParser::T__0

      || _la == ExprParser::NEWLINE) {
        setState(11);
        _la = _input->LA(1);
        if (!(_la == ExprParser::T__0

        || _la == ExprParser::NEWLINE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(16);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(19); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 104) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

ExprParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::StatContext::getRuleIndex() const {
  return ExprParser::RuleStat;
}

void ExprParser::StatContext::copyFrom(StatContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PrintExprContext ------------------------------------------------------------------

ExprParser::ExprAddContext* ExprParser::PrintExprContext::exprAdd() {
  return getRuleContext<ExprParser::ExprAddContext>(0);
}

ExprParser::PrintExprContext::PrintExprContext(StatContext *ctx) { copyFrom(ctx); }


std::any ExprParser::PrintExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitPrintExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::AssignContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::ExprAddContext* ExprParser::AssignContext::exprAdd() {
  return getRuleContext<ExprParser::ExprAddContext>(0);
}

ExprParser::AssignContext::AssignContext(StatContext *ctx) { copyFrom(ctx); }


std::any ExprParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::StatContext* ExprParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 2, ExprParser::RuleStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(25);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprParser::PrintExprContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(21);
      exprAdd(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExprParser::AssignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(22);
      match(ExprParser::ID);
      setState(23);
      match(ExprParser::T__1);
      setState(24);
      exprAdd(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprAddContext ------------------------------------------------------------------

ExprParser::ExprAddContext::ExprAddContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::ExprAddContext::getRuleIndex() const {
  return ExprParser::RuleExprAdd;
}

void ExprParser::ExprAddContext::copyFrom(ExprAddContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AddSubContext ------------------------------------------------------------------

ExprParser::ExprAddContext* ExprParser::AddSubContext::exprAdd() {
  return getRuleContext<ExprParser::ExprAddContext>(0);
}

ExprParser::ExprMulContext* ExprParser::AddSubContext::exprMul() {
  return getRuleContext<ExprParser::ExprMulContext>(0);
}

tree::TerminalNode* ExprParser::AddSubContext::ADD() {
  return getToken(ExprParser::ADD, 0);
}

tree::TerminalNode* ExprParser::AddSubContext::SUB() {
  return getToken(ExprParser::SUB, 0);
}

ExprParser::AddSubContext::AddSubContext(ExprAddContext *ctx) { copyFrom(ctx); }


std::any ExprParser::AddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ToMulContext ------------------------------------------------------------------

ExprParser::ExprMulContext* ExprParser::ToMulContext::exprMul() {
  return getRuleContext<ExprParser::ExprMulContext>(0);
}

ExprParser::ToMulContext::ToMulContext(ExprAddContext *ctx) { copyFrom(ctx); }


std::any ExprParser::ToMulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitToMul(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ExprAddContext* ExprParser::exprAdd() {
   return exprAdd(0);
}

ExprParser::ExprAddContext* ExprParser::exprAdd(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::ExprAddContext *_localctx = _tracker.createInstance<ExprAddContext>(_ctx, parentState);
  ExprParser::ExprAddContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, ExprParser::RuleExprAdd, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<ToMulContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(28);
    exprMul(0);
    _ctx->stop = _input->LT(-1);
    setState(35);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExprAddContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleExprAdd);
        setState(30);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(31);
        _la = _input->LA(1);
        if (!(_la == ExprParser::ADD

        || _la == ExprParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(32);
        exprMul(0); 
      }
      setState(37);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExprMulContext ------------------------------------------------------------------

ExprParser::ExprMulContext::ExprMulContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::ExprMulContext::getRuleIndex() const {
  return ExprParser::RuleExprMul;
}

void ExprParser::ExprMulContext::copyFrom(ExprMulContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ToFactorContext ------------------------------------------------------------------

ExprParser::ExprFactorContext* ExprParser::ToFactorContext::exprFactor() {
  return getRuleContext<ExprParser::ExprFactorContext>(0);
}

ExprParser::ToFactorContext::ToFactorContext(ExprMulContext *ctx) { copyFrom(ctx); }


std::any ExprParser::ToFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitToFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivContext ------------------------------------------------------------------

ExprParser::ExprMulContext* ExprParser::MulDivContext::exprMul() {
  return getRuleContext<ExprParser::ExprMulContext>(0);
}

ExprParser::ExprFactorContext* ExprParser::MulDivContext::exprFactor() {
  return getRuleContext<ExprParser::ExprFactorContext>(0);
}

tree::TerminalNode* ExprParser::MulDivContext::MUL() {
  return getToken(ExprParser::MUL, 0);
}

tree::TerminalNode* ExprParser::MulDivContext::DIV() {
  return getToken(ExprParser::DIV, 0);
}

ExprParser::MulDivContext::MulDivContext(ExprMulContext *ctx) { copyFrom(ctx); }


std::any ExprParser::MulDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMulDiv(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ExprMulContext* ExprParser::exprMul() {
   return exprMul(0);
}

ExprParser::ExprMulContext* ExprParser::exprMul(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::ExprMulContext *_localctx = _tracker.createInstance<ExprMulContext>(_ctx, parentState);
  ExprParser::ExprMulContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, ExprParser::RuleExprMul, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<ToFactorContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(39);
    exprFactor();
    _ctx->stop = _input->LT(-1);
    setState(46);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MulDivContext>(_tracker.createInstance<ExprMulContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleExprMul);
        setState(41);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(42);
        _la = _input->LA(1);
        if (!(_la == ExprParser::MUL

        || _la == ExprParser::DIV)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(43);
        exprFactor(); 
      }
      setState(48);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExprFactorContext ------------------------------------------------------------------

ExprParser::ExprFactorContext::ExprFactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::ExprFactorContext::getRuleIndex() const {
  return ExprParser::RuleExprFactor;
}

void ExprParser::ExprFactorContext::copyFrom(ExprFactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParensContext ------------------------------------------------------------------

ExprParser::ExprAddContext* ExprParser::ParensContext::exprAdd() {
  return getRuleContext<ExprParser::ExprAddContext>(0);
}

ExprParser::ParensContext::ParensContext(ExprFactorContext *ctx) { copyFrom(ctx); }


std::any ExprParser::ParensContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitParens(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::IdContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::IdContext::IdContext(ExprFactorContext *ctx) { copyFrom(ctx); }


std::any ExprParser::IdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::IntContext::INT() {
  return getToken(ExprParser::INT, 0);
}

ExprParser::IntContext::IntContext(ExprFactorContext *ctx) { copyFrom(ctx); }


std::any ExprParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::ExprFactorContext* ExprParser::exprFactor() {
  ExprFactorContext *_localctx = _tracker.createInstance<ExprFactorContext>(_ctx, getState());
  enterRule(_localctx, 8, ExprParser::RuleExprFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(55);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::ID: {
        _localctx = _tracker.createInstance<ExprParser::IdContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(49);
        match(ExprParser::ID);
        break;
      }

      case ExprParser::INT: {
        _localctx = _tracker.createInstance<ExprParser::IntContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(50);
        match(ExprParser::INT);
        break;
      }

      case ExprParser::T__2: {
        _localctx = _tracker.createInstance<ExprParser::ParensContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(51);
        match(ExprParser::T__2);
        setState(52);
        exprAdd(0);
        setState(53);
        match(ExprParser::T__3);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprAddSempred(antlrcpp::downCast<ExprAddContext *>(context), predicateIndex);
    case 3: return exprMulSempred(antlrcpp::downCast<ExprMulContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprAddSempred(ExprAddContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprMulSempred(ExprMulContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void ExprParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  exprParserInitialize();
#else
  ::antlr4::internal::call_once(exprParserOnceFlag, exprParserInitialize);
#endif
}
