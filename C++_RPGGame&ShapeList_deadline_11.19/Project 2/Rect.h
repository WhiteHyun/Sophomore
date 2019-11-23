#ifndef RECT_H
#define RECT_H
#include "Shape.h"
class Rect : public Shape
{
protected:
	virtual void draw();
public:
	Rect(const int size) : Shape(size)
	{
		//cout << "Shape :: Rect 积己磊 角青" << endl;
	}
	~Rect()
	{
		//cout << "Shape :: Rect 家戈磊 角青" << endl;
	}
};
#endif