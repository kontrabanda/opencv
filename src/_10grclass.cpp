#include "_10grclass.h"

_10GrClass::_10GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _10GrClass::checkIsThisClass(Element& el) {
	double areaRatio = (double)el.getArea()/(double)calibrationElement->getArea();

	if(areaRatio < areaMax && areaRatio > areaMin) {
		return true;
	} else {
		return false;
	}
}