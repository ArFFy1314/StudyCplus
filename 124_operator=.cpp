//赋值运算符重载

#include<iostream>
using namespace std;
class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}
	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	//重载 赋值运算符
	Person& operator=(Person &p)
	{
		//编译器提供浅拷贝
		//m.Age=p.Age;

		//应该先判断是否有属性再堆区，如果有先释放干净，然后再深拷贝
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);
		//返回对象本身
		return *this;
	}
	int *m_Age;
};
void test01()
{
	Person p1(10);
	Person p2(20);
	Person p3(30);
	p2 = p1;//赋值操作
	p3 = p2 = p1;//
	cout << "p1的年龄：" << *p1.m_Age << endl;
	cout << "p2的年龄：" << *p2.m_Age << endl;
}
int main()
{
	test01();
	//c=b=a;内置数据类型允许连等
	system("pause");
	return 0;
}
