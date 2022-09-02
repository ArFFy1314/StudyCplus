#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker;//声明Worker，维护职工信息
#include<fstream>
#define FILENAME "empFile.txt"
//职工管理系统
class WorkerManager
{
public:
	WorkerManager();
	//展示菜单
	void Show_Menu();
	//退出系统
	void Exit_System();
	
	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//统计人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//展示职工信息
	void show_Emp();

	//删除员工
	void del_Emp();
	//判断员工是否存在，如果存在返回职工所在数组中的位置，不存在返回-1
	int is_Exist(int id);

	//修改职工
	void mod_Emp();

	//查找职工
	void find_Emp();

	//排序
	void sort_Emp();

	//清空
	void clean_File();
	~WorkerManager();
private:
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker ** m_EmpArray;
	//判断文件是否为空
	bool m_FileIsEmpty;
	

};
//职工抽象基类
class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptname() = 0;
	//职工编号
	int m_Id;
	//职工姓名
	string m_Name;
	//部门编号
	int m_DeptId;
};
class Employee :public Worker
{
public:
	//构造函数
	Employee(int id, string name,int did);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptname();
};
class Manager :public Worker
{
public:
	Manager(int id, string name, int did);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptname();
};
class Boss :public Worker
{
public:
	Boss(int id, string name, int did);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptname();
};