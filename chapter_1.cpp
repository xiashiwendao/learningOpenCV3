#include <iostream>
#include <ctype.h>
#include <opencv.hpp>
#include "chapter1.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	//test();
	//test_2();
	Matx<double, 3, 3> mat = cv::Matx33d::ones();
	Matx<float, 3, 1> vec = Vec3f::ones();
	Matx<float, 3, 3> temp = mat.mul(temp);
	cout << "c++ output"<<endl;
	cout << "c++ output\n";
}

void test_2() {
	Mat img_src, img_gray, img_canny;
	img_src = imread("C:\\Users\\python_gay\\Pictures\\download.jpg");
	namedWindow("img_src", WINDOW_AUTOSIZE);
	namedWindow("img_gray", WINDOW_AUTOSIZE);
	namedWindow("img_canny", WINDOW_AUTOSIZE);
	imshow("img_src", img_src);
	cvtColor(img_src, img_gray, COLOR_BGR2GRAY);
	imshow("img_gray", img_gray);
	Canny(img_gray, img_canny, 10, 100, 3, true);
	imshow("img_canny", img_canny);

	waitKey(0);
}

void test() {
	Mat img_src, img_down;
	img_src = imread("C:\\Users\\python_gay\\Pictures\\download.jpg");
	namedWindow("pic", WINDOW_AUTOSIZE);
	namedWindow("pic_down", WINDOW_AUTOSIZE);
	imshow("pic", img_src);
	pyrDown(img_src, img_down);
	imshow("pic_down", img_down);
	waitKey(0);
	destroyAllWindows();
}
