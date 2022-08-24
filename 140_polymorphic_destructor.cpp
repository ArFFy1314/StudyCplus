//虚析构和纯虚析构
#include<iostream>
#include<string>
using namespace std;
class Animal
{
public:
	Animal()
	{
		cout << "Animal 构造" << endl;
	}
	//纯虚函数
	virtual void speak() = 0;
	//利用虚析构可以解决 父类指针释放子类对象不干净的问题
	/*virtual ~Animal()
	{
		cout << "Animal 虚析构" << endl;
	}*/
	//纯虚析构 声明实现 抽象类
	virtual ~Animal() = 0;
};
Animal::~Animal()
{
	cout << "Animal 纯虚析构" << endl;
}
class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat 构造" << endl;
		m_Name = new string(name);
	}
	virtual void speak()
	{
		cout << *m_Name<<"喵喵喵" << endl;
	}
	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "Cat 析构" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
	string* m_Name;
};
void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
	delete animal;
}
int main()
{
	test01();
	system("pause");
}