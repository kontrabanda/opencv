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
	bool isCoinShape(Element&);
	bool isBronze(Color&);
	bool isSilver(Color&);

public:
	Base();
	
	virtual bool checkIsThisClass(Element&);
};

#endif