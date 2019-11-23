#include "GraphicEditor.h"
#include <string>

const int TOTAL_SIZE = 0;
const int LINE = 1;
const int CIRCLE = 2;
const int RECTANGLE = 3;
//직관적인 코드의 가시성을 위해 선언한 const 변수

int GraphicEditor::Menu()	//메뉴 선택창 입출력을 맡음
{
	cout << "---------------------Graphic Editor---------------------" << endl;
	cout << "1. 삽입, 2. 삭제, 3. 모두보기, 4. 통계정보, 5. 종료" << endl;
	cout << "선택 : ";
	string select_menu_settings;
	while (true)		//에러 검출 반복문
	{
		cin >> select_menu_settings;
		if (!Error(select_menu_settings, 1, 5))		//에러가 발생하지 않으면 반복문 벗어남
			break;
	}
	return stoi(select_menu_settings, nullptr, 10);	//string 형에서 정수형(10진수)으로 변환해서 리턴
}

void GraphicEditor::Input()
{
	cout << endl << "1. 선, 2. 원 , 3. 사각형 >> ";
	string select_shape_convert;
	int select_shape;
	while (true)		//에러 검출 반복문
	{
		cin >> select_shape_convert;
		if (!Error(select_shape_convert, 1, 3))	//에러가 발생하지 않았을 경우 반복문 탈출
			break;
	}
	select_shape = stoi(select_shape_convert, nullptr, 10);	//string형-> int 형 형변환 후 해당 변수에 저장


	switch (select_shape)		//삽입 구문
	{
	case LINE:
		if (size[TOTAL_SIZE] == 0)		//콘솔 내 입력받은 도형이 없을 경우
		{
			this->startNode = new Line(LINE);
			this->peek = this->startNode;
			this->size[TOTAL_SIZE]++;
			this->size[LINE]++;
		}
		else				//입력 받은 도형이 있을 경우
		{
			this->peek = this->peek->add(new Line(LINE));
			this->size[TOTAL_SIZE]++;
			this->size[LINE]++;
		}
		break;
	case CIRCLE:
		if (size[TOTAL_SIZE] == 0)		//콘솔 내 입력받은 도형이 없을 경우
		{
			this->startNode = new Circle(CIRCLE);
			this->peek = this->startNode;
			this->size[TOTAL_SIZE]++;
			this->size[CIRCLE]++;
		}
		else				//입력 받은 도형이 있을 경우
		{
			this->peek = this->peek->add(new Circle(CIRCLE));
			this->size[TOTAL_SIZE]++;
			this->size[CIRCLE]++;
		}
		break;
	case RECTANGLE:
		if (size[TOTAL_SIZE] == 0)		//콘솔 내 입력받은 도형이 없을 경우
		{
			this->startNode = new Rect(RECTANGLE);
			this->peek = this->startNode;
			this->size[TOTAL_SIZE]++;
			this->size[RECTANGLE]++;
		}
		else				//입력 받은 도형이 있을 경우
		{
			this->peek = this->peek->add(new Rect(RECTANGLE));
			this->size[TOTAL_SIZE]++;
			this->size[RECTANGLE]++;
		}
		break;
	}
}

