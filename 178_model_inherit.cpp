//#### ��ģ����̳�
//����ģ�������̳�ʱ����Ҫע��һ�¼��㣺
//* ������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
//* �����ָ�����������޷�����������ڴ�
//* ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
//�ܽ᣺�����������ģ�壬������Ҫָ����������T����������
//
#include<iostream>
using namespace std;

template<class T>
class Base
{
public;
	T m;
};
//class Son :public Base //���󣬱���Ҫ֪���������������Ͳ��ܼ̳и�����
class Son:public Base<int>
{

};
void test01()
{
	Son s1;

}
//��������ָ������T���ͣ�����Ҳ��Ҫ���ģ��
template<class T1,class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1 type:" << typeid(T1).name() << endl;
		cout << "T2 type:" << typeid(T2).name() << endl;
	}
	T1 obj;
};
void test02()
{
	Son2<int, char>S2;//���ģ��ָ�����������������
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}