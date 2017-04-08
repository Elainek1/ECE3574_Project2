#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <string>
#include "environment.hpp"
#include "expression.hpp"


class Interpreter
{
public:
	// Default construct an Interpreter with the default environment and an empty AST
	Interpreter();
	~Interpreter();

	// Given a vtscript program as a std::istream, attempt to parse into an internal AST
	// return true on success, false on failure
	bool parse(std::istream & expression) noexcept;

	// Evaluate the current AST and return the resulting Expression
	// throws InterpreterSemanticError if a semantic error is encountered
	// the exception message string should document the nature of the semantic error 
	Expression eval();
	Expression evalExp(Expression * curLevel);
	std::string printExpression(Expression curLevel); //print expression
	//void reset(); //resets the interpreter environment
	std::vector<Expression> getDrawList();
private:
	Environment environment; //intialize the environment
	std::vector<Expression> drawList;
	
	//used to point to the root of the tree
	Expression * rootAST;

	//builds the AST
	bool buildAST(std::vector<std::string> tokens);

	//deletes the AST
	void deleteAST(Expression * curLevel);

	Expression* checkToken(std::string token, Expression * curLevel); //this reads in the token and checks for parsing error

	//void traversePost(Expression* curLevel); //traverses the tree and prints it out

	Expression checkExp(Expression * curLevel);
	Expression checkEnviroExp(Expression * curLevel);
	Expression checkSpecialExp(Expression * curLevel);

	//functions to evaluate the expressions
	Expression add(Expression * curLevel);
	Expression divide(Expression * curLevel);
	Expression multiply(Expression * curLevel);
	Expression subtract(Expression * curLevel);
	Expression equal(Expression * curLevel);
	Expression greaterEqual(Expression * curLevel);
	Expression greater(Expression * curLevel);
	Expression lessEqual(Expression * curLevel);
	Expression less(Expression * curLevel);
	Expression orFunct(Expression * curLevel);
	Expression andFunct(Expression * curLevel);
	Expression notFunct(Expression * curLevel);
	Expression ifExpression(Expression * curLevel);
	Expression begin(Expression * curLevel);
	Expression define(Expression * curLevel);
	Expression point(Expression * curLevel);
	Expression line(Expression * curLevel);
	Expression arc(Expression * curLevel);
	Expression draw(Expression * curLevel);
	Expression sinExp(Expression * curLevel);
	Expression cosExp(Expression * curLevel);
	Expression arctanExp(Expression * curLevel);
};



#endif