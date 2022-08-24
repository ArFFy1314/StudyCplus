//继承 方式
#include<iostream>
using namespace std;

class Base1
{
public: 
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
//公共继承
class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;//父类中公共权限成员，到子类中依然是公共权限
		m_B = 10;//父类中保护权限成员，到子类中依然是保护权限
		//m_C = 10;//父类中私有权限成员，子类访问不到
	}
};
//保护继承
class Son2 :protected Base1
{
public:
	void fun()
	{
		m_A = 100;//公共变保护
		m_B = 100;//保护
		//m_C = 100;私有
	}
};
//私有继承
class Son3 :private Base1
{
public:
	void func()
	{
		m_A = 100;//公共变私有
		m_B = 100;//保护变私有
		//m_C = 100;//私有不可以
	}
};
class GrandSon3 :public Son3
{
public:
	void func()
	{
		//到了son3变私有，子类不可访问
		/*m_A = 10;
		m_B = 10;
		m_C = 10;*/
	}
};
void test01()
{
	Son1 s1;
	s1.m_A = 100;//公共成员，类内类外均可以访问
	//s1.m_B = 100;//保护成员，类内可以访问，类外不可以访问
	Son2 s2;
	//s2.m_A = 100;//公共变保护
	//s2.m_B = 100;//保护
	//s2.m_C = 100;//私有
	Son3 s3;
	//s3.m_A = 10;变成私有

}
int main()
{

}