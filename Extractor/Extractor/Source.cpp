#include <sstream>
#include <iostream>
#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <Windows.h>
#define _CRT_SECURE_NO_DEPRECATE

using namespace cv;

// current gray-level image
Mat gray;
// accumulated background
Mat background;
// background image
Mat backImage;
// foreground image
Mat foreground;
// learning rate in background accumulation
double learningRate=2;
// threshold for foreground extraction
int threshold=155;

// processing method
void process(cv::Mat &frame, cv::Mat &output) {
	// convert to gray-level image
	cv::cvtColor(frame, gray, CV_BGR2GRAY);
	// initialize background to 1st frame
	if (background.empty())
		gray.convertTo(background, CV_32F);
	// convert background to 8U
	background.convertTo(backImage, CV_8U);
	// compute difference between image and background
	cv::absdiff(backImage, gray, foreground);
	// apply threshold to foreground image
	cv::threshold(foreground,output, 15, 255, cv::THRESH_BINARY_INV);
	// accumulate background
	cv::accumulateWeighted(gray, background,learningRate, output);
}

int main()
{
	Mat image;
	Mat video;
	int c = 0;
	VideoCapture cap;
	cap.open(0);
	namedWindow("window", 1);
	namedWindow("output", 1);
	while (1)
	{
		cap >> image;
		process(image, video);
		imshow("window", image);
		imshow("output", video);
		if (c == 0)
		{
			waitKey(3000);
			c++;
		}
		else
			waitKey(25);
	}
	return 0;
}