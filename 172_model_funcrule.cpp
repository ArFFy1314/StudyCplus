//##普通函数与函数模板的调用规则
//调用规则如下：
//1. 如果函数模板和普通函数都可以实现，优先调用普通函数
//2. 可以通过空模板参数列表来强制调用函数模板
//3. 函数模板也可以发生重载
//4. 如果函数模板可以产生更好的匹配, 优先调用函数模板
//总结：既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性
#include<iostream>
using namespace std;
void myPrint(int a, int b)
{
	cout << "调用普通函数" << endl;
}
//void myPrint(int a, int b);
template<typename T>
void myPrint(T a, T b)
{
	cout << "调用函数模板" << endl;
}
template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "调用函数重载模板" << endl;
}
void test01()
{
	int a = 10;
	int b = 20;

	myPrint(a, b);//优先调用普通函数,哪怕改成声明，会报错
	myPrint<>(a, b);//通过空模板参数列表，强制调用函数模板
	myPrint(a, b,100);//函数重载
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);//模板产生了更好的效果，普通函数需要转换，函数模板需要推导
}
int main()
{
	test01();
	system("pause");
	return 0;
}
