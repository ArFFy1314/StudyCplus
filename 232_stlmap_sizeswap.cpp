//####  map大小和交换
//**功能描述：**统计map容器大小以及交换map容器
//函数原型：
//- size();           //返回容器中元素的数目
//- empty();         //判断容器是否为空
//- swap(st);       //交换两个集合容器
//总结：
//- 统计大小-- - size
//- 判断是否为空-- - empty
//- 交换容器-- - swap
//
//
#include<iostream>
using namespace std;
#include<map>

void printMap(map<int, int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}
void test01()
{
	map<int, int> m;//键值对
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	if (m.empty())
	{
		cout << "m empty" << endl;
	}
	else
	{
		cout << "m !empty" << endl;
		cout << "m size:" << m.size() << endl;
	}


}
//交换
void test02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));

	cout << "交换前" << endl;
	printMap(m);
	printMap(m2);

	cout << "交换后" << endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}