//��̬�Ļ������� ������̬
//��̬��̬��������
//1.�̳й�ϵ2.����Ҫ��д�����麯��
//��д ��������ֵ���� ������ �����б� ��ȫ��ͬ
//��̬��̬ʹ�ã������ָ��������� ָ���������
#include<iostream>
using namespace std;

class Animal
{
public:
	//�麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

void test01()
{
	cout << "sizeof(animal)=" << sizeof(Animal) << endl;
}
int main()
{
	test01();
	system("pause");
}