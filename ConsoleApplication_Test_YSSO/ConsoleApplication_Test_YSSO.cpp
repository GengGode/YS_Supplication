// ConsoleApplication_Test_YSSO.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
class ProbabilityList
{
public:
	ProbabilityList() :ProbabilityList(3, new float[3]{ 0.943f,0.051f,0.006f }) {}

	~ProbabilityList() 
	{
		delete[]listOfProbability;
	}
public:
	ProbabilityList(int number) :numberOfTypes(number)
	{
		sum = 0;
		listOfProbability = new int[numberOfTypes]();
		for (int tmp_i = 0; tmp_i < numberOfTypes; tmp_i++)
		{
			listOfProbability[tmp_i] = ((int)(  10000.0f/ number)) % 10001;
			sum += listOfProbability[tmp_i];
			
		}
	}
	ProbabilityList(int number, float *list):numberOfTypes(number)
	{
		sum = 0;
		listOfProbability = new int[numberOfTypes]();
		for (int tmp_i = 0; tmp_i < numberOfTypes; tmp_i++)
		{
			if (list[tmp_i] <= 0 || list[tmp_i] > 1)
			{
				throw("Probability cannot be less than zero and cannot be greater than one!");
			}
			listOfProbability[tmp_i] = ((int)(list[tmp_i] * 10000)) % 10001;
			sum += listOfProbability[tmp_i];
		}
		if (sum != 10000)
		{
			std::cout << "List Of Probability Sum Should Be Equal To 1! Now Sum As: " << sum << std::endl;
			throw("List Of Probability Sum Should Be Equal To 1!");
		}
	}
	float at(int n)
	{
		float res = 0;
		if (n < 0 || n >= numberOfTypes)
		{
			throw("Array element out of bounds!");
		}
		else
		{
			res = listOfProbability[n] / (1.0f*sum);
		}
		return res;
	}
	int* list()
	{
		int *res = new int[numberOfTypes]();
		for (int tmp_i = 0; tmp_i < numberOfTypes; tmp_i++)
		{
			res[tmp_i] = listOfProbability[tmp_i];
		}
		return res;
	}
	int getRandKlass()
	{
		int k = rand() % (sum + 1);//10001;
		int tmp_Section = 0;
		for (int tmp_i = 0; tmp_i < numberOfTypes; tmp_i++)
		{
			tmp_Section = tmp_Section + listOfProbability[tmp_i];
			if (k < tmp_Section)
			{
				//std::cout << k << tmp_Section << std::endl;
				return tmp_i;
			}
		}
		return 0;
	}
	int getKlass(int k)
	{
		k = k % (sum + 1);// 10001;
		int tmp_Section = 0;
		for (int tmp_i = 0; tmp_i < numberOfTypes; tmp_i++)
		{
			tmp_Section = tmp_Section + listOfProbability[tmp_i];
			if (k < tmp_Section)
			{
				//std::cout << k <<" "<< tmp_Section << std::endl;
				return tmp_i;
			}
		}
		return 0;
	}
private:
	int sum;
	int numberOfTypes;
	int *listOfProbability;
};
enum YSSO_LX
{
	juese = 0,
	wuqi = 1
};

enum YSSO_MC
{
	KeQing,
	MoNa,
	QiQi,
	DiLuKe,
	Qin,
	ShaTang,
	ZhongYun,
	NuoAiEr,
	BanNiTe,
	FeiXieEr,
	NingGuang,
	HangQiu,
	BeiDou,
	XiangLing,
	AnBai,
	LeiZe,
	KaiYa,
	BaBaLa,
	LiSha,
	AMoSiZhiGong,
	TianKongZhiYi,
	SiFengYuanDian,
	TianKongZhiJuan,
	HePuYuan,
	TianKongZhiJi,
	LangDeMoLu,
	TianKongZhiAo,
	TianKongZhiRen,
	FengYingJian,
	GongCang,
	JiLiGong,
	JueXian,
	XiFengLieGong,
	ZhaoXin,
	JiLiCanZhang,
	LiuLangLeZhang,
	XiFengMiDian,
	XiFengZhangQiang,
	XiaLiMieChen,
	YuCai,
	JiLiDaJian,
	ZhongJian,
	XiFengDaJian,
	XiaLiLongYin,
	JiLiJian,
	DiJian,
	XiFengJian,
	DanGong,
	ShenSheShouZhiShi,
	YaYuGong,
	FeiYuFaQiu,
	TaoLongYingJieTan,
	MoDaoXuLun,
	HeiYingQiang,
	YiLiFuRen,
	MuYuLongXueDeJian,
	TieYingKuoJian,
	FeiTianYuJian,
	LiMingShenJian,
	LengRen

};

