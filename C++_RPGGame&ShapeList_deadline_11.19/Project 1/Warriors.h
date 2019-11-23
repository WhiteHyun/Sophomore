#ifndef WARRIORS_H
#define WARRIORS_H
#include "Character.h"
class Warriors : public Character
{
public:
	Warriors() : Character(150, 60, 10, 13)
	{
		//cout << "Character :: Warriors 생성자 실행" << endl;
	}
	~Warriors()
	{
		//cout << "Character :: Warriors 소멸자 실행" << endl;
	}
	void Attack(Character* enemies)
	{
		int attack = this->getDamage() - enemies->getArmor();
		cout << "당신은 상대에게 " << attack << "의 피해를 입혔습니다!" << endl;
		enemies->setHP(enemies->getHP() - attack);
	}

	// Warrior uses skill on enemy
	void Skill(Character* enemies)
	{
		int skill_damage = 15;
		int attack = skill_damage - enemies->getArmor();
		this->setMP(this->getMP() - 10);
		cout << "당신은 상대에게 " << attack << "의 피해를 입혔습니다!" << endl;
		enemies->setHP(enemies->getHP() - attack);
	}
};
#endif