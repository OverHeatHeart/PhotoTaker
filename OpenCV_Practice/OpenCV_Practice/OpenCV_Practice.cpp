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
		cerr << "카메라 없음" << endl;
		return -1;
	}

	Mat originalFrame;
	Mat cutFrame;

	int count = 0;	//초를 셀 변수
	int num = 0;	//0번부터 파일 이름
	while (true)
	{
		cap >> originalFrame;
		if (originalFrame.empty()) break;
		cutFrame = originalFrame(Rect(70, 70, 300, 300));
		//해당 프레임에서 특정 영역을 뽑아냄
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
				//잘라낸 프레임을 저장함
				imwrite(filename, cutFrame);
			}
		}

		int keycode = waitKey(5);

		if (keycode == 'a')		// a키를 누르면
		{
			switcher = !switcher;
		}
		else if (keycode == 27)		//esc를 누르면
		{					
			break;
		}
	}
}

