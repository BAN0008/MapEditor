#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "MainEditor.h"

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