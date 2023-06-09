//纯虚函数和抽象类
#include<iostream>
using namespace std;
class Base
{
public:
	//只要有一个纯虚函数，认为是抽象类
	//抽象类特点：
	//1.无法实例化对象
	//2.抽象类子类 必须重写父类纯虚函数，否则也是抽象类
	virtual void func() = 0;//纯虚函数
};
class Son :public Base
{
public:
	virtual void func()
	{
		cout << "func" << endl;
	}
};
void test01()
{
	//Base b;
	Son s;
	Base* base = new Son;
	base->func();
}
int main()
{
	test01();
	system("pause");
}