//多继承语法
//C++允许一个类继承多个类
//易引发父类中同名
#include<iostream>
using namespace std;
class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
	int m_A;
};
class Base2
{
public:
	Base2()
	{
		m_A = 200;
	}
	int m_A;
};
//子类 需要继承Base1和Base2
//语法 class子类: 继承方式 父亲1，继承方式 父亲2...
class Son :public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};
void test01()
{
	Son s;
	cout << "Sizeof(Son)=" << sizeof(s) << endl;
	//当父类中出现同名成员，需要加作用域
	cout << "m_A=" << s.Base1:: m_A << endl;
}
int main()
{
	test01();
	system("pause");
}