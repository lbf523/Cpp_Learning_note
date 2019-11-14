#include "LandOwnerV2.h"



LandOwnerV2::LandOwnerV2()
{
}

// 实现摸拍方法
void LandOwnerV2::TouchCard(int cardCount)	// 域方法
{
	// 暂时省略函数的实现
	cout << name << "摸" << cardCount << "张牌" << endl;
}

void LandOwnerV2::ShowScore() {
	cout << name << "当前的积分为：" << score << endl;
}

LandOwnerV2::~LandOwnerV2()
{
}
