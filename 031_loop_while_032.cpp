//while
//**���ã�**����ѭ��������ִ��ѭ�����
//**�﷨��**` while (ѭ������) { ѭ����� }`
//**���ͣ�* *= = ֻҪѭ�������Ľ��Ϊ�棬��ִ��ѭ����� ==
//> ע�⣺��ִ��ѭ�����ʱ�򣬳�������ṩ����ѭ���ĳ��ڣ����������ѭ��
//ϵͳ�������һ��1��100֮������֣���ҽ��в²⣬����´�����ʾ������ֹ�����С������¶Թ�ϲ���ʤ���������˳���Ϸ��
#include<iostream>
using namespace std;
#include<ctime>//timeϵͳʱ��ͷ�ļ�
int main()
{
	//�������������,���õ�ǰϵͳʱ���������������ֹ�ظ���
	srand((unsigned int)time(NULL));
	//1.ϵͳ���������
	int num = rand() % 100 + 1;	//0-99�����+1
	//cout << num << endl;
	//2.��ҽ��в²�
	int val = 0;
	while (1)
	{
		cout << "����������:" << endl;
		cin >> val;
		//3.�ж���ҵĲ²�
		if (val > num)
			cout << "�²����" << endl;
		else if (val < num)
			cout << "�²��С" << endl;
		else break;
		//�¶��˳� �´���ʾ
	}
	cout << "�¶���" << endl;
	system("pause");
	return 0;
}