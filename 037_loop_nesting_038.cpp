//Ƕ��ѭ��
//��ѭ��������Ƕ��һ��ѭ�������һЩʵ������
//
//��������������Ļ�д�ӡ����ͼƬ������Ҫ����Ƕ��ѭ��
//�˷��ھ���
#include<iostream>
using namespace std;
int main() {
	for (int i = 1; i <10; i++)
	{
		for (int j = 1; j <= i; j++) {
			cout << j << "��" << i << "=" << j*i << "\t";//�����ʱ������ʾ��1��1=1���ָ�ʽ�������Ǽ򵥵�һ����
		}
		cout << endl;
	}
	system("pause");
	return 0;
}