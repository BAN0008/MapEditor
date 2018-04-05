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

void Object::remove(Object *object)
{
	for (unsigned i = 0; i < objects.size(); i++)
	{
		if (objects[i] == object)
		{
			tableModel.beginRemoveRows2({}, i, i);
			delete object;
			objects[i] = nullptr;
			objects.erase(objects.begin() + i);
			tableModel.endRemoveRows2();
			break;
		}
	}	
}

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

void Object::selectionChange(const QItemSelection &selected, const QItemSelection &deselected)
{
	int listSize = selected.indexes().size();
	for (int i = 0; i < listSize; i++)
	{
		objects[selected.indexes()[i].row()]->selected = true;
	}
	listSize = deselected.indexes().size();
	for (int i = 0; i < listSize; i++)
	{
		objects[deselected.indexes()[i].row()]->selected = false;
	}
}