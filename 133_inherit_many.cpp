//��̳��﷨
//C++����һ����̳ж����
//������������ͬ��
#include<iostream>
using namespace std;
class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
	int m_A;
};
class Base2
{
public:
	Base2()
	{
		m_A = 200;
	}
	int m_A;
};
//���� ��Ҫ�̳�Base1��Base2
//�﷨ class����: �̳з�ʽ ����1���̳з�ʽ ����2...
class Son :public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};
void test01()
{
	Son s;
	cout << "Sizeof(Son)=" << sizeof(s) << endl;
	//�������г���ͬ����Ա����Ҫ��������
	cout << "m_A=" << s.Base1:: m_A << endl;
}
int main()
{
	test01();
	system("pause");
}