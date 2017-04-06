#include "qgraphics_arc_item.hpp"
#include <QWidget>
#include <QGraphicsEllipseItem>
#include <QPainter>

QGraphicsArcItem::QGraphicsArcItem(QGraphicsEllipseItem * parent) : QGraphicsEllipseItem(parent)
{
	//QGraphicsEllipseItem(this);
}
/*
QGraphicsArcItem::QGraphicsArcItem(qreal x, qreal y, qreal width, qreal height, QGraphicsEllipseItem * parent) : QGraphicsEllipseItem(parent)
{
	QGraphicsEllipseItem(x, y, width, height, this);
}*/


void QGraphicsArcItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->drawArc(rect(), startAngle(), spanAngle());
}