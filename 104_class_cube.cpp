//设计立方体类(Cube)
//求出立方体的面积和体积
//分别用全局函数和成员函数判断两个立方体是否相等。
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
设计立方体类（Cube）
求出立方体面积、体积
分别用全局函数和成员函数判断两个立方体是否相等
*/

class Cube
{
private:
	double cube_L;//长
	double cube_W;//宽
	double cube_H;//高

public:
	void setL(double L)
	{
		cube_L = L;
	}
	double getL()
	{
		return cube_L;
	}

	void setH(double H)
	{
		cube_H = H;
	}
	double getH()
	{
		return cube_H;
	}

	void setW(double W)
	{
		cube_W = W;
	}
	double getW()
	{
		return cube_W;
	}

	//面积
	void getS()
	{
		double S = 2 * cube_L * cube_H + 2 * cube_L * cube_W + 2 * cube_H * cube_W;
		cout << "立方体面积： " << S << endl;
	}

	//体积
	void getV()
	{
		double V = cube_L * cube_H * cube_W;
		cout << "立方体体积： " << V << endl;
	}

	//成员函数判断两个立方体是否相等
	void IfSame(Cube& c)
	{
		bool ref = cube_L == c.getL() && cube_H == c.getH() && cube_W == c.getW();
		if (ref)
		{
			cout << "成员函数判断：c1 与 c2 相等" << endl;
		}
		else
		{
			cout << "成员函数判断：c1 与 c2 不相等" << endl;
		}
	}
};

//全局函数判断立方体相等
void IfSame(Cube& c1, Cube& c2)//引用，可用于节省开销
{
	if (c1.getL() == c2.getL() && c1.getH() == c2.getH() && c1.getW() == c2.getW())
	{
		cout << "c1 与 c2 相等" << endl;
	}
	else
	{
		cout << "c1 与 c2 不相等" << endl;
	}
}

int main()
{
	Cube c1;
	c1.setL(10);
	c1.setH(10);
	c1.setW(10);


	Cube c2;
	c2.setL(11);
	c2.setH(10);
	c2.setW(10);

	c1.getS();
	c1.getV();

	IfSame(c1, c2);

	c1.IfSame(c2);

	system("pause");
	return EXIT_SUCCESS;
}


