#include <iostream>
#include <Windows.h>
#include <opencv2/opencv.hpp>

#include "YS_Supplication_Object.h"
using namespace ysc;
using namespace std;
using namespace cv;

namespace ysc
{
	BOOL CALLBACK EnumWindowsProc_0(HWND hWnd, LPARAM IProgress);
	void SetDesktop(char FormName[]);

	struct MouseParam
	{
		int x;
		int y;
		bool leftflag = false;
		MouseParam(int _x, int _y) :x(_x), y(_y) {}
	};

	//class YS_Supplication_Obj {};

	class YS_Supplication_Class
	{
	public:
		YS_Supplication_Class() {}
		~YS_Supplication_Class() {}
	public:
		void init();
		bool isRunning() const;
		void show();
		void getCheckTask();
		void runTask();

	private:
		bool loadConfigure();
		void fullScreen();
		void supplicationMode1();
		void supplicationMode10();
		void drawLable();
		static void onMouseCallFunA(int event, int x, int y, int flags, void *param);

		void exit();
	private:
		void matToMainMat(Mat img);
		bool isExistFouStar();
		bool isExistFivStar();
		bool isTiggerFouStarSecurity();
		bool isTiggerFivStarSecurity();
		int existFouStar();
		int existFivStar();
	public:

	private:
		bool isRunningFlag = true;

		bool supplicationMode1Flag = false;
		bool supplicationMode10Flag = false;

		ProbabilityList pL;
		ProbabilityList *pLn;
		

		Mat mainDrawCDC;
		Scalar initializeColor = Scalar(125, 125, 125);
		char *mainName = (char*)"YS Supplication";

		unsigned int width = 0;
		unsigned int height = 0;

		MouseParam mouseParam = MouseParam(0, 0);

		VideoCapture tmpVid;

		int lis[100] = { -1 };
		int lis2[100] = { -1 };
		int p = 0;

		string starsMp4[3] = { ".\\Res\\����.mp4" , ".\\Res\\����.mp4" , ".\\Res\\����.mp4" };
		YS_Supplication_PermanentItemPool itemsMp4;

	};
}

