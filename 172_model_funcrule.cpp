//##��ͨ�����뺯��ģ��ĵ��ù���
//���ù������£�
//1. �������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
//2. ����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
//3. ����ģ��Ҳ���Է�������
//4. �������ģ����Բ������õ�ƥ��, ���ȵ��ú���ģ��
//�ܽ᣺��Ȼ�ṩ�˺���ģ�壬��þͲ�Ҫ�ṩ��ͨ�������������׳��ֶ�����
#include<iostream>
using namespace std;
void myPrint(int a, int b)
{
	cout << "������ͨ����" << endl;
}
//void myPrint(int a, int b);
template<typename T>
void myPrint(T a, T b)
{
	cout << "���ú���ģ��" << endl;
}
template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "���ú�������ģ��" << endl;
}
void test01()
{
	int a = 10;
	int b = 20;

	myPrint(a, b);//���ȵ�����ͨ����,���¸ĳ��������ᱨ��
	myPrint<>(a, b);//ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
	myPrint(a, b,100);//��������
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);//ģ������˸��õ�Ч������ͨ������Ҫת��������ģ����Ҫ�Ƶ�
}
int main()
{
	test01();
	system("pause");
	return 0;
}
