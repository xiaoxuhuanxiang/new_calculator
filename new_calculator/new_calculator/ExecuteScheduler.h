#pragma once
#include <vector>
#include <string>
using namespace std;
//ִ�е�����������н�Client�෢������Ϣ����������ִ������
//��Client�з���������������䣬�������δ���m_statements��Ա��
//Execute������Client����ã������û�����Ĳ���������Ӧ�ĵ��Ȳ���
//�������ܰ���run��rund��next�ȡ�
//Execute�����У�Ӧ���ú����д�ģ�飬Ԫ�سɷַ���ģ�飬������ͷ���ģ�顢ִ��������ģ��Ⱥ���ģ��

class ExecuteScheduler
{
public:
	ExecuteScheduler();
	~ExecuteScheduler();
	void pushStatements(string &statement);
	int Execute(string &param);
private:
	vector<string> m_statements;
};

