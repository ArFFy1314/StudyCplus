//�ṹ������
//**���ã�**���Զ���Ľṹ����뵽�����з���ά��
//**�﷨��**` struct  �ṹ���� ������[Ԫ�ظ���] = { {} ,{} , ... {} }`
//�ṹ�嶨��
#include<iostream>
using namespace std;
#include<string>
struct student
{
	//��Ա�б�
	string name;  //����
	int age;      //����
	int score;    //����
}

int main() {

	//�ṹ������
	struct student arr[3] =
	{
		{ "����",18,80 },
		{ "����",19,60 },
		{ "����",20,70 }
	};

	for (int i = 0; i < 3; i++)
	{
		cout << "������" << arr[i].name << " ���䣺" << arr[i].age << " ������" << arr[i].score << endl;
	}
	system("pause");
	return 0;
}