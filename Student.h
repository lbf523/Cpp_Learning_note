#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student
{
public:
	Student();
	Student(int);
	Student(string, string);	// 带参构造
	~Student();
	void ShowInfo();
	// get，set
	string GetName() { return m_Name; }
	void SetName(string val) { m_Name = val; }
	string Getdesc() { return m_desc; }
	void Setdesc(string val) { m_desc = val; }
	int Getage() { return m_age; }
	void Setage(int val) { m_age = val; }

	void InitScores();		// 初始化学生成绩数组
	void AddScore(float);		// 添加分数

	// 返回一个学霸对象，分数较高的
	Student& GetSuperScholar(Student&);
	// 函数结尾加const，函数内部不允许修改变量，调用本对象非const就会报错
	//const Student& GetSuperScholar(Student&) const;
	float GetTotal();
private:
	string m_Name;
	string m_desc;
	int m_age;

	// this指针
	int scoresCount;	// 学生的成绩个数
	float* scores;		// 学生的分数数组
};

