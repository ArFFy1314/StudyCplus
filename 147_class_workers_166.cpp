#include"147_class_workers_166.h"
WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.当文件存在并记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为:" << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->init_Emp();
}
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void WorkerManager::Exit_System()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入一下添加职工数量:" << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间人数

		//开辟新空间
		Worker** newSpace = new Worker *[newSize];
		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择

			cout << "请输入第" << i + 1 << "个新职工编号:" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名:" << endl;
			cin >> name;
			cout << "请选择该职工岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}

			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;

		}
		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newSpace;

		//更新新职工人数
		this->m_EmpNum = newSize;

		//成功添加后 保存到文件中
		this->save();

		//改变文件状态
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;
	}
	else
	{
		cout << "输入数据有误" << endl;
	}

	//按任意键清屏后 回到上级目录
	system("pause");
	system("cls");

}
//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//写

	//将每个人数据写到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
//统计人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件 读
	
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id&&ifs >> name&&ifs >> did)
	{
		//统计人数
		num++;
	}
	return num;
}
//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id&&ifs >> name&&ifs >> did)
	{
		Worker * worker = NULL;
		if (did == 1)//普通职工
			worker = new Employee(id, name, did);
		else if (did == 2)
			worker = new Manager(id, name, did);
		else worker = new Boss(id, name, did);
		this->m_EmpArray[index] = worker;
		index++;
	}
	//关闭文件
	ifs.close();
}

void WorkerManager::show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键后会清屏
	system("pause");
	system("cls");
}
//删除员工
void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "删除时文件不存在或者记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除职工的编号:" << endl;
		int id = 0;
		cin >> id;
		int index = this->is_Exist(id);
		if (index != -1)//职工存在，删除index位置的职工
		{
			//数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新数组中记录人员个数
			//数据同步更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
//判断员工是否存在，如果存在返回职工所在数组中的位置，不存在返回-1
int WorkerManager::is_Exist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
//修改职工
void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "修改时文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号:" << endl;
		int id;
		cin >> id;

		int ret=this->is_Exist(id);
		if (ret != -1)
		{
			//查找到编号的职工

			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查找到" << id << "号职工，请输入新职工号" << endl;
			cin >> newId;
			cout << "请输入新姓名:" << endl;
			cin >> newName;
			cout << "请输入岗位:" << endl;
			cout << "1.职工 2.经理 3.老板" << endl;

			cin >> dSelect;
			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			//更新数据 到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功" << endl;

			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找职工
void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "查找时文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按照编号查
			int id;
			cout << "请输入查找的员工编号:" << endl;
			cin >> id;
			int ret = is_Exist(id);
			if (ret != -1)
			{
				//找到职工
				cout << "查找到职工，该职工信息如下:" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if(select==2)
		{
			//按照姓名查
			string name;
			cout << "请输入查找的姓名:" << endl;
			cin >> name;
			//加入查找标志
			bool find_flag = false;//默认未找到职工
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为:" 
						<< this->m_EmpArray[i]->m_Id 
						<< "号职工信息如下:" << endl;

					find_flag = true;
					//调用显示信息接口
					this->m_EmpArray[i]->showInfo();
				}
				
			}
			if (find_flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	//清屏
	system("pause");
	system("cls");
}
//排序
void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrmax = i;//声明最小值或者最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrmax]->m_Id
			> this->m_EmpArray[j]->m_Id)
						minOrmax = j;

				}
				else
				{
					if (this->m_EmpArray[minOrmax]->m_Id
		< this->m_EmpArray[j]->m_Id)
						minOrmax = j;
				}
			}
			//判断一开始认定 最小值或者最大值 是不是计算的最小值或者最大值，如果不是交换数据
			if (i != minOrmax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}
		}
		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->show_Emp();
	}
}
//清空
void WorkerManager::clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs("FILENAME", ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];//数组里的每个元素开辟到堆区
				this->m_EmpArray[i] = NULL;
			}
			//删除堆区数组指针|delete[] 删除数组本身的堆区内存
			delete[] this->m_EmpArray;//数组开辟到堆区
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
//构造函数
Employee::Employee(int id,string name,int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//显示个人信息
void Employee::showInfo()
{
	cout << "职工编号:" << this->m_Id
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDeptname()
		<< "\t岗位职责:完成经理交给的任务" << endl;
}
//获取岗位名称
string Employee::getDeptname()
{
	return string("员工");
}

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//显示个人信息
void Manager::showInfo()
{
	cout << "职工编号:" << this->m_Id
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDeptname()
		<< "\t岗位职责:完成老板交给的任务，并且下发任务" << endl;
}
//获取岗位名称
string Manager::getDeptname()
{
	return string("经理");
}

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号:" << this->m_Id
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDeptname()
		<< "\t岗位职责:管理公司" << endl;
}
//获取岗位名称
string Boss::getDeptname()
{
	return string("老板");
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
	}
	delete[] this->m_EmpArray;
	this->m_EmpArray = NULL;
}