//一维数组名称的**用途**：
//
//1. 可以统计整个数组在内存中的长度
//2. 可以获取数组在内存中的首地址
//> 注意：数组名是常量，不可以赋值
//> 总结1：直接打印数组名，可以查看数组所占内存的首地址
//> 总结2：对数组名进行sizeof，可以获取整个数组占内存空间的大小
#include<iostream>
using namespace std;
int main() {

	//数组名用途
	//1、可以获取整个数组占用内存空间大小
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
	cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
	cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;

	//2、可以通过数组名获取到数组首地址
	cout << "数组首地址为： " << (int)arr << endl;
	cout << "数组中第一个元素地址为： " << (int)&arr[0] << endl;
	cout << "数组中第二个元素地址为： " << (int)&arr[1] << endl;

	//arr = 100; 错误，数组名是常量，因此不可以赋值
	system("pause");
	return 0;
}
//在一个数组中记录了五只小猪的体重，如：int arr[5] = { 300,350,200,400,250 };
//找出并打印最重的小猪体重。

//#include<iostream>
//using namespace std;
//
//int main() {
//	//1.创建5只小猪体重的数组
//	int arr[5] = { 300,350,200,400,250 };
//	//2.从数组中找到最大值
//	int max = 0; //先认定一个最大值为0
//	for (int i = 0; i < 5; i++)
//	{
//		//cout << arr[i] << endl;
//		//如果访问的数组中的元素比我认定的最大值还要大，更新最大值
//		if (arr[i]>max)
//		{
//			max = arr[i];
//		}
//	}
//	//3.打印最大值
//	cout << "最终的小猪体重最重为：" << max << endl;
//}

//请声明一个5个元素的数组，并且将元素逆置.
//
//(如原数组元素为：1, 3, 2, 5, 4; 逆置后输出结果为:4, 5, 2, 3, 1);
//#include<iostream>
//using namespace std;
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	cout << "数组元素逆置前：" << endl;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << arr[i] << endl;
//	}
//	int start = 0;
//	int end = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (start < end)
//	{
//		int temp = arr[start];
//		arr[start] = arr[end];
//		arr[end] = temp;
//		start++;
//		end--;
//	}
//	cout << "数组元素逆置后：" << endl;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << arr[i] << endl;
//	}
//}
