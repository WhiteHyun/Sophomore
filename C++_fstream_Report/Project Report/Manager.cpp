#include "Manager.h"
#include <ctime>
constexpr auto NATION_NAME = true;
constexpr auto CAPITAL_NAME = false;

#pragma region 에러판별문
bool isError(const string& errorcode, const int size)
{
	int temp_int_errorcode;                                                               //int형 에러코드 판별 변수
	if ((errorcode.length() != 1) || (errorcode.length() == 1 && !isdigit(errorcode[0]))) //입력받은 문자열의 길이가 2자리 이상이거나, 1자리일 때 그 문자가 숫자가 아닌 경우
	{                                                                                     //오류 메시지 출력
		cout << endl;
		cout << "잘못된 입력입니다. 1부터 " << size << "까지의 번호 중 하나를 선택하여 입력하여 주시기 바랍니다." << endl;
		cout << endl;
	}
	else //정상적인 하나의 숫자를 입력 받을 경우
	{
		temp_int_errorcode = stoi(errorcode, nullptr, 10);       //int형으로 형변환하여 저장
		if (temp_int_errorcode > size || temp_int_errorcode < 1) //입력받은 숫자를 볼 때 1과 size 크기 만큼의 사이에 있지 않은 숫자일 경우 오류 메시지 출력
		{
			cout << endl;
			cout << "잘못된 입력입니다. 1부터 " << size << "까지의 번호 중 하나를 선택하여 입력하여 주시기 바랍니다." << endl;
			cout << endl;
		}
		else //정확한 숫자 입력했을 경우 오류 발생하지 않았으므로 false 반환
			return false;
	}
	return true; //오류가 검색되었으므로 true 반환
}
#pragma endregion

#pragma region 관리자 메뉴
int AdministratorMode(string& select)
{
	while (true)
	{
		cout << "---------Menu---------" << endl;
		cout << "[1] Source File Upload" << endl;
		cout << "[2] Update Information" << endl;
		cout << "----------------------" << endl;
		cout << "Select >> ";
		cin >> select;
		if (!isError(select, 2))
		{
			break;
		}
	}
	return stoi(select);
}
#pragma endregion

#pragma region 정보갱신 세부 메뉴
int Update_Information_Menu(string& select)
{
	while (true)
	{
		cout << "---------Menu---------" << endl;
		cout << "[1] Rename Capital" << endl;
		cout << "[2] Insert Nation" << endl;
		cout << "[3] Delete_Nation" << endl;
		cout << "[4] BackUp" << endl;
		cout << "----------------------" << endl;
		cout << "Select >> ";
		cin >> select;
		if (!isError(select, 4))
		{
			break;
		}
	}
	return stoi(select);
}
#pragma endregion

#pragma region 유저 메뉴
int UserMode(string& select)
{
	while (true)
	{
		cout << "---------Menu---------" << endl;
		cout << "[1] Search Capital Information" << endl;
		cout << "[2] Quiz" << endl;
		cout << "----------------------" << endl;
		cout << "Select >> ";
		cin >> select;
		if (!isError(select, 2))
		{
			break;
		}
	}
	return stoi(select);
}
#pragma endregion

#pragma region 수도 정보 검색 세부 메뉴
int Search_Capital_Information_Menu(string& select)
{
	while (true)
	{
		cout << "---------Menu---------" << endl;
		cout << "[1] Individual Search by Nation Name" << endl;
		cout << "[2] Print All of Nation's Information" << endl;
		cout << "----------------------" << endl;
		cout << "Select >> ";
		cin >> select;
		if (!isError(select, 2))
			break;
	}
	return stoi(select);
}
#pragma endregion

#pragma region-- ---------------------여기서부터는 멤버함수-- ----------------------

#pragma endregion

#pragma region 나라중복검색 및 중복된 위치 반환
vector<Nation>::iterator Manager::Find_Overlap(const Nation& nation_object)		//Nation 객체를 통한 중복검사
{
	for (vector<Nation>::iterator it = v.begin(); it < v.end(); it++)
	{
		if (nation_object == *it)		//같을경우
		{
			return it;	//해당 벡터의 위치 반환
		}
	}
	return v.end();		//중복이 없으면 벡터의 end를 반환
}
vector<Nation>::iterator Manager::Find_Overlap(const string& nation_name)		// 국가 이름을 통한 중복검사
{
		for (vector<Nation>::iterator it = v.begin(); it < v.end(); it++)
		{
			if (nation_name == it->getNation())		//같을 경우
			{
				return it;	//해당 벡터의 위치 반환
			}
		}
	return v.end();		//중복이 없으면 벡터의 end를 반환
}
#pragma endregion

