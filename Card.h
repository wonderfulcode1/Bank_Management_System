#include <iostream>
using namespace std;
#ifndef _Card_h
#define _Card_h
//�������п��࣬�ɴ��������ÿ���ʹ���ࡣ
class Card
{
protected:
	double money;  //���п��Ľ��
	
public:
	static double total_in;  //��̬��������¼�������п���������
	static double total_out;  //��̬��������¼�������п�����֧��
	double getmoney() { return money; }  //�������п��Ľ��
	static void show_inout() //��̬��������ʾ�ۼƴ�ȡ������
	{ cout << "�����ۼƴ�" << total_in << "Ԫ\t�ۼ�ȡ�" << total_out << "Ԫ\n"; }
	void change(double i)  //��change�����ı���
	{
		money += i;
		return;
	}
	virtual void create_card() = 0;  //���麯�����ṩ�쿨����Ĺ����ӿ�
	virtual void deposit() ;   //���г�Ա������ʵ�ִ�Ǯ����
	virtual void withdraw()=0; //���麯����ʵ��ȡǮ���ܽ���Ĺ����ӿ�
	virtual void transfer() = 0;   //���麯����ʵ��ת�˹��ܵĹ����ӿ�
	void goback();  //���г�Ա������ʵ�ַ��ع���

};						

class CreditCard :public Card   //�������ÿ��࣬�̳����п���
{
private:
	double overdraft;//��͸֧���
	double interest;//��Ϣ
public:
	double getoverdraft() { return overdraft; }  //�������ÿ����
	double getinterest() { return interest; }//�������ÿ���Ϣ
	void create_card();//�������ÿ��İ쿨
	void creditoperate(); //���ÿ�����ҳ��
	 void withdraw() ;//ȡǮ
	 void transfer() ;//ת��
	void cset(double i)  //�������ÿ���Ϣ
	{
		interest = i;
	}
	friend istream& operator>>(istream& input, CreditCard& a);
	friend ostream& operator<<(ostream& output, CreditCard& a);
};
class DepositCard :public Card //����͸֧������
{
private:
	double rate;//����
public:
	double getrate() { return rate; }
	void create_card() ;
	void depositoperate();//�����������
	virtual void withdraw();
	virtual void transfer();
	void dset(double r)  //���ô������
	{
		rate = r;
	}
	friend istream& operator>>(istream& input, DepositCard& a);
	friend ostream& operator<<(ostream& output, DepositCard& a);
};
#endif