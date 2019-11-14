/*********************************************
 * 文件名: game1.cpp
 * 创建人: lbf
 * 日  期: 2019年10月30日
 * 描  述: C++第一阶段项目《小公举养成记》
 * 修改人: someone
 * 日  期: someday
 * 版  本: 1.0.0
 * Copyrite (c) ...
*********************************************/
#include <iostream>
#include <iomanip> // 控制输出格式
#include <ctime>
#include <vector>
#include <array>
#include <string>
using namespace std;

int main()
{
	/* 父亲的姓名 */
	string value_father_name;
	/* 女儿的姓名 */
	string value_daughter_name;
	/* 女儿生日的月份 */
	int value_birth_month;
	/* 女儿生日的日期 */
	int value_birth_date;
	// 女儿的星座
	string value_daughter_constell;
	// 女儿的基本信息：
	array<int, 5> value_array_baseinfos;	// 定义数组
	// 五项基本属性名
	array<string, 5> value_array_baseinfo_names = { "体力","智力","魅力","道德","气质" };

	int choice, temp1, temp2;
	// 判断星座
	string constell_names[12][2] = {
		{ "山羊座","水瓶座" },	// 一月
		{ "水瓶座","双鱼座" },	// 二月
		{ "双鱼座","白羊座" },	// 三月
		{ "白羊座","金牛座" },	// 四月
		{ "金牛座","双子座" },	// 五月
		{ "双子座","巨蟹座" },	// 六月
		{ "巨蟹座","狮子座" },	// 七月
		{ "狮子座","处女座" },	// 八月
		{ "处女座","天秤座" },	// 九月
		{ "天秤座","天蝎座" },	// 十月
		{ "天蝎座","射手座" },	// 十一月
		{ "射手座","山羊座" },	// 十二月
	};
	// 1. 为父女取名字
	cout << "父亲的姓名：";
	cin >> value_father_name;
	cout << "女儿的姓名：";
	cin >> value_daughter_name;

	// 2. 为女儿录入初始信息（生日）
	cout << "女儿的生日（MM DD）：";
	cin >> value_birth_month >> value_birth_date;
	// 各月份的跨星座日期，每个星座的最后一天
	int constell_dates[]{ 20,19,21,20,21,22,23,23,23,24,23,22 };
	// 星座赋值
	value_daughter_constell = constell_names[value_birth_month - 1][value_birth_date / constell_dates[value_birth_month - 1]];
	cout << "----------------------------" << endl;
	cout << "女儿的信息：" << endl;
	cout << "\t姓名：" << value_daughter_name << endl;
	cout << "\t生日：1659-" << value_birth_month << "-" << value_birth_date << endl;
	cout << "\t星座：" << value_daughter_constell << endl;

	//    根据女儿的行踪，设置游戏的基本参数（体力、智力、道德、、、）
	// 3. 开始游戏大循环
	// 游戏从1659年6月开始
	for (int year = 1659; year <= 1659 + 7; year++) {
		for (int month = (year == 1659) ? value_birth_month : 1; month <= 12; month++) {
			// 判断本月是否是女儿生日
			if (month == value_birth_month) {
				cout << "本月是" << value_daughter_name << "的生日，是否要送礼物？" << endl;
				// 根据用户的输入进行判断
			}
			// 显示游戏主菜单
			cout << "\n1、查看状态\n2、安排行程\n3、亲自谈话\n4、存档\n5、读档" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:	// 查看状态
				cout << "女儿的信息：" << endl;
				cout << "\t姓名：" << value_daughter_name << endl;
				cout << "\t生日：1659-" << value_birth_month << "-" << value_birth_date << endl;
				cout << "\t星座：" << value_daughter_constell << endl;
				// 打印核心属性
				cout << left;	// 左对齐
				for (int i = 0; i < 5; i++) {
					cout << value_array_baseinfo_names[i] << ":" << setw(6) << value_array_baseinfos[i];
					// 计算实心方框的数量
					int solidCount = value_array_baseinfos[i] / 10;
					for (int j = 0; j < 10; j++) {
						if (j < solidCount)
							cout << "■";
						else
							cout << "□";
					}
					cout << endl;
				}
				break;
			default:
				break;
			}
		}
	}
	// 4. 根据各项参数，判定游戏结果
	system("PAUSE");
	return 0;
}