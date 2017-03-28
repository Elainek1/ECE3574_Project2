#ifndef QT_INTERPRETER_H
#define QT_INTERPRETER_H

#include <QtWidgets>
#include <QDebug>
#include <QWidget>

#include "interpreter.hpp"

class QtInterpreter : public QObject {
  Q_OBJECT
public:
	// Default construct an QtInterpreter with the default environment and an empty AST
	QtInterpreter(QObject * parent = nullptr);
signals:
	// a signal emitting a graphic to be drawn as a pointer
	void drawGraphic(QGraphicsItem * item);

	// a signal emitting an informational message
	void info(QString message);

	// a signal emitting an error message
	void error(QString message);

public slots:
	// a public slot that accepts and expression string and parses/evaluates it
	void parseAndEvaluate(QString entry);
private slots:

private:
	Interpreter * interpreter;
};

#endif