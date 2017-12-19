#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main(int argc, char** argv)
{
	int w = 600, h = 200; //������� ��������
	Point pt = Point(100, 100); //�����, ���� �������

	IplImage* hw = cvCreateImage(cvSize(w, h), 8, 3); //������ ��������
	cvSet(hw, cvScalar(0, 0, 0)); // �������� ������ ������
	
	CvFont font;
	cvInitFont(&font, CV_FONT_HERSHEY_COMPLEX, 1.0, 1.0, 0, 1, CV_AA); // �������������� �����
	cvPutText(hw, "OpenCV for sitev.ru", pt, &font, CV_RGB(255, 0, 0)); // ������� �� �������� �����

	namedWindow("sitev.ru", WINDOW_AUTOSIZE); // ������ ������
	cvShowImage("sitev.ru", hw); // ������� �������� � ������
	waitKey(0); // ��� ����� �������

	// ����������� �������
	cvReleaseImage(&hw);
	cvDestroyWindow("sitev.ru");
	return 0;
}

