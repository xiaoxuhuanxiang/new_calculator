// new_calculator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include "Client.h"
#include "ExecuteScheduler.h"
#include "cutStatement.h"
using namespace std;

void testClient_correct()  //Client类切分分号职责测试1
{
	string test;
	test = "1+1;2-5+3;";

	cout << endl;
	cout << "result:" << endl;
	Client ct;
	ct.clientRun(&test);

	cout << endl;
	cout << "expect:" << endl;
	cout << "1+1" << endl;
	cout << "2-5+3" << endl;
	cout << endl;
}

void testClient_wrong()  //Client类切分分号职责测试2
{
	string test;
	test = "1+1+2; 1+2+5; 1;	2-5*6;";

	cout << endl;
	cout << "result:" << endl;
	Client ct;
	ct.clientRun(&test);

	test = "3+2; 1*9-0+5 -3*(1+7);";
	ct.clientRun(&test);  //调用两次模拟换行操作

	cout << endl;
	cout << "expect:" << endl;
	cout << "1+1+2" << endl;
	cout << " 1+2+5" << endl;
	cout << " 1" << endl;
	cout << "	2-5*6" << endl;
	cout << "3+2" << endl;
	cout << " 1*9-0+5 -3*(1+7)" << endl;
	cout << endl;
}

void test_ExecuteScheduler()  //测试任务调度器
{
	string test;

	cout << endl;
	cout << "result:" << endl;
	ExecuteScheduler es;

	test = "1+1+2";
	es.pushStatements(test);
	test = " 1+2+5";
	es.pushStatements(test);
	test = " 1";
	es.pushStatements(test);
	test = "	2-5*6";
	es.pushStatements(test);

	test = "run";
	es.pushStatements(test);

	es.print();

	cout << endl;
	cout << "expect:" << endl;

	cout << "test input" << endl;
	cout << "1+1+2" << endl;
	cout << "After clean some useless characters:" << endl;
	cout << "1+1+2" << endl;

	cout << "test input" << endl;
	cout << " 1+2+5" << endl;
	cout << "After clean some useless characters:" << endl;
	cout << "1+2+5" << endl;

	cout << "test input" << endl;
	cout << " 1" << endl;
	cout << "After clean some useless characters:" << endl;
	cout << "1" << endl;

	cout << "test input" << endl;
	cout << "	2-5*6" << endl;
	cout << "After clean some useless characters:" << endl;
	cout << "2-5*6" << endl;

	cout << "run command: 1+1+2" << endl;
	cout << "run command: 1+2+5" << endl;
	cout << "run command: 1" << endl;
	cout << "run command: 2-5*6" << endl;

	cout << "statements waiting for execute: " << endl;
	cout << "1+1+2" << endl;
	cout << "1+2+5" << endl;
	cout << "1" << endl;
	cout << "2-5*6" << endl;
}

void test_cutStmt_correct()  //测试切词类，此例目前返回结果正确
{
	string test;
	test = "1+2+4*(7-8)";

	cout << "result:" << endl;
	cutStatement cs;
	cs.cutStmt(test);

	cout << endl;
	cout << "expect:" << endl;
	cout << "1" << " --> " << "+" << " --> " << "2" << " --> " << "+" << "4" << " --> " << "*" << " --> "
		<< "(" << " --> " << "7" << " --> " << "-" << " --> " << "8" << " --> " << ")" << endl;
}

void test_cutStmt_wrong()  //测试切词类，此例目前返回结果错误
{
	string test;
	test = "1-4+5+(1+2)";
	cutStatement cs;
	cs.cutStmt(test);

	cout << "expect:" << endl;
	cout << "1" << " --> " << "-" << " --> " << "4" << " --> " << "+" << "5" << " --> " << "+" << " --> "
		<< "(" << " --> " << "1" << " --> " << "+" << " --> " << "2" << " --> " << ")" << endl;
}

int main()
{
    std::cout << "Hello Calculator!\n";
	testClient_correct();
	testClient_wrong();
	test_ExecuteScheduler();
	test_cutStmt_correct();
	test_cutStmt_wrong();
}

