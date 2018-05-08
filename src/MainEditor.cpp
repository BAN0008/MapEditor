#include "MainEditor.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QMouseEvent>
#include "MainWindow.h"
#include "Object.h"

MainEditor::MainEditor()
{
    //setFixedSize(640, 480);
    setMinimumSize(640, 480);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setCursor(Qt::CrossCursor);
}

void MainEditor::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);
    QPainter painter(this);

    //painter.setBrush(Qt::Dense5Pattern);
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

    //TODO: If pressAction = ACTION_ADD_SINGLE draw image of object
    if (pressAction == ACTION_ADD_SINGLE)
    {
        painter.setBrush(QBrush(Qt::black));
        painter.drawRect(lastMouseX, lastMouseY, 32, 32);
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
    switch (event->button())
    {
        case Qt::LeftButton:
            if (controlDown)
            {
                if (!shiftDown && !altDown)
                {
                    if (mode == MODE_SELECT)
                    {
                        std::vector<unsigned> tmp = Object::find(QPoint(event->pos()));
                        if (tmp.size() > 0)
                        {
                            Object::addToSelection(tmp[tmp.size() - 1]);
                        }
                        pressAction = ACTION_SELECT_KEEP;
                    }
                    else
                    {
                        pressAction = ACTION_NONE;
                    }
                }
            }
            else
            {
                if (shiftDown)
                {
                    if (!altDown)
                    {
                        std::vector<unsigned> tmp;
                        switch (mode)
                        {
                            case MODE_ADD:
                                //TODO: If no collision(Depending on options) Add object at mouse position(snapped depending on options)
                                pressAction = ACTION_ADD_MULTIPLE;
                                break;
                            case MODE_REMOVE:
                                tmp = Object::find(QPoint(event->pos()));
                                if (tmp.size() > 0)
                                {
                                    Object::remove(objects[tmp[tmp.size() - 1]]);
                                }
                                pressAction = ACTION_REMOVE_MULTIPLE;
                                break;
                            default:
                                pressAction = ACTION_NONE;
                                break;
                        }
                    }
                }
                else
                {
                    if (altDown)
                    {
                        switch (mode)
                        {
                            case MODE_ADD:
                                //TODO: Add Fill
                                break;
                            case MODE_SELECT:
                                //TODO: Magic Select
                                break;

                        }
                        pressAction = ACTION_NONE;
                    }
                    else
                    {
                        std::vector<unsigned> tmp;
                        switch (mode)
                        {
                            case MODE_ADD:
                                pressAction = ACTION_ADD_SINGLE;
                                break;
                            case MODE_SELECT:
                                objectList->clearSelection();
                                tmp = Object::find(QPoint(event->pos()));
                                if (tmp.size() > 0)
                                {
                                    Object::addToSelection(tmp[tmp.size() - 1]);
                                }
                                pressAction = ACTION_SELECT;
                                break;
                            case MODE_REMOVE:
                                tmp = Object::find(QPoint(event->pos()));
                                if (tmp.size() > 0)
                                {
                                    Object::remove(objects[tmp[tmp.size() - 1]]);
                                }
                                pressAction = ACTION_NONE;
                                break;
                        }
                    }
                }
            }
    }
    lastMouseX = event->pos().x();
    lastMouseY = event->pos().y();
    update();
}

void MainEditor::mouseMoveEvent(QMouseEvent *event)
{
    std::vector<unsigned> tmp;
    switch (pressAction)
    {
        case ACTION_ADD_MULTIPLE:
            if (Object::find(QRect(event->pos(), QSize(32, 32))).size() == 0)
            {
                Object::create(event->pos().x(), event->pos().y());
            }
            break;
        case ACTION_REMOVE_MULTIPLE:
            tmp = Object::find(QPoint(event->pos()));
            if (tmp.size() > 0)
            {
                Object::remove(objects[tmp[tmp.size() - 1]]);
            }
            break;
    }
    lastMouseX = event->pos().x();
    lastMouseY = event->pos().y();
    update();
}

void MainEditor::mouseReleaseEvent(QMouseEvent *event)
{
    switch (event->button())
    {
        case Qt::LeftButton:
            std::vector<unsigned> tmp;
            switch (pressAction)
            {
                case ACTION_ADD_SINGLE:
                    Object::create(event->pos().x(), event->pos().y());
                    objectList->clearSelection();
                    Object::addToSelection(objects.size() - 1);
                    break;
            }
            break;
    }
    pressAction = ACTION_NONE;
    update();
}

void MainEditor::changeModeAdd()
{
    mode = MODE_ADD;
    mainWindow->addModeButton->setChecked(true);
}
void MainEditor::changeModeSelect()
{
    mode = MODE_SELECT;
    mainWindow->selectModeButton->setChecked(true);
}
void MainEditor::changeModeRemove()
{
    mode = MODE_REMOVE;
    mainWindow->removeModeButton->setChecked(true);
}