//ָ�롢���顢���� ʵս

//�����������뵽������Ϊ����ʱ�����˻�Ϊָ����Ԫ�ص�ָ��
//��װһ������������ð������ʵ�ֶ������������������
//�������飺int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };

#include<iostream>
using namespace std;

//ð��������
void bubbleSort(int * arr, int len)  //int * arr Ҳ����дΪint arr[]
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

//��ӡ���麯��
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

////������д ð��der
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