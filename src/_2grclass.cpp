#include "_2grclass.h"

_2GrClass::_2GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _2GrClass::checkIsThisClass(Element& el) {
	double areaRatio = (double)el.getArea()/(double)calibrationElement->getArea();

	if(areaRatio < areaMax && areaRatio > areaMin) {
		return true;
	} else {
		return false;
	}
}