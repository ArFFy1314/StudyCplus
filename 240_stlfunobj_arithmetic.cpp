//### �ڽ��������� �����º���
//#�ڽ�������������
//**���*** STL�ڽ���һЩ��������
//**����:**
//* �����º���
//* ��ϵ�º���
//* �߼��º���
//**�÷���**
//* ��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
//* ʹ���ڽ�����������Ҫ����ͷ�ļ� `#include<functional>`
//#�����º���
//**����������**
//* ʵ����������
//* ����negate��һԪ���㣬�������Ƕ�Ԫ����
//**�º���ԭ�ͣ�**
//* template<class T> T plus<T>                //�ӷ��º���
//* template<class T> T minus<T>              //�����º���
//* template<class T> T multiplies<T>		//�˷��º���
//* template<class T> T divides<T>         //�����º���
//* template<class T> T modulus<T>        //ȡģ�º���
//* template<class T> T negate<T>           //ȡ���º���
//�ܽ᣺ʹ���ڽ���������ʱ����Ҫ����ͷ�ļ� #include <functional>
//
#include<iostream>
using namespace std;
#include<functional>
void test01()
{
	negate<int> n;
	cout << "negate:" << n(50) << endl;
	plus<int> p;
	cout << "plus" << p(10, 20) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}