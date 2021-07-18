#include "Client.h"
#include <iostream>
using namespace std;
Client::Client()
{

}
Client::~Client()
{

}

int Client::clientRun(string *test)
{
	string str_crt = "";
	bool lastExecute = false;
	int res(0);
	while (1)
	{
		size_t pos = str_crt.find(sentenceEnd);
		if (!str_crt.empty() && lastExecute)
		{
#ifdef TEST_MODE
			if (pos == str_crt.npos)
			{
				if (!test)
					cout << promptIden << str_crt << endl;
				else
					cout << str_crt << endl;
			}
#else
			if (pos == str_crt.npos)
			{
				cout << promptIden << str_crt << endl;
			}
#endif
		}

		if (pos == str_crt.npos)
		{
			string tmp;
#ifdef TEST_MODE
			if (test)
			{
				if (!test->empty())
					tmp = *test;
				*test = "";
				if (tmp.empty())
					return 0;
			}
			else
			{
				getline(cin, tmp);
			}
#else
			cout << promptIden;
			getline(cin, tmp);
#endif
			str_crt += tmp;
			lastExecute = false;
			continue;
		}
		else
		{
			string str(str_crt.begin(), str_crt.begin() + pos);
			str_crt.erase(str_crt.begin(), str_crt.begin() + pos + 1);
			res = pushsOneStatement(str);
			if (res == RES_QUIT) break;
			lastExecute = true;
		}
	}
	return 0;
}

int Client::pushsOneStatement(string statement)
{
#ifdef TEST_MODE
	cout << statement << endl;
#endif
	es.pushStatements(statement);
	return 0;
}