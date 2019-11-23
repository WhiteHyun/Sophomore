#ifndef LINE_H
#define LINE_H
#include "Shape.h"
class Line : public Shape
{
protected:
	virtual void draw();
public:
	Line(const int size) : Shape(size)
	{
		//cout << "Shape :: Line 积己磊 角青" << endl;
	}
	~Line()
	{
		//cout << "Shape :: Line 家戈磊 角青" << endl;
	}
};
#endif