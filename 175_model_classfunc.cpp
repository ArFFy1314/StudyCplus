//��ģ���뺯��ģ������
//��Ҫ�����㣺
//1. ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
//2. ��ģ����ģ������б��п�����Ĭ�ϲ���
//�ܽ᣺
//* ��ģ��ʹ��ֻ������ʾָ�����ͷ�ʽ
//* ��ģ���е�ģ������б������Ĭ�ϲ���
//
#include<iostream>
#include<string>
using namespace std;
template<class NameType,class AgeType=int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "name:" << this->m_Name << "  age:" << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;

};
void test01()
{
	//Person p("sun", 9);�����������Զ������Ƶ�
	Person<string, int> p("sun", 9);
	p.showPerson();
}
void test02()
{
	Person<string> p("zhu", 1);//class AgeType=int  
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}