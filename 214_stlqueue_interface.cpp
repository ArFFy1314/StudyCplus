//#### queue ���ýӿ�
//����������ջ�������õĶ���ӿ�
//���캯����
//- queue<T> que;                                  //queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ
//- queue(const queue &que);             //�������캯��
//��ֵ������
//- queue& operator=(const queue &que);            //���صȺŲ�����
//���ݴ�ȡ��
//- push(elem);                              //����β���Ԫ��
//- pop();                                       //�Ӷ�ͷ�Ƴ���һ��Ԫ��
//- back();                                   //�������һ��Ԫ��
//- front();                                   //���ص�һ��Ԫ��
//��С������
//- empty();             //�ж϶�ջ�Ƿ�Ϊ��
//- size();               //����ջ�Ĵ�С
//�ܽ᣺
//- ���-- - push
//- ����-- - pop
//- ���ض�ͷԪ��-- - front
//- ���ض�βԪ��-- - back
//- �ж϶��Ƿ�Ϊ��-- - empty
//- ���ض��д�С-- - size
//
#include<iostream>
#include<queue>
#include<string>
using namespace std;
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void test01()
{
	//�������� �ص�:�����Ƚ��ȳ����ݽṹ
	queue<Person> q;
	//׼������
	Person p1("tang", 9);
	Person p2("sun", 4);
	Person p3("zhu", 3);
	Person p4("sha", 2);
	
	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	//�ж�ֻҪ���в�Ϊ�գ��鿴��ͷ���鿴��β������
	//���в��ṩ������������֧���������	
	while (!q.empty()) 
	{
		//�����ͷԪ��
		cout << "��ͷԪ��-- ������ " << q.front().m_Name
			<< " ���䣺 " << q.front().m_Age << endl;

		cout << "��βԪ��-- ������ " << q.back().m_Name
			<< " ���䣺 " << q.back().m_Age << endl;

		cout << endl;
		//������ͷԪ��
		q.pop();
	}
	cout << "���д�С:" << q.size() << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}