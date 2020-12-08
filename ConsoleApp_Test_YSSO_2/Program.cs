using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp_Test_YSSO_2
{
    class Program
    {
        static void Main(string[] args)
        {
# include<iostream>
# include"time.h"
            using namespace std;
double fivestar = 0.006, fourstar = 0.051;
    double fivea(int c)
    {
        int b = 73;
        if (c < b)
            return fivestar;
        else
            return fivestar + (1 - fivestar) * (c - b) / (90 - b);

    }
    double foura(int c)
    {
        int b = 7;
        if (c < b)
            return fourstar;
        else
            return fourstar + (1 - fourstar) * (c - b) / (10 - b);
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
        }
    }
}
