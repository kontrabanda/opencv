#ifndef INVARIANTS_H
#define INVARIANTS_H

#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <math.h>
#include <iostream>
#include <map>

using namespace std;
using namespace cv;

class Invariants {
private:
	Mat& image;
	map<string, int> smallInvariants;

	void computeSmallInvariants();

public:
	Invariants(Mat& img);

	

};

#endif