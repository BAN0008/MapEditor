#ifndef MAINEDITOR_H
#define MAINEDITOR_H

//Define Modes
#define MODE_ADD 0
#define MODE_SELECT 1
#define MODE_REMOVE 2

//Define Actions(See Plan.md Mode Controls and MainEditor.cpp:mousePressEvent)
#define ACTION_NONE 0
#define ACTION_ADD_SINGLE 1
#define ACTION_ADD_MULTIPLE 2
#define ACTION_SELECT 3
#define ACTION_SELECT_MOVED 4
#define ACTION_SELECT_KEEP 5
#define ACTION_SELECT_KEEP_MOVED 6
#define ACTION_REMOVE_MULTIPLE 7

#include <QtWidgets/QWidget>

class MainEditor : public QWidget
{
public:
	MainEditor();
	unsigned short mode = MODE_ADD;
	bool controlDown = false;
	bool shiftDown = false;
	bool altDown = false;
public slots:
	void changeModeAdd();
	void changeModeSelect();
	void changeModeRemove();

protected:
	void paintEvent(QPaintEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
private:
	unsigned short pressAction = ACTION_NONE;
	unsigned lastMouseX, lastMouseY;
};

#endif //MAINEDITOR_H