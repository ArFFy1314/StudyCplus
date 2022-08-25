//逻辑或
//> 逻辑==或==运算符总结： ==同假为假，其余为真==
#include<iostream>
using namespace std;
//逻辑运算符  --- 或
int main() 
{
	int a = 10;
	int b = 10;
	cout << (a || b) << endl;// 1
	a = 10;
	b = 0;
	cout << (a || b) << endl;// 1 
	a = 0;
	b = 0;
	cout << (a || b) << endl;// 0
	system("pause");
	return 0;
}