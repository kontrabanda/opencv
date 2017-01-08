#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <math.h>
#include <iostream>

using namespace cv;

class Segmentation {
private: 
	Mat& image;

	int getValidateColor(int color);
	void filterAvg(int);
	void filterColors(int*);

public:
	Segmentation(Mat& img);
	Mat getSegmentedImage();
};

#endif