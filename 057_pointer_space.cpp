//指针 所占空间
//所有指针类型在32位操作系统下是4个字节
//目前运行环境是64位操作系统，是8个字节
#include<iostream>
using namespace std;
int main() 
{
	int a = 10;
	int * p;
	p = &a; //指针指向数据a的地址
	cout << *p << endl; //* 解引用	//10
	cout << sizeof(p) << endl;		//8
	cout << sizeof(char *) << endl;	//8
	cout << sizeof(float *) << endl;//8
	cout << sizeof(double *) << endl;//8
	system("pause");
	return 0;
}