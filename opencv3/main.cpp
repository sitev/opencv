#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
IplImage* frame = 0;

int main(int argc, char* argv[])
{
	char* filename = "test.avi";

	namedWindow("sitev.ru", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture(filename); // ������������� ������� ����� �� �����

	while (1) {
		frame = cvQueryFrame(capture); // �������� ��������� ����
		if (!frame) break;

		cvShowImage("sitev.ru", frame); // ���������� ����

		char c = waitKey(33);
		if (c == 27) break; // ������� �� ESC 
	}

	// ����������� �������
	cvReleaseCapture(&capture);
	cvDestroyWindow("sitev.ru");
	return 0;
}

