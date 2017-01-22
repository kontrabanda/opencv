#include "_10grclass.h"

_10GrClass::_10GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _10GrClass::checkIsThisClass(Element& el) {
	if(!isCoinShape(el)) {
		return false;
	}

	double areaRatio = (double)el.getArea()/(double)calibrationElement->getArea();
	Color avgColor = el.getAvgColor();

	cout << "-------------------------------------" << endl;
	isBronze(avgColor);
	isSilver(avgColor);
	isSilverInBronze(el);
	isBonzeInSilver(el);
	cout << "-------------------------------------" << endl;

	if(areaRatio < areaMax && areaRatio > areaMin) {
		return true;
	} else {
		return false;
	}
}