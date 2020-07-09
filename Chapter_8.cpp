﻿#include "Chapter_8.h"
#include <opencv.hpp>
#include <iostream>
#include<stdio.h>

using namespace std;
using namespace cv;

std::vector<Point> points;



void exe_1() {
	VideoCapture cap;
	bool ret = cap.open("imgs\\class.avi");
	if (ret) {
		Mat frame, frame_resize, frame_gray, frame_canny, img_total;
		while (cap.read(frame)) {
			resize(frame, frame_resize, Size(frame.cols/3, frame.rows/3));

			cvtColor(frame_resize, frame_gray, COLOR_BGR2GRAY);
			Canny(frame_gray, frame_canny, 125, 125);

			img_total = Mat::zeros(frame_resize.rows, frame_resize.cols * 3, CV_8UC3);
			//Mat MatSub = img_total.colRange(0, frame_resize.cols);
			//frame_resize.copyTo(MatSub);
			Mat mat = img_total(Rect(0, 0, frame_resize.cols, frame_resize.rows));
			//mat.setTo(frame_resize.clone());
			frame_resize.copyTo(mat);
			//imshow("output_total", img_total);
			//waitKey(0);
			mat = img_total(Rect(frame_resize.cols, 0, frame_resize.cols, frame_resize.rows));
			Mat frame_gray_c3 = Mat::zeros(frame_resize.rows, frame_resize.cols, CV_8UC3);
			cvtColor(frame_gray, mat, COLOR_GRAY2BGR);
			mat = img_total(Rect(frame_resize.cols*2, 0, frame_resize.cols, frame_resize.rows));
			cvtColor(frame_canny, mat, COLOR_GRAY2BGR);
			

			Scalar color = CV_RGB(255, 0, 0);
			putText(img_total, "raw img", Point(50, 30), FONT_HERSHEY_DUPLEX, 1.0f, color);
			putText(img_total, "gray img", Point(50 + frame_resize.cols, 30), FONT_HERSHEY_SIMPLEX, 1.0f, color);
			putText(img_total, "cany img", Point(50 + frame_resize.cols*2, 30), FONT_HERSHEY_COMPLEX,
			1.0f, color);
			
			imshow("output_total", img_total);

			waitKey(0);
		}
	}

	cap.release();

}
Mat img = imread("C:\\Users\\python_gay\\Pictures\\download.jpg");
void on_mouce(int event, int x, int y, int flag, void *ustc);
void exe_2() {
	namedWindow("img");
	setMouseCallback("img", on_mouce);
	imshow("img", img);
	while (true){
		waitKey();
	}
}

void on_mouce(int event, int x, int y, int flag, void *ustc) {
	static Point pre_pt = Point(-1, -1);
	char temp[16];
	//String temp;
	if (event == cv::EVENT_LBUTTONDOWN) {
		pre_pt = Point(x, y);
		stringstream ss_x;
		stringstream ss_y;
		ss_x << x;
		ss_y << y;
		//String temp = "(" + ss_x.str() + ", " + ss_y.str();
		sprintf_s(temp, "x:%d,y:%d", x, y);
		putText(img, temp, pre_pt, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255), 1, 8);
		imshow("img", img);
	}
}

void on_mouce_rect(int event, int x, int y, int flag, void *ustc);
void exe_3() {
	namedWindow("img");
	setMouseCallback("img", on_mouce_rect);
	imshow("img", img);
	while (true) {
		waitKey();
	}
}

void on_mouce_rect(int event, int x, int y, int flag, void *ustc) {
	static Point pre_pt = Point(-1, -1);
	static Point cur_pt = Point(-1, -1);
	char temp[16];
	//String temp;
	if (event == cv::EVENT_LBUTTONDOWN) {
		if (pre_pt.x == -1) {
			pre_pt = Point(x, y);
		}
		
		//stringstream ss_x;
		//stringstream ss_y;
		//ss_x << x;
		//ss_y << y;
		////String temp = "(" + ss_x.str() + ", " + ss_y.str();
		//sprintf_s(temp, "x:%d,y:%d", x, y);
		//putText(img, temp, pre_pt, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255), 1, 8);
		//imshow("img", img);
	}
	else if (event == cv::EVENT_MOUSEMOVE) {
		if (pre_pt.x == -1) {
			return;
		}

		cur_pt = Point(x, y);
		Mat img_clone = img.clone();
		rectangle(img_clone, Rect(pre_pt.x, pre_pt.y, abs(pre_pt.x - cur_pt.x), abs(pre_pt.y - cur_pt.y)), Scalar(0, 0, 255));

		imshow("img", img_clone);
	}
	else if (event == cv::EVENT_LBUTTONUP ) {
		pre_pt = Point(-1, -1);
	}
}

void main(int argc, char** argv) {
	exe_3();
}