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
#ifdef TEST_MODE
	cout << "1" << " --> " << "+" << " --> " << "2" << " --> " << "+" << "4" << " --> " << "*" << " --> "
		<< "(" << " --> " << "7" << " --> " << "-" << " --> " << "8" << " --> " << ")" << endl;
#endif
	return 0;
}