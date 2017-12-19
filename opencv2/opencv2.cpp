#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main(int argc, char** argv)
{
	int w = 600, h = 200; //размеры картинки
	Point pt = Point(100, 100); //точка, куда выводим

	IplImage* hw = cvCreateImage(cvSize(w, h), 8, 3); //создаём картинку
	cvSet(hw, cvScalar(0, 0, 0)); // заливаем чёрным цветом
	
	CvFont font;
	cvInitFont(&font, CV_FONT_HERSHEY_COMPLEX, 1.0, 1.0, 0, 1, CV_AA); // инициализируем шрифт
	cvPutText(hw, "OpenCV for sitev.ru", pt, &font, CV_RGB(255, 0, 0)); // выводим на картинку текст

	namedWindow("sitev.ru", WINDOW_AUTOSIZE); // создаём окошко
	cvShowImage("sitev.ru", hw); // выводим картинку в окошко
	waitKey(0); // ждём любую клавишу

	// освобождаем ресурсы
	cvReleaseImage(&hw);
	cvDestroyWindow("sitev.ru");
	return 0;
}

