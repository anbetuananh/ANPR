// feature.h 
// TINH TOAN CAC DAC TRUNG CUA KY TU CHO VIEC HUAN LUYEN VA NHAN DANG


#ifndef FEATURE_H
#define FEATURE_H

#include <opencv\cxcore.h>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <vector>
#include "dirent.h"  // Lay thu vien dirent.h

using namespace std;
using namespace cv;

const int number_of_feature = 32;  // so luong dac trung cua ky tu

// Ham dem so luong diem den/ diem trang tren buc anh
static int count_pixel(Mat img, bool black_pixel = true)
{
	int black = 0;
	int white = 0;
	for (int i = 0; i < img.rows; ++i)
	for (int j = 0; j < img.cols; ++j)
	{
		if (img.at<uchar>(i, j) == 0)
			black++;
		else
			white++;
	}
	if (black_pixel)
		return black;
	else
		return white;
}

// Ham lay 32 dac trung cho 1 ky tu
static vector<float> calculate_feature(Mat src)
{
	Mat img;  // khai bao 1 mat la anh img
	vector<float> r;  // 1 vector dac trung anh la: r

	resize(src, img, Size(40, 40));  // resize anh goc src thanh anh img co kich thuoc 40x40
	int h = img.rows / 4;			 // h la so hang trong anh chia 4
	int w = img.cols / 4;			 // w là so cot trong anh chia 4
	int S = count_pixel(img);		 // S la ti le diem den/diem trang trong anh img
	int T = img.cols * img.rows;     // T la tich so hang va so cot trong img
	for (int i = 0; i < img.rows; i += h)
	{
		for (int j = 0; j < img.cols; j += w)
		{
			Mat cell = img(Rect(i, j, h, w));  // khai bao kich thuoc 1 cell
			int s = count_pixel(cell);		   // dem so diem anh trong 1 cell
			float f = (float)s / S;            // f la so cell tim duoc trong anh img
			r.push_back(f);					   // tra lai vector dac trung r gia tri la : f
		}
	}

	// tim 4 dac trung
	for (int i = 0; i < 16; i += 4)
	{
		float f = r[i] + r[i + 1] + r[i + 2] + r[i + 3];
		r.push_back(f);
	}

	// tim 4 dac trung
	for (int i = 0; i < 4; ++i)
	{
		float f = r[i] + r[i + 4] + r[i + 8] + r[i + 12];
		r.push_back(f);
	}

	// tim 8 dac trung
	r.push_back(r[0] + r[5] + r[10] + r[15]);
	r.push_back(r[3] + r[6] + r[9] + r[12]);
	r.push_back(r[0] + r[1] + r[4] + r[5]);
	r.push_back(r[2] + r[3] + r[6] + r[7]);
	r.push_back(r[8] + r[9] + r[12] + r[13]);
	r.push_back(r[10] + r[11] + r[14] + r[15]);
	r.push_back(r[5] + r[6] + r[9] + r[10]);
	r.push_back(r[0] + r[1] + r[2] + r[3] + r[4] + r[7] + r[8] + r[11] + r[12] + r[13] + r[14] + r[15]);

	return r; //32 feature
}
#endif