#include <opencv2\highgui\highgui.hpp>
#include <opencv\highgui.h>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>



using namespace cv;
using namespace std;

int main()
{

	Mat img_1 = imread("seg_cg10.jpg", -1);

	Mat contours_1;
	Mat contours_2;
	Canny(img_1, contours_1, 50, 100);
	Canny(img_1, contours_2, 100, 300);

	imshow("Keypoints 1", contours_1);
	imshow("Keypoints 1.5", contours_2);
	imshow("Keypoints 2", img_1);


	waitKey(0);

	return 0;

}