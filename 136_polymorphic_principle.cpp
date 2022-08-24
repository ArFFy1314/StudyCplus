//多态的基本概念 多种形态
//动态多态满足条件
//1.继承关系2.子类要重写父类虚函数
//重写 函数返回值类型 函数名 函数列表 完全相同
//动态多态使用：父类的指针或者引用 指向子类对象
#include<iostream>
using namespace std;

class Animal
{
public:
	//虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

void test01()
{
	cout << "sizeof(animal)=" << sizeof(Animal) << endl;
}
int main()
{
	test01();
	system("pause");
}