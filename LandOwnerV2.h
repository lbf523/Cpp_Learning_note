#pragma once
#include <string>
#include <iostream>
using namespace std;

class LandOwnerV2
{
public:
	string name;			//  地主的名称
	long score;							//  地主的积分
	int cards[20];						//  地主的手牌数组

public:
	LandOwnerV2();
	~LandOwnerV2();

	void TouchCard(int);		// 声明摸拍方法
	void ShowScore();
};

