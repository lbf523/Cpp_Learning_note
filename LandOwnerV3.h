#pragma once
// 用来掩饰封装的基本概念
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

class LandOwnerV3
{
	// 省略了private，默认为private
	// 私有变量命名前加下划线 
	string _name;	//  地主的名称
	long _score;		//  地主的积分，解决积分被赋值为负数错误的方法：将成员变量score进行隐藏并封装
	int _cards[20];	//  地主的手牌数组
public:
	LandOwnerV3();
	~LandOwnerV3();

	// 使用【方法\函数】 实现对成员变量的封装【Get\Set方法】
	void SetScore(long);

	void TouchCard(int);		// 声明摸拍方法
	void ShowScore();
};

