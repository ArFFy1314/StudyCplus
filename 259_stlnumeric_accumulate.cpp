//###  �������������㷨  accumulate
//**ѧϰĿ�꣺**���ճ��õ����������㷨
//**ע�⣺**���������㷨����С���㷨��ʹ��ʱ������ͷ�ļ�Ϊ `#include <numeric>`
//**�㷨��飺**
//- accumulate      // ��������Ԫ���ۼ��ܺ�
//- fill                // �����������Ԫ��
//#accumulate
//**����������**���������� ����Ԫ���ۼ��ܺ�
//**����ԭ�ͣ�**
//- accumulate(iterator beg, iterator end, value);  
//// ��������Ԫ���ۼ��ܺ�
//// beg ��ʼ������
//// end ����������
//// value ��ʼֵ
//**�ܽ᣺**accumulateʹ��ʱͷ�ļ�ע���� numeric������㷨��ʵ��
//
#include<iostream>
using namespace std;
#include <numeric>
#include <vector>
void test01()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}

	int total = accumulate(v.begin(), v.end(), 2);

	cout << "total = " << total << endl;
}

int main() 
{
	test01();
	system("pause");
	return 0;
}