//ͨѶ¼����
//main.cpp
#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

//��ϵ�˽ṹ
struct Person
{
	string m_Name; // ����
	int m_Sex; // �Ա� 1 male, 2 female
	int m_Age; // ���� between 0-200;
	string m_Phone; // �绰 length < 14
	string m_Addr; // סַ
};

//ͨѶ¼�ṹ
struct AddressBooks
{
	struct Person personArray[MAX];
	int m_Size;
};

void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

void addPerson(AddressBooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}

	//��Ӿ�����ϵ��
	// name
	string name;
	cout << "������������" << endl;
	cin >> name;
	abs->personArray[abs->m_Size].m_Name = name;

	// sex
	cout << "�������Ա�" << endl;
	cout << "1 --- ��" << endl;
	cout << "2 --- Ů" << endl;
	int sex = 0;
	while (true) {
		cin >> sex;
		if (sex == 1 || sex == 2) {
			abs->personArray[abs->m_Size].m_Sex = sex;
			break;
		}
		cout << "�����������������룺" << endl;
	}

	// age
	int age = 0;
	cout << "���������䣺" << endl;
	cin >> age;
	abs->personArray[abs->m_Size].m_Age = age;

	//phone Number

	cout << "��������ϵ�绰��" << endl;
	string phone;
	cin >> phone;
	abs->personArray[abs->m_Size].m_Phone = phone;

	// address
	cout << "�������ͥסַ��" << endl;
	string address;
	cin >> address;
	abs->personArray[abs->m_Size].m_Addr = address;

	//update
	abs->m_Size++;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
}

void showPerson(AddressBooks* abs) {
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼�м�¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << ((abs->personArray[i].m_Sex == 1) ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ����
int isExist(AddressBooks *abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i; // ���������±���
		}
	}
	return -1; // ������
}

//ɾ��ָ����ϵ��
void deletePerson(AddressBooks *abs) {
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//����ָ����ϵ��
void findPerson(AddressBooks *abs) {
	cout << "������������Ҫ����ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << ((abs->personArray[ret].m_Sex == 1) ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//�޸�ָ����ϵ����Ϣ
void modifyPerson(AddressBooks *abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		// age
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//phone Number

		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		// address
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ��
void cleanPerson(AddressBooks* abs) {
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

int main()
{
	// ����ͨѶ¼�ṹ�����
	AddressBooks abs;
	abs.m_Size = 0;

	int select = 0;

	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1: // 1�������ϵ��
			addPerson(&abs); // ���õ�ַ���ݣ������޸�ʵ��
			break;
		case 2: // 2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: // 3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4: // 4��������ϵ��
			findPerson(&abs);
			break;
		case 5: // 5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: // 6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0: // 0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause"); // �����������
	return 0;
}