#include <qt_interpreter.hpp>

#include <QWidget>
#include "interpreter.hpp"
#include <qstring.h>


QtInterpreter::QtInterpreter(QObject * parent)
{
	interpreter = new Interpreter;
	//QObject::connect(interpreter, SIGNAL(info(QString message)), messagePart, SLOT(info(QString message));
}

void QtInterpreter::parseAndEvaluate(QString entry)
{
	if (entry.size() > 0)
	{
		emit info(entry);
	}
}