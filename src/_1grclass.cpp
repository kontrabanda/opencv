#include "_1grclass.h"

_1GrClass::_1GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _1GrClass::checkIsThisClass(Element& el) {
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