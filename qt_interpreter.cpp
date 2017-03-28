#include <qt_interpreter.hpp>

#include <QWidget>
#include "interpreter.hpp"


QtInterpreter::QtInterpreter(QObject * parent)
{
	interpreter = new Interpreter;

}

void QtInterpreter::parseAndEvaluate(QString entry)
{

}