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
//2.ofstream ofs;		创建流对象
//3.ofs.open("文件路径",打开方式)	打开文件
//4.ofs<<"写入的数据"<<'	写数据
//5.ofs.close	关闭文件

#include<iostream>
using namespace std;
#include<fstream>
void test01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
	ofs.close();
}
int main()
{
	test01();
	system("pause");
	return 0;
}