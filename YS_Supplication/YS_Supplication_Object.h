#include <iostream>
#include <time.h>
using namespace std;

namespace ysc
{
	//enum YSSO_LX
	//{
	//	juese = 0,
	//	wuqi = 1
	//};

	//enum YSSO_MC
	//{
	//	
	//};

	//enum YSSO_XJ
	//{
	//	sanxing = 0,
	//	sixing = 1,
	//	wuxing = 2
	//};

	////float YSSO_GL[3] = { 0.943f,0.051f,0.006f };

	//struct YSSO_S
	//{
	//	int length = 13;
	//	//const int Klasa = 0;
	//	YSSO_LX lxList[13] = { wuqi ,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi };
	//	string mcList[13] = { 
	//		"弹弓",
	//		"神射手之誓",
	//		"鸦羽弓",
	//		"翡玉法球",
	//		"讨龙英杰谭",
	//		"魔导绪论",
	//		"黑缨枪",
	//		"以理服人",
	//		"沐浴龙血的剑",
	//		"铁影阔剑",
	//		"飞天御剑",
	//		"黎明神剑",
	//		"冷刃" 
	//	};
	//	//float gl = YSSO_GL[0];
	//};

	//struct SupplicationObject
	//{
	//	YSSO_LX Klass;
	//	string Name;//YSSO_MC Name;
	//	YSSO_XJ Star;
	//	SupplicationObject(YSSO_LX klass, string name, YSSO_XJ star):Klass(klass),Name(name),Star(star){}
	//};
	/*SupplicationObject OBJLib[3]={
		{juese,"KeQing",wuxing},
		{juese,"MoNa",wuxing},
		{juese,"QiQi",wuxing}
	};*/


	enum YS_Supplication_Object_Type
	{
		Arms = 0,
		Role = 1
	};
	enum YS_Supplication_Object_Rank
	{
		ThrStar = 0,
		FouStar = 1,
		FivStar = 2
	};

	struct YSSO_OBJ
	{
		YS_Supplication_Object_Type type;
		YS_Supplication_Object_Rank rank;
		string name;
		
		string path;

	};

	
	class YS_Supplication_TypeItems
	{
	public:
		YS_Supplication_TypeItems() {}
		~YS_Supplication_TypeItems() {}
	public:
		YS_Supplication_Object_Type type;


	};

	class YS_Supplication_RankPool
	{
	public:
		YS_Supplication_RankPool() {}
		~YS_Supplication_RankPool() {}

	public:
		YS_Supplication_Object_Rank rank;

		YS_Supplication_TypeItems armsItems;
		YS_Supplication_TypeItems roleItems;
	};

	class YS_Supplication_ItemPool
	{
	public:
		YS_Supplication_ItemPool() {}
		~YS_Supplication_ItemPool() {}

	public:
		YS_Supplication_RankPool thrStarPool;
		YS_Supplication_RankPool fouStarPool;
		YS_Supplication_RankPool fivStarPool;
	};

	class YS_Supplication_Object
	{

	};
	//struct YS_Supplication_Item
	//{
	//	string name;
	//	//string path;
	//}ThrItems[13] = { {"弹弓"},{"神射手之誓"},{"鸦羽弓"},{"翡玉法球"},{"讨龙英杰谭"},{"魔导绪论"},{"黑缨枪"},{"以理服人"},{"沐浴龙血的剑"},{"铁影阔剑"},{"飞天御剑"},{"黎明神剑"},{"冷刃"} },
	//	FouItems[32] = { {"砂糖"},{"重云"},{"诺艾尔"},{"班尼特"},{"菲谢尔"},{"凝光"},{"行秋"},{"北斗"},{"香菱"},{"安柏"},{"雷泽"},{"凯亚"},{"芭芭拉"},{"丽莎"},{"弓藏"},{"祭礼弓"},{"绝弦"},{"西风猎弓"},{"昭心"},{"祭礼残章"},{"流浪乐章"},{"西风秘典"},{"西风长枪"},{"匣里灭辰"},{"雨裁"},{"祭礼大剑"},{"钟剑"},{"西风大剑"},{"匣里龙吟"},{"祭礼剑"},{"笛剑"},{"西风剑"} },
	//	FivItems[15] = { {"刻晴"},{"莫娜"},{"七七"},{"迪卢克"},{"琴"},{"阿莫斯之弓"},{"天空之翼"},{"四风原典"},{"天空之卷"},{"和璞鸢"},{"天空之脊"},{"狼的末路"},{"天空之傲"},{"天空之刃"},{"风鹰剑"} };

