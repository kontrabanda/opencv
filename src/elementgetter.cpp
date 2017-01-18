 #include "elementgetter.h"

ElementGetter::ElementGetter(Mat& img, Mat& inputImage) {
	this->image = img.clone();
	this->inputImage = inputImage.clone();
}

vector<Element*> ElementGetter::getElements() {
	Mat_<Vec3b> _I = image;
	vector<Element*> result;

	for(int i = 0; i < _I.rows; ++i) {
		for(int j = 0; j < _I.cols; ++j) {
			if(_I(i, j)[0] == 255) {
				Point point(i, j);
				Element* el = this->growElement(point);

				if(el->size() < 150) {
					delete el;
				} else {
					result.push_back(el);
				}
			}
		}
	}

	return result;
}

Element* ElementGetter::growElement(Point startPoint) {
	Mat_<Vec3b> _I = image;
	vector<Point> elements;
	vector<Point> pretenders;

	Point currentPoint = startPoint;
	pretenders.push_back(currentPoint);

	do {
		currentPoint = pretenders.back();
		pretenders.pop_back();

		if(_I(currentPoint.x, currentPoint.y)[0] == 255) {
			_I(currentPoint.x, currentPoint.y)[0] = 0;
			_I(currentPoint.x, currentPoint.y)[1] = 0;
			_I(currentPoint.x, currentPoint.y)[2] = 0;

			elements.push_back(currentPoint);
			appendPointNeighborhood(currentPoint, pretenders);
		}
	} while(pretenders.size() > 0);

	image = _I;

	Element* result = new Element(elements, inputImage);
	return result;
}

void ElementGetter::appendPointNeighborhood(Point point, vector<Point>& pointsList) {
	for(int i = -1; i <= 1; ++i) {
		for(int j = -1; j <= 1; ++j) {
			if(i == 0 && j == 0) {
				continue;
			}

			Point neighbor(point.x + i, point.y + j);
			appendPoint(neighbor, pointsList);
		}
	}
}

void ElementGetter::appendPoint(Point point, vector<Point>& pointsList) {
	if(point.x >= 0 && point.y >= 0 && point.x < image.rows && point.y < image.cols) {
		pointsList.push_back(point);
	}
}