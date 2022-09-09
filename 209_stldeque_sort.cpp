//#### deque ����
//**����������**�����㷨ʵ�ֶ�deque������������
//**�㷨��**
//* sort(iterator beg, iterator end)  //��beg��end������Ԫ�ؽ�������
//�ܽ᣺sort�㷨�ǳ�ʵ�ã�ʹ��ʱ����ͷ�ļ� algorithm����
//
#include<iostream>
#include<deque>
using namespace std;
#include <algorithm>

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{

	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	printDeque(d);
	//���� Ĭ��������� ��С���� ����
	//����֧��������ʵĵ�����������������������sort�㷨ֱ�Ӷ����������
	//vector����Ҳ�������� sort��������
	sort(d.begin(), d.end());
	printDeque(d);

}

int main() {
	test01();
	system("pause");
	return 0;
}