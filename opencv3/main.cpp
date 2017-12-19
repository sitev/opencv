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
	CvCapture* capture = cvCreateFileCapture(filename); // инициализация захвата видео из файла

	while (1) {
		frame = cvQueryFrame(capture); // получить очередной кадр
		if (!frame) break;

		cvShowImage("sitev.ru", frame); // показываем кадр

		char c = waitKey(33);
		if (c == 27) break; // выходим по ESC 
	}

	// освобождаем ресурсы
	cvReleaseCapture(&capture);
	cvDestroyWindow("sitev.ru");
	return 0;
}

