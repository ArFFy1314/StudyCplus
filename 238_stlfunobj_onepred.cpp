//### ν��  һԪν��
//ν�ʸ�����**
//* ����bool���͵ķº�����Ϊ**ν��**
//* ���operator()����һ����������ô����һԪν��
//* ���operator()����������������ô������Ԫν��
//�ܽ᣺����ֻ��һ����ν�ʣ���ΪһԪν��
//
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

//1.һԪν��
struct GreaterFive {
	bool operator()(int val) {
		return val > 5;
	}
};

void test01() 
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//���������� ��û�д���5������
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "û�ҵ�!" << endl;
	}
	else {
		cout << "�ҵ�:" << *it << endl;
	}
}

int main() 
{
	test01();
	system("pause");
	return 0;
}
