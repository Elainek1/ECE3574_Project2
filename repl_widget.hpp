#ifndef REPL_WIDGET_H
#define REPL_WIDGET_H

#include <QWidget>

class REPLWidget : public QWidget {
	Q_OBJECT

public:
	// Default construct a REPLWidget
	REPLWidget(QWidget * parent = nullptr);

	// A signal that sends the current edited text as a QString when the return key is pressed.
	void lineEntered(QString);

private:

};


#endif