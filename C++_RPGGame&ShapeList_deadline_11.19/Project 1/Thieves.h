#ifndef THIEVES_H
#define THIEVES_H
#include "Character.h"
class Thieves : public Character
{
public:
	Thieves() : Character(120, 60, 7, 16)
	{
		//cout << "Character :: Thieves 생성자 실행" << endl;
	}
	~Thieves()
	{
		//cout << "Character :: Thieves 소멸자 실행" << endl;
	}
	void Attack(Character* enemies)
	{
		int attack = this->getDamage() - enemies->getArmor();
		cout << "당신은 상대에게 " << attack << "의 피해를 입혔습니다!" << endl;
		enemies->setHP(enemies->getHP() - attack);
	}

	// Thief uses skill on enemy
	void Skill(Character* enemies)
	{
		int skill_damage = (int)(this->damage * 1.5);
		int attack = skill_damage - enemies->getArmor();
		this->setMP(this->getMP() - 10);
		cout << "당신은 상대에게 " << attack << "의 피해를 입혔습니다!" << endl;
		enemies->setHP(enemies->getHP() - attack);
	}
};
#endif