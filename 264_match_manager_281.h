#pragma
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"264_match_speaker_281.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<string>
#include<fstream>
//��ƹ����ݽ���
class SpeedManager
{
public:
	//���캯��
	SpeedManager();

	//�˵�����
	void show_Menu();

	//�˳�ϵͳ
	void exitSystem();

	//��������
	~SpeedManager();

	//��ʼ������������
	void initSpeech();

	//����12��ѡ��
	void createSpeaker();

	//��ʼ���� �������̿���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�÷�
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//��ʾ�����¼
	void showRecord();

	//��ռ�¼
	void clearRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>> m_Record;

	//�����һ�ֱ���ѡ�ֱ������
	vector<int> v1;
	//��һ�ֽ���ѡ�ֱ������
	vector<int> v2;
	//ʤ��ǰ����ѡ�ֱ������
	vector<int> vVictory;
	//��ű�ż���Ӧ����ѡ������
	map<int, Speaker> m_Speaker;
	//��ű�������
	int m_Index;
};