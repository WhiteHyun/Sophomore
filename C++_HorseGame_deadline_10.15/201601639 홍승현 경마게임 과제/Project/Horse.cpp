#include "Horse.h"


Horse::Horse()
{
	this->move = 0;	// 단순 공간할당을 위해 0으로 초기화
	this->position = 0;	// 출발할 때 시작점으로부터 출발하기 때문에 0으로 초기화
}

void Horse::Addposition(int move)
{
	if (this->position == 20) {}		//이미 결승선에 있는 경우 넘어감
	else if (this->position + move > 20)		//만약 난수로 입력받은 move와 현위치의 값을 더해 최고거리인 20보다 초과할 경우
		this->position = 20;		//값을 20으로 초기화해준다.
	else
		this->position += move;		//그게 아니라면 현위치에서 움직인 값만큼 더해준다.
	
}