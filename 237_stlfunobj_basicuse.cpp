//## STL- ��������
//�����������:
//* ����**�������ò�����**���࣬����󳣳�Ϊ**��������**
//* **��������**ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ��**�º���**
//**���ʣ�**��������(�º���)��һ��**��**������һ������
//��������ʹ��**�ص㣺**
//* ����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
//* �������󳬳���ͨ�����ĸ����������������Լ���״̬
//* �������������Ϊ��������
//�ܽ᣺�º���д���ǳ���������Ϊ�������д��ݡ�
//
#include<iostream>
#include<string>
using namespace std;
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}

};
//1.����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
void test01()
{
	MyAdd myAdd;
	myAdd(10, 10);

}
//2.�������󳬳���ͨ�����ĸ����������������Լ���״̬
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		this->count++;
		cout << test << endl;
	}
	int count;//�ڲ��Լ�״̬
};
void test02()
{
	MyPrint myPrint;
	myPrint("helloworld");
	cout << "count:" << myPrint.count << endl;
}
//3.�������������Ϊ��������
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}
void test03()
{
	MyPrint myprint;
	doPrint(myprint, "hello c++");
}
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return(0);
}