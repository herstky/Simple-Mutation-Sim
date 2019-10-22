#pragma once
#include <QGraphicsItem>
#include "math.h"

#include "board.h"
#include "simulation.h"
#include "ui_replicator.h"

class Creature :
	public QGraphicsItem
{
public:
	Creature();
	Creature(Board*, Ui::ReplicatorClass* ui);
	QRectF boundingRect() const override;
	QPainterPath shape() const override;
	void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

protected:
	int size;
	double speed;
	double direction;
	QColor color;
	void advance(int) override;

private:
	int width;
	int height;
	Ui::ReplicatorClass* ui;
};

