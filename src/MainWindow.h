#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MainEditor.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableView>

class MainWindow : public QMainWindow
{
public:
	MainWindow();
private:
	void createActions();
	void createMenus();

	QWidget *centralWidget;
	QTableView *objectList;
	MainEditor *mainEditor;

	QMenu *fileMenu;
	QAction *exitAction;
};

#endif //MAINWINDOW_H