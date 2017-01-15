#include "element.h"

Element::Element(vector<Point> points) {
	this->points = points;
	
	avgX = getSmallmInvariant(1, 0)/getSmallmInvariant(0, 0);
	avgY = getSmallmInvariant(0, 1)/getSmallmInvariant(0, 0);
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

double Element::getSmallmInvariant(int p, int q) {
	double result = 0;

	for(vector<Point>::iterator it = points.begin(); it != points.end(); ++it) {
		result += pow(it->x + 1, p) * pow(it->y + 1, q);
	}

	return result;
}

double Element::getBigMInvariant(int p, int q) {
	double result = 0;

	for(vector<Point>::iterator it = points.begin(); it != points.end(); ++it) {
		result += pow((it->x + 1 - avgX) , p) * pow((it->y + 1 - avgY), q);
	}

	return result;
}

double Element::getM1() {
	double M20 = getBigMInvariant(2, 0);
	double M02 = getBigMInvariant(0, 2);
	double m00 = getSmallmInvariant(0, 0);

	return (M20 + M02)/pow(m00, 2);
}

double Element::getM2() {
	double M20 = getBigMInvariant(2, 0);
	double M02 = getBigMInvariant(0, 2);
	double M11 = getBigMInvariant(1, 1);
	double m00 = getSmallmInvariant(0, 0);

	return (pow((M20 + M02), 2) + 4 * pow(M11, 2))/pow(m00, 4);
}

double Element::getM3() {
	double M30 = getBigMInvariant(3, 0);
	double M12 = getBigMInvariant(1, 2);
	double M21 = getBigMInvariant(2, 1);
	double M03 = getBigMInvariant(0, 3);
	double m00 = getSmallmInvariant(0, 0);

	return (pow((M30 + 3*M12), 2) + pow((3*M21 - M03), 2))/pow(m00, 5);
}

double Element::getM7() {
	double M20 = getBigMInvariant(2, 0);
	double M02 = getBigMInvariant(0, 2);
	double M11 = getBigMInvariant(0, 2);
	double m00 = getSmallmInvariant(0, 0);

	return (M20 * M02 - pow(M11, 2))/pow(m00, 4);
}

void Element::print() {
	cout << "M1: " << getM1() << endl;
	cout << "M2: " << getM2() << endl;
	cout << "M3: " << getM3() << endl;
	cout << "M7: " << getM7() << endl;
}
