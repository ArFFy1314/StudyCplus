//#### list ��ת������
//**����������** �������е�Ԫ�ط�ת���Լ��������е����ݽ�������
//**����ԭ�ͣ�**
//* reverse();    //��ת����
//* sort();         //��������
//�ܽ᣺
//* ��ת-- - reverse
//* ����-- - sort ����Ա������
//
//
#include<iostream>
using namespace std;
#include<list>
#include<algorithm>
void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int val1, int val2)
{
	//���� ��һ����>�ڶ�����
	return val1 > val2;
}

//��ת������
void test01()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList(L);

	//��ת������Ԫ��
	L.reverse();
	printList(L);

	//����
	L.sort(); //Ĭ�ϵ�������� ��С����
	printList(L);

	//���в�֧��������ʵ��������������������ñ�׼�㷨
	/*sort(L.begin(), L.end());
	printList(L);*/

	L.sort(myCompare); //ָ�����򣬴Ӵ�С
	printList(L);
}

int main() 
{
	test01();
	system("pause");
	return 0;
}