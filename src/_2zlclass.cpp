#include "_2zlclass.h"

_2ZlClass::_2ZlClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _2ZlClass::checkIsThisClass(Element& el) {
	double areaRatio = (double)el.getArea()/(double)calibrationElement->getArea();

	if(areaRatio < areaMax && areaRatio > areaMin) {
		return true;
	} else {
		return false;
	}
}