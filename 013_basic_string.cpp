//用于表示一串字符
//
//**两种风格**

//沿用C语言风格(C++字符串) []""
//1. **C风格字符串**： char 变量名[] = "字符串值"
#include<iostream>
using namespace std;

//int main() {
//
//	char str1[] = "hello world";
//	cout << str1 << endl;
//
//	system("pause");
//
//	return 0;
//}

//> 注意：C风格的字符串要用双引号括起来

//2. **C++风格字符串**：  string  变量名 = "字符串值"
#include<string>
int main() {

	string str = "hello world";
	cout << str << endl;

	system("pause");

	return 0;
}
//> 注意：C++风格字符串，需要加入头文件 == #include\<string> ==