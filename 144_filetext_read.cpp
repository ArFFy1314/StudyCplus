//�ļ����� �ı��ļ� д
//�ļ����Խ����ݳ־û�
//�ļ���<fstream>
//�ı��ļ� ���ı���ASCII����ʽ�洢�ڼ������
//�������ļ� ���ı��Ķ������Դ洢���û�һ�㿴����
//�����ļ��������ࣺ
//1.ofstream:д����
//2.ifstream:������
//3.fstream:��д����

//1.#include<fstream>	����ͷ�ļ�
//2.ifstream ifs;		����������
//3.ifs.open("�ļ�·��",�򿪷�ʽ)	���ļ����ж��Ƿ�ɹ�
//4.���ַ�ʽ��ȡ
//5.ifs.close	�ر��ļ�

#include<iostream>
using namespace std;
#include<fstream>
#include<string>
void test01()
{
	ifstream ifs;
	ifs.open("test.txt",ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//1.
	/*char buf[1024] = { 0 };
	while (ifs>>buf)
	{
		cout << buf << endl;
	}*/
	//2.
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}*/
	//3.
	/*string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}*/
	//4.
	char c;
	while ((c=ifs.get())!=EOF)//end of file
	{
		cout << c;
	}
	ifs.close();
}
int main()
{
	test01();
	system("pause");
	return 0;
}