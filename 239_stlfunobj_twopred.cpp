//### 谓词  二元谓词
//谓词概念概念：**
//* 返回bool类型的仿函数称为**谓词**
//* 如果operator()接受一个参数，那么叫做一元谓词
//* 如果operator()接受两个参数，那么叫做二元谓词
//总结：参数只有两个的谓词，称为二元谓词

#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
//二元谓词
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	//默认从小到大
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;

	//使用函数对象改变算法策略，排序从大到小
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() 
{
	test01();
	system("pause");
	return 0;
}