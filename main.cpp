#include "simulation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Simulation sim;
	sim.setWindowState(Qt::WindowMaximized);
	sim.show();
	return a.exec();
}
