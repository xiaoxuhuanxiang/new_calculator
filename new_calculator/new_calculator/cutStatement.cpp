#include <iostream>
#include "cutStatement.h"
#include "ValuecMemManager.h"
using namespace std;
cutStatement::cutStatement()
{

}
cutStatement::~cutStatement()
{

}

bool cutStatement::isPartOfNumber(const char val_c, const char *val_c_reverse1)
{
	if (val_c == '.') return true;
	if (val_c == '-' && val_c_reverse1 == NULL) return true;
	if (val_c == '-' && !val_c_reverse1 && val_c_reverse1[0] == '(') return true;
	if (val_c >= '0' && val_c <= '9') return true;
	return false;
}

value_c *cutStatement::cutStmt(string &theStmt)
{
	if (theStmt.empty()) return 0;
	string::iterator itStart = theStmt.begin();
	string::iterator itEnd = itStart;
	char *lc;

	value_c *head = 0;
	value_c **current = &head;
	for (string::iterator it = theStmt.begin(); it != theStmt.end(); ++it)
	{
		if (it == theStmt.begin()) lc = NULL;
		else lc = &(*(it - 1));
		if (isPartOfNumber(*it, lc))  //数字的一部分
		{
			++itEnd;
			if (it == theStmt.end() - 1)
			{
				string crt(itStart, itEnd);
				*current = new value_c();
				(*current)->setStringData(crt, VT_NUMBER);
				current = &((*current)->next);
			}
			else if (!isPartOfNumber(*(it + 1), &(*it)))
			{
				string crt(itStart, itEnd);
				*current = new value_c();
				(*current)->setStringData(crt, VT_NUMBER);
				current = &((*current)->next);
			}
		}
		else
		{
			int operMaxLen = global::getMaxOperByte();
			int operRealMaxlen = (theStmt.end() - it > operMaxLen) ? operMaxLen : (theStmt.end() - it);
			string crtOper(it, it + operRealMaxlen);
			int len;
			ElementType theType = global::getOperType(crtOper, len);
			
			if (theType != VT_UNKNOWN)
			{
				*current = new value_c();
				itStart = it + len;
				itEnd = itStart;
				string crt(it, it + len);
				(*current)->setStringData(crt, theType);
				current = &((*current)->next);
				it += (len - 1);
			}
			else
			{
				string::iterator ittmp;
				ittmp = it;
				//itStart = it;
				while (theType == VT_UNKNOWN)
				{
					++ittmp;
					if (ittmp == theStmt.end())
					{
						string crt(it, ittmp);
						(*current)->setStringData(crt, VT_UNKNOWN);
						current = &((*current)->next);
						break;
					}
					operRealMaxlen = (theStmt.end() - ittmp > operMaxLen) ? operMaxLen : (theStmt.end() - ittmp);
					crtOper.assign(ittmp, ittmp + global::getMaxOperByte());
					theType = global::getOperType(crtOper, len);
				}

				string crt(it, ittmp);
				(*current)->setStringData(crt, VT_UNKNOWN);
				current = &((*current)->next);
				itStart = itEnd = ittmp;
				it = ittmp - 1;
			}
		}
	}

#ifdef TEST_MODE
	printChain(head);
#endif
	return head;
}

void cutStatement::printChain(value_c *head)
{
	value_c *current = 0;
	for (current = head; current; current = current->next)
	{
		cout << current->getStringData();
		if (current->next)
			cout << " --> ";
		else
			cout << endl;
	}
}