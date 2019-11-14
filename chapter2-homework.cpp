/* 第二章 课后作业 */
#include <iostream>
using namespace std;

int main()
{
	// 破冰练习1
	cout << "--------- exercise 1 -------" << endl;
	cout << "int		整型" << endl;
	cout << "short		短整型" << endl;
	cout << "long		长整型" << endl;
	cout << "bool		布尔类型" << endl;
	cout << "char		字符类型" << endl;
	cout << "float		单精度浮点型" << endl;
	cout << "double		双精度浮点型" << endl;

	// 破冰练习2
	cout << "--------- exercise 2 -------" << endl;
	int a, b, c;
	cout << "请输入 a =" << endl;
	cin >> a;
	cout << "请输入 b =" << endl;
	cin >> b;
	cout << endl << "交换前"
		<< "\t" << "a=" << a
		<< "\t" << "b=" << b << endl;
	c = a;
	a = b;
	b = c;
	cout << "交换后"
		<< "\t" << "a=" << a
		<< "\t" << "b=" << b << endl;

	// 破冰练习3
	cout << "--------- exercise 3 -------" << endl;
	char d;
	cout << "请输入一个小写字母：\n";
	cin >> d;
	d -= 32;
	cout << "转换后为：\n" << d << endl;

	// 课后练习
	char ab = 97;
	cout << ab << endl;

	system("PAUSE");
}