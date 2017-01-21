#include "_20grclass.h"

_20GrClass::_20GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _20GrClass::checkIsThisClass(Element& el) {
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