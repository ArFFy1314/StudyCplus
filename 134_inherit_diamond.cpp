//菱形继承|钻石继承
//利用虚继承virtual解决菱形继承浪费的问题
//vbptr
// virtual base pointer
#include<iostream>
using namespace std;
//动物类
class Animal
{
public:
	int m_Age;
};
//羊类
class Sheep :virtual public Animal
{

};
//驼类
class Tuo :virtual public Animal
{

};
//羊驼类
class SheepTuo :public Sheep, public Tuo
{

};
void test01()
{
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 1;
	cout << "Sheep Age=" << st.Sheep::m_Age << endl;
	cout << "Tuo Age=" << st.Tuo::m_Age << endl;

	//这份数据有一份就可以，浪费资源

}
int main()
{
	test01();
	system("pause");
}