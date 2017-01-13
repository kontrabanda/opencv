#ifndef ELEMENT_H
#define ELEMENT_H

#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <vector>
#include <map>

using namespace std;
using namespace cv;

class Element {

private:
	Point p;
	vector<Point> points;
	double avgX;
	double avgY;

	double getSmallmInvariant(int, int);
	double getBigMInvariant(int, int);

public:
	Element(vector<Point> points);

	int size();
	void drawElement(Mat& img);
	double getM1();
	double getM3();
	double getM7();
};

#endif