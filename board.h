#pragma once
#include <qgraphicsitem.h>
#include "replicator.h"

class Board :
	public QGraphicsItem
{

public:
	const double scalingFactor;
	const int width;
	const int height;

	Board();
	Board(int, int);
	QRectF boundingRect() const override;
	QPainterPath shape() const override;
	void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

protected:
	void advance(int) override;

private:
	QColor color;
};

