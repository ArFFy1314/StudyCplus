//### �����㷨��������ʶ:vector���������������
//�˽�STL���������㷨������������֮���������ô������STL������
//STL����õ�����ΪVector����������Ϊ���飬�������ǽ�ѧϰ�������������в������ݡ��������������
//##vector���������������
//������ vector
//�㷨�� for_each
//��������vector<int>::iterator

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
void MyPrint(int val)
{
	cout << val << endl;
}
void test01()
{
	//����һ��vector����������
	vector<int> v;
	//�������в�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	////ͨ�����������������е�����
	//vector<int>::iterator itBegin = v.begin();//��ʼ��������ָ�������е�һ��Ԫ��
	//vector<int>::iterator itEnd = v.end();//������������ָ�����������һ��Ԫ�ص���һ��λ��
	////��һ�ֱ�����ʽ
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//�ڶ��ֱ���
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//�����ֱ�����ʽ��
	//ʹ��STL�ṩ��׼�����㷨  ͷ�ļ� algorithm
	for_each(v.begin(), v.end(), MyPrint);
}

int main()
{
	test01();
	system("pause");
	return 0;
}