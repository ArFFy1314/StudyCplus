//##��ģ���г�Ա��������ʱ��
//
//��ģ���г�Ա��������ͨ���г�Ա��������ʱ����������ģ�
//* ��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
//* ��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���
//�ܽ᣺��ģ���еĳ�Ա����������һ��ʼ�ʹ����ģ��ڵ���ʱ��ȥ����
//
#include<iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};
template<class T>
class MyClass
{
public:
	T obj;
	//��ģ���еĳ�Ա����,�������õ�ʱ��Ŵ���
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};
void test01()
{
	MyClass<Person1> m;
	m.func1();

	m.func2();
}
int main()
{

	system("pause");
	return 0;
}