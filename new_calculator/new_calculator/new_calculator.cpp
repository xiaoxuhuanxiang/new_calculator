// new_calculator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include "Client.h"
using namespace std;

void testClient_correct()  //Client类切分分号职责测试1
{
	string test;
	test = "1+1;2-5+3";

	cout << endl;
	cout << "result:" << endl;
	Client ct;
	ct.clientRun(1, &test);

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
	ct.clientRun(1, &test);

	cout << endl;
	cout << "expect:" << endl;
	cout << "1+1+2" << endl;
	cout << " 1+2+5" << endl;
	cout << "	2-5*6" << endl;
	cout << endl;
}

int main()
{
    std::cout << "Hello Calculator!\n";
	testClient_correct();
	testClient_wrong();
}

