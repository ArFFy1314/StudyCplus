//ʵ��ͨ�� �������������ĺ���
//* ���ú���ģ���װһ������ĺ��������Զ�**��ͬ������������**��������
//* �������Ӵ�С�������㷨Ϊ**ѡ������**
//* �ֱ�����**char����**��**int����**���в���
//�ܽ᣺ģ�������ߴ��븴�ã���Ҫ��������
#include<iostream>
using namespace std;
//��������ģ��
template<typename T> void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
//�����㷨
template<typename T> void mySort(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//�϶����ֵ���±�
		for (int j = i + 1; j < len; j++)
		{
			//�϶������ֵ�ȱ��������ֵС��˵��J�±��
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			//����max��iԪ��
			mySwap(arr[max], arr[i]);
		}
	}
}
//��ӡ����ģ��
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
	//����char����
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);
}
void test02()
{
	//����int
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