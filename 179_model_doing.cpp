//##��ģ���Ա��������ʵ��
//ѧϰĿ�꣺�ܹ�������ģ���еĳ�Ա��������ʵ��
//�ܽ᣺��ģ���г�Ա��������ʵ��ʱ����Ҫ����ģ������б�

#include<iostream>
#include<string>
using namespace std;
template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	//{
	//	this->m_Name = name;
	//	this->m_Age = age;
	//}
	void showPerson();
	//{
	//	cout << "name:" << this->m_Name << "  age:" << this->m_Age << endl;
	//}
	T1 m_Name;
	T2 m_Age;
};
//���캯������ʵ��
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}
//��Ա��������ʵ��
template<class T1, class T2>
void Person<T1,T2>::showPerson()
{
	cout << "name:" << this->m_Name << "  age:" << this->m_Age << endl;
}
void test01()
{
	Person<string, int> p("ton", 20);
	p.showPerson();
}
int main()
{
	test01();
	system("pause");
	return 0;
}