#include "_2grclass.h"

_2GrClass::_2GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _2GrClass::checkIsThisClass(Element& el) {
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