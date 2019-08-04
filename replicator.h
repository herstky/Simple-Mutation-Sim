#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_replicator.h"
#include <QTimer>

class Replicator : public QMainWindow
{
	Q_OBJECT
		
public:
	Replicator(QWidget* parent = Q_NULLPTR);
	QGraphicsScene scene;

	const int width;
	const int height;
	Ui::ReplicatorClass ui;

private:
	QPushButton* playPauseBtn;
	QTimer timer;
	int animatedTimeStep;
	int unanimatedTimeStep;

	void initialize();

private slots:
	void update();
	void next();
	void restart();
	void toggleAnimation();
};
