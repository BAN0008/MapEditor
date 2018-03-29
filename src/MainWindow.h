#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow
{
public:
	MainWindow();
private:
	void createMenus();
	QMenu *fileMenu;
};

#endif //MAINWINDOW_H