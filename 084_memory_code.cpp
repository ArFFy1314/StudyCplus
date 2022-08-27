﻿//代码区
//C++程序在执行时，将内存大方向划分为**4个区域**
//
//-代码区：存放函数体的二进制代码，由操作系统进行管理的
//- 全局区：存放全局变量和静态变量以及常量
//- 栈区：由编译器自动分配释放, 存放函数的参数值, 局部变量等
//- 堆区：由程序员分配和释放, 若程序员不释放, 程序结束时由操作系统回收
//**内存四区意义：**
//
//不同区域存放的数据，赋予不同的生命周期, 给我们更大的灵活编程
//
//
//# 程序运行前
//
//​	在程序编译后，生成了exe可执行程序，**未执行该程序前**分为两个区域
//
//​	**代码区：**
//
//​		存放 CPU 执行的机器指令
//
//​		代码区是**共享**的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
//
//​		代码区是**只读**的，使其只读的原因是防止程序意外地修改了它的指令