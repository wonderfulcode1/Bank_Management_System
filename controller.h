#include<vector>
using namespace std;
#ifndef _Controller_h
#define _Controller_h
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
#endif
