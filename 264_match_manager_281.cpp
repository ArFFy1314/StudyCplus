#include"264_match_manager_281.h"
//���캯��
SpeedManager::SpeedManager()
{
	//��ʼ������������
	this->initSpeech();
	//����ѡ��
	this->createSpeaker();
	//��������
	this->loadRecord();
}
//�˵���ʾ
void SpeedManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//�Ƴ�ϵͳ
void SpeedManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
//��ʼ������������
void SpeedManager::initSpeech()
{
	//�ÿ�����
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//��ʼ����������
	this->m_Index = 1;
	//����¼������ Ҳ���
	this->m_Record.clear();
}
//����12��ѡ��
void SpeedManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		//����ѡ�ֱ�� ���ҷ���v1������
		this->v1.push_back(i + 10001);
		//ѡ�ֱ���Լ���Ӧѡ�� ���뵽mao������
		this->m_Speaker.insert(make_pair(i + 10001, sp));

	}
}
//��ʼ���� �������̿���
void SpeedManager::startSpeech()
{
	//��һ�ֿ�ʼ����
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ�������
	this->showScore();
	//�ڶ��ֿ�ʼ����
	this->m_Index++;
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ���ս��
	this->showScore();

	//���������ļ���
	this->saveRecord();

	//���ñ�������ȡ��¼
	//��ʼ������������
	this->initSpeech();
	//����12��ѡ��
	this->createSpeaker();
	//���������¼
	this->loadRecord();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}
void printDraw(int val)
{
	cout << val << " ";
}
//��ǩ
void SpeedManager::speechDraw()
{
	cout << "��<<" << this->m_Index << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "----------------------------" << endl;
	cout << "��ǩ���ݽ�˳������:" << endl;
	if (this->m_Index == 1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for_each(v1.begin(), v1.end(), printDraw);
		cout << endl;
	}
	else
	{
		//�ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end());
		for_each(v2.begin(), v2.end(), printDraw);
		cout << endl;
	}
	cout << "----------------------------" << endl;
	system("pause");
	cout << endl;
}
//����
void SpeedManager::speechContest()
{
	cout << "-----��<<" << this->m_Index << ">>�ֱ�����ʽ��ʼ-----" << endl;
	//׼����ʱ�������С��ɼ�
	multimap<double, int, greater<double>> groupScore;
	int num = 0;//��¼��Ա���� 6��һ��

	vector<int> v_Src;//����ѡ������
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//��������ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			/*cout << score << " ";*/
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());//����
		d.pop_front();//ȥ����߷�
		d.pop_back();//ȥ����ͷ�
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		////��ӡƽ����
		//cout << "���:" << *it << "����:" << this->m_Speaker[*it].m_Name << "�÷�:" << avg << endl;
		//��ƽ���ַ��뵽map������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//��������� ������ʱС��������
		groupScore.insert(make_pair(avg, *it));//key�ǵ÷֣�value�Ǿ���ѡ�ֱ��
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С���������:" << endl;
			//ȡ��ǰ��������
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++, count++)
			{
				if (this->m_Index == 1&&count<3)
				{
					v2.push_back((*it).second);
				}
				else if(this->m_Index == 2 && count<3)
				{
					vVictory.push_back((*it).second);
				}
				cout << "���:" << it->second << " ����:" << this->m_Speaker[it->second].m_Name
					<< " �ɼ�:" << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
			cout << endl;
			groupScore.clear();
		}
	}
	cout << "-----��<<" << this->m_Index << ">>�ֱ������-----" << endl;
	system("pause");
}
//��ʾ�÷�
void SpeedManager::showScore()
{
	cout << "-----��<<" << this->m_Index << ">>�ֽ���ѡ����Ϣ����:" << endl;
	vector<int> v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ��:" << *it
			<< "����:" << this->m_Speaker[*it].m_Name
			<< "�÷�:" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");

}
//�����¼
void SpeedManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�

	//��ÿ��ѡ������ д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "��¼�������" << endl;
	//�м�¼�ˣ��ļ���Ϊ��
	this->fileIsEmpty = false;
}
//��ȡ��¼
void SpeedManager::loadRecord()
{
	ifstream ifs("speech.csv",ios::in);//���ļ�
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch);//�������ȡ�ĵ����ַ� �Ż���
	int index = 0;
	string data;
	while (ifs >> data)
	{
		vector<string> v;
		//cout << data << endl;
		int pos = -1;//�鵽����λ�ñ���
		int start = 0;//������ʼλ��
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//û���ҵ�
				break;
			}

			string temp = data.substr(start, pos - start);
			cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << it->first << "�ھ����:" << it->second[0] << "����:" << it->second[1] << endl;
	}
}

//��ʾ�����¼
void SpeedManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڣ����¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "�� " <<
				"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
				"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
				"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}
//��ռ�¼
void SpeedManager::clearRecord()
{
	cout << "�Ƿ�ȷ������ļ�" << endl;
	cout << "1.��" << endl;
	cout << "2.��" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//ȷ�����
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//��ʼ������������
		this->initSpeech();
		//����ѡ��
		this->createSpeaker();
		//��������
		this->loadRecord();
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//��������
SpeedManager::~SpeedManager()
{

}