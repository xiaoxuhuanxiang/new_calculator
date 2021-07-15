#pragma once
#include <vector>
#include <string>
using namespace std;

//Client类主要负责在控制台和用户交互，允许输入多条语句
//当输入多条语句时，client负责初步切分语句，以分号为语句界限。切分出语句时，立即将语句推送给后续执行调度模块
//当输入run时，调用后续执行调度模块，将历史所有语句逐条执行。
//当输入rund时，调用后续执行调度模块，将历史所有语句以debug形式单步执行，允许打印变量和函数的debug信息。包括最终值，以及AST树
//当输入语句时，变量名等不允许输入内部关键字run，rund
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
	int clientRun(int testMode=0, string *test=0);	//主执行函数，供外部调用
private:
	int pushsOneStatement();
};

