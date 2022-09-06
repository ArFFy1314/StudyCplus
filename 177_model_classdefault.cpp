//## 类模板对象做函数参数
//* 类模板实例化出的对象，向函数传参的方式
//一共有三种传入方式：
//1. 指定传入的类型-- - 直接显示对象的数据类型
//2. 参数模板化-- - 将对象中的参数变为模板进行传递
//3. 整个类模板化-- - 将这个对象类型模板化进行传递
//总结：
//* 通过类模板创建的对象，可以有三种方式向函数中进行传参
//* 使用比较广泛是第一种：指定传入的类型
//
#include<iostream>
#include<string>
using namespace std;
template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name:" << this->m_Name << "  age:" << this->m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};
//1.指定传入类型
void printPerson1(Person<string, int>&p)
{
	p.showPerson();
}
void test01()
{
	Person<string, int> p("sun", 0);
	printPerson1(p);
}
//2.参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2>&p)
{
	p.showPerson();
	//查看模板推导类型
	cout << "T1类型:" << typeid(T1).name() << endl;
	cout << "T2类型:" << typeid(T2).name() << endl;
}
void test02()
{
	Person<string, int> p("zhu", 90);
	printPerson2(p);
}
//3.整个类模板化
template<class T>
void printPerson3(T&p)
{
	p.showPerson();
}
void test03()
{
	Person<string, int> p("tang", 30);
	printPerson3(p);
}
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}