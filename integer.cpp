#include "integer.h"



integer::integer() : m_value(0)	// 调用默认构造时，默认给m_value赋值0
{
}

const integer integer::operator+(const integer & other) const
{
	integer result(this->m_value + other.m_value);		// 用来返回结果对象
	return result;
}


integer::~integer()
{
}
