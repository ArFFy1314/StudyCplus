//左移运算符重载
//可以输出自定义数据类型,配合友元
#include<iostream>
using namespace std;
class Person
{
	friend ostream& operator<<(ostream &cout, Person& p);
public:
	//1.利用成员函数重载 左移运算符
	//不会利用成员函数重载<<运算符，因为无法实现cout在左侧
	//void operator<<(cout) //p.operator<<(cout) 简化版本p<<cout
	//{

	//}
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
private:
	int m_A;
	int m_B;
};
//只能利用全局函数重载左移运算符
ostream& operator<<(ostream &cout,Person& p)//本质operator<<(cout,p) cout<<p
{
	cout << "m_A=" << p.m_A << " m_B=" << p.m_B;
	return cout;
}
void test01()
{
	Person p(1,2);
	cout << p;//链式编程思想
	cout << p << endl;
}
int main()
{
	test01();
	system("pause");
}
