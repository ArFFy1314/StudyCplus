//### 案例-员工分组
//#案例描述
//* 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
//* 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
//* 随机给10名员工分配部门和工资
//* 通过multimap进行信息的插入  key(部门编号) value(员工)
//* 分部门显示员工信息
//#实现步骤
//1. 创建10名员工，放到vector中
//2. 遍历vector容器，取出每个员工，进行随机分组
//3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
//4. 分部门显示员工信息
//总结：* 当数据以键值对形式存在，可以考虑用map 或 multimap
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
		Worker worker("员工",rand()%10000+10000);//10000-19999
		worker.m_Name += nameSeed[i];
		//将员工放入容器中
		v.push_back(worker);
	}

}
//员工分组
void setGroup(vector<Worker>& vworker, multimap<int, Worker>& mworker)
{
	for (vector<Worker>::iterator it = vworker.begin(); it != vworker.end(); it++)
	{
		//产生随机部门编号
		int deptId = rand() % 3;//0 1 2
		//将员工插入到分组中
		mworker.insert(make_pair(deptId, *it));
	}
}
void showWorkerByGroup(multimap<int, Worker>& m)
{
	//0 A B 1 C D
	cout << "策划部门信息:" << endl;
	multimap<int,Worker>::iterator pos=m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end()&&index<count; pos++,index++)
	{
		cout << "name:" << pos->second.m_Name << " salary:" << pos->second.m_Salary << endl;
	}
	cout << "---------------------------------" << endl;
	cout << "美术部门信息:" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index<count; pos++, index++)
	{
		cout << "name:" << pos->second.m_Name << " salary:" << pos->second.m_Salary << endl;
	}
	cout << "---------------------------------" << endl;
	cout << "研发部门信息:" << endl;
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
	//1.创建员工
	vector<Worker> vWorker;
	createWorker(vWorker);
	//2.分组
	multimap<int, Worker> mWorker;
	setGroup(vWorker,mWorker);
	//3.分组显示员工
	showWorkerByGroup(mWorker);
	////测试
	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	//{
	//	cout << "姓名：" << it->m_Name << " 工资:" << it->m_Salary << endl;
	//}
	system("pause");
	return(0);
}