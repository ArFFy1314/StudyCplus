//���غ������������()��û�й̶�д�����ǳ����
//�������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳����º���
#include<iostream>
#include<string>
using namespace std;
//��ӡ�����
class MyPrint
{
public:
	//���غ������������
	void operator()(string test)
	{
		cout << test << endl;
	}
};
void test01()
{
	MyPrint myPrint;
	myPrint("hello world");
}
//�º����ǳ����
//�ӷ���
class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};
void test02()
{
	MyAdd myadd;
	int ret = myadd(10, 20);
	cout << "ret=" << ret << endl;

	//������������
	cout << MyAdd()(100, 100) << endl;
	//MyAdd()��������
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}