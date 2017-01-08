#ifndef ACTION_H
#define ACTION_H

#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

#include "imagewrapper.h"

using namespace cv;
using namespace std;

class Action {
private:
	vector<ImageWrapper*> images;

	void fetchImages(String);


public:
	Action(String);
	~Action();
	void start();
};

#endif