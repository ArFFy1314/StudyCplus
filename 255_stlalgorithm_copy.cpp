//### ���ÿ������滻�㷨
//**ѧϰĿ�꣺**���ճ��õĿ������滻�㷨
//**�㷨��飺**
//- copy                      // ������ָ����Χ��Ԫ�ؿ�������һ������
//- replace                // ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
//- replace_if           // ������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
//- swap                     // ��������������Ԫ��
//##copy
//**����������**������ָ����Χ��Ԫ�ؿ�������һ������
//**����ԭ�ͣ�**
//- copy(iterator beg, iterator end, iterator dest);  
//// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//// beg  ��ʼ������
//// end  ����������
//// dest Ŀ����ʼ������
//**�ܽ᣺**����copy�㷨�ڿ���ʱ��Ŀ�������ǵ���ǰ���ٿռ�
#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}

int main() 
{
	test01();
	system("pause");
	return 0;
}