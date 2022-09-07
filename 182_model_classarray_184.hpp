//
//class MyArray
//{
//public:
//	构造函数容量
//	拷贝构造
//	operator=
//	利用下标访问数组中的元素
//	尾插法
//	尾删法
//	获取数组容量
//	获取数组大小
//	析构
//private:
//	//数组 T* pAddress;
//	//容量 m_Capacity;
//	//大小 m_Size;
//};
//下两行标准，不是标准数据类型，得是我们自己定义的数据类型，如类等;否则可以混用。
//delete	释放new分配的单个对象指针指向的内存, 代表用来释放内存，且只用来释放ptr指向的内存
//delete[]	释放new分配的对象数组指针指向的内存,用来释放rg指向的内存，！！还逐一调用数组中每个对象的destructor！！
//对于像int/char/long/int*/struct等等简单数据类型，由于对象没有destructor，
//所以用delete 和delete [] 是一样的！但是如果是C++对象数组就不同了！
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
//	cout << hex << p1 << endl;                            //输出P1的地址												  //  delete[] p1;
//	delete p1;
//
//	T* p2 = new T[NUM];
//	cout << p2 << endl;                                    //输出P2的地址
//	delete[] p2;
//	return 0;
//}
//1、从运行结果中我们可以看出，delete p1 在回收空间的过程中，只有 p1[0] 这个对象调用了析构函数，其它对象如 p1[1]、p1[2] 等都没有调用自身的析构函数，这就是问题的症结所在。如果用 delete[]，则在回收空间之前所有对象都会首先调用自己的析构函数。
//2、基本类型的对象没有析构函数，所以回收基本类型组成的数组空间用 delete 和 delete[] 都是应该可以的；但是对于类对象数组，只能用 delete[]。对于 new 的单个对象，只能用 delete 不能用 delete[] 回收空间。
//3、所以一个简单的使用原则就是：new 和 delete、new[] 和 delete[] 对应使用。
//4、可以看出 如果只是使用了delete来进行释放数组对象 则会出现进程异常 且只 调用了 一次析构函数
//5、如果 换成 delete[] 可以看出释放对象数组时 调用了三次析构函数 也刚好把所有的空间都释放了


#pragma once
#include<iostream>
using namespace std;
template<class T>
class MyArray
{
public:
	//有参构造 参数 容量
	MyArray(int capacity)
	{
		cout << "MyArray有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造函数
	MyArray(const MyArray& arr)
	{
		cout << "MyArray拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;浅拷贝，重复释放
		this->pAddress=new T[arr.m_Capacity];//深拷贝
		//将arr中的数据拷贝过来
		for (int i = 0; i < this->m_Size; i ++ )
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator= 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr)
	{
		cout << "MyArray operator=调用" << endl;
		//先判断原来堆区是否有数据，有先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//尾插法
	void Push_Back(const T& val)
	{
		//判断容量是否等于大小
		if (this->m_Capacity == this->m_Size)
			return;
		this->pAddress[this->m_Size] = val;//在数组末尾插入数据
		this->m_Size++;//更新数组大小
	}
	//尾删法
	void Pop_Back()
	{

		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (this->m_Size == 0)
			return;
		this->m_Size--;
	}
	//通过下标方式访问数组中的元素 作为左值 arr[0]=100;
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	//返回数组的容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//返回数组的大小
	int getSize()
	{
		return this->m_Size;
	}
	//析构函数
	~MyArray()
	{
		cout << "MyArray析构调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;//指针指向堆区开辟的真实数组
	int m_Capacity;//数组容量
	int m_Size;//数组大小
};