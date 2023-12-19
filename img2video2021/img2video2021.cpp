// img2video2021.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;


int a[8] = {30,15,40,45,25,10,35,20};
int n = 8;
int k;



int main()
{

	cv::VideoWriter writer;
/*	*/int key;
	double fps = 3;//10.0;
	int img_width = 640;
	int img_height = 480;
	//Size img_size = cv::Size(640,427);
	Size img_size = cv::Size(640 * 2, 480);
	//Size img_size = cv::Size(img_width * 3, img_height);
	cv::Mat frame = cv::Mat(img_size, CV_8UC3);
	cv::Mat frame_raw;
	cv::Mat frame_result_network_maskrcnn;
	cv::Mat frame_result_network_semanticseg;

	cv::Mat raw_rect;
	cv::Mat result_network_maskrcnn_rect;
	cv::Mat result_network_semanticseg_rect;

	raw_rect = cv::Mat(frame, cv::Rect(0, 0, img_width, img_height));
	result_network_maskrcnn_rect = cv::Mat(frame, cv::Rect(640, 0, img_width, img_height));
	//result_network_semanticseg_rect = cv::Mat(frame, cv::Rect(1280, 0, img_width, img_height));

	//動画ファイル生成
	writer.open("\\\\150.97.78.223\\share\\鎌田颯太\\crop_AI_4.mp4", VideoWriter::fourcc('m', 'p', '4', 'v'), fps, img_size, true);
	//動画ファイル生成の確認
	if (!writer.isOpened()) {
		std::cerr << "Writer Not Opened!" << std::endl;
		return -1;
	}

	

	int start_frame = 1;
	for(int i = 0; i < 1500; i++)//i<100*fps
	{
		std::string img_raw_path = cv::format("\\\\150.97.78.223\\share\\長谷川晃己\\長谷川晃己 修士論文 データ\\2022_M2\\実験データ\\20220608_中間除草_実地走行\\AI_PC\\ST-2022-06-08-15.35.10\\image\\Src\\Src_%d.jpg", i+1);
		//std::string img_raw_path = cv::format("D:\\resize8-14\\resize_%d.JPG", start_frame + i);
		//std::string img_result_network_maskrcnn_path = cv::format("C:\\Users\\tnog7\\Documents\\save\\grape_kinect_color_day2\\kinect_color_%05d.png", start_frame + i);
		//std::string img_result_network_maskrcnn_path = cv::format("C:\\Users\\tnog7\\Documents\\save\\semanticseg\\%d.jpg", start_frame + i);
		std::string img_result_network_maskrcnn_path = cv::format("\\\\150.97.78.223\\share\\長谷川晃己\\長谷川晃己 修士論文 データ\\2022_M2\\実験データ\\20220608_中間除草_実地走行\\AI_PC\\ST-2022-06-08-15.35.10\\image\\AI\\AI_%d.jpg", start_frame + i);
		//std::string img_result_network_semanticseg_path = cv::format("C:\\Users\\tnog7\\Documents\\研究資料（ブドウ自動収穫機）\\AI_Picture\\picture-250\\%d.jpg", start_frame + i);
		//std::string img_result_network_semanticseg_path = cv::format("C:\\Users\\tnog7\\Documents\\save\\resize\\resize_%d.png", start_frame + i);
		
		frame_raw = imread(img_raw_path, 1);
		if (frame_raw.empty()) {
			std::cerr << "Can't image show." << std::endl;
			return -1;
		}

		frame_result_network_maskrcnn = imread(img_result_network_maskrcnn_path, 1);
		if (frame_result_network_maskrcnn.empty()) {
			std::cerr << "Can't image show." << std::endl;
			return -1;
		}
		//frame_result_network_semanticseg = imread(img_result_network_semanticseg_path, 1);
		//if (frame_result_network_semanticseg.empty()) {
		//	std::cerr << "Can't semanticseg image show." << std::endl;
		//	return -1;
		//}

		frame_raw.copyTo(raw_rect);
		frame_result_network_maskrcnn.copyTo(result_network_maskrcnn_rect);
		frame_result_network_semanticseg.copyTo(result_network_semanticseg_rect);

		//画像の表示
		imshow("frame", frame);
		//ビデオへの書き込み
		writer.write(frame);
		key = cv::waitKey(1);
		if (key == 27)
			break;
	}

	cv::destroyAllWindows();
	writer.release();
    return 0;
}

