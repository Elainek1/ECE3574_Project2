#include "repl_widget.hpp"


#include <QWidget>
#include <qlayout.h>
#include <qlineedit.h>
#include <qlabel.h>

// Default construct a MainWindow
REPLWidget::REPLWidget(QWidget * parent) : QWidget(parent)
{
	replWid = new QLineEdit;
	replLabel = new QLabel("vtscript>");
	auto layout = new QGridLayout;
	layout->addWidget(replLabel, 0, 0);
	layout->addWidget(replWid, 0, 1);
	this->setLayout(layout);
}