//####  set(集合容器)基本概念
//**简介：** 所有元素都会在插入时自动被排序
//**本质：**
//* set / multiset属于**关联式容器**，底层结构是用**二叉树**实现。
//**set和multiset区别**：
//* set不允许容器中有重复的元素
//* multiset允许容器中有重复的元素
//
//
//##set构造和赋值
//功能描述：创建set容器以及赋值
//构造：
//* set<T> st;                         //默认构造函数：
//* set(const set &st);        //拷贝构造函数
//赋值：
//* set& operator=(const set &st);     //重载等号操作符
//总结：
//* set容器插入数据时用insert
//* set容器插入数据的数据会自动排序
#include<iostream>
using namespace std;
#include<set>
void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	set<int> s1;
	//插入数据 只有insert
	s1.insert(20);
	s1.insert(10);
	s1.insert(50);
	s1.insert(40);
	//插入时自动排序
	//不允许重复值
	printSet(s1);

	set<int> s2(s1);
	printSet(s2);

	set<int>s3;
	s3 = s2;
	printSet(s3);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
