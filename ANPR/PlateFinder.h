#ifndef PlateFinder_H
#define PlateFinder_H
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <opencv\cxcore.h>
#include <iostream>

class LPR_PlateFinder
{
private:
	IplConvKernel* S1;	//S1 và S2 là các ma trận mặt nạ nhân tích chập
	IplConvKernel* S2;
	IplImage *plate;	// Ảnh biển số
public:
	LPR_PlateFinder();
	~LPR_PlateFinder();

	// Lọc nhiễu và lọc biên
	void WaveletEdge(IplImage *src_pyrdown, bool flag = false);	

	// Thực hiện việc tìm biển số xe qua hàm findPlate với: 
	// src: ảnh đầu vào 
	// show : hiện ảnh
	// k : chọn ảnh để hiện thị
	// => trả về ảnh biển số tìm được
	IplImage* FindPlate(IplImage *src, bool show = false, int k = 1);

	// Đếm số vùng có thể là biển số trên ảnh để nhận dạng
	int LPR_PlateFinder::Count(IplImage *plate);
};
#endif