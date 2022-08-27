//通讯录程序
//main.cpp
#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

//联系人结构
struct Person
{
	string m_Name; // 姓名
	int m_Sex; // 性别 1 male, 2 female
	int m_Age; // 年龄 between 0-200;
	string m_Phone; // 电话 length < 14
	string m_Addr; // 住址
};

//通讯录结构
struct AddressBooks
{
	struct Person personArray[MAX];
	int m_Size;
};

void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

void addPerson(AddressBooks* abs)
{
	//判断通讯录是否已满，如果满了就不能添加
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加" << endl;
		return;
	}

	//添加具体联系人
	// name
	string name;
	cout << "请输入姓名：" << endl;
	cin >> name;
	abs->personArray[abs->m_Size].m_Name = name;

	// sex
	cout << "请输入性别：" << endl;
	cout << "1 --- 男" << endl;
	cout << "2 --- 女" << endl;
	int sex = 0;
	while (true) {
		cin >> sex;
		if (sex == 1 || sex == 2) {
			abs->personArray[abs->m_Size].m_Sex = sex;
			break;
		}
		cout << "输入有误，请重新输入：" << endl;
	}

	// age
	int age = 0;
	cout << "请输入年龄：" << endl;
	cin >> age;
	abs->personArray[abs->m_Size].m_Age = age;

	//phone Number

	cout << "请输入联系电话：" << endl;
	string phone;
	cin >> phone;
	abs->personArray[abs->m_Size].m_Phone = phone;

	// address
	cout << "请输入家庭住址：" << endl;
	string address;
	cin >> address;
	abs->personArray[abs->m_Size].m_Addr = address;

	//update
	abs->m_Size++;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}

void showPerson(AddressBooks* abs) {
	if (abs->m_Size == 0) {
		cout << "通讯录中记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << ((abs->personArray[i].m_Sex == 1) ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在
int isExist(AddressBooks *abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i; // 返回数组下标编号
		}
	}
	return -1; // 不存在
}

//删除指定联系人
void deletePerson(AddressBooks *abs) {
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找指定联系人
void findPerson(AddressBooks *abs) {
	cout << "请输入您查找要的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << ((abs->personArray[ret].m_Sex == 1) ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//修改指定联系人信息
void modifyPerson(AddressBooks *abs) {
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		// age
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//phone Number

		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		// address
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void cleanPerson(AddressBooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

int main()
{
	// 创建通讯录结构体变量
	AddressBooks abs;
	abs.m_Size = 0;

	int select = 0;

	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1: // 1、添加联系人
			addPerson(&abs); // 利用地址传递，可以修改实参
			break;
		case 2: // 2、显示联系人
			showPerson(&abs);
			break;
		case 3: // 3、删除联系人
			deletePerson(&abs);
			break;
		case 4: // 4、查找联系人
			findPerson(&abs);
			break;
		case 5: // 5、修改联系人
			modifyPerson(&abs);
			break;
		case 6: // 6、清空联系人
			cleanPerson(&abs);
			break;
		case 0: // 0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause"); // 按任意键继续
	return 0;
}