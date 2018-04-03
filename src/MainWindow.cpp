#include "MainWindow.h"
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include "Object.h"

QTableView *objectList;

MainWindow::MainWindow()
{
	createActions();
	createMenus();

	objectList = new QTableView;
	mainEditor = new MainEditor;

	objectList->setModel(&Object::tableModel);
	objectList->setSelectionBehavior(QAbstractItemView::SelectRows);
	objectList->horizontalHeader()->setHighlightSections(false);

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(objectList);
	layout->addWidget(mainEditor);

	centralWidget = new QWidget;
	setCentralWidget(centralWidget);
	centralWidget->setLayout(layout);

	setWindowTitle("Map Editor");

	Object::create(32, 128);
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