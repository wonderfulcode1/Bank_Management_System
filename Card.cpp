#include<fstream>
#include "User.h"

using namespace std;
bool isFileExists_ifstream1(string& name) //���ڼ���ļ��Ƿ����
{
	ifstream f(name.c_str());
	return f.good();
}

//CreditCard
istream& operator>>(istream& input, CreditCard & a) //��������ȡ�����
{
	input >> a.money >> a.overdraft >> a.interest;
	return input;
}
ostream& operator<<(ostream& output, CreditCard &a)//���������������
{
	output << a.money << "\t" << a.overdraft << "\t" << a.interest << endl;
	return output;
}
void CreditCard::creditoperate()
{
	int choice;
	double m;
	system("cls");
	cout << "--------���ÿ�--------\n";
	if (overdraft == -1)
	{
		create_card();
	}
	while (1)
	{
		cout << "----------��ѡ����������--------\n";
		cout << "\t|\t��Ǯ ��\t\t|\t\n";
		cout << "\t|\tȡǮ ��\t\t|\t\n";
		cout << "\t|\tת�� ��\t\t|\t\n";
		cout << "\t|\t���� ��\t\t|\t\n";
		cout << "������ָ�";
		cin >> choice;
		if (choice == 1)//��Ǯ
		{
			deposit(); 
		}
		if (choice == 2)//ȡǮ
		{
			withdraw();  
		}
		if (choice == 3)//ת��
		{
			transfer();
		}

		if (choice == 4) { goback(); return; } //���ؼ�
	}

}
void Card::deposit() 
{
	double m;
	system("cls");
	cout << "-------��Ǯ-------\n";
	cout << "������Ҫ����Ľ�";
	cin >> m;
	money += m;
	total_in += m;
	cout << "�ɹ����룺" << m << "Ԫ��\n" << "��ǰ��" << money << "Ԫ��\n";
}//��Ǯ
void Card::goback() //���ؼ�
{
	system("cls"); cout << "---------���ѳɹ�����-------\n"; return;
}
void CreditCard::create_card()
{
	cout << "���μ��棬������ɣ��ף�\n";
	cout << "������͸֧���(2000~10000)��\n\t";
	cin >> overdraft;
	system("cls");
	cout << "---���ÿ�����ɹ���---\n";
	interest = 0.1;
	money = 0;
}
void CreditCard::withdraw()
{
	double m;
	system("cls");
	cout << "-------ȡǮ-------\n";
	cout << "������Ҫȡ���Ľ�";
	cin >> m;
	if (-(money - m) > overdraft)
	{
		cout << "�������!ȡ��ʧ�ܣ�\n";
		cout << "������" << m << "Ԫ\n";
	}
	else
		money -= m;
	   total_out += m;
	cout << "�ɹ�ȡ��" << m << "Ԫ\n";
	cout << "��ǰ��" << money << "Ԫ\n";
} //���ÿ�ȡǮ
void CreditCard::transfer()
{
	User B;
	string sure, file, phone;
	system("cls");
	cout << "-------ת��-------\n";
	cout << "���佫ת����˻����룺";
	cin >> phone;
	file = "Data/" + phone + ".txt";

	if (isFileExists_ifstream1(file))
	{
		double m;
		cout << "----�˻�����----\n";
		cout << "������ת���";
		B.name(phone);//�����ļ���ַ�����ڶ�д����
		cin >> m;
		if (-(money - m) > overdraft)
		{
			cout << "��" << money << endl;
			cout << "�������!\n����ʧ�ܡ�\n";
			cout << "������" << money << "Ԫ\n";
		}
		else {
			cout << "----ת�˳ɹ���ף��������죡----\n" << endl;
			change(-m);
			B.read();
			B.ccard.change(m);
			B.save();
		}
	}
}//���ÿ�ת��
//DepositCard
void DepositCard::create_card()
{
	system("cls");
	cout << "------���------\n";
	cout << "����Զ�����ɹ���\n";
	rate = 0.1;//ͳһ
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
		cout << "----------��ѡ����������--------\n";
		cout << "\t|\t��Ǯ ��\t\t|\t\n";
		cout << "\t|\tȡǮ ��\t\t|\t\n";
		cout << "\t|\tת�� ��\t\t|\t\n";
		cout << "\t|\t���� ��\t\t|\t\n";
		cout << "������ָ�";
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
	cout << "-------ȡǮ-------\n";
	cout << "������ȡ����";
	cin >> m;
	if (money >= m)
	{
		money -= m;
		total_out += m;
		cout << "�ɹ�ȡ�" << m << "Ԫ��\n";
		cout << "������" << m << "Ԫ��\n";
	}
	else
	{
		cout << "ִ��ʧ�ܣ��������㣡\n";
		cout << "������" << m << "Ԫ��\n";
	}
}  // �����Ǯ
void DepositCard::transfer()
{
	system("cls");
	cout << "-------ת��-------\n";
	User B;
	string sure, file, phone;
	cout << "���佫ת����˻����룺";
	cin >> phone;
	file = "Data/" + phone + ".txt";

	if (isFileExists_ifstream1(file))
	{
		double m;
		cout << "----�˻�����----\n";
		cout << "������ת���\t";
		B.name(phone);//�����ļ���ַ�����ڶ�д����
		cin >> m;
		if (money - m > 0)
		{

			cout << "****�������!\n����ʧ�ܡ�****\n";
			cout << "������" << money << endl;
		}
		else {
			change(-m);
			B.read();
			B.dcard.change(m);
			B.save();
			cout << "----ת�˳ɹ���ף��������죡----\n";
		}
	}
	else
	{
		cout << "****���˻������ڣ�****\n"; return;
	}
}//���ת��
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