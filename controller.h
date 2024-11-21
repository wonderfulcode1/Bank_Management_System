#include<vector>
using namespace std;
#ifndef _Controller_h
#define _Controller_h
class controller   //管理员类
{
public:
	vector<string>name;  //字符串变量，用于储存账户名字
	int all;//用户数量
	string pass;//管理员密码
	double interest, rate;//利息利率
	void Read();
	void Print();
	void Save();
	void operate();
	void show_inandout();//显示银行收支情况
};
#endif
