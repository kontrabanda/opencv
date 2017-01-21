#include "_50grclass.h"

_50GrClass::_50GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _50GrClass::checkIsThisClass(Element& el) {
	double areaRatio = (double)el.getArea()/(double)calibrationElement->getArea();

	if(areaRatio < areaMax && areaRatio > areaMin) {
		return true;
	} else {
		return false;
	}
}