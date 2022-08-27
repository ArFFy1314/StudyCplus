//点和圆的关系
//设计一个圆形类（Circle），和一个点类（Point），计算点和圆的关系。

#include<iostream>
using namespace std;
#include <iostream>
#include <string>
using namespace std;
//创建一个点类，用来表示圆心和另一个点
class point
{
public:
	//设置x
	void setx(int x)
	{
		m_x = x;
	}
	//获取x
	int getx()
	{
		return  m_x;
	}
	//设置y
	void sety(int y)
	{
		m_y = y;
	}
	//获取y
	int gety()
	{
		return  m_y;
	}

private:
	int m_x;
	int m_y;
};
class circle
{
public:
	//设置半径
	void setR(int R)
	{
		m_R = R;
	}
	//获取半径
	int getR()
	{
		return m_R;
	}
	//设置圆心
	void setcenter(point center)
	{
		m_center = center;
	}
	//获取圆心
	point getcenter()
	{
		return m_center;
	}
private:
	int m_R;
	//point 是另一个类
	point m_center;
};
//判断点和园的关系
void isincircle(circle& c, point & p)
{
	//计算两点之间距离的平方
	int distance = (c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx()) +
		(c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());
	//计算半径的平方
	int rDistance = c.getR() * c.getR();
	if (rDistance == distance)
	{
		cout << "点在圆上" << endl;
	}
	else if (rDistance > distance)
	{
		cout << "点在圆内" << endl;
	}
	else
		cout << "点在圆外" << endl;

}
int main()
{//创建圆
	circle c;
	c.setR(10);
	point center;
	center.setx(10);
	center.sety(0);
	c.setcenter(center);
	//创建点
	point p;
	p.setx(10);
	p.sety(10);
	//判断关系
	isincircle(c, p);
}