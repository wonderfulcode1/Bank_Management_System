#include "Card.h"
#ifndef _User_h
#define _user_h
class User
{
private:
	string phone, password;
public:
	CreditCard ccard;  //用户拥有信用卡
	DepositCard dcard;  //用户拥有储蓄卡
	string Register();//注册
	bool Login();//登录
	void save();//保存
	void read();//读取
	void print();//账户信息
	void print1();//带密码的
	void changepassword();//修改密码
	bool operate();////用户操作页面
	void name(string i);//记录电话信息
	string rename() { return phone; }//返回电话
	void get();//和管理员同步利率
};
#endif