//**���ã�** ����ѭ��������ִ��ѭ�����
//**�﷨��** `do{ ѭ����� } while (ѭ������); `
//**ע�⣺**��while���������� == do...while����ִ��һ��ѭ����� == �����ж�ѭ������
//�ܽ᣺��whileѭ���������ڣ�do...while��ִ��һ��ѭ����䣬���ж�ѭ������
//**����������**ˮ�ɻ�����ָһ�� 3 λ��������ÿ��λ�ϵ����ֵ� 3����֮�͵���������
//
//���磺1 ^ 3 + 5 ^ 3 + 3 ^ 3 = 153
//
//������do...while��䣬�������3λ���е�ˮ�ɻ���
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int number = 0;
	do
	{
		int a = 0;
		int b = 0;
		int c = 0;

		a = number % 10;//��ȡ��λ��
		b = number / 10 % 10;//��ȡʮλ��
		c = number / 100;//��ȡ��λ��
		double d = pow(a, 3) + pow(b, 3) + pow(c, 3);
		if (d == number)
		{
			cout << number << endl;
		}
		number++;
	} while (number < 1000);
	system("pause");
	return 0;
}
