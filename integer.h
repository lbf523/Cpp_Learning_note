#pragma once
// 运算符重载
// 定义的整型类，将整型封装成类，以便实现面向对象封装
class integer
{
public:
	integer();
	integer(int value) :m_value(value) {}	// 声明并实现

	// 重载+号运算符
	// 第一个const 更加有效率
	// 第二个const 不允许更改传递对象 
	// 第三个const 并不修改成员变量
	const integer operator+(const integer & other) const;
	int IntValue() { return m_value; }
	~integer();
private:
	int m_value;	// 实际的整型数字（member）
};

