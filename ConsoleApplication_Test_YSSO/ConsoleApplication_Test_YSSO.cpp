// ConsoleApplication_Test_YSSO.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include<cstdlib>
#include<time.h>
using namespace std;

struct YS_Supplication_StarItem
{
	string type;
	string name;
};

struct YS_Supplication_PermanentItemPool
{
	//YS_Supplication_ThrStarItemPool thr;
	YS_Supplication_StarItem ThrStarItems[13] = { {"武器","弹弓"},{"武器","神射手之誓"},{"武器","鸦羽弓"},{"武器","翡玉法球"},{"武器","讨龙英杰谭"},{"武器","魔导绪论"},{"武器","黑缨枪"},{"武器","以理服人"},{"武器","沐浴龙血的剑"},{"武器","铁影阔剑"},{"武器","飞天御剑"},{"武器","黎明神剑"},{"武器","冷刃"} };
	YS_Supplication_StarItem FouStarItems[32] = { {"角色","砂糖"},{"角色","重云"},{"角色","诺艾尔"},{"角色","班尼特"},{"角色","菲谢尔"},{"角色","凝光"},{"角色","行秋"},{"角色","北斗"},{"角色","香菱"},{"角色","安柏"},{"角色","雷泽"},{"角色","凯亚"},{"角色","芭芭拉"},{"角色","丽莎"} ,{"武器","弓藏"},{"武器","祭礼弓"},{"武器","绝弦"},{"武器","西风猎弓"},{"武器","昭心"},{"武器","祭礼残章"},{"武器","流浪乐章"},{"武器","西风秘典"},{"武器","西风长枪"},{"武器","匣里灭辰"},{"武器","雨裁"},{"武器","祭礼大剑"},{"武器","钟剑"},{"武器","西风大剑"},{"武器","匣里龙吟"},{"武器","祭礼剑"},{"武器","笛剑"},{"武器","西风剑"} };
	YS_Supplication_StarItem FivStarItems[15] = { {"角色","刻晴"},{"角色","莫娜"},{"角色","七七"},{"角色","迪卢克"},{"角色","琴"},{"武器","阿莫斯之弓"},{"武器","天空之翼"},{"武器","四风原典"},{"武器","天空之卷"},{"武器","和璞鸢"},{"武器","天空之脊"},{"武器","狼的末路"},{"武器","天空之傲"},{"武器","天空之刃"},{"武器","风鹰剑"} };
};

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

void fun10()
{
	ProbabilityList pl, *nl;
	nl = new ProbabilityList[3]{ 13,32,15 };
	int len = 10;
	int re = 0, re2 = 0;
	for (int i = 0; i < len; i++)
	{
		re = pl.getRandKlass();
		re2 = nl[re].getRandKlass();
		cout << re << " " << re2 << endl;
		switch (re)
		{
		case 0:
		{
			cout << lis.ThrStarItems[re2].type << " " << lis.ThrStarItems[re2].name << endl;
			break;
		}
		case 1:
		{
			cout << lis.FouStarItems[re2].type << " " << lis.FouStarItems[re2].name << endl;
			break;
		}
		case 2:
		{
			cout << lis.FivStarItems[re2].type << " " << lis.FivStarItems[re2].name << endl;
			break;
		}
		default:
			break;
		}
		k[re]++;
	}
}
int main()
{
	int root = 1000;
	srand(time(NULL));
	ProbabilityList pl,*nl;
	nl = new ProbabilityList[3]{ 13,32,15};
	YS_Supplication_PermanentItemPool lis;
	string asd = "asdasd";
	int len = 10;
	int re = 0,re2=0;
	int k[3] = { 0 };
	for (int i = 0; i < len; i++)
	{
		re = pl.getRandKlass();
		re2 = nl[re].getRandKlass();
		cout << re <<" "<< re2<< endl;
		switch (re)
		{
		case 0:
		{
			cout <<lis.ThrStarItems[re2].type << " " << lis.ThrStarItems[re2].name << endl;
			break;
		}
		case 1:
		{
			cout << lis.FouStarItems[re2].type << " " << lis.FouStarItems[re2].name << endl;
			break;
		}
		case 2:
		{
			cout << lis.FivStarItems[re2].type << " " << lis.FivStarItems[re2].name << endl;
			break;
		}
		default:
			break;
		}
		k[re]++;
	}
	//cout <<pl.at(0) << " " << pl.at(1) << " " << pl.at(2) << endl;
	//cout << k[0]*1.0/ len << " " << k[1] * 1.0 / len <<" "<< k[2] * 1.0 / len << endl;
	cout << k[0] << " " << k[1]  << " " << k[2]  << endl;


}

