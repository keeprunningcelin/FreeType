#include "CvxText.h"
#include<vector>

void main()
{
	// ��һ��
	//IplImage *img = cvLoadImage("lena.jpg");
	cv::Mat img = cv::imread("lena.jpg");
	
	// �������
	{
		CvxText text("C:\\Windows\\Fonts\\simhei.ttf"); // "zenhei.ttf"Ϊ���峣��
		std::vector<std::string> msgs;
		msgs.push_back("��OpenCV���������! 123abcdefghpygq");
		msgs.push_back("��OpenCV���������! 123abcdefghpygq");
		msgs.push_back("��OpenCV���������! 123abcdefghpygq");
		//const char *msg = "��OpenCV���������!123abcdefghpygq";

		float p = 0.9;
		text.setFont(NULL, NULL, NULL, &p);   // ͸������
		//text.putText(img, msg, cvPoint(100, 150), CV_RGB(0,255,0));
		//text.putText(img, msg, cv::Point(100, 150), cv::Scalar(0, 255, 0));
		text.putText(img, msgs, cv::Point(100, 150), cv::Scalar(0, 255, 0));
	}

	// ���崰�ڣ�����ʾӰ��
	cv::imshow("test", img);
	//cvShowImage("test", img );
	cvWaitKey(0);
	//cvReleaseImage(&img);

}

