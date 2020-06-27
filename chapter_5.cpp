#include "chapter_5.h"
#include <opencv.hpp>

using namespace cv;
using namespace std;

void main(int argc, char** argv) {
	//build_pryd();
	//build_pryd_answer();
	build_header();
}

void build_pryd() {
	Mat mat = Mat::zeros(210, 210, CV_8UC1);
	Mat roi = mat(Rect(0, 0, 200, 10));
	roi.setTo(255);
	roi = mat(Rect(20, 10, 160, 10));
	roi.setTo(255);
	roi = mat(Rect(40, 20, 120, 10));
	roi.setTo(255);
	imshow("roi", mat);
	waitKey(0);
}

void build_pryd_answer() {
	Mat m4 = Mat(210, 210, CV_8U, Scalar(0));
	for (int i = 0; i<210 / 2; i = i + 10)
	{
		Mat roi = m4(cv::Rect(i, i, 210 - i * 2, 210 - i * 2));
		roi.setTo(i * 2);// roi = i*2;

	}
	cv::imshow("execrise 4", m4);
	waitKey(0);
}

void build_header() {
	Mat m5 = Mat(100, 100, CV_8U, Scalar(0));
	Mat roi1 = m5(Rect(5, 10, 20, 30));
	Mat roi2 = m5(Rect(50, 60, 20, 30));
	bitwise_not(roi1, roi1);
	bitwise_not(roi2, roi2);
	cv::imshow("execrise 5", m5);
	waitKey(0);
}