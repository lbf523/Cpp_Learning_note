// 循环进阶
#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 5; i++)	// 控制行
	{
		for (int j = 0; j <= 3-i; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j <= i; j++) // 控制列
		{
			cout << '*';
		}
		cout << endl;
	}

	for (int i = 0; i < 5; i++)	// 控制行
	{
		for (int j = 0; j <= i-1; j++) // 控制列
		{
			cout << ' ';
		}
		for (int j = 0; j <= 4 - i; j++) // 控制列
		{
			cout << '*';
		}
		cout << endl;
	}
	system("PAUSE");
}