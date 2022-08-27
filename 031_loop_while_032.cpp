//while
//**作用：**满足循环条件，执行循环语句
//**语法：**` while (循环条件) { 循环语句 }`
//**解释：* *= = 只要循环条件的结果为真，就执行循环语句 ==
//> 注意：在执行循环语句时候，程序必须提供跳出循环的出口，否则出现死循环
//系统随机生成一个1到100之间的数字，玩家进行猜测，如果猜错，提示玩家数字过大或过小，如果猜对恭喜玩家胜利，并且退出游戏。
#include<iostream>
using namespace std;
#include<ctime>//time系统时间头文件
int main()
{
	//添加随机数种子,利用当前系统时间生成随机数，防止重复；
	srand((unsigned int)time(NULL));
	//1.系统生成随机数
	int num = rand() % 100 + 1;	//0-99随机数+1
	//cout << num << endl;
	//2.玩家进行猜测
	int val = 0;
	while (1)
	{
		cout << "请输入数据:" << endl;
		cin >> val;
		//3.判断玩家的猜测
		if (val > num)
			cout << "猜测过大" << endl;
		else if (val < num)
			cout << "猜测过小" << endl;
		else break;
		//猜对退出 猜错提示
	}
	cout << "猜对了" << endl;
	system("pause");
	return 0;
}