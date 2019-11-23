#ifndef GAMEMAIN_H
#define GAMEMAIN_H
#include "Enemies.h"
#include "Thieves.h"
#include "Wizards.h"
#include "Warriors.h"
#include <string>
class GameMain
{
	int difficulty;		//1 쉬움 2 보통 3 어려움
	Character* enemies;
	Character* main_hero;
	int Set_Difficulty();	//난이도 설정 메소드
	int Set_Job();		//직업 선택 메소드		난이도랑 직업 선택은 클래스 외부에서 설정할 수 없도록 하기 위해 private로 선언하였다.
	int Set_Menu();
public:
	GameMain()
	{
		Menu();
	}
	~GameMain()
	{
		if (enemies)
			delete[] enemies;
		if (main_hero)
			delete main_hero;
	}
	bool Error(const string& errorcode, const int size);	//1부터 size 까지 입력에 대한 에러 검출 메소드
	void Menu();		//메뉴 메소드
	void Start();		//게임 시작 메소드

};

#endif