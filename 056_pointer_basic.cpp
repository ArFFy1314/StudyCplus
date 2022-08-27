//指针的定义与使用
//指针的作用:可以通过指针间接访问内存
//* 内存编号是从0开始记录的，一般用十六进制数字表示
//* 可以利用指针变量保存地址
//指针变量定义语法：数据类型 * 变量名；

//int* a;int *a;区别：
//编译器编译时候不处理空格，使用上没有区别
//C语言写者更倾向于： int *p, 更强调语法，说明*p指向一个int类型,表示p是一个指针，指向类型为int
//C++语言写者：int* p, 更强调类型：p是一个指向int的指针类型,表示定义一个类型p为int型指针
//int* a, b; 等价于 int *a；int b；而不等价于 int *a; int *b;


//指针变量和普通变量的区别
//* 普通变量存放的是数据, 指针变量存放的是地址
//* 指针变量可以通过" * "操作符，操作指针变量指向的内存空间，这个过程称为解引用
//
//> 总结1： 我们可以通过 & 符号 获取变量的地址
//> 总结2：利用指针可以记录地址
//> 总结3：对指针变量解引用，可以操作指针指向的内存

//int相当于创建一个快递，快递的名字就是变量名，而价值就是变量,同时本身具有序列码
//指针就是序列码，&则是取序列码，*则是控制快递

#include<iostream>
using namespace std;
int main() {
	//1、指针的定义
	int a = 10; //定义整型变量a
	//指针定义语法： 数据类型 * 变量名 ;
	int* p;
	//指针变量赋值
	p = &a; //指针指向变量a的地址
	cout << &a << endl; //打印数据a的地址
	cout << p << endl;  //打印指针变量p
	//2、指针的使用
	//通过*操作指针变量指向的内存
	cout << "*p = " << *p << endl;
	system("pause");
	return 0;
}