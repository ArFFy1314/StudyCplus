//#### Vector存放自定义数据类型
//学习目标：vector中存放自定义数据类型，并打印输出
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void test01()
{
	vector<Person*> v;
	Person p1("tom", 10);
	Person p2("to", 10);
	Person p3("tm", 0);
	Person p4("om", 10);
	Person p5("m", 0);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it解引用之后就是<>里的数据类型
		Person * p = (*it);
		cout << "Name:" << p->m_Name << " Age:" << (*it)->m_Age << endl;
		cout << "Name:" << (*p).m_Name << " Age:" << (**it).m_Age << endl;
	}
}
void test02()
{
	vector<Person> v;

	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "Name:" << (*it).m_Name << " Age:" << (*it).m_Age << endl;
		cout << "Name:" << it->m_Name << " Age:" << it->m_Age << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}