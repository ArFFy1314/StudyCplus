//continue
//**作用：**在 == 循环语句 == 中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环
//注意：continue并没有使整个循环终止，而break会跳出循环
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