#include "MainWindow.h"
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>

MainWindow::MainWindow()
{
	createMenus();
}

void MainWindow::createMenus()
{
	fileMenu = new QMenu("&File");
	menuBar()->addMenu(fileMenu);
}