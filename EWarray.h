#ifndef EWARRAY_H_INCLUDE
#define EWARRAY_H_INCLUDE

#include <iostream>
using namespace std;

// 函数定义
void show(double(*)[5], int);

// 函数实现
void show(double(*arr)[5], int len)
{
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
		/*	cout << *(*(arr + i) + j) << ",";*/
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

#endif // !EWARRAY_H_INCLUDE
