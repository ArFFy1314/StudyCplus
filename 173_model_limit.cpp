//模板的局限性:模板的通用性不是万能的
//template<class T>
//	void f(T a, T b)
//	{
//		a = b;
//	}
//在上述代码中提供的赋值操作，如果传入的a和b是一个数组，就无法实现了
//template<class T>
//void f(T a, T b)
//{
//	if (a > b) { ... }
//}
//在上述代码中，如果T的数据类型传入的是像Person自定义数据类型，也无法正常运行
//因此C++为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板
//总结：
//1.利用具体化的模板，可以解决自定义类型的通用化
//2.学习模板并不是为了写模板，而是在STL能够运用系统提供的模板
//
//
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//姓名
	string m_Name;
	int m_Age;
};
//对比两个数据是否相等函数
template<typename T>
bool myCompare(T& a, T& b)
{
	if (a == b)
		return true;
	else
		return false;
}

//利用具体化Person的版本实现代码，具体化优先调用
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Name == p2.m_Name&&p1.m_Age==p2.m_Age)
		return true;
	else
		return false;
}
void test01()
{
	int a = 10;
	int b = 20;

	bool ret = myCompare(a, b);
	if (ret)
		cout << "a==b" << endl;
	else
		cout << "a!=b" << endl;
}
void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}