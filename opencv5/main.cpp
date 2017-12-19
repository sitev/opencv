#define _CRT_SECURE_NO_WARNINGS

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main(int argc, char* argv[])
{
	VideoCapture cap(0); //открыть камеру по-умолчанию

	if (cap.isOpened() == false) {
		cout << "Cannot open the video camera" << endl;
		cin.get(); 
		return -1;
	}

	double w = cap.get(CV_CAP_PROP_FRAME_WIDTH); //получить ширину кадра
	double h = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //получить высоту кадра

	cout << "Resolution of the video : " << w << " x " << h << endl;

	string window_name = "My Camera Feed";
	namedWindow(window_name); 

	while (true) {
		Mat frame;
		bool success = cap.read(frame); // читаем кадр
		if (success == false) {
			cout << "Video camera is disconnected" << endl;
			cin.get();
			break;
		}

		imshow(window_name, frame); // показать кадр

		if (waitKey(10) == 27) {
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}
	}

	return 0;
}

