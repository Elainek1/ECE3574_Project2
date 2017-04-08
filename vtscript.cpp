#include "interpreter.hpp"
#include "environment.hpp"
#include "expression.hpp"
#include "tokenize.hpp"
#include "interpreter_semantic_error.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <iomanip>
using namespace std;
void replMode();

int main(int argc, char*argv[]){
	//Interpreter interpreter;
	string input;  //for storing the filename grabbed from commandline
	std::vector<std::string>  arguments;
    for(int i = 0; i < argc; ++i){
		arguments.push_back(argv[i]);
	}
	if((argc == 1)|| (argc > 3)){ 	//if no arguments then enter repel mode	
		replMode();
	}
	else if(argc == 2){ //if a file name has been given then open it to become an input stream
		Interpreter interpreter;
		ifstream inputString(arguments[argc - 1]);
		if (!inputString.good()){
			cout << "Error: Could not open file\n";
			return EXIT_FAILURE; //if file doesnt open then return failure
		}
		if (!interpreter.parse(inputString)){
			cout << "Error: Parsing error\n";
			return EXIT_FAILURE;  //if parsing fails then return failure
		}
		try{ //otherwise try evaluating tree
			Expression result = interpreter.eval();
			interpreter.printExpression(result);
		}
		catch (InterpreterSemanticError error){ //catch error thrown
			std::cout << error.what() << "\n";  //print out error
			return EXIT_FAILURE; //return exit failure
		}
	}
	else if(argc == 3){ //if -e flag is given then use the next argument as input
		Interpreter interpreter;
		if(arguments[argc-2]=="-e"){
			input = arguments[argc-1];
			std::istringstream inputString(input);
			if (!interpreter.parse(inputString)){
				cout << "Error: Parsing error\n";
				return EXIT_FAILURE;
			}
			try{
				Expression result = interpreter.eval();
					interpreter.printExpression(result);
			}
			catch (InterpreterSemanticError error){
				std::cout << error.what() << "\n";
				return EXIT_FAILURE;
			}
		}
		else{ //otherwise the argument wasn't what it was expecting
			cout << "Error: Unexpected arguments of " << arguments[argc-2] << "\n"; //not appropriate -e flag specified so return with exit failure
			return EXIT_FAILURE;
		}
	}
	else{
		cout << "Error: Unexpected number of arguments" << "\n"; //no filename specified so return with exit failure
		return EXIT_FAILURE;
	}
    return EXIT_SUCCESS;  //return success
}

void replMode()
{
	Interpreter interpreter;
	std::string input;
	while (true) {
		cout << "vtscript>";
		std::getline(cin, input);
		if (input == "quit") { //if wants to quit then return
			break;
		}
		else if (input != "") {
			std::istringstream inputString(input);
			if (!interpreter.parse(inputString)) { //if parse fails then print error
				cout << "Error: Parsing error" << endl;
			}
			else { //if not failed then try to build tree and evaluate it
				try { //try to evaluate the tree
					Expression result = interpreter.eval();
					interpreter.printExpression(result);
					cout << "\n";
				}
				catch (InterpreterSemanticError error) { //if error thrown then catch it and display the error
					std::cout << error.what() << "\n";
				}
			}
		}
	}
}
