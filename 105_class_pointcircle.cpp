//���Բ�Ĺ�ϵ
//���һ��Բ���ࣨCircle������һ�����ࣨPoint����������Բ�Ĺ�ϵ��

#include<iostream>
using namespace std;
#include <iostream>
#include <string>
using namespace std;
//����һ�����࣬������ʾԲ�ĺ���һ����
class point
{
public:
	//����x
	void setx(int x)
	{
		m_x = x;
	}
	//��ȡx
	int getx()
	{
		return  m_x;
	}
	//����y
	void sety(int y)
	{
		m_y = y;
	}
	//��ȡy
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
	//���ð뾶
	void setR(int R)
	{
		m_R = R;
	}
	//��ȡ�뾶
	int getR()
	{
		return m_R;
	}
	//����Բ��
	void setcenter(point center)
	{
		m_center = center;
	}
	//��ȡԲ��
	point getcenter()
	{
		return m_center;
	}
private:
	int m_R;
	//point ����һ����
	point m_center;
};
//�жϵ��԰�Ĺ�ϵ
void isincircle(circle& c, point & p)
{
	//��������֮������ƽ��
	int distance = (c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx()) +
		(c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());
	//����뾶��ƽ��
	int rDistance = c.getR() * c.getR();
	if (rDistance == distance)
	{
		cout << "����Բ��" << endl;
	}
	else if (rDistance > distance)
	{
		cout << "����Բ��" << endl;
	}
	else
		cout << "����Բ��" << endl;

}
int main()
{//����Բ
	circle c;
	c.setR(10);
	point center;
	center.setx(10);
	center.sety(0);
	c.setcenter(center);
	//������
	point p;
	p.setx(10);
	p.sety(10);
	//�жϹ�ϵ
	isincircle(c, p);
}