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

class Color {
public:
	double r;
	double g;
	double b;

	Color(double b, double g, double r): r(r), g(g), b(b) {}

	double getLightness() {
		return (b + g + r)/3;
	}
};

class ColorPoint {
public:
	int x;
	int y;
	Color* color;
	
	ColorPoint(int x, int y, double b, double g, double r) {
		this->x = x;
		this->y = y;
		color = new Color(b, g, r);
	}

	~ColorPoint() {
		delete color;
	}
};

class Element {

private:
	double avgX;
	double avgY;

	void decorateColor(vector<Point> points, Mat& inputImg);
	double getSmallmInvariant(int, int);
	double getBigMInvariant(int, int);
	ColorPoint* getCenter();

public:
	vector<ColorPoint*> points;
	
	Element(vector<Point> points, Mat& img);
	Element(vector<ColorPoint*>& elPoints);

	int size();
	void drawElement(Mat& img, Color&);
	double getM1();
	double getM2();
	double getM3();
	double getM7();
	void print();
	int getArea();
	vector<ColorPoint*>& getPoints();
	Color getAvgColor();
	Color getColorStandardDev();
	void drawCenter(Mat&);
	Element* getOuterElement(int);
	Element* getInnerElement(int);

	double radiusPlaceholder;

	~Element();
};

#endif