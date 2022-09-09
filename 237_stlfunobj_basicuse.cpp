//## STL- 函数对象
//函数对象概念:
//* 重载**函数调用操作符**的类，其对象常称为**函数对象**
//* **函数对象**使用重载的()时，行为类似函数调用，也叫**仿函数**
//**本质：**函数对象(仿函数)是一个**类**，不是一个函数
//函数对象使用**特点：**
//* 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
//* 函数对象超出普通函数的概念，函数对象可以有自己的状态
//* 函数对象可以作为参数传递
//总结：仿函数写法非常灵活，可以作为参数进行传递。
//
#include<iostream>
#include<string>
using namespace std;
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}

};
//1.函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
void test01()
{
	MyAdd myAdd;
	myAdd(10, 10);

}
//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		this->count++;
		cout << test << endl;
	}
	int count;//内部自己状态
};
void test02()
{
	MyPrint myPrint;
	myPrint("helloworld");
	cout << "count:" << myPrint.count << endl;
}
//3.函数对象可以作为参数传递
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}
void test03()
{
	MyPrint myprint;
	doPrint(myprint, "hello c++");
}
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return(0);
}