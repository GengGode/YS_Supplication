// ConsoleApplication_Test_YSSO_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include"time.h"
using namespace std;
double fivestar = 0.006, fourstar = 0.051;
double fivea(int c)
{
	int b = 73;
	if (c < b)
		return fivestar;
	else
		return fivestar + (1 - fivestar)*(c - b) / (90 - b);

}
double foura(int c)
{
	int b = 7;
	if (c < b)
		return fourstar;
	else
		return fourstar + (1 - fourstar)*(c - b) / (10 - b);
}
void task1(int n)
{
	srand(time(0));
	int c4 = 0;
	int c5 = 0;
	int b4 = 0;
	int b5 = 0;
	for (int i = 0; i < n; i++)
	{
		b4++;
		b5++;
		double f5 = fivea(b5);
		double f4 = foura(b4);
		double r = (rand() % 1000) / 1000.0;
		if (r < f5)
		{
			c5++;
			b5 = 0;
			b4 = 0;
		}
		if (r >= f5 && r < (f5 + f4))
		{
			c4++;
			b4 = 0;
		}

	}
	cout << "实验次数为" << n << endl;
	cout << "5星个数" << c5 << endl;
	cout << "4星个数" << c4 << endl;
}
int main()
{
	task1(1000000);
	system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
