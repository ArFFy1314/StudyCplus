#pragma once
#include<iostream>
using namespace std;
#include"282_computer_identity_314.h"
//��ʦ��
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int empId, string name, string pwd);
	//�˵�����
	virtual void openMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
	//ְ����
	int m_EmpId;
};