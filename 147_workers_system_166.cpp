#include<iostream>
#include"147_class_workers_166.h"
using namespace std;
int main()
{
	////测试代码
	//Worker * worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "李四", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "王五", 3);
	//worker->showInfo();
	//delete worker;

	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;
	while(1)
	{
		wm.Show_Menu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.Exit_System();
			break;
		case 1://增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.del_Emp();
			break;
		case 4://修改职工
			wm.mod_Emp();
			break;
		case 5://查找职工
			wm.find_Emp();
			break;
		case 6://排序职工
			wm.sort_Emp();
			break;
		case 7://清空文档
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