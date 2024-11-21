#include "User.h"
#include <iostream>
#include<fstream>
#include<vector>
#include <string>
#include<conio.h>
#include<algorithm>

using namespace std;
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
void controller::Read()
{
	string single_name;
	fstream f;
	f.open("Data/number.txt", ios::in);
	getline(f, pass);
	f >> interest >> rate >> all;
	for (int i = 0; i < all; i++)
	{
		f >> single_name;
		name.push_back(single_name);//
	}
	f.close();
}
void controller::Print()
{
	cout << "----查看账户名单----\n";
	cout << endl << "账户电话号码名单如下：\n";
	vector<string>::iterator it;//去重
	it = unique(name.begin(), name.end());//
	name.erase(it, name.end());//
	for (int i = 0; i < name.size(); i++)
		cout << name[i] << endl;
}
void controller::Save()
{
	fstream f;
	f.open("Data/number.txt", ios::out);
	f << pass << endl << interest << endl << rate << endl << all <<endl;
	for (int i = 0; i < name.size(); i++)
	{
		f << name[i] << endl;
	}
	f.close();
}
void controller::operate()
{
	int choice;
	while (1) {
		cout << "\t|修改利率利息 ①|\n\t|查看账户名单 ②|\n\t|查看用户信息 ③|\n\t|   修改密码 ④ |\n\t|银行收支情况 ⑤|\n\t|   退出 0      |\n请输入指令：";
		cin >> choice;
		if (choice == 1)
		{
			int u;
			system("cls");
			cout << "----修改利率利息----\n";
			cout << "当下利率利息：\n";
			cout << "利息：" << interest << endl;
			cout << "利率：" << rate << endl;
			cout << "是否更改？\n请输入(1/0):\n";
			cin >> u;
			if (u)
			{
				cout << "请输入调整后利息（信用卡）：\n";
				cin >> interest;
				cout << "请输入调整后利率（储蓄卡）：\n";
				cin >> rate;
				Save();
			}
			system("cls");

		}
		if (choice == 2)
			system("cls");
			Print();
		if (choice == 3)
		{
			string o;
			User a;
			system("cls");
			cout << "----查看用户信息----\n";
			cout << "请输入所需查看账户号码：\n";
			cin >> o;
			a.name(o);
			a.read();
			a.get();
			cout << "账户信息如下：\n";
			a.print1();
			a.save();
			cout << endl;
		}
		if (choice == 4)
		{
			cout << "----修改利率利息----\n";
			cout << "请输入新密码：\n";

			//cin >> password;
			string pass1, sure;
			char w;
			while (1)
			{
				w = _getch();
				if (w == '\r')
					break;
				pass1 += w;
				putchar('*');
			}cout << endl;

			cout << "请确认密码： \n";
			//cin >> sure;
			while (1)
			{
				w = _getch();
				if (w == '\r')
					break;
				sure += w;
				putchar('*');
			}cout << endl;
			if (pass1 == sure)
			{
				cout << "修改密码成功！\n";
				pass = pass1;
				cout << pass;
			}
			else
			{
				cout << "前后密码不匹配，请重试。\n";
			}
			//Save();
		}
		if (choice == 5)
		{
			system("cls");
			cout << "-----银行收支情况-----\n";
			show_inandout();
		}
		if (choice == 0)
		{
			system("cls");
			Save();
			return;
		}

	}

}
void controller::show_inandout()
{
	Card::show_inout();
}
