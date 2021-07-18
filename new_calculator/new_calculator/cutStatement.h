#pragma once
#include "value_c.h"
#include "global.h"
class cutStatement
{
public:
	cutStatement();
	~cutStatement();
	static value_c *cutStmt(string &theStmt);
	static bool isPartOfNumber(const char val_c, const char *val_c_reverse1);
private:

};