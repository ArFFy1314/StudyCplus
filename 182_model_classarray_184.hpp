//
//class MyArray
//{
//public:
//	���캯������
//	��������
//	operator=
//	�����±���������е�Ԫ��
//	β�巨
//	βɾ��
//	��ȡ��������
//	��ȡ�����С
//	����
//private:
//	//���� T* pAddress;
//	//���� m_Capacity;
//	//��С m_Size;
//};
//�����б�׼�����Ǳ�׼�������ͣ����������Լ�������������ͣ������;������Ի��á�
//delete	�ͷ�new����ĵ�������ָ��ָ����ڴ�, ���������ͷ��ڴ棬��ֻ�����ͷ�ptrָ����ڴ�
//delete[]	�ͷ�new����Ķ�������ָ��ָ����ڴ�,�����ͷ�rgָ����ڴ棬��������һ����������ÿ�������destructor����
//������int/char/long/int*/struct�ȵȼ��������ͣ����ڶ���û��destructor��
//������delete ��delete [] ��һ���ģ����������C++��������Ͳ�ͬ�ˣ�
//#include <iostream>;
//using namespace std;
//class T {
//public:
//	T() { cout << "constructor" << endl; }
//	~T() { cout << "destructor" << endl; }
//};
//int main()
//{
//	const int NUM = 3;
//	T* p1 = new T[NUM];
//	cout << hex << p1 << endl;                            //���P1�ĵ�ַ												  //  delete[] p1;
//	delete p1;
//
//	T* p2 = new T[NUM];
//	cout << p2 << endl;                                    //���P2�ĵ�ַ
//	delete[] p2;
//	return 0;
//}
//1�������н�������ǿ��Կ�����delete p1 �ڻ��տռ�Ĺ����У�ֻ�� p1[0] �������������������������������� p1[1]��p1[2] �ȶ�û�е����������������������������֢�����ڡ������ delete[]�����ڻ��տռ�֮ǰ���ж��󶼻����ȵ����Լ�������������
//2���������͵Ķ���û���������������Ի��ջ���������ɵ�����ռ��� delete �� delete[] ����Ӧ�ÿ��Եģ����Ƕ�����������飬ֻ���� delete[]������ new �ĵ�������ֻ���� delete ������ delete[] ���տռ䡣
//3������һ���򵥵�ʹ��ԭ����ǣ�new �� delete��new[] �� delete[] ��Ӧʹ�á�
//4�����Կ��� ���ֻ��ʹ����delete�������ͷ�������� �����ֽ����쳣 ��ֻ ������ һ����������
//5����� ���� delete[] ���Կ����ͷŶ�������ʱ ������������������ Ҳ�պð����еĿռ䶼�ͷ���


#pragma once
#include<iostream>
using namespace std;
template<class T>
class MyArray
{
public:
	//�вι��� ���� ����
	MyArray(int capacity)
	{
		cout << "MyArray�вι������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//�������캯��
	MyArray(const MyArray& arr)
	{
		cout << "MyArray�����������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;ǳ�������ظ��ͷ�
		this->pAddress=new T[arr.m_Capacity];//���
		//��arr�е����ݿ�������
		for (int i = 0; i < this->m_Size; i ++ )
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator= ��ֹǳ��������
	MyArray& operator=(const MyArray& arr)
	{
		cout << "MyArray operator=����" << endl;
		//���ж�ԭ�������Ƿ������ݣ������ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//β�巨
	void Push_Back(const T& val)
	{
		//�ж������Ƿ���ڴ�С
		if (this->m_Capacity == this->m_Size)
			return;
		this->pAddress[this->m_Size] = val;//������ĩβ��������
		this->m_Size++;//���������С
	}
	//βɾ��
	void Pop_Back()
	{

		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
		if (this->m_Size == 0)
			return;
		this->m_Size--;
	}
	//ͨ���±귽ʽ���������е�Ԫ�� ��Ϊ��ֵ arr[0]=100;
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	//�������������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//��������Ĵ�С
	int getSize()
	{
		return this->m_Size;
	}
	//��������
	~MyArray()
	{
		cout << "MyArray��������" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;//ָ��ָ��������ٵ���ʵ����
	int m_Capacity;//��������
	int m_Size;//�����С
};