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
//2.ofstream ofs;		����������
//3.ofs.open("�ļ�·��",�򿪷�ʽ)	���ļ�
//4.ofs<<"д�������"<<'	д����
//5.ofs.close	�ر��ļ�

#include<iostream>
using namespace std;
#include<fstream>
void test01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;
	ofs.close();
}
int main()
{
	test01();
	system("pause");
	return 0;
}