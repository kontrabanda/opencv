#ifndef ELEMENT_H
#define ELEMENT_H

#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <vector>

using namespace std;
using namespace cv;

class Element {

private:
	Point p;
	vector<Point> points;

public:
	Element(vector<Point> points);

	int size();
	void drawElement(Mat& img);
};

#endif