//ָ�� ��ռ�ռ�
//����ָ��������32λ����ϵͳ����4���ֽ�
//Ŀǰ���л�����64λ����ϵͳ����8���ֽ�
#include<iostream>
using namespace std;
int main() 
{
	int a = 10;
	int * p;
	p = &a; //ָ��ָ������a�ĵ�ַ
	cout << *p << endl; //* ������	//10
	cout << sizeof(p) << endl;		//8
	cout << sizeof(char *) << endl;	//8
	cout << sizeof(float *) << endl;//8
	cout << sizeof(double *) << endl;//8
	system("pause");
	return 0;
}