#pragma region 메뉴
void Manager::Menu()
{
	string input_select;
	int select;
	bool end = false;
	while (!end)
	{
		cout << "---------Menu---------" << endl;
		cout << "[1] Administrator Mode" << endl;
		cout << "[2] User Mode" << endl;
		cout << "[3] Program Exit" << endl;
		cout << "----------------------" << endl;
		cout << "Select >> ";
		while (true) //오류 검출 반복문
		{
			cin >> input_select;
			if (!isError(input_select, 3))
			{
				select = stoi(input_select);
				break;
			}
		}

		switch (select)
		{
#pragma region 관리자모드일 때
		case ADMIN:
			select = AdministratorMode(input_select); //자식메뉴의 선택지를 입력받아 재할당 후 스위치문 적용
			switch (select)
			{
			case SOURCE_FILE_UPLOAD:
				Upload();
				break;
			case UPDATE_INFORMATION:
				select = Update_Information_Menu(input_select);
				switch (select)
				{
				case RENAME_CAPITAL:
					Rename_Capital();
					break;

				case INSERT_NATION:
					Insert_Nation();
					break;

				case DELETE_NATION:
					Delete_Nation();
					break;

				case BACKUP:
					BackUp();
					break;
				}
				break;
			}
			break;
#pragma endregion

#pragma region 유저모드일 때

		case USER:
			select = UserMode(input_select);
			switch (select)
			{
			case SEARCH_CAPITAL_INFORMATION:
				select = Search_Capital_Information_Menu(input_select);
				switch (select)
				{
				case INDIVIDUAL_SEARCH:
					Individual_Search();
					break;
				case ALL_PRINT:
					All_Print();
					break;
				}
				break;
			case QUIZ:
				Quiz();
				break;
			}
			break;
#pragma endregion
		default:
			cout << endl
				<< "System Exit" << endl;
			end = true;
			break;
		}
	}
}
#pragma endregion

#pragma region Upload
void Manager::Upload()
{
	int count = 0;		//중복되는 나라, 수도의 개수를 저장할 변수
	string line;		//파일의 각 한줄씩을 입력받아 저장할 변수
	int divide_index;	//나라이름과 수도를 나누어 저장해줄 기준이 되는 인덱스 변수
	Nation nation;
	ifstream fin("nation.txt");		//해당 텍스트 값을 오픈
	if (!fin)
	{
		cout << "ERROR!!!" << endl; //읽기 오류일경우 에러 출력 후 리턴
		return;
	}
	while (getline(fin, line))
	{
		divide_index = line.find(":");		//:을 기점으로 나누어 저장하기 위한 코드
		nation.setNation(line.substr(0, divide_index));						// : 을 기점으로 나라와
		nation.setCapital(line.substr((divide_index + 1), line.length()));	// 수도의 값을 입력받음
		if (Find_Overlap(nation) != v.end())                               //그리고 중복되는 결과가 있을 경우 중복 저장 변수 Increment
		{
			count++;
			continue;
		}
		else //정상적인 값일 경우 벡터에 저장
			v.push_back(nation);
	}
	cout << "Upload Finished" << endl;
	if (count != 0) //만약 중복되는 결과가 있을 경우 알려줌!
		cout << endl
		<< "System: 중복되는 나라가 " << count << "개 발견하였기에, 중복되어 넣지 않았음을 미리 알려드립니다." << endl;
	fin.close();
}
#pragma endregion

#pragma region 수도이름 수정
void Manager::Rename_Capital()
{
	string input;
	if (v.size() == 0)
		cout << "수정할 국가가 없습니다!" << endl;
	else
	{
		cout << "수도를 수정하려는 국가를 입력해주세요. 입력한 값을 통해 해당 국가파일을 검색합니다." << endl;
		cin >> input;
		auto it = Find_Overlap(input);		//중복인지 아닌지 구분하고 그에 대한 위치를 it에 저장
		if (it != v.end())	//만약 중복인 경우(국가 이름이 겹친 경우)
		{
			cout << "수정될 수도의 이름을 적어주세요 >>";
			cin >> input;
			it->setCapital(input);
			cout << "수정되었습니다." << endl;
		}
		else		//데이터 내부에 없을 경우
			cout << "수정하려는 국가가 존재하지 않습니다." << endl;
	}
}
#pragma endregion

