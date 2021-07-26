#pragma once
#include <string>
#include "global.h"
using namespace std;
//ÿ��value_c��Ķ��󶼶�Ӧһ��������дʺ��Ԫ��
//����ᴩִ��ģ���ʼ�գ�ÿ��ģ��Ĵ��������������ڴ�����д����Ϣ
//��Ԫ�ص����ͣ����֣�����������������+ - * / �ȣ�
//next���ڴ洢���ʽ��һ��Ԫ��
//vertical���ڴ洢��ֱ��������ݣ����������������������ڴ�ֱ��������

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

