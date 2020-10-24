#include <iostream>
#include<opencv2/opencv.hpp>

#include "YS_Supplication_Class.h"

using namespace std;
using namespace cv;

using namespace ysc;

int main()
{
	YS_Supplication_Class ck;
	ck.init();

	cout << "System Init" << endl;

	while (ck.isRunning())
	{
		
		ck.checkTask();
		//if (ck.)
		ck.runTask();
		ck.show();

		waitKey(30);
	}

	return 0;
}