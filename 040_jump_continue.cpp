//continue
//**���ã�**�� == ѭ����� == �У���������ѭ����������δִ�е���䣬����ִ����һ��ѭ��
//ע�⣺continue��û��ʹ����ѭ����ֹ����break������ѭ��
#include<iostream>
using namespace std;
int main() 
{
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		cout << i << endl;
	}
	system("pause");
	return 0;
}