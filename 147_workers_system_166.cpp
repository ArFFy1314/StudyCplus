#include<iostream>
#include"147_class_workers_166.h"
using namespace std;
int main()
{
	////���Դ���
	//Worker * worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "����", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "����", 3);
	//worker->showInfo();
	//delete worker;

	//ʵ���������߶���
	WorkerManager wm;
	int choice = 0;
	while(1)
	{
		wm.Show_Menu();
		cout << "����������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.Exit_System();
			break;
		case 1://����ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.del_Emp();
			break;
		case 4://�޸�ְ��
			wm.mod_Emp();
			break;
		case 5://����ְ��
			wm.find_Emp();
			break;
		case 6://����ְ��
			wm.sort_Emp();
			break;
		case 7://����ĵ�
			wm.clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}