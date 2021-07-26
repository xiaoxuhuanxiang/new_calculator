#include "global.h"
map<string, ElementType> global::operMap;
map<ElementType,int> global::m_operEles;
int global::operPrior[VT_MAX];
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
		operMap["+"] = VT_PLUS;
		operMap["-"] = VT_MINUS;
		operMap["*"] = VT_MUL;
		operMap["/"] = VT_DIV;
		operMap["("] = VT_LPTH;
		operMap[")"] = VT_RPTH;
		operMap["="] = VT_EQUAL;
		operPrior[VT_PLUS] = 1;
		operPrior[VT_MINUS] = 1;
		operPrior[VT_MUL] = 2;
		operPrior[VT_DIV] = 2;
		operPrior[VT_LPTH] = -1;
		operPrior[VT_RPTH] = -1;
		operPrior[VT_EQUAL] = -1;
		bInit = true;

		m_operEles.insert(make_pair(VT_PLUS, 2));
		m_operEles.insert(make_pair(VT_MINUS, 2));
		m_operEles.insert(make_pair(VT_MUL, 2));
		m_operEles.insert(make_pair(VT_DIV, 2));
	}
}

int global::getMaxOperByte()
{
	return 1;
}

ElementType global::getOperType(const string &oper_c, int &len)
{
	if (!bInit) Init();

	if (operMap.find(oper_c) != operMap.end())
	{
		len = int(oper_c.size());
		return operMap[oper_c];
	}
	string oper_c_tmp = oper_c;
	oper_c_tmp.pop_back();
	while (oper_c_tmp.size() > 0)
	{
		if (operMap.find(oper_c_tmp) != operMap.end())
		{
			len = int(oper_c_tmp.size());
			return operMap[oper_c_tmp];
		}
		else
		{
			oper_c_tmp.pop_back();
		}
	}
	len = 0;
	return VT_UNKNOWN;  //用于表明找不到
}

bool global::isOperType(ElementType theType)
{
	return m_operEles.find(theType) != m_operEles.end();
}

int global::getOperPrior_char(const string &oper_c)
{
	if (operMap.find(oper_c) == operMap.end()) return -2;
	return getOperPrior_type(operMap[oper_c]);
}

int global::getOperPrior_type(ElementType theType)
{
	return operPrior[theType];
}

int global::getNumOfOperandsByOper(ElementType theType)
{
	if (m_operEles.find(theType) == m_operEles.end()) return -1;
	return m_operEles[theType];
}