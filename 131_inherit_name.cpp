//�̳�ͬ����Ա����ʽ
//��������ͬ����Ա��ֱ�ӷ��ʼ���
//���ʸ���ͬ����Ա����Ҫֱ�Ӽ�������
//��ͬ������ʱ����������θ���ͬ������
#include<iostream>
using namespace std;
class Base
{
public:
	Base()
	{
		m_A = 10;
	}
	void fun()
	{
		cout << "Base-fun" << endl;
	}
	void fun(int a)
	{
		cout << "Base-fun(a)" << endl;
	}
	int m_A;
};
class Son :public Base
{
public:
	Son()
	{
		m_A = 20;
	}
	void fun()
	{
		cout << "Son-fun" << endl;
	}
	int m_A;
};
//ͬ����Ա���Դ���
void test01()
{
	Son s1;
	cout << "Son m_A=" << s1.m_A << endl;
	//���ͨ��������� ���ʵ�������ͬ����Ա����Ҫ��������
	cout << "Base m_A=" << s1.Base::m_A << endl;

}
//ͬ����������
void test02()
{
	Son s;
	s.fun();//ֱ�ӵ�������
	s.Base::fun();//����������ø���
	s.Base::fun(100);
}
int main()
{
	test01();
	test02();
	system("pause");
}