enum YSSO_XJ
{
	sanxing = 0,
	sixing = 1,
	wuxing = 2
};

struct YSSO_OBJ
{
	YSSO_LX Klass;
	YSSO_MC Name;//YSSO_MC Name;
	YSSO_XJ Star;
	YSSO_OBJ() {}
	YSSO_OBJ(YSSO_LX lx, YSSO_MC mc, YSSO_XJ xj):Klass(lx),Name(mc),Star(xj) {}
};
struct YSL
{
	YSSO_OBJ KQ = YSSO_OBJ(juese, KeQing, wuxing );
	YSSO_OBJ MN = YSSO_OBJ(juese, MoNa, wuxing );

};

class YSSO
{
public:
	YSSO() {}
	~YSSO() {}
public:
	YSSO_OBJ getOBJ()
	{
		YSSO_OBJ res;
		res.Star=YSSO_XJ(PL.getRandKlass());

	}
private:
	ProbabilityList PL;
};

//struct ProbabilityList
//{
//	int numberOfTypes;
//	float *listOfProbability;
//	ProbabilityList() :ProbabilityList(3, new float[3]{ 0.943,0.051,0.006 }) {}
//	ProbabilityList(int number)
//	{
//		float sum = 0;
//		numberOfTypes = number;
//		listOfProbability = new float[numberOfTypes]();
//		for (int tmp_i = 0; tmp_i < numberOfTypes; tmp_i++)
//		{
//			listOfProbability[tmp_i] = 1.0f / number;
//			sum += listOfProbability[tmp_i];
//		}
//		if (sum != 1)
//		{
//			std::cout << "List Of Probability Sum Should Be Equal To 1! Now Sum As: "<<sum << std::endl;
//			throw("List Of Probability Sum Should Be Equal To 1!");
//		}
//	}
//	ProbabilityList(int number,float *list)
//	{
//		float sum = 0;
//		numberOfTypes = number;
//		listOfProbability = new float[numberOfTypes]();
//		for (int tmp_i = 0; tmp_i < numberOfTypes; tmp_i++)
//		{
//			listOfProbability[tmp_i] = list[tmp_i];
//			sum += listOfProbability[tmp_i];
//		}
//		if (sum != 1)
//		{
//			std::cout << "List Of Probability Sum Should Be Equal To 1! Now Sum As: "<<sum << std::endl;
//			throw("List Of Probability Sum Should Be Equal To 1!");
//		}
//	}
//	~ProbabilityList()
//	{
//		delete []listOfProbability;
//	}
//};

int fun(int k)
{
	int list[3] = { 9430,510,60 };
	int tmp_Section = 0;
	for (int tmp_i = 0; tmp_i < 3; tmp_i++)
	{
		tmp_Section = tmp_Section + list[tmp_i];
		if (k < tmp_Section)
		{
			std::cout << k <<" "<< tmp_Section << std::endl;
			return tmp_i;
		}
	}
	return 0;
}
int main()
{
	int root = 1000;
	srand(time(NULL));
	ProbabilityList pl,*nl;
	nl = new ProbabilityList[3]{ 13,32,15};


	int len = 10;
	int re = 0;
	int k[3] = { 0 };
	for (int i = 0; i < len; i++)
	{
		re = pl.getRandKlass();
		cout << re <<" "<< nl[re].getRandKlass()<< endl;
		k[re]++;
	}
	//cout <<pl.at(0) << " " << pl.at(1) << " " << pl.at(2) << endl;
	//cout << k[0]*1.0/ len << " " << k[1] * 1.0 / len <<" "<< k[2] * 1.0 / len << endl;
	cout << k[0] << " " << k[1]  << " " << k[2]  << endl;


}

