//#### string�Ӵ�
//**����������**
//* ���ַ����л�ȡ��Ҫ���Ӵ�
//**����ԭ�ͣ�**
//* string substr(int pos = 0, int n = npos) const;    //������pos��ʼ��n���ַ���ɵ��ַ���
//**�ܽ᣺**�����������Ӵ����ܣ�������ʵ�ʿ����л�ȡ��Ч����Ϣ
//
#include<iostream>
#include<string>
using namespace std;
void test01()
{
	string str = "hello";
	string substr = str.substr(1, 3);
	cout << "substr=" << substr << endl;

	//ʵ�ò���
	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}