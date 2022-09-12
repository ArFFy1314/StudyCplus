#include<iostream>
#include"282_computer_identity_314.h"
#include<fstream>
#include<string>
#include"282_computer_globalFile_314.h"
#include"282_computer_student_314.h"
#include"282_computer_teacher_314.h"
#include"282_computer_manager_314.h"
using namespace std;
//学生菜单
void studentMenu(Identity * &student)
{
	while (true)
	{
		//学生菜单
		student->openMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3) //查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//进入管理员子菜单界面				//因为manager是形参，可以提高效率
void managerMenu(Identity* &manager)//指针指向引用指针，不用开辟新地址存储，作为别名调用
{
	while (true)
	{
		//调用管理员子菜单
		manager->openMenu();
		//将父类指针转为子类指针，调用子类里其他接口
		//Manager* man = dynamic_cast<Manager*>(manager);网友建议
		Manager* man = (Manager*)manager;
		int select = 0;
		//接受用户选项
		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addperson();
		}
		else if (select == 2)//查兰账号 
		{
			cout << "查兰账号" << endl;
			man->showPerson();
		}
		else if (select = 3)//查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			cout << "清空预约" << endl;
			man->clearFile();
		}
		else
		{
			delete manager;//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//教师菜单
void TeacherMenu(Identity * &teacher)
{
	while (true)
	{
		//教师菜单
		teacher->openMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//登录功能 参数1:操作文件名 参数2:操作身份类型
void LoginIn(string fileName, int type)
{
	//父类指针 指向子类对象
	Identity * person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接收用户信息
	int id = 0;
	string name;
	string pwd;
	//判断身份
	if (type == 1)//学生身份
	{
		cout << "请输入你的学号:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号:" << endl;
		cin >> id;
	}
	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//学生身份验证
		int fId;//从文件中读取ID
		string fName;
		string fPwd;
		while (ifs >> fId&&ifs >> fName&&ifs >> fPwd)
		{
			/*cout << fId << " " << fName << " " << fPwd << endl;*/
			//与用户输入信息做对比
			if (fId == id&&fName == name&&fPwd == pwd)
			{
				cout << "学生登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
	}//#(type == 1)
	else if (type == 2)
	{
		//教师登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "验证登录成功!" << endl;
				//登录成功后，按任意键进入管理员界面
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登陆失败" << endl;
	system("pause");
	system("cls");
	return;
}
int main() {

	int select = 0;

	while (true)
	{

		cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择

		switch (select)
		{
		case 1:  //学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //退出系统
			cout << "欢迎下一次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}