#include <iostream>
#include "GraphicEditor.h"
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
using namespace std;

const int SELECT_INPUT = 1;
const int SELECT_DELETE = 2;
const int SELECT_SHOW = 3;
const int SELECT_SEE_STATS = 4;
const int SELECT_SHUTDOWN = 5;

int main()
{
	bool exit = false;
	GraphicEditor editor;
	while (!exit)
	{
		switch (editor.Menu())
		{
		case SELECT_INPUT:
			editor.Input();
			break;
		case SELECT_DELETE:
			editor.Delete();
			break;
		case SELECT_SHOW:
			editor.AllShow();
			break;
		case SELECT_SEE_STATS:
			editor.Statistic_Information();
			break;
		case SELECT_SHUTDOWN:
			exit = true;
			break;
		}
	}
}