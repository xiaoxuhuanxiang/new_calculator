#pragma once
#include <map>
using namespace std;
//存储全局类，全局信息等内容
//包括但不限于，
//支持的符号，用于定义操作，需定义优先级。也为切词模块提供token
//全局共享的符号表，本程序不考虑函数和变量作用域，因此采用全局符号表存储函数和变量，不采用符号栈。
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

