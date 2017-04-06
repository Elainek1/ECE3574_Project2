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
	for (int i = 0; i < argc; ++i){
		arguments.push_back(argv[i]);
	}
	// code can use arguments as a C++ vector of C++ strings 
	//if no arguments then enter repel mode
	if (argc == 1){
		MainWindow * window = new MainWindow();
		window->setMinimumSize(800, 600);
		window->show();
	}
	//if a file name has been given then open it to become an input stream
	else if (argc == 2){
		filename = arguments[argc - 1];
		MainWindow * window = new MainWindow(filename);
		window->setMinimumSize(800, 600);
		window->show();
	}
	else{
		std::cout << "Error: Invalid number of arguments";
	}
	return app.exec();
}