#include <iostream>
#include <opencv2/opencv.hpp>


int main(void)
{
	cv::Mat frame_raw;
	cv::Mat frame_result;
	cv::Mat raw_rect;
	cv::Mat result_rect;


	cv::Size frame_size = cv::Size(640 * 2, 480);
	cv::Mat frame = cv::Mat(frame_size, CV_8UC3);
	raw_rect = cv::Mat(frame, cv::Rect(0, 0, 640, 480));
	result_rect = cv::Mat(frame, cv::Rect(640, 0, 640, 480));

	frame_raw = cv::imread("D:\\2021_2022 hasegawa\\2021\\20210512_tubetu_sakumotu\\20210520\\color\\color_11290.jpg");
	frame_result = cv::imread("D:\\2021_2022 hasegawa\\2021\\recognition_result_matlab\\network1\\testResults0521_img_all\\TestRst11290.png");
	if (frame_raw.empty() || frame_result.empty()) {
		std::cout << "Can't read image." << std::endl;
		return -1;
	}

	frame_raw.copyTo(raw_rect);
	frame_result.copyTo(result_rect);
	
	cv::namedWindow("test_merge");
	imshow("frame_raw", frame_raw);
	imshow("frame_result", frame_result);
	imshow("test_merge", frame);
	cv::waitKey(0);

	return 0;

}