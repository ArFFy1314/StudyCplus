//�����������(Cube)
//������������������
//�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ���ȡ�
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*
����������ࣨCube��
�����������������
�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
*/

class Cube
{
private:
	double cube_L;//��
	double cube_W;//��
	double cube_H;//��

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

	//���
	void getS()
	{
		double S = 2 * cube_L * cube_H + 2 * cube_L * cube_W + 2 * cube_H * cube_W;
		cout << "����������� " << S << endl;
	}

	//���
	void getV()
	{
		double V = cube_L * cube_H * cube_W;
		cout << "����������� " << V << endl;
	}

	//��Ա�����ж������������Ƿ����
	void IfSame(Cube& c)
	{
		bool ref = cube_L == c.getL() && cube_H == c.getH() && cube_W == c.getW();
		if (ref)
		{
			cout << "��Ա�����жϣ�c1 �� c2 ���" << endl;
		}
		else
		{
			cout << "��Ա�����жϣ�c1 �� c2 �����" << endl;
		}
	}
};

//ȫ�ֺ����ж����������
void IfSame(Cube& c1, Cube& c2)//���ã������ڽ�ʡ����
{
	if (c1.getL() == c2.getL() && c1.getH() == c2.getH() && c1.getW() == c2.getW())
	{
		cout << "c1 �� c2 ���" << endl;
	}
	else
	{
		cout << "c1 �� c2 �����" << endl;
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


