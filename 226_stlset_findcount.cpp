//#### set���Һ�ͳ��
//**����������**��set�������в��������Լ�ͳ������
//**����ԭ�ͣ�**
//* find(key);                   //����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
//* count(key);                 //ͳ��key��Ԫ�ظ���
//�ܽ᣺
//* ����-- - find    �����ص��ǵ�������
//* ͳ��-- - count  ������set�����Ϊ0����1��
//
//
#include<iostream>
using namespace std;
#include <set>

//���Һ�ͳ��
void test01()
{
	set<int> s1;
	//����
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	//����
	set<int>::iterator pos = s1.find(30);

	if (pos != s1.end())
	{
		cout << "�ҵ���Ԫ�� �� " << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	//ͳ��
	int num = s1.count(30);
	cout << "num = " << num << endl;
}

int main() 
{
	test01();
	system("pause");
	return 0;
}