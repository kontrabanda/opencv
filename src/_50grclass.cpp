#include "_50grclass.h"

_50GrClass::_50GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _50GrClass::checkIsThisClass(Element& el) {
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