#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker;//����Worker��ά��ְ����Ϣ
#include<fstream>
#define FILENAME "empFile.txt"
//ְ������ϵͳ
class WorkerManager
{
public:
	WorkerManager();
	//չʾ�˵�
	void Show_Menu();
	//�˳�ϵͳ
	void Exit_System();
	
	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//ͳ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//չʾְ����Ϣ
	void show_Emp();

	//ɾ��Ա��
	void del_Emp();
	//�ж�Ա���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int is_Exist(int id);

	//�޸�ְ��
	void mod_Emp();

	//����ְ��
	void find_Emp();

	//����
	void sort_Emp();

	//���
	void clean_File();
	~WorkerManager();
private:
	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker ** m_EmpArray;
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	

};
//ְ���������
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptname() = 0;
	//ְ�����
	int m_Id;
	//ְ������
	string m_Name;
	//���ű��
	int m_DeptId;
};
class Employee :public Worker
{
public:
	//���캯��
	Employee(int id, string name,int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptname();
};
class Manager :public Worker
{
public:
	Manager(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptname();
};
class Boss :public Worker
{
public:
	Boss(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptname();
};