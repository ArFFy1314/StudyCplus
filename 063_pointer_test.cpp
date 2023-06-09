//指针、数组、函数 实战

//当数组名传入到函数作为参数时，被退化为指向首元素的指针
//封装一个函数，利用冒泡排序，实现对整型数组的升序排序
//例如数组：int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };

#include<iostream>
using namespace std;

//冒泡排序函数
void bubbleSort(int * arr, int len)  //int * arr 也可以写为int arr[]
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//打印数组函数
void printArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}
int main() 
{
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
	int len = sizeof(arr) / sizeof(int);
	bubbleSort(arr, len);
	printArray(arr, len);
	system("pause");
	return 0;
}

////垃圾自写 冒个der
//void bubbleSort(int* p,int *q) 
//{
//	cout << *p << "," << *q << endl;
//	int temp = *p;
//	if (*p > *q)
//	{
//		*p = *q;
//		*q = temp;
//	}
//
//}
//int main()
//{
//	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9 - i; j++)
//			bubbleSort(&arr[j], &arr[j + 1]);
//		for (int i = 0; i<10; i++)
//			cout << arr[i] << ",";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}