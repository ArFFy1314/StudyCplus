//####  find_if
//**����������*** ����������Ԫ��
//**����ԭ�ͣ�**
//- find_if(iterator beg, iterator end, _Pred);  
//// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//// beg ��ʼ������
//// end ����������
//// _Pred ��������ν�ʣ�����bool���͵ķº�����
//�ܽ᣺find_if����������ʹ���Ҹ������ṩ�ķº������Ըı䲻ͬ�Ĳ���
#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <string>

//������������
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01() {

	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "û���ҵ�!" << endl;
	}
	else {
		cout << "�ҵ�����5������:" << *it << endl;
	}
}

//�Զ�����������
class Person {
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};

class Greater20
{
public:
	bool operator()(Person &p)
	{
		return p.m_Age > 20;
	}
};

void test02() {

	vector<Person> v;

	//��������
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "û���ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ�����:" << it->m_Name << " ����: " << it->m_Age << endl;
	}
}

int main() 
{
	//test01();
	test02();
	system("pause");
	return 0;
}