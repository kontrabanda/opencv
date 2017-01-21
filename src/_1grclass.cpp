#include "_1grclass.h"

_1GrClass::_1GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _1GrClass::checkIsThisClass(Element& el) {
	double areaRatio = (double)el.getArea()/(double)calibrationElement->getArea();
	
	if(areaRatio < areaMax && areaRatio > areaMin) {
		return true;
	} else {
		return false;
	}
}