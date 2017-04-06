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
	replWid = new QLineEdit(this);
	replLabel = new QLabel("vtscript>");
	//qInterpreter = new QtInterpreter;
	auto layout = new QGridLayout;
	layout->addWidget(replLabel, 0, 0);
	layout->addWidget(replWid, 0, 1);
	this->setLayout(layout);
	connect(replWid, SIGNAL(returnPressed()), this, SLOT(grabLine()));
	//connect(replWid, SIGNAL(keyPressEvent()), this, SLOT(keyPressUpDown()));
	histPlace = 0;
}

void REPLWidget::grabLine()
{
	QString line = replWid->displayText();
	history.push_back(line);
	histPlace = history.size();
	//qDebug() << line;
	replWid->setText("");
	emit lineEntered(line);
}

void REPLWidget::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Up) {
		// move back in history
		if (histPlace == 0)
		{
			if (history.size() > 0)
			{
				replWid->setText(history[histPlace]);
			}
			
		}
		else
		{
			replWid->setText(history[--histPlace]);
		}
	}
	else if (event->key() == Qt::Key_Down) {
		// move forward in history
		int inter = history.size() - 1;
		if (histPlace >= (inter))
		{
			replWid->setText("");
			histPlace = history.size();
		}
		else
		{
			if (histPlace < (history.size() - 1))
			{
				replWid->setText(history[++histPlace]);
			}
		}
	}
	else {
		// default handler for event
		//REPLWidget::keyPressEvent(event);
	}
}