//����ģ��ע������
//* �Զ������Ƶ��������Ƶ���һ�µ���������T, �ſ���ʹ��
//* ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
#include<iostream>
using namespace std;
//����ģ���ṩͨ�õĽ�������
template<typename T>//typename class��������
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


// 1���Զ������Ƶ��������Ƶ���һ�µ���������T,�ſ���ʹ��
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	mySwap(a, b); // ��ȷ�������Ƶ���һ�µ�T
				  //mySwap(a, c); // �����Ƶ�����һ�µ�T����
}


// 2��ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<typename T>
void func()
{
	cout << "func ����" << endl;
}

void test02()
{
	//func(); //����ģ�岻�ܶ���ʹ�ã�����ȷ����T������
	func<int>(); //������ʾָ�����͵ķ�ʽ����Tһ�����ͣ��ſ���ʹ�ø�ģ��
}

int main() {

	test01();
	test02();

	system("pause");

	return 0;
}