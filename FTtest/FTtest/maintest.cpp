#include "CvxText.h"
#include<vector>

void main()
{
	// 打开一幅
	//IplImage *img = cvLoadImage("lena.jpg");
	cv::Mat img = cv::imread("lena.jpg");
	
	// 输出汉字
	{
		CvxText text("C:\\Windows\\Fonts\\simhei.ttf"); // "zenhei.ttf"为黑体常规
		std::vector<std::string> msgs;
		msgs.push_back("在OpenCV中输出汉字! 123abcdefghpygq");
		msgs.push_back("在OpenCV中输出汉字! 123abcdefghpygq");
		msgs.push_back("在OpenCV中输出汉字! 123abcdefghpygq");
		//const char *msg = "在OpenCV中输出汉字!123abcdefghpygq";

		float p = 0.9;
		text.setFont(NULL, NULL, NULL, &p);   // 透明处理
		//text.putText(img, msg, cvPoint(100, 150), CV_RGB(0,255,0));
		//text.putText(img, msg, cv::Point(100, 150), cv::Scalar(0, 255, 0));
		text.putText(img, msgs, cv::Point(100, 150), cv::Scalar(0, 255, 0));
	}

	// 定义窗口，并显示影象
	cv::imshow("test", img);
	//cvShowImage("test", img );
	cvWaitKey(0);
	//cvReleaseImage(&img);

}

