#include "_1zlclass.h"

_1ZlClass::_1ZlClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _1ZlClass::checkIsThisClass(Element& el) {
	if(!isCoinShape(el)) {
		return false;
	}
	
	double areaRatio = (double)el.getArea()/(double)calibrationElement->getArea();
	Color avgColor = el.getAvgColor();

	if(areaRatio < areaMax && areaRatio > areaMin && isSilver(avgColor)) {
		return true;
	} else {
		return false;
	}
}