#include "Chapter_8.h"
#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

std::vector<Point> points;

//void on_mouce(int event, int x, int y, int flag, void *ustc) {
//	static Point pre_pt = Point(-1, -1);
//	static Point cur_pt = Point(-1, -1);
//	char temp[16];
//	if (event == cv::EVENT_LBUTTONDOWN) {
//		pre_pt = Point(x, y);
//		putText(img, temp, pre_pt, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255), 1, 8)
//	}
//}

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
void main(int argc, char** argv) {
	exe_1();
}