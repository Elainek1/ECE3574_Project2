#include "repl_widget.hpp"


#include <QWidget>
#include <qdebug.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qt_interpreter.hpp>

// Default construct a MainWindow
REPLWidget::REPLWidget(QWidget * parent) : QWidget(parent)
{
	replWid = new QLineEdit;
	replLabel = new QLabel("vtscript>");
	//qInterpreter = new QtInterpreter;
	auto layout = new QGridLayout;
	layout->addWidget(replLabel, 0, 0);
	layout->addWidget(replWid, 0, 1);
	this->setLayout(layout);
	connect(replWid, SIGNAL(returnPressed()), this, SLOT(grabLine()));
	
	
}

void REPLWidget::grabLine()
{
	QString line = replWid->displayText();
	qDebug() << line;
	emit lineEntered(line);
}