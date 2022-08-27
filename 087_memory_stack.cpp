//**堆区：**
//​		由程序员分配释放, 若程序员不释放, 程序结束时由操作系统回收
//​		在C++中主要利用new在堆区开辟内存
//**总结：**
//堆区数据由程序员管理开辟和释放
//堆区数据利用new关键字进行开辟内存
#include<iostream>
using namespace std;
int* func()
{
	int* a = new int(10);
	return a;
}

int main() {

	int *p = func();

	cout << *p << endl;
	cout << *p << endl;

	system("pause");

	return 0;
}