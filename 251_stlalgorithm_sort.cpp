//### ���������㷨
//**ѧϰĿ�꣺**���ճ��õ������㷨
//**�㷨��飺**
//- sort             //��������Ԫ�ؽ�������
//- random_shuffle   //ϴ��   ָ����Χ�ڵ�Ԫ�������������
//- merge            // ����Ԫ�غϲ������洢����һ������
//- reverse       // ��תָ����Χ��Ԫ��
//# sort
//**����������**��������Ԫ�ؽ�������
//**����ԭ�ͣ�**
//- sort(iterator beg, iterator end, _Pred);  
//// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
////  beg    ��ʼ������
////  end    ����������
//// _Pred  ν��
//**�ܽ᣺**sort���ڿ�������õ��㷨֮һ������������
#include<iostream>
using namespace std;
#include <algorithm>
#include<functional>
#include <vector>

void myPrint(int val)
{
	cout << val << " ";
}

void test01() {
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	//sortĬ�ϴ�С��������
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	//�Ӵ�С����
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main() 
{
	test01();
	system("pause");
	return 0;
}