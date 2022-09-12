#include<iostream>
#include"282_computer_identity_314.h"
#include<fstream>
#include<string>
#include"282_computer_globalFile_314.h"
#include"282_computer_student_314.h"
#include"282_computer_teacher_314.h"
#include"282_computer_manager_314.h"
using namespace std;
//ѧ���˵�
void studentMenu(Identity * &student)
{
	while (true)
	{
		//ѧ���˵�
		student->openMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//�������Ա�Ӳ˵�����				//��Ϊmanager���βΣ��������Ч��
void managerMenu(Identity* &manager)//ָ��ָ������ָ�룬���ÿ����µ�ַ�洢����Ϊ��������
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->openMenu();
		//������ָ��תΪ����ָ�룬���������������ӿ�
		//Manager* man = dynamic_cast<Manager*>(manager);���ѽ���
		Manager* man = (Manager*)manager;
		int select = 0;
		//�����û�ѡ��
		cin >> select;
		if (select == 1)//����˺�
		{
			cout << "����˺�" << endl;
			man->addperson();
		}
		else if (select == 2)//�����˺� 
		{
			cout << "�����˺�" << endl;
			man->showPerson();
		}
		else if (select = 3)//�鿴����
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->clearFile();
		}
		else
		{
			delete manager;//���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//��ʦ�˵�
void TeacherMenu(Identity * &teacher)
{
	while (true)
	{
		//��ʦ�˵�
		teacher->openMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//��¼���� ����1:�����ļ��� ����2:�����������
void LoginIn(string fileName, int type)
{
	//����ָ�� ָ���������
	Identity * person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;
	//�ж����
	if (type == 1)//ѧ�����
	{
		cout << "���������ѧ��:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ����:" << endl;
		cin >> id;
	}
	cout << "�������û���:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//ѧ�������֤
		int fId;//���ļ��ж�ȡID
		string fName;
		string fPwd;
		while (ifs >> fId&&ifs >> fName&&ifs >> fPwd)
		{
			/*cout << fId << " " << fName << " " << fPwd << endl;*/
			//���û�������Ϣ���Ա�
			if (fId == id&&fName == name&&fPwd == pwd)
			{
				cout << "ѧ����½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}//#(type == 1)
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
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
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "��֤��¼�ɹ�!" << endl;
				//��¼�ɹ��󣬰�������������Ա����
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��½ʧ��" << endl;
	system("pause");
	system("cls");
	return;
}
int main() {

	int select = 0;

	while (true)
	{

		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select; //�����û�ѡ��

		switch (select)
		{
		case 1:  //ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //�˳�ϵͳ
			cout << "��ӭ��һ��ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}