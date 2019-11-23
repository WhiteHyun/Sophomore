#ifndef WIZARDS_H
#define WIZARDS_H
#include "Character.h"
class Wizards : public Character
{
public:
	Wizards() : Character(120, 80, 7, 10)
	{
		//cout << "Character :: Wizards 생성자 실행" << endl;
	}
	~Wizards()
	{
		//cout << "Character :: Wizards 소멸자 실행" << endl;
	}
	void Attack(Character* enemies)
	{
		int attack = this->getDamage() - enemies->getArmor();
		cout << "당신은 상대에게 " << attack << "의 피해를 입혔습니다!" << endl;
		enemies->setHP(enemies->getHP() - attack);
	}

	// Wizard uses skill on enemy
	void Skill(Character* enemies)
	{
		int skill_damage = 30;
		int attack = skill_damage - enemies->getArmor();
		this->setMP(this->getMP() - 10);
		cout << "당신은 상대에게 " << attack << "의 피해를 입혔습니다!" << endl;
		enemies->setHP(enemies->getHP() - attack);
	}
};
#endif