#include "GameMain.h"

const string JOB_WARRIOR = "1";
const string JOB_WIZARD = "2";
const string JOB_THIEF = "3";
const string EASY = "1";
const string MEDIUM = "2";
const string DIFFICULT = "3";
const string GENERAL_ATTACK = "1";
const string SKILL_ATTACK = "2";
const int SELECT_JOB_WARRIOR = 1;
const int SELECT_JOB_WIZARD = 2;
const int SELECT_JOB_THIEF = 3;
const int MENU_DIFFICULTY_SETTING = 1;
const int MENU_JOB_SETTING = 2;
const int MENU_GAME_START = 3;
//직관적인 코드 구성을 위해 선언한 const 변수

int GameMain::Set_Difficulty()
{
	string difficulty;
	while (true)
	{
		cout << "[난이도 선택]" << endl;
		cout << "1. 쉬움   2. 보통    3. 어려움" << endl;
		cout << "선택 : ";
		cin >> difficulty;	//난이도 입력
		if (!Error(difficulty, 3))	//정확한 숫자를 받았는지 판별, 에러가 나지 않는다면 반복문 탈출
			break;
	}
	if (difficulty == EASY) cout << "난이도 \"쉬움\"을 선택하셨습니다." << endl;
	else if (difficulty == MEDIUM) cout << "난이도 \"보통\"을 선택하셨습니다." << endl;
	else if (difficulty == DIFFICULT) cout << "난이도 \"어려움\"을 선택하셨습니다." << endl;
	return stoi(difficulty, nullptr, 10);
}


int GameMain::Set_Job()
{
	string job;
	while (true)
	{
		cout << "[직업 선택]" << endl;
		cout << "1. 전사   2. 마법사    3. 도적" << endl;
		cout << "선택 : ";
		cin >> job;		//직업 선택 입력
		if (!Error(job, 3))	//정확한 숫자를 받았는지 판별, 에러가 나지 않는다면 반복문 탈출
			break;
	}
	if (job == JOB_WARRIOR) cout << "\"전사\"을 선택하셨습니다." << endl;
	else if (job == JOB_WIZARD) cout << "\"마법사\"를 선택하셨습니다." << endl;
	else if (job == JOB_THIEF) cout << "\"도적\"을 선택하셨습니다." << endl;
	return stoi(job, nullptr, 10);
}


int GameMain::Set_Menu()
{
	string select_menu;
	while (true)
	{
		cout << "-------MENU-------" << endl;
		cout << "1. 난이도 설정하기" << endl;
		cout << "2. 직업 선택하기" << endl;
		cout << "3. 게임하기" << endl;
		cout << "선택 : ";
		cin >> select_menu;	//메뉴 선택
		if (!Error(select_menu, 3))	//정확한 숫자를 받았는지 판별, 에러가 나지 않는다면 반복문 탈출
			break;
	}
	return stoi(select_menu, nullptr, 10);
}


bool GameMain::Error(const string& errorcode, const int size)
{
	int temp_int_errorcode;	//int형 에러코드 판별 변수
 	if ((errorcode.length() != 1) || (errorcode.length() == 1 && !isdigit(errorcode[0])))	//입력받은 문자열의 길이가 2자리 이상이거나, 1자리일 때 그 문자가 숫자가 아닌 경우
	{	//오류 메시지 출력
		cout << endl;
		cout << "잘못된 입력입니다. 1부터 " << size << "까지의 번호 중 하나를 선택하여 입력하여 주시기 바랍니다." << endl;
		cout << endl;
	}
	else		//정상적인 하나의 숫자를 입력 받을 경우
	{
		temp_int_errorcode = stoi(errorcode, nullptr, 10);	//int형으로 형변환하여 저장
		if (temp_int_errorcode > size || temp_int_errorcode < 1)	//입력받은 숫자를 볼 때 1과 size 크기 만큼의 사이에 있지 않은 숫자일 경우 오류 메시지 출력
		{
			cout << endl;
			cout << "잘못된 입력입니다. 1부터 " << size << "까지의 번호 중 하나를 선택하여 입력하여 주시기 바랍니다." << endl;
			cout << endl;
		}
		else	//정확한 숫자 입력했을 경우 오류 발생하지 않았으므로 false 반환
			return false;
	}
	return true;	//오류가 검색되었으므로 true 반환
}


