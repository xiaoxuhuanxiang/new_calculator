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

enum operType
{
	OPER_PLUS,
	OPER_MINUS,
	OPER_MUL,
	OPER_DIV,
	OPER_LPTH,  //左括号
	OPER_RPTH,  //左括号
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

