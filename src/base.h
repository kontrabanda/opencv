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
private:
	

public:
	Base();
	
	virtual bool checkIsThisClass(Element&);
};

#endif