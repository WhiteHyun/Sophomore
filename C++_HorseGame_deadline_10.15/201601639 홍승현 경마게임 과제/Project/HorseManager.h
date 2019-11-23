#ifndef HORSEMANAGER_H
#define HORSEMANAGER_H
#include "Horse.h"
class HorseManager
{
	int first_win[5];	//우승한 말을 저장할 변수 선언
	int count;	//경마 개수를 저장하기 위한 변수 선언
	int select;	//입력받은 예상 우승 경마를 저장하기 위한 변수 선언
	Horse* horse;	//만들어둔 경마 클래스로 포인터객체 선언
public:
	HorseManager();	//생성자
	~HorseManager();	//소멸자
	int horse_input();	//경마 수를 입력받고 반환할 함수 선언
	int select_input();	//선택할 경마 수를 입력받고 반환할 함수 선언
	void Progress();	//경기 진행 함수
	void Show(int time_i)const;		//현재 경기 양상이 어떻게 되어있는지 출력하는 함수 선언
	void End_Announcement();
};
#endif