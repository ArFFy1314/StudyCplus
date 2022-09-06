//##类模板与友元
//学习目标：
//* 掌握类模板配合友元函数的类内和类外实现
//全局函数类内实现 - 直接在类内声明友元即可
//全局函数类外实现 - 需要提前让编译器知道全局函数的存在
//总结：建议全局函数做类内实现，用法简单，而且编译器可以直接识别
//
#include<iostream>
#include<string>
using namespace std;

//让编译器提前知道
//2、全局函数配合友元  类外实现 - 先做函数模板声明，下方在做函数模板定义，在做友元
template<class T1, class T2> class Person;

//如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
template<class T1, class T2> void printPerson2(Person<T1, T2>  p); 



template<class T1,class T2>
class Person
{
	//全局函数 类内实现
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "name:" << p.m_Name << "  age:" << p.m_Age << endl;
	}
	//全局函数类外实现,<>函数模板的声明
	//加空模板参数列表
	//如果全局是类外实现 让编译器提前知道
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
	cout << "类外name:" << p.m_Name << "  age:" << p.m_Age << endl;
}
//1.全局函数在类内实现
void test01()
{
	Person<string, int>p("Tom", 20);
	printPerson(p);//全局函数
	Person<string, int>p2("Jerry", 20);
	printPerson2(p);
}
int main()
{
	test01();
	system("pause");
	return 0;
}