#pragma region 새로운 나라 추가
void Manager::Insert_Nation()
{
	Nation nation;
	cout << "추가할 나라의 이름을 입력해주세요." << endl;
	while (true)
	{
		cin >> nation;
		if (nation.getNation() == "no")
		{
			cout << endl
				<< "추가를 끝마치겠습니다." << endl;
			break;
		}
		if (Find_Overlap(nation) != v.end()) //중복검사
		{
			cout << "이미 존재하는 나라입니다. 다시 입력해주세요." << endl;
		}
		else //중복이 아닐 경우
		{
			v.push_back(nation);
			cout << "해당 나라를 추가하였습니다." << endl;
		}
	}
}
#pragma endregion

#pragma region 나라 삭제
void Manager::Delete_Nation()
{
	string nation_name;
	if (v.size() == 0)
		cout << "삭제할 국가가 존재하지 않습니다." << endl;
	else
	{
		cout << "삭제할 국가를 입력하여주십시오.";
		cin >> nation_name;
		auto it = Find_Overlap(nation_name);		//중복검사 후 해당 위치를 반환
		if (Find_Overlap(nation_name) != v.end())	//중복되는 값이 있을 경우
		{
			v.erase(it);		//해당 위치의 파일 삭제
			cout << "삭제되었습니다." << endl;
		}
		else				//중복이 없을경우(파일과 맞지 않는 경우)
		{
			cout << "존재하지 않는 국가입니다." << endl;
		}
	}
}
#pragma endregion

#pragma region 소스파일 백업
void Manager::BackUp()
{
	Nation nation;
	auto it = v.begin();
	if (v.size() == 0)
	{
		cout << "백업할 정보가 없습니다." << endl;
	}
	else
	{
		ofstream fout("nation.txt", ios::out);		//fout 스트림의 파일 열기
		if (!fout)		//파일 열기에 실패할 경우 리턴
		{
			cout << "ERROR!!!" << endl;
			return;
		}
		for (auto it = v.begin(); it < v.end(); it++)	//벡터의 모든 값을 저장
			fout << it->getNation() << ":" << it->getCapital() << endl;

		cout << "It completely backuped" << endl;
		fout.close();
	}
}
#pragma endregion

#pragma region 나라이름으로 개별 검색
void Manager::Individual_Search()
{
	string nation_name;
	if (v.size() == 0)
		cout << "검색할 나라가 존재하지 않습니다!" << endl;
	else
	{
		cout << "해당 나라를 검색하여 수도를 알아보세요!" << endl;
		cout << "나라 : ";
		cin >> nation_name;
		auto it = Find_Overlap(nation_name);		//검색할 나라가 벡터 내부에 존재하는지 여부 확인 후 그에 대한 위치 저장
		if (it != v.end())		//만약 존재할 경우
		{
			cout << it->getNation() << "의 수도는 " << it->getCapital() << "입니다." << endl;
		}
		else
			cout << "해당 나라는 데이터에 존재하지 않습니다!" << endl;
	}
}
#pragma endregion

#pragma region 나라정보 전체 출력
void Manager::All_Print()
{
	int count = 1;
	if (v.size() == 0)
		cout << endl
		<< "출력할 나라가 없습니다." << endl;
	else
	{
		for (auto it = v.begin(); it < v.end(); it++)
		{
			cout << "[" << count << "] " << *it;
			count++;
		}
	}
}
#pragma endregion

#pragma region 퀴즈
void Manager::Quiz()
{
	srand(time(nullptr));
	int index;
	string answer;
	int score = 0;
	int i;
	for (i = 0; i < 4; i++)
	{
		index = rand() % v.size();
		cout << "[문제 " << i + 1 << "] " << v[index].getNation() << "의 수도는?" << endl;
		cout << "정답 : ";
		cin >> answer;
		if (answer == "9")
		{
			break;
		}
		else if (answer == v[index].getCapital())
		{
			score++;
		}
	}
	cout << "퀴즈 문제풀이 수 : " << i << endl;
	cout << "그에 따른 정답률 : " << (float)score * 100 / i << "%" << endl;
}
#pragma endregion