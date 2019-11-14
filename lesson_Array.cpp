// 课程9
// 数组学习
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 使用泛型定义数组
	vector<double> vecDouble = { 100.3,213,42.6,23,53.6 };

	// 增加元素
	vecDouble.push_back(32.8);	// 在数组后加入一个值

	// 打印方法1:
	for (int i = 0; i < vecDouble.size(); i++) {
		cout << vecDouble[i] << '\t';
	}
	cout << endl;

	// 打印方法2：通用方法，使用迭代器
	cout << "使用迭代器的方法打印" << endl;
	vector<double>::iterator it;	// 得到一个指针
	// 从第一个元素开始迭代
	for (it = vecDouble.begin(); it != vecDouble.end(); ++it) {	// ++i:避免有缓存
		cout << *it << '\t';
	}
	cout << endl;

	// 排序
	sort(vecDouble.begin(), vecDouble.end());
	//reverse(vecDouble.begin(), vecDouble.end());	// 逆序
	for (it = vecDouble.begin(); it != vecDouble.end(); ++it) {	// ++i:避免有缓存
		cout << *it << '\t';
	}
	cout << endl;

	system("PAUSE");
}