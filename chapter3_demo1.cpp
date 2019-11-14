#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	// 打印德玛西亚之力
	SetConsoleTitle(L"示例：德玛西亚之力");		// https://zhidao.baidu.com/question/474974509.html
	/* 伤害 */
	double value_attack = 57.88;
	/* 伤害成长 */
	double value_attack_growth = 4.5;
	/* 攻击距离 */
	double value_attack_distance = 172;
	/* 护甲值 */
	double value_defence = 27.54;
	/* 护甲值加成 */
	double value_defence_growth = 3.0;

	cout << "名称：德玛西亚之力" << endl;
	cout << "伤害：" << value_attack << "(+" << value_attack_growth << ")\t"
		<< "攻击距离：" << value_attack_distance << endl;

	system("PAUSE");
	
}