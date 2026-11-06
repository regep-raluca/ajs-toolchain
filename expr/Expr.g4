grammar Expr;
/** The start rule; begin parsing here. */
prog: ( stat ( NEWLINE | ';' )* )+  ;

stat:
	exprAdd 					#printExpr
	| ID '=' exprAdd 		#assign
	;

exprAdd:
	exprAdd ( ADD|SUB) exprMul	#addSub
	| exprMul						#toMul
	;

exprMul:
	exprMul (MUL|DIV) exprFactor		#mulDiv
	| exprFactor									#toFactor
	;

exprFactor:
	ID								#id
	| INT						#int
	| '(' exprAdd ')'			#parens
	;

ID : [a-zA-Z]+ ; // match identifiers
INT : [0-9]+ ; // match integers

ADD: '+' ;
SUB: '-' ;
MUL: '*' ;
DIV: '/' ;

NEWLINE: '\r'? '\n' ; // return newlines to parser (is end-statement signal)
WS : [ \t]+ -> skip ; // toss out whitespace

