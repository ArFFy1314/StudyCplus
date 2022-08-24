//继承中的对象模型
//父类中所有非静态成员属性都会被子类继承下去
//父类中私有成员属性，被编译器隐藏了，访问不到

//利用开发人员命令提示工具查看对象模型
//跳转模型 F:
//跳转文件路径 cd 具体路径
//查看命名
// cl d1 reportSingleClassLayout类名 文件名

#include<iostream>
using namespace std;
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

//公共继承
class Son :public Base
{
public:
	int m_D;
};

void test01()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}