void GameMain::Menu()
{
	int select_job = 0;
	bool gamestart = false;		//게임 플레이 유/무 판단 변수
	bool complete_settings = false;	//설정 완료 판단 변수 ( 난이도 & 직업 )
	while (true)
	{
		if (gamestart)		//이미 게임을 한 번 진행했으면 반복문 빠져나옴
			break;
		else if (difficulty != 0 && select_job != 0)		//모든 설정이 완료되었는지 확인하는 코드
			complete_settings = true;			//설정이 모두 완료가 되었으면 게임을 시작할 수 있는 조건부울을 참으로 변경



//----------------------------------------------------------------------------//
		switch(Set_Menu())
		{
		case MENU_DIFFICULTY_SETTING:	//난이도 설정 조건문
			this->difficulty = Set_Difficulty();
			if (enemies)
				delete[] enemies;	//동적할당 되어있으면 적 클래스의 인스턴스 객체 메모리 해제
			enemies = new Enemies[difficulty + 2];	//적 클래스의 인스턴스 객체를 난이도에 해당하는 적의 수 만큼 동적 할당.
			break;
//----------------------------------------------------------------------------//
		case MENU_JOB_SETTING:	//직업 설정 조건문
			select_job = Set_Job();
			if (main_hero)
				delete main_hero;	//이미 직업을 선택했을 경우 해당 직업에 설정된 메모리 해제
			switch (select_job)
			{						//각 선택한 직업을 업캐스팅 하여 동적할당
			case SELECT_JOB_WARRIOR:
				main_hero = new Warriors();
				break;
			case SELECT_JOB_WIZARD:
				main_hero = new Wizards();
				break;
			case SELECT_JOB_THIEF:
				main_hero = new Thieves();
				break;
			}
			break;
//----------------------------------------------------------------------------//
		case MENU_GAME_START:
			if (complete_settings)	//만약 모든 설정이 완료되었으면 게임 시작
			{
				cout << "게임 시작" << endl;
				Start();		//게임 시작 구문
				gamestart = true;
			}	
			else	//설정이 채 완료도 되지 않은 채 게임을 시작하려 할 경우
			{
				cout << "아직 모든 설정이 완료되지 않았습니다." << endl;
			}
			break;
		default:
			cout << "에러가 발생하였습니다." << endl;
			return;
		}
//**************************SWITCH 구문 끝********************************//
	}
}


void GameMain::Start()
{
	int the_number_of_enemies = difficulty + 2;	//적의 숫자를 정의하는 변수
	bool ifDead = false;		//게임 유저가 게임 시작 시 생사 판별 변수
	string select_attack;
	for (int i = 0; i < the_number_of_enemies; i++)
	{
		for (int j = 1; !enemies[i].HP_isEmpty(); j++)
		{
			cout <<  endl << "<ROUND " << i + 1 << "-" << j << ">" << endl;
			cout << "당신 :  HP(" << main_hero->getHP() << ")" << "\t" << "MP(" << main_hero->getMP() << ")" << endl;
			cout << "상대 : HP(" << enemies[i].getHP() << ")" << endl << endl;
			cout << "1. 일반 공격     2. 스킬 사용" << endl;
			cout << "선택 : ";
			// 위 코드는 단순 출력문 : 상대와 자신의 hp, mp 및 공격 형식 선택 출력 코드이다.


			for (;;)		// 입력 시 에러 검출 반복문
			{
				cin >> select_attack;		//공격 형식 선택
				if (!Error(select_attack, 2))
					break;
			}


			if (select_attack == GENERAL_ATTACK)	//일반 공격일 경우
				main_hero->Attack(enemies + i);

			else if (select_attack == SKILL_ATTACK && main_hero->MP_isUsable())	//스킬 공격일 때 MP가 사용가능 할 경우
				main_hero->Skill(enemies + i);

			else if (select_attack == SKILL_ATTACK && !(main_hero->MP_isUsable())) //스킬 공격일 때 MP가 사용가능하지 않을 경우
				cout << "MP가 부족합니다. 스킬 사용에 실패했습니다. 턴이 넘어갑니다." << endl;

			if (enemies[i].HP_isEmpty())	//선공격을 하여 적을 쓰러트린 경우
				cout << "적을 처치했습니다." << endl;

			else	//공격했을 때 적이 쓰러지지 않고 HP가 남아 있는 경우
			{
				(enemies + i)->Attack(main_hero);	//적이 유저를 공격
				if (main_hero->HP_isEmpty())		//적에게 공격받아 유저의 캐릭터가 빈사상태일 경우
				{
					ifDead = true;		//죽었는지 판단하는 변수에 true값 반환
					break;
				}
			}
		}

		if (ifDead)		//유저가 죽었을 경우
		{
			cout << "당신은 패배하셨습니다." << endl << endl;
			break;
		}
	}
	if (enemies[the_number_of_enemies - 1].HP_isEmpty())	//마지막 적의 HP가 없을 경우
		cout << "당신은 승리하셨습니다!" << endl << endl;
}