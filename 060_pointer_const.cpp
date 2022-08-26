//const修饰指针
//1. const修饰指针--const int * p1 = &a; - 常量指针|指向常量的指针变量
//2. const修饰常量--int * const p2 = &a; - 指针常量|指向变量的指针常量
//3. const即修饰指针，又修饰常量--const int * const p3 = &a;|指向常量的指针常量
//技巧：看const右侧紧跟着的是指针还是常量, 是指针就是常量指针，是常量就是指针常量

#include<iostream>
using namespace std;
int main() 
{
	int a = 10;
	int b = 10;

	//const修饰的是指针，指针指向可以改，指针指向的值不可以更改,int* p;创建虚拟快递p
	const int * p1 = &a;//重在创建虚拟快递p，并且指定价值，而对序列号不进行约束
	p1 = &b; //正确
	//*p1 = 100;  报错

	//const修饰的是常量，指针指向不可以改，指针指向的值可以更改
	int * const p2 = &a;//只定序列号
	//p2 = &b; //错误
	*p2 = 100; //正确

	//const既修饰指针又修饰常量
	const int * const p3 = &a;
	//p3 = &b; //错误
	//*p3 = 100; //错误
	system("pause");
	return 0;
}