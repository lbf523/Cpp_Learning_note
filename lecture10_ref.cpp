// 引用

#include <iostream>

using namespace std;

void Swap1(int, int);
void Swap2(int*, int*);
void Swap3(int&, int&);

int main()
{
	int num1, num2;
	cout << "请输入两个整数，num1 num2" << '\t';
	cin >> num1 >> num2;
	cout << endl;
	cout << "num1和num2的值为：" << num1 << '\t' << num2 << endl;
	Swap1(num1, num2);
	cout << "Swap1交换后，num1和num2的值为：" << num1 << '\t' << num2 << endl;
	Swap2(&num1, &num2);
	cout << "Swap1交换后，num1和num2的值为：" << num1 << '\t' << num2 << endl;
	Swap3(num1, num2);
	cout << "Swap1交换后，num1和num2的值为：" << num1 << '\t' << num2 << endl;
	system("PAUSE");
	return 0;
}

// 按副本传递
void Swap1(int num1, int num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

void Swap2(int* p1, int* p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
// 引用为别名，将原来空间值传递过来，指针的高级实现
// 1. 可以更加简便地书写代码
// 2. 可以直接传递某个对象，而不只是复制了一份
// 3. 需避免参数被无意识修改，使用const
// 4. 不要返回局部变量的引用
// 5. 函数不返回值，默认返回传入的引用对象本身
void Swap3(int& ref1, int& ref2)
{
	int temp;
	temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}