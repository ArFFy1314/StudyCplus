//#### ��ģ�尸��
//�������� : ʵ��һ��ͨ�õ������࣬Ҫ�����£�
//	* ���Զ��������������Լ��Զ����������͵����ݽ��д洢
//	* �������е����ݴ洢������
//	* ���캯���п��Դ������������
//	* �ṩ��Ӧ�Ŀ������캯���Լ�operator = ��ֹǳ��������
//	* �ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
//	* ����ͨ���±�ķ�ʽ���������е�Ԫ��
//	* ���Ի�ȡ�����е�ǰԪ�ظ��������������
//�ܽ᣺	�ܹ�������ѧ֪ʶ��ʵ��ͨ�õ�����

#include<iostream>
#include<string>
#include"182_model_classarray_184.hpp"
using namespace std;
void printIntArray(MyArray<int>&arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}
void test01()
{
	MyArray<int> arr1(5);
	//MyArray<int> arr2(arr1);
	//MyArray<int> arr3(100);
	//arr3 = arr1;
	for (int i = 0; i < 5; i++)
	{
		//����β�巨�������в�������
		arr1.Push_Back(i);
	}
	cout << "arr1 cout" << endl;
	printIntArray(arr1);
	cout << "arr1 cap:" << arr1.getCapacity() << endl;
	cout << "arr1 size:" << arr1.getSize() << endl;
	MyArray<int> arr2(arr1);
	cout << "arr2 cout" << endl;
	printIntArray(arr2);
	//βɾ
	arr2.Pop_Back();
	cout << "arr1 pop_cap:" << arr2.getCapacity() << endl;
	cout << "arr1 pop_size:" << arr2.getSize() << endl;


}
//�����Զ�����������
class Person
{
public:
	Person() {};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void printPersonArray(MyArray<Person>&arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "������" << arr[i].m_Name << " ���䣺 " << arr[i].m_Age << endl;
	}
}
void test02()
{
	MyArray<Person> arr(10);
	Person p1("sun", 999);
	Person p2("zhu", 770);
	Person p3("sha", 9);
	Person p4("tang", 669);
	Person p5("hei", 87);
	Person p6("xoo", 0);
	//�����ݲ��뵽������
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	arr.Push_Back(p6);

	printPersonArray(arr);

	cout << "pArray�Ĵ�С��" << arr.getSize() << endl;
	cout << "pArray��������" << arr.getCapacity() << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}