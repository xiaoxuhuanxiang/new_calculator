#pragma once
#include <map>
using namespace std;
//�洢ȫ���࣬ȫ����Ϣ������
//�����������ڣ�
//֧�ֵķ��ţ����ڶ���������趨�����ȼ���ҲΪ�д�ģ���ṩtoken
//ȫ�ֹ���ķ��ű������򲻿��Ǻ����ͱ�����������˲���ȫ�ַ��ű�洢�����ͱ����������÷���ջ��
enum valueType
{
	VAL_INT,
	VAL_DOUBLE,
	VAL_STRING
};

enum operType
{
	OPER_PLUS,
	OPER_MINUS,
	OPER_MUL,
	OPER_DIV,
	OPER_LPTH,  //������
	OPER_RPTH,  //������
	OPER_NUM
};

class global
{
public:
	global();
	~global();
	static void Init();
private:
	static map<string, operType> operMap;
	static int operPrior[OPER_NUM];
	static bool bInit;
};

