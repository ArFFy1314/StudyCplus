//设计学生类
/*属性和行为作为主体

C++面向对象的三大特性为： == 封装、继承、多态 ==
C++认为 == 万事万物都皆为对象 == ，对象上有其属性和行为
**例如：**
​	1.人可以作为对象，属性有姓名、年龄、身高、体重...，行为有走、跑、跳、吃饭、唱歌...
​	2.车也可以作为对象，属性有轮胎、方向盘、车灯..., 行为有载人、放音乐、放空调...
​	具有相同性质的 == 对象 == ，我们可以抽象称为 == 类 == ，人属于人类，车属于车类
###封装的意义，封装是C++面向对象三大特性之一
* 将属性和行为作为一个整体，表现生活中的事物
* 将属性和行为加以权限控制

**封装意义一：**
​	在设计类的时候，属性和行为写在一起，表现事物
**语法：** class 类名{ 访问权限： 属性 / 行为 };*/
//设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
#include<iostream>
using namespace std;
//学生类
class Student {
public:
	void setName(string name) {
		m_name = name;
	}
	void setID(int id) {
		m_id = id;
	}

	void showStudent() {
		cout << "name:" << m_name << " ID:" << m_id << endl;
	}
public:
	string m_name;
	int m_id;
};

int main() {

	Student stu;
	stu.setName("德玛西亚");
	stu.setID(250);
	stu.showStudent();
	system("pause");
	return 0;
}

