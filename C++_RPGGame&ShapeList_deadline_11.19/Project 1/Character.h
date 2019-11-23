#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
using namespace std;
class Character
{
protected:
	int hp, mp, armor, damage;		//해당 게임에서 영웅에게 필요한 특성들임
public:
	Character(const int hp, const int mp, const int armor, const int damage) : hp(hp), mp(mp), armor(armor), damage(damage)
	{
		//cout << "Character 생성자 실행" << endl;
	}
	virtual ~Character()
	{
		//cout << "Character 소멸자 실행 " << endl;
	}
	int getHP() const { return hp; }		//HP get method (const)
	void setHP(int hp) { this->hp = hp; }	//HP set method
	int getMP() const { return mp; }		//MP get method (const)
	void setMP(int mp) { this->mp = mp; }	//MP set method
	int getArmor() const { return armor; }	//ARMOR get method (const)
	void setArmor() { this->armor = armor; }//ARMOR set method
	int getDamage() const { return damage; }//DAMAGE get method (const)
	void setDamage() { this->damage = damage; }//DAMAGE set method
	bool HP_isEmpty() const { if (this->hp <= 0) return true; else return false; }	//hp 유무 판단 메소드 (const)
	bool MP_isUsable() const { if (this->mp >= 10) return true; else return false; }//mp 사용가능 판단 메소드 (const)
	virtual void Attack(Character* c) = 0;	//Attack 가상 상속 메소드
	virtual void Skill(Character* c) = 0;	//Skill 가상 상속 메소드

};

#endif