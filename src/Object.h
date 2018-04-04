#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <QtCore/QItemSelection>
#include "ObjectTableModel.h"

class Object : public QObject
{
	Q_OBJECT
public:
	long x, y;
	bool selected = false;
	static void create(long x, long y);
	static void remove(Object *object);
	static void addToSelection(Object *object);
	static ObjectTableModel tableModel;
public slots:
	static void selectionChange(const QItemSelection &selected, const QItemSelection &deselected);
};

extern std::vector<Object *> objects;
extern std::vector<Object *> selectedObjects;

#endif //OBJECT_H