#include "_20grclass.h"

_20GrClass::_20GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _20GrClass::checkIsThisClass(Element& el) {
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