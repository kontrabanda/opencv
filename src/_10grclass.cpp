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
	cout << "LIGHTNESS: l=" << (avgColor.b + avgColor.g + avgColor.r)/3 << endl;
	cout << "COLOR: b=" << avgColor.b << ", g=" << avgColor.g << ", r=" << avgColor.r << endl; 
	cout << "BRATIO: ratio=" << avgColor.b/avgColor.getLightness() << endl;
	cout << "isBronze: " << isBronze(avgColor) << endl;
	cout << "isSilver: " << isSilver(avgColor) << endl;
	cout << "-------------------------------------" << endl;

	if(areaRatio < areaMax && areaRatio > areaMin) {
		return true;
	} else {
		return false;
	}
}