//类模板与函数模板区别
//主要有两点：
//1. 类模板没有自动类型推导的使用方式
//2. 类模板在模板参数列表中可以有默认参数
//总结：
//* 类模板使用只能用显示指定类型方式
//* 类模板中的模板参数列表可以有默认参数
//
#include<iostream>
#include<string>
using namespace std;
template<class NameType,class AgeType=int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "name:" << this->m_Name << "  age:" << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;

};
void test01()
{
	//Person p("sun", 9);编译器不能自动类型推导
	Person<string, int> p("sun", 9);
	p.showPerson();
}
void test02()
{
	Person<string> p("zhu", 1);//class AgeType=int  
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}