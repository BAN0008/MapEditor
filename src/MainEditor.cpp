#include "MainEditor.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QMouseEvent>
#include "Object.h"

MainEditor::MainEditor()
{
    setFixedSize(640, 480);
}

void MainEditor::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);
    QPainter painter(this);

    painter.setBrush(Qt::Dense5Pattern);
    for (unsigned i = 0; i < objects.size(); i++)
    {
        if (objects[i]->selected)
        {
            painter.setBrush(QBrush(Qt::red));
        }
        else
        {
            painter.setBrush(QBrush(Qt::black));
        }
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

void MainEditor::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        Object::create(event->pos().x(), event->pos().y());
    }
    if (event->button() == Qt::RightButton)
    {
        for (unsigned i = 0; i < objects.size(); i++)
        {
            if (objects[i]->x < event->pos().x() && objects[i]->x + 32 > event->pos().x() && objects[i]->y < event->pos().y() && objects[i]->y + 32 > event->pos().y())
            {
                Object::remove(objects[i]);
                break;
            }
        }
    }
    if (event->button() == Qt::MiddleButton)
    {
        for (unsigned i = 0; i < objects.size(); i++)
        {
            if (objects[i]->x < event->pos().x() && objects[i]->x + 32 > event->pos().x() && objects[i]->y < event->pos().y() && objects[i]->y + 32 > event->pos().y())
            {
                Object::addToSelection(objects[i]);
                break;
            }
        }
    }
    update();
}