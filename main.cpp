//先在main里写吧，然后在分文件
#include "User.h"//这一个就够？合着头文件用来套娃？
#include"controller.h"
#include<fstream>
#include<conio.h>//_getch();
using namespace std;
int main()
{
	system("color F4");  //设置页面背景为亮白色，设置页面字体为红色，以优化用户体验。
	int choice;
	controller A;
	A.Read();

	while (1)
	{
		cout << "**********************************\n";
		cout << "**********欢迎来到银行************\n";
		cout << "**********************************\n";
		cout << "----------请选择您的需求：--------\n";
		cout << "\t|\t登录 ①\t\t|\t\n";
		cout << "\t|\t注册 ②\t\t|\t\n";
		cout << "\t|    管理者模式 ③\t|\t\n";
		cout << "\t|\t退出 ④\t\t|\t\n";
		cout << "请输入指令：";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			User a;
			if (a.Login()) {
				a.read();
				a.print();
				if (a.operate())//是否注销账户
				{
					string p = a.rename();

					//p= "Data/" + p + ".txt";
					vector<string>::iterator it;
					it = find(A.name.begin(), A.name.end(), p);
					if (it != A.name.end())A.name.erase(it);
					else cout << "!\n";
					A.Save();
				}
				else
					a.save();
			}
		}
		if (choice == 2)
		{
			system("cls");
			string m;
			User a;
			m = a.Register();
			if (m != "No")
				A.name.push_back(m);//把用户加入
			A.all++;
			A.Save();
		}
		if (choice == 3)
		{
			system("cls");
			string password;
			cout << "-------管理员模式-------\n";
			cout << "请输入管理员密码(默认888)：";//
			char w;
			while (1)
			{
				w = _getch();
				if (w == '\r')
					break;
				password += w;
				putchar('*');
			}cout << endl;
			if (A.pass == password)
			{
				system("cls");
				cout << "-----成功进入管理员模式。-----\n";
				A.operate();
				//Print();
			}
			else
			{
				cout << "*****密码错误！请重试。*****\n";
			}
		}
		if (choice == 4) {
			system("cls"); cout << "------您已成功退出！---------"; break;
		}
	}
}