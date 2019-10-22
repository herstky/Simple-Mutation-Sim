#include "simulation.h"

#include "board.h"
#include "creature.h"

Simulation::Simulation(QWidget* parent)
	: QMainWindow(parent), 
	  width(800), height(600), 
	  animatedTimeStep(1000 / 33), 
	  unanimatedTimeStep(0)
{
	ui.setupUi(this);
	ui.graphicsView->setFixedSize(width, height);
	scene.setItemIndexMethod(QGraphicsScene::NoIndex);
	ui.graphicsView->setScene(&scene);
	ui.graphicsView->setRenderHint(QPainter::Antialiasing);
	ui.graphicsView->setCacheMode(QGraphicsView::CacheBackground);
	ui.graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

	initialize();

	connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance);
	timer.start(animatedTimeStep);
	
	playPauseBtn = ui.playPause;
	playPauseBtn->setText("Pause");
	connect(playPauseBtn, SIGNAL(released()), this, SLOT(update()));
	connect(ui.next, SIGNAL(released()), this, SLOT(next()));
	connect(ui.restart, SIGNAL(released()), this, SLOT(restart()));
	connect(ui.animate, SIGNAL(clicked(bool)), this, SLOT(toggleAnimation()));
}

void Simulation::initialize()
{
	scene.clear();
	Board* board = new Board(width, height);
	board->setPos(0, 0);
	scene.addItem(board);
	for (int i = 0; i < 10; i++)
	{
		Creature* creature = new Creature(board, &ui);
		creature->setCacheMode(QGraphicsItem::ItemCoordinateCache);
		scene.addItem(creature);
	}
}

void Simulation::update()
{
	if (timer.isActive())
	{
		timer.stop();
		playPauseBtn->setText("Play");
	}
	else
	{
		timer.start();
		playPauseBtn->setText("Pause");
	}
}

void Simulation::next()
{
	if (timer.isActive())
	{
		return;
	}
	scene.advance();
}

void Simulation::restart()
{
	initialize();
}

void Simulation::toggleAnimation()
{
	if (ui.animate->checkState())
	{
		timer.start(animatedTimeStep);
	}
	else
	{
		timer.start(unanimatedTimeStep);
	}
}