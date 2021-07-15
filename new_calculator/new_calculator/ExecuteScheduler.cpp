#include "ExecuteScheduler.h"
ExecuteScheduler::ExecuteScheduler()
{

}
ExecuteScheduler::~ExecuteScheduler()
{

}

void ExecuteScheduler::pushStatements(string &statement)
{
	m_statements.push_back(statement);
}

int ExecuteScheduler::Execute(string &param)
{
	return 0;
}