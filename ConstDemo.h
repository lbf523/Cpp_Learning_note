#pragma once
#ifndef CONSTDEMO_H_INCLUDE
#define CONSTDEMO_H_INCLUDE

#include <iostream>
using namespace std;

// 1. const修饰成员变量
void ConstDemo1()
{
	int num1;
	const int num2 = 111;
	//num2 = 2048;	//“num2” : 不能给常量赋值
	const int *ptr1_num1 = &num1;
	int const *ptr2_num1 = &num1;
	ptr1_num1 = &num2;	// 合法
	//ptr1_num1 = 1234;	// 不合法
	// const修饰指针变量时：
	// 1. 只有一个const时，如果const位于*指针的左侧：表示指针所指的数据是常量，不能通过该指针修改实际数据
	//		指针本身是变量，可以指向其他内存
	// 2.  只有一个const时，如果const位于*指针的右侧：表示指针本身是常量，不能指向其他内存单元，所指向的数据可以修改
	int* const ptr3_num1 = &num1;
	//ptr3_num1 = ptr2_num1;	// 不合法
	// 3. 如果有两个const位于指针左右两侧，指针和指针指向的数据都不能改
}

// 2. const修饰函数参数
void ConstTest2(const int num)
{
	//num = 123;	// 传递进来的参数在函数体内不能改，与修饰变量时的性质一致
}
class Computer
{
public:
	Computer(int core) { this->m_core = core; }
	void buy() const{}
	void buy(int core){}
	void SetCore(int core) { this->m_core = core; }		// 修改电脑的核心频率
	int GetCore() const{ return this->m_core; }
private:
	int m_core;		// cpu主频
};

void ConstTest3(const Computer& computer)
{
	// const修改引用时，不能修改引用对象中的任何成员，可以保护传递的参数，不需要一个新的副本
	computer.buy();	// const 成员函数不能调用非const成员函数
	// 使用const传递对象的引用时，可以起到不copy对象的目的（节省效率）
}

// 3. const修饰返回值
// 强调：使用const修饰引用类型可以提高效率
const Computer & GetMax(const Computer &com1, const Computer &com2)
{
	if (com1.GetCore() > com2.GetCore()) {
		return com1;
	}
	return com2;
}
#endif // !CONSTDEMO_H_INCLUDE
