#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
IplImage* frame = 0;

int main(int argc, char* argv[])
{
	// ��� ����� ������� ������ ����������
	char* filename = argc == 2 ? argv[1] : "test.avi";

	printf("[i] file: %s\n", filename);

	// ���� ��� ����������� ��������
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);

	// �������� ���������� � �����-�����
	CvCapture* capture = cvCreateFileCapture(filename);

	while (1) {
		// �������� ��������� ����
		frame = cvQueryFrame(capture);
		if (!frame) {
			break;
		}

		// ����� ����� ��������
		// ��������� ���������

		// ���������� ����
		cvShowImage("original", frame);

		char c = cvWaitKey(33);
		if (c == 27) { // ���� ������ ESC - �������
			break;
		}
	}

	// ����������� �������
	cvReleaseCapture(&capture);
	// ������� ����
	cvDestroyWindow("original");
	return 0;
}

