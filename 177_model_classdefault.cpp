//## ��ģ���������������
//* ��ģ��ʵ�������Ķ����������εķ�ʽ
//һ�������ִ��뷽ʽ��
//1. ָ�����������-- - ֱ����ʾ�������������
//2. ����ģ�廯-- - �������еĲ�����Ϊģ����д���
//3. ������ģ�廯-- - �������������ģ�廯���д���
//�ܽ᣺
//* ͨ����ģ�崴���Ķ��󣬿��������ַ�ʽ�����н��д���
//* ʹ�ñȽϹ㷺�ǵ�һ�֣�ָ�����������
//
#include<iostream>
#include<string>
using namespace std;
template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "name:" << this->m_Name << "  age:" << this->m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};
//1.ָ����������
void printPerson1(Person<string, int>&p)
{
	p.showPerson();
}
void test01()
{
	Person<string, int> p("sun", 0);
	printPerson1(p);
}
//2.����ģ�廯
template<class T1, class T2>
void printPerson2(Person<T1, T2>&p)
{
	p.showPerson();
	//�鿴ģ���Ƶ�����
	cout << "T1����:" << typeid(T1).name() << endl;
	cout << "T2����:" << typeid(T2).name() << endl;
}
void test02()
{
	Person<string, int> p("zhu", 90);
	printPerson2(p);
}
//3.������ģ�廯
template<class T>
void printPerson3(T&p)
{
	p.showPerson();
}
void test03()
{
	Person<string, int> p("tang", 30);
	printPerson3(p);
}
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}