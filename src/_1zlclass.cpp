#include "_1zlclass.h"

_1ZlClass::_1ZlClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _1ZlClass::checkIsThisClass(Element& el) {
	double areaRatio = (double)el.getArea()/(double)calibrationElement->getArea();

	if(areaRatio < areaMax && areaRatio > areaMin) {
		return true;
	} else {
		return false;
	}
}