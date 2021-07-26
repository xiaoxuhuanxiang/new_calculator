#pragma once
#include <string>
#include "global.h"
using namespace std;
//每个value_c类的对象都对应一个对语句切词后的元素
//此类贯穿执行模块的始终，每个模块的处理结果几乎都会在此类中写入信息
//如元素的类型（数字，函数名，变量名，+ - * / 等）
//next用于存储表达式下一个元素
//vertical用于存储垂直方向的内容，如遇到函数，变量，则在垂直方向解决。

class value_c
{
public:
	value_c();
	~value_c();
	void setStringData(string &data, ElementType roughType);
	const string& getStringData();
	value_c *addNext(value_c *&current);
	void freeChains(value_c *head);
	ElementType getElementType();
	value_c *next;
	value_c *vertical;
private:
	ElementType m_type;
	string m_data;
	//int m_validNum;
	int m_pos;
	int m_line;
};

