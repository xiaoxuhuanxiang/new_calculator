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

enum ElementType
{
	VT_NUMBER = 0,
	VT_PLUS,
	VT_MINUS,
	VT_MUL,
	VT_DIV,
	VT_LPTH,
	VT_RPTH,
	VT_EQUAL,
	VT_FUNCNAME,
	VT_FUNCLPTH,
	VT_FUNCRPTH,
	VT_FUNCARGU,
	VT_FUNCARGDELI,
	VT_VARNAME,
	VT_UNKNOWN,
	VT_MAX
};

class global
{
public:
	global();
	~global();
	static void Init();
	static ElementType getOperType(const string &oper_c, int &len);
	static int getMaxOperByte();
	static bool isOperType(ElementType theType);
	static int getOperPrior_char(const string &oper_c);
	static int getOperPrior_type(ElementType theType);
	static int getNumOfOperandsByOper(ElementType theType);
private:
	static map<string, ElementType> operMap;
	static int operPrior[VT_MAX];
	static bool bInit;
	static map<ElementType, int> m_operEles;
};

