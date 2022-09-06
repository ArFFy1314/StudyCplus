//##类模板成员函数类外实现
//学习目标：能够掌握类模板中的成员函数类外实现
//总结：类模板中成员函数类外实现时，需要加上模板参数列表

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
//构造函数类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}
//成员函数类外实现
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