#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "ObjectTableModel.h"

class Object
{
public:
	long x, y;
	bool selected = false;
	static void create(long x, long y);
	static void remove(Object *object);
	static void addToSelection(Object *object);
	static ObjectTableModel tableModel;
};

extern std::vector<Object *> objects;
extern std::vector<Object *> selectedObjects;

#endif //OBJECT_H