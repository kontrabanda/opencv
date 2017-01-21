#ifndef IMAGE_WRAPPER_H
#define IMAGE_WRAPPER_H

#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

#include "segmentation.h"
#include "elementgetter.h"
#include "element.h"
#include "classifier.h"

using namespace cv;
using namespace std;

class ImageWrapper {
private:
	string saveFilePath;
	Mat calibrationImage;
	Mat image;
	Mat inputImage;
	
	Segmentation* calibrationSegmentation;
	Segmentation* contentSegmentation;

	vector<Element*>* calibrationElements;
	vector<Element*>* findedElements;

	Classifier* classifier;

public:
	ImageWrapper(Mat img, string saveFilePath);
	
	void performClassification();
	void performCalibrationSegmentation();
	void performContentSegmentation();
	void writeImage();

	~ImageWrapper();
};

#endif