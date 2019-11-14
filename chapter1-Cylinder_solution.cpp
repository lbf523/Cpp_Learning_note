#include <iostream>
#include <cmath>
#include <iomanip>	// 控制符头文件
using namespace std;

int main()
{
	// 控制cout的显示精度
	// 1. 强制以小数的方式显示
	cout << fixed;
	// 2. 控制显示精度
	cout << setprecision(2);	// 显示两位小数
	// 输出double类型数据
	double doubleNum = 100.0 / 3.0;

	cout << doubleNum * 1000000 << endl;
	
	// 已知圆柱体的半径和高，求体积
	const float PI = 3.14f;		// const 定义常量，不能改变
	float radius = 4.5f;
	float height = 90.0f;
	double volume = PI * pow(radius, 2)*height;
	cout << "体积是：" << volume << endl;
	
	system("PAUSE");
}