#pragma once
#include <vector>
#include <string>
using namespace std;

//Client类主要负责在控制台和用户交互，允许输入多条语句
//当输入多条语句时，client负责初步切分语句，以分号为语句界限，并将所有语句存入成员m_statements当中
//当输入run时，对m_statements中存储的所有语句逐条循环执行，调用后续模块(用runOneStatement私有函数来做)
//当输入rund时，输入的语句以debug形式单步执行，允许打印变量和函数的debug信息。包括最终值，以及AST树
//当输入语句时，不允许输入内部关键字run
//输入quit时退出
//以‘>’为命令提示符

const std::string runRel = "run";    //执行语句
const std::string rundebug = "rund"; //debug执行语句
const std::string quitIden = "quit"; //退出语句
const std::string promptIden = ">";  //命令提示符
class Client
{
public:
	Client();
	~Client();
	int clientRun();	//主执行函数，供外部调用
private:
	int runOneStatement();
	vector<string> m_statements; //以分号为语句分隔符，得到的语句集，允许一次输入多条语句。
};

