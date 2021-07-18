#include <iostream>
#include "ExecuteScheduler.h"
#include <ctype.h>
#include <algorithm>
using namespace std;

ExecuteScheduler::ExecuteScheduler()
{
	m_pos = 0;
}
ExecuteScheduler::~ExecuteScheduler()
{

}

void ExecuteScheduler::pushStatements(string &statement)
{
#ifdef TEST_MODE
	cout << "test input" << endl;  //²âÊÔÊäÈë
	cout << statement << endl;  //²âÊÔÊäÈë
#endif
	statement.erase(remove_if(statement.begin(), statement.end(), ::isspace), statement.end());
#ifdef TEST_MODE
	cout << "After clean some useless characters:" << endl;
	cout << statement << endl;  //²âÊÔÇå³ý¿Õ¸ñºÍtabµÈ×Ö·ûºó
#endif
	if(!commandParse(statement))
		m_statements.push_back(statement);
}

int ExecuteScheduler::commandParse(string &statement)
{
	if (statement == runCommand)
	{
		if (m_statements.empty()) return -1;
		if (m_pos >= m_statements.size())
		{
			cout << "the execute position last time > the number of all statements, this should not be happened" << endl;
			return -2;
		}
		for (size_t ix = m_pos; ix < m_statements.size(); ++ix)
		{
			if (execute(m_statements[ix]))
			{
				cout << "execute wrong" << endl;
				cleanAll();
				return -3;
			}
			++m_pos;
		}
	}
}
int ExecuteScheduler::execute(string &calcu_statement)
{
#ifdef TEST_MODE
	cout << "run command: " << calcu_statement << endl;
#endif
	return 0;
}

void ExecuteScheduler::cleanAll()
{
	m_pos = 0;
}

int ExecuteScheduler::print()
{
	cout << "statements waiting for execute: " << endl;
	for (size_t ix = 0; ix < m_statements.size(); ++ix)
	{
		cout << m_statements[ix] << endl;
	}
	return 0;
}
