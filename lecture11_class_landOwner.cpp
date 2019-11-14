// 面向对象编程
// 使用class
// 创建类文件
#include <iostream>
#include "LandOwnerV1.hpp"	// 如果要使用类，那么必须包含类的头文件
#include "LandOwnerV2.h"
#include "LandOwnerV3.h"
#include "LandOwnerV5.h"
#include "Student.h"
using namespace std;

int main()
{
	// this 指针，是类成员函数的第一个默认隐含参数
	Student* ptrStu1 = new Student("迪丽热巴", "微胖女神");
	ptrStu1->AddScore(88.9f);
	ptrStu1->AddScore(92.9f);
	ptrStu1->AddScore(80.0f);
	ptrStu1->AddScore(95.2f);
	ptrStu1->AddScore(88.2f);
	ptrStu1->ShowInfo();

	// 使用栈内存
	Student Stu2 = { "刘强东","不是妻美" };
	Stu2.AddScore(88.5f);
	Stu2.AddScore(76);
	Stu2.AddScore(72);
	Stu2.AddScore(66);
	Stu2.AddScore(77);
	Stu2.ShowInfo();

	Student& scholar1 = Stu2.GetSuperScholar(*ptrStu1);
	Student& scholar2 = ptrStu1->GetSuperScholar(Stu2);

	cout << "学霸是：" << scholar1.GetName() << endl;
	cout << "学霸是：" << scholar2.GetName() << endl;

	delete ptrStu1;

	// scholar1在栈内存中引用，会自动释放

	/*------------------
	// 第五个版本
	LandOwnerV5* ptr_landOwner1 = new LandOwnerV5();
	LandOwnerV5* ptr_landOwner2 = new LandOwnerV5("二地主");
	LandOwnerV5* ptr_landOwner3 = new LandOwnerV5("三地主", "男", 10, 999);
	ptr_landOwner1->ShowInfo();
	ptr_landOwner2->ShowInfo();
	ptr_landOwner3->ShowInfo();

	// 地主摸牌
	ptr_landOwner1->TouchCard(20);

	delete ptr_landOwner1;
	delete ptr_landOwner2;
	delete ptr_landOwner3;
	/*-----------------------
	// 构造函数重载
	Student stu1;		// 在栈内存中直接分配空间
	Student stu2("马化腾", "普通家庭");
	Student stu3(32);
	Student stu4 = 50;
	stu2.ShowInfo();

	Student* stu5 = new Student("杰克马", "毁创阿里");	// 给stu5构造一个student的内存，在堆内存里新分配一个空间
	stu5->ShowInfo();	// 访问堆内存

	// 当对象使用完毕时，记得delete，释放内存
	delete stu5;

	//--------------------

	/* 第三个版本，封装
	LandOwnerV3 landOwner3;

	/* 第二个版本 .h
	LandOwnerV2 landOwner2;
	landOwner2.name = "【国王】";
	landOwner2.TouchCard(10);
	landOwner2.score = 100;
	landOwner2.ShowScore();

	
	/* 第一个版本 .hpp
	LandOwnerV1 landOwner1;		// 声明了一个LandOwnerV1的变量
	// 调用对象的成员方法
	// 不能直接使用对象的私有成员
	landOwner1.TouchCard(100);
	*/
	system("PAUSE");
	return 0;
}