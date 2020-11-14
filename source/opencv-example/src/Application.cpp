#include <iostream>
#include <functional>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {
	// [out = std::ref(std::cout << "Hello world, ")] (){out.get() << "Hello C++!\n"; }();
	// read the input image from file
	cv::Mat image = cv::imread("E:\\lena.jpg", cv::IMREAD_COLOR);
	// create and set the window name
	cv::namedWindow("Show Image", cv::WINDOW_NORMAL);
	// show the image on window
	cv::imshow("Show Image", image);
	// close the window
	cv::waitKey(0);
	return 0;
}