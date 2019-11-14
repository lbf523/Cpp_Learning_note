// 函数重载
#include <iostream>
#include <string>
using namespace std;

// 使用函数重载技术
// 读取参数的时候才知道参数类型
template<typename T> void Sort(T tArray[], int len);
template<typename T> void Show(T tArray[], int len);

int main()
{
	int inums[] = { 4,2,6,3,1 };
	float fnums[] = { 4.3f, 5.2f, 6.4f, 2.4f, 5.6f };
	string sNames[] = { "关羽","张飞","刘备" };

	cout << "排序前：";
	Show(inums, sizeof(inums) / sizeof(int));
	Sort(inums, sizeof(inums) / sizeof(int));
	cout << "排序后：";
	Show(inums, sizeof(inums) / sizeof(int));
	cout << endl;
	cout << "排序前：";
	Show(fnums, sizeof(fnums) / sizeof(int));
	Sort(fnums, sizeof(fnums) / sizeof(int));
	cout << "排序后：";
	Show(fnums, sizeof(fnums) / sizeof(int));

	Show(sNames, 3);

	system("PAUSE");
	return 0;
}

// 定义时习惯性用两行
template<typename T>
void Sort(T tArray[], int len)
{
	T temp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (tArray[j] > tArray[j + 1]) {
				temp = tArray[j];
				tArray[j] = tArray[j + 1];
				tArray[j + 1] = temp;
			}
		}
	}
}

template<typename T>
void Show(T tArray[], int len)
{
	for (int i = 0; i < len; i++) {
		cout << tArray[i] << ", ";
	}
	cout << endl;
}
