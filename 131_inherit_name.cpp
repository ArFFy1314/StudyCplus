//继承同名成员处理方式
//访问子类同名成员，直接访问即可
//访问父类同名成员，需要直接加作用域
//有同名函数时，子类会屏蔽父类同名函数
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
//同名成员属性处理
void test01()
{
	Son s1;
	cout << "Son m_A=" << s1.m_A << endl;
	//如果通过子类对象 访问到父类中同名成员，需要加作用域
	cout << "Base m_A=" << s1.Base::m_A << endl;

}
//同名函数处理
void test02()
{
	Son s;
	s.fun();//直接调用子类
	s.Base::fun();//加作用域调用父类
	s.Base::fun(100);
}
int main()
{
	test01();
	test02();
	system("pause");
}