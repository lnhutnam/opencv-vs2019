#include <iostream>
#include <functional>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int rgb2gray(cv::Mat& srcImage, cv::Mat& dstImage) {
	if (srcImage.data == NULL) {
		return 0;
	}

	int width = srcImage.cols;
	int heigth = srcImage.rows;
	int srcChannels = srcImage.channels();
	int dstChannels = dstImage.channels();

	dstImage = cv::Mat(heigth, width, CV_8UC1);

	for (int y = 0; y < heigth; y++) {
		uchar* pSrcRow = srcImage.ptr<uchar>(y);
		uchar* pDstRow = dstImage.ptr<uchar>(y);
		for (int x = 0; x < width; x++, pSrcRow += srcChannels, pDstRow += dstChannels) {
			uchar blue = pSrcRow[0];
			uchar green = pSrcRow[1];
			uchar red = pSrcRow[2];
			uchar gray_value = (uchar)((blue + green + red) / 3);
			pDstRow[0] = gray_value;
		}
	}

	return 1;
}

int rgb2gray_1(cv::Mat& srcImage, cv::Mat& dstImage) {
	if (srcImage.data == NULL) {
		return 0;
	}

	int width = srcImage.cols;
	int heigth = srcImage.rows;
	int srcChannels = srcImage.channels();
	int dstChannels = dstImage.channels();

	dstImage = cv::Mat(heigth, width, CV_8UC1);

	int srcWidthStep = srcImage.step[0];
	int dstWidthStep = dstImage.step[0];

	uchar* pSrcData = srcImage.data;
	uchar* pDstData = dstImage.data;

	for (int y = 0; y < heigth; y++, pSrcData += srcWidthStep, pDstData += dstWidthStep) {
		uchar* pSrcRow = pSrcData;
		uchar* pDstRow = pDstData;

		for (int x = 0; x < width; x++, pSrcRow += srcChannels, pDstRow += dstChannels) {
			uchar blue = pSrcRow[0];
			uchar green = pSrcRow[1];
			uchar red = pSrcRow[2];
			uchar gray_value = (uchar)((blue + green + red) / 3);
			pDstRow[0] = gray_value;
		}
	}

	return 1;

}

int main() {
	// [out = std::ref(std::cout << "Hello world, ")] (){out.get() << "Hello C++!\n"; }();
	// read the input image from file
	cv::Mat image = cv::imread("E:\\lena.jpg", cv::IMREAD_COLOR);
	// create and set the window name
	//cv::namedWindow("Show Image", cv::WINDOW_NORMAL);
	// show the image on window
	cv::imshow("Show Image", image);
	// close the window
	cv::Mat dstImg;
	rgb2gray_1(image, dstImg);
	//cv::namedWindow("Show Result Image", cv::WINDOW_NORMAL);
	cv::imshow("Show Result Image", dstImg);
	cv::waitKey(0);
	return 0;
}