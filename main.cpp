//����main��д�ɣ�Ȼ���ڷ��ļ�
#include "User.h"//��һ���͹�������ͷ�ļ��������ޣ�
#include"controller.h"
#include<fstream>
#include<conio.h>//_getch();
using namespace std;
int main()
{
	system("color F4");  //����ҳ�汳��Ϊ����ɫ������ҳ������Ϊ��ɫ�����Ż��û����顣
	int choice;
	controller A;
	A.Read();

	while (1)
	{
		cout << "**********************************\n";
		cout << "**********��ӭ��������************\n";
		cout << "**********************************\n";
		cout << "----------��ѡ����������--------\n";
		cout << "\t|\t��¼ ��\t\t|\t\n";
		cout << "\t|\tע�� ��\t\t|\t\n";
		cout << "\t|    ������ģʽ ��\t|\t\n";
		cout << "\t|\t�˳� ��\t\t|\t\n";
		cout << "������ָ�";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			User a;
			if (a.Login()) {
				a.read();
				a.print();
				if (a.operate())//�Ƿ�ע���˻�
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
				A.name.push_back(m);//���û�����
			A.all++;
			A.Save();
		}
		if (choice == 3)
		{
			system("cls");
			string password;
			cout << "-------����Աģʽ-------\n";
			cout << "���������Ա����(Ĭ��888)��";//
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
				cout << "-----�ɹ��������Աģʽ��-----\n";
				A.operate();
				//Print();
			}
			else
			{
				cout << "*****������������ԡ�*****\n";
			}
		}
		if (choice == 4) {
			system("cls"); cout << "------���ѳɹ��˳���---------"; break;
		}
	}
}