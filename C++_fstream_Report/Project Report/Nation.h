#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Nation
{
	string nation;  //나라이름
	string capital; //수도
public:
	Nation()
	{
		this->nation = "";
		this->capital = "";
	}
	void setNation(const string nation)
	{
		this->nation = nation;
	}
	void setCapital(const string capital)
	{
		this->capital = capital;
	}
	string getNation() const
	{
		return this->nation;
	}
	string getCapital() const
	{
		return this->capital;
	}
	
	friend istream& operator>>(istream& ins, Nation& op);
	friend ostream& operator<<(ostream& outs, Nation& op);
	friend bool operator==(const Nation& op1, const Nation& op2);
};