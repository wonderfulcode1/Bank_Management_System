#include "Card.h"
#ifndef _User_h
#define _user_h
class User
{
private:
	string phone, password;
public:
	CreditCard ccard;  //�û�ӵ�����ÿ�
	DepositCard dcard;  //�û�ӵ�д��
	string Register();//ע��
	bool Login();//��¼
	void save();//����
	void read();//��ȡ
	void print();//�˻���Ϣ
	void print1();//�������
	void changepassword();//�޸�����
	bool operate();////�û�����ҳ��
	void name(string i);//��¼�绰��Ϣ
	string rename() { return phone; }//���ص绰
	void get();//�͹���Աͬ������
};
#endif