//继承中的构造与析构顺序
//先构造父类 再构造子类
//先析构子类 再析构父类
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "父类构造" << endl;
	}
	~Base()
	{
		cout << "父类析构" << endl;
	}
};
class Son :public Base
{
public:
	Son()
	{
		cout << "子类构造" << endl;
	}
	~Son()
	{
		cout << "子类析构" << endl;
	}
};
void test01()
{
	Son s1;
}
int main()
{
	test01();
	system("pause");
}