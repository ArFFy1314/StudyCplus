//##��ģ������Ԫ
//ѧϰĿ�꣺
//* ������ģ�������Ԫ���������ں�����ʵ��
//ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����
//ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
//�ܽ᣺����ȫ�ֺ���������ʵ�֣��÷��򵥣����ұ���������ֱ��ʶ��
//
#include<iostream>
#include<string>
using namespace std;

//�ñ�������ǰ֪��
//2��ȫ�ֺ��������Ԫ  ����ʵ�� - ��������ģ���������·���������ģ�嶨�壬������Ԫ
template<class T1, class T2> class Person;

//��������˺���ģ�壬���Խ�ʵ��д�����棬������Ҫ��ʵ����д�����ǰ���ñ�������ǰ����
template<class T1, class T2> void printPerson2(Person<T1, T2>  p); 



template<class T1,class T2>
class Person
{
	//ȫ�ֺ��� ����ʵ��
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "name:" << p.m_Name << "  age:" << p.m_Age << endl;
	}
	//ȫ�ֺ�������ʵ��,<>����ģ�������
	//�ӿ�ģ������б�
	//���ȫ��������ʵ�� �ñ�������ǰ֪��
	friend void printPerson2<>(Person<T1, T2> p);
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};
template<class T1,class T2>
void printPerson2(Person<T1, T2> p)
{
	cout << "����name:" << p.m_Name << "  age:" << p.m_Age << endl;
}
//1.ȫ�ֺ���������ʵ��
void test01()
{
	Person<string, int>p("Tom", 20);
	printPerson(p);//ȫ�ֺ���
	Person<string, int>p2("Jerry", 20);
	printPerson2(p);
}
int main()
{
	test01();
	system("pause");
	return 0;
}