//�̳��еĹ���������˳��
//�ȹ��츸�� �ٹ�������
//���������� ����������
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "���๹��" << endl;
	}
	~Base()
	{
		cout << "��������" << endl;
	}
};
class Son :public Base
{
public:
	Son()
	{
		cout << "���๹��" << endl;
	}
	~Son()
	{
		cout << "��������" << endl;
	}
};
void test01()
{
	Son s1;
}
int main()
{
	test01();
	system("pause");
}