#include "FuncPtr.h"

using namespace std;

int main()
{
	// 定义函数指针
	//double(*ptrCalc)(double, double);
	auto ptrCalc = addition; // 需要初始化
	double num1, num2;
	char op;
	cout << "请用户输入两个数：";
	cin >> num1 >> num2;
	cout << "请用户+操作符：";
	cin >> op;
	cout << addition(num1, num2) << endl;

	cout << "-------------" << endl;
	if (op == '+')
		ptrCalc = addition;
	print_result(ptrCalc, num1, num2);

	system("PAUSE");
	return 0;
}