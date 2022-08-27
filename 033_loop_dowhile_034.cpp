//**作用：** 满足循环条件，执行循环语句
//**语法：** `do{ 循环语句 } while (循环条件); `
//**注意：**与while的区别在于 == do...while会先执行一次循环语句 == ，再判断循环条件
//总结：与while循环区别在于，do...while先执行一次循环语句，再判断循环条件
//**案例描述：**水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身
//
//例如：1 ^ 3 + 5 ^ 3 + 3 ^ 3 = 153
//
//请利用do...while语句，求出所有3位数中的水仙花数
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int number = 0;
	do
	{
		int a = 0;
		int b = 0;
		int c = 0;

		a = number % 10;//获取个位数
		b = number / 10 % 10;//获取十位数
		c = number / 100;//获取百位数
		double d = pow(a, 3) + pow(b, 3) + pow(c, 3);
		if (d == number)
		{
			cout << number << endl;
		}
		number++;
	} while (number < 1000);
	system("pause");
	return 0;
}
