//���麯���ͳ�����
#include<iostream>
using namespace std;
class Base
{
public:
	//ֻҪ��һ�����麯������Ϊ�ǳ�����
	//�������ص㣺
	//1.�޷�ʵ��������
	//2.���������� ������д���ി�麯��������Ҳ�ǳ�����
	virtual void func() = 0;//���麯��
};
class Son :public Base
{
public:
	virtual void func()
	{
		cout << "func" << endl;
	}
};
void test01()
{
	//Base b;
	Son s;
	Base* base = new Son;
	base->func();
}
int main()
{
	test01();
	system("pause");
}