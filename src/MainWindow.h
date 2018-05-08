#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MainEditor.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>

class MainWindow : public QMainWindow
{
public:
	MainWindow();

	QToolButton *addModeButton;
	QToolButton *selectModeButton;
	QToolButton *removeModeButton;

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

	QToolBar *toolBar;
};

extern QTableView *objectList;
extern MainWindow *mainWindow;

#endif //MAINWINDOW_H