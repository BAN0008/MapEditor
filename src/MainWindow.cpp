#include "MainWindow.h"
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>

MainWindow::MainWindow()
{
	setWindowTitle("Map Editor");
	mainEditor = new MainEditor;
	setCentralWidget(mainEditor);

	createActions();
	createMenus();
}

void MainWindow::createActions()
{
	exitAction = new QAction("E&xit");
	connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus()
{
	fileMenu = new QMenu("&File");
	fileMenu->addAction(exitAction);
	menuBar()->addMenu(fileMenu);
}