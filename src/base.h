#ifndef BASE_H
#define BASE_H

#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <vector>

#include "element.h"

using namespace cv;
using namespace std;

class Base {
protected:
	static const double M1_MIN = 0.158;
	static const double M1_MAX = 0.161;

	static const double M2_MIN = 0.0253;
	static const double M2_MAX = 0.0256;

	bool isCoinShape(Element&);

public:
	Base();
	
	virtual bool checkIsThisClass(Element&);
};

#endif