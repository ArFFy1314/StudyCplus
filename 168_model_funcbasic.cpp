//����ģ��
//* C++��һ�ֱ��˼���Ϊ == ���ͱ�� == ����Ҫ���õļ�������ģ��
//* C++�ṩ����ģ�����:**����ģ��**��**��ģ��**
//#### ����ģ���﷨
//����ģ�����ã�
//����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ������ƶ���
//��һ��**���������**������
//template<typename T>
//������������
//template  -- - ��������ģ��
//typename  -- - ���������ķ�����һ���������ͣ�������class����
//T-- - ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ
//�ܽ᣺
//* ����ģ�����ùؼ��� template
//* ʹ�ú���ģ�������ַ�ʽ���Զ������Ƶ�����ʾָ������
//* ģ���Ŀ����Ϊ����߸����ԣ������Ͳ�����
#include<iostream>
using namespace std;
//����ģ��

//�������ͽ�������
void swapInt(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
//�������������ͺ���
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}
//����ģ��
template<typename T>//����һ��ģ�壬���߱�������Ҫ����ͨ����������
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
void test01()
{
	int a = 10;
	int b = 20;

	swapInt(a, b);
	//����ģ��ʵ�ֽ���
	//1���Զ������Ƶ�
	mySwap(a, b);

	//2����ʾָ������
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}