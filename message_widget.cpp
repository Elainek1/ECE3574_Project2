#include "message_widget.hpp"


#include <QWidget>
#include <qlayout.h>
#include <qlineedit.h>
#include <qlabel.h>

// Default construct a MainWindow
MessageWidget::MessageWidget(QWidget * parent) : QWidget(parent)
{
	messageWid = new QLineEdit(this);
	messageLabel = new QLabel("Message:");
	messageWid->setReadOnly(true);
	auto layout = new QGridLayout;
	layout->addWidget(messageLabel, 0, 0);
	layout->addWidget(messageWid, 0, 1);
	this->setLayout(layout);
}

void MessageWidget::info(QString message)
{
	//messageWid->setStyleSheet("QLineEdit {background-color: white;}");
	QPalette *palette = new QPalette(Qt::white);
	palette->setColor(QPalette::Highlight, Qt::white);
	palette->setColor(QPalette::Text, Qt::black);

	messageWid->setPalette(*palette);
	messageWid->setText(message);
	//messageWid->selectAll();
}

void MessageWidget::error(QString message)
{
	//messageWid->setStyleSheet("QLineEdit {background-color: red;}");
	QPalette *palette = new QPalette(Qt::red);
	
	//palette->setColor(QPalette::Base, Qt::red);
	//palette->setColor(QPalette::Text, Qt::white);
	palette->setColor(QPalette::Highlight, Qt::red);
	palette->setColor(QPalette::Background, Qt::red);
	messageWid->setPalette(*palette);
	messageWid->setText(message);
	messageWid->selectAll();
}