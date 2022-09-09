//## list���캯��
//**����������** ����list����
//**����ԭ�ͣ�**
//* list<T> lst;                                //list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
//* list(beg, end);                            //���캯����[beg, end)�����е�Ԫ�ؿ�����������
//* list(n, elem);                              //���캯����n��elem������������
//* list(const list &lst);             //�������캯����
//�ܽ᣺list���췽ʽͬ��������STL�����������������ռ���
//
#include<iostream>
using namespace std;
#include<list>
void printList(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	//����list����
	list<int>L1;
	//��������
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	//��������
	printList(L1);

	//���䷽ʽ����
	list<int> L2(L1.begin(), L1.end());
	printList(L2);
	//��������
	list<int> L3(L2);
	printList(L3);
	//elem
	list<int> L4(10, 1000);
	printList(L4);
}
int main()
{
	test01();
	system("pause");
	return 0;
}