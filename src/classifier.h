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

#include "_1grclass.h"
#include "_2grclass.h"
#include "_5grclass.h"
#include "_10grclass.h"
#include "_20grclass.h"
#include "_50grclass.h"
#include "_1zlclass.h"
#include "_2zlclass.h"
#include "_5zlclass.h"

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
	static const int CLASSES_COUNT = 9;

	Element* calibrationElement;
	Mat& image;
	Base* classesCheck[CLASSES_COUNT];
	vector<Element*>* classifiedElements;

	Element* getCalibrationElement(vector<Element*>*);
	void initClassesCheck();

public:
	Classifier(vector<Element*>*, Mat&);
	void classify(Element*);
	void printItemsInfo(Mat&);

	~Classifier();
};

#endif