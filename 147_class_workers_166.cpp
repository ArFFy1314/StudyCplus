#include"147_class_workers_166.h"
WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.���ļ����ڲ���¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ:" << num << endl;
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();
}
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void WorkerManager::Exit_System()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "������һ�����ְ������:" << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ�����

		//�����¿ռ�
		Worker** newSpace = new Worker *[newSize];
		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��

			cout << "�������" << i + 1 << "����ְ�����:" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������:" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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

			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;

		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//������ְ������
		this->m_EmpNum = newSize;

		//�ɹ���Ӻ� ���浽�ļ���
		this->save();

		//�ı��ļ�״̬
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
	}
	else
	{
		cout << "������������" << endl;
	}

	//������������� �ص��ϼ�Ŀ¼
	system("pause");
	system("cls");

}
//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//д

	//��ÿ��������д���ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
//ͳ������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ��
	
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id&&ifs >> name&&ifs >> did)
	{
		//ͳ������
		num++;
	}
	return num;
}
//��ʼ��Ա��
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
		if (did == 1)//��ְͨ��
			worker = new Employee(id, name, did);
		else if (did == 2)
			worker = new Manager(id, name, did);
		else worker = new Boss(id, name, did);
		this->m_EmpArray[index] = worker;
		index++;
	}
	//�ر��ļ�
	ifs.close();
}

void WorkerManager::show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	//��������������
	system("pause");
	system("cls");
}
//ɾ��Ա��
void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ɾ��ʱ�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ��ְ���ı��:" << endl;
		int id = 0;
		cin >> id;
		int index = this->is_Exist(id);
		if (index != -1)//ְ�����ڣ�ɾ��indexλ�õ�ְ��
		{
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//���������м�¼��Ա����
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}
//�ж�Ա���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ���-1
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
//�޸�ְ��
void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�޸�ʱ�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��:" << endl;
		int id;
		cin >> id;

		int ret=this->is_Exist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��

			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "���ҵ�" << id << "��ְ������������ְ����" << endl;
			cin >> newId;
			cout << "������������:" << endl;
			cin >> newName;
			cout << "�������λ:" << endl;
			cout << "1.ְ�� 2.���� 3.�ϰ�" << endl;

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
			//�������� ��������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ�" << endl;

			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
//����ְ��
void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "����ʱ�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1.����ְ����Ų���" << endl;
		cout << "2.����ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//���ձ�Ų�
			int id;
			cout << "��������ҵ�Ա�����:" << endl;
			cin >> id;
			int ret = is_Exist(id);
			if (ret != -1)
			{
				//�ҵ�ְ��
				cout << "���ҵ�ְ������ְ����Ϣ����:" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if(select==2)
		{
			//����������
			string name;
			cout << "��������ҵ�����:" << endl;
			cin >> name;
			//������ұ�־
			bool find_flag = false;//Ĭ��δ�ҵ�ְ��
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ:" 
						<< this->m_EmpArray[i]->m_Id 
						<< "��ְ����Ϣ����:" << endl;

					find_flag = true;
					//������ʾ��Ϣ�ӿ�
					this->m_EmpArray[i]->showInfo();
				}
				
			}
			if (find_flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	//����
	system("pause");
	system("cls");
}
//����
void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrmax = i;//������Сֵ�������ֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
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
			//�ж�һ��ʼ�϶� ��Сֵ�������ֵ �ǲ��Ǽ������Сֵ�������ֵ��������ǽ�������
			if (i != minOrmax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}
		}
		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->show_Emp();
	}
}
//���
void WorkerManager::clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//����ļ�
		ofstream ofs("FILENAME", ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];//�������ÿ��Ԫ�ؿ��ٵ�����
				this->m_EmpArray[i] = NULL;
			}
			//ɾ����������ָ��|delete[] ɾ�����鱾��Ķ����ڴ�
			delete[] this->m_EmpArray;//���鿪�ٵ�����
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//���캯��
Employee::Employee(int id,string name,int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ�����:" << this->m_Id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptname()
		<< "\t��λְ��:��ɾ�����������" << endl;
}
//��ȡ��λ����
string Employee::getDeptname()
{
	return string("Ա��");
}

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ�����:" << this->m_Id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptname()
		<< "\t��λְ��:����ϰ彻�������񣬲����·�����" << endl;
}
//��ȡ��λ����
string Manager::getDeptname()
{
	return string("����");
}

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ�����:" << this->m_Id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptname()
		<< "\t��λְ��:����˾" << endl;
}
//��ȡ��λ����
string Boss::getDeptname()
{
	return string("�ϰ�");
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