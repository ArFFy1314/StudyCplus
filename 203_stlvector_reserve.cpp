//#### vectorԤ���ռ�
//**����������**����vector�ڶ�̬��չ����ʱ����չ����
//**����ԭ�ͣ�**
//* reserve(int len); // ����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
//�ܽ᣺����������ϴ󣬿���һ��ʼ����reserveԤ���ռ�
//
#include<iostream>
#include<vector>
using namespace std;
void test01()
{
	vector<int> v;
	int num = 0;//ͳ�ƿ��ٴ���
	int *p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
			cout << "vector capa:" << v.capacity() << endl;
		}
	}
	cout << "vector num:" << num << endl;

}
void test02()
{
	vector<int> v;
	//����reserveԤ���ռ�
	v.reserve(100000);
	int num = 0;//ͳ�ƿ��ٴ���
	int *p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
			cout << "vector capa:" << v.capacity() << endl;
		}
	}
	cout << "vector num:" << num << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}