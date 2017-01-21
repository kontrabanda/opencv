#include "base.h"

Base::Base() {

}

bool Base::checkIsThisClass(Element& el) {
	return false;
}

bool Base::isCoinShape(Element& el) {
	const double M1_MIN = 0.158;
	const double M1_MAX = 0.161;
	const double M2_MIN = 0.0253;
	const double M2_MAX = 0.0256;

	double M1 = el.getM1();
	double M2 = el.getM2();

	if(M1 > M1_MIN && M1 < M1_MAX &&
		M2 > M2_MIN && M2 < M2_MAX) {
		return true;
	}

	return false;
}

bool Base::isBronze(Color& avgColor) {
	const double bRatio = 0.85;

	return ((double)avgColor.b/avgColor.getLightness()) <= bRatio;
}

bool Base::isSilver(Color& avgColor) {
	const double bRatio = 0.85;

	return ((double)avgColor.b/avgColor.getLightness()) >= bRatio;
}