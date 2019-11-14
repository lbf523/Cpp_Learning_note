#include "LandOwnerV3.h"

LandOwnerV3::LandOwnerV3()
{
	// 一般使用构造函数进行成员变量初始化
	_name = "【地主1】";
	_score = 0;
	// 将用户的手牌数组初始化为0
	memset(_cards, 0, sizeof(_cards));
	cout << "LandOwnerV3 的无参构造函数（默认构造）被调用！" << endl;
	cout << "初始化的结果如下：" << endl;
	cout << "\t名称：\t" << _name << endl;
	cout << "\t积分：\t" << _score << endl;
	cout << "\t手牌数组：\t";
	for (int i = 0; i < sizeof(_cards) / sizeof(_cards[0]); i++) {
		cout << _cards[i] << ", ";
	}
	cout << endl;
}

void LandOwnerV3::SetScore(long lScore)
{
	if (lScore < 0) {
		// 如果传入的积分为非法情况，那么积分就默认为0
		_score = 0;
	}
	else {
		// 积分为正数时，才进行赋值操作
		_score = lScore;
	}
}


// 实现摸牌方法
void LandOwnerV3::TouchCard(int cardCount)	// 域方法
{
	// 暂时省略函数的实现
	cout << _name << "摸" << cardCount << "张牌" << endl;
}

void LandOwnerV3::ShowScore() {
	cout << _name << "当前的积分为：" << _score << endl;
}

LandOwnerV3::~LandOwnerV3()
{
}
