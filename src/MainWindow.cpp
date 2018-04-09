#include "MainWindow.h"
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtCore/QItemSelectionModel>
#include <QtGui/QKeyEvent>
#include <QtWidgets/QStatusBar>
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
	objectList->setSelectionMode(QAbstractItemView::ExtendedSelection);
	objectList->horizontalHeader()->setHighlightSections(false);
	QObject::connect(objectList->selectionModel(), &QItemSelectionModel::selectionChanged, &Object::selectionChange);

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(objectList);
	layout->addWidget(mainEditor);

	centralWidget = new QWidget;
	setCentralWidget(centralWidget);
	centralWidget->setLayout(layout);

	//setStatusBar(new QStatusBar());

	setWindowTitle("Map Editor");
	setFocus();
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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
	qDebug("Test");
    switch (event->key())
    {
        case Qt::Key_Control:
            mainEditor->controlDown = true;
            break;
        case Qt::Key_Shift:
            mainEditor->shiftDown = true;
            break;
        case Qt::Key_Alt:
            mainEditor->altDown = true;
            break;
        case Qt::Key_Delete:
        	qDebug("Deleting Selected Objects");
        	for (int i = selectedObjects.size() - 1; i >= 0; i--)
        	{
        		Object::remove(selectedObjects[i]);
        	}
        	break;
        case Qt::Key_D:
        	if (mainEditor->controlDown && !mainEditor->shiftDown && !mainEditor->altDown)
        	{
        		objectList->clearSelection();
        	}
        	break;
        case Qt::Key_A:
        	if (mainEditor->controlDown && !mainEditor->shiftDown && !mainEditor->altDown)
        	{
        		objectList->selectAll();
        	}
        	break;
        case Qt::Key_Q:
            mainEditor->mode = MODE_ADD;
            break;
        case Qt::Key_W:
            mainEditor->mode = MODE_SELECT;
            break;
        case Qt::Key_E:
            mainEditor->mode = MODE_REMOVE;
            break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Control:
            mainEditor->controlDown = false;
            break;
        case Qt::Key_Shift:
            mainEditor->shiftDown = false;
            break;
        case Qt::Key_Alt:
        	mainEditor->altDown = false;
            break;
    }
}