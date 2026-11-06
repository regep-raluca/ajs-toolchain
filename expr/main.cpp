#include "generated/ExprLexer.h"
#include "generated/ExprParser.h"
#include "generated/ExprVisitor.h"
using namespace antlr4;

#include <iostream>
#include <fstream>
#include <set>
#include <cassert>
#include <sstream>
using namespace std;

class CGenExprVisitor : public ExprVisitor {
public:
	// Set to store unique variable identifiers encountered across expressions.
	set<string> vars;

	// Buffer to accumulate generated C statements in sequence.
	stringstream body;

	any visitProg(ExprParser::ProgContext* ctx) override {
		// Traverse all child statements in the program to populate vars and body.
		visitChildren(ctx);

		stringstream all;
		all << "\n";
		all << "#include <stdio.h>\n\n";
		all << "int main() {\n";

		// Declare and initialize every captured variable to zero at main scope.
		for (const auto& varName : vars) {
			all << "      int " << varName << " = 0;\n";
		}

		// Append the accumulated statement body.
		all << body.str();

		all << "      return 0;\n";
		all << "}\n";

		return all.str();
	}

	any visitPrintExpr(ExprParser::PrintExprContext* ctx) override {
		cerr << "#printExpr" << endl;

		// Recursively evaluate the expression subtree to retrieve its C string representation.
		auto r = ctx->exprAdd()->accept(this);
		auto exprStr = any_cast<string>(r);

		// Append an evaluative print statement to output the calculated result.
		body << "      printf(\"%d\\n\", (" << exprStr << "));\n";

		return any();
	}

	any visitAssign(ExprParser::AssignContext* ctx) override {
		cerr << "#assign" << endl;

		// Extract identifier token string and track it for declarations.
		auto var = ctx->ID()->getText();
		vars.insert(var);

		// Recursively evaluate the right-hand side expression.
		auto val = ctx->exprAdd()->accept(this);
		auto exprStr = any_cast<string>(val);

		// Emit an assignment wrapped in a printf call to assign and print simultaneously.
		body << "      printf(\"%d\\n\", (" << var << " = " << exprStr << "));\n";

		return val;
	}

	any visitAddSub(ExprParser::AddSubContext* ctx) override {
		cerr << "#addSub" << endl;

		// Resolve left and right subexpressions recursively.
		auto left = any_cast<string>(ctx->exprAdd()->accept(this));
		auto right = any_cast<string>(ctx->exprMul()->accept(this));

		// Identify the arithmetic operator present in the matched context.
		string op = ctx->ADD() ? "+" : "-";

		// Return the subexpression enclosed in defensive parentheses.
		return string("(" + left + op + right + ")");
	}

	any visitToMul(ExprParser::ToMulContext* ctx) override {
		cerr << "#toMul" << endl;

		// Forward traversal down to the multiplicative expression rule.
		return ctx->exprMul()->accept(this);
	}

	any visitToFactor(ExprParser::ToFactorContext* ctx) override {
		cerr << "#toFactor" << endl;

		// Forward traversal down to the primary factor rule.
		return ctx->exprFactor()->accept(this);
	}

	any visitMulDiv(ExprParser::MulDivContext* ctx) override {
		cerr << "#mulDiv" << endl;

		// Resolve left factor and right term recursively.
		auto left = any_cast<string>(ctx->exprMul()->accept(this));
		auto right = any_cast<string>(ctx->exprFactor()->accept(this));

		// Identify the multiplicative operator present in the matched context.
		string op = ctx->MUL() ? "*" : "/";

		// Return the subexpression enclosed in defensive parentheses.
		return string("(" + left + op + right + ")");
	}

	any visitId(ExprParser::IdContext* ctx) override {
		cerr << "#id: " << ctx->ID()->getText() << endl;

		// Track variable usage even if it appears solely as an operand.
		auto name = ctx->ID()->getText();
		vars.insert(name);

		return name;
	}

	any visitInt(ExprParser::IntContext* ctx) override {
		cerr << "#int: " << ctx->INT()->getText() << endl;

		// Return the literal string directly from the terminal token.
		return ctx->INT()->getText();
	}

	any visitParens(ExprParser::ParensContext* ctx) override {
		cerr << "#parens" << endl;

		// Unwrap nested expression within explicit parenthesis grouping.
		return ctx->exprAdd()->accept(this);
	}
};

int main(int argc, char** argv) {
	// Validate CLI argument counts.
	if (argc != 2) {
		cerr << "Usage: expr <file>" << endl;
		return EXIT_FAILURE;
	}

	// Open input stream for source expression script.
	ifstream stream;
	stream.open(argv[1]);

	if (!stream.good()) {
		cerr << "could not open file: " << argv[1] << endl;
		return EXIT_FAILURE;
	}

	try {
		// Feed input stream into ANTLR lexer and token buffer.
		ANTLRInputStream input(stream);
		ExprLexer lexer(&input);
		CommonTokenStream tokens(&lexer);

		// Build parse tree starting from the root grammar rule.
		ExprParser parser(&tokens);
		tree::ParseTree* tree = parser.prog();

		// Traverse AST and synthesize C target program string.
		CGenExprVisitor cGenVisitor;
		auto allCode = any_cast<string>(cGenVisitor.visit(tree));
		cout << allCode << endl;

		// Write synthesized code out to destination file.
		ofstream fout("out.c");
		if (fout.is_open()) {
			fout << allCode;
			fout.close();
			cout << "The code has been saved in the \"out.c\" file." << endl;
		}
		else {
			cerr << "The file \"out.c\" couldn't be opened." << endl;
		}

	}
	catch (const exception& e) {
		cerr << "error: " << e.what() << endl;
	}

	return 0;
}