#include "Student.h"



Student::Student()
{
	cout << "默认构造" << endl;
}
Student::Student(int age)
{
	Setage(age);
	InitScores();
	cout << "调用带参构造：Student(int age)" << endl;
}
Student::Student(string name, string desc)	: m_Name(name), m_desc(desc)// 初始化参数列表的写法
{
	//m_Name = name;	//等价	SetName(name);
	//m_desc = desc;
	InitScores();
	cout << "调用带参构造：Student(string name, string desc)" << endl;
}

void Student::ShowInfo()
{
	cout << m_desc << "-" << m_Name << endl;
	for (int i = 0; i < scoresCount - 1; i++) {
		cout << this->scores[i] << "\t";
	}
	cout << endl;
}

// ----------- this 指针 --------------
/*void myShow(const Student* thiz)	// c语言的写法，this在C++中时函数的隐含第一个默认参数
{
	thiz->AddScore(88.9f);
}*/

void Student::InitScores()
{
	this->scores = new float[1];		// 分配一个float空间
	this->scoresCount = 1;				// 学生成绩个数为1
}

void Student::AddScore(float score)
{
	this->scores[this->scoresCount - 1] = score;	// 给scores数组的最后一个元素赋值
	// 1. 创建一个新数组，分配scoresCount+1个空间
	// 2. 将scores的内容复制到新数组中
	// 3. scoresCount++
	// 4. scores指向新数组
	float* newScores = new float[scoresCount + 1];
	float* oldScores = scores;		// 避免野指针
	memcpy(newScores, scores, sizeof(float)*scoresCount);	// 将scoresCount各元素从老数组复制到新数组
	scoresCount++;
	scores = newScores;
	delete oldScores;		// 删除旧的指针地址
}

/**
 * 返回学霸对象
 * @param otherStu 要对比的另外一个学生
 * @return 返回总分比较大的那个学生对象
 */
float Student::GetTotal()
{
	float sum = 0;
	for (int i = 0; i < scoresCount - 1; i++) {
		sum += scores[i];
	}
	return sum;		// 基本类型直接赋值就行，不用写成引用
}
Student& Student::GetSuperScholar(Student& otherStu)
{
	// 分别计算两个学生的总分
	if (this->GetTotal() > otherStu.GetTotal()) {
		return *this;		// 返回当前对象的引用，未假设分数相同
	}
	else {
		return otherStu;
	}
}
/*
析构函数（~）：
	1.对象过期时自动调用的特殊成员函数
	2.析构函数一般用来完成清理工作，释放对象使用的资源，并销毁对象的非static数据成员；无论何时一个对象被销毁，都会自动调用其析构函数
	3.析构函数没有参数，只有一个

	构造函数：程序调用开始时启用
	析构函数：程序调用结束时启用
*/
Student::~Student()
{
	delete this->scores;
	cout << m_Name << "被释放" << endl;
}
