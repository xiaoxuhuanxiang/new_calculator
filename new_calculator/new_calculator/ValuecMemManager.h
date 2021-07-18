#pragma once
#include "value_c.h"
#include <vector>
using namespace std;
class ValuecMemManager
{
public:
	ValuecMemManager();
	~ValuecMemManager();
	static void setSize(size_t size);
	static value_c* p_malloc();
	static void p_freeAll();
private:
	static vector<value_c *> m_data;
};

