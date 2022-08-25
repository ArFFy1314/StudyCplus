//多态 电脑组装
//电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）
//将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商
//创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
//测试时组装三台不同的电脑进行工作
#include<iostream>
using namespace std;

//抽象不同零件类
//抽象cpu类
class CPU
{
public:
	//抽象的计算函数
	virtual void calculate() = 0;
};
//抽象显卡类
class VideoCard
{
public:
	//抽象的显示函数
	virtual void display() = 0;
};
//抽象内存条类
class Memory
{
public:
	//抽象的存储函数
	virtual void storage() = 0;
};

//电脑类
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//提供工作的函数
	void work()
	{
		//让零件工作起来
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//提供析构函数
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};
//Intel
class IntelCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel 运行" << endl;
	}
};

class IntelVideoCard : public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel 显示" << endl;
	}
};

class IntelMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel 存储" << endl;
	}
};

//Lenovo
class LenovoCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo 运行" << endl;
	}
};

class LenovoVideoCard : public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo 显示" << endl;
	}
};

class LenovoMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo 存储" << endl;
	}
};
void test01()
{
	//创建第一台电脑的零件
	CPU* IntelCpu = new IntelCPU;
	VideoCard* IntelCard = new IntelVideoCard;
	Memory* IntelMem = new IntelMemory;

	//创建第一台电脑
	Computer* computer1 = new Computer(IntelCpu, IntelCard, IntelMem);
	computer1->work();
	delete computer1;

	//创建第二台电脑
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
