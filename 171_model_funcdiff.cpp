//**普通函数与函数模板区别：**
//* 普通函数调用时可以发生自动类型转换（隐式类型转换）
//* 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
//* 如果利用显示指定类型的方式，可以发生隐式类型转换
//总结：建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T

#include<iostream>
using namespace std;
//普通函数
int myAdd01(int a, int b)
{
	return a + b;
}
//函数模板
template<typename T>
T myAdd02(T a,T b)
{
	return a + b;
}
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd01(a, b) << endl;
	//1.隐式类型转换 字符型->整型 a97 c99
	cout << myAdd01(a, c) << endl;
	
	//自动类型推导
	cout << myAdd02(a, b) << endl;
	//cout << myAdd02(a, c) << endl;函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换

	//显示指定类型//* 如果利用显示指定类型的方式，可以发生隐式类型转换
	cout << myAdd02<int>(a, c) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}