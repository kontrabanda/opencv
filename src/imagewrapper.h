#ifndef IMAGE_WRAPPER_H
#define IMAGE_WRAPPER_H

#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

#include "segmentation.h"
#include "elementgetter.h"
#include "element.h"

using namespace cv;
using namespace std;

class ImageWrapper {
private:
	string saveFilePath;
	Mat image;
	Segmentation* segmentation;

public:

	ImageWrapper(Mat img, string saveFilePath);
	
	void performClassification();
	void writeImage();

	~ImageWrapper();
};

#endif