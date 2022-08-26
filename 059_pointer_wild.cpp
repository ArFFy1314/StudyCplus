//野指针
//指针变量指向非法的内存空间
//空指针和野指针都不是我们申请的内存空间，不要访问
#include<iostream>
using namespace std;
int main() 
{
	//指针变量p指向内存地址编号为0x1100的空间
	int * p = (int *)0x1100;//创建一个虚拟快递，序列号为另外一个快递的序列号
	//访问野指针报错 
	cout << *p << endl;
	system("pause");
	return 0;
}