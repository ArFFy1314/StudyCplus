#include<iostream>
using namespace std;
#include"264_match_manager_281.h"
#include<string>
#include<ctime>
int main()
{
	//���������
	srand((unsigned int)time(NULL));

	//�������������
	SpeedManager sm;
	
	////���Դ���ѡ��
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "ѡ�ֱ��:" << it->first
	//		<< "����:" << it->second.m_Name
	//		<< "�ɼ�:" << it->second.m_Score[0] << endl;
	//}

	int choice = 0;//���ڴ洢�û�����
	while (true)
	{
		sm.show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴�����¼
			sm.showRecord();
			break;
		case 3://��ձ�����¼
			sm.clearRecord();
			break;
		case 0://�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("pause");//����
			break;
		}
	}
	system("pause");
	return 0;
}