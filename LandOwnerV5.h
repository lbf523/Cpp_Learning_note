#pragma once
#include <string>
#include <iostream>
#include <vector>
// 迭代器与算法头文件
#include <iterator>
#include <algorithm>
// 随机数头文件
#include <cstdlib>
#include <ctime>
using namespace std;

class LandOwnerV5
{
private:
	string m_Name;
	string m_Sex;
	int m_Gold;
	long m_Exp;
	vector<int> packCards;		// 一副牌，1-54
	vector<int> surplusCards;	// 摸牌后剩下的牌
	vector<int> currCards;		// 当前玩家的手牌

	bool isContains(int);		// 剩余牌中是否包含这张牌
	void deleteCard(vector<int>&, int);		// 删除集合中的牌

	string getColor(int);		// 获得花色
	string getValue(int);		// 获得牌面
public:
	LandOwnerV5();
	LandOwnerV5(string);
	LandOwnerV5(string, string, int, long);
	~LandOwnerV5();

	string GetName() { return m_Name; }
	void SetName(string val) { m_Name = val; }
	string GetSex() { return m_Sex; }
	void SetSex(string val) { m_Sex = val; }
	int GetGold() { return m_Gold; }
	void SetGold(int val) { m_Gold = val; }
	long GetExp() { return m_Exp; }
	void SetExp(long val) { m_Exp = val; }

	void TouchCard(int);	// 摸牌
	void ShowInfo();
	void InitCards();		// 初始化packCards，surplusCards，currCards
	void ShowCards(const vector<int>&);		// 传入牌数组并显示
};

