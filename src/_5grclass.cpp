#include "_5grclass.h"

_5GrClass::_5GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _5GrClass::checkIsThisClass(Element& el) {
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