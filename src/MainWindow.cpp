#include "MainWindow.h"
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtCore/QItemSelectionModel>
#include <QtGui/QKeyEvent>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QStatusBar>
#include <QtGui/QBitmap>
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

    toolBar = new QToolBar();
    
    QPixmap px = QIcon::fromTheme("list-add-symbolic").pixmap(24, 24);
    QPixmap pxr(px.size());
    pxr.fill(QColor(0, 150, 0));
    pxr.setMask(px.createMaskFromColor(Qt::transparent));
    addModeButton = new QToolButton();
    addModeButton->setIcon(QIcon(pxr));
    addModeButton->setToolTip("Add Mode");
    addModeButton->setCheckable(true);
    addModeButton->setAutoExclusive(true);
    toolBar->addWidget(addModeButton);


    px = QIcon::fromTheme("edit-select-all-symbolic").pixmap(24, 24);
    pxr = QPixmap(px.size());
    pxr.fill(QColor(0, 0, 150));
    pxr.setMask(px.createMaskFromColor(Qt::transparent));
    selectModeButton = new QToolButton();
    selectModeButton->setIcon(QIcon(pxr));
    selectModeButton->setToolTip("Select Mode");
    selectModeButton->setCheckable(true);
    selectModeButton->setAutoExclusive(true);
    toolBar->addWidget(selectModeButton);

    px = QIcon::fromTheme("list-remove-symbolic").pixmap(24, 24);
    pxr = QPixmap(px.size());
    pxr.fill(QColor(150, 0, 0));
    pxr.setMask(px.createMaskFromColor(Qt::transparent));
    removeModeButton = new QToolButton();
    removeModeButton->setIcon(QIcon(pxr));
    removeModeButton->setToolTip("Remove Mode");
    removeModeButton->setCheckable(true);
    removeModeButton->setAutoExclusive(true);
    toolBar->addWidget(removeModeButton);

    addToolBar(toolBar);
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
            mainEditor->changeModeAdd();
            break;
        case Qt::Key_W:
            mainEditor->changeModeSelect();
            break;
        case Qt::Key_E:
            mainEditor->changeModeRemove();
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