//�������ʹ�������
#include<iostream>
#include<string>
using namespace std;
class Animal
{
public:
	Animal()
	{
		cout << "Animal ����" << endl;
	}
	//���麯��
	virtual void speak() = 0;
	//�������������Խ�� ����ָ���ͷ�������󲻸ɾ�������
	/*virtual ~Animal()
	{
		cout << "Animal ������" << endl;
	}*/
	//�������� ����ʵ�� ������
	virtual ~Animal() = 0;
};
Animal::~Animal()
{
	cout << "Animal ��������" << endl;
}
class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat ����" << endl;
		m_Name = new string(name);
	}
	virtual void speak()
	{
		cout << *m_Name<<"������" << endl;
	}
	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "Cat ����" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
	string* m_Name;
};
void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//ͨ������ָ��ȥ�ͷţ��ᵼ�����������������ɾ�������ڴ�й©
	//��ô���������������һ������������
	//���������������������ͨ������ָ���ͷ��������
	delete animal;
}
int main()
{
	test01();
	system("pause");
}