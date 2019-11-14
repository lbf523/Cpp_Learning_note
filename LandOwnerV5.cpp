#include "LandOwnerV5.h"



LandOwnerV5::LandOwnerV5()
{
	SetName("默认地主");
	SetSex("保密");
	SetGold(1000);
	SetExp(0);
	cout << "LandOwnerV5()" << endl;
	//InitCards();
}

LandOwnerV5::LandOwnerV5(string name) : m_Name(name)
{
	SetSex("保密");
	SetGold(1000);
	SetExp(0);
	cout << "LandOwnerV5(string name)" << endl;
	//InitCards();
}

LandOwnerV5::LandOwnerV5(string name, string sex, int gold, long exp) : m_Name(name), m_Sex(sex), m_Gold(gold), m_Exp(exp)
{

	cout << "LandOwnerV5(string name, string sex, int gold, long exp)" << endl;
	//InitCards();
}

void LandOwnerV5::ShowInfo()
{
	cout << "-------------------------" << endl;
	cout << "昵称：" << GetName() << endl;
	cout << "性别：" << GetSex() << endl;
	cout << "金币：" << GetGold() << endl;
	cout << "经验：" << GetExp() << endl;
}

// 初始化packCards，surplusCards，currCards
void LandOwnerV5::InitCards()
{
	// 生成一副扑克牌
	for (int i = 0; i < 54; i++) {
		packCards.push_back(i + 1);
		surplusCards.push_back(packCards.at(i));		// 从packCards中取值
	}
	currCards.clear();		// 手牌清空

	ShowCards(packCards);
}

// 显示牌面
void LandOwnerV5::ShowCards(const vector<int>& cards)	// 采用引用的方法，避免赋值
{
	/* 1. C 语言方式
	for (int i = 0; i < cards.size(); i++) {
		cout << cards[i] << ", ";
	}
	*/
	/* 2. 使用迭代器
	for (vector<int>::const_iterator iter = cards.begin(); iter != cards.end(); iter++) {
		cout << *iter << ", ";
	}*/
	/* 3.使用C++11 中的类型推断
	for (auto iter = cards.begin(); iter != cards.end(); iter++) {
		cout << *iter << ", ";
	}*/
	// 4. C++11中的for区间遍历
	for (auto card : cards) {
		cout << getColor(card) << " " << getValue(card) << ", ";
	}
	// 5. 使用算法的方式，将容器中的内容复制到cout 绑定的迭代器容器中
	// #include <iterator>		#include <algorithm>
	// copy(cards.cbegin(), cards.cend(), ostream_iterator<int>(cout, ", "));

	cout << endl;
}

// ----------- 摸牌程序------------------
void LandOwnerV5::TouchCard(int cardCount)
{
	srand(time(NULL));	// 生成时间种子
	// 随机生成一张剩余牌集合中有的牌，添加到currCards中，从surplusCards中删除这张牌
	for (int i = 0; i < cardCount; i++) {
		int randIndex = rand() % 54;		// 生成0-53中的随机数字
		// 判断生成的这张牌是否在剩余牌集合中
		if (isContains(packCards[randIndex])) {
			currCards.push_back(packCards[randIndex]);		// 将摸的牌放入手牌中
			// 在剩余牌中删除这张牌
			deleteCard(surplusCards, packCards[randIndex]);
		}
		else {
			i--;		// 重新摸牌
		}
	}

	cout << "<地主摸牌> - 当前手牌如下" << endl;
	ShowCards(currCards);
	cout << "<地主摸牌后> - 剩下手牌如下" << endl;
	ShowCards(surplusCards);
}

bool LandOwnerV5::isContains(int cardNum)
{
	// 使用算法查找
	vector<int>::iterator iter = find(surplusCards.begin(), surplusCards.end(), cardNum);
	//if (iter == surplusCards.end()) {
	//	return false;
	//}
	//else {
	//	return true;
	//}
	return iter != surplusCards.end();

	/* 普通青年的做法
	for (int i = 0; i < surplusCards.size(); i++) {
		if (surplusCards[i] == cardNum) {
			return true;
		}
	}
	return false;*/
}

void LandOwnerV5::deleteCard(vector<int>& cardVec, int card)
{
	/* 普通青年的做法
	for (auto iter = cardVec.begin(); iter != cardVec.end;) {
		if (*iter == card) {	// 找到这张牌
			iter = cardVec.erase(iter);		// 这里的返回值指向已删除元素的下一个值
		}
		else {
			++iter;		// 继续判断下一个元素是否相同
		}
	}*/
	auto iter = find(cardVec.begin(), cardVec.end(), card);
	if (iter != cardVec.end()) {	// 找到
		cardVec.erase(iter);
	}
}
// -----------获得花色与牌面-------------------
string LandOwnerV5::getColor(int card)	// 给的牌面,card不是下标
{
	if (card == 53) return "小王";
	if (card == 54) return "大王";
	string colors[] = {
		"○", "●", "◇", "※"
	};
	return colors[(card - 1) / 13];
}

string LandOwnerV5::getValue(int card)
{
	if (card == 53) return "Black Joker";
	if (card == 54) return "Red Joker";
	string values[] = {
		"A", "2", "3", "4", "5", "6", "7", "8", "9",
		"10", "J", "Q", "K"
	};
	return values[(card - 1) % 13];
}
// ------------------------------------
LandOwnerV5::~LandOwnerV5()
{
	cout << m_Name << "被释放" << endl;
}
