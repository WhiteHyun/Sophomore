#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
class Circle : public Shape
{
protected:
	virtual void draw();
public:
	Circle(const int size) : Shape(size)
	{
		//cout << "Shape :: Circle 积己磊 角青" << endl;
	}
	~Circle()
	{
		//cout << "Shape :: Circle 家戈磊 角青" << endl;
	}
};
#endif