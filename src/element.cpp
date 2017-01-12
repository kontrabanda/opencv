#include "element.h"

Element::Element(vector<Point> points) {
	this->points = points;
}

int Element::size() {
	return points.size();
}

void Element::drawElement(Mat& img) {
	Mat_<Vec3b> _I = img;

	for(int i = 0; i < points.size(); ++i) {
		Point curr = points[i];
		_I(curr.x, curr.y)[0] = 150;
		_I(curr.x, curr.y)[1] = 50;
		_I(curr.x, curr.y)[2] = 150;
	}

	_I = img;
}