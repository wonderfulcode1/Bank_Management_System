#include "User.h"
#include <iostream>
#include<fstream>
#include<vector>
#include <string>
#include<conio.h>
#include<algorithm>

using namespace std;
class controller   //����Ա��
{
	public:
		vector<string>name;  //�ַ������������ڴ����˻�����
		int all;//�û�����
		string pass;//����Ա����
		double interest, rate;//��Ϣ����
		void Read();
		void Print();
		void Save();
		void operate();
		void show_inandout();//��ʾ������֧���
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
	cout << "----�鿴�˻�����----\n";
	cout << endl << "�˻��绰�����������£�\n";
	vector<string>::iterator it;//ȥ��
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
		cout << "\t|�޸�������Ϣ ��|\n\t|�鿴�˻����� ��|\n\t|�鿴�û���Ϣ ��|\n\t|   �޸����� �� |\n\t|������֧��� ��|\n\t|   �˳� 0      |\n������ָ�";
		cin >> choice;
		if (choice == 1)
		{
			int u;
			system("cls");
			cout << "----�޸�������Ϣ----\n";
			cout << "����������Ϣ��\n";
			cout << "��Ϣ��" << interest << endl;
			cout << "���ʣ�" << rate << endl;
			cout << "�Ƿ���ģ�\n������(1/0):\n";
			cin >> u;
			if (u)
			{
				cout << "�������������Ϣ�����ÿ�����\n";
				cin >> interest;
				cout << "��������������ʣ��������\n";
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
			cout << "----�鿴�û���Ϣ----\n";
			cout << "����������鿴�˻����룺\n";
			cin >> o;
			a.name(o);
			a.read();
			a.get();
			cout << "�˻���Ϣ���£�\n";
			a.print1();
			a.save();
			cout << endl;
		}
		if (choice == 4)
		{
			cout << "----�޸�������Ϣ----\n";
			cout << "�����������룺\n";

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

			cout << "��ȷ�����룺 \n";
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
				cout << "�޸�����ɹ���\n";
				pass = pass1;
				cout << pass;
			}
			else
			{
				cout << "ǰ�����벻ƥ�䣬�����ԡ�\n";
			}
			//Save();
		}
		if (choice == 5)
		{
			system("cls");
			cout << "-----������֧���-----\n";
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
