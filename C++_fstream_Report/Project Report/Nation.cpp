#include "Nation.h"

istream& operator>>(istream& ins, Nation& op)
{
	cout << "나라 이름 입력 >>";
	ins >> op.nation;
	if (op.nation == "no")		//나라를 no라고 입력 받았을 경우 바로 반환함
		return ins;
	cout << op.nation << "의수도 입력 >>";
	ins >> op.capital;
	return ins;
}

ostream& operator<<(ostream& outs, Nation& op)
{
	outs << "국가 : " << op.nation << ", 수도 : " << op.capital << endl;
	return outs;
}

bool operator==(const Nation& op1, const Nation& op2)
{
	if (op1.capital == op2.capital && op1.nation == op2.nation)
		return true;
	else
		false;
}