#include <iostream>
using namespace std;
#ifndef _Card_h
#define _Card_h
//定义银行卡类，由此派生信用卡类和储蓄卡类。
class Card
{
protected:
	double money;  //银行卡的金额
	
public:
	static double total_in;  //静态变量，记录所有银行卡的总收入
	static double total_out;  //静态变量，记录所以银行卡的总支出
	double getmoney() { return money; }  //返回银行卡的金额
	static void show_inout() //静态函数，显示累计存取款总数
	{ cout << "银行累计存款：" << total_in << "元\t累计取款：" << total_out << "元\n"; }
	void change(double i)  //用change函数改变金额
	{
		money += i;
		return;
	}
	virtual void create_card() = 0;  //纯虚函数，提供办卡界面的公共接口
	virtual void deposit() ;   //共有成员函数，实现存钱功能
	virtual void withdraw()=0; //纯虚函数，实现取钱功能界面的公共接口
	virtual void transfer() = 0;   //纯虚函数，实现转账功能的公共接口
	void goback();  //共有成员函数，实现返回功能

};						

class CreditCard :public Card   //定义信用卡类，继承银行卡类
{
private:
	double overdraft;//可透支额度
	double interest;//利息
public:
	double getoverdraft() { return overdraft; }  //返回信用卡额度
	double getinterest() { return interest; }//返回信用卡利息
	void create_card();//声明信用卡的办卡
	void creditoperate(); //信用卡操作页面
	 void withdraw() ;//取钱
	 void transfer() ;//转账
	void cset(double i)  //设置信用卡利息
	{
		interest = i;
	}
	friend istream& operator>>(istream& input, CreditCard& a);
	friend ostream& operator<<(ostream& output, CreditCard& a);
};
class DepositCard :public Card //不可透支，基金
{
private:
	double rate;//利率
public:
	double getrate() { return rate; }
	void create_card() ;
	void depositoperate();//储蓄卡操作界面
	virtual void withdraw();
	virtual void transfer();
	void dset(double r)  //设置储蓄卡利率
	{
		rate = r;
	}
	friend istream& operator>>(istream& input, DepositCard& a);
	friend ostream& operator<<(ostream& output, DepositCard& a);
};
#endif