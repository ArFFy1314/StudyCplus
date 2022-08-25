//��̬ ������װ
//������Ҫ��ɲ���Ϊ CPU�����ڼ��㣩���Կ���������ʾ�����ڴ��������ڴ洢��
//��ÿ�������װ��������࣬�����ṩ��ͬ�ĳ���������ͬ�����������Intel���̺�Lenovo����
//�����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿ�
//����ʱ��װ��̨��ͬ�ĵ��Խ��й���
#include<iostream>
using namespace std;

//����ͬ�����
//����cpu��
class CPU
{
public:
	//����ļ��㺯��
	virtual void calculate() = 0;
};
//�����Կ���
class VideoCard
{
public:
	//�������ʾ����
	virtual void display() = 0;
};
//�����ڴ�����
class Memory
{
public:
	//����Ĵ洢����
	virtual void storage() = 0;
};

//������
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//�ṩ�����ĺ���
	void work()
	{
		//�������������
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//�ṩ��������
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
		cout << "Intel ����" << endl;
	}
};

class IntelVideoCard : public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel ��ʾ" << endl;
	}
};

class IntelMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel �洢" << endl;
	}
};

//Lenovo
class LenovoCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo ����" << endl;
	}
};

class LenovoVideoCard : public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo ��ʾ" << endl;
	}
};

class LenovoMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo �洢" << endl;
	}
};
void test01()
{
	//������һ̨���Ե����
	CPU* IntelCpu = new IntelCPU;
	VideoCard* IntelCard = new IntelVideoCard;
	Memory* IntelMem = new IntelMemory;

	//������һ̨����
	Computer* computer1 = new Computer(IntelCpu, IntelCard, IntelMem);
	computer1->work();
	delete computer1;

	//�����ڶ�̨����
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
