//实现通用 对数组进行排序的函数
//* 利用函数模板封装一个排序的函数，可以对**不同数据类型数组**进行排序
//* 排序规则从大到小，排序算法为**选择排序**
//* 分别利用**char数组**和**int数组**进行测试
//总结：模板可以提高代码复用，需要熟练掌握
#include<iostream>
using namespace std;
//交换函数模板
template<typename T> void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
//排序算法
template<typename T> void mySort(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//认定最大值的下标
		for (int j = i + 1; j < len; j++)
		{
			//认定的最大值比遍历的最大值小，说明J下标大
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			//交换max和i元素
			mySwap(arr[max], arr[i]);
		}
	}
}
//打印数组模板
template<typename T> void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void test01()
{
	//测试char数组
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);
}
void test02()
{
	//测试int
	int intArr[] = { 7,5,1,2,3,4 };
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArray(intArr, num);
}
int main()
{
	test01();
	system("pause");
	return 0;
}