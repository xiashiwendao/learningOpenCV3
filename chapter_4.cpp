#include <opencv.hpp>
#include "chapter_4.h"

using namespace cv;
using namespace std;

void main(int agrc, char** argv) {
	draw_rec_answer();
}

void chapter_4() {
	Mat mat = Mat::eye(4, 4, CV_64F);
	cout << mat;
	mat.setTo(Scalar(1.0f, 0.0f, 1.0f));
}

void draw_rec() {
	Mat mat = Mat::zeros(100, 100, CV_8UC3);
	Mat part = mat(Rect(20, 5, 20, 15));
	int y1 = 20;
	int y2 = 5;
	for (int xi = 20; xi <= 40; xi++) {
		mat.at<Vec3b>(xi, y1)[1] = 255;
		mat.at<Vec3b>(xi, y2)[1] = 255;
	}

	int x1 = 20;
	int x2 = 40;
	for (int yi = 5; yi <= 20; yi++) {
		mat.at<Vec3b>(x1, yi)[1] = 255;
		mat.at<Vec3b>(x2, yi)[1] = 255;
	}

	namedWindow("show mat");
	imshow("show mat", mat);

	waitKey(0);
}

void draw_rec_answer() {
	Mat m2 = Mat(100, 100, CV_8UC3, Scalar(0));
	for (int i = 0; i<m2.rows; i++)
	{
		for (int j = 0; j<m2.cols; j++)
		{
			if (j >= 20 && j <= 40 && i >= 5 && i <= 20)
			{
				m2.at<Vec3b>(i, j)[0] = 0;    //b
				m2.at<Vec3b>(i, j)[1] = 255;  //g
				m2.at<Vec3b>(i, j)[2] = 0;    //r
			}
		}
	}
	cv::imshow("execrise 2", m2);
	waitKey(0);
}

void draw_pry(){
	Mat mat = Mat::zeros(210, 210, CV_8UC3);
}