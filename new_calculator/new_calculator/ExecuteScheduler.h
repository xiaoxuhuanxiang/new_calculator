#pragma once
#include <vector>
#include <string>
using namespace std;
//执行调度器，负责承接Client类发来的信息，包括语句和执行请求。
//将Client切分语句后推送来的语句，逐条依次存入m_statements成员。
//Execute函数供Client类调用，根据用户输入的参数进行相应的调度操作
//参数可能包括run，rund，next等。
//Execute函数中，应调用后续切词模块，元素成分分析模块，语句类型分析模块、执行链生成模块等后续模块

const std::string runCommand = "run";

class ExecuteScheduler
{
public:
	ExecuteScheduler();
	~ExecuteScheduler();
	void pushStatements(string &statement);
	int print();
private:
	int commandParse(string &statement);
	int execute(string &calcu_statement);
	void cleanAll();
	vector<string> m_statements;
	size_t m_pos;   //记录执行位置
};

