//#### replace_if
//**��������:**������������������Ԫ�أ��滻��ָ��Ԫ��
//**����ԭ�ͣ�**
//- replace_if(iterator beg, iterator end, _pred, newvalue);  
//// �������滻Ԫ�أ������������滻��ָ��Ԫ��
//// beg ��ʼ������
//// end ����������
//// _pred ν��
//// newvalue �滻����Ԫ��
//**�ܽ᣺**replace_if���������ң��������÷º������ɸѡ���������
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

class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}

};

void test01()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;

	//�������д��ڵ��ڵ�30 �滻�� 3000
	cout << "�滻��" << endl;
	replace_if(v.begin(), v.end(), ReplaceGreater30(), 3000);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main() 
{
	test01();
	system("pause");
	return 0;
}