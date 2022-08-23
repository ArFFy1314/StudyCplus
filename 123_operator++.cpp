//递增运算符重载 ++
//前置递增先递增，后置递增先运行
#include<iostream>
using namespace std;

//自定义整形
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载前置++运算符
	MyInteger& operator++()//返回引用是为了对一个数据进行运算
	{
		m_Num++;
		return *this;
	}
	//重载后置++运算符
	//int代表占位参数，用于区分前置后置
	MyInteger operator++(int)//返回局部，不能引用，会崩
	{
		//先 记录结果
		MyInteger temp = *this;
		//后 递增
		m_Num++;
		//将结果返回
		return temp;
	}
private:
	int m_Num;
};
//重载一下左移运算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}
void test01()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
}