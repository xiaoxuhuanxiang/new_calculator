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
	m_type = roughType;
}

const string& value_c::getStringData()
{
	return m_data;
}

value_c *value_c::addNext(value_c *&current)
{
	current->next = new value_c();
	return current->next;
}

void value_c::freeChains(value_c *head)
{
	if (head->vertical)
	{
		freeChains(head->vertical);
	}
	if (head->next)
	{
		freeChains(head->next);
	}

	delete head;
}

ElementType value_c::getElementType()
{
	return m_type;
}