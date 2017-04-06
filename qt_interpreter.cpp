#include <qt_interpreter.hpp>

#include <QWidget>
#include <QBrush>
#include "interpreter.hpp"
#include "expression.hpp"
#include <qstring.h>
#include <iostream>
#include <fstream>
#include "interpreter_semantic_error.hpp"
#include <sstream>
#include "qgraphics_arc_item.hpp"
#include <cmath>



QtInterpreter::QtInterpreter(QObject * parent)
{
	interpreter = new Interpreter;
	//QObject::connect(interpreter, SIGNAL(info(QString message)), messagePart, SLOT(info(QString message));
}

void QtInterpreter::parseAndEvaluate(QString entry)
{
	std::string input = entry.toStdString();
	std::istringstream inputString(input);
	bool parsePass = interpreter->parse(inputString);
	if (!parsePass){
		std::cout << "Error: Parsing error\n";
		emit error(QString("Error: Parsing error"));
	}
	else{
		try{ //otherwise try evaluating tree
			Expression result = interpreter->eval();
			std::string infoIn = interpreter->printExpression(result);
			std::cout << "\n";
			QString qstr = QString::fromStdString(infoIn);
			emit info(qstr);
			std::vector<Expression> drawList = interpreter->getDrawList();
			for (unsigned int i = 0; i < drawList.size(); i++){ //convert drawList to GraphicsItemList
				if (drawList[i].atomType == 4){ //if point
					QGraphicsEllipseItem * point = new QGraphicsEllipseItem(std::get<0>(drawList[i].valueAtom) - 2, std::get<1>(drawList[i].valueAtom) - 2, 4, 4);
					QBrush brush = QBrush(Qt::black, Qt::SolidPattern);
					point->setBrush(brush);
					emit drawGraphic(point);
				}
				else if (drawList[i].atomType == 5){ //if line
					QGraphicsLineItem * line = new QGraphicsLineItem(std::get<0>(drawList[i].startAtom), std::get<1>(drawList[i].startAtom), std::get<0>(drawList[i].endAtom), std::get<1>(drawList[i].endAtom));
					emit drawGraphic(line);
				}
				else if (drawList[i].atomType == 6){ //if arc
					QGraphicsArcItem * arc = new QGraphicsArcItem();
					qreal xSide, ySide;
					xSide = std::get<0>(drawList[i].startAtom) - std::get<0>(drawList[i].centerAtom);
					ySide = std::get<1>(drawList[i].startAtom) - std::get<1>(drawList[i].centerAtom);
					qreal radius = sqrt((xSide*xSide) + (ySide*ySide));
					qreal x, y;
					x = std::get<0>(drawList[i].centerAtom) - radius;
					y = std::get<1>(drawList[i].centerAtom) - radius;
					arc->setRect(x, y, 2*radius, 2*radius);
					double ang;
					if (xSide >= 0){
						ang = 0 - atan2(ySide, xSide);
					}
					else{
						ang = 0 - atan2(ySide, xSide);
					}
					int startAng = 16* ang * 180 / 3.14159;
					arc->setStartAngle(startAng);
					int spanAng = 1 * 16 * drawList[i].doubleAtom * 180 / 3.14159;
					arc->setSpanAngle(spanAng);
					emit drawGraphic(arc);	
				}
			}
		}
		catch (InterpreterSemanticError errorOut){
			std::cout << errorOut.what() << "\n";  //print out error
			emit error(QString(errorOut.what()));
		}
	}
}