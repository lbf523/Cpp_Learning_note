// 数组，冒泡排序
#include <iostream>
using namespace std;

int main()
{
	// 1, 第一轮比较的次数：总个数-1
	// 2, 第二轮比上一轮比较的次数少1次

	int nums[] = { 5,3,7,10,2,1,15,19,8,6,17 };
	int len = sizeof(nums) / sizeof(int);
	int temp;

	cout << "排序前：";
	for (int n = 0; n < len; n++) {
		cout << nums[n] << ',';
	}

	// 选择排序
	int min;	// 假定第一个为最小值
	int minindex;		// 下标
	for (int i = 0; i < len; i++) {
		min = nums[i];
		minindex = i;
		for (int j = i+1; j < len; j++) {
			if (nums[j] < min)
			{
				min = nums[j];
				minindex = j;
			}
		}
		if (minindex > i) {
			temp = nums[minindex];
			nums[minindex] = nums[i];
			nums[i] = temp;
		}
	}

	/*
	// 冒泡排序
	// 1, 外层循环控制轮数
	for (int i = len-1; i > 0; i--) {
		// 2, 内层循环控制每轮的比较和交换
		for (int j = len-i; j > 0; j--) {
			if (nums[j-1 ] > nums[j]) 
			{
				temp = nums[j-1];
				nums[j-1] = nums[j];
				nums[j] = temp;
			}
		}
	}
	*/

	cout << "\n排序后：";
	for (int n = 0; n < len; n++) {
		cout << nums[n] << ',';
	}
	cout << endl;

	// 逆序
	for (int i = 0; i < len / 2; i++) {
		temp = nums[i];
		nums[i] = nums[len-i-1];
		nums[len-i-1] = temp;
	}
	cout << "\n逆序后：";
	for (int n = 0; n < len; n++) {
		cout << nums[n] << ',';
	}
	cout << endl;
	system("PAUSE");
}