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

		MouseParam(int _x,int _y):x(_x),y(_y){}
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
		void checkTask();
		void runTask();

	private:
		bool loadConfigure();
		void fullScreen();
		void supplicationMode1();
		void supplicationMode10();
		void drawLable();
		static void onMouseCallFunA(int event, int x, int y, int flags, void *param);

		void exit();
		 

	public:

	private:
		bool isRunningFlag = true;
		Mat mainDrawCDC;
		Scalar initializeColor = Scalar(125, 125, 125);
		char *mainName = (char*)"YS Supplication";

		unsigned int width = 0;
		unsigned int height = 0;

		MouseParam mouseParam= MouseParam(0, 0);

		VideoCapture tmpVid;
		
	};
}

