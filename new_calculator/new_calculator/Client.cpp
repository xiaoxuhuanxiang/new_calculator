#include "Client.h"
#include <iostream>
using namespace std;
Client::Client()
{

}
Client::~Client()
{

}

int Client::clientRun(int testMode, string *test)
{
	string str_crt = "";
	bool lastExecute = false;
	int res(0);
	while (1)
	{
		size_t pos = str_crt.find(sentenceEnd);
		if (!str_crt.empty() && lastExecute)
		{
			if (pos == str_crt.npos)
			{
				cout << promptIden << str_crt << endl;
			}
		}

		if (pos == str_crt.npos)
		{
			string tmp;
			cout << promptIden;
			if (!testMode)
				getline(cin, tmp);
			else
			{
				if(!test->empty())
					tmp = *test;
				*test = "";
				if (tmp.empty())
					return 0;
			}

			str_crt += tmp;
			lastExecute = false;
			continue;
		}
		else
		{
			string str(str_crt.begin(), str_crt.begin() + pos);
			str_crt.erase(str_crt.begin(), str_crt.begin() + pos + 1);
			res = pushsOneStatement(str, testMode);
			if (res == RES_QUIT) break;
			lastExecute = true;
		}
	}
	return 0;
}

int Client::pushsOneStatement(string statement, int testMode)
{
	if (testMode)
	{
		cout << statement << endl;
	}
	return 0;
}