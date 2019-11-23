#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
class GraphicEditor
{
	Shape* startNode;
	Shape* peek;
	int size[4] = { 0, };
	bool Error(const string& errorcode, const int size_start, const int size_end);
public:
	GraphicEditor()
	{
		this->startNode = nullptr;
		this->peek = nullptr;
		//cout << "GrahpicEditor 积己磊 角青" << endl;
	}
	~GraphicEditor()
	{
		//cout << "GrahpicEditor 家戈磊 角青" << endl;
		if (size[0] != 0)
		{
			Shape* tempNode;
			for (Shape* deleteNode = startNode; deleteNode != nullptr; deleteNode = tempNode)
			{
				tempNode = deleteNode->getNext();
				delete deleteNode;
			}
		}
	}
	int Menu();
	void Input();
	void Delete();
	void AllShow() const;
	void Statistic_Information();

};
#endif