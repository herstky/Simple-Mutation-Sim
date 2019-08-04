#include "Creature.h"
#include <algorithm>
#include <QPainter>
#include "qrandom.h"

Creature::Creature()
	: size(30),
	  speed(5),
	  direction(QRandomGenerator::global()->bounded(360)),
	  color(0, 0, 200, 128),
	  width(800),
	  height(600),
	  ui(NULL)
{
	setCacheMode(QGraphicsItem::DeviceCoordinateCache);
	setPos(QRandomGenerator::global()->bounded(width - size), QRandomGenerator::global()->bounded(height - size));
}

Creature::Creature(Board* board, Ui::ReplicatorClass* ui)
	: size(30),
	  speed(5),
	  direction(QRandomGenerator::global()->bounded(360)),
	  color(0, 0, 200, 128),
	  width(board->width),
	  height(board->height),
	  ui(ui)
{
	setCacheMode(QGraphicsItem::DeviceCoordinateCache);
	setPos(QRandomGenerator::global()->bounded(width - size), QRandomGenerator::global()->bounded(height - size));
}

QRectF Creature::boundingRect() const
{
	return QRectF(0, 0, size, size);
}

QPainterPath Creature::shape()const
{
	QPainterPath path;
	path.addEllipse(0, 0, size, size);
	return path;
}

void Creature::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
	painter->setBrush(color);
	painter->drawEllipse(0, 0, size, size);
}

void Creature::advance(int step)
{
	if (!step)
	{
		return;
	}
	
	if (ui->animate->checkState())
	{
		show();
	}
	else
	{
		hide();
	}

	double dx = speed  * std::cos(direction);
	double dy = speed * std::sin(direction);

	if (pos().x() + dx + size >= static_cast<double>(width) - 1.0)
	{
		direction = std::_Pi - direction;
	}
	else if (static_cast<int>(pos().x()) + dx <= 0)
	{
		direction = std::_Pi - direction;
	}
	if (static_cast<int>(pos().y()) + dy + size >= static_cast<double>(height) - 1.0)
	{
		direction = 2 * std::_Pi - direction;
	}
	else if (static_cast<int>(pos().y()) + dy <= 0)
	{
		direction = 2 * std::_Pi - direction;
	}

	dx = speed * std::cos(direction);
	dy = speed * std::sin(direction);
	setPos(mapToParent(dx, dy));
}