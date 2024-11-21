#include<fstream>
#include "User.h"

using namespace std;
bool isFileExists_ifstream1(string& name) //用于检查文件是否存在
{
	ifstream f(name.c_str());
	return f.good();
}

//CreditCard
istream& operator>>(istream& input, CreditCard & a) //重载流提取运算符
{
	input >> a.money >> a.overdraft >> a.interest;
	return input;
}
ostream& operator<<(ostream& output, CreditCard &a)//重载流插入运算符
{
	output << a.money << "\t" << a.overdraft << "\t" << a.interest << endl;
	return output;
}
void CreditCard::creditoperate()
{
	int choice;
	double m;
	system("cls");
	cout << "--------信用卡--------\n";
	if (overdraft == -1)
	{
		create_card();
	}
	while (1)
	{
		cout << "----------请选择您的需求--------\n";
		cout << "\t|\t存钱 ①\t\t|\t\n";
		cout << "\t|\t取钱 ②\t\t|\t\n";
		cout << "\t|\t转账 ③\t\t|\t\n";
		cout << "\t|\t返回 ④\t\t|\t\n";
		cout << "请输入指令：";
		cin >> choice;
		if (choice == 1)//存钱
		{
			deposit(); 
		}
		if (choice == 2)//取钱
		{
			withdraw();  
		}
		if (choice == 3)//转账
		{
			transfer();
		}

		if (choice == 4) { goback(); return; } //返回键
	}

}
void Card::deposit() 
{
	double m;
	system("cls");
	cout << "-------存钱-------\n";
	cout << "请输入要存入的金额：";
	cin >> m;
	money += m;
	total_in += m;
	cout << "成功存入：" << m << "元！\n" << "当前余额：" << money << "元。\n";
}//存钱
void Card::goback() //返回键
{
	system("cls"); cout << "---------您已成功返回-------\n"; return;
}
void CreditCard::create_card()
{
	cout << "初次见面，办个卡吧，亲！\n";
	cout << "请输入透支额度(2000~10000)：\n\t";
	cin >> overdraft;
	system("cls");
	cout << "---信用卡办理成功！---\n";
	interest = 0.1;
	money = 0;
}
void CreditCard::withdraw()
{
	double m;
	system("cls");
	cout << "-------取钱-------\n";
	cout << "请输入要取出的金额：";
	cin >> m;
	if (-(money - m) > overdraft)
	{
		cout << "超出额度!取款失败！\n";
		cout << "您的余额：" << m << "元\n";
	}
	else
		money -= m;
	   total_out += m;
	cout << "成功取出" << m << "元\n";
	cout << "当前余额：" << money << "元\n";
} //信用卡取钱
void CreditCard::transfer()
{
	User B;
	string sure, file, phone;
	system("cls");
	cout << "-------转账-------\n";
	cout << "请输将转入的账户号码：";
	cin >> phone;
	file = "Data/" + phone + ".txt";

	if (isFileExists_ifstream1(file))
	{
		double m;
		cout << "----账户存在----\n";
		cout << "请输入转入金额：";
		B.name(phone);//传入文件地址，便于读写数据
		cin >> m;
		if (-(money - m) > overdraft)
		{
			cout << "余额：" << money << endl;
			cout << "超出额度!\n交易失败。\n";
			cout << "您的余额：" << money << "元\n";
		}
		else {
			cout << "----转账成功！祝您生活愉快！----\n" << endl;
			change(-m);
			B.read();
			B.ccard.change(m);
			B.save();
		}
	}
}//信用卡转账
//DepositCard
void DepositCard::create_card()
{
	system("cls");
	cout << "------储蓄卡------\n";
	cout << "储蓄卡自动办理成功！\n";
	rate = 0.1;//统一
	money = 0;
}
void DepositCard::depositoperate()
{
	int choice;
	double m;
	if (money == -1)
	{
		create_card();
	}
	while (1)
	{
		cout << "----------请选择您的需求--------\n";
		cout << "\t|\t存钱 ①\t\t|\t\n";
		cout << "\t|\t取钱 ②\t\t|\t\n";
		cout << "\t|\t转账 ③\t\t|\t\n";
		cout << "\t|\t返回 ④\t\t|\t\n";
		cout << "请输入指令：";
		cin >> choice;
		if (choice == 1)
		{
			deposit();
		}
		if (choice == 2)
		{
			withdraw();
		}
		if (choice == 3)
		{
			transfer();
		}
		if (choice == 4) { goback(); return; }
	}
}
void DepositCard::withdraw()  
{
	double m;
	system("cls");
	cout << "-------取钱-------\n";
	cout << "请输入取出金额：";
	cin >> m;
	if (money >= m)
	{
		money -= m;
		total_out += m;
		cout << "成功取款：" << m << "元！\n";
		cout << "您的余额：" << m << "元。\n";
	}
	else
	{
		cout << "执行失败，您的余额不足！\n";
		cout << "您的余额：" << m << "元。\n";
	}
}  // 储蓄卡存钱
void DepositCard::transfer()
{
	system("cls");
	cout << "-------转账-------\n";
	User B;
	string sure, file, phone;
	cout << "请输将转入的账户号码：";
	cin >> phone;
	file = "Data/" + phone + ".txt";

	if (isFileExists_ifstream1(file))
	{
		double m;
		cout << "----账户存在----\n";
		cout << "请输入转入金额：\t";
		B.name(phone);//传入文件地址，便于读写数据
		cin >> m;
		if (money - m > 0)
		{

			cout << "****超出额度!\n交易失败。****\n";
			cout << "您的余额：" << money << endl;
		}
		else {
			change(-m);
			B.read();
			B.dcard.change(m);
			B.save();
			cout << "----转账成功！祝您生活愉快！----\n";
		}
	}
	else
	{
		cout << "****该账户不存在！****\n"; return;
	}
}//储蓄卡转账
istream& operator>>(istream& input, DepositCard & a)
{
	input >> a.money >> a.rate;
	return input;
}
ostream& operator<<(ostream& output, DepositCard &a)
{
	output << a.money << '\t' << a.rate << endl;
	return output;
}
double Card::total_in = 0;
double Card::total_out = 0;