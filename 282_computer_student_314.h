#pragma once 
#include<iostream>
using namespace std;
#include"282_computer_identity_314.h"
#include<vector>
#include"282_computer_room_314.h"
//ѧ����
class Student :public Identity
{
public:

	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string name, string pwd);
	//�˵�����
	virtual void openMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴����ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
	//ѧ��ѧ��
	int m_Id;
	//��������
	vector<ComputerRoom> vCom;
};