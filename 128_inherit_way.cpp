//�̳� ��ʽ
#include<iostream>
using namespace std;

class Base1
{
public: 
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
//�����̳�
class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;//�����й���Ȩ�޳�Ա������������Ȼ�ǹ���Ȩ��
		m_B = 10;//�����б���Ȩ�޳�Ա������������Ȼ�Ǳ���Ȩ��
		//m_C = 10;//������˽��Ȩ�޳�Ա��������ʲ���
	}
};
//�����̳�
class Son2 :protected Base1
{
public:
	void fun()
	{
		m_A = 100;//�����䱣��
		m_B = 100;//����
		//m_C = 100;˽��
	}
};
//˽�м̳�
class Son3 :private Base1
{
public:
	void func()
	{
		m_A = 100;//������˽��
		m_B = 100;//������˽��
		//m_C = 100;//˽�в�����
	}
};
class GrandSon3 :public Son3
{
public:
	void func()
	{
		//����son3��˽�У����಻�ɷ���
		/*m_A = 10;
		m_B = 10;
		m_C = 10;*/
	}
};
void test01()
{
	Son1 s1;
	s1.m_A = 100;//������Ա��������������Է���
	//s1.m_B = 100;//������Ա�����ڿ��Է��ʣ����ⲻ���Է���
	Son2 s2;
	//s2.m_A = 100;//�����䱣��
	//s2.m_B = 100;//����
	//s2.m_C = 100;//˽��
	Son3 s3;
	//s3.m_A = 10;���˽��

}
int main()
{

}