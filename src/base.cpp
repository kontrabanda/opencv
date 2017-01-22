#include "base.h"

Base::Base() {

}

bool Base::checkIsThisClass(Element& el) {
	return isCoinShape(el);
}

bool Base::isCoinShape(Element& el) {
	const double M1_MIN = 0.158;
	const double M1_MAX = 0.162;
	const double M2_MIN = 0.0253;
	const double M2_MAX = 0.0262;

	double M1 = el.getM1();
	double M2 = el.getM2();

	if(M1 > M1_MIN && M1 < M1_MAX &&
		M2 > M2_MIN && M2 < M2_MAX) {
		return true;
	}

	return false;
}

bool Base::isBronze(Color& avgColor) {
	const double bRatio = 0.855;
	double lightness = avgColor.getLightness();
	return ((double)avgColor.b/lightness) <= bRatio || (lightness - avgColor.b >= 20);
}

bool Base::isSilver(Color& avgColor) {
	const double bRatio = 0.845;
	return ((double)avgColor.b/avgColor.getLightness()) >= bRatio;
}

bool Base::isBonzeInSilver(Element& el) {
	double radiusRatio = 0.7;
	double bThreshold = -10;
	double rThreshold = 10;
	double radius = pow((double)el.getArea()/M_PI, 0.5) * radiusRatio;

	Element* innerEl = el.getInnerElement(radius);
	Element* outerEl = el.getOuterElement(radius);

	Color innerColor = innerEl->getAvgColor();
	Color outerColor = outerEl->getAvgColor();

	bool result = ((innerColor.b - outerColor.b < bThreshold && innerColor.r - outerColor.r > 0) || (innerColor.r - outerColor.r > rThreshold && innerColor.b - outerColor.b < 0)  && innerColor.r - outerColor.r > 0);

	delete innerEl;
	delete outerEl;

	return result;
}

bool Base::isSilverInBronze(Element& el) {
	double radiusRatio = 0.55;
	double bThreshold = 8;
	double rThreshold = -8;
	double radius = pow((double)el.getArea()/M_PI, 0.5) * radiusRatio;
	
	el.radiusPlaceholder = radius;

	Element* innerEl = el.getInnerElement(radius);
	Element* outerEl = el.getOuterElement(radius);

	Color innerColor = innerEl->getAvgColor();
	Color outerColor = outerEl->getAvgColor();

	double b = innerColor.b - outerColor.b;
	double r = innerColor.r - outerColor.r;

	bool result = (((b > bThreshold) || (r < rThreshold)) && r - b < rThreshold);

	cout << "Silver in bronze: b=" << innerColor.b - outerColor.b << ", r=" << innerColor.r - outerColor.r << endl;
	cout << "Silver in bronze: ratio=" << r - b << endl;

	delete innerEl;
	delete outerEl;

	return result;
}