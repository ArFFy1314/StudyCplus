//ѡ��ṹ

//ִ���������������
//
//if����������ʽ
//
//* ���и�ʽif���
//
//* ���и�ʽif���
//
//* ��������if���
#include<iostream>
using namespace std;

//��ֻС�������
int main()
{
	//������ֻС������ر���
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	//����
	cout << "������С��A������" << endl;
	cin >> num1;
	cout << "������С��B������" << endl;
	cin >> num2;
	cout << "������С��C������" << endl;
	cin >> num3;

	//�ж�����
	if (num1 > num2)
		if (num1 > num3)
			cout << "A����:" << num1 << endl;
		else cout << "C����:" << num3 << endl;
	else
		if(num2 > num3)
			cout << "B����:" << num2 << endl;
		else cout << "C����:" << num3 << endl;
		system("pause");
	return 0;
}