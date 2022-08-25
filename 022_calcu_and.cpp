//逻辑与
#include<iostream>
using namespace std;
//逻辑运算符  --- 与
//总结：逻辑==与==运算符总结： ==同真为真，其余为假==
int main() {
	int a = 10;
	int b = 10;
	cout << (a && b) << endl;// 1
	a = 10;
	b = 0;
	cout << (a && b) << endl;// 0 
	a = 0;
	b = 0;
	cout << (a && b) << endl;// 0
	system("pause");
	return 0;
}
