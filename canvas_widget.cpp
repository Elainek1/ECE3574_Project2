#include "canvas_widget.hpp"
#include <qwidget.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qgridlayout.h>

CanvasWidget::CanvasWidget(QWidget * parent)
{
	scene = new QGraphicsScene(this);
	view = new QGraphicsView(scene, this);
	auto layout = new QGridLayout;
	layout->addWidget(view);
	this->setLayout(layout);
}

void CanvasWidget::addGraphic(QGraphicsItem * item)
{
	scene->addItem(item);
}