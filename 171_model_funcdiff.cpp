//**��ͨ�����뺯��ģ������**
//* ��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
//* ����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
//* ���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
//�ܽ᣺����ʹ����ʾָ�����͵ķ�ʽ�����ú���ģ�壬��Ϊ�����Լ�ȷ��ͨ������T

#include<iostream>
using namespace std;
//��ͨ����
int myAdd01(int a, int b)
{
	return a + b;
}
//����ģ��
template<typename T>
T myAdd02(T a,T b)
{
	return a + b;
}
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd01(a, b) << endl;
	//1.��ʽ����ת�� �ַ���->���� a97 c99
	cout << myAdd01(a, c) << endl;
	
	//�Զ������Ƶ�
	cout << myAdd02(a, b) << endl;
	//cout << myAdd02(a, c) << endl;����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��

	//��ʾָ������//* ���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
	cout << myAdd02<int>(a, c) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}