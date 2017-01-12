#ifndef ELEMENT_GETTER_H
#define ELEMENT_GETTER_H

#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <math.h>
#include <iostream>
#include <vector>

#include "element.h"

using namespace std;
using namespace cv;

class ElementGetter {

private:
	Mat image;

	Element* growElement(Point);
	void appendPointNeighborhood(Point, vector<Point>&);
	void appendPoint(Point, vector<Point>&);

public:
	ElementGetter(Mat& img);
	vector<Element*> getElements();
};

#endif