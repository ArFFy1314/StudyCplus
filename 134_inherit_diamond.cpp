//���μ̳�|��ʯ�̳�
//������̳�virtual������μ̳��˷ѵ�����
//vbptr
// virtual base pointer
#include<iostream>
using namespace std;
//������
class Animal
{
public:
	int m_Age;
};
//����
class Sheep :virtual public Animal
{

};
//����
class Tuo :virtual public Animal
{

};
//������
class SheepTuo :public Sheep, public Tuo
{

};
void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 1;
	cout << "Sheep Age=" << st.Sheep::m_Age << endl;
	cout << "Tuo Age=" << st.Tuo::m_Age << endl;

	//���������һ�ݾͿ��ԣ��˷���Դ

}
int main()
{
	test01();
	system("pause");
}