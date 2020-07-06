#include "chapter_5.h"
#include <opencv.hpp>

using namespace cv;
using namespace std;

void main(int argc, char** argv) {
	//build_pryd();
	//build_pryd_answer();
	//build_header();
	build_compare_and_split();
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
	//Mat m5 = Mat(100, 100, CV_8U, Scalar(0));
	Mat m5 = imread("imgs\\girl.jpg");
	Mat roi1 = m5(Rect(5, 10, 20, 30));
	Mat roi2 = m5(Rect(230, 60, 20, 30));
	bitwise_not(roi1, roi1);
	bitwise_not(roi2, roi2);
	cv::imshow("execrise 5", m5);
	waitKey(0);
}

void build_compare_and_split() {
	Mat pic = imread("imgs\\girl.jpg");
	Mat channels[3];
	split(pic, channels);

	/*imshow("Blue", channels[0]);
	imshow("Green", channels[1]);
	imshow("Red", channels[2]);
	waitKey(0);*/
	// get the green channel
	Mat green_channel = channels[1];
	//Mat green_channel_1 = repeat(green_channel, 1, 1);
	Mat green_channel_1 = green_channel.clone();
	//imshow("green_copy", green_channel_1);
	//waitKey(0);

	// get the min max value
	double minv, maxv;
	int idx_max[2], idx_min[2];
	minMaxIdx(green_channel, &minv, &maxv, idx_min, idx_max);
	
	cout << "min value: " << minv << endl;
	cout << "max value: " << maxv << endl;
	// batch set matrix value
	green_channel_1.setTo((maxv - minv) / 2);
	imshow("clone change value::1", green_channel_1);
	Mat green_channel_2 = green_channel.clone();
	green_channel_2.setTo(0);
	compare(green_channel, green_channel_1, green_channel_2, cv::CMP_GE);
	imshow("compare::2", green_channel_2);
	Mat green_channel_3 = green_channel.clone();
	green_channel_3.setTo(0);
	subtract(green_channel, green_channel_1, green_channel_3);
	imshow("subtract::thresh", green_channel_3);
	subtract(green_channel, (maxv-minv)/4, green_channel_3);
	imshow("subtract::thresh/2", green_channel_3);
	waitKey(0);
}