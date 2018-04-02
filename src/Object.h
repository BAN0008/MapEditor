#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

class Object
{
public:
	long x, y;
};

extern std::vector<Object *> objects;
extern std::vector<Object *> selectedObjects;

#endif //OBJECT_H