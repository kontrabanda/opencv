#include "_5grclass.h"

_5GrClass::_5GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _5GrClass::checkIsThisClass(Element& el) {
	if(!isCoinShape(el)) {
		return false;
	}
	
	double areaRatio = (double)el.getArea()/(double)calibrationElement->getArea();
	Color avgColor = el.getAvgColor();

	if(areaRatio < areaMax && areaRatio > areaMin && isBronze(avgColor)) {
		return true;
	} else {
		return false;
	}
}