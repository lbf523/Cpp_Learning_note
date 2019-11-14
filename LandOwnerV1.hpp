#pragma once
// 声明并实现
/*
	.hpp 文件一般包含实现的内联函数
	通常用于模板类，一种声明与实现共存的情况
	建议：只要不是纯模板，一律使用.h后缀，使用.cpp作为函数实现文件
*/

/*
	public:		修饰的成员在任意地方都可以访问
	private:	修饰的成员只能够在类中，或者友元函数中可以访问
	protected:	修饰的成员可以在类中函数、子类函数及友元函数中访问
*/
#include <string>
#include <iostream>
using namespace std;

class LandOwnerV1
{
private:
	string name="【国王】";			//  地主的名称
	long score;				//  地主的积分
	int cards[20];			//  地主的手牌数组

public:
	// 以类名作为函数名
	// 无返回值类型
	// 作用：	1. 初始化对象的数据成员
	//			2. 类对象被创建时，编译器为对象分配内存空间
	//				并自动调用构造函数以完成成员的初始化
	// 构造函数的种类：1.无参构造，2.一般构造（重载构造），3.拷贝构造
	LandOwnerV1()	// 大括号是实现了默认构造函数
	{
	}

	~LandOwnerV1()
	{
	}

	inline void TouchCard(int cardCount)
	{
		// 暂时省略函数的实现
		cout << name << "摸" << cardCount << "张牌" << endl;
	}
	void ShowScore() {
		cout << name << "当前的积分为：" << score << endl;
	}
};

