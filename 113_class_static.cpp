//��̬��Ա
//��̬��Ա�����ڳ�Ա�����ͳ�Ա����ǰ���Ϲؼ���static����Ϊ��̬��Ա
//��̬��Ա��Ϊ��
//*  ��̬��Ա����
//*		���ж�����ͬһ������
//*		�ڱ���׶η����ڴ�
//*		���������������ʼ��
//*  ��̬��Ա����
//*		���ж�����ͬһ������
//*		��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����

#include<iostream>
using namespace std;
class Person
{

public:

	static int m_A; //��̬��Ա����

					//��̬��Ա�����ص㣺
					//1 �ڱ���׶η����ڴ�
					//2 ���������������ʼ��
					//3 ���ж�����ͬһ������

private:
	static int m_B; //��̬��Ա����Ҳ���з���Ȩ�޵�
};
int Person::m_A = 10;
int Person::m_B = 10;

void test01()
{
	//��̬��Ա�������ַ��ʷ�ʽ

	//1��ͨ������
	Person p1;
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl; //����ͬһ������
	cout << "p2.m_A = " << p2.m_A << endl;

	//2��ͨ������
	cout << "m_A = " << Person::m_A << endl;


	//cout << "m_B = " << Person::m_B << endl; //˽��Ȩ�޷��ʲ���
}

int main() {

	test01();

	system("pause");

	return 0;
}

//class Person
//{
//
//public:
//
//	//��̬��Ա�����ص㣺
//	//1 ������һ������
//	//2 ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
//
//	static void func()
//	{
//		cout << "func����" << endl;
//		m_A = 100;
//		//m_B = 100; //���󣬲����Է��ʷǾ�̬��Ա����
//	}
//
//	static int m_A; //��̬��Ա����
//	int m_B; // 
//private:
//
//	//��̬��Ա����Ҳ���з���Ȩ�޵�
//	static void func2()
//	{
//		cout << "func2����" << endl;
//	}
//};
//int Person::m_A = 10;
//
//
//void test01()
//{
//	//��̬��Ա�������ַ��ʷ�ʽ
//
//	//1��ͨ������
//	Person p1;
//	p1.func();
//
//	//2��ͨ������
//	Person::func();
//
//
//	//Person::func2(); //˽��Ȩ�޷��ʲ���
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}