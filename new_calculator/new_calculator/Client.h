#pragma once
#include <vector>
#include <string>
using namespace std;

//Client����Ҫ�����ڿ���̨���û���������������������
//������������ʱ��client��������з���䣬�Էֺ�Ϊ�����ޣ����������������Աm_statements����
//������runʱ����m_statements�д洢�������������ѭ��ִ�У����ú���ģ��(��runOneStatement˽�к�������)
//������rundʱ������������debug��ʽ����ִ�У������ӡ�����ͺ�����debug��Ϣ����������ֵ���Լ�AST��
//���������ʱ�������������ڲ��ؼ���run
//����quitʱ�˳�
//�ԡ�>��Ϊ������ʾ��

const std::string runRel = "run";    //ִ�����
const std::string rundebug = "rund"; //debugִ�����
const std::string quitIden = "quit"; //�˳����
const std::string promptIden = ">";  //������ʾ��
class Client
{
public:
	Client();
	~Client();
	int clientRun();	//��ִ�к��������ⲿ����
private:
	int runOneStatement();
	vector<string> m_statements; //�Էֺ�Ϊ���ָ������õ�����伯������һ�����������䡣
};

