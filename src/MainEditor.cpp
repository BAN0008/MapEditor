#include "MainEditor.h"
#include <QtGui/QPainter>
#include <QtGui/QColor>

MainEditor::MainEditor()
{

}

void MainEditor::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);
    QPainter painter(this);
    int gridCellWidth = 32;
    int gridCellHeight = 32;
    for (int i = 0; i < 50; i++)
    {
    	painter.drawLine(i * gridCellWidth, 0, i * gridCellWidth, 50 * 32);
    	painter.drawLine(0, i * gridCellHeight, 50 * 32, i * gridCellHeight);
    }
}