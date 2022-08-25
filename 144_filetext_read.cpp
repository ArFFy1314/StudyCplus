//文件操作 文本文件 写
//文件可以将数据持久化
//文件流<fstream>
//文本文件 以文本的ASCII码形式存储在计算机中
//二进制文件 以文本的二进制性存储，用户一般看不懂
//操作文件的三大类：
//1.ofstream:写操作
//2.ifstream:读操作
//3.fstream:读写操作

//1.#include<fstream>	包含头文件
//2.ifstream ifs;		创建流对象
//3.ifs.open("文件路径",打开方式)	打开文件并判断是否成功
//4.四种方式读取
//5.ifs.close	关闭文件

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
		cout << "文件打开失败" << endl;
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