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
	//		"����",
	//		"������֮��",
	//		"ѻ��",
	//		"������",
	//		"����Ӣ��̷",
	//		"ħ������",
	//		"��ӧǹ",
	//		"�������",
	//		"��ԡ��Ѫ�Ľ�",
	//		"��Ӱ����",
	//		"��������",
	//		"������",
	//		"����" 
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
	//}ThrItems[13] = { {"����"},{"������֮��"},{"ѻ��"},{"������"},{"����Ӣ��̷"},{"ħ������"},{"��ӧǹ"},{"�������"},{"��ԡ��Ѫ�Ľ�"},{"��Ӱ����"},{"��������"},{"������"},{"����"} },
	//	FouItems[32] = { {"ɰ��"},{"����"},{"ŵ����"},{"������"},{"��л��"},{"����"},{"����"},{"����"},{"����"},{"����"},{"����"},{"����"},{"�Ű���"},{"��ɯ"},{"����"},{"����"},{"����"},{"�����Թ�"},{"����"},{"�������"},{"��������"},{"�����ص�"},{"���糤ǹ"},{"ϻ����"},{"���"},{"�����"},{"�ӽ�"},{"�����"},{"ϻ������"},{"����"},{"�ѽ�"},{"���罣"} },
	//	FivItems[15] = { {"����"},{"Ī��"},{"����"},{"��¬��"},{"��"},{"��Ī˹֮��"},{"���֮��"},{"�ķ�ԭ��"},{"���֮��"},{"����"},{"���֮��"},{"�ǵ�ĩ·"},{"���֮��"},{"���֮��"},{"��ӥ��"} };

	struct YS_Supplication_StarItem
	{
		string type;
		string name;
	};
	//ThrStarItems[13] =
	//{ {"����","����"},{"����","������֮��"},{"����","ѻ��"},{"����","������"},{"����","����Ӣ��̷"},{"����","ħ������"},{"����","��ӧǹ"},{"����","�������"},{"����","��ԡ��Ѫ�Ľ�"},{"����","��Ӱ����"},{"����","��������"},{"����","������"},{"����","����"} },
	//	FouStarItems[32] =
	//{ {"��ɫ","ɰ��"},{"��ɫ","����"},{"��ɫ","ŵ����"},{"��ɫ","������"},{"��ɫ","��л��"},{"��ɫ","����"},{"��ɫ","����"},{"��ɫ","����"},{"��ɫ","����"},{"��ɫ","����"},{"��ɫ","����"},{"��ɫ","����"},{"��ɫ","�Ű���"},{"��ɫ","��ɯ"} ,{"����","����"},{"����","����"},{"����","����"},{"����","�����Թ�"},{"����","����"},{"����","�������"},{"����","��������"},{"����","�����ص�"},{"����","���糤ǹ"},{"����","ϻ����"},{"����","���"},{"����","�����"},{"����","�ӽ�"},{"����","�����"},{"����","ϻ������"},{"����","����"},{"����","�ѽ�"},{"����","���罣"} },
	//	FivStarItems[15] =
	//{ {"��ɫ","����"},{"��ɫ","Ī��"},{"��ɫ","����"},{"��ɫ","��¬��"},{"��ɫ","��"},{"����","��Ī˹֮��"},{"����","���֮��"},{"����","�ķ�ԭ��"},{"����","���֮��"},{"����","����"},{"����","���֮��"},{"����","�ǵ�ĩ·"},{"����","���֮��"},{"����","���֮��"},{"����","��ӥ��"} }
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
		YS_Supplication_StarItem ThrStarItems[13] ={ {"����","����"},{"����","������֮��"},{"����","ѻ��"},{"����","������"},{"����","����Ӣ��̷"},{"����","ħ������"},{"����","��ӧǹ"},{"����","�������"},{"����","��ԡ��Ѫ�Ľ�"},{"����","��Ӱ����"},{"����","��������"},{"����","������"},{"����","����"} };
		YS_Supplication_StarItem FouStarItems[32] ={ {"��ɫ","ɰ��"},{"��ɫ","����"},{"��ɫ","ŵ����"},{"��ɫ","������"},{"��ɫ","��л��"},{"��ɫ","����"},{"��ɫ","����"},{"��ɫ","����"},{"��ɫ","����"},{"��ɫ","����"},{"��ɫ","����"},{"��ɫ","����"},{"��ɫ","�Ű���"},{"��ɫ","��ɯ"} ,{"����","����"},{"����","����"},{"����","����"},{"����","�����Թ�"},{"����","����"},{"����","�������"},{"����","��������"},{"����","�����ص�"},{"����","���糤ǹ"},{"����","ϻ����"},{"����","���"},{"����","�����"},{"����","�ӽ�"},{"����","�����"},{"����","ϻ������"},{"����","����"},{"����","�ѽ�"},{"����","���罣"} };
		YS_Supplication_StarItem FivStarItems[15] ={ {"��ɫ","����"},{"��ɫ","Ī��"},{"��ɫ","����"},{"��ɫ","��¬��"},{"��ɫ","��"},{"����","��Ī˹֮��"},{"����","���֮��"},{"����","�ķ�ԭ��"},{"����","���֮��"},{"����","����"},{"����","���֮��"},{"����","�ǵ�ĩ·"},{"����","���֮��"},{"����","���֮��"},{"����","��ӥ��"} };
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
