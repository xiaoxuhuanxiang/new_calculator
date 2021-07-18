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
	cout << statement << endl;  //测试输入
#endif
	statement.erase(remove_if(statement.begin(), statement.end(), ::isspace), statement.end());
#ifdef TEST_MODE
	cout << "After clean some useless characters:" << endl;
	cout << statement << endl;  //测试清除空格和tab等字符后
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
			if (!execute(m_statements[ix]))
			{
				cout << "execute wrong" << endl;
				cleanAll();
				return -3;
			}
		}
	}
}
int ExecuteScheduler::execute(string &param)
{

	return 0;
}

void ExecuteScheduler::cleanAll()
{

}