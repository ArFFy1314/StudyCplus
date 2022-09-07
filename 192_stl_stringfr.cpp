//## string���Һ��滻
//**����������**
//* ���ң�����ָ���ַ����Ƿ����
//* �滻����ָ����λ���滻�ַ���
//**����ԭ�ͣ�**
//* int find(const string& str, int pos = 0) const;               //����str��һ�γ���λ��,��pos��ʼ����
//* int find(const char* s, int pos = 0) const;                      //����s��һ�γ���λ��,��pos��ʼ����
//* int find(const char* s, int pos, int n) const;                //��posλ�ò���s��ǰn���ַ���һ��λ��
//* int find(const char c, int pos = 0) const;                        //�����ַ�c��һ�γ���λ��
//* int rfind(const string& str, int pos = npos) const;       //����str���һ��λ��,��pos��ʼ����
//* int rfind(const char* s, int pos = npos) const;               //����s���һ�γ���λ��,��pos��ʼ����
//* int rfind(const char* s, int pos, int n) const;               //��pos����s��ǰn���ַ����һ��λ��
//* int rfind(const char c, int pos = 0) const;                        //�����ַ�c���һ�γ���λ��
//* string& replace(int pos, int n, const string& str);        //�滻��pos��ʼn���ַ�Ϊ�ַ���str
//* string& replace(int pos, int n, const char* s);                  //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
//
//�ܽ᣺
//* find�����Ǵ�������rfind��������
//* find�ҵ��ַ����󷵻ز��ҵĵ�һ���ַ�λ�ã��Ҳ������� - 1
//* replace���滻ʱ��Ҫָ�����ĸ�λ���𣬶��ٸ��ַ����滻��ʲô�����ַ���

#include<iostream>
#include<string>
using namespace std;
//1.����
void test01()
{
	string str1 = "abcdefgde";
	int pos=str1.find("de");
	if (pos == -1)
	{
		cout << "δ�ҵ��ַ���" << endl;
	}
	else
	{
		cout << "�ҵ��ַ�����de=" << pos << endl;
	}

	//rfind 
	pos=str1.rfind("de");
	cout << "�ҵ��ַ�����de=" << pos << endl;
}
//2.�滻
void test02()
{
	string str1 = "abvdef";
	str1.replace(1, 3, "11");
	//str1.replace(1, 3, "1111");
	//��һ��λ�����滻
	cout << "str1=" << str1 << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}