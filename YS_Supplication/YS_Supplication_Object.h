#include <iostream>
using namespace std;

namespace ysc
{
	enum YSSO_LX
	{
		juese = 0,
		wuqi = 1
	};

	enum YSSO_MC
	{
		
	};

	enum YSSO_XJ
	{
		sanxing = 0,
		sixing = 1,
		wuxing = 2
	};

	//float YSSO_GL[3] = { 0.943f,0.051f,0.006f };

	struct YSSO_S
	{
		int length = 13;
		//const int Klasa = 0;
		YSSO_LX lxList[13] = { wuqi ,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi,wuqi };
		string mcList[13] = { 
			"弹弓",
			"神射手之誓",
			"鸦羽弓",
			"翡玉法球",
			"讨龙英杰谭",
			"魔导绪论",
			"黑缨枪",
			"以理服人",
			"沐浴龙血的剑",
			"铁影阔剑",
			"飞天御剑",
			"黎明神剑",
			"冷刃" 
		};
		//float gl = YSSO_GL[0];
	};

	struct YSSO_OBJ
	{
		
	};

	struct SupplicationObject
	{
		YSSO_LX Klass;
		string Name;//YSSO_MC Name;
		YSSO_XJ Star;
		SupplicationObject(YSSO_LX klass, string name, YSSO_XJ star):Klass(klass),Name(name),Star(star){}
	};
	/*SupplicationObject OBJLib[3]={
		{juese,"KeQing",wuxing},
		{juese,"MoNa",wuxing},
		{juese,"QiQi",wuxing}
	};*/

	class YS_Supplication_Object
	{

	};

}