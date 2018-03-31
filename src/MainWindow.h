#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MainEditor.h"
#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow
{
public:
	MainWindow();
private:
	void createActions();
	void createMenus();

	MainEditor *mainEditor;

	QMenu *fileMenu;

	QAction *exitAction;
};

#endif //MAINWINDOW_H