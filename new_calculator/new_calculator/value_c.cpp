#include "value_c.h"
value_c::value_c()
{
	next = 0;
	vertical = 0;
	m_pos = 0;
	m_line = 0;
}
value_c::~value_c()
{

}

void value_c::setStringData(string &data, ElementType roughType)
{
	m_data = data;
}

const string& value_c::getStringData()
{
	return m_data;
}