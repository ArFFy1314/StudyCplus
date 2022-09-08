//#### queue 常用接口
//功能描述：栈容器常用的对外接口
//构造函数：
//- queue<T> que;                                  //queue采用模板类实现，queue对象的默认构造形式
//- queue(const queue &que);             //拷贝构造函数
//赋值操作：
//- queue& operator=(const queue &que);            //重载等号操作符
//数据存取：
//- push(elem);                              //往队尾添加元素
//- pop();                                       //从队头移除第一个元素
//- back();                                   //返回最后一个元素
//- front();                                   //返回第一个元素
//大小操作：
//- empty();             //判断堆栈是否为空
//- size();               //返回栈的大小
//总结：
//- 入队-- - push
//- 出队-- - pop
//- 返回队头元素-- - front
//- 返回队尾元素-- - back
//- 判断队是否为空-- - empty
//- 返回队列大小-- - size
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
	//创建队列 特点:符合先进先出数据结构
	queue<Person> q;
	//准备数据
	Person p1("tang", 9);
	Person p2("sun", 4);
	Person p3("zhu", 3);
	Person p4("sha", 2);
	
	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	//判断只要队列不为空，查看队头，查看队尾，出队
	//队列不提供迭代器，更不支持随机访问	
	while (!q.empty()) 
	{
		//输出队头元素
		cout << "队头元素-- 姓名： " << q.front().m_Name
			<< " 年龄： " << q.front().m_Age << endl;

		cout << "队尾元素-- 姓名： " << q.back().m_Name
			<< " 年龄： " << q.back().m_Age << endl;

		cout << endl;
		//弹出队头元素
		q.pop();
	}
	cout << "队列大小:" << q.size() << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}