#include "Object.h"
#include "MainWindow.h"
#include <QtCore/QItemSelectionModel>

std::vector<Object *> objects;
std::vector<Object *> selectedObjects;

ObjectTableModel Object::tableModel;

void Object::create(long x, long y)
{
	tableModel.beginInsertRows2({}, objects.size(), objects.size());
	objects.push_back(new Object());
	objects[objects.size() - 1]->x = x;
	objects[objects.size() - 1]->y = y;
	tableModel.endInsertRows2();
}

void Object::remove(const Object *object)
{
	for (unsigned i = 0; i < objects.size(); i++)
	{
		if (objects[i] == object)
		{
			if (object->selected)
			{
				for (int j = 0; j < tableModel.columnCount(); j++)
				{
					objectList->selectionModel()->select(objectList->selectionModel()->model()->index(i, j), QItemSelectionModel::Deselect);
				}
			}
			tableModel.beginRemoveRows2({}, i, i);
			delete object;
			objects[i] = nullptr;
			objects.erase(objects.begin() + i);
			tableModel.endRemoveRows2();
			break;
		}
	}
	/*
	for (unsigned i = 0; i < selectedObjects.size(); i++)
	{
		if (selectedObjects[i] == object)
		{
			selectedObjects[i] = nullptr;
			selectedObjects.erase(selectedObjects.begin() + i);
		}
	}
	*/
}
/*
void Object::addToSelection(Object *object)
{
	int index = -1;
	for (unsigned i = 0; i < objects.size(); i++)
	{
		if (objects[i] == object)
		{
			index = i;
			break;
		}
	}
	if (index > -1)
	{
		selectedObjects.push_back(object);
		object->selected = true;
		objectList->selectRow(index);
	}
}
*/
void Object::addToSelection(unsigned index)
{
	//selectedObjects.push_back(objects[index]);
	//objectList->selectRow(index);
	for (int i = 0; i < tableModel.columnCount(); i++)
	{
		objectList->selectionModel()->select(objectList->selectionModel()->model()->index(index, i), QItemSelectionModel::Select);
	}
}

std::vector<unsigned> Object::find(QPoint point)
{
	std::vector<unsigned> returnVector;
	for (unsigned i = 0; i < objects.size(); i++)
	{
		if (objects[i]->x < point.x() && objects[i]->x + 32 > point.x() && objects[i]->y < point.y() && objects[i]->y + 32 > point.y())
        {
        	returnVector.push_back(i);
		}
	}
	return returnVector;
}
std::vector<unsigned> Object::find(QRect rect)
{
	std::vector<unsigned> returnVector;
	for (unsigned i = 0; i < objects.size(); i++)
	{
		if (rect.intersects(QRect(objects[i]->x, objects[i]->y, 32, 32)))
        {
        	returnVector.push_back(i);
		}
	}
	return returnVector;
}


void Object::selectionChange(const QItemSelection &selected, const QItemSelection &deselected)
{
	int listSize = selected.indexes().size();
	for (int i = 0; i < listSize; i++)
	{
		if (selected.indexes()[i].column() == 0)
		{
			objects[selected.indexes()[i].row()]->selected = true;
			selectedObjects.push_back(objects[selected.indexes()[i].row()]);
		}
	}
	listSize = deselected.indexes().size();
	for (int i = 0; i < listSize; i++)
	{
		if (deselected.indexes()[i].column() == 0)
		{
			objects[deselected.indexes()[i].row()]->selected = false;
			for (unsigned j = 0; j < selectedObjects.size(); j++)
			{
				if (objects[deselected.indexes()[i].row()] == selectedObjects[j])
				{
					selectedObjects[j] = nullptr;
					selectedObjects.erase(selectedObjects.begin() + j);
					break;
				}
			}
		}
	}
}