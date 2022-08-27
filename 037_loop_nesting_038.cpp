//嵌套循环
//在循环体中再嵌套一层循环，解决一些实际问题
//
//例如我们想在屏幕中打印如下图片，就需要利用嵌套循环
//乘法口诀表
#include<iostream>
using namespace std;
int main() {
	for (int i = 1; i <10; i++)
	{
		for (int j = 1; j <= i; j++) {
			cout << j << "×" << i << "=" << j*i << "\t";//输出的时候，是显示出1×1=1这种格式，而不是简单的一个积
		}
		cout << endl;
	}
	system("pause");
	return 0;
}