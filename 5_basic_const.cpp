//1. **\#define** �곣���� `#define ������ ����ֵ`
//* == ͨ�����ļ��Ϸ����� == ����ʾһ������
//
//
//2. **const**���εı��� `const �������� ������ = ����ֵ`
//* == ͨ���ڱ�������ǰ�ӹؼ���const == �����θñ���Ϊ�����������޸�

#include<iostream>
using namespace std;
//1���곣��
#define day 7

int main() {

	cout << "һ�����ܹ��� " << day << " ��" << endl;
	//day = 8;  //�����곣���������޸�

	//2��const���α���
	const int month = 12;
	cout << "һ�����ܹ��� " << month << " ���·�" << endl;
	//month = 24; //���������ǲ������޸ĵ�


	system("pause");

	return 0;
}