//## string字符串拼接
//**功能描述：**
//* 实现在字符串末尾拼接字符串
//**函数原型：**
//* string& operator+=(const char* str);                    //重载+=操作符
//* string& operator+=(const char c);                          //重载+=操作符
//* string& operator+=(const string& str);                 //重载+=操作符
//* string& append(const char *s);                                //把字符串s连接到当前字符串结尾
//* string& append(const char *s, int n);                  //把字符串s的前n个字符连接到当前字符串结尾
//* string& append(const string &s);                            //同operator+=(const string& str)
//* string& append(const string &s, int pos, int n); / / 字符串s中从pos开始的n个字符连接到字符串结尾
//总结：字符串拼接的重载版本很多，初学阶段记住几种即可
//
#include<iostream>
#include<string>
using namespace std;
void test01()
{
	string str1 = "我";
	str1 += "爱玩游戏";
	cout << "str1=" << str1 << endl;

	str1 += ';';
	cout << "str2" << str1 << endl;

	string str2 = "LOL DNF";
	str1 += str2;
	cout << "str1=" << str1 << endl;

	string str3 = "i";
	str3.append("love");
	cout << "str3=" << str3 << endl;

	str3.append("gameabc", 4);
	cout << "str3=" << str3 << endl;

	str3.append(str2);
	cout << "str3="<<str3 << endl;

	str3.append(str2, 0, 3);
	cout << "str3=" << str3 << endl;

	str3.append(str2, 4, 3);
	cout << "str3=" << str3 << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}