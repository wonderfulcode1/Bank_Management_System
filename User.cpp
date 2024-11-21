#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>

bool isFileExists_ifstream(string& name) //用于检查文件是否存在（要放在使用它的函数前面）
{
	ifstream f(name.c_str());
	return f.good();//会自动关文件？
}
void User::print1()
{
	get();
	cout << "\t\t该账户信息如下\n";
	cout <<"账户密码：" << password << endl;
	if (ccard.getmoney() == -1)
		cout << "信用卡：\t未办理。\n" << endl;
	else
		cout << "\t\t余额\t透支额度  利息\n" << "信用卡：\t" << ccard;
	if (dcard.getmoney() == -1)
		cout << "储蓄卡：\t未办理。\n" << endl;
	else
		cout << "\t\t余额\t利率\n" << "储蓄卡：\t" << dcard;
}
void User::print()
{
	get();
	system("cls");
	cout << "--------账户信息--------\n";
	if (ccard.getmoney() == -1)
		cout << "信用卡：\t未办理。\n" << endl;
	else
		cout <<"\t\t余额\t透支额度  利息\n" << "信用卡：\t" << ccard;
	if (dcard.getmoney() == -1)
		cout << "储蓄卡：\t未办理。\n" << endl;
	else
		cout <<"\t\t余额\t利率\n" << "储蓄卡：\t" << dcard;
}
string User::Register()
{
	cout << "-------------注册-------------\n";
	string sure,file;
	cout << "请在此输入电话号码：";
	cin >> phone;
	file = "Data/" + phone + ".txt";
	if (isFileExists_ifstream(file))
	{
		system("cls");
		cout << "**********该账户已注册！**********\n\n";
		return "No";
	}
	//fstream y;
	//y.open(file, ios::app);
	while (1)
	{
		cout << "请设置密码：";

		//cin >> password;
		password.clear();
		char w;
		while (1)
		{
			w = _getch();
			if (w == '\r')
				break;
			password += w;
			putchar('*');
		}cout << endl;

		cout << "请确认密码： ";
		//cin >> sure;
		sure.clear();
		while (1)
		{
			w = _getch();
			if (w == '\r')
				break;
			sure += w;
			putchar('*');
		}cout << endl;

		if (sure == password)
		{
			fstream y;
			y.open(file, ios::app);
			system("cls");
			cout << "--------创建成功！---------\n";
			cout << "----即将回到主界面登录呢，亲！----\n";
			y << password << endl;
			y << -1 << '\t' << -1 << '\t' << -1 << endl;//信用卡
			y << -1 << '\t' << -1 << endl;//储蓄卡
			y.close();
			break;
		}
		else
		{
			cout << "****密码不一致，请重新输入。****\n";
		}
	}
	return phone;
}
bool User::Login()
{
	string number, pass;
	cout << "-------------登录-------------\n";
	cout << "-----------身份认证----------\n请在此输入账户电话号码：";
	cin >> number;
	phone = number;
	number = "Data/" + number + ".txt";
	if (isFileExists_ifstream(number))
	{
		fstream f;
		f.open(number, ios::in);
		getline(f, password);
		cout << "请在此输入密码：";
		char w;
		while (1)
		{
			w = _getch();
			if (w == '\r')
				break;
			pass += w;
			putchar('*');
		}cout << endl;

		if (pass == password)
		{
			system("cls");
			cout << "---------登陆成功！---------\n";
			f.close();
			return 1;
		}
		else
		{
			system("cls");
			cout << "********密码错误，请重新登录。*********\n\n";
			f.close();
			return 0;
		}
	}
	else
	{
		system("cls");
		cout << "******不存在该账户，请先注册。********\n\n";
		return 0;
	}
}
void User::changepassword()
{
	system("cls");
	cout << "------修改密码-------\n";
	cout << "请输入新密码：\n";
	string pass, sure;
	char w;
	while (1)
	{
		w = _getch();
		if (w == '\r')
			break;
		pass += w;
		putchar('*');
	}cout << endl;
	cout << "请确认密码： \n";
	while (1)
	{
		w = _getch();
		if (w == '\r')
			break;
		sure += w;
		putchar('*');
	}
	cout << endl;
	if (pass == sure)
	{
		cout << "修改密码成功！\n";
		password = pass;
	}
	else
	{
		cout << "前后密码不匹配，请重试。\n";
	}
} 
bool User::operate()  //用户操作页面
{
	int choice;
	double m;
	while (1) {
		cout << "----------请选择您的需求--------\n";
		cout << "\t|\t账户信息 ①\t|\t\n";
		cout << "\t|\t信用卡 ②\t|\t\n";
		cout << "\t|\t储蓄卡 ③\t|\t\n";
		cout << "\t|\t修改密码 ④\t|\t\n";
		cout << "\t|\t注销账户 ⑤\t|\t\n";
		cout << "\t|\t退出登录 ⑥\t|\t\n";
		cout << "请输入指令：";
		cin >> choice;
		if (choice == 1)print();
		if (choice == 2)
		{
			ccard.creditoperate();
		}
		if (choice == 3)
		{
			dcard.depositoperate();
		}
		if (choice == 5) 
		{
			system("cls");
			string a= "Data/" + phone + ".txt";
			const char* b = a.c_str();
			if (remove(b) == 0)
			{
				cout << "-----注销账户成功!-----" << endl;
				return 1;
			}
			else
			{
				cout << "*****注销失败*****" << endl;
			}

		}
		if (choice == 4)
		{
			changepassword();
		}
		if (choice == 6)
		{
			system("cls");
			cout << "----成功退出登录----\n"; return 0;
		}
		save();
	}
}
void User::get()//与管理员设置利率同步
{
	string o;
	fstream f;
	double i,r;
	f.open("Data/number.txt", ios::in);
	getline(f, o);
	f >> i >> r;
	ccard.cset(i);
	dcard.dset(r);
}
void User::save()
{
	string name = "Data/" + phone + ".txt", m;
	fstream f;
	f.open(name, ios::out);
	f << password << endl;
	f << ccard << dcard;
	f.close();
}
void User::name(string i)
{
	phone = i;
}
void User::read()
{
	string name = "Data/" + phone + ".txt", m;
	fstream f;
	f.open(name, ios::in);
	f >> password;
	f >> ccard;
	f >> dcard;
	f.close();
}