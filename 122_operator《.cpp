//�������������
//��������Զ�����������,�����Ԫ
#include<iostream>
using namespace std;
class Person
{
	friend ostream& operator<<(ostream &cout, Person& p);
public:
	//1.���ó�Ա�������� ���������
	//�������ó�Ա��������<<���������Ϊ�޷�ʵ��cout�����
	//void operator<<(cout) //p.operator<<(cout) �򻯰汾p<<cout
	//{

	//}
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
private:
	int m_A;
	int m_B;
};
//ֻ������ȫ�ֺ����������������
ostream& operator<<(ostream &cout,Person& p)//����operator<<(cout,p) cout<<p
{
	cout << "m_A=" << p.m_A << " m_B=" << p.m_B;
	return cout;
}
void test01()
{
	Person p(1,2);
	cout << p;//��ʽ���˼��
	cout << p << endl;
}
int main()
{
	test01();
	system("pause");
}
