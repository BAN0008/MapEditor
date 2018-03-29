#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
	//Create Menus
	QMenu fileMenu("&File");
	menuBar()->addMenu(fileMenu);
}