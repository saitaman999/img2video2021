#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	cv::VideoWriter writer;
	int key;
	double fps = 10.0;
	int img_width = 640;
	int img_height = 480;
	Size img_size = cv::Size(img_width, img_height);
	cv::Mat frame = cv::Mat(img_size, CV_8UC3);
	cv::Mat detect_line;

	//動画ファイル生成
	writer.open("D:\\2021_2022 hasegawa\\2021\\videos\\20210520_tsubetsu_onion_network4_recognition.mov", VideoWriter::fourcc('m', 'p', '4', 'v'), fps, img_size, true);
	//動画ファイル生成の確認
	if (!writer.isOpened()) {
		std::cerr << "Writer Not Opened!" << std::endl;
		return -1;
	}

	for (int i = 0; i <= 6412; i++)
	{
		std::string img_raw_path = cv::format("D:\\2021_2022 hasegawa\\2021\\recognition_result_matlab\\testResults0614\\network4_result\\20210520_all\\TestRst%d.png", i + 1200);
		frame = imread(img_raw_path, 1);
		if (frame.empty()) {
			std::cerr << "Can't image show." << std::endl;
			return -1;
		}
		
		//画像の表示
		imshow("frame", frame);
		//ビデオへの書き込み
		writer.write(frame);
		key = cv::waitKey(1);
		if (key == 27)
			break;
	}

	destroyAllWindows();
	writer.release();
	return 0;
}