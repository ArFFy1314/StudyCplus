#include"264_match_manager_281.h"
//构造函数
SpeedManager::SpeedManager()
{
	//初始化容器和属性
	this->initSpeech();
	//创建选手
	this->createSpeaker();
	//加载数据
	this->loadRecord();
}
//菜单显示
void SpeedManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//推出系统
void SpeedManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
//初始化容器和属性
void SpeedManager::initSpeech()
{
	//置空容器
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//初始化比赛轮数
	this->m_Index = 1;
	//将记录的容器 也清空
	this->m_Record.clear();
}
//创建12名选手
void SpeedManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		//创建选手编号 并且放入v1容器中
		this->v1.push_back(i + 10001);
		//选手编号以及对应选手 放入到mao容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));

	}
}
//开始比赛 整个流程控制
void SpeedManager::startSpeech()
{
	//第一轮开始比赛
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示晋级结果
	this->showScore();
	//第二轮开始比赛
	this->m_Index++;
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示最终结果
	this->showScore();

	//保存结果到文件中
	this->saveRecord();

	//重置比赛，获取记录
	//初始化容器和属性
	this->initSpeech();
	//创建12名选手
	this->createSpeaker();
	//加载往届记录
	this->loadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}
void printDraw(int val)
{
	cout << val << " ";
}
//抽签
void SpeedManager::speechDraw()
{
	cout << "第<<" << this->m_Index << ">>轮比赛选手正在抽签" << endl;
	cout << "----------------------------" << endl;
	cout << "抽签后演讲顺序如下:" << endl;
	if (this->m_Index == 1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for_each(v1.begin(), v1.end(), printDraw);
		cout << endl;
	}
	else
	{
		//第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for_each(v2.begin(), v2.end(), printDraw);
		cout << endl;
	}
	cout << "----------------------------" << endl;
	system("pause");
	cout << endl;
}
//比赛
void SpeedManager::speechContest()
{
	cout << "-----第<<" << this->m_Index << ">>轮比赛正式开始-----" << endl;
	//准备临时容器存放小组成绩
	multimap<double, int, greater<double>> groupScore;
	int num = 0;//记录人员个数 6人一组

	vector<int> v_Src;//比赛选手容器
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//遍历所有选手
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			/*cout << score << " ";*/
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());//排序
		d.pop_front();//去除最高分
		d.pop_back();//去除最低分
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		////打印平均分
		//cout << "编号:" << *it << "姓名:" << this->m_Speaker[*it].m_Name << "得分:" << avg << endl;
		//将平均分放入到map容器中
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//将打分数据 放入临时小组容器中
		groupScore.insert(make_pair(avg, *it));//key是得分，value是具体选手编号
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次:" << endl;
			//取走前三名放入
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
				cout << "编号:" << it->second << " 姓名:" << this->m_Speaker[it->second].m_Name
					<< " 成绩:" << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
			cout << endl;
			groupScore.clear();
		}
	}
	cout << "-----第<<" << this->m_Index << ">>轮比赛完毕-----" << endl;
	system("pause");
}
//显示得分
void SpeedManager::showScore()
{
	cout << "-----第<<" << this->m_Index << ">>轮晋级选手信息如下:" << endl;
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
		cout << "选手编号:" << *it
			<< "姓名:" << this->m_Speaker[*it].m_Name
			<< "得分:" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");

}
//保存记录
void SpeedManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用追加的方式写文件

	//将每个选手数据 写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录保存完毕" << endl;
	//有记录了，文件不为空
	this->fileIsEmpty = false;
}
//读取记录
void SpeedManager::loadRecord()
{
	ifstream ifs("speech.csv",ios::in);//读文件
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);//将上面读取的单个字符 放回来
	int index = 0;
	string data;
	while (ifs >> data)
	{
		vector<string> v;
		//cout << data << endl;
		int pos = -1;//查到逗号位置变量
		int start = 0;//查找起始位置
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//没有找到
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
		cout << it->first << "冠军编号:" << it->second[0] << "分数:" << it->second[1] << endl;
	}
}

//显示往届记录
void SpeedManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在，或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届 " <<
				"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
				"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
				"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}
//清空记录
void SpeedManager::clearRecord()
{
	cout << "是否确定清空文件" << endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//确认清空
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//初始化容器和属性
		this->initSpeech();
		//创建选手
		this->createSpeaker();
		//加载数据
		this->loadRecord();
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
//析构函数
SpeedManager::~SpeedManager()
{

}