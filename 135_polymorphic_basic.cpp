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
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè������" << endl;
	}
};
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С��������" << endl;
	}
};
//��ַ��󶨣��ڱ���׶ξ�ȷ���˵�ַ
//�����è˵������Ҫ���
void doSpeak(Animal& animal)//Animal& animal=cat
{
	animal.speak();
}
void test01()
{
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
	Animal animal;
	doSpeak(animal);
}
int main()
{
	test01();
	system("pause");
}