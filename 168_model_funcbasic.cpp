//函数模板
//* C++另一种编程思想称为 == 泛型编程 == ，主要利用的技术就是模板
//* C++提供两种模板机制:**函数模板**和**类模板**
//#### 函数模板语法
//函数模板作用：
//建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，
//用一个**虚拟的类型**来代表。
//template<typename T>
//函数声明或定义
//template  -- - 声明创建模板
//typename  -- - 表面其后面的符号是一种数据类型，可以用class代替
//T-- - 通用的数据类型，名称可以替换，通常为大写字母
//总结：
//* 函数模板利用关键字 template
//* 使用函数模板有两种方式：自动类型推导、显示指定类型
//* 模板的目的是为了提高复用性，将类型参数化
#include<iostream>
using namespace std;
//函数模板

//两个整型交换函数
void swapInt(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
//交换两个浮点型函数
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}
//函数模板
template<typename T>//声明一个模板，告诉编译器不要报错，通用数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
void test01()
{
	int a = 10;
	int b = 20;

	swapInt(a, b);
	//利用模板实现交换
	//1、自动类型推导
	mySwap(a, b);

	//2、显示指定类型
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}