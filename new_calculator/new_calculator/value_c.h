#pragma once
#include <string>
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
private:
	string m_data;
	int m_validNum;
	int m_pos;
	value_c *next;
	value_c *vertical;
};

