#pragma once
#include <vector>
#include <string>
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
class Client
{
public:
	Client();
	~Client();
	int clientRun(int testMode=0, string *test=0);	//��ִ�к��������ⲿ����
private:
	int pushsOneStatement();
};

