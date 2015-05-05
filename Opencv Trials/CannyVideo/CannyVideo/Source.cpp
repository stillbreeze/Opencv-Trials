#include <opencv2\highgui\highgui.hpp>
#include <opencv\highgui.h>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>
#include <sstream>
#include <opencv\cv.h>



using namespace cv;
using namespace std;

int main()
{
	VideoCapture capture;
	Mat contours_1;
	Mat contours_2;
	Mat img;
	capture.open(0);

	while (true) {
		capture >> img;
		Canny(img, contours_1, 50, 100);
		Canny(img, contours_2, 100, 300);
		namedWindow("Keypoints 1", 0);
		resizeWindow("KeyPoints 1", 2000, 2000);
		imshow("Keypoints 1", contours_1);
		imshow("Keypoints 1.5", contours_2);
		imshow("Keypoints 2", img);

		int c = waitKey(30);
		if (c == 27) break;
		else if (c == 'p') waitKey(0);
	}
	return 0;
}
