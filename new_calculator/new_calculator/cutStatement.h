#pragma once
#include "value_c.h"
#include "global.h"
class cutStatement
{
public:
	cutStatement();
	~cutStatement();
	static value_c *cutStmt(string &theStmt);
private:

};

