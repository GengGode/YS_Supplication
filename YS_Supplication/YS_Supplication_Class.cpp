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
	//tmpVid.open(".\\Res\\五星.mp4");
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
	//drawLable();
	//cout << mouseParam.x << " " << mouseParam.y << endl;
	imshow(mainName, mainDrawCDC);
}

/*  */
void ysc::YS_Supplication_Class::checkTask()
{
	int k = 0;
	p++;

	lis[p] = pL.getRandKlass();
	if (isTiggerFouStarSecurity())
	{
		cout << "触发四星保底" << endl;
		lis[p] = 1;
	}
	if (isTiggerFivStarSecurity())
	{
		cout << "触发五星保底" << endl;
		lis[p] = 2;
	}
	k = lis[p];

	switch (k)
	{
	case 0:
	{		cout << thrStarMp4 << endl;
	tmpVid.open(thrStarMp4);
	break;
	}
	case 1:
	{
		cout << fouStarMp4 << endl;
		tmpVid.open(fouStarMp4);
		break;
	}
	case 2:
	{
		cout << fivStarMp4 << endl;
		tmpVid.open(fivStarMp4);
		break;
	}
	default:
		tmpVid.open(thrStarMp4);
		break;
	}
	supplicationMode1Flag = true;

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
	//流星
	//物品
	//无总览
	if (supplicationMode1Flag==false || supplicationMode10Flag)
	{
		return;
	}
	else
	{
		supplicationMode1Flag = false;
		supplicationMode10Flag = false;
	}
	double t = 0;
	int dt = 0;
	VideoCapture vid;
	Mat img;
	vid = tmpVid;
	vid >> img;
	while (!img.empty())
	{
		t = (double)cv::getTickCount();
		imshow(mainName, mainDrawCDC);
		matToMainMat(img);
		vid >> img;
		dt = (int)(((double)cv::getTickCount() - t) / cv::getTickFrequency()*1000);
		if (dt<33)
		{
			if (dt > 0)
			{
				waitKey(33 - dt);
			}
		}
		//cout << mouseParam.x << " " << mouseParam.y << endl;
		if (mouseParam.leftflag)
		{
			//1400 860 -200 860 //1500 60 -100 60
			if (mouseParam.x > (width - 100) && mouseParam.y <  60)
			{
				waitKey(100);
				break;
			}
		}
		//waitKey()
	}
}

void ysc::YS_Supplication_Class::supplicationMode10()
{
	//流星
	//物品
	//总览
	if (supplicationMode1Flag || supplicationMode10Flag== false)
	{
		return;
	}
	else
	{
		supplicationMode1Flag = false;
		supplicationMode10Flag = false;
	}
}

void ysc::YS_Supplication_Class::drawLable()
{
	Mat tmp;
	tmpVid >> tmp;//mainDrawCDC;
	if (!tmp.empty())
	{
		matToMainMat(tmp);
	}
	
}

void ysc::YS_Supplication_Class::onMouseCallFunA(int event, int x, int y, int flags, void *param)
{
	MouseParam& par = *(MouseParam*)param;
	par.x = x;
	par.y = y;
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
	{
		par.leftflag = true;
		break;
	}
	case EVENT_LBUTTONUP:
	{
		par.leftflag = false;
		break;
	}
	default:
		break;
	}
}

void ysc::YS_Supplication_Class::exit()
{
	isRunningFlag = false;
}

void ysc::YS_Supplication_Class::matToMainMat(Mat img)
{
	if (img.size().width == mainDrawCDC.size().width&&img.size().height == mainDrawCDC.size().height)
	{
		mainDrawCDC = img;
	}
	else
	{
		resize(img, mainDrawCDC, mainDrawCDC.size());
	}
}

bool ysc::YS_Supplication_Class::isExistFouStar()
{
	if (p >= 10)
	{
		for (int i = p - 10; i < p; p++)
		{
			if (lis[i] == 1)
			{
				return true;
			}
		}
	}
	else
	{
		for (int i = 0; i < p; i++)
		{
			if (lis[i] == 1)
			{
				return true;
			}
		}
	}
	return false;
}

bool ysc::YS_Supplication_Class::isExistFivStar()
{
	if (p >= 90)
	{
		for (int i = p - 90; i < p; p++)
		{
			if (lis[i] == 2)
			{
				return true;
			}
		}
	}
	else
	{
		for (int i = 0; i < p; i++)
		{
			if (lis[i] == 2)
			{
				return true;
			}
		}
	}
	return false;
}

bool ysc::YS_Supplication_Class::isTiggerFouStarSecurity()
{
	if (existFouStar() >= 9)//if (isExistFouStar() == false)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

bool ysc::YS_Supplication_Class::isTiggerFivStarSecurity()
{
	if (existFivStar() >= 89)//if (isExistFivStar() == false)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

int ysc::YS_Supplication_Class::existFouStar()
{
	int res = 0;
		for (int i = p-1; i > 0; i--)
		{
			if (lis[i] >=1)
			{
				return res;
			}
			else
			{
				res++;
			}
		}
	return res;
}

int ysc::YS_Supplication_Class::existFivStar()
{
	int res = 0;
	for (int i = p - 1; i > 0; i--)
	{
		if (lis[i] >= 2)
		{
			return res;
		}
		else
		{
			res++;
		}
	}
	return res;
}
