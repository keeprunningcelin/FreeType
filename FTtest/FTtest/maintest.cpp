#include "CvxText.h"
#include<vector>

cv::Mat getCanvas(const cv::Mat& inputImage, const std::vector<std::string>& Msgs)
{
	CV_Assert(inputImage.data && inputImage.type() == CV_8UC3);

	int numMsgs = (int)Msgs.size();
	int inputImageHeight = inputImage.rows;
	int inputImageWidth = inputImage.cols;
	int msgHeight = 22;
	int msgWidth = 20;
	int allMsgsHeight = msgHeight * numMsgs;
	int allMsgsWidth = msgWidth * 5;//����ÿһ�����ݵĶ��ٿ�����Ӧ�޸�
	int outputImageHeight = inputImageHeight > allMsgsHeight ? inputImageHeight : allMsgsHeight;
	int outputImageWidth = inputImageWidth + allMsgsWidth;
	
	cv::Mat outputImage(outputImageHeight, outputImageWidth, CV_8UC3,cv::Scalar(0,0,0));

	for (int r = 0; r < inputImageHeight; r++)
	{
		for (int c = 0; c < inputImageWidth; c++)
		{
			cv::Vec3b &val = outputImage.at<cv::Vec3b>(r, c);
			cv::Vec3b val2 = inputImage.at<cv::Vec3b>(r, c);
			for (int k = 0; k < 3; ++k)
			{
				val[k] =val2[k];
			}
		}
	}
	
	return outputImage;
	
}

void drawResults(const cv::Mat& inputImage, const std::vector<std::string>& Msgs, cv::Mat& outputImage)
{
	outputImage=getCanvas(inputImage, Msgs);
	CvxText text("C:\\Windows\\Fonts\\simsun.ttc"); // "simsun.ttc"Ϊ����
	float p = 0.9;
	text.setFont(NULL, NULL, NULL, &p);   // ͸������
	text.putText(outputImage, Msgs, cv::Point(inputImage.cols + 10, 20), cv::Scalar(255, 255, 255));
}

int main()
{
	cv::Mat img = cv::imread("test.jpg");
	std::vector<std::string> msgs;
	cv::Mat outputImage;
	msgs.push_back("�� 0.8000");
	msgs.push_back("�� 0.0020");
	msgs.push_back("�� 0.0060");
	msgs.push_back("�� 0.0120");
	msgs.push_back("�� 0.0010");

	// �������
	drawResults(img, msgs, outputImage);
	// ���崰�ڣ�����ʾӰ��
	cv::imshow("test", outputImage);
	cvWaitKey(0);

}

