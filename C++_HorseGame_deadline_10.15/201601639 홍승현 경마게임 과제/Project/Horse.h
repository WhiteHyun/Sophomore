#ifndef HORSE_H
#define HORSE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//경마라는 객체를 만들기 위한 클래스 선언
class Horse
{
	int move;		//매 타임(time)마다 움직이는 값을 저장하기 위해 move라는 변수를 선언
	int position;	//매 타임(time)마다 바뀌는 위치를 저장하기 위해 position이라는 변수를 선언
public:
	Horse();
	void setMove(int move)		//사적(private)공간에 있는 move 멤버를 변경해주기 위한 set함수
	{
		this->move = move;
	}
	int getMove()			//사적(private)공간에 있는 move 멤버를 읽기 위한 get함수
	{
		return move;
	}
	int getPosition()		//사적(private)공간에 있는 position 멤버를 읽기 위한 위한 set함수
	{
		return position;
	}
	void Addposition(int move);	//사적(private)공간에 있는 position 멤버에 move값을 더해주기 위한 함수

};


#endif