#include "main_window.hpp"
#include "message_widget.hpp"
#include "canvas_widget.hpp"
#include "repl_widget.hpp"



#include <QWidget>
#include <qgridlayout.h>
#include <qstring.h>

// Default construct a MainWindow
MainWindow::MainWindow(QWidget * parent) : QWidget(parent)
{
	messagePart = new MessageWidget;
	replPart = new REPLWidget;
	canvasPart = new CanvasWidget;
	auto layout = new QGridLayout;
	layout->addWidget(messagePart, 0, 0);
	layout->addWidget(canvasPart, 1, 0);
	layout->addWidget(replPart, 2, 0);
	this->setLayout(layout);
}

// Default construct a MainWidow, using filename as the script file to attempt to preload
MainWindow::MainWindow(std::string filename, QWidget * parent)
{
	messagePart = new MessageWidget;
	auto layout = new QGridLayout;
	layout->addWidget(messagePart, 0, 0);
	this->setLayout(layout);
}