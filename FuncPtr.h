#ifndef FUNCPTR_H_INCLUDE
#define FUNCPTR_H_INCLUDE
// 函数指针
// 自定义计算器
#include <iostream>
using namespace std;

// 加法
double addition(double, double);
// 减法
// 除法

// 打印计算结果
void print_result(double(*)(double, double), double, double);
// 函数指针操作
void print_result(double(*ptrCalc)(double, double), double num1, double num2)
{
	// 调用函数，打印结果
	double result = ptrCalc(num1, num2);
	cout << result << endl;
}

double addition(double num1, double num2)
{
	return num1 + num2;
}

#endif // !FUNCPTR_H_INCLUDE

