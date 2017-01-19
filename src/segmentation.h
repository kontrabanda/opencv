#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <math.h>
#include <iostream>

using namespace cv;
using namespace std;

class Segmentation {
private: 
	Mat image;
	Mat inputImage;

	int getValidateColor(int color);

public:
	Segmentation(Mat& img);

	Mat getSegmentedImage();
	void filterAvg(int*, int*, int*);
	void filterColorsMin(int*);
	void filterColorsMax(int*);
	void binarization();
	void dilatation();
	void erosion();
	void opening();
	void closing();
	void windowFilter();
};

#endif