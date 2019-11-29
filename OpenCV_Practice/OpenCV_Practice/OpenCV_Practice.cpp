#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main()
{
	bool switcher = false;
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		cerr << "카메라가 없어염" << endl;
		return -1;
	}
	Mat originalFrame;
	Mat cutFrame;
	int count = 0;
	int num = 490;
	while (true)
	{
		cap >> originalFrame;
		if (originalFrame.empty()) break;
		cutFrame = originalFrame(Rect(70, 70, 300, 300));
		rectangle(originalFrame, Rect(70, 70, 300, 300), Scalar(255, 255, 255), 2);
		imshow("skin", cutFrame);
		imshow("origin", originalFrame);
		count++;
		if (switcher == true)
		{
			if (count >= 25)
			{
				count = 0;
				cout << "HELLO" << num << endl;
				string filename = format("D:\\Datasets\\Handlays\\Hands%d.jpg", num);
				num++;
				imwrite(filename, cutFrame);
			}
		}

		int keycode = waitKey(5);

		if (keycode == 'a') // a키를 누르면
		{
			switcher = !switcher;
		}
		else if (keycode == 27) {
			break;
		}
	}
}

