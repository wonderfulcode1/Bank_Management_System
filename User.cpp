#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>

bool isFileExists_ifstream(string& name) //���ڼ���ļ��Ƿ���ڣ�Ҫ����ʹ�����ĺ���ǰ�棩
{
	ifstream f(name.c_str());
	return f.good();//���Զ����ļ���
}
void User::print1()
{
	get();
	cout << "\t\t���˻���Ϣ����\n";
	cout <<"�˻����룺" << password << endl;
	if (ccard.getmoney() == -1)
		cout << "���ÿ���\tδ����\n" << endl;
	else
		cout << "\t\t���\t͸֧���  ��Ϣ\n" << "���ÿ���\t" << ccard;
	if (dcard.getmoney() == -1)
		cout << "�����\tδ����\n" << endl;
	else
		cout << "\t\t���\t����\n" << "�����\t" << dcard;
}
void User::print()
{
	get();
	system("cls");
	cout << "--------�˻���Ϣ--------\n";
	if (ccard.getmoney() == -1)
		cout << "���ÿ���\tδ����\n" << endl;
	else
		cout <<"\t\t���\t͸֧���  ��Ϣ\n" << "���ÿ���\t" << ccard;
	if (dcard.getmoney() == -1)
		cout << "�����\tδ����\n" << endl;
	else
		cout <<"\t\t���\t����\n" << "�����\t" << dcard;
}
string User::Register()
{
	cout << "-------------ע��-------------\n";
	string sure,file;
	cout << "���ڴ�����绰���룺";
	cin >> phone;
	file = "Data/" + phone + ".txt";
	if (isFileExists_ifstream(file))
	{
		system("cls");
		cout << "**********���˻���ע�ᣡ**********\n\n";
		return "No";
	}
	//fstream y;
	//y.open(file, ios::app);
	while (1)
	{
		cout << "���������룺";

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

		cout << "��ȷ�����룺 ";
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
			cout << "--------�����ɹ���---------\n";
			cout << "----�����ص��������¼�أ��ף�----\n";
			y << password << endl;
			y << -1 << '\t' << -1 << '\t' << -1 << endl;//���ÿ�
			y << -1 << '\t' << -1 << endl;//���
			y.close();
			break;
		}
		else
		{
			cout << "****���벻һ�£����������롣****\n";
		}
	}
	return phone;
}
bool User::Login()
{
	string number, pass;
	cout << "-------------��¼-------------\n";
	cout << "-----------�����֤----------\n���ڴ������˻��绰���룺";
	cin >> number;
	phone = number;
	number = "Data/" + number + ".txt";
	if (isFileExists_ifstream(number))
	{
		fstream f;
		f.open(number, ios::in);
		getline(f, password);
		cout << "���ڴ��������룺";
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
			cout << "---------��½�ɹ���---------\n";
			f.close();
			return 1;
		}
		else
		{
			system("cls");
			cout << "********������������µ�¼��*********\n\n";
			f.close();
			return 0;
		}
	}
	else
	{
		system("cls");
		cout << "******�����ڸ��˻�������ע�ᡣ********\n\n";
		return 0;
	}
}
void User::changepassword()
{
	system("cls");
	cout << "------�޸�����-------\n";
	cout << "�����������룺\n";
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
	cout << "��ȷ�����룺 \n";
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
		cout << "�޸�����ɹ���\n";
		password = pass;
	}
	else
	{
		cout << "ǰ�����벻ƥ�䣬�����ԡ�\n";
	}
} 
bool User::operate()  //�û�����ҳ��
{
	int choice;
	double m;
	while (1) {
		cout << "----------��ѡ����������--------\n";
		cout << "\t|\t�˻���Ϣ ��\t|\t\n";
		cout << "\t|\t���ÿ� ��\t|\t\n";
		cout << "\t|\t��� ��\t|\t\n";
		cout << "\t|\t�޸����� ��\t|\t\n";
		cout << "\t|\tע���˻� ��\t|\t\n";
		cout << "\t|\t�˳���¼ ��\t|\t\n";
		cout << "������ָ�";
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
				cout << "-----ע���˻��ɹ�!-----" << endl;
				return 1;
			}
			else
			{
				cout << "*****ע��ʧ��*****" << endl;
			}

		}
		if (choice == 4)
		{
			changepassword();
		}
		if (choice == 6)
		{
			system("cls");
			cout << "----�ɹ��˳���¼----\n"; return 0;
		}
		save();
	}
}
void User::get()//�����Ա��������ͬ��
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