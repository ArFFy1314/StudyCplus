//���õ�ע������
//* ���ñ����ʼ��
//* �����ڳ�ʼ���󣬲����Ըı�
#include<iostream>
using namespace std;
int main() {

	int a = 10;
	int b = 20;
	//int &c; //�������ñ����ʼ��
	int &c = a; //һ����ʼ���󣬾Ͳ����Ը���
	c = b; //���Ǹ�ֵ���������Ǹ�������

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");

	return 0;
}