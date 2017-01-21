#include "_5zlclass.h"

_5ZlClass::_5ZlClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _5ZlClass::checkIsThisClass(Element& el) {
	if(!isCoinShape(el)) {
		return false;
	}

	double areaRatio = (double)el.getArea()/(double)calibrationElement->getArea();

	if(areaRatio < areaMax && areaRatio > areaMin) {
		return true;
	} else {
		return false;
	}
}