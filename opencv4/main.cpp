#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main(int argc, char* argv[])
{
	char* filename = "lena.jpg";
	IplImage* image = cvLoadImage(filename, 1);

	namedWindow("sitev.ru", CV_WINDOW_AUTOSIZE);
	namedWindow("ROI", CV_WINDOW_AUTOSIZE);

	// задаём ROI
	int x = 250;
	int y = 250;
	int w = 100;
	int h = 100;
	
	int add = 100; // добавочная величина 

	cvShowImage("sitev.ru", image);
	cvSetImageROI(image, cvRect(x, y, w, h)); // устанавливаем ROI
	cvAddS(image, cvScalar(add), image); // добавить скалярную величину
	cvResetImageROI(image); // сбрасываем ROI
	cvShowImage("ROI", image); // показываем изображение

	waitKey(0);

	// освобождаем ресурсы
	cvReleaseImage(&image);
	cvDestroyAllWindows();
	return 0;
}

