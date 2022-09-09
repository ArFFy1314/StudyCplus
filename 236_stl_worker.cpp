//### ����-Ա������
//#��������
//* ��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//* Ա����Ϣ��: ����  ������ɣ����ŷ�Ϊ���߻����������з�
//* �����10��Ա�����䲿�ź͹���
//* ͨ��multimap������Ϣ�Ĳ���  key(���ű��) value(Ա��)
//* �ֲ�����ʾԱ����Ϣ
//#ʵ�ֲ���
//1. ����10��Ա�����ŵ�vector��
//2. ����vector������ȡ��ÿ��Ա���������������
//3. ����󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue�����뵽multimap������
//4. �ֲ�����ʾԱ����Ϣ
//�ܽ᣺* �������Լ�ֵ����ʽ���ڣ����Կ�����map �� multimap
//

#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<string>
#include<map>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	Worker(string name, int salary)
	{
		this->m_Name = name;
		this->m_Salary = salary;
	}
	string m_Name;
	int m_Salary;
};
void createWorker(vector<Worker> &v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker("Ա��",rand()%10000+10000);//10000-19999
		worker.m_Name += nameSeed[i];
		//��Ա������������
		v.push_back(worker);
	}

}
//Ա������
void setGroup(vector<Worker>& vworker, multimap<int, Worker>& mworker)
{
	for (vector<Worker>::iterator it = vworker.begin(); it != vworker.end(); it++)
	{
		//����������ű��
		int deptId = rand() % 3;//0 1 2
		//��Ա�����뵽������
		mworker.insert(make_pair(deptId, *it));
	}
}
void showWorkerByGroup(multimap<int, Worker>& m)
{
	//0 A B 1 C D
	cout << "�߻�������Ϣ:" << endl;
	multimap<int,Worker>::iterator pos=m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end()&&index<count; pos++,index++)
	{
		cout << "name:" << pos->second.m_Name << " salary:" << pos->second.m_Salary << endl;
	}
	cout << "---------------------------------" << endl;
	cout << "����������Ϣ:" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index<count; pos++, index++)
	{
		cout << "name:" << pos->second.m_Name << " salary:" << pos->second.m_Salary << endl;
	}
	cout << "---------------------------------" << endl;
	cout << "�з�������Ϣ:" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index<count; pos++, index++)
	{
		cout << "name:" << pos->second.m_Name << " salary:" << pos->second.m_Salary << endl;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	//1.����Ա��
	vector<Worker> vWorker;
	createWorker(vWorker);
	//2.����
	multimap<int, Worker> mWorker;
	setGroup(vWorker,mWorker);
	//3.������ʾԱ��
	showWorkerByGroup(mWorker);
	////����
	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	//{
	//	cout << "������" << it->m_Name << " ����:" << it->m_Salary << endl;
	//}
	system("pause");
	return(0);
}