#include "ValuecMemManager.h"

vector<value_c *> ValuecMemManager::m_data;
ValuecMemManager::ValuecMemManager()
{

}

ValuecMemManager::~ValuecMemManager()
{

}

void ValuecMemManager::setSize(size_t size)
{
	m_data.reserve(size);
}

value_c* ValuecMemManager::p_malloc()
{
	value_c *theNew = new value_c();
	m_data.push_back(theNew);
	return theNew;
}

void ValuecMemManager::p_freeAll()
{
	for (auto &theNew : m_data)
	{
		delete theNew;
	}
}