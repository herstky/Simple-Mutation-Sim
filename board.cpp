#include "board.h"

Board::Board()
	: scalingFactor(1), width(800), height(600), color(211, 211, 211) {}

Board::Board(int width, int height)
	: scalingFactor(0.9),
	  width(static_cast<int>(width * scalingFactor)),
	  height(static_cast<int>(height * scalingFactor)),
	  color(211, 211, 211) {}

QRectF Board::boundingRect() const
{
	return QRectF(0, 0, width, height);
}

QPainterPath Board::shape() const
{
	QPainterPath path;
	path.addRect(0, 0, width, height);
	return path;
}

void Board::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
	painter->setBrush(color);
	painter->drawRect(0, 0, width, height);
}

void Board::advance(int step)
{
	if (!step)
	{
		return;
	}
}