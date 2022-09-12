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
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//�˵�����
	virtual void openMenu();
	//����˺�
	void addperson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��Ϣ
	void clearFile();
	//��ʼ������
	void initVector();

	//����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
	bool checkRepeat(int id, int type);

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<ComputerRoom> vCom;
};