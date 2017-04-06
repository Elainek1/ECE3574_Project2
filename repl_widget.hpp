#ifndef REPL_WIDGET_H
#define REPL_WIDGET_H

#include <QWidget>
#include <vector>

class QLineEdit;
class QLabel;

class REPLWidget : public QWidget {
	Q_OBJECT

public:
	// Default construct a REPLWidget
	REPLWidget(QWidget * parent = nullptr);

	// A signal that sends the current edited text as a QString when the return key is pressed.
signals:
	void lineEntered(QString );
protected:
	virtual void keyPressEvent(QKeyEvent *event);
private:
	QLineEdit * replWid;
	QLabel * replLabel;
	//QtInterpreter * qInterpreter;
	std::vector<QString> history;
	int histPlace;
private slots:
	void grabLine();
};


#endif