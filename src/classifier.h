#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <vector>

#include "element.h"
#include "base.h"
#include "calibrationclass.h"

using namespace cv;
using namespace std;

enum COINS {
	_1_GR = 0,
	_2_GR,
	_5_GR,
	_10_GR,
	_20_GR,
	_50_GR,
	_1_ZL,
	_2_ZL,
	_5_ZL,
	_OTHER
};

class Classifier {
private:
	Element* calibrationElement;
	Mat& image;
	vector<Element*>* classifiedElements;
	Element* getCalibrationElement(vector<Element*>*);

public:
	Classifier(vector<Element*>*, Mat&);
	void classify();

	~Classifier();
};

#endif