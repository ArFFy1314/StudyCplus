//#### vector���ݴ�ȡ
//**����������**��vector�е����ݵĴ�ȡ����
//**����ԭ�ͣ�**
//* at(int idx);      //��������idx��ָ������
//* operator[];       //��������idx��ָ������
//* front();          //���������е�һ������Ԫ��
//* back();           //�������������һ������Ԫ��
//�ܽ᣺
//* �����õ�������ȡvector������Ԫ�أ�[]��atҲ����
//* front����������һ��Ԫ��
//* back�����������һ��Ԫ��
//
#include<iostream>
#include<vector>
using namespace std;

void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//����[]������������Ԫ��
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	//����at��ʽ������
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
	//��ȡ��һ��Ԫ��
	cout << "start:" << v1.front() << endl;
	//��ȡ���һ��Ԫ��
	cout << "back:" << v1.back() << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}