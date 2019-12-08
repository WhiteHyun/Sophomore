#pragma once
#include "Nation.h"
#include <vector>
#include <fstream>
#include <string>
constexpr auto ADMIN = 1;
constexpr auto SOURCE_FILE_UPLOAD = 1;
constexpr auto UPDATE_INFORMATION = 2;

constexpr auto USER = 2;
constexpr auto SEARCH_CAPITAL_INFORMATION = 1;
constexpr auto QUIZ = 2;

constexpr auto RENAME_CAPITAL = 1;
constexpr auto INSERT_NATION = 2;
constexpr auto DELETE_NATION = 3;
constexpr auto BACKUP = 4;
constexpr auto INDIVIDUAL_SEARCH = 1;
constexpr auto ALL_PRINT = 2;

class Manager
{
private:
	vector<Nation> v;
	void Upload();
	void Rename_Capital();
	void Insert_Nation();
	void Delete_Nation();
	void BackUp();
	void Individual_Search();
	void All_Print();
	void Quiz();
	vector<Nation>::iterator Find_Overlap(const Nation& nation);		//중복 여부 검사 후 위치 반환 함수
	vector<Nation>::iterator Find_Overlap(const string& nation_name);	//이하 동일
public:
	void Menu();
};