	struct YS_Supplication_StarItem
	{
		string type;
		string name;
	};
	//ThrStarItems[13] =
	//{ {"武器","弹弓"},{"武器","神射手之誓"},{"武器","鸦羽弓"},{"武器","翡玉法球"},{"武器","讨龙英杰谭"},{"武器","魔导绪论"},{"武器","黑缨枪"},{"武器","以理服人"},{"武器","沐浴龙血的剑"},{"武器","铁影阔剑"},{"武器","飞天御剑"},{"武器","黎明神剑"},{"武器","冷刃"} },
	//	FouStarItems[32] =
	//{ {"角色","砂糖"},{"角色","重云"},{"角色","诺艾尔"},{"角色","班尼特"},{"角色","菲谢尔"},{"角色","凝光"},{"角色","行秋"},{"角色","北斗"},{"角色","香菱"},{"角色","安柏"},{"角色","雷泽"},{"角色","凯亚"},{"角色","芭芭拉"},{"角色","丽莎"} ,{"武器","弓藏"},{"武器","祭礼弓"},{"武器","绝弦"},{"武器","西风猎弓"},{"武器","昭心"},{"武器","祭礼残章"},{"武器","流浪乐章"},{"武器","西风秘典"},{"武器","西风长枪"},{"武器","匣里灭辰"},{"武器","雨裁"},{"武器","祭礼大剑"},{"武器","钟剑"},{"武器","西风大剑"},{"武器","匣里龙吟"},{"武器","祭礼剑"},{"武器","笛剑"},{"武器","西风剑"} },
	//	FivStarItems[15] =
	//{ {"角色","刻晴"},{"角色","莫娜"},{"角色","七七"},{"角色","迪卢克"},{"角色","琴"},{"武器","阿莫斯之弓"},{"武器","天空之翼"},{"武器","四风原典"},{"武器","天空之卷"},{"武器","和璞鸢"},{"武器","天空之脊"},{"武器","狼的末路"},{"武器","天空之傲"},{"武器","天空之刃"},{"武器","风鹰剑"} }
	//;

	struct YS_Supplication_ThrStarArmsItem
	{

	};
	struct YS_Supplication_ThrStarItemPool
	{
		YS_Supplication_ThrStarArmsItem arms;
	};

	struct YS_Supplication_PermanentItemPool
	{
		//YS_Supplication_ThrStarItemPool thr;
		YS_Supplication_StarItem ThrStarItems[13] ={ {"武器","弹弓"},{"武器","神射手之誓"},{"武器","鸦羽弓"},{"武器","翡玉法球"},{"武器","讨龙英杰谭"},{"武器","魔导绪论"},{"武器","黑缨枪"},{"武器","以理服人"},{"武器","沐浴龙血的剑"},{"武器","铁影阔剑"},{"武器","飞天御剑"},{"武器","黎明神剑"},{"武器","冷刃"} };
		YS_Supplication_StarItem FouStarItems[32] ={ {"角色","砂糖"},{"角色","重云"},{"角色","诺艾尔"},{"角色","班尼特"},{"角色","菲谢尔"},{"角色","凝光"},{"角色","行秋"},{"角色","北斗"},{"角色","香菱"},{"角色","安柏"},{"角色","雷泽"},{"角色","凯亚"},{"角色","芭芭拉"},{"角色","丽莎"} ,{"武器","弓藏"},{"武器","祭礼弓"},{"武器","绝弦"},{"武器","西风猎弓"},{"武器","昭心"},{"武器","祭礼残章"},{"武器","流浪乐章"},{"武器","西风秘典"},{"武器","西风长枪"},{"武器","匣里灭辰"},{"武器","雨裁"},{"武器","祭礼大剑"},{"武器","钟剑"},{"武器","西风大剑"},{"武器","匣里龙吟"},{"武器","祭礼剑"},{"武器","笛剑"},{"武器","西风剑"} };
		YS_Supplication_StarItem FivStarItems[15] ={ {"角色","刻晴"},{"角色","莫娜"},{"角色","七七"},{"角色","迪卢克"},{"角色","琴"},{"武器","阿莫斯之弓"},{"武器","天空之翼"},{"武器","四风原典"},{"武器","天空之卷"},{"武器","和璞鸢"},{"武器","天空之脊"},{"武器","狼的末路"},{"武器","天空之傲"},{"武器","天空之刃"},{"武器","风鹰剑"} };
	};

	class ProbabilityList
	{
	public:
		ProbabilityList() :ProbabilityList(3, new float[3]{ 0.943f,0.051f,0.006f }) { srand(time(NULL)); }

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
				listOfProbability[tmp_i] = ((int)(10000.0f / number)) % 10001;
				sum += listOfProbability[tmp_i];

			}
		}
		ProbabilityList(int number, float *list) :numberOfTypes(number)
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
}
