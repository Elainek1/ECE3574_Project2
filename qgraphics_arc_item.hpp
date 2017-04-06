#ifndef QGRAPHICS_ARC_ITEM_H
#define QGRAPHICS_ARC_ITEM_H


#include <QGraphicsEllipseItem>

class QGraphicsArcItem : public QGraphicsEllipseItem {
	//Q_OBJECT shouldn't do this because we don't have any signals and slots in this class

public:
	// Default construct a QGraphicsArcItem
	QGraphicsArcItem(QGraphicsEllipseItem * parent = nullptr);
	//QGraphicsArcItem(qreal x, qreal y, qreal width, qreal height, QGraphicsEllipseItem * parent = nullptr);
	//QGraphicsArcItem()
	virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
private:

};

#endif

