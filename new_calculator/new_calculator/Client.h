#pragma once
#include <vector>
#include <string>
#include "ExecuteScheduler.h"
using namespace std;

//Client����Ҫ�����ڿ���̨���û���������������������
//������������ʱ��client��������з���䣬�Էֺ�Ϊ�����ޡ��зֳ����ʱ��������������͸�����ִ�е���ģ��
//������runʱ�����ú���ִ�е���ģ�飬����ʷ�����������ִ�С�
//������rundʱ�����ú���ִ�е���ģ�飬����ʷ���������debug��ʽ����ִ�У������ӡ�����ͺ�����debug��Ϣ����������ֵ���Լ�AST��
//���������ʱ���������Ȳ����������ڲ��ؼ���run��rund
//����quitʱ�˳�
//�ԡ�>��Ϊ������ʾ��

const std::string runRel = "run";    //ִ�����
const std::string rundebug = "rund"; //debugִ�����
const std::string quitIden = "quit"; //�˳����
const std::string promptIden = ">";  //������ʾ��
const std::string sentenceEnd = ";";  //��������
class Client
{
public:
	Client();
	~Client();
	int clientRun(string *test = 0);	//��ִ�к��������ⲿ����
private:
	enum runRes {
		RES_OK,
		RES_ERROR,
		RES_QUIT
	};
	int pushsOneStatement(string statement);
	ExecuteScheduler es;
};

