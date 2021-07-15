#include "global.h"
map<string, operType> global::operMap;
int global::operPrior[OPER_NUM];
bool global::bInit = false;
global::global()
{
}
global::~global()
{
}

void global::Init()
{
	if (!bInit)
	{
		operMap["+"] = OPER_PLUS;
		operMap["-"] = OPER_MINUS;
		operMap["*"] = OPER_MUL;
		operMap["/"] = OPER_DIV;
		operMap["("] = OPER_LPTH;
		operMap[")"] = OPER_RPTH;
		operPrior[OPER_PLUS] = 1;
		operPrior[OPER_MINUS] = 1;
		operPrior[OPER_MUL] = 2;
		operPrior[OPER_DIV] = 2;
		operPrior[OPER_LPTH] = -1;
		operPrior[OPER_RPTH] = -1;
		bInit = true;
	}
}