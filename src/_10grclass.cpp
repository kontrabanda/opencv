#include "_10grclass.h"

_10GrClass::_10GrClass(Element* calibrationElement) {
	this->calibrationElement = calibrationElement;
}

bool _10GrClass::checkIsThisClass(Element& el) {

	cout << "***************************************" << endl;
	cout << "Is coin shape: " << isCoinShape(el) << endl;
	cout << "M1: " << el.getM1() << endl;
	cout << "M2: " << el.getM2() << endl;
	

	if(!isCoinShape(el)) {
		cout << "***************************************" << endl;
		return false;
	}

	double areaRatio = (double)el.getArea()/(double)calibrationElement->getArea();
	Color avgColor = el.getAvgColor();

	cout << "Area ratio: " << areaRatio << endl;
	cout << "AvgColor: b=" << avgColor.b << ", g=" << avgColor.g << ", r=" << avgColor.r << endl;
	cout << "Lightness: L=" << avgColor.getLightness() << endl;
 	cout << "Is bronze: " << isBronze(avgColor) << endl;
	cout << "Is silver: " << isSilver(avgColor) << endl;
	cout << "Is 2zl colors: " << isSilverInBronze(el) << endl;
	cout << "Is 5zl colors: " << isBonzeInSilver(el) << endl;
	cout << "***************************************" << endl;

	if(areaRatio < areaMax && areaRatio > areaMin && isSilver(avgColor)) {
		return true;
	} else {
		return false;
	}
}