#include "HorseManager.h"

HorseManager::HorseManager()
{
	cout << "경마 게임 생성!" << endl;
	this->count = horse_input();			// 입력받은 경마의 수를 카운트 변수에 할당
	for (int i = 0; i < sizeof(first_win) / sizeof(int); i++)
		this->first_win[i] = -1;		//우승한 말의 변수 값 공간 할당
	horse = new Horse[count];		//입력받은 경마의 수만큼 동적 할당, 배열로 볼 수 있음
	this->select = select_input();		// 우승을 예측할 경마를 입력받아 select 변수에 초기화 
}

HorseManager::~HorseManager()
{
	//동적할당한 메모리를 해제
	delete[] horse;
}

int HorseManager::horse_input()
{
	cout << "몇 마리의 말로 플레이 하시겠습니까?" << endl;
	int temp_count;	//입력받을 값을 선언
	for (;;)	//무한루프
	{
		cin >> temp_count;		//경마 수 입력

		if (!cin)	//number가 아닌 letter 값을 받았을 경우
			cout << "잘못된 숫자입력입니다." << endl << "다시 입력해주세요" << endl;

		else if (temp_count >= 2 && temp_count <= 5)	//정상적인 경마 수(2마리~5마리)를 받았을 경우
			break;

		else if (temp_count < 2)		//2마리 미만의 경마 수를 받을	때
			cout << "최소 2마리의 말이 필요합니다. 다시 입력해주세요." << endl;

		else if (temp_count > 5)		//5마리 초과의 경마 수를 받았을 경우
			cout << "최대 5마리의 말까지 플레이 가능합니다, 다시 입력해주세요" << endl;

		//버퍼 지움
		cin.clear();												//문자 값을 받을 경우 남은 버퍼 값이 있기에 무한 반복에서 벗어나질 못함.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');		//과제 개요에 일러두신 함수를 사용했으나 문자의 개수만큼 출력해, ignore 안에 세부적인 값을 넣었음.
	}
	//정상적인 입력값을 받았을 경우 값 반환
	return temp_count;
}

int HorseManager::select_input()
{
	int temp_count;
	cout << "몇 번째 말을 선택 하시겠습니까?" << endl;
	for (;;)
	{
		cin >> temp_count;		//선택할 경마 입력

		if (!cin)	//number가 아닌 letter 값을 받았을 경우
			cout << "잘못된 숫자입력입니다." << endl << "다시 입력해주세요" << endl;

		else if (temp_count >= 1 && temp_count <= this->count)	//정상적인 경마 수 안에서의 번호를 입력 받았을 경우
			break;
		
		else		//입력받은 경마 수를 벗어난 입력을 받을 경우
			cout << "잘못된 입력입니다. 입력은 1이상 " << this->count << "이하여야 합니다." << endl;
		//버퍼 지움
		cin.clear();												//문자 값을 받을 경우 남은 버퍼 값이 있기에 무한 반복에서 벗어나질 못함.
		cin.ignore(numeric_limits<streamsize>::max(), '\n');		//과제 개요에 일러두신 함수를 사용했으나 문자의 개수만큼 출력해, ignore 안에 세부적인 값을 넣었음.
	}
	//정상적인 입력값을 받았을 경우 값 반환
	return temp_count;
}

void HorseManager::Progress()
{
	srand(time(nullptr));			//srand 안에 시간 시드를 넣음
									//srand((unsigned)time(0)); 난수추출 이렇게도 가능!
	int loop = 0;	//경마가 모두 도착지점에 골인했는 지 임시 변수 선언 및 0으로 초기화
	bool havegoal = true;	//1등 경마 검색을 결정할 변수를 true로 초기화
	int time_i = 0;	//단순 타임 출력 값
	int cnt = 0;
	while (loop != this->count)	//모든 경마가 도착했을 경우 반복문을 나감
	{
		time_i++;
		loop = 0;	//루프 조건 변수 값을 0으로 초기화

		for (int i = 0; i < this->count; i++)
		{
			horse[i].setMove(rand() % 6);			//무작위 값(0부터 5까지)을 입력 받아 각 객체의 move 멤버에 값 할당.
			horse[i].Addposition(horse[i].getMove());
			//cout << horse[i].getPosition() << endl;
		}

		clock_t start = clock();			//1초 뒤에 출력하기 위해
		while (clock() - start < 1000);		//만들어 놓은 코드

		Show(time_i);	//현재 경기양상을 출력해주는 함수

		//루프문 탈출조건 만족할 시 탈출
		for (int i = 0; i < this->count; i++)
		{
			//만약 경마가 도착선에 있지 않을 경우
			if (horse[i].getPosition() != 20)
				continue;

			//경마가 도착선에 있을 경우
			else
			{
				if (havegoal)
					first_win[cnt++] = i;	//요소에 경마 번호 저장후 cnt값을 1만큼 증가
				loop++;	//루프변수 1만큼을 더함.
			}
		}
		if (first_win[0] != -1)
			havegoal = false;		//만약 한 마리 이상의 경마가 결승선에 도착했을 경우 1등 경마 검색은 하지 않게끔 havegoal 변수를 false 로 지정.

		//모든 경마가 다 들어오면  loop = this->count 가 되있을 것.
	}
	End_Announcement();
}


void HorseManager::Show(int time_i) const
{
	//cout << horse[0].getPosition() << ' ' << horse[1].getPosition() << ' ' << horse[2].getPosition() << ' ' << horse[3].getPosition() << endl;
	cout << endl << endl;
	cout << "Time : " << time_i << endl;
	cout << "====================================================" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << i + 1 << "|";
		for (int j = 0; j < horse[i].getPosition(); j++)
			cout << "--";
		cout << "(  )=> " << horse[i].getPosition() << endl;
	}
	cout << "====================================================" << endl << endl << endl;
}

void HorseManager::End_Announcement()
{
	//경기가 끝난 후 멘트 출력
	cout << "우승자는 ";
	for (int i = 0; first_win[i] != -1; i++)
	{
		//공동 우승 포함
		if (first_win[i+1] == -1)
			cout << first_win[i] + 1 << "번째 ";
		else
			cout << first_win[i] + 1 << "번째, ";
	}
	cout << "경마입니다!" << endl;

	for (int i = 0; first_win[i] != -1; i++)
	{
		//만약 우승경마를 맞추었을 경우
		if (this->select == first_win[i] + 1)
		{
			cout << "축하드립니다! 당신은 승리하셨습니다." << endl;
			return;
		}
	}	
		// 아닌 경우
		cout << "당신은 패배하셨습니다. :(" << endl;
}