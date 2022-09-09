//### 谓词  一元谓词
//谓词概念概念：**
//* 返回bool类型的仿函数称为**谓词**
//* 如果operator()接受一个参数，那么叫做一元谓词
//* 如果operator()接受两个参数，那么叫做二元谓词
//总结：参数只有一个的谓词，称为一元谓词
//
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

//1.一元谓词
struct GreaterFive {
	bool operator()(int val) {
		return val > 5;
	}
};

void test01() 
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找容器中 有没有大于5的数字
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "没找到!" << endl;
	}
	else {
		cout << "找到:" << *it << endl;
	}
}

int main() 
{
	test01();
	system("pause");
	return 0;
}
