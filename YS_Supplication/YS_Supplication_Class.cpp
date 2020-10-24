#include "YS_Supplication_Class.h"

BOOL CALLBACK ysc::EnumWindowsProc_0(HWND hWnd, LPARAM IProgress)
{
	if (::FindWindowEx(hWnd, NULL, "SHELLDLL_DefView", NULL) != NULL)
	{
		HWND tempHwnd = ::FindWindowEx(NULL, hWnd, "WorkerW", NULL);
		::ShowWindow(tempHwnd, 0);
	}
	return true;
}

void ysc::SetDesktop(char FormName[])
{
	//setWindowProperty(FormName, CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
	setWindowProperty(FormName, 0, 1);

	HWND hWnd = ::FindWindow("Progman", NULL);
	HWND my_hWnd = ::FindWindow(NULL, FormName);

	if (hWnd != NULL && my_hWnd != NULL)
	{
		MoveWindow(my_hWnd, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), true);
		SendMessageTimeout(hWnd, 0x52c, NULL, NULL, 0, 0x3e8, NULL);
		EnumWindows(EnumWindowsProc_0, NULL);
		SetParent(my_hWnd, hWnd);
	}
}

/* Nop Task. */
void ysc::YS_Supplication_Class::init()
{
	loadConfigure();
	tmpVid.open("C:\\Users\\GengG\\Videos\\OBS\\2020-10-22 18-34-07.mp4");
	mainDrawCDC = Mat(height,width, CV_8UC3);
	mainDrawCDC = initializeColor;
	namedWindow(mainName);
	setMouseCallback(mainName, onMouseCallFunA, (void*)&mouseParam);
	imshow(mainName, mainDrawCDC);
	fullScreen();
}

/* return isRunning Flag. */
bool ysc::YS_Supplication_Class::isRunning() const
{
	return isRunningFlag;
}

void ysc::YS_Supplication_Class::show()
{
	drawLable();
	cout << mouseParam.x << " " << mouseParam.y << endl;
	imshow(mainName, mainDrawCDC);
}

/*  */
void ysc::YS_Supplication_Class::checkTask()
{

}

void ysc::YS_Supplication_Class::runTask()
{
	supplicationMode1();
	supplicationMode10();

}

bool ysc::YS_Supplication_Class::loadConfigure()
{
	bool loadFileFlag = false;
	
	/* form .conf file load configure */
	//loadFileFlag = loadFile();
	/* *** */

	if (loadFileFlag)
	{
		width = 1600;
		height = 900;
		initializeColor = Scalar(0, 0, 0);
		return true;
	}
	else
	{
		width = 1600;
		height = 900;
		initializeColor = Scalar(0, 0, 0);
		return false;
	}
	return false;
}

void ysc::YS_Supplication_Class::fullScreen()
{
	setWindowProperty(mainName, 0, 1);

	//HWND my_hWnd = ::FindWindow(NULL, mainName);

	//MoveWindow(my_hWnd, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), true);

	//SetDesktop(mainName);

}

void ysc::YS_Supplication_Class::supplicationMode1()
{
}

void ysc::YS_Supplication_Class::supplicationMode10()
{
}

void ysc::YS_Supplication_Class::drawLable()
{
	Mat tmp;
	tmpVid >> tmp;//mainDrawCDC;
	if (!tmp.empty())
	{
		if (tmp.size().width == mainDrawCDC.size().width&&tmp.size().height == mainDrawCDC.size().height)
		{
			mainDrawCDC = tmp;
		}
		else
		{
			resize(tmp, mainDrawCDC, mainDrawCDC.size());
		}
		//resize(tmp, mainDrawCDC, mainDrawCDC.size());
	}
	
}

void ysc::YS_Supplication_Class::onMouseCallFunA(int event, int x, int y, int flags, void *param)
{
	MouseParam& par = *(MouseParam*)param;
	par.x = x;
	par.y = y;
}

void ysc::YS_Supplication_Class::exit()
{
	isRunningFlag = false;
}
