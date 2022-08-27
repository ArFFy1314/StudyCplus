//选择结构

//执行满足条件的语句
//
//if语句的三种形式
//
//* 单行格式if语句
//
//* 多行格式if语句
//
//* 多条件的if语句
#include<iostream>
using namespace std;

//三只小猪称体重
int main()
{
	//创建三只小猪的体重变量
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	//输入
	cout << "请输入小猪A的体重" << endl;
	cin >> num1;
	cout << "请输入小猪B的体重" << endl;
	cin >> num2;
	cout << "请输入小猪C的体重" << endl;
	cin >> num3;

	//判断最重
	if (num1 > num2)
		if (num1 > num3)
			cout << "A最重:" << num1 << endl;
		else cout << "C最重:" << num3 << endl;
	else
		if(num2 > num3)
			cout << "B最重:" << num2 << endl;
		else cout << "C最重:" << num3 << endl;
		system("pause");
	return 0;
}