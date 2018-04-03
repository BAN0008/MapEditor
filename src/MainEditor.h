#ifndef MAINEDITOR_H
#define MAINEDITOR_H

#include <QtWidgets/QWidget>

class MainEditor : public QWidget
{
public:
	MainEditor();
protected:
	void paintEvent(QPaintEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
};

#endif //MAINEDITOR_H