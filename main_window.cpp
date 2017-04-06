#include "main_window.hpp"
#include "message_widget.hpp"
#include "canvas_widget.hpp"
#include "repl_widget.hpp"



#include <QWidget>
#include <qgridlayout.h>
#include <qstring.h>
#include <fstream>
#include <cstdint>
#include <iomanip>
#include <string>
#include <iostream>

// Default construct a MainWindow
MainWindow::MainWindow(QWidget * parent) : QWidget(parent)
{
	messagePart = new MessageWidget;
	replPart = new REPLWidget;
	canvasPart = new CanvasWidget;
	qInterpreter = new QtInterpreter;
	auto layout = new QGridLayout;
	layout->addWidget(messagePart, 0, 0);
	layout->addWidget(canvasPart, 1, 0);
	layout->addWidget(replPart, 2, 0);
	this->setLayout(layout);

	connect(replPart, SIGNAL(lineEntered(QString)), qInterpreter, SLOT(parseAndEvaluate(QString)));
	connect(qInterpreter, SIGNAL(info(QString)), messagePart, SLOT(info(QString)));
	connect(qInterpreter, SIGNAL(error(QString)), messagePart, SLOT(error(QString)));
	connect(qInterpreter, SIGNAL(drawGraphic(QGraphicsItem *)), canvasPart, SLOT(addGraphic(QGraphicsItem *)));

}

// Default construct a MainWidow, using filename as the script file to attempt to preload
MainWindow::MainWindow(std::string filename, QWidget * parent) : QWidget(parent)
{
	messagePart = new MessageWidget;
	replPart = new REPLWidget;
	canvasPart = new CanvasWidget;
	qInterpreter = new QtInterpreter;
	auto layout = new QGridLayout;
	layout->addWidget(messagePart, 0, 0);
	layout->addWidget(canvasPart, 1, 0);
	layout->addWidget(replPart, 2, 0);
	this->setLayout(layout);

	connect(replPart, SIGNAL(lineEntered(QString)), qInterpreter, SLOT(parseAndEvaluate(QString)));
	connect(qInterpreter, SIGNAL(info(QString)), messagePart, SLOT(info(QString)));
	connect(qInterpreter, SIGNAL(error(QString)), messagePart, SLOT(error(QString)));
	connect(qInterpreter, SIGNAL(drawGraphic(QGraphicsItem *)), canvasPart, SLOT(addGraphic(QGraphicsItem *)));

	std::ifstream inputString(filename);
	if (!inputString.good())
	{
		std::cout << "Error: Could not open file" << endl;
		emit qInterpreter->error(QString("Error: Could not open file"));
	}
	else
	{
		QString inputStr = "";
		std::string temp;
		while (std::getline(inputString, temp)) {
			inputStr += QString::fromStdString(temp);
			inputStr += QString('\n');
		}
		qInterpreter->parseAndEvaluate(inputStr);
	}

}