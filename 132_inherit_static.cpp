//继承 同名静态成员处理
//静态成员属性特点：1编译阶段分配内存
//2所有对象共享同一份数据，类内声明，类外初始化
#include<iostream>
using namespace std;
class Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "base func" << endl;
	}
};
int Base::m_A = 100;
class Son :public Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Son func" << endl;
	}
};
int Son::m_A = 200;
//同名静态成员属性
void test01()
{
	//1.通过对象来访问
	Son s;
	cout << "Son m_A=" << s.m_A << endl;
	cout << "Base m_A=" << s.Base::m_A << endl;
	//2.通过类名来访问
	cout << "Son !m_A=" << Son::m_A << endl;
	cout << "Base !m_A=" << Son::Base::m_A << endl;
	//第一个::代表通过类名方式来访问 第二个代表访问父类作用域
}
//同名静态成员函数
void test02()
{
	Son s;
	s.func();
	s.Base::func();

	Son::Base::func();
}
int main()
{
	//test01();
	test02();
	system("pause");
}