//重载函数调用运算符()。没有固定写法，非常灵活
//由于重载后使用的方式非常像函数的调用，因此称作仿函数
#include<iostream>
#include<string>
using namespace std;
//打印输出类
class MyPrint
{
public:
	//重载函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}
};
void test01()
{
	MyPrint myPrint;
	myPrint("hello world");
}
//仿函数非常灵活
//加法类
class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};
void test02()
{
	MyAdd myadd;
	int ret = myadd(10, 20);
	cout << "ret=" << ret << endl;

	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;
	//MyAdd()匿名对象
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}