#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MainEditor.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableView>

class MainWindow : public QMainWindow
{
public:
	MainWindow();
protected:
	void keyPressEvent(QKeyEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;
private:
	void createActions();
	void createMenus();

	QWidget *centralWidget;
	MainEditor *mainEditor;

	QMenu *fileMenu;
	QAction *exitAction;
};

extern QTableView *objectList;

#endif //MAINWINDOW_H