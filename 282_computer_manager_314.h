#pragma once
#include<iostream>
using namespace std;
#include"282_computer_identity_314.h"
#include<vector>
#include"282_computer_student_314.h"
#include"282_computer_teacher_314.h"
#include"282_computer_room_314.h"
class Manager :public Identity
{
public:
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string pwd);
	//菜单界面
	virtual void openMenu();
	//添加账号
	void addperson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约信息
	void clearFile();
	//初始化容器
	void initVector();

	//检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
	bool checkRepeat(int id, int type);

	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	//机房容器
	vector<ComputerRoom> vCom;
};