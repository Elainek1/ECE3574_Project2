#ifndef CANVAS_WIDGET_H
#define CANVAS_WIDGET_H

#include <QGraphicsEllipseItem>

class QGraphicsArcItem : public QGraphicsEllipseItem {
	Q_OBJECT

public:
	// Default construct a QGraphicsArcItem
	QGraphicsArcItem(QGraphicsEllipseItem * parent = nullptr);
	virtual void paint() = 0;
private:

};


#endif