void GraphicEditor::Delete()
{
	if (size[TOTAL_SIZE] == 0)	//존재하는 도형이 없을 경우
	{
		cout << "삭제할 노드가 없습니다!! 우선적으로 도형을 삽입해주세요!" << endl;
		return;
	}

	Shape* deleteNode = startNode;	//삭제할 노드를 가리키는 임시 노드
	Shape* changeNode;	//삭제할 노드 앞에 있는 노드의 next를 변경해주는 임시 노드

	cout << "삭제하고자 하는 도형의 인덱스>> ";

	string input_index_string;		//삭제할 인덱스 입력 변수
	int index;						//삭제 인덱스 변환받을 변수

	while (true)		//에러 검출 반복문
	{
		cin >> input_index_string;
		if (!Error(input_index_string, 0, this->size[TOTAL_SIZE] - 1))		//에러가 검출되지 않으면 반복문 탈출
			break;
	}
	index = stoi(input_index_string, nullptr, 10);

	if (index == 0)	//제거할 노드가 첫 노드일 때
	{
		if (peek == startNode)		//첫 노드가 peek일 경우
		{
			startNode = nullptr;
			peek = nullptr;
		}
		else						//첫 노드가 peek 이 아닐 경우
		{
			startNode = startNode->add(startNode->getNext());
		}
		switch (deleteNode->getShape())	//제거할 도형 검색(search) 후 도형의 개수(size)를 1씩 discount
		{
		case LINE:
			this->size[LINE]--;
			break;
		case CIRCLE:
			this->size[CIRCLE]--;
			break;
		case RECTANGLE:
			this->size[RECTANGLE]--;
			break;
		}
		this->size[TOTAL_SIZE]--;		//총 도형의 개수(size)를 1 discount.
		delete[] deleteNode;	//노드 제거
	}
	else			//제거할 노드가 첫 노드가 아닐 경우
	{
		for (int i = 0; i < index - 1; i++)		//선택한 인덱스(노드)가 있기 바로 전 까지를 deleteNode에 Search 후 저장, 즉 선택한 인덱스(노드)의 앞 공간
		{
			deleteNode = deleteNode->getNext();
		}
		changeNode = deleteNode;				//삭제할 노드의 전 도형을 해당 변수에 저장
		deleteNode = deleteNode->getNext();	//next를 가리켜 삭제할 노드로 이동

		if (deleteNode == peek)			// 만약 삭제하려는 노드가 가장 마지막(peek) 인 경우
		{
			changeNode->add(deleteNode->getNext());
			this->peek = changeNode;
		}
		else  if(deleteNode != peek/* && deleteNode != nullptr*/)		//첫 노드와 마지막 노드 사이의 노드인 경우
			changeNode->add(deleteNode->getNext());

		switch (deleteNode->getShape())
		{
		case LINE:
			this->size[LINE]--;
			break;
		case CIRCLE:
			this->size[CIRCLE]--;
			break;
		case RECTANGLE:
			this->size[RECTANGLE]--;
			break;
		}
		this->size[TOTAL_SIZE]--;
		delete deleteNode;
	}
}

void GraphicEditor::AllShow() const
{
	int i = 0;
	if (size[TOTAL_SIZE] == 0)
	{
		cout << "현재 도형이 존재하지 않습니다. 삽입을 통해 도형을 생성해주세요." << endl;
		return;
	}
	else
	{
		for (Shape* tempNode = startNode; tempNode != nullptr; tempNode = tempNode->add(tempNode->getNext()))
		{
			cout << i << ": ";
			tempNode->paint();
			i++;
		}
	}

}

void GraphicEditor::Statistic_Information()
{
	if (size[TOTAL_SIZE] == 0)
		cout << "현재 도형이 존재하지 않습니다. 삽입을 통해 도형을 생성해주세요." << endl;
	else
	{
		cout << "1. 선 도형의 개수 : " << size[LINE] << endl
			 << "2. 원 도형의 개수 : " << size[CIRCLE] << endl
			 << "3. 사각형 도형의 개수 : " << size[RECTANGLE] << endl
			 << "총 도형의 개수 : " << size[TOTAL_SIZE] << endl;
	}
}

bool GraphicEditor::Error(const string& errorcode, const int size_start, const int size_end)
{
	int temp_int_errorcode;	//int형 에러코드 판별 변수

	for (unsigned int i = 0; i < errorcode.length(); i++)	//문자 유무 처리 반복문
	{
		if (!isdigit(errorcode[i]))	//입력받은 문자열 중에 문자가 하나라도 있는 경우
		{	//오류 메시지 출력
			cout << endl;
			cout << "잘못된 입력입니다. " << size_start << "부터 " << size_end << "까지의 번호 중 하나를 선택하여 입력하여 주시기 바랍니다." << endl;
			cout << endl;
			return true;	//오류 발생했으므로 true 반환
		}
	}

	temp_int_errorcode = stoi(errorcode, nullptr, 10);	//int형으로 형변환하여 저장

	if (temp_int_errorcode > size_end || temp_int_errorcode < size_start)	//입력받은 숫자를 볼 때 size_start와 size_end 크기 만큼의 사이에 있지 않은 숫자일 경우 오류 메시지 출력
	{
		cout << endl;
		cout << "잘못된 입력입니다. " << size_start << "부터 " << size_end << "까지의 번호 중 하나를 선택하여 입력하여 주시기 바랍니다." << endl;
		cout << endl;
	}
	else	//정확한 숫자 입력했을 경우 오류 발생하지 않았으므로 false 반환
		return false;


	return true;	//오류가 검색되었으므로 true 반환
}