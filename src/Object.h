#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <QtCore/QItemSelection>
#include "ObjectTableModel.h"

class Object
{
public:
	long x, y;
	bool selected = false;
	static void create(long x, long y);
	static void remove(const Object *object);
	//static void addToSelection(Object *object);
	static void addToSelection(unsigned index);
	static std::vector<unsigned> find(QPoint point);
	static std::vector<unsigned> find(QRect rect);
	static ObjectTableModel tableModel;
public slots:
	static void selectionChange(const QItemSelection &selected, const QItemSelection &deselected);
};

extern std::vector<Object *> objects;
extern std::vector<Object *> selectedObjects;

#endif //OBJECT_H