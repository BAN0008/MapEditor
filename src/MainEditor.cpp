#include "MainEditor.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include "Object.h"

MainEditor::MainEditor()
{
	objects.push_back(new Object());
	objects[0]->x = 32;
	objects[0]->y = 32;
	update();
}

void MainEditor::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);
    QPainter painter(this);

    painter.setBrush(Qt::Dense5Pattern);
    for (unsigned i = 0; i < objects.size(); i++)
    {
    	painter.drawRect(objects[i]->x, objects[i]->y, 32, 32);
    }

    int gridCellWidth = 32;
    int gridCellHeight = 32;
    for (int i = 0; i < 50; i++)
    {
    	painter.drawLine(i * gridCellWidth, 0, i * gridCellWidth, 50 * 32);
    	painter.drawLine(0, i * gridCellHeight, 50 * 32, i * gridCellHeight);
    }
}