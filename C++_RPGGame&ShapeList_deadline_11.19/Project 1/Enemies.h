#ifndef ENEMIES_H
#define ENEMIES_H
#include "Character.h"
class Enemies : public Character
{
public:
	Enemies() : Character(40, 0, 5, 15)
	{
		//cout << "Character :: Enemies 생성자 실행" << endl;
	}
	~Enemies()
	{
		//cout << "Character :: Enemies 소멸자 실행" << endl;
	}
	void Attack(Character* main_hero)
	{
		int attack = this->getDamage() - main_hero->getArmor();
		cout << "당신은 상대로부터 " << attack << "의 피해를 입었습니다!" << endl << endl;
		main_hero->setHP(main_hero->getHP() - attack);
	}
	void Skill(Character* trash)
	{
		//상속받아 오버라이딩 하되, 사용하는 것은 없음.
	}

};
#endif