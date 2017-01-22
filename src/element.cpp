#include "element.h"

Element::Element(vector<Point> points, Mat& img) {
	decorateColor(points, img);

	avgX = getSmallmInvariant(1, 0)/getSmallmInvariant(0, 0);
	avgY = getSmallmInvariant(0, 1)/getSmallmInvariant(0, 0);
}

Element::Element(vector<ColorPoint*>& elPoints) {
	for(vector<ColorPoint*>::iterator it = elPoints.begin(); it != elPoints.end(); ++it) {
		Color* color = (*it)->color;
		ColorPoint* cp = new ColorPoint((*it)->x, (*it)->y, color->b, color->g, color->r);
		this->points.push_back(cp);
	}

	avgX = getSmallmInvariant(1, 0)/getSmallmInvariant(0, 0);
	avgY = getSmallmInvariant(0, 1)/getSmallmInvariant(0, 0);	
}

int Element::size() {
	return points.size();
}

void Element::drawElement(Mat& img, Color& color) {
	Mat_<Vec3b> _I = img;

	for(int i = 0; i < points.size(); ++i) {
		int x = points[i]->x;
		int y = points[i]->y;

		_I(x, y)[0] = color.b;
		_I(x, y)[1] = color.g;
		_I(x, y)[2] = color.r;
	}

	_I = img;
}

ColorPoint* Element::getCenter() {
	int xSum = 0;
	int ySum = 0;

	for(int i = 0; i < points.size(); ++i) {
		xSum += points[i]->x;
		ySum += points[i]->y;
	}	

	double xCenter = (double)xSum/points.size();
	double yCenter = (double)ySum/points.size();

	return new ColorPoint(xCenter, yCenter, 0, 0, 0);
}

void Element::drawCenter(Mat& img) {
	Mat_<Vec3b> _I = img;
	int radius = radiusPlaceholder;
	ColorPoint* center = getCenter();

	for(int i = 0; i < points.size(); ++i) {
		double x = points[i]->x - center->x;
		double y = points[i]->y - center->y;
		double distance = pow(pow(y, 2) + pow(x, 2), 0.5);

		if(distance <= radius) {
			_I(points[i]->x, points[i]->y)[0] = 139;
			_I(points[i]->x, points[i]->y)[1] = 39;
			_I(points[i]->x, points[i]->y)[2] = 216;
		}
	}	

	delete center;
}

Element* Element::getInnerElement(int radius) {
	vector<ColorPoint*>	resultPoints;
	ColorPoint* center = getCenter();

	for(int i = 0; i < points.size(); ++i) {
		double x = points[i]->x - center->x;
		double y = points[i]->y - center->y;
		double distance = pow(pow(y, 2) + pow(x, 2), 0.5);

		if(distance <= radius) {
			resultPoints.push_back(points[i]);
		}
	}

	return new Element(resultPoints);
}

Element* Element::getOuterElement(int radius) {
	vector<ColorPoint*>	resultPoints;
	ColorPoint* center = getCenter();

	for(int i = 0; i < points.size(); ++i) {
		double x = points[i]->x - center->x;
		double y = points[i]->y - center->y;
		double distance = pow(pow(y, 2) + pow(x, 2), 0.5);

		if(distance >= radius) {
			resultPoints.push_back(points[i]);
		}
	}

	return new Element(resultPoints);
}


void Element::decorateColor(vector<Point> points, Mat& img) {
	Mat_<Vec3b> _I = img;

	for(vector<Point>::iterator it = points.begin(); it != points.end(); ++it) {
		int b = _I(it->x, it->y)[0];
		int g = _I(it->x, it->y)[1];
		int r = _I(it->x, it->y)[2];

		ColorPoint* cp = new ColorPoint(it->x, it->y, b, g, r);
		this->points.push_back(cp);
	}
}

double Element::getSmallmInvariant(int p, int q) {
	double result = 0;

	for(vector<ColorPoint*>::iterator it = points.begin(); it != points.end(); ++it) {
		result += pow((*it)->x + 1, p) * pow((*it)->y + 1, q);
	}

	return result;
}

double Element::getBigMInvariant(int p, int q) {
	double result = 0;

	for(vector<ColorPoint*>::iterator it = points.begin(); it != points.end(); ++it) {
		result += pow(((*it)->x + 1 - avgX) , p) * pow(((*it)->y + 1 - avgY), q);
	}

	return result;
}

int Element::getArea() {
	return points.size();
}

Color Element::getAvgColor() {
	int b = 0;
	int g = 0;
	int r = 0;

	for(vector<ColorPoint*>::iterator it = points.begin(); it != points.end(); ++it) {
		b += (*it)->color->b;
		g += (*it)->color->g;
		r += (*it)->color->r;
	}

	b /= points.size();
	g /= points.size();
	r /= points.size();

	return Color(b, g, r);
}

Color Element::getColorStandardDev() {
	double b = 0;
	double g = 0;
	double r = 0;
	Color avgColor = getAvgColor();
	int n = points.size();

	for(int i = 0; i < n; ++i) {
		b += pow(points[i]->color->b - avgColor.b, 2);
		g += pow(points[i]->color->g - avgColor.g, 2);
		r += pow(points[i]->color->r - avgColor.r, 2);
	}

	return Color(
		pow(b/n, 0.5),
		pow(g/n, 0.5),
		pow(r/n, 0.5));
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

	return (pow((M30 + 3 * M12), 2) + pow((3 * M21 - M03), 2))/pow(m00, 5);
}

double Element::getM7() {
	double M20 = getBigMInvariant(2, 0);
	double M02 = getBigMInvariant(0, 2);
	double M11 = getBigMInvariant(0, 2);
	double m00 = getSmallmInvariant(0, 0);

	return (M20 * M02 - pow(M11, 2))/pow(m00, 4);
}

void Element::print() {
	cout << "Area: " << getArea() << endl;

	Color avgColor = getAvgColor();
	cout << "AvgColor: b=" << avgColor.b << ", g=" << avgColor.g << ", r=" << avgColor.r << endl;

	Color stdColor = getColorStandardDev();
	cout << "VarianceColor: b=" << stdColor.b << ", g=" << stdColor.g << ", r=" << stdColor.r << endl;
}

vector<ColorPoint*>& Element::getPoints() {
	return this->points;
};

Element::~Element() {
	for(vector<ColorPoint*>::iterator it = points.begin(); it != points.end(); ++it) {
		delete (*it);
	}
}
