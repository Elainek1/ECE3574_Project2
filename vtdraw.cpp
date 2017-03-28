#include <QApplication>
#include "main_window.hpp"
#include "message_widget.hpp"
//#include "canvas_widget.hpp"
//#include "repl_widget.hpp"
#include "interpreter.hpp"
#include "expression.hpp"
#include "environment.hpp"
#include "tokenize.hpp"
#include "interpreter_semantic_error.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdint>
#include <iomanip>

int main(int argc, char *argv[])
{

	QApplication app(argc, argv);

	Interpreter interpreter;// = Interpreter();
	std::string filename;  //for storing the filename grabbed from commandline
	std::string input;
	std::vector<std::string>  arguments;
	for (int i = 0; i < argc; ++i)
	{
		arguments.push_back(argv[i]);
	}
	// code can use arguments as a C++ vector of C++ strings 

	//if no arguments then enter repel mode
	if (argc == 1)
	{
		//std::vector<std::string> tokens;
		/*while (true)
		{
			//prompt user
			//std::cout << "vtscript>";
			//getline(std::cin, input);
			if (input == "quit")
			{
				//if wants to quit then return
				break;
			}
			else if (input != "")
			{
				//parse the input
				std::istringstream inputString(input);
				bool parsePass = interpreter.parse(inputString);
				//if parse fails then print error and reset interpreter
				if (!parsePass)
				{
					std::cout << "Error: Parsing error" << std::endl;
					//interpreter.reset();// = Interpreter(); //create reset method instead
					//return EXIT_FAILURE;
				}
				//if not failed then try to build tree and evaluate it
				else
				{

					try
					{
						//try to evaluate the tree
						Expression result = interpreter.eval();
						if (result.atomType == 0)
						{
							//call interpreter reset method
							//interpreter.reset();
						}
						else
						{
							//print out the result
							interpreter.printExpression(result);
						}
					}
					//if error thrown then catch it and display the error
					catch (InterpreterSemanticError error)
					{
						//call interpreter reset method
						//interpreter.reset();
						std::cout << error.what() << "\n";

					}
				}
			}

		}*/

		MainWindow * window = new MainWindow();
		window->setMinimumSize(800, 600);
		window->show();
	}
	//if a file name has been given then open it to become an input stream
	else if (argc == 2)
	{
		filename = arguments[argc - 1];
		std::ifstream inputString(filename);
		if (!inputString)
		{
			std::cout << "Error: Could not open file" << std::endl;
			return EXIT_FAILURE; //if file doesnt open then return failure
		}
		//parse input
		bool parsePass = interpreter.parse(inputString);
		if (!parsePass)
		{
			std::cout << "Error: Parsing error" << std::endl;
			return EXIT_FAILURE;  //if parsing fails then return failure
		}
		else
		{
			//otherwise try evaluating tree
			try
			{
				Expression result = interpreter.eval();
				/*if (result.atomType == 0)
				{
					std::cout << "Error when evaluating \n";
					return EXIT_FAILURE;  //if evaluating tree fails then return failure
				}
				else
				{*/
					//print out result
					interpreter.printExpression(result);

					MainWindow * window = new MainWindow();
					window->show();
				//}
			}
			//catch error thrown
			catch (InterpreterSemanticError error)
			{
				std::cout << error.what() << "\n";  //print out error
				return EXIT_FAILURE; //return exit failure
			}
			
		}
	}
	//if -e flag is given then use the next argument as input
	/*else if (argc == 3)
	{
		if (arguments[argc - 2] == "-e")
		{
			input = arguments[argc - 1];
			std::istringstream inputString(input);

			bool parsePass = interpreter.parse(inputString);
			if (!parsePass)
			{
				std::cout << "Error: Parsing error" << std::endl;
				return EXIT_FAILURE;
			}
			else
			{
				try
				{
					Expression result = interpreter.eval();
					if (result.atomType == 0)
					{
						std::cout << "Error when evaluating \n";
						return EXIT_FAILURE;
					}
					else
					{
						interpreter.printExpression(result);
					}
				}
				catch (InterpreterSemanticError error)
				{
					std::cout << error.what() << "\n";
					return EXIT_FAILURE;
				}
			}
		}
		//otherwise the argument wasn't what it was expecting
		else
		{
			std::cout << "Error: Unexpected arguments of " << arguments[argc - 2] << std::endl; //not appropriate -e flag specified so return with exit failure
			return EXIT_FAILURE;
		}
	}
	else
	{
		std::cout << "Error: Unexpected number of arguments" << std::endl; //no filename specified so return with exit failure
		return EXIT_FAILURE;
	}
	//return EXIT_SUCCESS;  //return success
	*/

	return app.exec();
}